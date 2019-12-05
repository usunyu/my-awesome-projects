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
using UnityEngine.Serialization;
using UnityEngine.XR.MagicLeap;

using System.Collections;

namespace MagicLeap
{
    /// <summary>
    /// This provides textual state feedback for the connected controller.
    /// </summary>
    public class VideoError : MonoBehaviour
    {
        #region Public Variables
        public Texture2D errorImage;
        #endregion

        private void Awake()
        {
            if (errorImage == null)
            {
                Debug.LogError("Error: VideoError no image found, disabling script.");
                enabled = false;
                return;
            }
        }

        public void ShowError()
        {
            Renderer renderer = GetComponent<Renderer>();
            if (renderer)
            {
                renderer.material.SetTexture("_MainTex", errorImage);
            }
        }
    }
}