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
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.MagicLeap;

namespace MagicLeap
{
    /// <summary>
    /// Visualizes PCFs in Debug Mode
    /// </summary>
    public class PCFVisualizer : MonoBehaviour
    {
        #region Private Variables
        [SerializeField, Tooltip("Prefab to represent a PCF visually")]
        private GameObject _prefab = null;
        private List<GameObject> _pcfObjs = new List<GameObject>();

        [SerializeField, Tooltip("UI Text to show PCF Stored Count")]
        private Text _pcfCountText = null;
        private uint _pcfCount = 0;
        const string PCF_COUNT_TEXT_FORMAT = "PCF Count: {0}";

        private int _ongoingQueriesCount = 0;
        IEnumerator _findAllPCFs = null;
        #endregion

        #region Public Properties
        /// <summary>
        /// Flag to indicate debug mode
        /// </summary>
        public static bool IsDebugMode
        {
            get; private set;
        }
        #endregion

        #region Unity Methods
        /// <summary>
        /// Validates variables, initializes systems, and prepares to show PCFs
        /// </summary>
        void Start()
        {
            if (_prefab == null)
            {
                Debug.LogError("Error: PCFVisualizer._representativePrefab is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_pcfCountText == null)
            {
                Debug.LogError("Error: PCFVisualizer._pcfCountText is not set, disabling script.");
                enabled = false;
                return;
            }
            _pcfCountText.gameObject.SetActive(false);

            MLResult result = MLPersistentStore.Start();
            if (!result.IsOk)
            {
                Debug.LogErrorFormat("Error: PCFVisualizer failed starting MLPersistentStore, disabling script. Reason: {0}", result);
                enabled = false;
                return;
            }

            result = MLPersistentCoordinateFrames.Start();
            if (!result.IsOk)
            {
                MLPersistentStore.Stop();
                Debug.LogErrorFormat("Error: PCFVisualizer failed starting MLPersistentCoordinateFrames, disabling script. Reason: {0}", result);
                enabled = false;
                return;
            }

            MLPCF.OnCreate += HandleCreate;
            _findAllPCFs = FindAllPCFs();
        }

        /// <summary>
        /// Clean up
        /// </summary>
        void OnDestroy()
        {
            StopCoroutine(_findAllPCFs);
            foreach (GameObject go in _pcfObjs)
            {
                if (go != null)
                {
                    Destroy(go);
                }
            }

            MLPCF.OnCreate -= HandleCreate;
            if (MLPersistentStore.IsStarted)
            {
                MLPersistentStore.Stop();
            }
            if (MLPersistentCoordinateFrames.IsStarted)
            {
                MLPersistentCoordinateFrames.Stop();
            }
        }
        #endregion // Unity Methods

        #region Event Handlers
        /// <summary>
        /// Called once for every MLPCF successfully created.
        /// </summary>
        /// <param name="pcf">The PCF</param>
        private void HandleCreate(MLPCF pcf)
        {
            _pcfCount++;
            _pcfCountText.text = string.Format(PCF_COUNT_TEXT_FORMAT, _pcfCount);

            AddPCFObject(pcf);
        }

        /// <summary>
        /// Handler when a PCF Position is found. Called in conjunction with MLPersistentCoordinateFrames.GetPCFPosition(...)
        /// </summary>
        /// <param name="result">Result of the Query</param>
        /// <param name="pcf">PCF</param>
        private void HandlePCFPositionQuery(MLResult result, MLPCF pcf)
        {
            if (result.IsOk)
            {
                // This is only for demonstration purposes because we want to track all the PCFs found.
                // Ideally in a production app, we only wish to track PCFs that have virtual content
                // bound to them - which is already automatically done by MLPersistentBehavior.
                MLPersistentCoordinateFrames.QueueForUpdates(pcf);
            }
            --_ongoingQueriesCount;
        }
        #endregion // Event Handlers

        #region Private Methods
        /// <summary>
        /// Creates the PCF game object.
        /// </summary>
        /// <param name="pcf">Pcf.</param>
        void AddPCFObject(MLPCF pcf)
        {
            GameObject repObj = Instantiate(_prefab, Vector3.zero, Quaternion.identity);
            repObj.name = pcf.CFUID.ToString();
            repObj.transform.position = pcf.Position;
            repObj.transform.rotation = pcf.Orientation;

            PCFStatusText statusTextBehavior = repObj.GetComponent<PCFStatusText>();
            if (statusTextBehavior != null)
            {
                statusTextBehavior.PCF = pcf;
            }

            repObj.SetActive(IsDebugMode);
            _pcfObjs.Add(repObj);
        }

        /// <summary>
        /// Coroutine to continuously query for all PCFs and their locations in debug mode.
        /// Note: Getting all PCFs is highly inefficient and ill-advised. We are only
        /// doing this for demonstration/debug purposes. Do NOT do this on production code!
        /// </summary>
        /// <returns>IEnumerator</returns>
        IEnumerator FindAllPCFs()
        {
            while (IsDebugMode)
            {
                List<MLPCF> allPCFs;
                MLResult result = MLPersistentCoordinateFrames.GetAllPCFs(out allPCFs);
                if (!result.IsOk)
                {
                    Debug.LogErrorFormat("Error: MLPersistentCoordinateFrames failed to get all PCFs. Reason: {0}", result);
                    yield break;
                }

                // MLPersistentCoordinateFrames.GetAllPCFs() returns the PCFs stored in the device.
                // We don't have their positions yet. In fact, we don't even know if they're in the
                // same landscape as the user is loaded into.

                _ongoingQueriesCount = allPCFs.Count;
                foreach (MLPCF pcf in allPCFs)
                {
                    result = MLPersistentCoordinateFrames.GetPCFPosition(pcf, HandlePCFPositionQuery);
                    // HandlePCFPositionQuery could execute immediately (when the requested PCF has been requested before)
                    // or later (when the PCF is completely new).
                    if (!result.IsOk)
                    {
                        Debug.LogErrorFormat("Error: MLPersistentCoordinateFrames failed to get PCF position. Reason: {0}", result);
                        yield break;
                    }

                    // When MLPersistentCoordinateFrames.GetPCFPosition() successfully gets the position of the PCF,
                    // MLPCF.OnCreate() gets triggered which will call HandleCreate()
                }

                // It is possible for _ongoingQueriesCount to be 0 at this point when no new PCFs have been found.
                // Such a case would cause an infinite loop in the current frame. The following yield statement
                // prevents the infinite loop in a single frame.
                yield return null;

                while (_ongoingQueriesCount > 0)
                {
                    yield return null;
                }
            }
        }
        #endregion // Private Methods

        #region Public Methods
        /// <summary>
        /// Toggle Debug Mode
        /// </summary>
        public void ToggleDebug()
        {
            IsDebugMode = !IsDebugMode;

            _pcfCountText.gameObject.SetActive(IsDebugMode);

            foreach (GameObject pcfGO in _pcfObjs)
            {
                pcfGO.SetActive(IsDebugMode);
            }

            if (IsDebugMode)
            {
                StartCoroutine(_findAllPCFs);
            }
            else
            {
                StopCoroutine(_findAllPCFs);
            }
        }
        #endregion
    }
}
