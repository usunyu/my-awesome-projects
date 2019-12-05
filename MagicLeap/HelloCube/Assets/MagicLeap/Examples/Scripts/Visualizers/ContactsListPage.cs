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

using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.MagicLeap;

namespace MagicLeap
{
    /// <summary>
    /// UI controller for the List Page. This lists the contacts provided by
    /// ContactsExample and attaches the relevant event handlers.
    /// </summary>
    public class ContactsListPage : MonoBehaviour
    {
        #region Private Variables
        [SerializeField, Tooltip("Contacts Example main controller.")]
        private ContactsExample _mainController = null;

        [SerializeField, Tooltip("Button to add a new Contact.")]
        private ContactsButton _addContactButton = null;

        [SerializeField, Tooltip("Text field for the search criteria.")]
        private ContactsTextField _searchTextField = null;

        [SerializeField, Tooltip("Prefab of a Contact List Item.")]
        private ContactItem _contactItem = null;

        [SerializeField, Tooltip("Button to delete a non-existing Contact.")]
        private ContactsButton _deleteNonExistentContactButton = null;

        private List<GameObject> _contactGOList = new List<GameObject>();
        #endregion

        #region Unity Methods
        /// <summary>
        /// Validate inspector properties, initialize page, and attach event handlers.
        /// </summary>
        void Start()
        {
            if (_mainController == null)
            {
                Debug.LogError("Error: ContactsListPage._mainController is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_addContactButton == null)
            {
                Debug.LogError("Error: ContactsListPage._addContactButton is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_searchTextField == null)
            {
                Debug.LogError("Error: ContactsListPage._searchTextField is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_contactItem == null)
            {
                Debug.LogError("Error: ContactsListPage._contactItem is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_deleteNonExistentContactButton == null)
            {
                Debug.LogError("Error: ContactsListPage._delNonExistentContactButton is not set, disabling script.");
                enabled = false;
                return;
            }

            _addContactButton.OnTap += HandleAddContact;
            _searchTextField.OnTextUpdated += HandleSearchTextUpdated;
            _deleteNonExistentContactButton.OnTap += HandleNonExistingContactDeleteTap;
        }

        /// <summary>
        /// Clean Up.
        /// </summary>
        void OnDestroy()
        {
            _addContactButton.OnTap -= HandleAddContact;
            _searchTextField.OnTextUpdated -= HandleSearchTextUpdated;
            _deleteNonExistentContactButton.OnTap -= HandleNonExistingContactDeleteTap;

            DestroyListItems();
        }
        #endregion

        #region Event Handlers
        /// <summary>
        /// Handler when a new search query is entered.
        /// </summary>
        /// <param name="newText">New search query</param>
        private void HandleSearchTextUpdated(string newText)
        {
            _mainController.SearchQuery = newText;
        }

        /// <summary>
        /// Handler when user wants to create a new contact.
        /// </summary>
        private void HandleAddContact()
        {
            _mainController.LoadContact(string.Empty);
        }

        /// <summary>
        /// Special Handler when the user wants to see what happens when
        /// attempting to delete a non-existent contact.
        /// </summary>
        private void HandleNonExistingContactDeleteTap()
        {
            _mainController.DeleteContact("InvalidContactId");
        }
        #endregion

        #region Public Methods
        /// <summary>
        /// Clear out list items displayed.
        /// </summary>
        public void DestroyListItems()
        {
            foreach (GameObject item in _contactGOList)
            {
                Destroy(item);
            }

            _contactGOList.Clear();
        }

        /// <summary>
        /// Views the selected contact. Called by ContactItem.
        /// </summary>
        /// <param name="id">ID of the Contact</param>
        public void LoadContact(string id)
        {
            _mainController.LoadContact(id);
        }

        /// <summary>
        /// Deletes the selected contact. Called by ContactItem.
        /// </summary>
        /// <param name="id">ID of the Contact</param>
        public void DeleteContact(string id)
        {
            _mainController.DeleteContact(id);
        }

        /// <summary>
        /// Rebuilds the displayed list. Called by ContactsExample.
        /// </summary>
        /// <param name="contacts">List of contacts to display</param>
        public void PopulateList(List<MLContactsContact> contacts)
        {
            DestroyListItems();

            for (int i = 0; i < contacts.Count; ++i)
            {
                MLContactsContact contact = contacts[i];
                GameObject contactItemGO = Instantiate(_contactItem.gameObject, transform);
                contactItemGO.transform.localPosition = new Vector3(-0.25f, 0.04f - (0.03f * i), 0);

                ContactItem contactItem = contactItemGO.GetComponent<ContactItem>();
                contactItem.ListPage = this;
                contactItem.ID = contact.ID;
                contactItem.ContactName = contact.Name;

                _contactGOList.Add(contactItemGO);
            }
        }
        #endregion
    }
}
