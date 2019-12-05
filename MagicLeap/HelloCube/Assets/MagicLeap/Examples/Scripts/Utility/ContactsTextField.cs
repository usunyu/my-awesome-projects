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

namespace MagicLeap
{
    /// <summary>
    /// A Text Field template that works with VirtualCursor
    /// </summary>
    [RequireComponent(typeof(Text))]
    public class ContactsTextField : MonoBehaviour
    {
        #region Public Events
        public delegate void TextChangedEvent(string newText);

        /// <summary>
        /// Triggered when the text changes.
        /// </summary>
        /// <param name="newText">Updated string</param>
        public event TextChangedEvent OnTextUpdated;
        #endregion

        #region Private Variables
        [SerializeField, Tooltip("Reference contact button to associate events with")]
        private ContactsButton _button = null;

        [SerializeField, Tooltip("Field of editable text")]
        private Text _label = null;

        private string _content = string.Empty;

        /// <summary>
        /// Flag to determine if any new keyboard input should be received by this instance
        /// </summary>
        private bool _isSelected = false;
        #endregion

        #region Public Properties
        /// <summary>
        /// Getter/setter for the Text stored by this text field.
        /// </summary>
        public string Text
        {
            get
            {
                return _content;
            }
            set
            {
                if (_content != value)
                {
                    _content = value;
                    if (OnTextUpdated != null)
                    {
                        OnTextUpdated(_content);
                    }
                    RefreshText();
                }
            }
        }
        #endregion

        #region Unity Events
        /// <summary>
        /// Validate inspector properties, initialize variables, and attach event handlers.
        /// </summary>
        void Awake()
        {
            if (_button == null)
            {
                Debug.LogError("Error: ContactsTextField._button is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_label == null)
            {
                Debug.LogError("Error: ContactsTextField._label is not set, disabling script.");
                enabled = false;
                return;
            }

            _content = _label.text;

            _button.OnCursorEnter += HandleCursorEnter;
            _button.OnCursorLeave += HandleCursorLeave;
            _button.OnTap += HandleTap;
        }

        /// <summary>
        /// Propagate enabling of this component to reference button.
        /// </summary>
        void OnEnable()
        {
            _button.enabled = true;
        }

        /// <summary>
        /// Propagate disabling of this component to reference button.
        /// </summary>
        void OnDisable()
        {
            _button.enabled = false;
        }

        /// <summary>
        /// Clean up.
        /// </summary>
        void OnDestroy()
        {
            _button.OnCursorEnter -= HandleCursorEnter;
            _button.OnCursorLeave -= HandleCursorLeave;
            _button.OnTap -= HandleTap;
        }

        /// <summary>
        /// Update loop to check if text has changed
        /// </summary>
        void LateUpdate()
        {
            if (_content != _label.text)
            {
                if (OnTextUpdated != null)
                {
                    OnTextUpdated(_content);
                }
                RefreshText();
            }
        }
        #endregion

        #region Event Handlers
        /// <summary>
        /// Handler when cursor hovers over associated button.
        /// </summary>
        private void HandleCursorEnter()
        {
            _isSelected = true;
        }

        /// <summary>
        /// Handler when cursor leaves over associated button.
        /// </summary>
        private void HandleCursorLeave()
        {
            _isSelected = false;
        }

        /// <summary>
        /// Handler when user taps on associated button.
        /// </summary>
        private void HandleTap()
        {
            Text = string.Empty;
            _isSelected = true;
        }

        /// <summary>
        /// Handler for new keyboard events.
        /// </summary>
        void OnGUI()
        {
            if (!_isSelected)
            {
                return;
            }

            Event e = Event.current;
            if (e.type == EventType.KeyDown)
            {
                if (e.keyCode == KeyCode.Backspace)
                {
                    if (_content.Length > 0)
                    {
                        _content = _content.Substring(0, _content.Length - 1);
                    }
                }
                else if (!Char.IsControl(e.character))
                {
                    if (e.modifiers == EventModifiers.Shift)
                    {
                        _content += char.ToUpper(e.character);
                    }
                    else
                    {
                        _content += e.character;
                    }
                }
            }
        }
        #endregion

        #region Private Methods
        /// <summary>
        /// Updates the text displayed.
        /// </summary>
        private void RefreshText()
        {
            _label.text = _content;
        }
        #endregion
    }
}
