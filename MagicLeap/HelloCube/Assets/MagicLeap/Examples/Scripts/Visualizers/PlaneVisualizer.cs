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

using System.Collections.Generic;
using System.Linq;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.MagicLeap;

namespace MagicLeap
{
    /// <summary>
    /// Manages plane rendering based on plane detection from Planes component.
    /// </summary>
    [RequireComponent(typeof(Planes))]
    public class PlaneVisualizer : MonoBehaviour
    {
        /// <summary>
        /// Caches the results of Boundaries by ID, for the current session.
        /// </summary>
        private class BoundariesCache
        {
            public ulong Id { get; set; }
            public List<PlanesCache> Planes { get; set; }

            /// <summary>
            /// Initialize the boundaries cache with the provided id.
            /// </summary>
            /// <param name="id">The id of the boundaries.</param>
            public BoundariesCache(ulong id)
            {
                Id = id;
                Planes = new List<PlanesCache>();
            }

            /// <summary>
            /// Invoke the hide method on all planes.
            /// </summary>
            public void Hide()
            {
                if (Planes != null)
                {
                    Planes.ForEach(x => x.Hide());
                }
            }

            /// <summary>
            /// Invokes the clear method on all planes.
            /// </summary>
            public void Clear()
            {
                if (Planes != null)
                {
                    Planes.ForEach(x => x.Clear());
                }
            }
        }

        /// <summary>
        /// Caches the results of the Planes, including the holes.
        /// </summary>
        private class PlanesCache
        {
            public GameObject Plane { get; set; }
            public List<GameObject> Holes { get; set; }

            /// <summary>
            /// Initialize the plane cache with the provided visual plane GameObject.
            /// </summary>
            /// <param name="plane">The visual plane GameObject.</param>
            public PlanesCache(GameObject plane)
            {
                Plane = plane;
                Holes = new List<GameObject>();
            }

            /// <summary>
            /// Make all the planes and holes invisible.
            /// </summary>
            public void Hide()
            {
                if(Plane != null)
                {
                    Holes.ForEach(x => x.SetActive(false));
                    Plane.SetActive(false);
                }
            }

            /// <summary>
            /// Clear and destroy all the planes and holes.
            /// </summary>
            public void Clear()
            {
                Holes.ForEach(x => Destroy(x));
                Holes.Clear();

                if (Plane != null)
                {
                    Destroy(Plane);
                }
            }
        }

        private enum RenderType
        {
            Border,
            Texture,
            Polygon
        }

        #region Public Variables
        [Tooltip("Object prefab to use for plane visualization.")]
        public GameObject PlaneVisualPrefab;

        [Header("Materials")]
        [Tooltip("Material used for wall planes.")]
        public Material WallMaterial;
        [Tooltip("Material used for floor planes.")]
        public Material FloorMaterial;
        [Tooltip("Material used for ceiling planes.")]
        public Material CeilingMaterial;
        [Tooltip("Material used for other types of planes.")]
        public Material DefaultMaterial;
        [Tooltip("Material used to show the planes")]
        public Material BorderMaterial;
        #endregion

        #region Private Members
        [Space, SerializeField, Tooltip("Text to display render mode.")]
        private Text _renderModeText = null;

        private GameObject _planesParent = null;
        private GameObject _boundariesParent = null;

        // List of all the planes being rendered.
        private List<GameObject> _planeCache = null;
        private List<uint> _planeFlags = null;

        // List of all boundaries and holes being rendered.
        private List<BoundariesCache> _boundariesCache = null;
        private RenderType _renderType = RenderType.Border;
        #endregion

        #region Unity Methods
        /// <summary>
        /// Initializes all variables and makes sure needed components exist
        /// </summary>
        void Awake()
        {
            if (PlaneVisualPrefab == null)
            {
                Debug.LogError("Error: PlanesVisualizer.PlaneVisualPrefab is not set, disabling script.");
                enabled = false;
                return;
            }

            if (WallMaterial == null || FloorMaterial == null || CeilingMaterial == null || DefaultMaterial == null || BorderMaterial == null)
            {
                Debug.LogError("Error: PlanesVisualizer.Materials is not set, disabling script.");
                enabled = false;
                return;
            }

            MeshRenderer planeRenderer = PlaneVisualPrefab.GetComponent<MeshRenderer>();
            if (planeRenderer == null)
            {
                Debug.LogError("Error: PlanesVisualizer MeshRenderer component not found, disabling script.");
                enabled = false;
                return;
            }

            if (_renderModeText == null)
            {
                Debug.LogError("Error: PlanesVisualizer._renderModeText is not set, disabling script.");
                enabled = false;
                return;
            }

            MagicLeapDevice.RegisterOnHeadTrackingMapEvent(HandleOnHeadTrackingMapEvent);

            _planesParent = new GameObject();
            _planeCache = new List<GameObject>();
            _planeFlags = new List<uint>();

            _boundariesParent = new GameObject();
            _boundariesCache = new List<BoundariesCache>();

            UpdateStatusText();
        }

        /// <summary>
        /// Destroys all planes instances created
        /// </summary>
        void OnDestroy()
        {
            MagicLeapDevice.UnregisterOnHeadTrackingMapEvent(HandleOnHeadTrackingMapEvent);

            DestroyPlanes();
            DestroyBoundaries();
        }
        #endregion

        #region Public Methods
        /// <summary>
        /// Toggle showing of borders and refresh all plane materials
        /// </summary>
        public void CycleMode()
        {
            _renderType = (_renderType != RenderType.Polygon) ? (RenderType)((int)_renderType + 1) : RenderType.Border;

            // Hide the parent GameObject based on the active type.
            if (_renderType == RenderType.Border)
            {
                _boundariesParent.SetActive(false);
                _planesParent.SetActive(true);
            }
            else if (_renderType == RenderType.Polygon)
            {
                _planesParent.SetActive(false);
                _boundariesParent.SetActive(true);
            }

            UpdateStatusText();
            RefreshAllPlaneMaterials();
        }
        #endregion

        #region Private Methods
        private void DrawPlanes(MLWorldPlane[] planes)
        {
            if (planes == null)
                return;

            // Hide the unused plane cache.
            int index = planes.Length > 0 ? planes.Length - 1 : 0;
            for (int i = index; i < _planeCache.Count; ++i)
            {
                _planeCache[i].SetActive(false);
            }

            // Update the active planes.
            for (int i = 0; i < planes.Length; ++i)
            {
                GameObject planeVisual;
                if (i < _planeCache.Count)
                {
                    planeVisual = _planeCache[i];
                    planeVisual.SetActive(true);
                }
                else
                {
                    planeVisual = Instantiate(PlaneVisualPrefab);
                    planeVisual.transform.SetParent(_planesParent.transform);

                    _planeCache.Add(planeVisual);
                    _planeFlags.Add(0);
                }

                planeVisual.transform.position = planes[i].Center;
                planeVisual.transform.rotation = planes[i].Rotation;
                planeVisual.transform.localScale = new Vector3(planes[i].Width, planes[i].Height, 1f);

                _planeFlags[i] = planes[i].Flags;
            }

            RefreshAllPlaneMaterials();
        }

        private void DrawBoundaries(MLWorldPlaneBoundaries[] boundaries)
        {
            if (boundaries == null)
                return;

            // Cleanup the cache
            foreach (var cache in _boundariesCache)
            {
                MLWorldPlaneBoundaries? bounds = boundaries.FirstOrDefault(x => x.Id == cache.Id);
                if (bounds == null)
                {
                    // The boundaries no longer exist, destroy.
                    _boundariesCache.Remove(cache);
                    cache.Clear();
                }
                else
                {
                    // Hide the boundaries.
                    cache.Hide();
                }
            }

            // Update the active boundaries.
            foreach (MLWorldPlaneBoundaries worldBoundary in boundaries)
            {
                BoundariesCache cache = _boundariesCache.Find(x => x.Id == worldBoundary.Id);
                if (cache == null)
                {
                    cache = new BoundariesCache(worldBoundary.Id);
                    _boundariesCache.Add(cache);
                }

                // Obtain the list of mesh filters.
                List<PlanesCache> planesCache = cache.Planes;

                // Enable or create a new GameObject to render the plane boundry.
                for (int i = 0; i < worldBoundary.Boundaries.Length; ++i)
                {
                    MeshFilter meshFilter;
                    if (i < planesCache.Count)
                    {
                        // Obtain the reference and enable it.
                        meshFilter = planesCache[i].Plane.GetComponent<MeshFilter>();
                        meshFilter.mesh.Clear();

                        meshFilter.gameObject.SetActive(true);
                    }
                    else
                    {
                        GameObject planeVisual = new GameObject();
                        planeVisual.transform.SetParent(_boundariesParent.transform);

                        planeVisual.transform.position = Vector3.zero;
                        planeVisual.transform.rotation = Quaternion.identity;

                        // Assign standard shader and pick a random color for the polygon surface.
                        Renderer renderer = planeVisual.AddComponent<MeshRenderer>();
                        renderer.material.shader = Shader.Find("Standard");
                        renderer.material.color = new Color(Random.Range(0f, 0.5f), Random.Range(0f, 1f), Random.Range(0f, 1f));

                        meshFilter = planeVisual.AddComponent<MeshFilter>();
                        meshFilter.mesh = new Mesh();

                        // Add the reference to the cache.
                        planesCache.Add(new PlanesCache(meshFilter.gameObject));
                    }

                    // Calculate the centroid and update the vertices to include it.
                    Vector3 centroid = FindCentroid(worldBoundary.Boundaries[i].Polygon.Vertices);
                    Vector3[] vertices = worldBoundary.Boundaries[i].Polygon.Vertices;

                    // Increase the size by 1, to hold the last element the centroid.
                    System.Array.Resize(ref vertices, worldBoundary.Boundaries[i].Polygon.Vertices.Length + 1);
                    vertices[vertices.Length - 1] = centroid;

                    // Assign the vertices and triangles to the mesh filter.
                    meshFilter.mesh.vertices = vertices;
                    meshFilter.mesh.triangles = GenerateTriangles(vertices);

                    DrawHoles(meshFilter.transform, planesCache[i], worldBoundary.Boundaries[i].Holes);
                }
            }
        }

        private void DrawHoles(Transform parent, PlanesCache planesCache, MLWorldPolygon[] holes)
        {
            if (holes == null)
                return;

            // Enable or create a new GameObject to render the plane boundry.
            for (int i = 0; i < holes.Length; ++i)
            {
                MeshFilter meshFilter;
                if (i < planesCache.Holes.Count)
                {
                    // Obtain the reference and enable it.
                    meshFilter = planesCache.Holes[i].GetComponent<MeshFilter>();
                    meshFilter.mesh.Clear();

                    // Re-parent and offset slightly to prevent z fighting.
                    meshFilter.transform.SetParent(parent);
                    meshFilter.transform.position = parent.forward * 0.01f;
                    meshFilter.transform.rotation = Quaternion.identity;

                    meshFilter.gameObject.SetActive(true);
                }
                else
                {
                    GameObject holeVisual = new GameObject();
                    holeVisual.name = "Hole";

                    // Parent and offset slightly to prevent z fighting.
                    holeVisual.transform.SetParent(parent);
                    holeVisual.transform.position = parent.forward * 0.01f;
                    holeVisual.transform.rotation = Quaternion.identity;

                    // Assign standard shader and pick a random color for the polygon surface.
                    Renderer renderer = holeVisual.AddComponent<MeshRenderer>();
                    renderer.material.shader = Shader.Find("Standard");
                    renderer.material.color = Color.red;

                    meshFilter = holeVisual.AddComponent<MeshFilter>();
                    meshFilter.mesh = new Mesh();

                    // Add the reference to the cache.
                    planesCache.Holes.Add(meshFilter.gameObject);
                }

                // Calculate the centroid and update the vertices to include it.
                Vector3 centroid = FindCentroid(holes[i].Vertices);
                Vector3[] vertices = holes[i].Vertices;

                // Increase the size by 1, to hold the last element the centroid.
                System.Array.Resize(ref vertices, holes[i].Vertices.Length + 1);
                vertices[vertices.Length - 1] = centroid;

                // Assign the vertices and triangles to the mesh filter.
                meshFilter.mesh.vertices = vertices;
                meshFilter.mesh.triangles = GenerateTriangles(vertices, true);
            }
        }

        /// <summary>
        /// Refresh all the plane materials
        /// </summary>
        private void RefreshAllPlaneMaterials()
        {
            for (int i = 0; i < _planeCache.Count; ++i)
            {
                if (!_planeCache[i].activeSelf)
                {
                    continue;
                }

                Renderer planeRenderer = _planeCache[i].GetComponent<Renderer>();
                if (planeRenderer != null)
                {
                    SetRenderTexture(planeRenderer, _planeFlags[i]);
                }
            }
        }

        /// <summary>
        /// Sets correct texture to plane based on surface type
        /// </summary>
        /// <param name="renderer">The renderer component</param>
        /// <param name="flags">The flags of the plane containing the surface type</param>
        private void SetRenderTexture(Renderer renderer, uint flags)
        {
            if (_renderType == RenderType.Border)
            {
                renderer.sharedMaterial = BorderMaterial;
            }
            else if (_renderType == RenderType.Texture)
            {
                if ((flags & (uint)SemanticFlags.Wall) != 0)
                {
                    renderer.sharedMaterial = WallMaterial;
                }
                else if ((flags & (uint)SemanticFlags.Floor) != 0)
                {
                    renderer.sharedMaterial = FloorMaterial;
                }
                else if ((flags & (uint)SemanticFlags.Ceiling) != 0)
                {
                    renderer.sharedMaterial = CeilingMaterial;
                }
                else
                {
                    renderer.sharedMaterial = DefaultMaterial;
                }
            }
        }

        /// <summary>
        /// Update render mode text to match current render mode.
        /// </summary>
        private void UpdateStatusText()
        {
            _renderModeText.text = string.Format("Render Mode: {0}", _renderType.ToString());
        }

        /// <summary>
        /// Create triangles for the supplied vertices, the last vertex is the center.
        /// </summary>
        /// <param name="vertices">Vertices in linear order, with the last vertex being the center.</param>
        /// <param name="clockwise">Winding order</param>
        /// <returns></returns>
        private int[] GenerateTriangles(Vector3[] vertices, bool clockwise = false)
        {
            List<int> triangles = new List<int>();

            if (vertices.Length > 3)
            {
                // The last element is the centroid.
                for (int i = 0; i < vertices.Length - 2; i++)
                {
                    triangles.AddRange(new int[]
                    {
                    i + ((!clockwise) ? 1 : 0),
                    i + ((clockwise)? 1 : 0),
                    vertices.Length - 1
                    });
                }

                // Close the last face.
                triangles.AddRange(new int[]
                {
                    0,
                    vertices.Length - ((clockwise) ? 1 : 2),
                    vertices.Length - ((clockwise) ? 2 : 1)
                });
            }

            return triangles.ToArray();
        }

        /// <summary>
        /// Locates the center point of all the combined vertices.
        /// </summary>
        /// <param name="vertices"></param>
        /// <returns></returns>
        private Vector3 FindCentroid(Vector3[] vertices)
        {
            Vector3 center;
            Vector3 min = vertices[0];
            Vector3 max = vertices[0];

            for (int i = 1; i < vertices.Length; i++)
            {
                Vector3 pos = vertices[i];

                // X
                if (pos.x < min.x)
                {
                    min.x = pos.x;
                }
                else if (pos.x > max.x)
                {
                    max.x = pos.x;
                }

                // Y
                if (pos.y < min.y)
                {
                    min.y = pos.y;
                }
                else if (pos.y > max.y)
                {
                    max.y = pos.y;
                }

                // Z
                if (pos.z < min.z)
                {
                    min.z = pos.z;
                }
                else if (pos.z > max.z)
                {
                    max.z = pos.z;
                }
            }

            center = min + 0.5f * (max - min);

            return center;
        }

        private void DestroyPlanes()
        {
            // Destroy the GameObjects and clear the plane cache.
            _planeCache.ForEach(x => Destroy(x));
            _planeCache.Clear();
            _planeFlags.Clear();
        }

        private void DestroyBoundaries()
        {
            // Destroy the GameObjects and clear the boundaries cache.
            _boundariesCache.ForEach(boundaries => boundaries.Clear());
            _boundariesCache.Clear();
        }
        #endregion

        #region Event Handlers
        /// <summary>
        /// Handle in charge of clearing all planes/boundaries if map gets lost.
        /// </summary>
        /// <param name="mapEvents"> Map Events that happened. </param>
        private void HandleOnHeadTrackingMapEvent(MLHeadTrackingMapEvent mapEvents)
        {
            if (mapEvents.IsLost())
            {
                DestroyPlanes();
                DestroyBoundaries();
            }
        }

        /// <summary>
        /// Updates planes and creates new planes based on detected planes.
        ///
        /// This function reuses previously allocated memory to convert all planes
        /// to the new ones by changing their transforms, it allocates new objects
        /// if the current result ammount is bigger than the ones already stored.
        /// </summary>
        /// <param name="p">The planes component</param>
        public void HandleOnPlanesUpdate(MLWorldPlane[] planes, MLWorldPlaneBoundaries[] boundaries)
        {
            if (_renderType == RenderType.Border || _renderType == RenderType.Texture)
            {
                DrawPlanes(planes);
            }
            else
            {
                DrawBoundaries(boundaries);
            }
        }
        #endregion
    }
}
