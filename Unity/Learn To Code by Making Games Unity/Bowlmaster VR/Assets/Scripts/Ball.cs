using UnityEngine;
using System.Collections;

public class Ball : MonoBehaviour {

	public Vector3 launchVeclocity;

	private Rigidbody rigidBoday;
	private AudioSource audioSource;

	public void Launch ()
	{
		rigidBoday.velocity = launchVeclocity;
		audioSource.Play ();
	}

	// Use this for initialization
	void Start () {
		rigidBoday = GetComponent<Rigidbody> ();
		audioSource = GetComponent<AudioSource> ();

		Launch ();
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
