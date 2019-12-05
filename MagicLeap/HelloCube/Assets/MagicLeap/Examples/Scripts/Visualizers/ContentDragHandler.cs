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
using UnityEngine.XR.MagicLeap;

namespace MagicLeap
{
    /// <summary>
    /// Utility Component to allow users to drag persistent content around.
    /// </summary>
    [RequireComponent(typeof(Collider), typeof(MLPersistentBehavior))]
    public class ContentDragHandler : MonoBehaviour
    {
        #region Private Variables
        Vector3 _controllerPositionOffset;
        Quaternion _controllerOrientationOffset;
        ContentDragController _controllerDrag;
        MLPersistentBehavior _pointBehavior;

        bool _dragStarted = false;
        #endregion

        #region Unity Methods
        /// <summary>
        /// Set Up
        /// </summary>
        private void Start()
        {
            _pointBehavior = GetComponent<MLPersistentBehavior>();
        }

        /// <summary>
        /// Register for events when a ContentDragController enters the trigger area
        /// </summary>
        /// <param name="other">Collider of ContentDragController</param>
        private void OnTriggerEnter(Collider other)
        {
            ContentDragController controllerDrag = other.GetComponent<ContentDragController>();
            if (controllerDrag == null)
            {
                return;
            }

            _controllerDrag = controllerDrag;
            _controllerDrag.OnBeginDrag += HandleBeginDrag;
            _controllerDrag.OnDrag += HandleDrag;
            _controllerDrag.OnEndDrag += HandleEndDrag;
        }

        /// <summary>
        /// Unregister for events when a ContentDragController leaves the trigger area
        /// </summary>
        /// <param name="other">Collider of ContentDragController</param>
        private void OnTriggerExit(Collider other)
        {
            ContentDragController controllerDrag = other.GetComponent<ContentDragController>();
            if (controllerDrag == null)
            {
                return;
            }

            if (_controllerDrag == controllerDrag)
            {
                _controllerDrag.OnBeginDrag -= HandleBeginDrag;
                _controllerDrag.OnDrag -= HandleDrag;
                _controllerDrag.OnEndDrag -= HandleEndDrag;
                _controllerDrag = null;
            }
        }

        /// <summary>
        /// Unregister for events in case this component gets destroyed while being dragged
        /// </summary>
        private void OnDestroy()
        {
            if (_controllerDrag != null)
            {
                _controllerDrag.OnBeginDrag -= HandleBeginDrag;
                _controllerDrag.OnDrag -= HandleDrag;
                _controllerDrag.OnEndDrag -= HandleEndDrag;
                _controllerDrag = null;
            }
        }
        #endregion

        #region Event Handlers
        /// <summary>
        /// Set up offsets when dragging begins
        /// </summary>
        private void HandleBeginDrag()
        {
            Vector3 relativeDirection = transform.position - _controllerDrag.transform.position;
            _controllerPositionOffset = transform.InverseTransformDirection(relativeDirection);
            _controllerOrientationOffset = Quaternion.Inverse(_controllerDrag.transform.rotation) * transform.rotation;

            _dragStarted = true;
        }

        /// <summary>
        /// Update transform while dragging
        /// </summary>
        private void HandleDrag()
        {
            if (_dragStarted)
            {
                transform.position = _controllerDrag.transform.position + transform.TransformDirection(_controllerPositionOffset);
                transform.rotation = _controllerDrag.transform.rotation * _controllerOrientationOffset;
            }
        }

        /// <summary>
        /// Save binding when dragging ends
        /// </summary>
        private void HandleEndDrag()
        {
            _dragStarted = false;
            _pointBehavior.UpdateBinding();
        }
        #endregion
    }
}
