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

namespace MagicLeap
{
    /// <summary>
    /// Behavior to represent a Contact in the List Page.
    /// This offloads the coordination with the UI elements.
    /// </summary>
    public class ContactItem : MonoBehaviour
    {
        #region Public Properties
        /// <summary>
        /// The List Page controller.
        /// Must be set when this is instantiated.
        /// </summary>
        [HideInInspector]
        public ContactsListPage ListPage = null;

        /// <summary>
        /// ID of the contact being displayed.
        /// Must be set when this is instantiated.
        /// </summary>
        [HideInInspector]
        public string ID = "";

        /// <summary>
        /// Name of the contact being displayed.
        /// Must be set when this is instantiated.
        /// </summary>
        public string ContactName
        {
            set
            {
                if (_nameLabel != null)
                {
                    _nameLabel.text = value;
                }
            }
        }
        #endregion

        #region Private Properties
        [SerializeField, Tooltip("Button to edit the contact.")]
        private ContactsButton _editButton = null;

        [SerializeField, Tooltip("Button to delete the contact.")]
        private ContactsButton _delButton = null;

        [SerializeField, Tooltip("Text label to show the name.")]
        private Text _nameLabel = null;
        #endregion

        #region Unity Methods
        /// <summary>
        /// Validate inspector properties and attach event handlers.
        /// </summary>
        void Start()
        {
            if (ListPage == null)
            {
                Debug.LogError("Error: ContactItem.ListPage is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_editButton == null)
            {
                Debug.LogError("Error: ContactItem._editButton is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_delButton == null)
            {
                Debug.LogError("Error: ContactItem._delButton is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_nameLabel == null)
            {
                Debug.LogError("Error: ContactItem._nameLabel is not set, disabling script.");
                enabled = false;
                return;
            }

            if (string.IsNullOrEmpty(ID))
            {
                Debug.LogError("Error: ContactItem.ID is not set, disabling script.");
                enabled = false;
                return;
            }

            _editButton.OnTap += HandleSelectContact;
            _delButton.OnTap += HandleDeleteContact;
        }

        /// <summary>
        /// Clean Up.
        /// </summary>
        private void OnDestroy()
        {
            _editButton.OnTap -= HandleSelectContact;
            _delButton.OnTap -= HandleDeleteContact;
        }
        #endregion

        #region Event Handlers
        /// <summary>
        /// Handler when the user selects a contact.
        /// </summary>
        private void HandleSelectContact()
        {
            ListPage.LoadContact(ID);
        }

        /// <summary>
        /// Handler when the user wants to delete a contact.
        /// </summary>
        private void HandleDeleteContact()
        {
            ListPage.DeleteContact(ID);
        }
        #endregion
    }
}
