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

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace UnityEngine.XR.MagicLeap
{
    /// <summary>
    /// Helper script to manage a privilege denied error pop up
    /// </summary>
    [RequireComponent(typeof(Canvas))]
    public class PrivilegeDeniedError : MonoBehaviour
    {
        #region Public Variables
        /// <summary>
        /// The time the error popup will display before it destroys itself
        /// </summary>
        public float TimeToDisplay = 10.0f;
        #endregion

        #region Unity Methods
        /// <summary>
        /// Starts the coroutine that will ultimately destroy this game object and creates the headpose canvas tracker
        /// </summary>
        void Awake()
        {
            StartCoroutine(DestroyAfterTime(TimeToDisplay));
            GetComponent<Canvas>().worldCamera = Camera.main;
            HeadposeCanvas headposeCanvas = gameObject.AddComponent<HeadposeCanvas>();
            headposeCanvas.CanvasDistanceForwards = 1.0f;
            headposeCanvas.CanvasDistanceUpwards = 0.0f;
            headposeCanvas.PositionLerpSpeed = 1.0f;
            headposeCanvas.RotationLerpSpeed = 1.0f;
        }
        #endregion

        #region Private Methods
        IEnumerator DestroyAfterTime(float timeInSeconds)
        {
            yield return new WaitForSeconds(timeInSeconds);
            Destroy(gameObject);
        }
        #endregion

    }
}
