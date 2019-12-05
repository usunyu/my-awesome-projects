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
    /// Utility class that relays controller trigger events to drag events
    /// </summary>
    [RequireComponent(typeof(ControllerConnectionHandler))]
    public class ContentDragController : MonoBehaviour
    {
        #region Private Variables
        ControllerConnectionHandler _controllerConnectionHandler;
        bool _isDragging = false;
        #endregion

        #region Public Events
        /// <summary>
        /// Triggered when dragging begins
        /// </summary>
        public event Action OnBeginDrag;

        /// <summary>
        /// Triggered every frame while a drag is on-going and the transform has changed
        /// </summary>
        public event Action OnDrag;

        /// <summary>
        /// Triggered when dragging ends
        /// </summary>
        public event Action OnEndDrag;
        #endregion

        #region Unity Methods
        /// <summary>
        /// Set Up
        /// </summary>
        void Start()
        {
            _controllerConnectionHandler = GetComponent<ControllerConnectionHandler>();

            MLInput.OnTriggerDown += HandleTriggerDown;
            MLInput.OnTriggerUp += HandleTriggerUp;
        }

        /// <summary>
        /// Clean Up
        /// </summary>
        private void OnDestroy()
        {
            MLInput.OnTriggerDown -= HandleTriggerDown;
            MLInput.OnTriggerUp -= HandleTriggerUp;
        }

        /// <summary>
        /// Triggers drag event if needed
        /// </summary>
        private void Update()
        {
            if (_isDragging && transform.hasChanged)
            {
                transform.hasChanged = false;
                if (OnDrag != null)
                {
                    OnDrag();
                }
            }
        }
        #endregion

        #region Event Handlers
        /// <summary>
        /// Handler for controller trigger down
        /// </summary>
        /// <param name="controllerId">Controller ID</param>
        /// <param name="triggerValue">Trigger Value (unused)</param>
        private void HandleTriggerDown(byte controllerId, float triggerValue)
        {
            if (_controllerConnectionHandler.IsControllerValid(controllerId))
            {
                if (OnBeginDrag != null)
                {
                    OnBeginDrag();
                }
                _isDragging = true;
            }
        }

        /// <summary>
        /// Handler for controller trigger up
        /// </summary>
        /// <param name="controllerId">Controller ID</param>
        /// <param name="triggerValue">Trigger Value (unused)</param>
        private void HandleTriggerUp(byte controllerId, float triggerValue)
        {
            if (_controllerConnectionHandler.IsControllerValid(controllerId))
            {
                if (OnEndDrag != null)
                {
                    OnEndDrag();
                }
                _isDragging = false;
            }
        }
        #endregion
    }
}
