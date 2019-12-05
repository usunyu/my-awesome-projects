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

namespace UnityEngine.XR.MagicLeap
{
    /// <summary>
    /// Class to automatically handle connection/disconnection events of an input device. By default,
    /// all device types are allowed but it could be modified through the inspector to limit which types to
    /// allow. This class automatically handles the disconnection/reconnection of Control and MLA devices.
    /// This class keeps track of all connected devices matching allowed types. If more than one allowed
    /// device is connected, the first one connected is returned.
    /// </summary>
    [AddComponentMenu("Magic Leap/Controller Connection Handler")]
    public sealed class ControllerConnectionHandler : MonoBehaviour
    {
        #region Public Enum
        /// <summary>
        /// Flags to determine which input devices to allow
        /// </summary>
        [Flags]
        public enum DeviceTypesAllowed : int
        {
            MobileApp = 1 << 0,
            ControllerLeft = 1 << 1,
            ControllerRight = 1 << 2,
        }
        #endregion

        #region Private Variables
        [SerializeField, MagicLeapBitMask(typeof(DeviceTypesAllowed)), Tooltip("Bitmask on which devices to allow.")]
        private DeviceTypesAllowed _devicesAllowed = (DeviceTypesAllowed)~0;

        private List<MLInputController> _allowedConnectedDevices = new List<MLInputController>();
        #endregion

        #region Public Variables
        /// <summary>
        /// Getter for the first allowed connected device, could return null.
        /// </summary>
        public MLInputController ConnectedController
        {
            get
            {
                return (_allowedConnectedDevices.Count == 0) ? null : _allowedConnectedDevices[0];
            }
        }

        /// <summary>
        /// Getter for devices allowed bitmask
        /// </summary>
        public DeviceTypesAllowed DevicesAllowed
        {
            get
            {
                return _devicesAllowed;
            }
        }
        #endregion

        #region Public Events
        /// <summary>
        /// Invoked when a valid controller has connected.
        /// </summary>
        public event Action<byte> OnControllerConnected;

        /// <summary>
        /// Invoked when an invalid controller has disconnected.
        /// </summary>
        public event Action<byte> OnControllerDisconnected;
        #endregion

        #region Unity Methods
        /// <summary>
        /// Starts the MLInput, initializes the first controller, and registers the connection handlers
        /// </summary>
        void Start()
        {
            if (_devicesAllowed == 0)
            {
                Debug.LogErrorFormat("Error: ControllerConnectionHandler._devicesAllowed is invalid, disabling script.");
                enabled = false;
                return;

            }

            bool requestCFUID = DevicesAllowed.HasFlag(DeviceTypesAllowed.ControllerLeft) ||
                DevicesAllowed.HasFlag(DeviceTypesAllowed.ControllerRight);

            if (!MLInput.IsStarted)
            {
                MLInputConfiguration config = new MLInputConfiguration(MLInputConfiguration.DEFAULT_TRIGGER_DOWN_THRESHOLD,
                                                            MLInputConfiguration.DEFAULT_TRIGGER_UP_THRESHOLD,
                                                            requestCFUID);
                MLResult result = MLInput.Start(config);
                if (!result.IsOk)
                {
                    Debug.LogErrorFormat("Error: ControllerConnectionHandler failed starting MLInput, disabling script. Reason: {0}", result);
                    enabled = false;
                    return;
                }
            }

            MLInput.OnControllerConnected += HandleOnControllerConnected;
            MLInput.OnControllerDisconnected += HandleOnControllerDisconnected;

            GetAllowedInput();
        }

        /// <summary>
        /// Unregisters the connection handlers and stops the MLInput
        /// </summary>
        void OnDestroy()
        {
            if (MLInput.IsStarted)
            {
                MLInput.OnControllerDisconnected -= HandleOnControllerDisconnected;
                MLInput.OnControllerConnected -= HandleOnControllerConnected;

                MLInput.Stop();
            }
        }

        #endregion

        #region Private Methods
        /// <summary>
        /// Fills allowed connected devices list with all the connected controllers matching
        /// types set in _devicesAllowed.
        /// </summary>
        private void GetAllowedInput()
        {
            _allowedConnectedDevices.Clear();

            for (int i = 0; i < 2; ++i)
            {
                MLInputController controller = MLInput.GetController(i);
                if (IsDeviceAllowed(controller) && !_allowedConnectedDevices.Exists((device) => device.Id == controller.Id))
                {
                    _allowedConnectedDevices.Add(controller);
                }
            }
        }

        /// <summary>
        /// Checks if a controller exists, is connected, and is allowed.
        /// </summary>
        /// <param name="controller">The controller to be checked for</param>
        /// <returns>True if the controller exists, is connected, and is allowed</returns>
        private bool IsDeviceAllowed(MLInputController controller)
        {
            if (controller == null || !controller.Connected)
            {
                return false;
            }

            return (((_devicesAllowed & DeviceTypesAllowed.MobileApp) != 0 && controller.Type == MLInputControllerType.MobileApp) ||
                ((_devicesAllowed & DeviceTypesAllowed.ControllerLeft) != 0 && controller.Type == MLInputControllerType.Control && controller.Hand == MLInput.Hand.Left) ||
                ((_devicesAllowed & DeviceTypesAllowed.ControllerRight) != 0 && controller.Type == MLInputControllerType.Control && controller.Hand == MLInput.Hand.Right));
        }
        #endregion

        #region Public Methods
        /// <summary>
        /// Checks if there is a controller in the list. This method
        /// does not check if the controller is of the allowed device type
        /// since that's handled by the connection/disconnection handlers.
        /// Should not be called from Awake() or OnEnable().
        /// </summary>
        /// <returns>True if the controller is ready for use, false otherwise</returns>
        public bool IsControllerValid()
        {
            return (ConnectedController != null);
        }

        /// <summary>
        /// Checks if controller list contains controller with input id.
        /// This method does not check if the controller is of the allowed device
        /// type since that's handled by the connection/disconnection handlers.
        /// Should not be called from Awake() or OnEnable().
        /// </summary>
        /// <param name="controllerId"> Controller id to check against </param>
        /// <returns>True if a controller is found, false otherwise</returns>
        public bool IsControllerValid(byte controllerId)
        {
            return _allowedConnectedDevices.Exists((device) => device.Id == controllerId);
        }
        #endregion

        #region Event Handlers
        /// <summary>
        /// Handles the event when a controller connects. If the connected controller
        /// is valid, we add it to the _allowedConnectedDevices list.
        /// </summary>
        /// <param name="controllerId">The id of the controller.</param>
        private void HandleOnControllerConnected(byte controllerId)
        {
            MLInputController newController = MLInput.GetController(controllerId);
            if (IsDeviceAllowed(newController))
            {
                if(_allowedConnectedDevices.Exists((device) => device.Id == controllerId))
                {
                    Debug.LogWarning(string.Format("Connected controller with id {0} already connected.", controllerId));
                    return;
                }

                _allowedConnectedDevices.Add(newController);

                // Notify Listeners
                if (OnControllerConnected != null)
                {
                    OnControllerConnected.Invoke(controllerId);
                }
            }
        }

        /// <summary>
        /// Handles the event when a controller disconnects. If the disconnected
        /// controller happens to be in the _allowedConnectedDevices list, we
        /// remove it from the list.
        /// </summary>
        /// <param name="controllerId">The id of the controller.</param>
        private void HandleOnControllerDisconnected(byte controllerId)
        {
            // Remove from the list of allowed devices.
            int devicesRemoved = _allowedConnectedDevices.RemoveAll((device) => device.Id == controllerId);

            // Notify Listeners of the disconnected device.
            if (devicesRemoved > 0)
            {
                if (OnControllerDisconnected != null)
                {
                    OnControllerDisconnected.Invoke(controllerId);
                }
            }
        }
        #endregion
    }
}
