using UnityEngine;
using System.Collections;

public class Ball : MonoBehaviour {

	public Vector3 launchVeclocity;
	public bool inPlay = false;

	private Rigidbody rigidBoday;
	private AudioSource audioSource;

	public void Launch (Vector3 vec)
	{
		inPlay = true;
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
