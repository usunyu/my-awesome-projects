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

namespace MagicLeap
{
    /// <summary>
    /// A Toggle Button template that works with VirtualRaycastController
    /// </summary>
    [DisallowMultipleComponent]
    public class MediaPlayerToggle : MediaPlayerButton
    {
        #region Public Events
        public event System.Action OnToggle;
        #endregion

        #region Unity Methods
        protected override void OnEnable()
        {
            OnControllerTriggerDown += HandleTriggerDown;

            base.OnEnable();
        }

        protected override void OnDisable()
        {
            OnControllerTriggerDown -= HandleTriggerDown;

            base.OnDisable();
        }
        #endregion

        #region Event Handlers
        private void HandleTriggerDown(float triggerValue)
        {
            OnToggle?.Invoke();
        }
        #endregion
    }
}
