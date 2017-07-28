/*SAMSUNG AND ITS AFFILIATES, SUBSIDIARIES, OFFICERS, DIRECTORS, EMPLOYEES, AGENTS, PARTNERS, AND LICENSORS (COLLECTIVELY, “SAMSUNG”) DO NOT PROMISE OR GUARANTEE THAT THE CODE CONTAINED HEREIN (INCLUDING, FUNCTIONALITY OR FEATURES OF THE FOREGOING) (COLLECTIVELY, THE “CODE”) WILL BE RELIABLE, SECURE, OR ERROR-FREE, OR THAT ANY DEFECTS WILL BE CORRECTED.  THE CODE IS PROVIDED ON AN “AS-IS” BASIS. SAMSUNG CANNOT ENSURE THAT THE CODE WILL BE FREE OF VIRUSES, CONTAMINATION OR DESTRUCTIVE FEATURES. FURTHER, SAMSUNG DOES NOT GUARANTEE ANY RESULTS OR IDENTIFICATION OR CORRECTION OF PROBLEMS AS PART OF THE CODE AND SAMSUNG DISCLAIMS ANY LIABILITY RELATED THERETO. SAMSUNG DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING ANY WARRANTIES OF ACCURACY, NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. SAMSUNG DISCLAIMS ANY AND ALL LIABILITY FOR THE ACTS, OMISSIONS AND CONDUCT OF ANY THIRD PARTIES IN CONNECTION WITH OR RELATED TO YOUR USE OF THE CODE. YOU ASSUME TOTAL RESPONSIBILITY AND ALL RISKS FOR YOUR USE OF THE CODE. YOUR SOLE REMEDY AGAINST SAMSUNG FOR DISSATISFACTION WITH THE CODE IS TO STOP USING THE CODE. SAMSUNG HAS NO OTHER OBLIGATION OR RESPONSIBILITY TO YOU.*/

using UnityEngine;


public class AnimShaderAlpha : Anim {
	Material mMaterial = null;

	Color mColor = new Color();
	float mStartAlpha = 0;
	float mEndAlpha = 0;

	void Awake() {
		mMaterial = GetComponent<MeshRenderer>().GetComponent<Renderer>().material;
	}
	
	protected override void updateAnim( float factor, float deltaTime ) {
		mColor.a = Mathf.Lerp( mStartAlpha, mEndAlpha, factor );
		setColor ( mColor );
	}

	public void animateToValue( float alpha ) {
		mColor = getCurrentColor();
		mStartAlpha = mColor.a;
		mEndAlpha = alpha;
		startAnimation();
	}

	public Color getCurrentColor() {
		//Debug.Log(name + " - Getcurrentcolor");
		return mMaterial.GetColor ( "_Color" );
	}
	
	public float getCurrentAlpha() {
		return getCurrentColor().a;
	}

	void setColor( Color newColor ) {
		mMaterial.SetColor ("_Color", newColor);
	}

	public void setAlpha( float alpha ) {
		Color c = getCurrentColor();
		c.a = alpha;
		setColor ( c );
	}


}
