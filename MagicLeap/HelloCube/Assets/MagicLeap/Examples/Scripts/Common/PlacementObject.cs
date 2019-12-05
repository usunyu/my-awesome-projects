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

namespace MagicLeap
{
    /// <summary>
    /// This class allows a GameObject to be used with the PlacementExample script.
    /// The properties defined on each object update the placement criteria.
    /// </summary>
    public class PlacementObject : MonoBehaviour
    {
        #region Private Variables
        [SerializeField, Tooltip("Is placement allowed on horizontal surfaces?")]
        private bool _allowHorizontal = true;

        [SerializeField, Tooltip("Is placement allowed on vertical surfaces?")]
        private bool _allowVertical = true;

        // Used to prevent z-fighting with the visual indicator.
        private readonly Vector3 _padding = new Vector3(0.001f, 0.001f, 0.001f);
        #endregion

        #region Public Properties
        /// <summary>
        /// The Bounds that encapsulates all the mesh objects who are
        /// children to this ContentObject. The bounds returned is the
        /// complete bounding box of the object in local space.
        /// </summary>
        public Bounds LocalBounds
        {
            get
            {
                // Use MeshFilter objects here because their bounding boxes
                // are calculated using local space.
                // Also pass true as a parameter to GetComponentsInChildren<>
                // in case this get function is being called from an object
                // that has not yet been instantiated or activated.
                MeshFilter[] filters = gameObject.GetComponentsInChildren<MeshFilter>(true);
                Bounds newBounds = new Bounds();
                foreach (MeshFilter filter in filters)
                {
#if UNITY_EDITOR
                    if (filter.sharedMesh != null)
                    {
                        newBounds.Encapsulate(new Bounds(
                                filter.transform.TransformVector(filter.sharedMesh.bounds.center),
                                filter.transform.TransformVector(filter.sharedMesh.bounds.size + _padding)
                                ));
                    }
#else
                if (filter.mesh != null)
                {
                    newBounds.Encapsulate(new Bounds(
                        filter.transform.TransformVector(filter.mesh.bounds.center),
                        filter.transform.TransformVector(filter.mesh.bounds.size + _padding)
                        ));
                }
#endif
                }

                return newBounds;
            }
        }

        public bool AllowVertical
        {
            get
            {
                return _allowVertical;
            }
        }

        public bool AllowHorizontal
        {
            get
            {
                return _allowHorizontal;
            }
        }

        public Vector3 Volume
        {
            get
            {
                return LocalBounds.size;
            }
        }
        #endregion

        #region Unity Methods
        void OnDrawGizmosSelected()
        {
            Bounds bounds = LocalBounds;

            Gizmos.color = Color.yellow;
            Gizmos.DrawWireCube(this.transform.position + bounds.center, bounds.size);
        }
        #endregion
    }
}
