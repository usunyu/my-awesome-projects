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

namespace UnityEngine.XR.MagicLeap
{
    /// <summary>
    /// Automatically requests specified privileges. Exposes delegate for when the requests are done.
    /// Fails if at least one privilege is denied.
    /// </summary>
    [AddComponentMenu("Magic Leap/Privilege Requester")]
    public class PrivilegeRequester : MonoBehaviour
    {
        // <summary/>
        public enum PrivilegeState
        {
            /// <summary>Requester has not started.</summary>
            Off,

            /// <summary>Failed to start because a privilege system failure.</summary>
            StartFailed,

            /// <summary>Requester has started requesting privileges.</summary>
            Started,

            /// <summary>All privileges have been requested. Waiting on results.</summary>
            Requested,

            /// <summary>All privileges were granted.</summary>
            Succeeded,

            /// <summary>One or more of the privileges were denied, or some other privilege failure request occured.</summary>
            Failed
        }

        PrivilegeState _state = PrivilegeState.Off;

        /// <summary>
        /// Current state of the requester.
        /// </summary>
        public PrivilegeState State
        {
            get { return _state; }
        }

        /// <summary>
        /// Subscribed methods are called when all privileges have been granted,
        /// or if a failure occured with the request. The possible result codes are:
        ///
        /// MLResultCode.Ok if all privileges were granted.
        ///
        /// MLResultCode.PrivilegeDenied if one or more of the requested privileges were denied.
        ///
        /// MLResultCode.UnspecifiedFailure if the privilege system failed to startup.
        /// </summary>
        public event Action<MLResult> OnPrivilegesDone = delegate { };

        // TODO: Disable editor edit when state is StartFailed, Started, Requested, Failed or Succeeded states.
        [SerializeField] [Tooltip("Requested privileges. " +
            "Can also be modified via script using Privileges property. " +
            "Should only be changed in Editor mode. Changes with the component active will not be immediately reflected in behavior.")]
        MLRuntimeRequestPrivilegeId[] _privileges;

        /// <summary>
        /// Requested privileges. Should be set on Awake.
        /// </summary>
        public MLRuntimeRequestPrivilegeId[] Privileges
        {
            get { return _privileges; }
            set { _privileges = value; }
        }

        readonly List<MLPrivilegeId> _privilegesToRequest = new List<MLPrivilegeId>();
        readonly List<MLPrivilegeId> _privilegesGranted = new List<MLPrivilegeId>();

        #region Unity Methods
        /// <summary>
        /// Start the Privileges API and set the Privilege State
        /// </summary>
        void Start()
        {
            MLResult result = MLPrivileges.Start();
            if (result.IsOk)
            {
                _privilegesToRequest.AddRange(Array.ConvertAll(_privileges, tempPrivilege => (MLPrivilegeId)tempPrivilege));
                _state = PrivilegeState.Started;
            }
            else
            {
                Debug.LogErrorFormat("Error: PrivilegeRequester failed starting MLPrivileges, disabling script. Reason: {0}", result);
                _state = PrivilegeState.StartFailed;
                OnPrivilegesDone(result);
                enabled = false;
            }
        }

        /// <summary>
        /// Move through the privilege stages
        /// </summary>
        void Update()
        {
            /// Privileges have not yet been granted, go through the privilege states.
            if (_state != PrivilegeState.Succeeded)
            {
                UpdatePrivilege();
            }
        }

        /// <summary>
        /// If the Privileges API is running, stop it.
        /// </summary>
        void OnDestroy()
        {
            if (MLPrivileges.IsStarted)
            {
                MLPrivileges.Stop();
            }
        }

        /// <summary>
        /// Cannot make the assumption that a reality privilege is still granted after
        /// returning from pause. Return the application to the state where it
        /// requests privileges needed and clear out the list of already granted
        /// privileges. Also, disable the camera and unregister callbacks.
        /// </summary>
        /// <remarks>
        /// Not necessary, but harmless, for sensitive privileges.
        /// </remarks>
        void OnApplicationPause(bool pause)
        {
            if (pause && _state != PrivilegeState.Off)
            {
                _privilegesGranted.Clear();
                _state = PrivilegeState.Started;
            }
        }
        #endregion

        #region Private Methods
        /// <summary>
        /// Handle the privilege states.
        /// </summary>
        private void UpdatePrivilege()
        {
            switch (_state)
            {
                /// Privilege API has been started successfully, ready to make requests.
                case PrivilegeState.Started:
                {
                    RequestPrivileges();
                    break;
                }
                /// Privilege requests have been made, wait until all privileges are granted before enabling the feature that requires privileges.
                case PrivilegeState.Requested:
                {
                    foreach (MLPrivilegeId priv in _privilegesToRequest)
                    {
                        if (!_privilegesGranted.Contains(priv))
                        {
                            return;
                        }
                    }
                    _state = PrivilegeState.Succeeded;
                    OnPrivilegesDone(MLResult.ResultOk);
                    break;
                }
                /// Privileges have been denied, respond appropriately.
                case PrivilegeState.Failed:
                {
                    OnPrivilegesDone(new MLResult(MLResultCode.PrivilegeDenied));
                    enabled = false;
                    break;
                }
            }
        }

        /// <summary>
        /// Request each needed privilege.
        /// </summary>
        private void RequestPrivileges()
        {
            foreach (MLPrivilegeId priv in _privilegesToRequest)
            {
                MLResult result = MLPrivileges.RequestPrivilegeAsync(priv, HandlePrivilegeAsyncRequest);
                if (!result.IsOk)
                {
                    Debug.LogErrorFormat("Error: PrivilegeRequester failed requesting {0} privilege. Reason: {1}", priv, result);
                    _state = PrivilegeState.Failed;
                    return;
                }
            }

            _state = PrivilegeState.Requested;
        }
        #endregion

        #region Event Handlers
        /// <summary>
        /// Handles the result that is received from the query to the Privilege API.
        /// If one of the required privileges are denied, set the Privilege state to Denied.
        /// <param name="result">The resulting status of the query</param>
        /// <param name="privilegeId">The privilege being queried</param>
        /// </summary>
        private void HandlePrivilegeAsyncRequest(MLResult result, MLPrivilegeId privilegeId)
        {
            if (result.Code == MLResultCode.PrivilegeGranted)
            {
                _privilegesGranted.Add(privilegeId);
                Debug.LogFormat("{0} Privilege Granted", privilegeId);
            }
            else
            {
                Debug.LogErrorFormat("{0} Privilege Error: {1}, disabling example.", privilegeId, result);
                _state = PrivilegeState.Failed;
            }
        }
        #endregion
    }
}
