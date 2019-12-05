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
    /// This class displays the current world scale information
    /// and allows the user to adjust the distance of the marker
    /// within the range of (0.25 Meters - 1.00 Meters).
    /// </summary>
    public class WorldScaleExample : MonoBehaviour
    {
        #region Private Variables
        [SerializeField, Tooltip("The reference to the controller connection handler in the scene.")]
        private ControllerConnectionHandler _controllerConnectionHandler = null;

        [SerializeField, Tooltip("Text to display the current distance and world scale.")]
        private Text _statusLabel = null;

        [SerializeField, Tooltip("The Transform of the visual marker, which is attached to the end of the line.")]
        private Transform _marker = null;

        [SerializeField, Tooltip("The world scale scene component attached to the main camera.")]
        private WorldScale _worldScale = null;

        private const float ADJUSTMENT_DISTANCE_METERS = 0.25f;
        private const float MINIMUM_DISTANCE_METERS = 0.25f;
        private const float MAXIMUM_DISTANCE_METERS = 1;
        #endregion

        #region Unity Methods
        void Start()
        {
            if (_controllerConnectionHandler == null)
            {
                Debug.LogError("Error: WorldScaleExample._controllerConnectionHandler is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_statusLabel == null)
            {
                Debug.LogError("Error: WorldScaleExample._statusLabel is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_marker == null)
            {
                Debug.LogError("Error: WorldScaleExample._marker is not set, disabling script.");
                enabled = false;
                return;
            }

            // Register listeners.
            MLInput.OnControllerTouchpadGestureStart += HandleOnTouchpadGestureStart;
        }

        void OnDestroy()
        {
            // Unregister listeners.
            MLInput.OnControllerTouchpadGestureStart -= HandleOnTouchpadGestureStart;
        }

        void Update()
        {
            _statusLabel.text = string.Format(
                "Scale:\t\t\t{0}\n" +
                "Distance:\t{1} {2}", _worldScale.Scale, _marker.localPosition.z * _worldScale.Scale, _worldScale.Units);
        }
        #endregion

        #region Event Handlers
        private void HandleOnTouchpadGestureStart(byte controllerId, MLInputControllerTouchpadGesture gesture)
        {
            if (_controllerConnectionHandler.IsControllerValid(controllerId) && gesture.Type == MLInputControllerTouchpadGestureType.Swipe)
            {
                // Increase / Decrease the marker distance based on the swipe gesture.
                if (gesture.Direction == MLInputControllerTouchpadGestureDirection.Up)
                {
                    if (_marker.localPosition.z < MAXIMUM_DISTANCE_METERS)
                    {
                        _marker.localPosition = new Vector3(0, 0, _marker.localPosition.z + ADJUSTMENT_DISTANCE_METERS);
                    }
                }
                else if (gesture.Direction == MLInputControllerTouchpadGestureDirection.Down)
                {
                    if (_marker.localPosition.z > MINIMUM_DISTANCE_METERS)
                    {
                        _marker.localPosition = new Vector3(0, 0, _marker.localPosition.z - ADJUSTMENT_DISTANCE_METERS);
                    }
                }
            }
        }
        #endregion
    }
}
