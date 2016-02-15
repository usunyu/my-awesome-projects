using UnityEngine;
using System.Collections;

public class Pin : MonoBehaviour {

	public float standingThreshold = 3f;

	private float distanceToRaise = 40f;
	private Rigidbody rigidbody;

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
		rigidbody = GetComponent<Rigidbody> ();
	}
	
	// Update is called once per frame
	void Update () {
//		print (name + " " + IsStanding ());
	}

	public void Raise() {
		if (IsStanding ()) {
			rigidbody.useGravity = false;
			rigidbody.velocity = Vector3.zero;
			transform.Translate (new Vector3 (0, distanceToRaise, 0));
		}
	}

	public void Lower() {
		if (IsStanding ()) {
			rigidbody.useGravity = true;
			transform.Translate (new Vector3 (0, -distanceToRaise, 0));
		}
	}
}
