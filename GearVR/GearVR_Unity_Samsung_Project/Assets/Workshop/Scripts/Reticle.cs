/*SAMSUNG AND ITS AFFILIATES, SUBSIDIARIES, OFFICERS, DIRECTORS, EMPLOYEES, AGENTS, PARTNERS, AND LICENSORS (COLLECTIVELY, “SAMSUNG”) DO NOT PROMISE OR GUARANTEE THAT THE CODE CONTAINED HEREIN (INCLUDING, FUNCTIONALITY OR FEATURES OF THE FOREGOING) (COLLECTIVELY, THE “CODE”) WILL BE RELIABLE, SECURE, OR ERROR-FREE, OR THAT ANY DEFECTS WILL BE CORRECTED.  THE CODE IS PROVIDED ON AN “AS-IS” BASIS. SAMSUNG CANNOT ENSURE THAT THE CODE WILL BE FREE OF VIRUSES, CONTAMINATION OR DESTRUCTIVE FEATURES. FURTHER, SAMSUNG DOES NOT GUARANTEE ANY RESULTS OR IDENTIFICATION OR CORRECTION OF PROBLEMS AS PART OF THE CODE AND SAMSUNG DISCLAIMS ANY LIABILITY RELATED THERETO. SAMSUNG DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING ANY WARRANTIES OF ACCURACY, NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. SAMSUNG DISCLAIMS ANY AND ALL LIABILITY FOR THE ACTS, OMISSIONS AND CONDUCT OF ANY THIRD PARTIES IN CONNECTION WITH OR RELATED TO YOUR USE OF THE CODE. YOU ASSUME TOTAL RESPONSIBILITY AND ALL RISKS FOR YOUR USE OF THE CODE. YOUR SOLE REMEDY AGAINST SAMSUNG FOR DISSATISFACTION WITH THE CODE IS TO STOP USING THE CODE. SAMSUNG HAS NO OTHER OBLIGATION OR RESPONSIBILITY TO YOU.*/

using UnityEngine;
using System.Collections;


public class Reticle : SingletonMonoBehaviour<Reticle> {

	private bool isLerping			= false;
	private float mAnimStartTime 	= 0.0f;
	private float mAnimEndTime 		= 0.0f;
	private float mAnimHalfTime 	= 0.0f; 

	private InputManager mInputManager = null;

	public Color PressedColor 		= new Color (1f, 1f, 1f, 1f);
	public Color StartColor 		= new Color (1f, 1f, 1f, 0.5f);

	public float ClickAnimationDuration = 0.5f;

	// Use this for initialization
	void Start () {
		mInputManager = InputManager.getInstance(); 
		SpriteRenderer reticleSpriteRenderer = GetComponent<SpriteRenderer>();

		if(reticleSpriteRenderer != null) {
			StartColor = reticleSpriteRenderer.color;
		}
	}
	
	// Update is called once per frame
	void Update () {
		// While the user has clicked we signal the flag to lerp the reticle color.
		if(mInputManager != null) {
			if (mInputManager.IsPressed == true) {
				mAnimStartTime = Time.unscaledTime;
				mAnimHalfTime = mAnimStartTime + (ClickAnimationDuration/2);
				mAnimEndTime = Time.unscaledTime + ClickAnimationDuration;

				// Reset the color on clicks before lerping.
				GetComponent<SpriteRenderer> ().color = StartColor;
				isLerping = true;
			}
		}

		// True if the animation hasn't reached the end yet.
		if(Time.unscaledTime < mAnimEndTime) {
			lerpReticleColor();
		}
		else if(Time.unscaledTime > mAnimEndTime && GetComponent<SpriteRenderer> ().color == PressedColor) {
			isLerping = false;
		}
		else if(Time.unscaledTime > mAnimEndTime && GetComponent<SpriteRenderer> ().color != PressedColor && isLerping) {
			isLerping = false;
			GetComponent<SpriteRenderer> ().color = StartColor;
		}
	}

	private void lerpReticleColor() {
		// % animation has progress since start [0,1] (depending on first or second half of animation)
		float animProgress = Time.unscaledTime - (Time.unscaledTime <= mAnimHalfTime ? mAnimStartTime : mAnimHalfTime);
		
		// Total duration in real-time of the animation (depending on if the animation is in first half or second).
		float halfAnimDuration = ClickAnimationDuration / 2.0f;
		
		// The first half of the reticle color animation will go from idleColor -> pressedColor
		if(Time.unscaledTime <= mAnimHalfTime) {
			// Lerp the color to the appropriate amount.
			GetComponent<SpriteRenderer> ().color = Color.Lerp(StartColor, PressedColor, animProgress / halfAnimDuration);
		}
		// The second half of the reticle color animation will go back from PressedColor -> idleColor
		else {
			GetComponent<SpriteRenderer> ().color = Color.Lerp(
				GetComponent<SpriteRenderer> ().color, 
				StartColor, 
				animProgress / halfAnimDuration);
		}
	}
}
