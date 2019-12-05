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
    /// Class outputs to input UI.Text the most up to date gestures
    /// and confidence values for each of the hands.
    /// </summary>
    [RequireComponent(typeof(HandTracking))]
    public class HandTrackingExample : MonoBehaviour
    {
        #region Private Variables
        [SerializeField, Tooltip("Text to display gesture status to.")]
        private Text _statusText = null;
        #endregion

        #region Unity Methods
        /// <summary>
        /// Check editor set variables for null references.
        /// </summary>
        void Awake()
        {
            if (_statusText == null)
            {
                Debug.LogError("Error: HandTrackingExample._statusText is not set, disabling script.");
                enabled = false;
                return;
            }
        }

        /// <summary>
        ///  Polls the Gestures API for up to date confidence values.
        /// </summary>
        void Update()
        {
            if (MLHands.IsStarted)
            {
                _statusText.text = string.Format(
                    "Current Hand Gestures\nLeft: {0}, {2}% confidence\nRight: {1}, {3}% confidence",
                    MLHands.Left.KeyPose.ToString(),
                    MLHands.Right.KeyPose.ToString(),
                    (MLHands.Left.KeyPoseConfidence * 100.0f).ToString("n0"),
                    (MLHands.Right.KeyPoseConfidence * 100.0f).ToString("n0"));
            }
        }
        #endregion
    }
}
