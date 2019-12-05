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

namespace UnityEngine.XR.MagicLeap
{
    /// <summary>
    /// This is a component you can use to make a specific game object a persistent anchor/point
    /// in space. This component would try to restore itself on Start and will notify the listener
    /// if it's restored correctly or not. If this is the first time it would automatically look
    /// for the closest real world PCF to bind itself to. You can simply put your content you
    /// want to persist under the game object with this behavior attached to it.
    /// </summary>
    [AddComponentMenu("Magic Leap/Persistent Behavior")]
    public class MLPersistentBehavior : MonoBehaviour
    {
        #region Public Enumerations
        /// <summary>
        /// Possible states of the MLPersistentBehavior
        /// </summary>
        public enum Status
        {
            /// <summary>
            /// Binding created and saved successfully
            /// </summary>
            BINDING_CREATED,

            /// <summary>
            /// Binding updated successfully
            /// </summary>
            BINDING_UPDATED,

            /// <summary>
            /// Binding destroyed succesfully
            /// </summary>
            BINDING_DESTROYED,

            /// <summary>
            /// Failed to create binding
            /// </summary>
            BINDING_CREATE_FAILED,

            /// <summary>
            /// Restoration successful
            /// </summary>
            RESTORE_SUCCESSFUL,

            /// <summary>
            /// Restoration failed
            /// </summary>
            RESTORE_FAILED,

            /// <summary>
            /// Restoration retry
            /// </summary>
            RESTORE_RETRY,
        }
        #endregion

        #region Public Variables
        [Tooltip("Unique id for this persistent behavior. If not provided, the name of the GameObject would be used")]
        public string UniqueId;

        /// <summary>
        /// Retry timeout.
        /// <summary/>
        public float TimeOutInSeconds = 5.0f;

        /// <summary>
        /// Delay to retry when failing to restore
        /// </summary>
        public float RetryDelayInSeconds = 2.0f;

        /// <summary>
        /// Number of times to retry when failing to restore
        /// </summary>
        public int NumRetriesForRestore = 3;
        #endregion

        #region Public Properties
        /// <summary>
        /// Gets the binding.
        /// </summary>
        /// <value>The binding.</value>
        public MLContentBinding Binding { get; private set; }
        #endregion

        #region Public Events
        /// <summary>
        /// This event is raised when the state of the MLPersistentBehavior has changed.
        /// </summary>
        public event System.Action<Status, MLResult> OnStatusUpdate;
        #endregion

        #region Private Variables
        bool _done = false;
        Coroutine _searchForPCF = null;
        #endregion

        #region Unity Methods
        /// <summary>
        /// Start up
        /// Note: This requires the privilege to be granted prior to Start()
        /// </summary>
        void Start()
        {
            MLResult result = MLPersistentStore.Start();
            if (!result.IsOk)
            {
                Debug.LogErrorFormat("MLPersistentBehavior failed starting MLPersistentStore, disabling script. Reason: {0}", result);
                enabled = false;
                return;
            }

            result = MLPersistentCoordinateFrames.Start();
            if (!result.IsOk)
            {
                MLPersistentStore.Stop();
                Debug.LogErrorFormat("MLPersistentBehavior failed starting MLPersistentCoordinateFrames, disabling script. Reason: {0}", result);
                enabled = false;
                return;
            }

            if (string.IsNullOrEmpty(UniqueId))
            {
                Debug.LogWarning("Unique Id is empty will try to use game object's name. It's good to provide a unique id for virtual objects to avoid weird behavior.");
                if (string.IsNullOrEmpty(gameObject.name))
                {
                    Debug.LogError("Either UniqueId or name should be non empty. Disabling component");
                    enabled = false;
                    return;
                }
                UniqueId = gameObject.name;
            }

            if (MLPersistentCoordinateFrames.IsReady)
            {
                CreateOrRestoreBinding();
            }
            else
            {
                MLPersistentCoordinateFrames.OnInitialized += HandleInitialized;
            }
        }

        /// <summary>
        /// Clean Up
        /// </summary>
        void OnDestroy()
        {
            if (MLPersistentStore.IsStarted)
            {
                MLPersistentStore.Stop();
            }
            if (MLPersistentCoordinateFrames.IsStarted)
            {
                MLPersistentCoordinateFrames.Stop();
            }

            UnregisterPCFEventHandlers();
            StopAllCoroutines();
        }
        #endregion // Unity Methods

        #region Private Methods
        /// <summary>
        /// Determine and perform the appropriate action
        /// </summary>
        void CreateOrRestoreBinding()
        {
            if (MLPersistentStore.Contains(UniqueId))
            {
                RestoreBinding();
            }
            else
            {
                // Find closest PCF and create binding to it
                StartCoroutine(BindToClosestPCF());
            }
        }

        /// <summary>
        /// Tries to restore the binding
        /// </summary>
        void RestoreBinding()
        {
            MLContentBinding binding;

            MLResult result = MLPersistentStore.Load(UniqueId, out binding);
            if (!result.IsOk)
            {
                Debug.LogErrorFormat("Error: MLPersistentBehavior failed to load binding. Reason: {0}", result);
                NotifyChangeOfStatus(Status.RESTORE_FAILED, result);
            }
            else
            {
                Binding = binding;
                Binding.GameObject = this.gameObject;
                MLContentBinder.Restore(Binding, HandleBindingRestore);
            }

        }

        /// <summary>
        /// Finds the closest pcf for this persistent point.
        /// </summary>
        IEnumerator BindToClosestPCF()
        {
            float timeoutInSeconds = TimeOutInSeconds;
            while (timeoutInSeconds > 0.0f)
            {
                yield return StartCoroutine(TryBindingToClosestPCF());
                if (_done)
                {
                    yield break;
                }
                yield return new WaitForSeconds(1.0f);
                timeoutInSeconds -= 1.0f;
            }

            Debug.LogErrorFormat("Error: MLPersistentBehavior failed to bind to closest PCF. Reason: Timeout");
            NotifyChangeOfStatus(Status.BINDING_CREATE_FAILED, new MLResult(MLResultCode.Timeout));
        }

        /// <summary>
        /// Creates a binding to the closest PCF
        /// </summary>
        /// <returns>Must be executed as a Coroutine</returns>
        IEnumerator TryBindingToClosestPCF()
        {
            _done = false;
            MLResult returnResult = MLPersistentCoordinateFrames.FindClosestPCF(gameObject.transform.position, (pcfPositionResult, pcfWithPosition) =>
            {
                if (pcfPositionResult.IsOk && pcfWithPosition != null && pcfWithPosition.CurrentResult == MLResultCode.Ok)
                {
                    Debug.Log("Binding to closest found PCF: " + pcfWithPosition.CFUID);
                    Binding = MLContentBinder.BindToPCF(UniqueId, gameObject, pcfWithPosition);
                    MLPersistentStore.Save(Binding);
                    NotifyChangeOfStatus(Status.BINDING_CREATED, MLResult.ResultOk);
                    RegisterPCFEventHandlers();
                    _done = true;
                }
                else
                {
                    Debug.LogErrorFormat("Error: MLPersistentBehavior failed to get PCF position. Reason: {0}", pcfPositionResult);
                    NotifyChangeOfStatus(Status.BINDING_CREATE_FAILED, pcfPositionResult);
                    _done = true;
                }
            });

            if (!returnResult.IsOk)
            {
                Debug.LogErrorFormat("Error: MLPersistentBehavior failed to attempt to find closest PCF. Reason: {0}", returnResult);
                NotifyChangeOfStatus(Status.BINDING_CREATE_FAILED, returnResult);
                _done = true;
            }

            while (!_done)
            {
                yield return null;
            }
        }

        /// <summary>
        /// Triggers OnStatusUpdate event with the status
        /// </summary>
        /// <param name="status">PersistentBehaviorStatus</param>
        void NotifyChangeOfStatus(Status status, MLResult result)
        {
            if (OnStatusUpdate != null)
            {
                OnStatusUpdate(status, result);
            }
        }

        /// <summary>
        /// Try to restore after a delay
        /// </summary>
        /// <returns>IEnumerator for delay</returns>
        IEnumerator TryRestore()
        {
            yield return new WaitForSeconds(RetryDelayInSeconds);
            MLContentBinder.Restore(Binding, HandleBindingRestore);
        }

        /// <summary>
        /// Retry finding a reliable PCF after a delay
        /// </summary>
        /// <returns>Coroutine</returns>
        IEnumerator RetryFindPCFToRebind()
        {
            yield return new WaitForSeconds(RetryDelayInSeconds);
            HandlePCFLost();
        }

        /// <summary>
        /// Register event handlers to the PCF this Persistent Behavior is bound to
        /// </summary>
        void RegisterPCFEventHandlers()
        {
            if (Binding != null && Binding.PCF != null)
            {
                Binding.PCF.OnLost += HandlePCFLost;
                Binding.PCF.OnRegain += HandlePCFRegain;
            }
        }

        /// <summary>
        /// Unregister event handlers to the PCF this Persistent Behavior is bound to
        /// </summary>
        void UnregisterPCFEventHandlers()
        {
            if (Binding != null && Binding.PCF != null)
            {
                Binding.PCF.OnLost -= HandlePCFLost;
                Binding.PCF.OnRegain -= HandlePCFRegain;
            }
        }

        /// <summary>
        /// Destroys the given binding
        /// </summary>
        /// <param name="binding">Binding</param>
        void DestroyBindingInternal(MLContentBinding binding)
        {
            if (binding != null)
            {
                MLPersistentStore.DeleteBinding(binding);
            }
        }
        #endregion // Private Methods

        #region Event Handlers
        /// <summary>
        /// Handler for binding restore
        /// </summary>
        /// <param name="contentBinding">Content binding.</param>
        /// <param name="resultCode">Result code.</param>
        void HandleBindingRestore(MLContentBinding contentBinding, MLResult result)
        {
            if (!result.IsOk)
            {
                if (NumRetriesForRestore > 0)
                {
                    NumRetriesForRestore--;
                    Debug.LogWarningFormat("Failed to restore: {0} - {1}. Retries left: {2}. Result Code: {3}",
                        gameObject.name, contentBinding.PCF.CFUID, NumRetriesForRestore, result);
                    NotifyChangeOfStatus(Status.RESTORE_RETRY, result);
                    StartCoroutine(TryRestore());
                }
                else
                {
                    string logMessage = string.Format("Failed to restore : {0} - {1}. Result code: {2}",
                        gameObject.name, contentBinding.PCF.CFUID, result);
                    if (result.Code == MLResultCode.SnapshotPoseNotFound)
                    {
                        // Content is bound to a PCF in a different map
                        Debug.LogWarning(logMessage);
                    }
                    else
                    {
                        Debug.LogError(logMessage);
                    }

                    NotifyChangeOfStatus(Status.RESTORE_FAILED, result);
                }
            }
            else
            {
                NotifyChangeOfStatus(Status.RESTORE_SUCCESSFUL, MLResult.ResultOk);
                RegisterPCFEventHandlers();
            }
        }

        /// <summary>
        /// Handler when MLPersistentCoordinateFrames becomes ready
        /// </summary>
        void HandleInitialized(MLResult status)
        {
            MLPersistentCoordinateFrames.OnInitialized -= HandleInitialized;

            if (status.IsOk)
            {
                CreateOrRestoreBinding();
            }
            else
            {
                Debug.LogErrorFormat("Error: MLPersistentCoordinateFrames failed to initialize, disabling script. Reason: {0}", status);
                enabled = false;
            }
        }

        /// <summary>
        /// Handler when PCF bound to is lost. It tries to look for reliable PCF to bind to. If no PCF
        /// is available, try again later.
        /// </summary>
        void HandlePCFLost()
        {
            _searchForPCF = null;
            MLResult result = MLPersistentCoordinateFrames.FindClosestPCF(transform.position, (findResult, returnPCF) =>
            {
                if (findResult.IsOk && returnPCF != null && returnPCF.CurrentResult == MLResultCode.Ok)
                {
                    UnregisterPCFEventHandlers();

                    Debug.LogFormat("Rebinding to closest found PCF: {0}", returnPCF.CFUID);
                    Binding.PCF = returnPCF;
                    MLResult bindingUpdateResult = Binding.Update();
                    if (!bindingUpdateResult.IsOk)
                    {
                        MLPersistentStore.Save(Binding);
                    }

                    RegisterPCFEventHandlers();
                }
                else
                {
                    Debug.LogFormat("MLPersistentBehavior failed to rebind to closest PCF. Reason: {0}. Retrying in {1} seconds", findResult, RetryDelayInSeconds);
                    _searchForPCF = StartCoroutine(RetryFindPCFToRebind());
                }
            });

            if (!result.IsOk)
            {
                Debug.LogWarningFormat("Error: MLPersistentBehavior failed to attempt to find another closest PCF. Reason: {0}", result);
            }
        }

        /// <summary>
        /// Handler when PCF bound to regains. Cancel any on-going search for another PCF.
        /// </summary>
        void HandlePCFRegain()
        {
            Debug.Log("PCF Regained: " + Binding.PCF.CFUID);
            if (_searchForPCF != null)
            {
                StopCoroutine(_searchForPCF);
                _searchForPCF = null;
            }
        }
        #endregion // Event Handlers

        #region Public Methods
        /// <summary>
        /// Destroys the binding
        /// Note: Game Object is still alive. It is the responsibility
        /// of the caller to deal with the Game Object
        /// </summary>
        public void DestroyBinding()
        {
            DestroyBindingInternal(Binding);
            NotifyChangeOfStatus(Status.BINDING_DESTROYED, MLResult.ResultOk);
        }

        /// <summary>
        /// Called externally to save its binding
        /// </summary>
        public void UpdateBinding()
        {
            if (transform.hasChanged)
            {
                // Note: this does not change the PCF bound to
                // Note 2: if the binding doesn't exist, it will be created

                Binding.Update();
                MLPersistentStore.Save(Binding);
                transform.hasChanged = false;
                NotifyChangeOfStatus(Status.BINDING_UPDATED, MLResult.ResultOk);
            }
        }
        #endregion
    }
}
