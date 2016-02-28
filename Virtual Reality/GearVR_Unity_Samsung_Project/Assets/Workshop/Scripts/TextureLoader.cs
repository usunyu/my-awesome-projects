using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;

public class TextureLoader : SingletonMonoBehaviour<TextureLoader> {

	public Texture2D[] mStartingTextures	= new Texture2D[1];
	public string mLocalStorageDirPath 		= "";

	private List<string> mTextureFileNames 	= new List<string>();
	private Texture2D mCurrTexture 			= null;
	private int mCurrTextureIndex			= 0;
	private bool mFinishedFirstTexture 		= false;
	private bool mAndroidEnvironment		= false;
	
	void Start () {
#if UNITY_ANDROID && !UNITY_EDITOR
		mAndroidEnvironment = true;
		readTextureFileNames();
#endif

		// Check if there are starting textures i.e. pre-loaded textures set on the TextureLoader instance.
		// Otherwise, if not, we load from the device (or try to).
		if(mStartingTextures != null && mStartingTextures.Length > 0) {
			mFinishedFirstTexture = true;
		}
		else {
			StartCoroutine(LoadTextureAtIndex(0, true, GameObject.Find("Sphere_Inv").GetComponent<TextureCycler>()));
		}
	}

	// Used to read and load a texture2D from an Android device - from a specific folder.
	// mCurrTexture is set to null when the index indicates we want to use default textures; in this case
	// we just return the mStartingTexture[mCurrentTextureIndex]. Otherwise, if we are loading a texture from
	// the device, mCurrTexture will be set to the texture read.
	public IEnumerator LoadTextureAtIndex (int textureIndex, bool firstTime, TextureCycler cyclerToCallback) { 
		if (mAndroidEnvironment && !string.IsNullOrEmpty(mLocalStorageDirPath) && System.IO.Directory.Exists (mLocalStorageDirPath) 
		    && (textureIndex >= mStartingTextures.Length 
		    && textureIndex < (mTextureFileNames.Count + mStartingTextures.Length))) {

			// Append each texture name (as the name appears inside mLocalStoragePath) before each load.
			int startingTextureOffset = mStartingTextures == null ? 0 : mStartingTextures.Length;  
			string currTexturePath = mLocalStorageDirPath + mTextureFileNames[textureIndex - startingTextureOffset];

			// Add "file:///" to the beginning of the absolute path so the WWW object knows its a file protocol.
			WWW textureWWW = new WWW ("file:///" + currTexturePath);

			if (textureWWW.error != null) {
				Debug.Log (name + textureWWW.url + " error: " + textureWWW.error);
			} else {   
				// Yield return from the coroutine while the texture is loading.
				while(!textureWWW.isDone) {
					yield return null;
				}

				// Destroy the old texture member variable before creating a new one to save memory.
				if(mCurrTexture != null) {
					Texture2D.Destroy(mCurrTexture);
				}

				// Create a new texture2D and load the WWW contents into it
				// Note: this call is blocking on the UI thread, so we fade in and out to mask load times.
				mCurrTexture = new Texture2D (4, 4, TextureFormat.DXT1, false);
				mCurrTexture.wrapMode = TextureWrapMode.Repeat;
				textureWWW.LoadImageIntoTexture (mCurrTexture);

				// Clean up the WWW object and call the GC each time we load a texture from device.
				// This is to avoid memory allocation issues.
				textureWWW.Dispose();
				textureWWW = null;
				System.GC.Collect();

				if(cyclerToCallback != null) {
					cyclerToCallback.applyReadyTexture();
					ScreenFaderSphere.getInstance().fadeToTransparent();

					// Check if this is the first texture loaded, if so set this flag so that
					// the texture cycler can know when it's ready.
					if(firstTime) {
						mFinishedFirstTexture = true; 
					}
				}
			} 
		}
		else {
			mCurrTextureIndex = textureIndex;
			mCurrTexture = null;
			cyclerToCallback.applyReadyTexture();

			if(ScreenFaderSphere.getInstance()) {
				ScreenFaderSphere.getInstance().fadeToTransparent();
			}
		}
	}

	private void readTextureFileNames() {
		if(!string.IsNullOrEmpty(mLocalStorageDirPath) && System.IO.Directory.Exists (mLocalStorageDirPath)) {
			foreach(FileInfo file in GetFilesWithExtensions(
				new DirectoryInfo(mLocalStorageDirPath), 
				new string[]{ WorkshopUtils.PNG_EXTENSION, WorkshopUtils.JPEG_EXTENSION })) {

				// Add each file name to the list of names, which we store.
				mTextureFileNames.Add(file.Name);
			}
		}
		else {
			Debug.Log("mLocalStorageDirPath doesn't exist or the string is empty or null");
		}
	}
	
	// Gets the list of files in the directory by extention and filters for our specified ones (images)
	private IEnumerable<FileInfo> GetFilesWithExtensions (this DirectoryInfo dir, params string[] extensions) {
		IEnumerable<FileInfo> files = dir.GetFiles();
		return files.Where(f => extensions.Contains(f.Extension));
	}

	public bool isFinishedLoadingFirstTexture() {
		return mFinishedFirstTexture;
	}

	// Returns the current texture to set on the sphere.. If we are setting a texture from the default list, mCurrTexture
	// will be null.
	public Texture2D getCurrentTexture() {
		return mCurrTexture == null ? mStartingTextures[mCurrTextureIndex] : mCurrTexture;
	}

	// Returns the total number of textures available between the default mStartingTextures array + the number of
	// textures on the device (use file names to get count).
	public int getTextureCount() {
		return mStartingTextures.Length + mTextureFileNames.Count;
	}

	// Returns just the count/size of the array of Starting textures (excluding the device textures)
	public int getStartingTextureCount() { 
		return mStartingTextures.Count();
	}
}



