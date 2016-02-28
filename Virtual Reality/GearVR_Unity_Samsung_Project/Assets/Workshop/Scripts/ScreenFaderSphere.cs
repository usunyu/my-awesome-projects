/*SAMSUNG AND ITS AFFILIATES, SUBSIDIARIES, OFFICERS, DIRECTORS, EMPLOYEES, AGENTS, PARTNERS, AND LICENSORS (COLLECTIVELY, “SAMSUNG”) DO NOT PROMISE OR GUARANTEE THAT THE CODE CONTAINED HEREIN (INCLUDING, FUNCTIONALITY OR FEATURES OF THE FOREGOING) (COLLECTIVELY, THE “CODE”) WILL BE RELIABLE, SECURE, OR ERROR-FREE, OR THAT ANY DEFECTS WILL BE CORRECTED.  THE CODE IS PROVIDED ON AN “AS-IS” BASIS. SAMSUNG CANNOT ENSURE THAT THE CODE WILL BE FREE OF VIRUSES, CONTAMINATION OR DESTRUCTIVE FEATURES. FURTHER, SAMSUNG DOES NOT GUARANTEE ANY RESULTS OR IDENTIFICATION OR CORRECTION OF PROBLEMS AS PART OF THE CODE AND SAMSUNG DISCLAIMS ANY LIABILITY RELATED THERETO. SAMSUNG DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING ANY WARRANTIES OF ACCURACY, NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. SAMSUNG DISCLAIMS ANY AND ALL LIABILITY FOR THE ACTS, OMISSIONS AND CONDUCT OF ANY THIRD PARTIES IN CONNECTION WITH OR RELATED TO YOUR USE OF THE CODE. YOU ASSUME TOTAL RESPONSIBILITY AND ALL RISKS FOR YOUR USE OF THE CODE. YOUR SOLE REMEDY AGAINST SAMSUNG FOR DISSATISFACTION WITH THE CODE IS TO STOP USING THE CODE. SAMSUNG HAS NO OTHER OBLIGATION OR RESPONSIBILITY TO YOU.*/

using UnityEngine;
using System.Collections;


public class ScreenFaderSphere : SingletonMonoBehaviour<ScreenFaderSphere>, AnimShaderAlpha.Listener {
	public float fadeToBlackDuration = 0.3f;
	public float fadeToTransparentDuration = 0.3f;

	AnimShaderAlpha mAnimFade = null;
	MeshRenderer mMeshRenderer = null;

	void Awake() {		
		mAnimFade = GetComponent<AnimShaderAlpha>();
		mAnimFade.setListener( this );
		mMeshRenderer = GetComponent<MeshRenderer>();
	}

	void Update() { 
	}

	public float getAlpha() {
		return mAnimFade.getCurrentAlpha();
	}

	public void setAlpha( float alpha ) {
		mAnimFade.setAlpha( alpha );
	}

	public void fadeToBlack() {
		mMeshRenderer.enabled = true;
		mAnimFade.duration = fadeToBlackDuration;
		mAnimFade.animateToValue( 1.0f );
	}

	public void fadeToTransparent() {
		mMeshRenderer.enabled = true;
		mAnimFade.duration = fadeToTransparentDuration;
		mAnimFade.animateToValue( 0 );
	}

	public void fadeToBlackThenTransparent() {
		fadeToBlack();
		Invoke( "fadeToTransparent", fadeToBlackDuration );
	}

	void AnimShaderAlpha.Listener.animationStarted ( Anim anim ) {}

	// Factor: [0..1]
	void AnimShaderAlpha.Listener.animationUpdated ( Anim anim, float factor ){}
	void AnimShaderAlpha.Listener.animationEnded ( Anim anim, float factor ) {
		if ( mAnimFade.getCurrentAlpha() < 0.01f ) {
			mMeshRenderer.enabled = false;
		}
	}

}
