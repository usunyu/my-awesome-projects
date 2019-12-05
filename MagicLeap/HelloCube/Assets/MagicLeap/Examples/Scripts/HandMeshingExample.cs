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
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.MagicLeap;

namespace MagicLeap
{
    public class HandMeshingExample : MonoBehaviour
    {
        #region Public Enum
        /// <summary>
        /// Different Render Modes for the Hand Meshing Example
        /// </summary>
        public enum RenderMode : uint
        {
            Occlusion,
            Flat,
            Wireframe,
            Paused
        }
        #endregion

        #region Private Properties
        [SerializeField, Tooltip("The Hand Meshing Behavior to control")]
        private MLHandMeshingBehavior _behavior = null;

        [SerializeField, Tooltip("Material used in Occlusion Render Mode")]
        private Material _occlusionMaterial = null;

        [SerializeField, Tooltip("Material used in Flat Render Mode")]
        private Material _flatMaterial = null;

        [SerializeField, Tooltip("Material used in Wireframe Render Mode")]
        private Material _wireframeMaterial = null;

        [SerializeField, Tooltip("Duration, in seconds, to hold key pose before changing render modes"), Min(1.0f)]
        private float _secondsBetweenModes = 2;

        [SerializeField, Tooltip("Key Pose to switch render modes")]
        private MLHandKeyPose _keyposeToSwitch = MLHandKeyPose.Ok;

        [SerializeField, Tooltip("Status Text")]
        private Text _status = null;

        [SerializeField, Tooltip("Switching tooltip text")]
        private TextMesh _switchTooltip = null;

        private const float _minimumConfidence = 0.8f;
        private float _timer = 0;
        private RenderMode _mode = RenderMode.Occlusion;
        #endregion

        #region Unity Methods
        /// <summary>
        /// Validate and initialize properties
        /// </summary>
        void Start()
        {
            if (_behavior == null)
            {
                Debug.LogError("Error: HandMeshingExample._behavior is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_occlusionMaterial == null)
            {
                Debug.LogError("Error: HandMeshingExample._occlusionMaterial is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_flatMaterial == null)
            {
                Debug.LogError("Error: HandMeshingExample._flatMaterial is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_wireframeMaterial == null)
            {
                Debug.LogError("Error: HandMeshingExample._wireframeMaterial is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_status == null)
            {
                Debug.LogError("Error: HandMeshingExample._status is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_switchTooltip == null)
            {
                Debug.LogError("Error: HandMeshingExample._switchTooltip is not set, disabling script.");
                enabled = false;
                return;
            }
            _switchTooltip.gameObject.SetActive(false);

            // Note: MLHands is not necessary to use Hand Meshing.
            // It is only used for switching the render modes in this example.
            MLResult result = MLHands.Start();
            if (!result.IsOk)
            {
                Debug.LogError("Error: HandMeshingExample failed to start MLHands, disabling script.");
                enabled = false;
                return;
            }
            MLHands.KeyPoseManager.EnableKeyPoses(new [] { _keyposeToSwitch }, true, true);
            MLHands.KeyPoseManager.SetPoseFilterLevel(MLPoseFilterLevel.ExtraRobust);
            MLHands.KeyPoseManager.SetKeyPointsFilterLevel(MLKeyPointFilterLevel.ExtraSmoothed);

            _timer = _secondsBetweenModes;
        }

        void OnDestroy()
        {
            if (MLHands.IsStarted)
            {
                MLHands.KeyPoseManager.DisableAllKeyPoses();
                MLHands.Stop();
            }
        }

        /// <summary>
        /// Updates timer and render mode
        /// </summary>
        void Update()
        {
            if (!IsSwitchingModes())
            {
                _timer = _secondsBetweenModes;
                _switchTooltip.gameObject.SetActive(false);
                return;
            }

            _timer -= Time.deltaTime;
            if (_timer > 0)
            {
                _switchTooltip.gameObject.SetActive(true);
                UpdateSwitchTooltip();
                return;
            }

            _timer = _secondsBetweenModes;
            _mode = GetNextRenderMode();

            UpdateHandMeshingBehavior();
            UpdateStatusText();
        }
        #endregion

        #region Private Methods
        private bool IsSwitchingModes()
        {
            return (MLHands.Right.KeyPose == _keyposeToSwitch && MLHands.Right.KeyPoseConfidence > _minimumConfidence);
        }

        private void UpdateStatusText()
        {
            _status.text = string.Format("Current Render Mode: <color=green>{0}</color>", _mode);
        }

        private RenderMode GetNextRenderMode()
        {
            return (_mode == RenderMode.Paused) ? RenderMode.Occlusion : (RenderMode)((uint)_mode + 1);
        }

        private void UpdateSwitchTooltip()
        {
            _switchTooltip.transform.position = MLHands.Right.Thumb.KeyPoints[0].Position;
            _switchTooltip.text = string.Format("Switching to <color=yellow>{0}</color> in {1} seconds",
                GetNextRenderMode(), _timer.ToString("0.0"));
        }

        private void UpdateHandMeshingBehavior()
        {
            switch (_mode)
            {
                case RenderMode.Occlusion:
                    _behavior.enabled = true;
                    _behavior.MeshMaterial = _occlusionMaterial;
                    break;
                case RenderMode.Flat:
                    _behavior.MeshMaterial = _flatMaterial;
                    break;
                case RenderMode.Wireframe:
                    _behavior.MeshMaterial = _wireframeMaterial;
                    break;
                case RenderMode.Paused:
                    _behavior.enabled = false;
                    break;
            }
        }
        #endregion
    }
}
