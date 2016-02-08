using UnityEngine;
using System.Collections;

public class Pin : MonoBehaviour {

	public float standingThreshold = 3f;

	public bool IsStanding() {
		Vector3 rotationInEuler = transform.rotation.eulerAngles;
		float tiltInX = rotationInEuler.x;
		float tiltInZ = rotationInEuler.z;

		if (tiltInX < standingThreshold && tiltInZ < standingThreshold) {
			return true;
		}

		return false;
	}

	// Use this for initialization
	void Start () {
		IsStanding ();
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
