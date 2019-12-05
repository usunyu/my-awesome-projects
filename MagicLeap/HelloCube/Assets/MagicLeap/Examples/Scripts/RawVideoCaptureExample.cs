// %BANNER_BEGIN%
// ---------------------------------------------------------------------
// %COPYRIGHT_BEGIN%
//
// Copyright (c) 2019 Magic Leap, Inc. All Rights Reserved.
// Use of this file is governed by the Creator Agreement, located
// here: https://id.magicleap.com/creator-terms
//
// %COPYRIGHT_END%
// ---------------------------------------------------------------------
// %BANNER_END%

using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Events;
using UnityEngine.XR.MagicLeap;
using System.Collections.Generic;
using System;
using System.Text;

namespace MagicLeap
{
    /// <summary>
    /// This class handles video recording and loading based on controller
    /// input.
    /// </summary>
    [RequireComponent(typeof(PrivilegeRequester))]
    public class RawVideoCaptureExample : MonoBehaviour
    {
        #region Private Variables
        [Space, SerializeField, Tooltip("Camera intrinsic values text field.")]
        private Text _intrinsicValuesText = null;

        [Space, SerializeField, Tooltip("Object placed at the Frame Pose origin (camera location).")]
        private Transform _framePoseTransform = null;

        [Space, SerializeField, Tooltip("ControllerConnectionHandler reference.")]
        private ControllerConnectionHandler _controllerConnectionHandler = null;

        [Space, Header("Events")]
        [SerializeField, Tooltip("Event called when recording starts")]
        private UnityEvent OnVideoCaptureStarted = null;

        [SerializeField, Tooltip("Event called when recording stops")]
        private UnityEvent OnVideoCaptureEnded = null;

        [System.Serializable]
        private class MyEvent : UnityEvent<MLCameraResultExtras, YUVFrameInfo, MLCameraFrameMetadata> { }

        [SerializeField, Tooltip("Event called when raw data is received")]
        private MyEvent OnRawVideoDataReceived = null;

        // Is the camera currently recording
        private bool _isCapturing;

        private bool _isCameraConnected = false;

        private float _captureStartTime;

        private PrivilegeRequester _privilegeRequester = null;

        private bool _hasStarted = false;

        private bool _appPaused = false;
        #endregion

        #region Unity Methods
        // Using Awake so that Privileges is set before PrivilegeRequester Start
        void Awake()
        {
            enabled = false;

            if (_controllerConnectionHandler == null)
            {
                Debug.LogError("Error: VideoCamptureExample._controllerConnectionHandler is not set, disabling script.");
                return;
            }

            if (_intrinsicValuesText == null)
            {
                Debug.LogError("Error: VideoCamptureExample._intrinsicValuesText is not set, disabling script.");
                return;
            }

            if (_framePoseTransform == null)
            {
                Debug.LogError("Error: VideoCamptureExample._framePoseTransform is not set, disabling script.");
                return;
            }

            enabled = true;

            _privilegeRequester = GetComponent<PrivilegeRequester>();

            // Before enabling the Camera, the scene must wait until the privileges have been granted.
            _privilegeRequester.OnPrivilegesDone += HandlePrivilegesDone;
        }

        /// <summary>
        /// Stop the camera, unregister callbacks, and stop input and privileges APIs.
        /// </summary>
        void OnDisable()
        {
            MLInput.OnControllerButtonDown -= OnButtonDown;

            if (_isCameraConnected)
            {
                DisableMLCamera();
            }
        }

        /// <summary>
        /// Cannot make the assumption that a privilege is still granted after
        /// returning from pause. Return the application to the state where it
        /// requests privileges needed and clear out the list of already granted
        /// privileges. Also, disable the camera and unregister callbacks.
        /// </summary>
        void OnApplicationPause(bool pause)
        {
            if (pause)
            {
                _appPaused = true;

                if (_isCameraConnected && MLCamera.IsStarted)
                {
                    MLResult result = MLCamera.ApplicationPause(_appPaused);
                    if(!result.IsOk)
                    {
                        Debug.LogErrorFormat("Error: RawVideoCaptureExample failed to pause MLCamera, disabling script. Reason: {0}", result);
                        enabled = false;
                        return;
                    }

                    if (_isCapturing)
                    {
                        OnVideoCaptureEnded?.Invoke();
                    }

                    _isCapturing = false;
                    _captureStartTime = 0;
                    _isCameraConnected = false;
                }

                MLInput.OnControllerButtonDown -= OnButtonDown;
            }
        }

        void OnDestroy()
        {
            if (_privilegeRequester != null)
            {
                _privilegeRequester.OnPrivilegesDone -= HandlePrivilegesDone;
            }
        }
        #endregion

        #region Public Methods
        /// <summary>
        /// Start capturing raw video.
        /// </summary>
        public void StartCapture()
        {
            if(!_isCapturing && MLCamera.IsStarted && _isCameraConnected)
            {
                MLResult result = MLCamera.StartRawVideoCapture();
                if (result.IsOk)
                {
                    _isCapturing = true;
                    _captureStartTime = Time.time;
                    OnVideoCaptureStarted?.Invoke();
                    SetupCameraIntrinsics();
                }
                else
                {
                    CheckPrivilegeDenied(result);
                    Debug.LogErrorFormat("Error: RawVideoCaptureExample failed to start raw video capture. Reason: {1}", MLCamera.GetErrorCode().ToString());
                }
            }
            else
            {
                Debug.LogErrorFormat("Error: RawVideoCaptureExample failed to start raw video capture.");
            }
        }

        /// <summary>
        /// Stop capturing video.
        /// </summary>
        public void EndCapture()
        {
            if (_isCapturing)
            {
                MLResult result = MLCamera.StopVideoCapture();
                if (result.IsOk)
                {
                    _isCapturing = false;
                    _captureStartTime = 0;
                    OnVideoCaptureEnded?.Invoke();
                }
                else
                {
                    CheckPrivilegeDenied(result);
                    Debug.LogErrorFormat("Error: RawVideoCaptureExample failed to end raw video capture. Error Code: {0}", MLCamera.GetErrorCode().ToString());
                }
            }
            else
            {
                Debug.LogError("Error: RawVideoCaptureExample failed to end raw video capture because the camera is not capturing.");
            }
        }
        #endregion

        #region Private Functions
        /// <summary>
        /// Check the result for PrivilegeDenied, and display the appropriate visual for the user.
        /// </summary>
        /// <param name="result">The result to check.</param>
        private void CheckPrivilegeDenied(MLResult result)
        {
            if (result.Code == MLResultCode.PrivilegeDenied)
            {
                Instantiate(Resources.Load("PrivilegeDeniedError"));
            }
        }

        /// <summary>
        /// Connects the MLCamera component and instantiates a new instance
        /// if it was never created.
        /// </summary>
        private void EnableMLCamera()
        {
            MLResult result = MLCamera.Start();
            if (result.IsOk)
            {
                result = MLCamera.Connect();
                MLCamera.OnRawVideoFrameAvailableYUV += OnRawCaptureDataReceived;
                _isCameraConnected = true;
            }
            else
            {
                CheckPrivilegeDenied(result);
                Debug.LogErrorFormat("Error: RawVideoCaptureExample failed starting MLCamera, disabling script. Reason: {0}", result);
                enabled = false;
            }
        }

        /// <summary>
        /// Disconnects the MLCamera if it was ever created or connected.
        /// Also stops any video recording if active.
        /// </summary>
        private void DisableMLCamera()
        {
            if (MLCamera.IsStarted)
            {
                if (_isCapturing)
                {
                    EndCapture();
                }
                MLCamera.Disconnect();
                _isCameraConnected = false;
                MLCamera.Stop();
                MLCamera.OnRawVideoFrameAvailableYUV -= OnRawCaptureDataReceived;
            }
        }

        /// <summary>
        /// Enable the camera and callbacks. Called once privileges have been granted.
        /// </summary>
        private void EnableCapture()
        {
            if (!_hasStarted)
            {
                EnableMLCamera();

                MLInput.OnControllerButtonDown += OnButtonDown;

                _hasStarted = true;
            }
        }
        #endregion

        #region Event Handlers
        /// <summary>
        /// Responds to privilege requester result.
        /// </summary>
        /// <param name="result">Result of the privilege request.</param>
        private void HandlePrivilegesDone(MLResult result)
        {
            if (!result.IsOk)
            {
                CheckPrivilegeDenied(result);
                Debug.LogErrorFormat("Error: RawVideoCaptureExample failed to get all requested privileges, disabling script. Reason: {0}", result);
                enabled = false;
                return;
            }

            Debug.Log("Succeeded in requesting all privileges");

            // Called here because it needs privileges to be granted first on resume by PrivilegeRequester.
            if (_appPaused)
            {
                _appPaused = false;

                result = MLCamera.ApplicationPause(_appPaused);
                if (!result.IsOk)
                {
                    Debug.LogErrorFormat("Error: RawVideoCaptureExample failed to resume MLCamera, disabling script. Reason: {0}", result);
                    enabled = false;
                    return;
                }

                _isCameraConnected = true;

                MLInput.OnControllerButtonDown += OnButtonDown;
            }
            else
            {
                EnableCapture();
            }
        }

        /// <summary>
        /// Handles the event for button down. Starts or stops recording.
        /// </summary>
        /// <param name="controllerId">The id of the controller.</param>
        /// <param name="button">The button that is being pressed.</param>
        private void OnButtonDown(byte controllerId, MLInputControllerButton button)
        {
            if (_controllerConnectionHandler.IsControllerValid(controllerId) && MLInputControllerButton.Bumper == button)
            {
                if (!_isCapturing)
                {
                    StartCapture();
                }
                else
                {
                    EndCapture();
                }
            }
        }

        /// <summary>
        /// Handles the event for raw capture data recieved, and forwards it to any listeners.
        /// Sets the orientation of the framePoseTransform to the current frame pose.
        /// </summary>
        /// <param name="extras">Contains timestamp to use with GetFramePose, also forwarded to listeners.</param>
        /// <param name="frameData">Forwarded to listeners.</param>
        /// <param name="frameMetadata">Forwarded to listeners.</param>
        private void OnRawCaptureDataReceived(MLCameraResultExtras extras, YUVFrameInfo frameData, MLCameraFrameMetadata frameMetadata)
        {
            Matrix4x4 matrix = Matrix4x4.identity;
            MLResult result = MLCamera.GetFramePose(extras.VcamTimestampUs * 1000, out matrix);
            _framePoseTransform.position = matrix.MultiplyPoint(Vector3.zero);
            _framePoseTransform.rotation = matrix.rotation;

            OnRawVideoDataReceived?.Invoke(extras, frameData, frameMetadata);
        }

        /// <summary>
        /// Setup the text field for camera intrinsic values.
        /// Precondition: MLCamera must be successfully started.
        /// </summary>
        void SetupCameraIntrinsics()
        {
            MLCVCameraIntrinsicCalibrationParameters parameters;
            MLResult result = MLCamera.GetIntrinsicCalibrationParameters(out parameters);
            if (result.IsOk)
            {
                _intrinsicValuesText.text = CalibrationParametersToString(parameters);
            }
            else
            {
                Debug.LogErrorFormat("Error: RawVideoCaptureExample failed to GetIntrinsicCalibrationParameters. Reason: {0}", result);
            }
        }

        /// <summary>
        /// Convert camera calibration parameters to a string.
        /// </summary>
        /// <param name="parameters">The camera calibration values to pull from.</param>
        static string CalibrationParametersToString(MLCVCameraIntrinsicCalibrationParameters parameters)
        {
            StringBuilder b = new StringBuilder();
            b.Append("Camera Instrinsic Values:")
                .Append("\n   Width: ").Append(parameters.Width)
                .Append("\n   Height: ").Append(parameters.Height)
                .Append("\n   Focal Length: ").Append(parameters.FocalLength)
                .Append("\n   Principal Point: ").Append(parameters.PrincipalPoint)
                .Append("\n   FOV: ").Append(parameters.FOV)
                .Append("\n   Distortion Coeff.:");
            for (int i = 0; i < parameters.Distortion.Length; ++i)
            {
                b.AppendFormat("\n   [{0}]: {1}", i, parameters.Distortion[i]);
            }
            return b.ToString();
        }
        #endregion
    }
}
