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
    /// This class implements the functionality for the object with this component
    /// to follow an input transform.
    /// </summary>
    public class TransformFollower : MonoBehaviour
    {
        #region Public Variables
        [Tooltip("The object that should be followed.")]
        public Transform ObjectToFollow;

        [Tooltip("Following should respect(local) or ignore(world) hierarchy.")]
        public bool UseLocalTransform = true;
        #endregion

        #region Unity Methods
        /// <summary>
        /// Updates the transform of the object.
        /// </summary>
        void Update()
        {
            if (ObjectToFollow != null)
            {
                if (UseLocalTransform)
                {
                    transform.localPosition = ObjectToFollow.localPosition;
                    transform.localRotation = ObjectToFollow.localRotation;
                }
                else
                {
                    transform.position = ObjectToFollow.position;
                    transform.rotation = ObjectToFollow.rotation;
                }
            }
        }
        #endregion
    }
}
