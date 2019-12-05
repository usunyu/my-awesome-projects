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
using UnityEngine.XR.MagicLeap;

namespace MagicLeap
{
    /// <summary>
    /// PersistentBall is responsible for relaying controller event
    /// to destroy this content
    /// </summary>
    [RequireComponent(typeof(Collider), typeof(MLPersistentBehavior))]
    public class PersistentBall : MonoBehaviour
    {
        #region Private Variables
        ControllerConnectionHandler _controllerConnectionHandler;
        #endregion

        #region Public Events
        /// <summary>
        /// Triggered when this content is to be destroyed
        /// </summary>
        public event Action<GameObject> OnContentDestroy;
        #endregion

        #region Unity Methods
        /// <summary>
        /// Clean Up
        /// </summary>
        private void OnDestroy()
        {
            if (_controllerConnectionHandler != null)
            {
                MLInput.OnControllerTouchpadGestureStart -= HandleControllerTouchpadGestureStart;
                _controllerConnectionHandler = null;
            }
        }

        /// <summary>
        /// Register for controller input only when a controller enters the trigger area
        /// </summary>
        /// <param name="other">Collider of the Controller</param>
        private void OnTriggerEnter(Collider other)
        {
            ControllerConnectionHandler controllerConnectionHandler = other.GetComponent<ControllerConnectionHandler>();
            if (controllerConnectionHandler == null)
            {
                return;
            }

            _controllerConnectionHandler = controllerConnectionHandler;
            MLInput.OnControllerTouchpadGestureStart += HandleControllerTouchpadGestureStart;
        }

        /// <summary>
        /// Unregister controller input when controller leaves the trigger area
        /// </summary>
        /// <param name="other">Collider of the Controller</param>
        private void OnTriggerExit(Collider other)
        {
            ControllerConnectionHandler controllerConnectionHandler = other.GetComponent<ControllerConnectionHandler>();
            if (_controllerConnectionHandler == controllerConnectionHandler)
            {
                _controllerConnectionHandler = null;
                MLInput.OnControllerTouchpadGestureStart -= HandleControllerTouchpadGestureStart;
            }
        }
        #endregion

        #region Event Handlers
        /// <summary>
        /// Handler for Gesture Start events
        /// </summary>
        /// <param name="controllerId">Controller Id</param>
        /// <param name="gesture">Touchpad Gesture</param>
        private void HandleControllerTouchpadGestureStart(byte controllerId, MLInputControllerTouchpadGesture gesture)
        {
            if (_controllerConnectionHandler != null
                && _controllerConnectionHandler.IsControllerValid(controllerId)
                && gesture.Type == MLInputControllerTouchpadGestureType.Tap)
            {
                if (OnContentDestroy != null)
                {
                    OnContentDestroy(gameObject);
                }
            }
        }
        #endregion
    }
}
