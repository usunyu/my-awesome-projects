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
    /// This class handles the functionality of updating the scene based on the lighting conditions.
    /// This includes the intensity, ambient intensity & color, and also updates the animation
    /// of a plant model which react to the light intensity changes.
    /// The UI also displays the detected light intensity level indicated in the top right.
    /// </summary>

    [RequireComponent(typeof(PrivilegeRequester))]
    public class LightTrackingExample : MonoBehaviour
    {
        #region Private Variables
        [SerializeField, Tooltip("The primary light that is used in the scene.")]
        private Light _light = null;

        [SerializeField, Tooltip("The image (filled) that is used to display the light intensity.")]
        private Image _lightIntensity = null;

        [SerializeField, Tooltip("The model animator that will update based on the light intensity.")]
        private Animator _animator = null;

        [SerializeField, Tooltip("The cursor used to visualize the location of the plant.")]
        private Transform _raycastCursor = null;

        [SerializeField, Tooltip("The transform of the plant model used in the scene.")]
        private Transform _plantModel = null;

        private Color _color = Color.clear;
        private float _normalizedLuminance;
        private float _maxLuminance = 0;

        private PrivilegeRequester _privilegeRequester = null;
        #endregion

        #region Unity Methods
        private void Start()
        {
            if (_light == null)
            {
                Debug.LogError("Error: LightTrackingExample._light is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_lightIntensity == null)
            {
                Debug.LogError("Error: LightTrackingExample._lightIntensity is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_animator == null)
            {
                Debug.LogError("Error: LightTrackingExample._animator is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_plantModel == null)
            {
                Debug.LogError("Error: LightTrackingExample._plantModel is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_raycastCursor == null)
            {
                Debug.LogError("Error: LightTrackingExample._raycastCursor is not set, disabling script.");
                enabled = false;
                return;
            }

            _privilegeRequester = GetComponent<PrivilegeRequester>();

            // Register Listeners
            // Before enabling the camera, the scene must wait until the privileges have been granted.
            _privilegeRequester.OnPrivilegesDone += HandleOnPrivilegesDone;
            MLInput.OnControllerButtonDown += HandleOnButtonDown;
        }

        void OnDestroy()
        {
            // Unregister Listeners
            _privilegeRequester.OnPrivilegesDone -= HandleOnPrivilegesDone;
            MLInput.OnControllerButtonDown -= HandleOnButtonDown;

            if (MLLightingTracker.IsStarted)
            {
                MLLightingTracker.Stop();
            }
        }

        void Update()
        {
            if (MLLightingTracker.IsStarted)
            {
                // Set the maximum observed luminance, so we can normalize it.
                if (_maxLuminance < (MLLightingTracker.AverageLuminance / 3.0f))
                {
                    _maxLuminance = (MLLightingTracker.AverageLuminance / 3.0f);
                }

                _color = MLLightingTracker.GlobalTemperatureColor;
                _normalizedLuminance = (float)(System.Math.Min(System.Math.Max((double)MLLightingTracker.AverageLuminance, 0.0), _maxLuminance) / _maxLuminance);

                RenderSettings.ambientLight = _color;
                RenderSettings.ambientIntensity = _normalizedLuminance;

                // Adjust the light for the plant animation.
                _animator.SetFloat("Sunlight", _normalizedLuminance);

                // Set the light intensity of the scene light.
                if (_light != null)
                {
                    _light.intensity = _normalizedLuminance;
                }

                // Set the light intensity meter.
                if (_lightIntensity != null)
                {
                    _lightIntensity.fillAmount = _normalizedLuminance;
                }
            }
        }
        #endregion

        #region Event Handlers
        /// <summary>
        /// Responds to privilege requester result.
        /// </summary>
        /// <param name="result"/>
        private void HandleOnPrivilegesDone(MLResult result)
        {
            if (!result.IsOk)
            {
                if (result.Code == MLResultCode.PrivilegeDenied)
                {
                    Instantiate(Resources.Load("PrivilegeDeniedError"));
                }

                Debug.LogErrorFormat("Error: LightTrackingExample failed to get all requested privileges, disabling script. Reason: {0}", result);
                enabled = false;
                return;
            }

            Debug.Log("Succeeded in requesting all privileges");

            result = MLLightingTracker.Start();
            if (!result.IsOk)
            {
                Debug.LogErrorFormat("Error: LightTrackingExample failed starting MLLightingTracker, disabling script. Reason: {0}", result);
                enabled = false;
                return;
            }
        }

        /// <summary>
        /// Toggles the placement of the plant model.
        /// </summary>
        /// <param name="controllerId"></param>
        /// <param name="button"></param>
        private void HandleOnButtonDown(byte controllerId, MLInputControllerButton button)
        {
            if (button == MLInputControllerButton.Bumper)
            {
                if(_plantModel.transform.parent == null)
                {
                    _raycastCursor.gameObject.SetActive(true);

                    _plantModel.transform.SetParent(_raycastCursor);
                    _plantModel.transform.localPosition = Vector3.zero;
                    _plantModel.transform.localRotation = Quaternion.Euler(90, 0, 0);
                }
                else if (_plantModel.transform.parent == _raycastCursor)
                {
                    _raycastCursor.gameObject.SetActive(false);

                    _plantModel.transform.SetParent(null);
                }
            }
        }
        #endregion
    }
}
