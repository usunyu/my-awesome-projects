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
    /// A utility behavior to draw a sequence of sprites unto a sprite renderer
    /// </summary>
    public class SpriteSequenceAnimation : MonoBehaviour
    {
        #region Private Variables
        [SerializeField, Tooltip("Sprite Renderer")]
        private SpriteRenderer _spriteRenderer = null;

        [SerializeField, Tooltip("Sprites to cycle through")]
        private Sprite[] _sprites = null;

        [SerializeField, Tooltip("Duration of a frame in seconds (1/fps)"), Min(0.01f)]
        private float _frameDuration = 0.033f;

        private int _currIndex = 0;
        private float _currDuration = 0;
        #endregion

        #region Unity Methods
        void Awake()
        {
            if (_spriteRenderer == null)
            {
                Debug.LogError("Error: SpriteSequenceAnimation._spriteRenderer is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_sprites == null)
            {
                Debug.LogError("Error: SpriteSequenceAnimation._sprites is not set, disabling script.");
                enabled = false;
                return;
            }
        }

        void Update()
        {
            _currDuration += Time.deltaTime;
            if (_currDuration >= _frameDuration)
            {
                _currDuration -= _frameDuration;
                _currIndex++;
                _currIndex %= _sprites.Length;

                _spriteRenderer.sprite = _sprites[_currIndex];
            }
        }
        #endregion
    }
}
