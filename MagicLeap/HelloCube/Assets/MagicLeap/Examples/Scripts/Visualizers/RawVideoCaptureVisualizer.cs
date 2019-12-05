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
using UnityEngine;
using UnityEngine.XR.MagicLeap;

namespace MagicLeap
{
    /// <summary>
    /// This class handles visualization of the video and the UI with the status
    /// of the recording.
    /// </summary>
    public class RawVideoCaptureVisualizer : MonoBehaviour
    {
        #region Private Variables
        [SerializeField, Tooltip("The renderer to show the video capture on")]
        private Renderer _screenRenderer = null;

        [Header("Visuals")]
        [SerializeField, Tooltip("Object that will show up when recording")]
        private GameObject _recordingIndicator = null;

        [SerializeField, Tooltip("Posterization levels of the frame processor")]
        private byte _posterizationLevels = 4;

        private Texture2D _rawVideoTexture = null;
        #endregion

        #region Unity Methods
        /// <summary>
        /// Check for all required variables to be initialized.
        /// </summary>
        void Start()
        {
            if(_screenRenderer == null)
            {
                Debug.LogError("Error: RawVideoCaptureVisualizer._screenRenderer is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_recordingIndicator == null)
            {
                Debug.LogError("Error: RawVideoCaptureVisualizer._recordingIndicator is not set, disabling script.");
                enabled = false;
                return;
            }

            _screenRenderer.enabled = true;
        }
        #endregion

        #region Event Handlers
        /// <summary>
        /// Handles video capture being started.
        /// </summary>
        public void OnCaptureStarted()
        {
            // Manage canvas visuals
            _recordingIndicator.SetActive(true);
        }

        /// <summary>
        /// Handles video capture ending.
        /// </summary>
        public void OnCaptureEnded()
        {
            // Manage canvas visuals
            _recordingIndicator.SetActive(false);
        }

        /// <summary>
        /// Display the raw video frame on the texture object.
        /// </summary>
        /// <param name="extras">Unused.</param>
        /// <param name="frameData">Contains raw frame bytes to manipulate.</param>
        /// <param name="frameMetadata">Unused.</param>
        public void OnRawCaptureDataReceived(MLCameraResultExtras extras, YUVFrameInfo frameData, MLCameraFrameMetadata frameMetadata)
        {
            YUVBuffer yBuffer = frameData.Y;

            if (_rawVideoTexture == null)
            {
                _rawVideoTexture = new Texture2D((int)yBuffer.Stride, (int)yBuffer.Height, TextureFormat.R8, false);
                _rawVideoTexture.filterMode = FilterMode.Point;
                _screenRenderer.material.mainTexture = _rawVideoTexture;
                _screenRenderer.material.mainTextureScale = new Vector2(yBuffer.Width / (float)yBuffer.Stride, -1.0f);
            }

            ProcessImage(yBuffer.Data, _posterizationLevels);
            _rawVideoTexture.LoadRawTextureData(yBuffer.Data);
            _rawVideoTexture.Apply();
        }

        /// <summary>
        /// Modify `data` by applying a posterization transformation to it.
        /// </summary>
        /// <param name="data">The byte array to modify.</param>
        /// <param name="levels">The threshold levels to split each byte into.</param>
        public static void ProcessImage(byte[] data, byte levels)
        {
            byte factor = (byte) (byte.MaxValue / levels);
            for (int i = 0; i < data.Length; i++)
            {
                data[i] = (byte) (data[i] / factor * factor);
            }
        }
        #endregion
    }
}
