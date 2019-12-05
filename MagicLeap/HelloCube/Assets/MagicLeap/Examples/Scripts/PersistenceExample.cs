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
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.MagicLeap;

namespace MagicLeap
{
    /// <summary>
    /// Demonstrates how to persist objects dynamically by interfacing with
    /// the MLPersistence API. This facilitates restoration of existing
    /// and creation of new persistent points.
    /// </summary>
    [RequireComponent(typeof(PrivilegeRequester))]
    public class PersistenceExample : MonoBehaviour
    {
        #region Private Variables
        [SerializeField, Tooltip("Content to create")]
        GameObject _content = null;
        List<MLPersistentBehavior> _pointBehaviors = new List<MLPersistentBehavior>();

        [SerializeField, Tooltip("Status Text")]
        Text _statusText = null;

        [SerializeField, Tooltip("Destroyed content effect")]
        GameObject _destroyedContentEffect = null;

        [SerializeField, Tooltip("Text to count restored objects")]
        Text _countRestoredText = null;
        string _countRestoredTextFormat;
        int _countRestoredGood = 0;
        int _countRestoredBad = 0;

        [SerializeField, Tooltip("Text to count created objects")]
        Text _countCreatedText = null;
        string _countCreatedTextFormat;
        int _countCreatedGood = 0;
        int _countCreatedBad = 0;

        [SerializeField, Tooltip("Controller")]
        ControllerConnectionHandler _controller = null;

        [SerializeField, Tooltip("Distance in front of Controller to create content")]
        float _distance = 0.2f;

        PrivilegeRequester _privilegeRequester;

        [SerializeField, Tooltip("PCF Visualizer when debugging")]
        PCFVisualizer _pcfVisualizer = null;

        [SerializeField, Tooltip("Number of frames to perform delete all gesture before executing the deletion")]
        int _deleteAllSequenceMinFrames = 60;
        int _deleteAllSequenceFrameCount = 0;
        bool _deleteAllInitiated = false;
        #endregion // Private Variables

        #region Unity Methods
        /// <summary>
        /// Validate properties. Attach event listener to when privileges are granted
        /// on Awake because the privilege requester requests on Start.
        /// </summary>
        void Awake()
        {
            if (_content == null || _content.GetComponent<MLPersistentBehavior>() == null)
            {
                Debug.LogError("Error: PersistenceExample._content is not set or is missing MLPersistentBehavior behavior, disabling script.");
                enabled = false;
                return;
            }

            if (_destroyedContentEffect == null)
            {
                Debug.LogError("Error: PersistenceExample._destroyedContentEffect is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_controller == null)
            {
                Debug.LogError("Error: PersistenceExample._controller is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_statusText == null)
            {
                Debug.LogError("Error: PersistenceExample._statusText is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_countCreatedText == null)
            {
                Debug.LogError("Error: PersistenceExample._countCreatedText is not set, disabling script.");
                enabled = false;
                return;
            }
            _countCreatedTextFormat = _countCreatedText.text;
            _countCreatedText.text = string.Format(_countCreatedTextFormat, _countCreatedGood, _countCreatedBad);

            if (_countRestoredText == null)
            {
                Debug.LogError("Error: PersistenceExample._countRestoredText is not set, disabling script.");
                enabled = false;
                return;
            }
            _countRestoredTextFormat = _countRestoredText.text;
            _countRestoredText.text = string.Format(_countRestoredTextFormat, _countRestoredGood, _countRestoredBad);

            // _privilegeRequester is expected to request for PwFoundObjRead privilege
            _privilegeRequester = GetComponent<PrivilegeRequester>();
            _privilegeRequester.OnPrivilegesDone += HandlePrivilegesDone;
            _statusText.text = "Status: Requesting Privileges";
        }

        /// <summary>
        /// Clean up
        /// </summary>
        void OnDestroy()
        {
            foreach (MLPersistentBehavior pointBehavior in _pointBehaviors)
            {
                if (pointBehavior != null)
                {
                    RemoveContentListeners(pointBehavior);
                    Destroy(pointBehavior.gameObject);
                }
            }

            if (MLPersistentCoordinateFrames.IsStarted)
            {
                MLPersistentCoordinateFrames.Stop();
            }

            if (MLPersistentStore.IsStarted)
            {
                MLPersistentStore.Stop();
            }

            if (_privilegeRequester != null)
            {
                _privilegeRequester.OnPrivilegesDone -= HandlePrivilegesDone;
            }

            MLInput.OnControllerButtonDown -= HandleControllerButtonDown;
            MLInput.OnControllerTouchpadGestureStart -= HandleTouchpadGestureStart;
            MLInput.OnControllerTouchpadGestureContinue -= HandleTouchpadGestureContinue;
            MLInput.OnControllerTouchpadGestureEnd -= HandleTouchpadGestureEnd;
        }
        #endregion // Unity Methods

        #region Event Handlers
        /// <summary>
        /// Listens for Bumper and Home Tap.
        /// </summary>
        /// <param name="controllerId">Controller ID</param>
        /// <param name="button">Controller Button</param>
        void HandleControllerButtonDown(byte controllerId, MLInputControllerButton button)
        {
            if (!_controller.IsControllerValid(controllerId))
            {
                return;
            }

            if (button == MLInputControllerButton.Bumper)
            {
                Vector3 position = _controller.transform.position + _controller.transform.forward * _distance;
                CreateContent(position, _controller.transform.rotation);
            }
            else if (button == MLInputControllerButton.HomeTap)
            {
                _pcfVisualizer.ToggleDebug();
            }
        }

        /// <summary>
        /// Responds to privilege requester result.
        /// </summary>
        /// <param name="result">MLResult of the privilege request</param>
        void HandlePrivilegesDone(MLResult result)
        {
            _privilegeRequester.OnPrivilegesDone -= HandlePrivilegesDone;
            if (!result.IsOk)
            {
                if (result.Code == MLResultCode.PrivilegeDenied)
                {
                    Instantiate(Resources.Load("PrivilegeDeniedError"));
                }

                Debug.LogErrorFormat("Error: PersistenceExample failed to get requested privileges, disabling script. Reason: {0}", result);
                _statusText.text = "<color=red>Failed to acquire necessary privileges</color>";
                enabled = false;
                return;
            }
            _statusText.text = "Status: Starting up Systems";

            result = MLPersistentStore.Start();
            if (!result.IsOk)
            {
                if (result.Code == MLResultCode.PrivilegeDenied)
                {
                    Instantiate(Resources.Load("PrivilegeDeniedError"));
                }

                Debug.LogErrorFormat("Error: PersistenceExample failed starting MLPersistentStore, disabling script. Reason: {0}", result);
                enabled = false;
                return;
            }

            result = MLPersistentCoordinateFrames.Start();
            if (!result.IsOk)
            {
                if (result.Code == MLResultCode.PrivilegeDenied)
                {
                    Instantiate(Resources.Load("PrivilegeDeniedError"));
                }

                MLPersistentStore.Stop();
                Debug.LogErrorFormat("Error: PersistenceExample failed starting MLPersistentCoordinateFrames, disabling script. Reason: {0}", result);
                enabled = false;
                return;
            }

            if (MLPersistentCoordinateFrames.IsReady)
            {
                PerformStartup();
            }
            else
            {
                MLPersistentCoordinateFrames.OnInitialized += HandleInitialized;
            }
        }

        /// <summary>
        /// Proceeds with further start up operations if the system successfully initialized.
        /// </summary>
        void HandleInitialized(MLResult status)
        {
            MLPersistentCoordinateFrames.OnInitialized -= HandleInitialized;

            if (status.IsOk)
            {
                PerformStartup();
            }
            else
            {
                _statusText.text = string.Format("<color=red>{0}</color>", status);
                Debug.LogErrorFormat("Error: MLPersistentCoordinateFrames failed to initialize, disabling script. Reason: {0}", status);
                enabled = false;
            }
        }

        /// <summary>
        /// Handler when Content status changes
        /// </summary>
        /// <param name="status">MLPersistentBehavior.PersistentBehaviorStatus</param>
        /// <param name="result">MLResult</param>
        void HandleContentStatusUpdate(MLPersistentBehavior.Status status, MLResult result)
        {
            switch (status)
            {
                case MLPersistentBehavior.Status.BINDING_CREATED:
                    _countCreatedGood++;
                    UpdateCreatedCountText();
                    break;
                case MLPersistentBehavior.Status.BINDING_CREATE_FAILED:
                    _countCreatedBad++;
                    UpdateCreatedCountText();
                    ShowError(result);
                    break;
                case MLPersistentBehavior.Status.RESTORE_SUCCESSFUL:
                    _countRestoredGood++;
                    UpdateRestoredCountText();
                    break;
                case MLPersistentBehavior.Status.RESTORE_FAILED:
                    _countRestoredBad++;
                    UpdateRestoredCountText();

                    // MLResultCode.SnapshotPoseNotFound means the content is bound to a PCF
                    // that does not belong to the current map which is normal behavior
                    if (result.Code != MLResultCode.SnapshotPoseNotFound)
                    {
                        ShowError(result);
                    }
                    break;
                default:
                    break;
            }
        }

        /// <summary>
        /// Handler when touchpad gesture begins
        /// </summary>
        /// <param name="controllerId">Controller ID</param>
        /// <param name="touchpadGesture">Touchpad Gesture</param>
        private void HandleTouchpadGestureStart(byte controllerId, MLInputControllerTouchpadGesture touchpadGesture)
        {
            if (!_controller.IsControllerValid(controllerId))
            {
                return;
            }

            if (touchpadGesture.Type == MLInputControllerTouchpadGestureType.RadialScroll)
            {
                _deleteAllInitiated = true;
                _deleteAllSequenceFrameCount = 0;
            }
        }

        /// <summary>
        /// Handler when touchpad gesture continues
        /// </summary>
        /// <param name="controllerId">Controller ID</param>
        /// <param name="touchpadGesture">Touchpad Gesture</param>
        private void HandleTouchpadGestureContinue(byte controllerId, MLInputControllerTouchpadGesture touchpadGesture)
        {
            if (!_controller.IsControllerValid(controllerId))
            {
                return;
            }

            if (_deleteAllInitiated)
            {
                if (touchpadGesture.Type == MLInputControllerTouchpadGestureType.RadialScroll)
                {
                    ++_deleteAllSequenceFrameCount;
                    if (_deleteAllSequenceFrameCount < _deleteAllSequenceMinFrames)
                    {
                        _statusText.text = string.Format("<color=yellow>Delete All sequence {0:P} complete.</color>",
                            (float)(_deleteAllSequenceFrameCount) / _deleteAllSequenceMinFrames);
                    }
                    else
                    {
                        MLPersistentStore.DeleteAll();
                        foreach (var pointBehavior in _pointBehaviors)
                        {
                            Instantiate(_destroyedContentEffect, pointBehavior.transform.position, Quaternion.identity);
                            Destroy(pointBehavior.gameObject);
                        }
                        _pointBehaviors.Clear();

                        _statusText.text = string.Format("<color=green>Delete All complete.</color>");
                        _deleteAllInitiated = false;
                    }
                }
            }
        }

        /// <summary>
        /// Handler when touchpad gesture ends
        /// </summary>
        /// <param name="controllerId">Controller ID</param>
        /// <param name="touchpadGesture">Touchpad Gesture</param>
        private void HandleTouchpadGestureEnd(byte controllerId, MLInputControllerTouchpadGesture touchpadGesture)
        {
            if (!_controller.IsControllerValid(controllerId))
            {
                return;
            }

            if (_deleteAllInitiated)
            {
                if (touchpadGesture.Type == MLInputControllerTouchpadGestureType.RadialScroll &&
                    _deleteAllSequenceFrameCount < _deleteAllSequenceMinFrames)
                {
                    _statusText.text = string.Format("Delete All sequence aborted!");
                    _deleteAllInitiated = false;
                }
            }
        }
        #endregion // Event Handlers

        #region Private Methods
        /// <summary>
        /// Activate PCF Visualizer, restore content, and update status text
        /// </summary>
        void PerformStartup()
        {
            MLInput.OnControllerButtonDown += HandleControllerButtonDown;
            MLInput.OnControllerTouchpadGestureStart += HandleTouchpadGestureStart;
            MLInput.OnControllerTouchpadGestureContinue += HandleTouchpadGestureContinue;
            MLInput.OnControllerTouchpadGestureEnd += HandleTouchpadGestureEnd;

            _pcfVisualizer.gameObject.SetActive(true);
            _statusText.text = "Status: Restoring Content";
            ReadAllStoredObjects();
            _statusText.text = "";
        }

        /// <summary>
        /// Update counter for restored content
        /// </summary>
        void UpdateRestoredCountText()
        {
            _countRestoredText.text = string.Format(_countRestoredTextFormat, _countRestoredGood, _countRestoredBad);
        }

        /// <summary>
        /// Update counter for created content
        /// </summary>
        void UpdateCreatedCountText()
        {
            _countCreatedText.text = string.Format(_countCreatedTextFormat, _countCreatedGood, _countCreatedBad);
        }

        /// <summary>
        /// Visualize and log error
        /// </summary>
        /// <param name="result">The specific error</param>
        void ShowError(MLResult result)
        {
            Debug.LogErrorFormat("Error: {0}", result);
            _statusText.text = string.Format("<color=red>Error: {0}</color>", result);
        }

        /// <summary>
        /// Reads all stored game object ids.
        /// </summary>
        void ReadAllStoredObjects()
        {
            List<MLContentBinding> allBindings = MLPersistentStore.AllBindings;
            foreach (MLContentBinding binding in allBindings)
            {
                GameObject gameObj = Instantiate(_content, Vector3.zero, Quaternion.identity);
                MLPersistentBehavior persistentBehavior = gameObj.GetComponent<MLPersistentBehavior>();
                persistentBehavior.UniqueId = binding.ObjectId;
                _pointBehaviors.Add(persistentBehavior);
                AddContentListeners(persistentBehavior);
            }
        }

        /// <summary>
        /// Instantiates a new object with MLPersistentBehavior. The MLPersistentBehavior is
        /// responsible for restoring and saving itself.
        /// </summary>
        void CreateContent(Vector3 position, Quaternion rotation)
        {
            GameObject gameObj = Instantiate(_content, position, rotation);
            MLPersistentBehavior persistentBehavior = gameObj.GetComponent<MLPersistentBehavior>();
            persistentBehavior.UniqueId = Guid.NewGuid().ToString();
            _pointBehaviors.Add(persistentBehavior);
            AddContentListeners(persistentBehavior);
        }

        /// <summary>
        /// Removes the points and destroys its binding to prevent future restoration
        /// </summary>
        /// <param name="gameObj">Game Object to be removed</param>
        void RemoveContent(GameObject gameObj)
        {
            MLPersistentBehavior persistentBehavior = gameObj.GetComponent<MLPersistentBehavior>();
            RemoveContentListeners(persistentBehavior);
            _pointBehaviors.Remove(persistentBehavior);
            persistentBehavior.DestroyBinding();
            Instantiate(_destroyedContentEffect, persistentBehavior.transform.position, Quaternion.identity);

            Destroy(persistentBehavior.gameObject);
        }

        /// <summary>
        /// Add listeners to content events
        /// </summary>
        /// <param name="persistentBehavior">Dynamic Content</param>
        void AddContentListeners(MLPersistentBehavior persistentBehavior)
        {
            persistentBehavior.OnStatusUpdate += HandleContentStatusUpdate;

            PersistentBall contentBehavior = persistentBehavior.GetComponent<PersistentBall>();
            contentBehavior.OnContentDestroy += RemoveContent;
        }

        /// <summary>
        /// Remove listeners from content events
        /// </summary>
        /// <param name="persistentBehavior">Dynamic Content</param>
        void RemoveContentListeners(MLPersistentBehavior persistentBehavior)
        {
            // it is safe to unsubscribe to events even if we're not originally subscribing to them
            persistentBehavior.OnStatusUpdate -= HandleContentStatusUpdate;

            PersistentBall contentBehavior = persistentBehavior.GetComponent<PersistentBall>();
            contentBehavior.OnContentDestroy -= RemoveContent;
        }
        #endregion // Private Methods
    }
}
