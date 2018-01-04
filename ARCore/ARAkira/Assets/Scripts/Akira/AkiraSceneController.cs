using UnityEngine;
using GoogleARCore;
using GoogleARCore.HelloAR;
using System.Collections.Generic;

public class AkiraSceneController : MonoBehaviour
{
	[SerializeField]
    private GameObject akiraPrefab;
    
    [SerializeField]
    private Camera firstPersonCamera;

    [SerializeField]
    private GameObject trackedPlanePrefab;
    
    [SerializeField]
    private GameObject searchingForPlaneUI;

    private List<TrackedPlane> newPlanes = new List<TrackedPlane>();

    private List<TrackedPlane> allPlanes = new List<TrackedPlane>();
    
    private Akira akira;

    private void Update () 
	{
        UpdateTracking();

        UpdateTouches();
    }

    private void UpdateTracking()
    {
        _QuitOnConnectionErrors();

        // The tracking state must be FrameTrackingState.Tracking in order to access the Frame.
        if (Frame.TrackingState != FrameTrackingState.Tracking)
        {
            const int LOST_TRACKING_SLEEP_TIMEOUT = 15;
            Screen.sleepTimeout = LOST_TRACKING_SLEEP_TIMEOUT;
            return;
        }

        Screen.sleepTimeout = SleepTimeout.NeverSleep;
        Frame.GetNewPlanes(ref newPlanes);

        // Iterate over planes found in this frame and instantiate corresponding GameObjects to visualize them.
        for (int i = 0; i < newPlanes.Count; i++)
        {
            // Instantiate a plane visualization prefab and set it to track the new plane. The transform is set to
            // the origin with an identity rotation since the mesh for our prefab is updated in Unity World
            // coordinates.
            GameObject planeObject = Instantiate(trackedPlanePrefab, Vector3.zero, Quaternion.identity, transform);
            planeObject.GetComponent<TrackedPlaneVisualizer>().SetTrackedPlane(newPlanes[i]);

            planeObject.GetComponent<Renderer>().material.SetFloat("_UvRotation", Random.Range(0.0f, 360.0f));
        }

        // Disable the snackbar UI when no planes are valid.
        bool showSearchingUI = true;
        Frame.GetAllPlanes(ref allPlanes);
        for (int i = 0; i < allPlanes.Count; i++)
        {
            if (allPlanes[i].IsValid)
            {
                showSearchingUI = false;
                break;
            }
        }

        searchingForPlaneUI.SetActive(showSearchingUI);
    }

    private void UpdateTouches()
    {
        if (Input.touchCount > 0)
        {
            Touch touch = Input.GetTouch(0);
            if (touch.phase == TouchPhase.Began)
            {
                OnTouch(touch.position);
            }
        }
    }

    private void OnTouch(Vector2 touch)
    {        
        TrackableHit hit;
        TrackableHitFlag raycastFilter = TrackableHitFlag.PlaneWithinBounds | TrackableHitFlag.PlaneWithinPolygon;

        if (Session.Raycast(firstPersonCamera.ScreenPointToRay(touch), raycastFilter, out hit))
        {
            if (akira == null)
            {
                SpawnCharacter(hit);
            }
            else
            {
                akira.WalkToPosition(hit.Point);
            }
        }
        else
        {
            if (akira != null)
            {
                akira.TriggerExcited();
            }
        }
    }

    private void SpawnCharacter(TrackableHit hit)
    {
        Vector3 lookRotation = Quaternion.LookRotation(firstPersonCamera.transform.position - hit.Point).eulerAngles;
        lookRotation.x = 0f;
        lookRotation.z = 0f;

        // Spawned characted needs to face the camera
        Quaternion spawnRotation = Quaternion.Euler(lookRotation);

        // Create an anchor to allow ARCore to track the hitpoint as understanding of the physical
        // world evolves.
        Anchor anchor = Session.CreateAnchor(hit.Point, Quaternion.identity);
        
        // Spawn character from prefab and attach it to anchor
        GameObject akiraGO = Instantiate(akiraPrefab, hit.Point, spawnRotation, anchor.transform);

        // Save reference to character
        akira = akiraGO.GetComponent<Akira>();
        
        // Use a plane attachment component to maintain Akira's y-offset from the plane
        // (occurs after anchor updates).
        akiraGO.AddComponent<PlaneAttachment>().Attach(hit.Plane);

        // Print message on screen
        _ShowAndroidToastMessage("Created character!");
    }

    private void _QuitOnConnectionErrors()
    {
        // Do not update if ARCore is not tracking.
        if (Session.ConnectionState == SessionConnectionState.DeviceNotSupported)
        {
            _ShowAndroidToastMessage("This device does not support ARCore.");
            Application.Quit();
        }
        else if (Session.ConnectionState == SessionConnectionState.UserRejectedNeededPermission)
        {
            _ShowAndroidToastMessage("Camera permission is needed to run this application.");
            Application.Quit();
        }
        else if (Session.ConnectionState == SessionConnectionState.ConnectToServiceFailed)
        {
            _ShowAndroidToastMessage("ARCore encountered a problem connecting.  Please start the app again.");
            Application.Quit();
        }
    }

    private static void _ShowAndroidToastMessage(string message)
    {
        AndroidJavaClass unityPlayer = new AndroidJavaClass("com.unity3d.player.UnityPlayer");
        AndroidJavaObject unityActivity = unityPlayer.GetStatic<AndroidJavaObject>("currentActivity");

        if (unityActivity != null)
        {
            AndroidJavaClass toastClass = new AndroidJavaClass("android.widget.Toast");
            unityActivity.Call("runOnUiThread", new AndroidJavaRunnable(() =>
            {
                AndroidJavaObject toastObject = toastClass.CallStatic<AndroidJavaObject>("makeText", unityActivity,
                    message, 0);
                toastObject.Call("show");
            }));
        }
    }
}
