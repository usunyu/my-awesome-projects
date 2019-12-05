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
using UnityEngine.XR.MagicLeap;

namespace MagicLeap
{
    /// <summary>
    /// The one true controller to rule the other material controllers.
    /// </summary>
    public class MasterMaterialController : MonoBehaviour
    {
        #region Private Variables
        [SerializeField, Tooltip("Plane Visualizer")]
        private PlaneVisualizer _visualizer = null;

        [SerializeField, Tooltip("Status Text to show which object is currently being manipulated")]
        private Text _statusText = null;

        [Space, SerializeField, Tooltip("ControllerConnectionHandler reference.")]
        private ControllerConnectionHandler _controllerConnectionHandler = null;

        private MaterialController [] _materialControllers = null;
        private MaterialController _materialControllerInGaze = null;

        private uint swipeRight = 0;
        private uint swipeLeft = 0;
        #endregion

        #region Unity Methods
        /// <summary>
        /// Validate variables
        /// </summary>
        void Start ()
        {
            if (null == _visualizer)
            {
                Debug.LogError("Error: MasterMaterialController._visualizer is not set, disabling script");
                enabled = false;
                return;
            }

            _materialControllers = GetComponents<MaterialController>();
            if (_materialControllers.Length < 1)
            {
                Debug.LogError("Error: MasterMaterialController._materialControllers is empty, disabling script.");
                enabled = false;
                return;
            }
            if (_controllerConnectionHandler == null)
            {
                Debug.LogError("Error: MasterMaterialController._controllerConnectionHandler is not set, disabling script.");
                enabled = false;
                return;
            }

            _statusText.text = "";
            MLInput.OnControllerButtonUp += HandleOnButtonUp;
            MLInput.OnControllerTouchpadGestureStart += HandleOnTouchpadGestureStart;
            MLInput.OnControllerTouchpadGestureEnd += HandleOnTouchpadGestureEnd;
        }

        void Update()
        {
            if(swipeRight > 0)
            {
                UpdateMaterialController(0.5f * Time.deltaTime);
            }
            if(swipeLeft > 0)
            {
                UpdateMaterialController(-0.5f * Time.deltaTime);
            }
        }

        /// <summary>
        /// Unregister event handlers
        /// </summary>
        void OnDestroy()
        {
            MLInput.OnControllerTouchpadGestureContinue -= HandleOnTouchpadGestureEnd;
            MLInput.OnControllerTouchpadGestureStart -= HandleOnTouchpadGestureStart;
            MLInput.OnControllerButtonUp -= HandleOnButtonUp;
        }
        #endregion

        #region Private Methods
        /// <summary>
        /// Update the parameter on the material controller that owns the renderer
        /// </summary>
        /// <param name="value">Adjustment value</param>
        private void UpdateMaterialController(float value)
        {
            if (_materialControllerInGaze)
            {
                _materialControllerInGaze.OnUpdateValue(value);
            }
        }
        #endregion

        #region Event Handlers
        /// <summary>
        /// Toggle viewing custom materials and plane borders on button press
        /// </summary>
        /// <param name="controllerId">The id of the controller.</param>
        /// <param name="button">The button that is being released.</param>
        private void HandleOnButtonUp(byte controllerId, MLInputControllerButton button)
        {
            if (_controllerConnectionHandler.IsControllerValid(controllerId) && button == MLInputControllerButton.Bumper)
            {
                _visualizer.CycleMode();
            }
        }

        /// <summary>
        /// Update swiping counters to update textures if swipe left or right.
        /// </summary>
        /// <param name="controllerId">The id of the controller.</param>
        /// <param name="gesture">Touchpad gesture getting done.</param>
        private void HandleOnTouchpadGestureStart(byte controllerId, MLInputControllerTouchpadGesture gesture)
        {
            if (_controllerConnectionHandler.IsControllerValid(controllerId) && gesture.Type == MLInputControllerTouchpadGestureType.Swipe)
            {
                if (gesture.Direction == MLInputControllerTouchpadGestureDirection.Right)
                {
                    ++swipeRight;
                }
                else if (gesture.Direction == MLInputControllerTouchpadGestureDirection.Left)
                {
                    ++swipeLeft;
                }
            }
        }

        /// <summary>
        /// Update swiping counters to update textures if swipe left or right.
        /// </summary>
        /// <param name="controllerId">The id of the controller.</param>
        /// <param name="gesture">Touchpad gesture getting done.</param>
        private void HandleOnTouchpadGestureEnd(byte controllerId, MLInputControllerTouchpadGesture gesture)
        {
            if (_controllerConnectionHandler.IsControllerValid(controllerId) && gesture.Type == MLInputControllerTouchpadGestureType.Swipe)
            {
                if (gesture.Direction == MLInputControllerTouchpadGestureDirection.Right)
                {
                    --swipeRight;
                }
                else if (gesture.Direction == MLInputControllerTouchpadGestureDirection.Left)
                {
                    --swipeLeft;
                }
            }
        }

        /// <summary>
        /// Update the selected material. This function is called frequently (like Update).
        /// </summary>
        /// <param name="state"> The state of the raycast result.</param>
        /// <param name="result"> The hit results (point, normal, distance).</param>
        /// <param name="confidence"> Confidence value of hit. 0 no hit, 1 sure hit.</param>
        public void HandleOnRaycastHit(MLWorldRays.MLWorldRaycastResultState state, RaycastHit result, float confidence)
        {
            if (confidence > 0 && null != result.transform)
            {
                // TODO: keep track of the last transform seen
                Renderer planeRenderer = result.transform.GetComponent<Renderer>();
                if (null != planeRenderer)
                {
                    foreach (MaterialController controller in _materialControllers)
                    {
                        if (controller.ReferenceMaterial == planeRenderer.sharedMaterial)
                        {
                            _materialControllerInGaze = controller;
                            _materialControllerInGaze.UpdateTextOnView();
                            return;
                        }
                    }
                }
            }
            _statusText.text = "";
            _materialControllerInGaze = null;
        }
        #endregion
    }
}
