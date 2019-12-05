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
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.MagicLeap;

namespace MagicLeap
{
    /// <summary>
    /// This a utility class to help debug MLPersistentBehavior. This class listens to
    /// events from MLPersistentBehavior and displays them.
    /// </summary>
    [RequireComponent(typeof(MLPersistentBehavior), typeof(Collider))]
    public class ContentBindingVisualizer : MonoBehaviour
    {
        #region Private Variables
        MLPersistentBehavior _persistentBehavior = null;

        [SerializeField, Tooltip("Text to display name")]
        TextMesh _nameText = null;

        [SerializeField, Tooltip("Highlight Effect")]
        GameObject _highlightEffect = null;

        [SerializeField, Tooltip("Line to PCF")]
        LineRenderer _lineToPCF = null;

        Renderer[] _renderers = null;
        Collider _collider = null;
        ContentDragController _controllerDrag = null;
        #endregion

        #region Public Events
        /// <summary>
        /// Triggered when a controller touches trigger area
        /// </summary>
        public event Action OnHighlight;

        /// <summary>
        /// Triggered when a controller leaves trigger area
        /// </summary>
        public event Action OnUnhighlight;
        #endregion

        #region Unity Methods
        /// <summary>
        /// Validate parameters, initialize renderers, and listen to events
        /// </summary>
        void Awake()
        {
            _persistentBehavior = GetComponent<MLPersistentBehavior>();
            _persistentBehavior.OnStatusUpdate += HandleStatusUpdate;

            if (_nameText == null)
            {
                Debug.LogError("Error: ContentBindingStatusText._nameText is not set, disabling script");
                enabled = false;
                return;
            }

            if (_highlightEffect == null)
            {
                Debug.LogError("Error: ContentBindingStatusText._highlightEffect is not set, disabling script");
                enabled = false;
                return;
            }
            _highlightEffect.SetActive(false);

            if (_lineToPCF == null)
            {
                Debug.LogError("Error: ContentBindingStatusText._lineToPCF is not set, disabling script");
                enabled = false;
                return;
            }
            _lineToPCF.positionCount = 2;
            _lineToPCF.enabled = false;

            _renderers = GetComponentsInChildren<Renderer>();
            EnableRenderers(false);

            _collider = GetComponent<Collider>();
            _collider.enabled = false;
        }

        /// <summary>
        /// Remove event listeners
        /// </summary>
        void OnDestroy()
        {
            if (_persistentBehavior != null)
            {
                _persistentBehavior.OnStatusUpdate -= HandleStatusUpdate;
            }

            if (_controllerDrag != null)
            {
                _controllerDrag.OnDrag -= HandleDrag;
            }
        }

        /// <summary>
        /// Controller touches this content
        /// </summary>
        /// <param name="other">Collider of Controller</param>
        private void OnTriggerEnter(Collider other)
        {
            ContentDragController controllerDrag = other.GetComponent<ContentDragController>();
            if (controllerDrag == null)
            {
                return;
            }

            _controllerDrag = controllerDrag;
            _controllerDrag.OnDrag += HandleDrag;
            Highlight();
        }

        /// <summary>
        /// Controller leaves this content
        /// </summary>
        /// <param name="other">Collider of Controller</param>
        private void OnTriggerExit(Collider other)
        {
            ContentDragController controllerDrag = other.GetComponent<ContentDragController>();
            if (controllerDrag == null)
            {
                return;
            }

            if (_controllerDrag == controllerDrag)
            {
                _controllerDrag.OnDrag -= HandleDrag;
                _controllerDrag = null;
                Unhighlight();
            }
        }
        #endregion

        #region Private Methods
        /// <summary>
        /// Show visual effect when highlighting
        /// </summary>
        private void Highlight()
        {
            _highlightEffect.SetActive(true);

            if (_persistentBehavior != null && _persistentBehavior.Binding.PCF.CurrentResult == MLResultCode.Ok)
            {
                _lineToPCF.SetPosition(0, transform.position);
                _lineToPCF.SetPosition(1, _persistentBehavior.Binding.PCF.Position);
                _lineToPCF.enabled = PCFVisualizer.IsDebugMode;
            }

            if (OnHighlight != null)
            {
                OnHighlight();
            }
        }

        /// <summary>
        /// Remove highlight visual effects
        /// </summary>
        private void Unhighlight()
        {
            _highlightEffect.SetActive(false);
            _lineToPCF.enabled = false;

            if (OnUnhighlight != null)
            {
                OnUnhighlight();
            }
        }

        /// <summary>
        /// Enable/Disable Renderers
        /// </summary>
        /// <param name="enable">Toggle value</param>
        void EnableRenderers(bool enable)
        {
            foreach(Renderer r in _renderers)
            {
                r.enabled = enable;
            }
        }
        #endregion

        #region Event Handlers
        /// <summary>
        /// Handler for content status updates
        /// </summary>
        /// <param name="status">MLPersistentBehavior.PersistentBehaviorStatus</param>
        /// <param name="result">MLResult</param>
        void HandleStatusUpdate(MLPersistentBehavior.Status status, MLResult result)
        {
            switch (status)
            {
                case MLPersistentBehavior.Status.BINDING_CREATED:
                case MLPersistentBehavior.Status.RESTORE_SUCCESSFUL:
                    _nameText.transform.position = transform.position + new Vector3(0, 0.25f, 0);
                    _nameText.text = _persistentBehavior.Binding.ObjectId;

                    EnableRenderers(true);
                    _collider.enabled = true;
                    break;
                case MLPersistentBehavior.Status.BINDING_CREATE_FAILED:
                case MLPersistentBehavior.Status.RESTORE_FAILED:
                    Destroy(gameObject);
                    break;
                case MLPersistentBehavior.Status.BINDING_UPDATED:
                    Debug.Log("MLPersistentBehavior " + _persistentBehavior.UniqueId + " updated");
                    break;
            }
        }

        /// <summary>
        /// Listener for Drag event
        /// </summary>
        private void HandleDrag()
        {
            _lineToPCF.SetPosition(0, transform.position);
        }
        #endregion // Event Handlers
    }
}
