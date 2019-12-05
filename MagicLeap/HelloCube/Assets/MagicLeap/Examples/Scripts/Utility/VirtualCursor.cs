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
using UnityEngine.XR.MagicLeap;

namespace MagicLeap
{
    /// <summary>
    /// This class represents an MLA-controlled 2D cursor.
    /// This works hand-in-hand with ContactsButton.
    /// </summary>
    public class VirtualCursor : MonoBehaviour
    {
        #region Private Variables
        [SerializeField, Tooltip("Sensitivity"), Range(-1, 1)]
        private float _sensitivity = 1.0f;

        private bool _touchActiveBefore = false;
        private Vector2 _prevTouchPos = Vector2.zero;

        private ContactsButton _prevButton = null;

        [SerializeField, Tooltip("ControllerConnectionHandler reference")]
        private ControllerConnectionHandler _controllerHandler = null;

        [SerializeField, Tooltip("Tooltip text")]
        private Text _tooltip = null;
        #endregion Private Variables

        #region Unity Methods
        /// <summary>
        /// Validate inspector properties and attach event handlers.
        /// </summary>
        void Awake()
        {
            if (_controllerHandler == null)
            {
                Debug.LogError("Error: VirtualCursor._controllerHandler is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_tooltip == null)
            {
                Debug.LogError("Error: VirtualCursor._tooltip is not set, disabling script.");
                enabled = false;
                return;
            }

            _tooltip.text = "";
            _tooltip.gameObject.SetActive(false);

            MLInput.OnControllerTouchpadGestureStart += HandleTouchpadGestureStart;
        }

        /// <summary>
        /// Clean up.
        /// </summary>
        void OnDestroy()
        {
            MLInput.OnControllerTouchpadGestureStart -= HandleTouchpadGestureStart;
        }

        /// <summary>
        /// Update state of touch position and buttons.
        /// </summary>
        void LateUpdate()
        {
            var controller = _controllerHandler.ConnectedController;
            if (controller != null)
            {
                UpdateTouchPosition(controller);
                UpdateButtonState();
            }
        }
        #endregion

        #region Event Handlers
        /// <summary>
        /// Handler for Tap gesture.
        /// </summary>
        /// <param name="controllerId">Controller ID</param>
        /// <param name="touchpadGesture">Touchpad Gesture</param>
        private void HandleTouchpadGestureStart(byte controllerId, MLInputControllerTouchpadGesture touchpadGesture)
        {
            if (_controllerHandler.IsControllerValid() &&
                _controllerHandler.ConnectedController.Id == controllerId &&
                touchpadGesture.Type == MLInputControllerTouchpadGestureType.Tap &&
                _prevButton != null)
            {
                _prevButton.Tap();
            }
        }
        #endregion

        #region Private Methods
        /// <summary>
        /// Update cursor position based on touch
        /// </summary>
        /// <param name="controller">Controller</param>
        private void UpdateTouchPosition(MLInputController controller)
        {
            if (controller.Touch1Active)
            {
                if (_touchActiveBefore)
                {
                    Vector2 pos = transform.localPosition;
                    Vector2 currTouchPos = controller.Touch1PosAndForce;
                    pos += (currTouchPos - _prevTouchPos) * _sensitivity;
                    transform.localPosition = pos;
                }
                else
                {
                    _prevTouchPos = controller.Touch1PosAndForce;
                }
                _touchActiveBefore = true;
            }
            else
            {
                _touchActiveBefore = false;
            }
        }

        /// <summary>
        /// Update the state of buttons underneath.
        /// </summary>
        private void UpdateButtonState()
        {
            // we're only expecting a maximum of 1 button underneath
            RaycastHit hitInfo;
            if (Physics.Raycast(transform.position - transform.forward, transform.forward, out hitInfo))
            {
                Collider collider = hitInfo.collider;
                var button = collider.GetComponent<ContactsButton>();
                if (button != null)
                {
                    if (_prevButton == null)
                    {
                        button.CursorEnter();
                        UpdateTooltip(button.TooltipText);
                    }
                    else if (_prevButton != button)
                    {
                        _prevButton.CursorLeave();
                        button.CursorEnter();
                        UpdateTooltip(button.TooltipText);
                    }
                }
                _prevButton = button;
            }
            else if (_prevButton != null)
            {
                _prevButton.CursorLeave();
                _prevButton = null;
                UpdateTooltip("");
            }
        }

        /// <summary>
        /// Update the tooltip.
        /// </summary>
        /// <param name="text">Text to display</param>
        private void UpdateTooltip(string text)
        {
            _tooltip.text = text;
            _tooltip.gameObject.SetActive(!string.IsNullOrEmpty(text));
        }
        #endregion
    }
}
