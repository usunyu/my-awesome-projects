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
    /// Helper script that will set Main Camera values to those recommended for the Magic Leap Platform
    /// </summary>
    [AddComponentMenu("Magic Leap/Scene Optimizer")]
    public class MagicLeapSceneOptimizer : MonoBehaviour
    {
        #region Public Variables
        /// <summary>
        /// Correct any issues with the camera on startup
        /// </summary>
        public bool FixProblemsOnStartup = true;

        /// <summary>
        /// The minimum recommended near clip value
        /// </summary>
        public readonly float MINIMUM_NEAR_CLIP_METERS = MagicLeapDevice.MinimumNearClipDistance;

        /// <summary>
        /// The recommended clear mode for the camera
        /// </summary>
        public readonly CameraClearFlags DEFAULT_CLEAR_FLAGS = CameraClearFlags.SolidColor;

        /// <summary>
        /// The recommended clear color for the camera
        /// </summary>
        public readonly Color DEFAULT_CLEAR_COLOR = new Color(0.0f, 0.0f, 0.0f, 0.0f);

        /// <summary>
        /// The recommended camera position
        /// </summary>
        public readonly Vector3 DEFAULT_CAMERA_POSITION = Vector3.zero;

        /// <summary>
        /// The recommended camera rotation
        /// </summary>
        public readonly Quaternion DEFAULT_CAMERA_ROTATION = Quaternion.identity;

        /// <summary>
        /// The recommended camera scale
        /// </summary>
        public readonly Vector3 DEFAULT_CAMERA_SCALE = Vector3.one;
        #endregion

        #region Private Variables
        Camera _mainCamera;
        #endregion


        #region Unity Methods
        /// <summary>
        /// Startup function to check for any problems and fix them if FixProblemsOnStartup is true
        /// </summary>
        void Start()
        {
            _mainCamera = Camera.main;
            FixupCamera(FixProblemsOnStartup);
        }
        #endregion

        #region Public Methods
        /// <summary>
        /// Check for any camera discrepancies, warn about them and optionally fix them
        /// </summary>
        /// <param name="fixIssues">Whether or not to fix any found problems</param>
        public void FixupCamera(bool fixIssues)
        {
            Vector3 cameraScale = GetCameraScale();
            float scale = 1.0f;
            if (!(Mathf.Approximately(cameraScale.x, cameraScale.y) && Mathf.Approximately(cameraScale.x, cameraScale.z)))
            {
                // Non uniform scale
                scale = (cameraScale.x + cameraScale.y + cameraScale.z) / 3.0f;
            }
            else
            {
                scale = cameraScale.x;
            }

            if ((_mainCamera.nearClipPlane / scale) < MINIMUM_NEAR_CLIP_METERS)
            {
                Debug.LogWarning("[Magic Leap] The near clipping plane of the main camera is closer than " + MINIMUM_NEAR_CLIP_METERS + "m, which can cause artifacts.");

                if (fixIssues)
                {
                    _mainCamera.nearClipPlane = MINIMUM_NEAR_CLIP_METERS * scale;
                }
            }

            if ((_mainCamera.clearFlags != DEFAULT_CLEAR_FLAGS) ||
                (_mainCamera.backgroundColor != DEFAULT_CLEAR_COLOR))
            {
                Debug.LogWarning("[Magic Leap] The main camera background is not solid black with an alpha of zero, which is recommended for the Magic Leap platform.");

                if (fixIssues)
                {
                    _mainCamera.clearFlags = DEFAULT_CLEAR_FLAGS;
                    _mainCamera.backgroundColor = DEFAULT_CLEAR_COLOR;
                }
            }

            if ((_mainCamera.transform.localPosition != DEFAULT_CAMERA_POSITION) ||
                (_mainCamera.transform.localRotation != DEFAULT_CAMERA_ROTATION) ||
                (_mainCamera.transform.localScale != DEFAULT_CAMERA_SCALE))
            {
                Debug.LogWarning("[Magic Leap] The main camera isn't at the origin. This will cause head tracking problems.");

                if (fixIssues)
                {
                    _mainCamera.transform.localPosition = DEFAULT_CAMERA_POSITION;
                    _mainCamera.transform.localRotation = DEFAULT_CAMERA_ROTATION;
                    _mainCamera.transform.localScale = DEFAULT_CAMERA_SCALE;
                }
            }
        }
        #endregion

        /// <summary>
        /// Get the scale of the camera based on its parent transform
        /// </summary>
        /// <returns></returns>
        private Vector3 GetCameraScale()
        {
            Vector3 scale = Vector3.one;

            if (_mainCamera)
            {
                if (transform.parent)
                {
                    scale = transform.parent.lossyScale;
                }
            }

            return scale;
        }
    }
}
