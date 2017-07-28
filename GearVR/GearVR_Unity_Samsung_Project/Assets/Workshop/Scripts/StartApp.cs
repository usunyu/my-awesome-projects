/*SAMSUNG AND ITS AFFILIATES, SUBSIDIARIES, OFFICERS, DIRECTORS, EMPLOYEES, AGENTS, PARTNERS, AND LICENSORS (COLLECTIVELY, “SAMSUNG”) DO NOT PROMISE OR GUARANTEE THAT THE CODE CONTAINED HEREIN (INCLUDING, FUNCTIONALITY OR FEATURES OF THE FOREGOING) (COLLECTIVELY, THE “CODE”) WILL BE RELIABLE, SECURE, OR ERROR-FREE, OR THAT ANY DEFECTS WILL BE CORRECTED.  THE CODE IS PROVIDED ON AN “AS-IS” BASIS. SAMSUNG CANNOT ENSURE THAT THE CODE WILL BE FREE OF VIRUSES, CONTAMINATION OR DESTRUCTIVE FEATURES. FURTHER, SAMSUNG DOES NOT GUARANTEE ANY RESULTS OR IDENTIFICATION OR CORRECTION OF PROBLEMS AS PART OF THE CODE AND SAMSUNG DISCLAIMS ANY LIABILITY RELATED THERETO. SAMSUNG DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING ANY WARRANTIES OF ACCURACY, NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. SAMSUNG DISCLAIMS ANY AND ALL LIABILITY FOR THE ACTS, OMISSIONS AND CONDUCT OF ANY THIRD PARTIES IN CONNECTION WITH OR RELATED TO YOUR USE OF THE CODE. YOU ASSUME TOTAL RESPONSIBILITY AND ALL RISKS FOR YOUR USE OF THE CODE. YOUR SOLE REMEDY AGAINST SAMSUNG FOR DISSATISFACTION WITH THE CODE IS TO STOP USING THE CODE. SAMSUNG HAS NO OTHER OBLIGATION OR RESPONSIBILITY TO YOU.*/

using UnityEngine;
using System.Collections;
using System.IO;


// StartApp is responsible for handling the scene introductions and transitions when the application first starts.
// The scene name set for mMainSceneName will be loaded after the splash.
public class StartApp : MonoBehaviour {

	public int mMainSceneIndex = 1;
	private float mFadeToBlackDuration = 0.0f;

	private bool mFastGpuMode = false;
	private bool mTransitionStarted = false;
	
	public float mSplashDuration = 2.5f;

	// Use this for initialization
	void Awake () {
		Application.targetFrameRate = 60;
		//OVRModeParms.setCpuGpuLevels( 2, 2 );

		if(ScreenFaderSphere.getInstance()) {
			mFadeToBlackDuration = ScreenFaderSphere.getInstance().fadeToBlackDuration;
		}
	}

	void Start() {
		// Must wake until end of Splash screen to load the main scene.
		Invoke( "launchNextScene", mSplashDuration);
	}

	void Update() {
		if ( !mFastGpuMode ) {
			mFastGpuMode = true;
		}

		if(!mTransitionStarted && Time.time >= timeFadeShouldStart()) {
			if(ScreenFaderSphere.getInstance()) {
				ScreenFaderSphere.getInstance().fadeToBlack();
			}

			mTransitionStarted = true;
		}
	}

	void launchNextScene() {
		// Load the scene at the given index in build settings.
		Application.LoadLevel(mMainSceneIndex);
	}

	// The fade should start at the exact moment there is enough time left in the splash scene
	// to fully see the fade. I.e. if the splash scene lasts 3 seconds, and the fade to black animation is 1.5 seconds,
	// then the fade should start at 1.5 seconds into the application.
	private float timeFadeShouldStart() {
		return (mSplashDuration - mFadeToBlackDuration);
	}
}