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

using System;
using UnityEngine;
using UnityEngine.Events;
using UnityEngine.XR.MagicLeap;
using System.Collections.Generic;
using System.Threading;
namespace MagicLeap
{
    [RequireComponent(typeof(PrivilegeRequester))]
    public class ImageCaptureExample : MonoBehaviour
    {
        [System.Serializable]
        private class ImageCaptureEvent : UnityEvent<Texture2D>
        {}

        #region Private Variables
        [SerializeField, Space, Tooltip("ControllerConnectionHandler reference.")]
        private ControllerConnectionHandler _controllerConnectionHandler = null;

        [SerializeField, Space]
        private ImageCaptureEvent OnImageReceivedEvent = null;

        private bool _isCameraConnected = false;
        private bool _isCapturing = false;
        private bool _hasStarted = false;
        private bool _doPrivPopup = false;
        private bool _hasShownPrivPopup = false;
        private Thread _captureThread = null;

        /// <summary>
        /// The example is using threads on the call to MLCamera.CaptureRawImageAsync to alleviate the blocking
        /// call at the beginning of CaptureRawImageAsync, and the safest way to prevent race conditions here is to
        /// lock our access into the MLCamera class, so that we don't accidentally shut down the camera
        /// while the thread is attempting to work
        /// </summary>
        private object _cameraLockObject = new object();

        private PrivilegeRequester _privilegeRequester = null;
        #endregion

        #region Unity Methods

        /// <summary>
        /// Using Awake so that Privileges is set before PrivilegeRequester Start.
        /// </summary>
        void Awake()
        {
            if(_controllerConnectionHandler == null)
            {
                Debug.LogError("Error: ImageCaptureExample._controllerConnectionHandler is not set, disabling script.");
                enabled = false;
                return;
            }

            // If not listed here, the PrivilegeRequester assumes the request for
            // the privileges needed, CameraCapture in this case, are in the editor.
            _privilegeRequester = GetComponent<PrivilegeRequester>();

            // Before enabling the Camera, the scene must wait until the privilege has been granted.
            _privilegeRequester.OnPrivilegesDone += HandlePrivilegesDone;
        }

        /// <summary>
        /// Stop the camera, unregister callbacks, and stop input and privileges APIs.
        /// </summary>
        void OnDisable()
        {
            MLInput.OnControllerButtonDown -= OnButtonDown;
            lock (_cameraLockObject)
            {
                if (_isCameraConnected)
                {
                    MLCamera.OnRawImageAvailable -= OnCaptureRawImageComplete;
                    _isCapturing = false;
                    DisableMLCamera();
                }
            }
        }

        /// <summary>
        /// Cannot make the assumption that a reality privilege is still granted after
        /// returning from pause. Return the application to the state where it
        /// requests privileges needed and clear out the list of already granted
        /// privileges. Also, disable the camera and unregister callbacks.
        /// </summary>
        void OnApplicationPause(bool pause)
        {
            if (pause)
            {
                lock (_cameraLockObject)
                {
                    if (_isCameraConnected)
                    {
                        MLCamera.OnRawImageAvailable -= OnCaptureRawImageComplete;
                        _isCapturing = false;
                        DisableMLCamera();
                    }
                }

                MLInput.OnControllerButtonDown -= OnButtonDown;

                _hasStarted = false;
            }
        }

        void OnDestroy()
        {
            if (_privilegeRequester != null)
            {
                _privilegeRequester.OnPrivilegesDone -= HandlePrivilegesDone;
            }
        }

        private void Update()
        {
            if (_doPrivPopup && !_hasShownPrivPopup)
            {
                Instantiate(Resources.Load("PrivilegeDeniedError"));
                _doPrivPopup = false;
                _hasShownPrivPopup = true;
            }
        }
        #endregion

        #region Public Methods
        /// <summary>
        /// Captures a still image using the device's camera and returns
        /// the data path where it is saved.
        /// </summary>
        /// <param name="fileName">The name of the file to be saved to.</param>
        public void TriggerAsyncCapture()
        {
            if (_captureThread == null || (!_captureThread.IsAlive))
            {
                ThreadStart captureThreadStart = new ThreadStart(CaptureThreadWorker);
                _captureThread = new Thread(captureThreadStart);
                _captureThread.Start();
            }
            else
            {
                Debug.Log("Previous thread has not finished, unable to begin a new capture just yet.");
            }
        }
        #endregion

        #region Private Functions
        /// <summary>
        /// Connects the MLCamera component and instantiates a new instance
        /// if it was never created.
        /// </summary>
        private void EnableMLCamera()
        {
            lock (_cameraLockObject)
            {
                MLResult result = MLCamera.Start();
                if (result.IsOk)
                {
                    result = MLCamera.Connect();
                    _isCameraConnected = true;
                }
                else
                {
                    if (result.Code == MLResultCode.PrivilegeDenied)
                    {
                        Instantiate(Resources.Load("PrivilegeDeniedError"));
                    }

                    Debug.LogErrorFormat("Error: ImageCaptureExample failed starting MLCamera, disabling script. Reason: {0}", result);
                    enabled = false;
                    return;
                }
            }
        }

        /// <summary>
        /// Disconnects the MLCamera if it was ever created or connected.
        /// </summary>
        private void DisableMLCamera()
        {
            lock (_cameraLockObject)
            {
                if (MLCamera.IsStarted)
                {
                    MLCamera.Disconnect();
                    // Explicitly set to false here as the disconnect was attempted.
                    _isCameraConnected = false;
                    MLCamera.Stop();
                }
            }
        }

        /// <summary>
        /// Once privileges have been granted, enable the camera and callbacks.
        /// </summary>
        private void StartCapture()
        {
            if (!_hasStarted)
            {
                lock (_cameraLockObject)
                {
                    EnableMLCamera();
                    MLCamera.OnRawImageAvailable += OnCaptureRawImageComplete;
                }
                MLInput.OnControllerButtonDown += OnButtonDown;

                _hasStarted = true;
            }
        }
        #endregion

        #region Event Handlers
        /// <summary>
        /// Responds to privilege requester result.
        /// </summary>
        /// <param name="result"/>
        private void HandlePrivilegesDone(MLResult result)
        {
            if (!result.IsOk)
            {
                if (result.Code == MLResultCode.PrivilegeDenied)
                {
                    Instantiate(Resources.Load("PrivilegeDeniedError"));
                }

                Debug.LogErrorFormat("Error: ImageCaptureExample failed to get requested privileges, disabling script. Reason: {0}", result);
                enabled = false;
                return;
            }

            Debug.Log("Succeeded in requesting all privileges");
            StartCapture();
        }

        /// <summary>
        /// Handles the event for button down.
        /// </summary>
        /// <param name="controllerId">The id of the controller.</param>
        /// <param name="button">The button that is being pressed.</param>
        private void OnButtonDown(byte controllerId, MLInputControllerButton button)
        {
            if (_controllerConnectionHandler.IsControllerValid(controllerId) && MLInputControllerButton.Bumper == button && !_isCapturing)
            {
                TriggerAsyncCapture();
            }
        }

        /// <summary>
        /// Handles the event of a new image getting captured.
        /// </summary>
        /// <param name="imageData">The raw data of the image.</param>
        private void OnCaptureRawImageComplete(byte[] imageData)
        {
            lock (_cameraLockObject)
            {
                _isCapturing = false;
            }
            // Initialize to 8x8 texture so there is no discrepency
            // between uninitalized captures and error texture
            Texture2D texture = new Texture2D(8, 8);
            bool status = texture.LoadImage(imageData);

            if (status && (texture.width != 8 && texture.height != 8))
            {
                OnImageReceivedEvent.Invoke(texture);
            }
        }

        /// <summary>
        /// Worker function to call the API's Capture function
        /// </summary>
        private void CaptureThreadWorker()
        {
            lock (_cameraLockObject)
            {
                if (MLCamera.IsStarted && _isCameraConnected)
                {
                    MLResult result = MLCamera.CaptureRawImageAsync();
                    if (result.IsOk)
                    {
                        _isCapturing = true;
                    }
                    else if (result.Code == MLResultCode.PrivilegeDenied)
                    {
                        _doPrivPopup = true;
                    }
                }
            }
        }
        #endregion
    }
}
