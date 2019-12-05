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

namespace UnityEngine.XR.MagicLeap
{
    /// <summary>
    /// Script used to position this Canvas object directly in front of the user by
    /// using lerp functionality to give it a smooth look. Components on the canvas
    /// should function normally.
    /// </summary>
    [AddComponentMenu("Magic Leap/Headpose Canvas")]
    [RequireComponent(typeof(Canvas))]
    public class HeadposeCanvas : MonoBehaviour
    {
        #region Public Variables
        [Tooltip("The forwards distance from the camera that this object should be placed.")]
        public float CanvasDistanceForwards = 1.5f;

        [Tooltip("The upwards distance from the camera that this object should be placed.")]
        public float CanvasDistanceUpwards = 0.0f;

        [Tooltip("The speed at which this object changes its position.")]
        public float PositionLerpSpeed = 5f;

        [Tooltip("The speed at which this object changes its rotation.")]
        public float RotationLerpSpeed = 5f;
        #endregion

        #region Private Varibles
        // The canvas that is attached to this object.
        private Canvas _canvas;

        // The camera this object will be in front of.
        private Camera _camera;
        #endregion

        #region Unity Methods
        /// <summary>
        /// Initializes variables and verifies that necessary components exist.
        /// </summary>
        void Awake()
        {
            _canvas = GetComponent<Canvas>();
            _camera = _canvas.worldCamera;

            // Disable this component if
            // it failed to initialize properly.
            if (_canvas == null)
            {
                Debug.LogError("Error: HeadposeCanvas._canvas is not set, disabling script.");
                enabled = false;
                return;
            }
            if (_camera == null)
            {
                Debug.LogError("Error: HeadposeCanvas._camera is not set, disabling script.");
                enabled = false;
                return;
            }
        }

        /// <summary>
        /// Update position and rotation of this canvas object to face the camera using lerp for smoothness.
        /// </summary>
        void Update()
        {
            // Move the object CanvasDistance units in front of the camera.
            float posSpeed = Time.deltaTime * PositionLerpSpeed;
            Vector3 posTo = _camera.transform.position + (_camera.transform.forward * CanvasDistanceForwards) + (_camera.transform.up * CanvasDistanceUpwards);
            transform.position = Vector3.SlerpUnclamped(transform.position, posTo, posSpeed);

            // Rotate the object to face the camera.
            float rotSpeed = Time.deltaTime * RotationLerpSpeed;
            Quaternion rotTo = Quaternion.LookRotation(transform.position - _camera.transform.position);
            transform.rotation = Quaternion.Slerp(transform.rotation, rotTo, rotSpeed);
        }
        #endregion
    }
}
