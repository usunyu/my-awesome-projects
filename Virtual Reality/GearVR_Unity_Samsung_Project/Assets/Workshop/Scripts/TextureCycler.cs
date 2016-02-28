/*SAMSUNG AND ITS AFFILIATES, SUBSIDIARIES, OFFICERS, DIRECTORS, EMPLOYEES, AGENTS, PARTNERS, AND LICENSORS (COLLECTIVELY, “SAMSUNG”) DO NOT PROMISE OR GUARANTEE THAT THE CODE CONTAINED HEREIN (INCLUDING, FUNCTIONALITY OR FEATURES OF THE FOREGOING) (COLLECTIVELY, THE “CODE”) WILL BE RELIABLE, SECURE, OR ERROR-FREE, OR THAT ANY DEFECTS WILL BE CORRECTED.  THE CODE IS PROVIDED ON AN “AS-IS” BASIS. SAMSUNG CANNOT ENSURE THAT THE CODE WILL BE FREE OF VIRUSES, CONTAMINATION OR DESTRUCTIVE FEATURES. FURTHER, SAMSUNG DOES NOT GUARANTEE ANY RESULTS OR IDENTIFICATION OR CORRECTION OF PROBLEMS AS PART OF THE CODE AND SAMSUNG DISCLAIMS ANY LIABILITY RELATED THERETO. SAMSUNG DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING ANY WARRANTIES OF ACCURACY, NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. SAMSUNG DISCLAIMS ANY AND ALL LIABILITY FOR THE ACTS, OMISSIONS AND CONDUCT OF ANY THIRD PARTIES IN CONNECTION WITH OR RELATED TO YOUR USE OF THE CODE. YOU ASSUME TOTAL RESPONSIBILITY AND ALL RISKS FOR YOUR USE OF THE CODE. YOUR SOLE REMEDY AGAINST SAMSUNG FOR DISSATISFACTION WITH THE CODE IS TO STOP USING THE CODE. SAMSUNG HAS NO OTHER OBLIGATION OR RESPONSIBILITY TO YOU.*/

using UnityEngine;
using System.Collections;


// Attach this script to an object to allow for easy cycling of textures.
public class TextureCycler : MonoBehaviour {

	// Public control variables
	public bool mChangeSlideOnFirstClick= true; 	// If set true, will change the sphere texture on slideshow start
	public bool mDecrementSlides		= false; 	// If true, slideshow will decrement backwards instead of cycling forward
	public int mStartingTextureIndex 	= 0; 		// The index of the starting texture to use
	public int mCycleMode 				= 0; 		// The texture mode to use when cycling / receiving input
	public float mCycleDelay			= 5.0f; 	// The delay, ONLY IF IN SLIDESHOW MODE, between cycling textures

	private int mCurrentTextureIndex 	= 0; 		// Current texture index to display
	private int mLastTextureIndex 		= 0;		// Tracks the last index to know when a change occurs
	private float mSlideUpdateTime 		= 0.0f;		// The timing used for cycling slideshow (this controls the next time to cycle)
	private bool mSlideShowStarted 		= false;	// Set to true when the user first clicks the slideshow to start it
	private bool mFirstSlideShown 		= false;
	private bool mFirstTextureReady 	= false; 

	// Cycle Modes:
	// 0: Textures will cycle forward (positive increment on index)
	// 1: Textures will cycle downward (negative increment on index)
	// 2: Textures will cycle forward in slideshow mode after a delay (mCycleDelay)
	private const int TEXTURE_MODE_INCREMENT = 0;
	private const int TEXTURE_MODE_DECREMENT = 1;
	private const int TEXTURE_MODE_SLIDESHOW = 2;

	void Update () {

		// This mFirstTextureReady flag is only used to check the first texture loading.
		// Once the textures are loaded we mark a flag so that this only executes once.
		if(!mFirstTextureReady && TextureLoader.getInstance().isFinishedLoadingFirstTexture()) {
			mFirstTextureReady = true;

			// Make sure the texture index is in the right bounds.
			if(mStartingTextureIndex >= TextureLoader.getInstance().getTextureCount() || mStartingTextureIndex < 0) {
				mStartingTextureIndex = 0;
			}

			mCurrentTextureIndex = mStartingTextureIndex;

			// Only apply the texture if the application is using the device textures ONLY for start (starting tex == 0)
			// because applyReadyTexture() is already called from the loader.
			if(TextureLoader.getInstance().getStartingTextureCount() > 0) {
				applyReadyTexture();
			}
		}

		// If the texture index has changes (cycle called), this will modify the texture object
		// on the material.
		if(mCurrentTextureIndex != mLastTextureIndex) {
			mLastTextureIndex = mCurrentTextureIndex;

			float fadeBlackDur = 0.0f;
			if(ScreenFaderSphere.getInstance()) {
				fadeBlackDur = ScreenFaderSphere.getInstance().fadeToBlackDuration;
				ScreenFaderSphere.getInstance().fadeToBlack();
			}

			Invoke("beginTextureLoading", fadeBlackDur);
		}

		// Responsible for cycling textures every (mCycleDelay) intervals.
		if(mSlideShowStarted && Time.unscaledTime >= mSlideUpdateTime) {
			mSlideUpdateTime = Time.unscaledTime + mCycleDelay;

			if(mChangeSlideOnFirstClick || mFirstSlideShown) {
				mCurrentTextureIndex = (mDecrementSlides) ? mCurrentTextureIndex-1 : mCurrentTextureIndex+1;
			}

			mFirstSlideShown = true;
			resetTextureIndexCheckBounds(); 
		}
	}
	
	private void beginTextureLoading() {
		StartCoroutine(TextureLoader.getInstance().LoadTextureAtIndex(mCurrentTextureIndex, false, this));
	}

	// Allows changing of the current texture cycling mode 'mode' must be within the range [0, 2] 
	// given the above constants, otherwise it will default to TEXTURE_MODE_INCREMENT.
	public void setTextureCycleMode(int newMode) {
		if(newMode < TEXTURE_MODE_INCREMENT || newMode > TEXTURE_MODE_SLIDESHOW) {
			mCycleMode = TEXTURE_MODE_INCREMENT;
		}
		else {
			mCycleMode = newMode;
		}
	}

	// Called when the raycast for input is detected. It cycles according to the current 
	// texture mode set.
	public void cycleTextures() {
		switch(mCycleMode) {

		case TEXTURE_MODE_INCREMENT:
			mCurrentTextureIndex++;
			break;

		case TEXTURE_MODE_DECREMENT:  
			mCurrentTextureIndex--;
			break;

		case TEXTURE_MODE_SLIDESHOW: 
			// Toggle the slideshow on and off when in slideshow mode and cycle is hit
			mSlideShowStarted = !mSlideShowStarted;
			break;
		}

		resetTextureIndexCheckBounds();
	}

	// Called by TextureLoader after LoadTextureAtIndex() finishes. Applies the texture to the main sphere.
	public void applyReadyTexture() {
		this.GetComponent<Renderer>().material.mainTexture = TextureLoader.getInstance().getCurrentTexture();
	}

	// Ensures the texture index for current display is never out of bounds!
	private void resetTextureIndexCheckBounds() {

		if(mCurrentTextureIndex == TextureLoader.getInstance().getTextureCount() || mCurrentTextureIndex < 0) {

			switch(mCycleMode) 
			{

			case TEXTURE_MODE_INCREMENT:
				mCurrentTextureIndex = 0;
				break;

			case TEXTURE_MODE_DECREMENT:
				mCurrentTextureIndex = TextureLoader.getInstance().getTextureCount() - 1;
				break;

			case TEXTURE_MODE_SLIDESHOW:
				mCurrentTextureIndex = (mDecrementSlides) ? TextureLoader.getInstance().getTextureCount() - 1 : 0;
				break;
			}
		}
	}
}
