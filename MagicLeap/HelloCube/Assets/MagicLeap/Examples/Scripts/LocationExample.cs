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
using System;
using System.Collections;

namespace MagicLeap
{
    /// <summary>
    /// This example uses the Location API obtain a latitude and longitude, based on the zip code.
    /// The globe is rotated and a pin placed at the geographic location.
    /// </summary>
    [RequireComponent(typeof(PrivilegeRequester))]
    public class LocationExample : MonoBehaviour
    {
        private PrivilegeRequester _privilegeRequester;

        [SerializeField, Tooltip("The text used to display status messages.")]
        private Text _statusText = null;

        [SerializeField, Tooltip("The text used to display the location information.")]
        private Text _locationText = null;

        [SerializeField, Tooltip("The pin to place at the geographic location.")]
        private Transform _pin = null;

        [SerializeField, Tooltip("The GameObject for the globe.")]
        private GameObject _globe = null;

        [SerializeField, Tooltip("Smoothing time for the rotation of the globe.")]
        private float _rotationSmoothTime = 2.0f;

        [SerializeField, Tooltip("The distance from the camera through its forward vector.")]
        private float _distance = 1.0f;

        private bool _placedPin = false;
        private bool _placedGlobe = false;

        private void Awake()
        {
            if (_statusText == null)
            {
                Debug.LogError("Error: LocationExample._statusText is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_locationText == null)
            {
                Debug.LogError("Error: LocationExample._locationData is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_pin == null)
            {
                Debug.LogError("Error: LocationExample._pin is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_globe == null)
            {
                Debug.LogError("Error: LocationExample._globe is not set, disabling script.");
                enabled = false;
                return;
            }

            _globe.SetActive(false);
            _pin.gameObject.SetActive(false);

            _privilegeRequester = GetComponent<PrivilegeRequester>();
            if (_privilegeRequester)
            {
                // Register event listeners.
                _privilegeRequester.OnPrivilegesDone += HandlePrivilegesDone;
            }
        }

        void OnDestroy()
        {
            if (MLLocation.IsStarted)
            {
                MLLocation.Stop();
            }

            if (_privilegeRequester != null)
            {
                // Unregister event listeners.
                _privilegeRequester.OnPrivilegesDone -= HandlePrivilegesDone;
            }
        }

        void Update()
        {
            if (_placedGlobe && _placedPin && Camera.main.transform.hasChanged)
            {
                RotateGlobe();
            }
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

                Debug.LogErrorFormat("Error: LocationExample failed to get requested privileges, disabling script. Reason: {0}", result);
                enabled = false;
                return;
            }

            StartupAPI();
        }

        /// <summary>
        /// Starts the MLLocation API and polls data if needed.
        /// </summary>
        private void StartupAPI()
        {
            MLLocation.Start();

            // Only want to place the pin once
            if (!_placedPin)
            {
                GetLocation();
            }
        }

        /// <summary>
        /// Polls current location data.
        /// </summary>
        private void GetLocation()
        {
            MLLocationData newData = new MLLocationData();
            MLResult result = MLLocation.GetLastCoarseLocation(out newData);
            if (result.IsOk)
            {
                _locationText.text = String.Format(
                    "Latitude:\t<i>{0}</i>\n" +
                    "Longitude:\t<i>{1}</i>\n" +
                    "Postal Code:\t<i>{2}</i>",
                    newData.Latitude,
                    newData.Longitude,
                    newData.HasPostalCode ? newData.PostalCode : "(unknown)"
                );

                StartCoroutine(PlaceGlobe());
                PlacePin(GetWorldCartesianCoords(newData.Latitude, newData.Longitude));
            }
            else
            {
                if (result.Code == MLResultCode.LocationNetworkConnection)
                {
                    _statusText.text = "<color=red>Received network error, please check the network connection and relaunch the application.</color>";
                }
                else
                {
                    _statusText.text = "<color=red>Failed to retrieve location with result: " + result.Code + "</color>";
                }

                enabled = false;
                return;
            }
        }

        /// <summary>
        /// Convert the given latitude and longitude to a Vector3
        /// This converts spherical coordinates to cartesian coordinates
        /// </summary>
        /// <param name="lat">Latitude of the given spherical coordinates</param>
        /// <param name="lon">Longitude of the given spherical coordinates</param>
        /// <returns>Vector3 of cartesian coordinates</returns>
        public Vector3 GetWorldCartesianCoords(float lat, float lon)
        {
            // Convert Latitude and Longitude to radians
            float latitude = Mathf.Deg2Rad * lat;
            float longitude = Mathf.Deg2Rad * lon;
            // adjust position by radians
            latitude -= 1.570795765134f; // subtract 90 degrees (in radians)

            var radius = _globe.GetComponent<SphereCollider>().radius;

            // and switch z and y (since z is forward)
            float xPos = (radius) * Mathf.Sin(latitude) * Mathf.Cos(longitude);
            float zPos = (radius) * Mathf.Sin(latitude) * Mathf.Sin(longitude);
            float yPos = (radius) * Mathf.Cos(latitude);

            return new Vector3(xPos, yPos, zPos);
        }

        /// <summary>
        /// Create our pin and place it at the proper location
        /// </summary>
        /// <param name="position">Vector3 of cartesian coordinates</param>
        /// <returns>The created pin's GameObject</returns>
        public void PlacePin(Vector3 position)
        {
            _pin.transform.parent = _globe.transform;
            _pin.transform.up = position.normalized;
            _pin.transform.position = _globe.transform.position + (position * _globe.transform.localScale.x);
            _pin.gameObject.SetActive(true);

            _placedPin = true;
        }

        /// <summary>
        /// Coroutine to trigger placing the globe after headpose stabliizes.
        /// </summary>
        public IEnumerator PlaceGlobe()
        {
            yield return new WaitForSeconds(1);
            PlaceGlobeFromCamera();

            _placedGlobe = true;
        }

        /// <summary>
        /// Place the globe in front of the user and activate the GameObject.
        /// </summary>
        private void PlaceGlobeFromCamera()
        {
            Camera camera = Camera.main;
            Vector3 targetPosition = camera.transform.position + (camera.transform.forward * _distance);

            _globe.SetActive(true);
            _globe.transform.position = targetPosition;
        }

        /// <summary>
        /// Rotate the globe so that the user can see their location pin.
        /// </summary>
        public void RotateGlobe()
        {
            Camera camera = Camera.main;
            // Find the proper rotation needed to view the _currentLocationPin
            Quaternion targetRotation = Quaternion.LookRotation(camera.transform.position - _pin.transform.position);
            // Rotate the object to face the camera.
            _globe.transform.rotation = Quaternion.Slerp(_globe.transform.rotation, targetRotation, Time.deltaTime / _rotationSmoothTime);
        }
    }
}
