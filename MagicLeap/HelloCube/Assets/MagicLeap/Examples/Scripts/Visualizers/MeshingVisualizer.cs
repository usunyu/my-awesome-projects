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

#if UNITY_EDITOR || PLATFORM_LUMIN

using UnityEngine;
using UnityEngine.Experimental.XR;
using UnityEngine.XR.MagicLeap;

namespace MagicLeap
{
    /// <summary>
    /// This class allows you to change meshing properties at runtime, including the rendering mode.
    /// Manages the MLSpatialMapper behaviour and tracks the meshes.
    /// </summary>
    public class MeshingVisualizer : MonoBehaviour
    {
        public enum RenderMode
        {
            None,
            Wireframe,
            PointCloud,
            Occlusion
        }

        #region Private Variables
        [SerializeField, Tooltip("The MLSpatialMapper from which to get update on mesh types.")]
        private MLSpatialMapper _mlSpatialMapper = null;

        [SerializeField, Tooltip("The material to apply for occlusion.")]
        private Material _occlusionMaterial = null;

        [SerializeField, Tooltip("The material to apply for wireframe rendering.")]
        private Material _wireframeMaterial = null;

        [SerializeField, Tooltip("The material to apply for point cloud rendering.")]
        private Material _pointCloudMaterial = null;

        private RenderMode _renderMode = RenderMode.Wireframe;
        #endregion

        #region Unity Methods
        /// <summary>
        /// Start listening for MLSpatialMapper events.
        /// </summary>
        void Awake()
        {
            // Validate all required game objects.
            if (_mlSpatialMapper == null)
            {
                Debug.LogError("Error: MeshingVisualizer._mlSpatialMapper is not set, disabling script!");
                enabled = false;
                return;
            }
            if(_occlusionMaterial == null)
            {
                Debug.LogError("Error: MeshingVisualizer._occlusionMaterial is not set, disabling script!");
                enabled = false;
                return;
            }
            if (_wireframeMaterial == null)
            {
                Debug.LogError("Error: MeshingVisualizer._wireframeMaterial is not set, disabling script!");
                enabled = false;
                return;
            }
            if (_pointCloudMaterial == null)
            {
                Debug.LogError("Error: MeshingVisualizer._pointCloudMaterial is not set, disabling script!");
                enabled = false;
                return;
            }
        }

        /// <summary>
        /// Register for new and updated freagments.
        /// </summary>
        void Start()
        {
            _mlSpatialMapper.meshAdded += HandleOnMeshReady;
            _mlSpatialMapper.meshUpdated += HandleOnMeshReady;
        }

        /// <summary>
        /// Unregister callbacks.
        /// </summary>
        void OnDestroy()
        {
            _mlSpatialMapper.meshAdded -= HandleOnMeshReady;
            _mlSpatialMapper.meshUpdated -= HandleOnMeshReady;
        }
        #endregion

        #region Public Methods
        /// <summary>
        /// Set the render material on the meshes.
        /// </summary>
        /// <param name="mode">The render mode that should be used on the material.</param>
        public void SetRenderers(RenderMode mode)
        {
            if (_renderMode != mode)
            {
                // Set the render mode.
                _renderMode = mode;

                // Clear existing meshes to process the new mesh type.
                switch (_renderMode)
                {
                    case RenderMode.Wireframe:
                    case RenderMode.Occlusion:
                    {
                        _mlSpatialMapper.meshType = MLSpatialMapper.MeshType.Triangles;

                        break;
                    }
                    case RenderMode.PointCloud:
                    {
                        _mlSpatialMapper.meshType = MLSpatialMapper.MeshType.PointCloud;

                        break;
                    }
                }

                _mlSpatialMapper.DestroyAllMeshes();
                _mlSpatialMapper.RefreshAllMeshes();
            }
        }
        #endregion

        #region Private Methods
        /// <summary>
        /// Updates the currently selected render material on the MeshRenderer.
        /// </summary>
        /// <param name="meshRenderer">The MeshRenderer that should be updated.</param>
        private void UpdateRenderer(MeshRenderer meshRenderer)
        {
            if (meshRenderer != null)
            {
                // Toggle the GameObject(s) and set the correct materia based on the current RenderMode.
                if (_renderMode == RenderMode.None)
                {
                    meshRenderer.enabled = false;
                }
                else if (_renderMode == RenderMode.PointCloud)
                {
                    meshRenderer.enabled = true;
                    meshRenderer.material = _pointCloudMaterial;
                }
                else if (_renderMode == RenderMode.Wireframe)
                {
                    meshRenderer.enabled = true;
                    meshRenderer.material = _wireframeMaterial;
                }
                else if (_renderMode == RenderMode.Occlusion)
                {
                    meshRenderer.enabled = true;
                    meshRenderer.material = _occlusionMaterial;
                }
            }
        }
        #endregion

        #region Event Handlers
        /// <summary>
        /// Handles the MeshReady event, which tracks and assigns the correct mesh renderer materials.
        /// </summary>
        /// <param name="meshId">Id of the mesh that got added / upated.</param>
        private void HandleOnMeshReady(TrackableId meshId)
        {
            if (_mlSpatialMapper.meshIdToGameObjectMap.ContainsKey(meshId))
            {
                UpdateRenderer(_mlSpatialMapper.meshIdToGameObjectMap[meshId].GetComponent<MeshRenderer>());
            }
        }
        #endregion
    }
}

#endif
