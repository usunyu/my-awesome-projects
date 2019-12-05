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
    /// <summary>
    /// A Button template that works with VirtualCursor
    /// </summary>
    [RequireComponent(typeof(Collider), typeof(Image))]
    public class ContactsButton : MonoBehaviour
    {
        #region Public Events
        /// <summary>
        /// Triggered when the cursor hovers over this button.
        /// </summary>
        public event Action OnCursorEnter;

        /// <summary>
        /// Triggered when the cursor leaves this button.
        /// </summary>
        public event Action OnCursorLeave;

        /// <summary>
        /// Triggered when the user taps while cursor is hovering over this button.
        /// </summary>
        public event Action OnTap;
        #endregion

        #region Private Variables
        [SerializeField, Tooltip("Image to manipulate the color with")]
        private Image _image = null;
        [SerializeField, Tooltip("Collider to interact with the cursor")]
        private Collider _collider = null;

        [SerializeField, Tooltip("Color of Image while cursor hovers over")]
        private Color _hoverColor = Color.white;
        private Color _idleColor = Color.clear;

        [SerializeField, Tooltip("Tooltip string"), TextArea]
        private string _tooltip = string.Empty;
        #endregion

        #region Public Properties
        /// <summary>
        /// Text to be shown as tooltip.
        /// </summary>
        public string TooltipText
        {
            get
            {
                return _tooltip;
            }
        }
        #endregion

        #region Unity Methods
        /// <summary>
        /// Validate inspector properties and initialize variables.
        /// </summary>
        void Awake()
        {
            if (_image == null)
            {
                Debug.LogError("Error: ContactsButton._image is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_collider == null)
            {
                Debug.LogError("Error: ContactsButton._collider is not set, disabling script.");
                enabled = false;
                return;
            }

            _idleColor = _image.color;
        }

        /// <summary>
        /// Enable image and collider when this is enabled.
        /// </summary>
        void OnEnable()
        {
            _image.enabled = true;
            _collider.enabled = true;
        }

        /// <summary>
        /// Disable image and collider when this is disabled.
        /// </summary>
        void OnDisable()
        {
            _image.color = _idleColor;
            _image.enabled = false;
            _collider.enabled = false;
        }
        #endregion

        #region Public Methods
        /// <summary>
        /// Called by VirtualCursor when leaving the button.
        /// Triggers associated event.
        /// </summary>
        public void CursorLeave()
        {
            _image.color = _idleColor;
            if (OnCursorLeave != null)
            {
                OnCursorLeave();
            }
        }

        /// <summary>
        /// Called by VirtualCursor when entering the button.
        /// Triggers associated event.
        /// </summary>
        public void CursorEnter()
        {
            _image.color = _hoverColor;
            if (OnCursorEnter != null)
            {
                OnCursorEnter();
            }
        }

        /// <summary>
        /// Called by VirtualCursor when the user Taps while hovering of this button.
        /// Triggers associated event.
        /// </summary>
        public void Tap()
        {
            if (OnTap != null)
            {
                OnTap();
            }
        }
        #endregion
    }
}
