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

namespace UnityEngine.XR.MagicLeap
{
    /// <summary>
    /// This class applies a uniform scale to the parent of the attached camera.
    /// </summary>
    [AddComponentMenu("Magic Leap/World Scale")]
    [RequireComponent(typeof(Camera))]
    public class WorldScale : MonoBehaviour
    {
        #region Private Variables
        [SerializeField, Tooltip("The scale that should be applied to the camera.")]
        private float _scale = 0.0f;

        private Camera _camera = null;
        private float _originalNearClipDistance = 0.0f;
        private float _originalFarClipDistance = 0.0f;
        #endregion

        #region Public Properties
        /// <summary>
        /// Returns the scale that is being applied.
        /// </summary>
        public float Scale
        {
            get { return _scale; }
        }

        /// <summary>
        /// Returns the friendly name of the units being used based on the scale.
        /// </summary>
        public string Units
        {
            get
            {
                if (Scale == 1)
                {
                    return "Meters";
                }
                else if (Scale == 100)
                {
                    return "Centimeters";
                }
                else
                {
                    return "Custom";
                }
            }
        }
        #endregion

        #region Unity Methods
        void Start()
        {
            _camera = GetComponent<Camera>();

            // Cache the original Main Camera clip values.
            _originalNearClipDistance = Camera.main.nearClipPlane;
            _originalFarClipDistance = Camera.main.farClipPlane;

            UpdateWorldScale();
        }
        #endregion

        #region Private Methods
        private void UpdateWorldScale()
        {
            // Update the world scale on the main camera's parent.
            _camera.transform.parent.localScale = new Vector3(_scale, _scale, _scale);

            // Calculate the updated clip distances based on the world scale.
            float worldScale = _camera.transform.parent.lossyScale.x;

            // Assumes the original clip distances are in meters.
            _camera.nearClipPlane = _originalNearClipDistance * worldScale;
            _camera.farClipPlane = _originalFarClipDistance * worldScale;

            // Notify the MagicLeapDevice the scale has changed.
            MagicLeapDevice.UpdateWorldScale();
        }
        #endregion
    }
}
