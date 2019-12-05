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
    /// This class allows the user to cycle between the Vignette modes: (Off, On, Mask)
    /// and adjust the power of the effect. This helps to gradually blend the edges of
    /// the FOV to remove the hard edge once the limit is reached.
    /// </summary>
    public class VignetteExample : MonoBehaviour
    {
        #region Private Variables
        [SerializeField, Tooltip("A reference to the controller connection handler in the scene.")]
        private ControllerConnectionHandler _controllerConnectionHandler = null;

        [SerializeField, Tooltip("A reference to the Vignette component.")]
        private Vignette _vignette = null;

        [SerializeField, Tooltip("Text to display the current vignette mode and power.")]
        private Text _statusLabel = null;

        private const float VIGNETTE_SCALE = 20f;
        #endregion

        #region Unity Methods
        void Awake()
        {
            if (_controllerConnectionHandler == null)
            {
                Debug.LogError("Error VignetteExample._controllerConnectionHandler not set, disabling script.");
                enabled = false;
                return;
            }

            if (_statusLabel == null)
            {
                Debug.LogError("Error: VignetteExample._statusLabel is not set, disabling script.");
                enabled = false;
                return;
            }

            MLInput.OnControllerButtonDown += HandleOnButtonDown;
        }

        void OnDestroy()
        {
            MLInput.OnControllerButtonDown -= HandleOnButtonDown;
        }

        void Update()
        {
            _vignette.VignettePower = (1 - _controllerConnectionHandler.ConnectedController.TriggerValue) * VIGNETTE_SCALE;
            UpdateStatusText();
        }
        #endregion

        #region Private Methods
        private void UpdateStatusText()
        {
            _statusLabel.text = string.Format("Vignette Mode: {0}\n\nVignette Power: {1}", _vignette.VignetteState, _vignette.VignettePower);
        }
        #endregion

        #region Event Handlers
        private void HandleOnButtonDown(byte controllerId, MLInputControllerButton button)
        {
            if (_controllerConnectionHandler.IsControllerValid(controllerId))
            {
                if (button == MLInputControllerButton.Bumper)
                {
                    _vignette.CycleVignetteState();
                }
                else if (button == MLInputControllerButton.HomeTap)
                {
                    _vignette.Reset();
                }
            }
        }
        #endregion
    }
}
