/*SAMSUNG AND ITS AFFILIATES, SUBSIDIARIES, OFFICERS, DIRECTORS, EMPLOYEES, AGENTS, PARTNERS, AND LICENSORS (COLLECTIVELY, “SAMSUNG”) DO NOT PROMISE OR GUARANTEE THAT THE CODE CONTAINED HEREIN (INCLUDING, FUNCTIONALITY OR FEATURES OF THE FOREGOING) (COLLECTIVELY, THE “CODE”) WILL BE RELIABLE, SECURE, OR ERROR-FREE, OR THAT ANY DEFECTS WILL BE CORRECTED.  THE CODE IS PROVIDED ON AN “AS-IS” BASIS. SAMSUNG CANNOT ENSURE THAT THE CODE WILL BE FREE OF VIRUSES, CONTAMINATION OR DESTRUCTIVE FEATURES. FURTHER, SAMSUNG DOES NOT GUARANTEE ANY RESULTS OR IDENTIFICATION OR CORRECTION OF PROBLEMS AS PART OF THE CODE AND SAMSUNG DISCLAIMS ANY LIABILITY RELATED THERETO. SAMSUNG DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING ANY WARRANTIES OF ACCURACY, NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. SAMSUNG DISCLAIMS ANY AND ALL LIABILITY FOR THE ACTS, OMISSIONS AND CONDUCT OF ANY THIRD PARTIES IN CONNECTION WITH OR RELATED TO YOUR USE OF THE CODE. YOU ASSUME TOTAL RESPONSIBILITY AND ALL RISKS FOR YOUR USE OF THE CODE. YOUR SOLE REMEDY AGAINST SAMSUNG FOR DISSATISFACTION WITH THE CODE IS TO STOP USING THE CODE. SAMSUNG HAS NO OTHER OBLIGATION OR RESPONSIBILITY TO YOU.*/

using UnityEngine;
using System.Collections;


// Raycaster is a Singleton class that works closesly with InputManager. When an input event is detected (click/press),
// a raycast is fired from the reticle in the center of the screen. Then, the Raycaster checks for objects that it collided
// with. Objects that are hit by the ray cast can be queried each frame using anythingHitByRay(), or getObjectHitByRay
// which returns null/false if nothing was hit this frame.
public class Raycaster : SingletonMonoBehaviour<Raycaster> {

	private GameObject mLastObjectHit = null;
	
	// Update is called once per frame
	void Update () {
		if(InputManager.getInstance().checkForClick()) {
			RaycastHit hit = new RaycastHit();
			Vector3 forward = Reticle.getInstance().transform.TransformDirection (Vector3.forward);

			// Create the ray that will be casted straight into the screen. It's origin is the coordinates
			// of the reticle after a click is detected. The destination is our forward vector.
			Ray castedRay = new Ray (Reticle.getInstance().transform.position, forward);
		
			// Check if the raycast hit anything, if so, acquire the game object that it hit using the 'out' struct.
			if(Physics.Raycast(castedRay, out hit)) {

				// Acquire the game object information from the object that is hit. This allows for anybody
				// to query getObjectHitByRay() each frame for access to that object. This will be further used to
				// cycle textures.
				if(hit.collider.gameObject != null) {
					mLastObjectHit = hit.collider.gameObject;
				}
			}
		}
		// Reset the last object hit reference each frame that nothing was hit.
		else {
			mLastObjectHit = null;
		}
	}

	public bool anythingHitByRay() {
		return mLastObjectHit == null ? false : true;
	}

	// Returns the object hit by the raycast, NULL otherwise if nothing was hit this frame by click.
	public GameObject getObjectHitByRay() {
		return mLastObjectHit;
	}
}
