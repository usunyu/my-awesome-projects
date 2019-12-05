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
using UnityEngine.XR.MagicLeap;

namespace MagicLeap
{
    /// <summary>
    /// Manages the visual placement indicator upon attempting to place content.
    /// </summary>
    [RequireComponent(typeof(Placement))]
    public class PlacementVisualizer : MonoBehaviour
    {
        #region Private Variables
        [SerializeField, Tooltip("A visual to be displayed when the volume will fit.  This transform's scale should be 1, 1, 1.")]
        private GameObject _willFitVolume = null;
        [SerializeField, Tooltip("A visual to be displayed when the volume will not fit.  This transform's scale should be 1, 1, 1.")]
        private GameObject _willNotFitVolume = null;

        private Placement _placement = null;
        #endregion

        #region Unity Methods
        void Awake()
        {
            _placement = GetComponent<Placement>();

            // Hide the visuals.
            _willFitVolume.SetActive(false);
            _willNotFitVolume.SetActive(false);
        }

        private void OnEnable()
        {
            _placement.OnPlacementEvent += HandlePlacementEvent;
            _placement.OnPlacementBegin += HandlePlacementBegin;
        }

        private void OnDisable()
        {
            _placement.OnPlacementEvent -= HandlePlacementEvent;
            _placement.OnPlacementBegin -= HandlePlacementBegin;
        }

        void Update()
        {
            // Position the volume visuals.
            _willFitVolume.transform.SetPositionAndRotation(_placement.AdjustedPosition, _placement.Rotation);
            _willNotFitVolume.transform.SetPositionAndRotation(_placement.AdjustedPosition, _placement.Rotation);
        }
        #endregion

        #region Private Methods
        private void HandlePlacementBegin(GameObject obj)
        {
            // Apply the volume scale.
            _willFitVolume.transform.localScale = _placement.Scale;
            _willNotFitVolume.transform.localScale = _placement.Scale;
        }

        private void HandlePlacementEvent(FitType newFit)
        {
            if (_placement.Fit == FitType.Fits)
            {
                _willFitVolume.SetActive(true);
                _willNotFitVolume.SetActive(false);
            }
            else
            {
                _willFitVolume.SetActive(false);
                _willNotFitVolume.SetActive(true);
            }
        }
        #endregion
    }
}
