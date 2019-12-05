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

//#pragma warning disable 472

namespace UnityEngine.XR.MagicLeap
{
    /// <summary>
    /// The type of surface that will be acceptable for placement.
    /// </summary>
    public enum SurfaceType
    {
        Unknown,
        Horizontal,
        Vertical,
        Slanted
    }

    /// <summary>
    /// The fit type that is determined upon positioning the content.
    /// </summary>
    public enum FitType
    {
        Unknown,
        Fits,
        NoSurface,
        Uneven,
        Overhang,
        VolumeIntersection,
        WrongOrientation
    }

    /// <summary>
    /// Handles the overall content validation and confirmation for placement objects.
    /// A valid fit is determined based on the desired orientation and clearance of the volume.
    /// </summary>
    [AddComponentMenu("Magic Leap/Placement")]
    public class Placement : MonoBehaviour
    {
        #region Private Variables
        [SerializeField, Tooltip("Tilts the placement's cast lower or higher than the source's forward.")]
        private float _tilt = 0.0f;

        [SerializeField, Tooltip("When on a wall should the volume's y axis match gravity?")]
        private bool _matchGravityOnVerticals = true;

        [SerializeField, Tooltip("How far to detect a surface.")]
        private float _maxDistance = 3.048f;

        [SerializeField, Tooltip("Beyond this value a surface will be determined to be uneven.")]
        private float _maxUneven = 0.0508f;

        [SerializeField, Tooltip("The layers that should allow placement.")]
        private LayerMask _hitLayers = new LayerMask();

        private Transform _source;
        private bool _allowHorizontal;
        private bool _allowVertical;
        private System.Action<Vector3, Quaternion> _callback;

        private RaycastHit _surfaceHit;
        private FitType _fitStatus;
        private SurfaceType _surfaceType;
        private Vector3 _normal;

        private RaycastHit _cornerAHit = new RaycastHit();
        private RaycastHit _cornerBHit = new RaycastHit();
        private RaycastHit _cornerCHit = new RaycastHit();
        private RaycastHit _cornerDHit = new RaycastHit();

        private const float MIN_CAST_DISTANCE = 0.05f;
        #endregion

        #region Events
        public event Action<FitType> OnPlacementEvent;
        //event for the gameobject, and custom scale setting when placement starts
        public event Action<GameObject> OnPlacementBegin;
        #endregion

        #region Public Properties
        /// <summary>
        /// The active status of the placement script.
        /// </summary>
        public bool IsRunning
        {
            get;
            private set;
        }

        /// <summary>
        /// The current fit status based on placement and collisions.
        /// </summary>
        public FitType Fit
        {
            get;
            private set;
        }

        /// <summary>
        /// The position of the placement object.
        /// </summary>
        public Vector3 Position
        {
            get;
            private set;
        }

        /// <summary>
        /// The adjusted position based on the current placement location.
        /// </summary>
        public Vector3 AdjustedPosition
        {
            get;
            private set;
        }

        /// <summary>
        /// The rotation of the placement object.
        /// </summary>
        public Quaternion Rotation
        {
            get;
            private set;
        }

        /// <summary>
        /// The SurfaceType of the placement object.
        /// </summary>
        public SurfaceType Surface
        {
            get
            {
                return _surfaceType;
            }
            private set
            {
                _surfaceType = value;
            }
        }

        /// <summary>
        /// The Scale of the placement object.
        /// </summary>
        public Vector3 Scale
        {
            get;
            private set;
        }

        /// <summary>
        /// If the placement object should orientate to match gravity on vertical surfaces.
        /// </summary>
        public bool OrientToGravity
        {
            get { return _matchGravityOnVerticals; }
        }
        #endregion

        #region Unity Methods
        void Update()
        {
            if (!IsRunning)
            {
                return;
            }

            // Adjust the cast by the tilt value.
            Quaternion adjustmentQuaternion = Quaternion.AngleAxis(_tilt, _source.right);
            Vector3 castVector = adjustmentQuaternion * _source.forward;

            if (Physics.Raycast(_source.position, castVector, out _surfaceHit, _maxDistance, _hitLayers))
            {
                // Set the initial values.
                Position = _surfaceHit.point;
                UpdateAdjustedPosition();
                Surface = GetSurfaceType(_surfaceHit.normal);
                _fitStatus = GetFitType(Surface);

                // Obtain a "perfect" normal since meshed surfaces are not smooth.
                _normal = GetPerfectNormal(Surface, _surfaceHit.normal);

                ValidateCorners(_surfaceHit);

                ValidateVolume();
            }
            else
            {
                _fitStatus = FitType.NoSurface;
                Surface = SurfaceType.Unknown;
                _normal = Vector3.zero;

                Position = _source.position + (castVector * _maxDistance);
                Rotation = Quaternion.LookRotation(-_source.forward);
            }

            // Event Notification
            if (Fit != _fitStatus)
            {
                Fit = _fitStatus;
                if (OnPlacementEvent != null)
                {
                    OnPlacementEvent.Invoke(_fitStatus);
                }
            }
        }
        #endregion

        #region Public Methods
        public void Confirm()
        {
            if (IsRunning && Fit == FitType.Fits)
            {
                IsRunning = false;
                _callback(Position, Rotation);
            }
        }

        /// <summary>
        /// Begins placement session. Callback provides position and volume rotation.
        /// </summary>
        public void Place(Transform placementSource, Vector3 scale, bool allowHorizontal, bool allowVertical, System.Action<Vector3, Quaternion> callback)
        {
            if (IsRunning) return;

            Scale = scale;
            _allowHorizontal = allowHorizontal;
            _allowVertical = allowVertical;

            //cache:
            _source = placementSource;
            _callback = callback;

            //start placement loop:
            IsRunning = true;

            if (OnPlacementBegin != null)
            {
                OnPlacementBegin(placementSource.gameObject);
            }
        }

        /// <summary>
        /// Resumes placement and starts updating.
        /// </summary>
        public void Resume()
        {
            IsRunning = true;
        }

        /// <summary>
        /// Cancels placement and stops updating.
        /// </summary>
        public void Cancel()
        {
            IsRunning = false;
        }
        #endregion

        #region Private Methods
        private void ValidateCorners(RaycastHit surfaceHit)
        {
            if (_fitStatus == FitType.Fits || _fitStatus == FitType.WrongOrientation)
            {
                // Find the axes.
                Vector3 XAxis = GetRightAxis(Surface, _normal);
                Vector3 ZAxis = Vector3.Cross(Vector3.up, XAxis);

                // Set the rotation.
                if(Surface == SurfaceType.Vertical)
                {
                    if (_matchGravityOnVerticals)
                    {
                        Rotation = Quaternion.LookRotation(_normal, Vector3.up);
                    }
                    else
                    {
                        Vector3 YAxis = Vector3.Cross(XAxis, ZAxis);
                        Rotation = Quaternion.LookRotation(_normal, YAxis);
                    }
                }
                else
                {
                    Rotation = Quaternion.LookRotation(ZAxis, _normal);
                }


                GetCornersHitPoints(surfaceHit, XAxis, ZAxis, out _cornerAHit, out _cornerBHit, out _cornerCHit, out _cornerDHit);

                UpdateFitStatus(surfaceHit, XAxis, ZAxis);
            }
        }

        /// <summary>
        /// Push out from the surface to account for the size of the object.
        /// </summary>
        void UpdateAdjustedPosition()
        {
            if (Surface == SurfaceType.Vertical)
            {
                AdjustedPosition = Position + _normal * Scale.z * .5f;
            }
            if(Surface == SurfaceType.Horizontal)
            {
                AdjustedPosition = Position + _normal * Scale.y * .5f;
            }
        }

        private void GetCornersHitPoints(RaycastHit surfaceHit, Vector3 XAxis, Vector3 ZAxis,
            out RaycastHit cornerAHit, out RaycastHit cornerBHit, out RaycastHit cornerCHit, out RaycastHit cornerDHit)
        {
            // Locate each surface-proximity corner.
            Vector3 halfVolume = Scale * .5f;
            Vector3 cornerA = Vector3.zero;
            Vector3 cornerB = Vector3.zero;
            Vector3 cornerC = Vector3.zero;
            Vector3 cornerD = Vector3.zero;

            if (_matchGravityOnVerticals && Surface == SurfaceType.Vertical)
            {
                cornerA = surfaceHit.point + (ZAxis * -halfVolume.y) + (XAxis * -halfVolume.x);
                cornerB = surfaceHit.point + (ZAxis * -halfVolume.y) + (XAxis * halfVolume.x);
                cornerC = surfaceHit.point + (ZAxis * halfVolume.y) + (XAxis * halfVolume.x);
                cornerD = surfaceHit.point + (ZAxis * halfVolume.y) + (XAxis * -halfVolume.x);

                // Find the corner-to-surface points.
                cornerAHit = PerformCornerCast(_normal, cornerA, Scale.z);
                cornerBHit = PerformCornerCast(_normal, cornerB, Scale.z);
                cornerCHit = PerformCornerCast(_normal, cornerC, Scale.z);
                cornerDHit = PerformCornerCast(_normal, cornerD, Scale.z);
            }
            else
            {
                cornerA = surfaceHit.point + (ZAxis * halfVolume.z) + (XAxis * halfVolume.x);
                cornerB = surfaceHit.point + (ZAxis * halfVolume.z) + (XAxis * -halfVolume.x);
                cornerC = surfaceHit.point + (ZAxis * -halfVolume.z) + (XAxis * -halfVolume.x);
                cornerD = surfaceHit.point + (ZAxis * -halfVolume.z) + (XAxis * halfVolume.x);

                // Find the corner-to-surface points.
                cornerAHit = PerformCornerCast(_normal, cornerA, Scale.y);
                cornerBHit = PerformCornerCast(_normal, cornerB, Scale.y);
                cornerCHit = PerformCornerCast(_normal, cornerC, Scale.y);
                cornerDHit = PerformCornerCast(_normal, cornerD, Scale.y);
            }
        }

        private void UpdateFitStatus(RaycastHit surfaceHit, Vector3 XAxis, Vector3 ZAxis)
        {
            // All corners have hit something.
            if (_cornerAHit.collider != null && _cornerBHit.collider != null && _cornerCHit.collider != null && _cornerDHit.collider != null)
            {
                // Obtain the even-ness values.
                float cornerAEvenness = CheckForEvenSurface(surfaceHit.point, _cornerAHit.point, XAxis, ZAxis);
                float cornerBEvenness = CheckForEvenSurface(surfaceHit.point, _cornerBHit.point, XAxis, ZAxis);
                float cornerCEvenness = CheckForEvenSurface(surfaceHit.point, _cornerCHit.point, XAxis, ZAxis);
                float cornerDEvenness = CheckForEvenSurface(surfaceHit.point, _cornerDHit.point, XAxis, ZAxis);

                // Are we within the maxUneven threshold?
                float largestBump = Mathf.Max(cornerAEvenness, cornerBEvenness, cornerCEvenness, cornerDEvenness);

                // Determine if we passed even-ness testing.
                if (largestBump > _maxUneven)
                {
                    _fitStatus = FitType.Uneven;
                }
                else
                {
                    // Only set as fits if we are in the correct orientation.
                    if (_fitStatus != FitType.WrongOrientation)
                    {
                        _fitStatus = FitType.Fits;
                        Position = surfaceHit.point + (_normal * largestBump);
                        UpdateAdjustedPosition();
                    }
                }
            }
            else
            {
                // We are likely hanging over a physical edge.
                _fitStatus = FitType.Overhang;
            }
        }

        private void ValidateVolume()
        {
            if (_fitStatus == FitType.Fits)
            {

                // Determine if the volume is smaller than our actual volume by uneven allowance as a buffer.
                Vector3 collisionVolumeSize = Scale * (.5f - _maxUneven);

                // Check for any volume collisions.
                Collider[] volumeCollisions = Physics.OverlapBox(AdjustedPosition, collisionVolumeSize, Rotation);

                if (volumeCollisions.Length > 0)
                {
                    _fitStatus = FitType.VolumeIntersection;
                }
                else
                {
                    _fitStatus = FitType.Fits;
                }
            }
        }

        private float CheckForEvenSurface(Vector3 rootPoint, Vector3 cornerPoint, Vector3 normalA, Vector3 normalB)
        {
            Vector3 gapVector = rootPoint - cornerPoint;

            // Collapse vector:
            gapVector = Vector3.ProjectOnPlane(gapVector, normalA);

            // Collapse vector again:
            gapVector = Vector3.ProjectOnPlane(gapVector, normalB);

            return gapVector.magnitude;
        }

        private RaycastHit PerformCornerCast(Vector3 normal, Vector3 corner, float volumeAxis)
        {
            RaycastHit hit;
            // Translate corner to the top of our volume to cast "down".
            corner = corner + (normal * volumeAxis);

            // Over cast to ensure we can hit a surface.
            float castDistance = volumeAxis * 1.5f;

            // Fix cast distance for objects that are flat or very thin.
            if (castDistance < MIN_CAST_DISTANCE)
            {
                castDistance = MIN_CAST_DISTANCE;
            }

            Physics.Raycast(corner, -normal, out hit, castDistance);

            return hit;
        }

        private Vector3 GetRightAxis(SurfaceType surfaceType, Vector3 normal)
        {
            if (surfaceType == SurfaceType.Horizontal)
            {
                return Vector3.Cross(normal, _source.forward).normalized;
            }

            if (surfaceType == SurfaceType.Vertical)
            {
                return Vector3.Cross(Vector3.up,normal);
            }

            return Vector3.zero;
        }

        private Vector3 GetPerfectNormal(SurfaceType surfaceType, Vector3 normal)
        {
            if (surfaceType == SurfaceType.Vertical)
            {
                normal.y = 0;
                return normal;
            }

            if (surfaceType == SurfaceType.Horizontal)
            {
                normal.x = 0;
                normal.z = 0;
                normal.y = normal.y > 0 ? 1.0f : -1.0f;
                return normal;
            }

            return Vector3.zero;
        }

        private FitType GetFitType(SurfaceType surfaceType)
        {
            if (surfaceType == SurfaceType.Slanted)
            {
                return FitType.Uneven;
            }

            if (surfaceType == SurfaceType.Horizontal && !_allowHorizontal)
            {
                return FitType.WrongOrientation;
            }

            if (surfaceType == SurfaceType.Vertical && !_allowVertical)
            {
                return FitType.WrongOrientation;
            }

            if (surfaceType == SurfaceType.Horizontal && _allowHorizontal)
            {
                return FitType.Fits;
            }

            if (surfaceType == SurfaceType.Vertical && _allowVertical)
            {
                return FitType.Fits;
            }

            return FitType.Unknown;
        }

        private SurfaceType GetSurfaceType(Vector3 surfaceNormal)
        {
            float dot = Vector3.Dot(surfaceNormal, Vector3.up);

            // Determine the surface orientation.
            if (dot >= .97f || dot <= -.97f)
            {
                return SurfaceType.Horizontal;
            }

            if (dot >= -.3f && dot <= .3f)
            {
                return SurfaceType.Vertical;
            }

            return SurfaceType.Slanted;
        }
        #endregion
    }
}
