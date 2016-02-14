using UnityEngine;
using System.Collections;

public class Pin : MonoBehaviour {

	public float standingThreshold = 3f;

	public bool IsStanding() {
		// hope the ball will be destoried :)
		return true;
//		Vector3 rotationInEuler = transform.rotation.eulerAngles;
//		float tiltInX = Mathf.Abs(rotationInEuler.x);
//		float tiltInZ = Mathf.Abs(rotationInEuler.z);
//
//		if (tiltInX < standingThreshold && tiltInZ < standingThreshold) {
//			return true;
//		}
//
//		return false;
	}

	// Use this for initialization
	void Start () {
	}
	
	// Update is called once per frame
	void Update () {
//		print (name + " " + IsStanding ());
	}
}
