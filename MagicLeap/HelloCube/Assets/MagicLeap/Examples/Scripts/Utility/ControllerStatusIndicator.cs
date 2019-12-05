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
    /// This represents the controller sprite icon connectivity status.
    /// Red: MLInput error.
    /// Green: Controller connected.
    /// Yellow: Controller disconnected.
    /// </summary>
    [RequireComponent(typeof(SpriteRenderer))]
    public class ControllerStatusIndicator : MonoBehaviour
    {
        #region Private Variables
        [SerializeField, Tooltip("Controller Icon")]
        private Sprite _controllerIcon = null;

        [SerializeField, Tooltip("Mobile App Icon")]
        private Sprite _mobileAppIcon = null;

        [SerializeField, Tooltip("ControllerConnectionHandler reference.")]
        private ControllerConnectionHandler _controllerConnectionHandler = null;

        private SpriteRenderer _spriteRenderer;
        #endregion

        #region Unity Methods
        /// <summary>
        /// Initializes component data and starts MLInput.
        /// </summary>
        void Awake()
        {
            _spriteRenderer = gameObject.GetComponent<SpriteRenderer>();

            if (_controllerIcon == null)
            {
                Debug.LogError("Error: ControllerStatusIndicator._controllerIcon is not set, disabling script.");
                enabled = false;
                return;
            }
            if (_mobileAppIcon == null)
            {
                Debug.LogError("Error: ControllerStatusIndicator._mobileAppIcon is not set, disabling script.");
                enabled = false;
                return;
            }
            if (_controllerConnectionHandler == null)
            {
                Debug.LogError("Error: ControllerStatusIndicator._controllerConnectionHandler is not set, disabling script.");
                enabled = false;
                return;
            }

            _controllerConnectionHandler.OnControllerConnected += HandleOnControllerChanged;
            _controllerConnectionHandler.OnControllerDisconnected += HandleOnControllerChanged;
        }

        void Start()
        {
            SetDefaultIcon();

            UpdateColor();
            UpdateIcon();
        }

        void OnDestroy()
        {
            _controllerConnectionHandler.OnControllerConnected -= HandleOnControllerChanged;
            _controllerConnectionHandler.OnControllerDisconnected -= HandleOnControllerChanged;
        }

        void OnApplicationPause(bool pause)
        {
            if (!pause)
            {
                UpdateColor();
                UpdateIcon();
            }
        }
        #endregion

        #region Private Methods
        /// <summary>
        /// Update the color depending on the controller connection.
        /// </summary>
        private void UpdateColor()
        {
            if (_controllerConnectionHandler.enabled)
            {
                if (_controllerConnectionHandler.IsControllerValid())
                {
                    _spriteRenderer.color = Color.green;
                }
                else
                {
                    _spriteRenderer.color = Color.yellow;
                }
            }
            else
            {
                _spriteRenderer.color = Color.red;
            }
        }

        /// <summary>
        /// Update Icon to show type of connected icon or device allowed.
        /// </summary>
        private void UpdateIcon()
        {
            if (_controllerConnectionHandler.enabled &&
                _controllerConnectionHandler.IsControllerValid())
            {
                switch (_controllerConnectionHandler.ConnectedController.Type)
                {
                    case MLInputControllerType.Control:
                        {
                            _spriteRenderer.sprite = _controllerIcon;
                            break;
                        }
                    case MLInputControllerType.MobileApp:
                        {
                            _spriteRenderer.sprite = _mobileAppIcon;
                            break;
                        }
                }
            }
        }

        /// <summary>
        /// This will set the default icon used to represent the controller.
        /// When the device controller is excluded, MobileApp will be used instead.
        /// </summary>
        private void SetDefaultIcon()
        {
            if ((_controllerConnectionHandler.DevicesAllowed & ControllerConnectionHandler.DeviceTypesAllowed.ControllerLeft) != 0 ||
                (_controllerConnectionHandler.DevicesAllowed & ControllerConnectionHandler.DeviceTypesAllowed.ControllerRight) != 0)
            {
                _spriteRenderer.sprite = _controllerIcon;
            }
            else
            {
                _spriteRenderer.sprite = _mobileAppIcon;
            }
        }
        #endregion

        #region Event Handlers
        private void HandleOnControllerChanged(byte controllerId)
        {
            UpdateColor();
            UpdateIcon();
        }
        #endregion
    }
}
