using UnityEngine;
using System.Collections;

public class Orbit : MonoBehaviour {
	
	public float degreesPerSecond = 10;
	
	// Update is called once per frame
	void Update () {
		transform.RotateAround (Vector3.zero, Vector3.up, degreesPerSecond * Time.deltaTime);
	}
}
