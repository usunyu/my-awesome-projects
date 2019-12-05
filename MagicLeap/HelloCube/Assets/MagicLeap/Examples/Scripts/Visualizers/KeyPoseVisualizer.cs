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

namespace MagicLeap
{
    /// <summary>
    /// Class for tracking a specific Keypose and handling confidence value
    /// based sprite renderer color changes.
    /// </summary>
    [RequireComponent(typeof(SpriteRenderer))]
    public class KeyPoseVisualizer : MonoBehaviour
    {
        #region Private Variables
        private const float ROTATION_SPEED = 100.0f;
        private const float CONFIDENCE_THRESHOLD = 0.95f;

        [SerializeField, Tooltip("KeyPose to track.")]
        private MLHandKeyPose _keyPoseToTrack = MLHandKeyPose.NoPose;

        [Space, SerializeField, Tooltip("Flag to specify if left hand should be tracked.")]
        private bool _trackLeftHand = true;

        [SerializeField, Tooltip("Flag to specify id right hand should be tracked.")]
        private bool _trackRightHand = true;

        private SpriteRenderer _spriteRenderer = null;
        #endregion

        #region Unity Methods
        /// <summary>
        /// Initialize variables.
        /// </summary>
        void Awake()
        {
            _spriteRenderer = GetComponent<SpriteRenderer>();
        }

        /// <summary>
        /// Update color of sprite renderer material based on confidence of the KeyPose.
        /// </summary>
        void Update()
        {
            if (!MLHands.IsStarted)
            {
                _spriteRenderer.material.color = Color.red;
                return;
            }

            float confidenceLeft = _trackLeftHand ? GetKeyPoseConfidence(MLHands.Left) : 0.0f;
            float confidenceRight = _trackRightHand ? GetKeyPoseConfidence(MLHands.Right) : 0.0f;
            float confidenceValue = Mathf.Max(confidenceLeft, confidenceRight);

            Color currentColor = Color.white;

            if (confidenceValue > 0.0f)
            {
                currentColor.r = 1.0f - confidenceValue;
                currentColor.g = 1.0f;
                currentColor.b = 1.0f - confidenceValue;
            }

            // When the keypose is detected for both hands, spin the image continuously.
            if (confidenceValue > 0.0f && confidenceLeft >= CONFIDENCE_THRESHOLD && confidenceRight >= CONFIDENCE_THRESHOLD)
            {
                transform.Rotate(Vector3.up, ROTATION_SPEED * Time.deltaTime, Space.Self);
            }
            else if(confidenceValue > 0.0f && confidenceRight > confidenceLeft)
            {
                // Show Right-Hand Orientation
                transform.localRotation = Quaternion.RotateTowards(transform.localRotation, Quaternion.Euler(0, 180, 0), ROTATION_SPEED * Time.deltaTime);
            }
            else
            {
                // Show Left-Hand Orientation (Default)
                transform.localRotation = Quaternion.RotateTowards(transform.localRotation, Quaternion.Euler(0, 0, 0), ROTATION_SPEED * Time.deltaTime);
            }

            _spriteRenderer.material.color = currentColor;
        }
        #endregion

        #region Private Methods
        /// <summary>
        /// Get the confidence value for the hand being tracked.
        /// </summary>
        /// <param name="hand">Hand to check the confidence value on. </param>
        /// <returns></returns>
        private float GetKeyPoseConfidence(MLHand hand)
        {
            if (hand != null)
            {
                if (hand.KeyPose == _keyPoseToTrack)
                {
                    return hand.KeyPoseConfidence;
                }
            }
            return 0.0f;
        }
        #endregion
    }
}
