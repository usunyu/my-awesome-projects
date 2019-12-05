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
    /// This is an example class that demonstrates how to visualize the input selection and cursor locations from the MLInputModule.
    /// </summary>
    public class InputExample : MonoBehaviour
    {
        #region Private Variables
        [SerializeField, Tooltip("The MLInputModule used in the scene.")]
        private MLInputModule _inputModule = null;

        [SerializeField, Tooltip("The LineRenderer to show the line from the input to the hit point.")]
        private LineRenderer _beam = null;

        [SerializeField, Tooltip("The prefab that will represent a visual cursor.")]
        private GameObject _cursorPrefab = null;

        private GameObject _cursor = null;
        #endregion

        #region Unity Methods
        void Awake()
        {
            _cursor = Instantiate(_cursorPrefab);
            _cursor.name = "Cursor";
        }

        void Update()
        {
            if (_inputModule.PointerLineSegment.End.HasValue)
            {
                _beam.enabled = (_inputModule.PointerInput == MLInputModule.PointerInputType.Controller);
                _beam.SetPosition(0, _inputModule.PointerLineSegment.Start);
                _beam.SetPosition(1, _inputModule.PointerLineSegment.End.Value);

                _cursor.SetActive(true);
                _cursor.transform.position = _inputModule.PointerLineSegment.End.Value;
                _cursor.transform.localRotation = Quaternion.LookRotation(_inputModule.PointerLineSegment.Normal, _cursor.transform.up);
            }
            else
            {
                _cursor.SetActive(false);
                _beam.enabled = false;
            }
        }
        #endregion
    }
}
