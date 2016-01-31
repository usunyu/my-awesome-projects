using UnityEngine;
using System.Collections;

public class CardboardController : MonoBehaviour {

	private Vector3 _offset;

	// Use this for initialization
	void Start () {
		_offset = new Vector3(0.0f, -0.4f, 1.0f);
	}
	
	// Update is called once per frame
	void Update () {
		if (Cardboard.SDK.VRModeEnabled) {  
			
		}
	}
}
