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

namespace UnityEngine.XR.MagicLeap
{
    /// <summary>
    /// The class applies a vignette effect to the attached camera.
    /// This effect is achieved by using a material with the Magic Leap/Vignette shader.
    /// </summary>
    [AddComponentMenu("Magic Leap/Vignette")]
    [RequireComponent(typeof(Camera))]
    public class Vignette : MonoBehaviour
    {
        public enum State { OFF = 0, ON = 1, MASK = 2 };

        #region Private Variables
        [SerializeField, Tooltip("The power to use for the vignette intensity.")]
        private float _vignettePower = 10.0f;

        [SerializeField, Tooltip("A reference to the vignette material.")]
        private Material _vignetteMaterial = null;

        private float _defaultVigettePower;
        private int _vignetteState = (int)State.ON;

        private const float VIGNETTE_MIN = 1.0f;
        private const float VIGNETTE_MAX = 20.0f;
        #endregion

        #region Public Properties
        /// <summary>
        /// The power of the vignette.
        /// </summary>
        public float VignettePower
        {
            get
            {
                return _vignettePower;
            }
            set
            {
                _vignettePower = Mathf.Clamp(value, VIGNETTE_MIN, VIGNETTE_MAX);
            }
        }

        /// <summary>
        /// The state of the vignette.
        /// </summary>
        public State VignetteState
        {
            get { return (State)_vignetteState; }
        }
        #endregion

        #region Unity Methods
        void Awake()
        {
            // Cache the default vignette power.
            _defaultVigettePower = _vignettePower;

            // Reset to ensure the material properties are properly set.
            Reset();
        }

        void OnRenderImage(RenderTexture srcTexture, RenderTexture destTexture)
        {
            _vignetteMaterial.SetFloat("_VignettePower", VignettePower);
            Graphics.Blit(srcTexture, destTexture, _vignetteMaterial);
        }
        #endregion

        #region Public Methods
        /// <summary>
        /// Cycle to the next available vignette state.
        /// </summary>
        public void CycleVignetteState()
        {
            _vignetteState = (_vignetteState + 1) % 3;

            switch ((State)_vignetteState)
            {
                case State.OFF:
                    {
                        enabled = false;
                        break;
                    }

                case State.ON:
                    {
                        enabled = true;
                        _vignetteMaterial.SetInt("_VignetteMode", (int)State.ON);
                    }
                    break;

                case State.MASK:
                    {
                        enabled = true;
                        _vignetteMaterial.SetInt("_VignetteMode", (int)State.MASK);
                    }
                    break;
            }
        }

        /// <summary>
        /// Reset the state and power of the vignette to default values.
        /// </summary>
        public void Reset()
        {
            _vignettePower = _defaultVigettePower;

            _vignetteState = (int)State.OFF;
            CycleVignetteState();
        }
        #endregion
    }
}
