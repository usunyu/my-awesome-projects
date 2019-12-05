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
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.MagicLeap;

namespace MagicLeap
{
    /// <summary>
    /// This is the main controller for the Contacts Example.
    /// This directly interfaces with the Contacts API and propagates
    /// the state changes to the relevant UI elements.
    /// </summary>
    public class ContactsExample : MonoBehaviour
    {
        #region Private Variables
        [SerializeField, Tooltip("Privilege Requester")]
        private PrivilegeRequester _privilegeRequester = null;

        [SerializeField, Tooltip("Example Root Canvas")]
        private GameObject _root = null;

        [SerializeField, Tooltip("Help Screen")]
        private GameObject _helpScreen = null;

        [SerializeField, Tooltip("Root of List Page")]
        private ContactsListPage _listPage = null;

        [SerializeField, Tooltip("Root of Contact Page")]
        private ContactPage _contactPage = null;

        [SerializeField, Tooltip("Status text for logs")]
        private Text _statusText = null;

        private Dictionary<string, MLContactsContact> _loadedContacts = new Dictionary<string, MLContactsContact>();
        private bool _needToReloadContacts = true;
        private string _lastSearchQuery = "";
        #endregion

        #region Public Properties
        /// <summary>
        /// Search pattern. Leave blank to load all contacts.
        /// </summary>
        public string SearchQuery
        {
            get
            {
                return _lastSearchQuery;
            }
            set
            {
                if (_lastSearchQuery != value)
                {
                    _lastSearchQuery = value;
                    LoadContactsFromAPI(value);
                }
            }
        }
        #endregion

        #region Unity Methods
        /// <summary>
        /// Validate inspector properties, initialize scene, and attach event handlers.
        /// </summary>
        void Start()
        {
            if (_privilegeRequester == null)
            {
                Debug.LogError("Error: ContactsExample._privilegeRequester is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_root == null)
            {
                Debug.LogError("Error: ContactsExample._root is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_helpScreen == null)
            {
                Debug.LogError("Error: ContactsExample._helpScreen is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_listPage == null)
            {
                Debug.LogError("Error: ContactsExample._listParent is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_contactPage == null)
            {
                Debug.LogError("Error: ContactsExample._contactPage is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_statusText == null)
            {
                Debug.LogError("Error: ContactsExample._statusText is not set, disabling script.");
                enabled = false;
                return;
            }

            _privilegeRequester.OnPrivilegesDone += HandlePrivilegesDone;

            _root.SetActive(false);
            _helpScreen.SetActive(true);

        }

        /// <summary>
        /// Clean Up.
        /// </summary>
        void OnDestroy()
        {
            _privilegeRequester.OnPrivilegesDone -= HandlePrivilegesDone;

            MLInput.OnControllerButtonUp -= HandleControllerButtonUp;

            if (MLContacts.IsStarted)
            {
                MLContacts.OnContactAdded -= HandleOnContactAdded;
                MLContacts.OnContactUpdated -= HandleOnContactUpdated;
                MLContacts.OnContactDeleted -= HandleOnContactDeleted;
                MLContacts.OnOperationFailed -= HandleOnOperationFailed;
                MLContacts.Stop();
            }
        }
        #endregion

        #region Public Methods
        /// <summary>
        /// Updates on-screen log.
        /// </summary>
        /// <param name="msg">Log message</param>
        public void Log(string msg)
        {
            _statusText.text = msg;
        }

        /// <summary>
        /// Switch to list page. May reload contacts if needed.
        /// </summary>
        public void LoadListPage()
        {
            Log("");

            _listPage.gameObject.SetActive(true);
            _contactPage.gameObject.SetActive(false);

            if (_needToReloadContacts)
            {
                LoadContactsFromAPI();
            }
        }

        /// <summary>
        /// Validates a contact.
        /// </summary>
        /// <param name="contact">Contact to be validated</param>
        /// <returns>Result of Validation</returns>
        public MLResult ValidateContact(MLContactsContact contact)
        {
            return MLContacts.ValidateContact(contact);
        }

        /// <summary>
        /// Loads an existing contact and switches to contact page.
        /// </summary>
        /// <param name="id">ID of Contact</param>
        public void LoadContact(string id)
        {
            Log("");

            _listPage.gameObject.SetActive(false);
            _contactPage.gameObject.SetActive(true);

            if (!string.IsNullOrEmpty(id) && _loadedContacts.ContainsKey(id))
            {
                _contactPage.Populate(new MLContactsContact(_loadedContacts[id]));
            }
            else
            {
                _contactPage.Populate(new MLContactsContact());
            }
        }

        /// <summary>
        /// Adds a new contact or updates an existing contact. Called by ContactPage.
        /// </summary>
        /// <param name="contact">New Contact</param>
        /// <returns>Result of operation</returns>
        public MLResult SaveContact(MLContactsContact contact)
        {
            Log("Saving...");

            ulong requestHandle = 0;
            MLResult result;

            if (!string.IsNullOrEmpty(contact.ID))
            {
                Debug.LogFormat("Updating existing contact with id = {0}", contact.ID);
                result = MLContacts.UpdateContact(contact, out requestHandle);
            }
            else
            {
                Debug.LogFormat("Saving new contact with name = {0}", contact.Name);
                result = MLContacts.AddContact(contact, out requestHandle);
            }

            if (!result.IsOk)
            {
                Debug.LogErrorFormat("Error: ContactsExample failed to save contact. Reason: {0}", result);
                Log(string.Format("<color=red>Failed to save contact. {0}</color>", result));
            }

            return result;
        }

        /// <summary>
        /// Deletes a contact. Called by ContactListPage.
        /// </summary>
        /// <param name="id">ID of the Contact</param>
        public void DeleteContact(string id)
        {
            Log("Deleting contact");

            ulong requestHandle = 0;

            if (!string.IsNullOrEmpty(id) && _loadedContacts.ContainsKey(id))
            {
                MLResult result = MLContacts.DeleteContact(_loadedContacts[id], out requestHandle);
                if (!result.IsOk)
                {
                    Debug.LogErrorFormat("Error: ContactsExample failed to delete contact. Reason: {0}", result);
                    Log(string.Format("<color=red>Failed to delete contact. {0}</color>", result));
                }
            }
            else
            {
                Debug.LogErrorFormat("Error: ContactsExample failed to delete contact. Reason: Invalid ID {0}", id);
                Log("<color=red>Failed to delete contact.</color>");
            }
        }
        #endregion

        #region Private Methods
        /// <summary>
        /// Fetches all contacts matching the query, if any.
        /// </summary>
        /// <param name="query">Search Query</param>
        private void LoadContactsFromAPI(string query = "")
        {
            _loadedContacts.Clear();
            _needToReloadContacts = false;

            MLResult result;
            MLContactsListPage fillPage = null;

            if (string.IsNullOrEmpty(query))
            {
                fillPage = MLContacts.CreateListPage(MLContacts.DEFAULT_FETCH_LIMIT, out result, RefreshListPageReady, HandlePageFailed);
                if (!result.IsOk)
                {
                    Log(string.Format("<color=red>Cannot load contacts. Reason: {0}</color>", result));
                    Debug.LogErrorFormat("Error: ContactsExample failed to create the contacts list page, disabling script. Reason: {0}", result);
                    enabled = false;
                    return;
                }
            }
            else
            {
                // change second parameter to limit searching by name, email address, or phone number only
                fillPage = MLContacts.CreateSearchPage(query, MLContactsSearchField.All, MLContacts.DEFAULT_FETCH_LIMIT, out result, RefreshListPageReady, HandlePageFailed);
                if (!result.IsOk)
                {
                    Log(string.Format("<color=red>Cannot search contacts. Reason: {0}</color>", result));
                    Debug.LogErrorFormat("Error: ContactsExample failed to create the contacts search page, disabling script. Reason: {0}", result);
                    enabled = false;
                    return;
                }
            }

            // begin fetching contacts
            result = fillPage.NextPage();
            if (!result.IsOk)
            {
                Log(string.Format("<color=red>Cannot load contacts. Reason: {0}</color>", result));
                Debug.LogErrorFormat("Error: ContactsExample failed to request the next page of contacts, disabling script. Reason: {0}", result);
                enabled = false;
                return;
            }
        }

        /// <summary>
        /// Start the API and register callbacks.
        /// </summary>
        private void StartupAPI()
        {
            MLResult result = MLContacts.Start();
            if (!result.IsOk)
            {
                Debug.LogErrorFormat("Error: ContactsExample failed starting MLContacts, disabling script. Reason: {0}", result);
                enabled = false;
                return;
            }

            Log("<color=green>API Started</color>");

            MLContacts.OnContactAdded += HandleOnContactAdded;
            MLContacts.OnContactUpdated += HandleOnContactUpdated;
            MLContacts.OnContactDeleted += HandleOnContactDeleted;
            MLContacts.OnOperationFailed += HandleOnOperationFailed;
            MLInput.OnControllerButtonUp += HandleControllerButtonUp;

            LoadListPage();
        }
        #endregion

        #region Event Handlers
        /// <summary>
        /// Toggle showing help screen on/off.
        /// </summary>
        /// <param name="controllerId">ID of the controller</param>
        /// <param name="button">Button released</param>
        private void HandleControllerButtonUp(byte controllerId, MLInputControllerButton button)
        {
            if (button == MLInputControllerButton.HomeTap)
            {
                _root.SetActive(!_root.activeInHierarchy);
                _helpScreen.SetActive(!_helpScreen.activeInHierarchy);
            }
        }

        /// <summary>
        /// Handler when Contacts API fails any operation.
        /// </summary>
        /// <param name="operationResult">Result of operation</param>
        /// <param name="requestHandle">Handle of the request</param>
        private void HandleOnOperationFailed(MLContactsOperationResult operationResult, ulong requestHandle)
        {
            string reason = "unspecified failure";
            switch (operationResult.Status)
            {
                case MLContactsOperationStatus.Duplicate:
                    reason = "A contact, with the same details, already exist.";
                    break;
                case MLContactsOperationStatus.Fail:
                    reason = "An internal error has occurred.";
                    break;
                case MLContactsOperationStatus.NotFound:
                    reason = "The contact does not exist.";
                    break;
                case MLContactsOperationStatus.Success:
                    // this case should never be reached in this callback.
                    break;
            }

            Debug.LogErrorFormat("Error: ContactsExample encountered an error from an operation. {0}", reason);
            Log(string.Format("<color=red>Operation Failed. {0}</color>", reason));
        }

        /// <summary>
        /// Handler when Contacts API successfully removes a contact.
        /// This is called from the list contacts page.
        /// </summary>
        /// <param name="operationResult">Result of operation</param>
        /// <param name="requestHandle">Handle of the request</param>
        private void HandleOnContactDeleted(MLContactsOperationResult operationResult, ulong requestHandle)
        {
            LoadContactsFromAPI();
            Log("<color=green>Contact deleted</color>");
        }

        /// <summary>
        /// Handler when Contacts API successfully updates an existing contact.
        /// This is called from the add/edit contact page.
        /// </summary>
        /// <param name="operationResult">Result of operation</param>
        /// <param name="requestHandle">Handle of the request</param>
        private void HandleOnContactUpdated(MLContactsOperationResult operationResult, ulong requestHandle)
        {
            _contactPage.Populate(operationResult.Contact);

            _needToReloadContacts = true;
            Log("<color=green>Contact updated</color>");
        }

        /// <summary>
        /// Handler when Contacts API successfully adds a new contact.
        /// This is called from the add/edit contact page.
        /// </summary>
        /// <param name="operationResult">Result of operation</param>
        /// <param name="requestHandle">Handle of the request</param>
        private void HandleOnContactAdded(MLContactsOperationResult operationResult, ulong requestHandle)
        {
            _contactPage.Populate(operationResult.Contact);

            _needToReloadContacts = true;
            Log("<color=green>Contact added</color>");
        }

        /// <summary>
        /// Handler when privileges have been requested.
        /// </summary>
        /// <param name="result">Result of the operation</param>
        private void HandlePrivilegesDone(MLResult result)
        {
            if (!result.IsOk)
            {
                if (result.Code == MLResultCode.PrivilegeDenied)
                {
                    Instantiate(Resources.Load("PrivilegeDeniedError"));
                }

                Log("<color=red>Privileges Error: " + result.ToString() + "</color>");
                Debug.LogErrorFormat("Error: ContactsExample failed to get requested privileges, disabling script. Reason: {0}", result);
                enabled = false;
                return;
            }

            Log("<color=green>Privileges Granted</color>");

            StartupAPI();
        }

        /// <summary>
        /// Handler when page is retrieved successfully. Store the list of contacts in memory and
        /// fetch the next page. If this is the last page, display them.
        /// </summary>
        /// <param name="page">Page with list of contacts</param>
        private void RefreshListPageReady(MLContactsListPage page)
        {
            foreach (MLContactsContact contact in page.ContactsList)
            {
                _loadedContacts[contact.ID] = contact;
            }

            if (page.Status == MLContactsListPage.PageStatus.LastPage)
            {
                _listPage.PopulateList(new List<MLContactsContact>(_loadedContacts.Values));
            }
            else
            {
                MLResult result = page.NextPage(); // automatically fetches the next page; triggering RefreshListPageReady when done or HandlePageFailed on failure
                if (!result.IsOk)
                {
                    Log("<color=red>RefreshListPageReady() Error: " + result.ToString() + "</color>");
                    Debug.LogErrorFormat("Error: ContactsExample failed to request the next page while refreshing the list, disabling script. Reason was: {0}", result);
                    enabled = false;
                    return;
                }
            }
        }

        /// <summary>
        /// Handler when page failed to retrieve.
        /// </summary>
        /// <param name="page">Page that failed</param>
        /// <param name="result">Result of the operation</param>
        private void HandlePageFailed(MLContactsListPage page, MLResult result)
        {
            Log(string.Format("<color=red>HandlePageFailed() Error: {0}</color>", result));
            Debug.LogErrorFormat("Error: ContactsExample failed to retreive a page. Reason was: {0}", result);
        }
        #endregion
    }
}
