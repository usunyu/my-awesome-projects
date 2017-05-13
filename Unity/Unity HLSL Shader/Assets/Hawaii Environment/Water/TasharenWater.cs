using UnityEngine;
using System.Collections;

/// <summary>
/// Tasharen Water -- started with the Unity's built-in water, with refraction logic replaced by GrabPass.
/// </summary>

[ExecuteInEditMode]
[RequireComponent(typeof(Renderer))]
[AddComponentMenu("Tasharen/Water")]
public class TasharenWater : MonoBehaviour
{
	public enum Quality
	{
		Fastest,	// No refraction, skybox reflection
		Low,		// Refraction, skybox reflection
		Medium,		// Refraction, 512 reflection reflecting ships
		High,		// Refraction, 512 reflection reflecting everything
		Uber,		// Refraction, 1024 reflection reflecting everything
	}

	/// <summary>
	/// Active quality level.
	/// </summary>

	public Quality quality = Quality.High;

	/// <summary>
	/// Reflection mask used when the quality is "High" or above.
	/// </summary>

	public LayerMask highReflectionMask = -1;

	/// <summary>
	/// Reflection mask used when the quality is set to "Medium".
	/// </summary>

	public LayerMask mediumReflectionMask = -1;

	/// <summary>
	/// Whether to always reposition the water, always keeping it underneath the main camera.
	/// </summary>

	public bool keepUnderCamera = true;

	/// <summary>
	/// Quality of the water.
	/// </summary>

	Transform mTrans;
	Hashtable mCameras = new Hashtable();
	RenderTexture mTex = null;
	int mTexSize = 0;
	Renderer mRen;

	// Whether rendering is already in progress (stops recursive rendering)
	static bool mIsRendering = false;

	/// <summary>
	/// Return the texture size we should be using for reflection.
	/// </summary>

	public int reflectionTextureSize
	{
		get
		{
			switch (quality)
			{
				case Quality.Uber: return 1024;
				case Quality.High:
				case Quality.Medium: return 512;
			}
			return 0;
		}
	}

	/// <summary>
	/// Return the reflection layer mask we should be using.
	/// </summary>

	public LayerMask reflectionMask
	{
		get
		{
			switch (quality)
			{
				case Quality.Uber:
				case Quality.High: return highReflectionMask;
				case Quality.Medium: return mediumReflectionMask;
			}
			return 0;
		}
	}

	/// <summary>
	/// Whether refraction will be used.
	/// </summary>

	public bool useRefraction { get { return (int)quality > (int)Quality.Fastest; } }

	/// <summary>
	/// Extended sign: returns -1, 0 or 1
	/// </summary>

	static float SignExt (float a)
	{
		if (a > 0.0f) return 1.0f;
		if (a < 0.0f) return -1.0f;
		return 0.0f;
	}

	/// <summary>
	/// Adjusts the given projection matrix so that near plane is the given clipPlane
	/// clipPlane is given in camera space. See article in Game Programming Gems 5 and
	/// http://aras-p.info/texts/obliqueortho.html
	/// </summary>

	static void CalculateObliqueMatrix (ref Matrix4x4 projection, Vector4 clipPlane)
	{
		Vector4 q = projection.inverse * new Vector4(SignExt(clipPlane.x), SignExt(clipPlane.y), 1.0f, 1.0f);
		Vector4 c = clipPlane * (2.0F / (Vector4.Dot(clipPlane, q)));

		// third row = clip plane - fourth row
		projection[2] = c.x - projection[3];
		projection[6] = c.y - projection[7];
		projection[10] = c.z - projection[11];
		projection[14] = c.w - projection[15];
	}

	/// <summary>
	/// Calculates reflection matrix around the given plane.
	/// </summary>

	static void CalculateReflectionMatrix (ref Matrix4x4 reflectionMat, Vector4 plane)
	{
		reflectionMat.m00 = (1F - 2F * plane[0] * plane[0]);
		reflectionMat.m01 = (-2F * plane[0] * plane[1]);
		reflectionMat.m02 = (-2F * plane[0] * plane[2]);
		reflectionMat.m03 = (-2F * plane[3] * plane[0]);

		reflectionMat.m10 = (-2F * plane[1] * plane[0]);
		reflectionMat.m11 = (1F - 2F * plane[1] * plane[1]);
		reflectionMat.m12 = (-2F * plane[1] * plane[2]);
		reflectionMat.m13 = (-2F * plane[3] * plane[1]);

		reflectionMat.m20 = (-2F * plane[2] * plane[0]);
		reflectionMat.m21 = (-2F * plane[2] * plane[1]);
		reflectionMat.m22 = (1F - 2F * plane[2] * plane[2]);
		reflectionMat.m23 = (-2F * plane[3] * plane[2]);

		reflectionMat.m30 = 0F;
		reflectionMat.m31 = 0F;
		reflectionMat.m32 = 0F;
		reflectionMat.m33 = 1F;
	}

	/// <summary>
	/// Get the saved quality level for water.
	/// </summary>

	static public Quality GetQuality ()
	{
		Quality q = (Quality)PlayerPrefs.GetInt("Water", (int)Quality.High);
		return q;
	}

	/// <summary>
	/// Set the water quality, saving it in player prefs as well.
	/// </summary>

	static public void SetQuality (Quality q)
	{
		TasharenWater[] wws = FindObjectsOfType(typeof(TasharenWater)) as TasharenWater[];
		if (wws.Length > 0) foreach (TasharenWater ww in wws) ww.quality = q;
		else PlayerPrefs.SetInt("Water", (int)q);
	}

	/// <summary>
	/// Caching is always a good idea.
	/// </summary>

	void Awake ()
	{
		mTrans = transform;
		mRen = GetComponent<Renderer>();
		quality = GetQuality();
	}

	/// <summary>
	/// Cleanup all the objects we possibly have created.
	/// </summary>

	void OnDisable ()
	{
		Clear();
		foreach (DictionaryEntry kvp in mCameras) DestroyImmediate(((Camera)kvp.Value).gameObject);
		mCameras.Clear();
	}

	/// <summary>
	/// Release the texture and the temporary cameras
	/// </summary>

	void Clear ()
	{
		if (mTex)
		{
			DestroyImmediate(mTex);
			mTex = null;
		}
	}

	/// <summary>
	/// Copy camera settings from source to destination.
	/// </summary>

	void CopyCamera (Camera src, Camera dest)
	{
		if (src.clearFlags == CameraClearFlags.Skybox)
		{
			Skybox sky = src.GetComponent<Skybox>();
			Skybox mysky = dest.GetComponent<Skybox>();

			if (!sky || !sky.material)
			{
				mysky.enabled = false;
			}
			else
			{
				mysky.enabled = true;
				mysky.material = sky.material;
			}
		}

		dest.clearFlags = src.clearFlags;
		dest.backgroundColor = src.backgroundColor;
		dest.farClipPlane = src.farClipPlane;
		dest.nearClipPlane = src.nearClipPlane;
		dest.orthographic = src.orthographic;
		dest.fieldOfView = src.fieldOfView;
		dest.aspect = src.aspect;
		dest.orthographicSize = src.orthographicSize;
		dest.depthTextureMode = DepthTextureMode.None;
		dest.renderingPath = RenderingPath.Forward;
	}

	/// <summary>
	/// Get or create the camera used for reflection.
	/// </summary>

	Camera GetReflectionCamera (Camera current, Material mat, int textureSize)
	{
		if (!mTex || mTexSize != textureSize)
		{
			if (mTex) DestroyImmediate(mTex);
			mTex = new RenderTexture(textureSize, textureSize, 16);
			mTex.name = "__MirrorReflection" + GetInstanceID();
			mTex.isPowerOfTwo = true;
			mTex.hideFlags = HideFlags.DontSave;
			mTexSize = textureSize;
		}

		Camera cam = mCameras[current] as Camera;

		if (!cam)
		{
			GameObject go = new GameObject("Mirror Refl Camera id" + GetInstanceID() + " for " + current.GetInstanceID(), typeof(Camera), typeof(Skybox));
			go.hideFlags = HideFlags.HideAndDontSave;

			cam = go.GetComponent<Camera>();
			cam.enabled = false;

			Transform t = cam.transform;
			t.position = mTrans.position;
			t.rotation = mTrans.rotation;

			cam.gameObject.AddComponent<FlareLayer>();
			mCameras[current] = cam;
		}

		// Automatically update the reflection texture
		if (mat.HasProperty("_ReflectionTex")) mat.SetTexture("_ReflectionTex", mTex);
		return cam;
	}

	/// <summary>
	/// Given position/normal of the plane, calculates plane in camera space.
	/// </summary>

	Vector4 CameraSpacePlane (Camera cam, Vector3 pos, Vector3 normal, float sideSign)
	{
		Matrix4x4 m = cam.worldToCameraMatrix;
		Vector3 cpos = m.MultiplyPoint(pos);
		Vector3 cnormal = m.MultiplyVector(normal).normalized * sideSign;
		return new Vector4(cnormal.x, cnormal.y, cnormal.z, -Vector3.Dot(cpos, cnormal));
	}

	/// <summary>
	/// Keep the water underneath the camera.
	/// </summary>

	void LateUpdate ()
	{
#if UNITY_EDITOR
		if (keepUnderCamera && Application.isPlaying)
#else
		if (keepUnderCamera)
#endif
		{
			Transform camTrans = Camera.main.transform;
			Vector3 cp = camTrans.position;
			cp.y = mTrans.position.y;
			if (mTrans.position != cp) mTrans.position = cp;
		}
	}

	/// <summary>
	/// Called when the object is being renderered.
	/// </summary>

	void OnWillRenderObject ()
	{
		// Safeguard from recursive reflections
		if (mIsRendering) return;

		if (!enabled || !mRen || !mRen.enabled)
		{
			Clear();
			return;
		}

		Material mat = mRen.sharedMaterial;
		if (!mat) return;

#if UNITY_IPHONE || UNITY_ANDROID
		// Mobile platforms can only do the lowest possible quality
		quality = Quality.Fastest;
		mat.shader.maximumLOD = 100;
#else

#if UNITY_EDITOR
		mat.shader.maximumLOD = 700;
#endif
		Camera cam = Camera.current;
		if (!cam) return;

		// Depth texture is always needed for water as we used to to calculate the color (at the very least)
		bool imageEffects = SystemInfo.supportsImageEffects;
		if (imageEffects) cam.depthTextureMode |= DepthTextureMode.Depth;
		else quality = Quality.Fastest;

		// No refraction also means no reflection -- lowest quality level
		if (!useRefraction)
		{
			mat.shader.maximumLOD = imageEffects ? 200 : 100;
			Clear();
			return;
		}

		// Don't try to do anything else if the reflections have been turned off
		LayerMask mask = reflectionMask;
		int textureSize = reflectionTextureSize;

		if (mask == 0 || textureSize < 512)
		{
			// No reflection
			mat.shader.maximumLOD = 300;
			Clear();
		}
		else
		{
			// Refraction and reflection -- we first need to create the reflection texture
			mat.shader.maximumLOD = 400;
			mIsRendering = true;

			// Get the reflection camera for the specified game camera (ie: main camera or scene view camera)
			Camera reflectionCamera = GetReflectionCamera(cam, mat, textureSize);

			// find out the reflection plane: position and normal in world space
			Vector3 pos = mTrans.position;
			Vector3 normal = mTrans.up;

			CopyCamera(cam, reflectionCamera);

			// Reflect camera around the reflection plane
			float d = -Vector3.Dot(normal, pos);
			Vector4 reflectionPlane = new Vector4(normal.x, normal.y, normal.z, d);
			Matrix4x4 reflection = Matrix4x4.zero;

			CalculateReflectionMatrix(ref reflection, reflectionPlane);

			Vector3 oldpos = cam.transform.position;
			Vector3 newpos = reflection.MultiplyPoint(oldpos);
			reflectionCamera.worldToCameraMatrix = cam.worldToCameraMatrix * reflection;

			// Setup oblique projection matrix so that near plane is our reflection
			// plane. This way we clip everything below/above it for free.
			Vector4 clipPlane = CameraSpacePlane(reflectionCamera, pos, normal, 1.0f);
			Matrix4x4 projection = cam.projectionMatrix;

			CalculateObliqueMatrix(ref projection, clipPlane);

			reflectionCamera.projectionMatrix = projection;
			reflectionCamera.cullingMask = ~(1 << 4) & mask.value;
			reflectionCamera.targetTexture = mTex;

			GL.SetRevertBackfacing(true);
			{
				reflectionCamera.transform.position = newpos;
				Vector3 euler = cam.transform.eulerAngles;
				reflectionCamera.transform.eulerAngles = new Vector3(0, euler.y, euler.z);
				reflectionCamera.Render();
				reflectionCamera.transform.position = oldpos;
			}
			GL.SetRevertBackfacing(false);
			mIsRendering = false;
		}
#endif
	}
}