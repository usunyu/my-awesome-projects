using UnityEngine;
using System.Collections;

public class Ball : MonoBehaviour {

	public Vector3 launchVeclocity;

	private Rigidbody rigidBoday;
	private AudioSource audioSource;

	public void Launch (Vector3 vec)
	{
		rigidBoday.velocity = vec;
		rigidBoday.useGravity = true;

		audioSource = GetComponent<AudioSource> ();
		audioSource.Play ();
	}

	// Use this for initialization
	void Start () {
		rigidBoday = GetComponent<Rigidbody> ();
		rigidBoday.useGravity = false;
//		Launch (launchVeclocity);
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
