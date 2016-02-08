using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class PinSetter : MonoBehaviour {
	public Text standingDisplay;
	private bool ballEnteredBox = false;

	public int CountStanding() {
		int standing = 0;
		foreach (Pin pin in GameObject.FindObjectsOfType<Pin>()) {
			if (pin.IsStanding ()) {
				standing++;
			}
		}
		return standing;
	}

	void OnTriggerEnter(Collider collider) {
		GameObject thingHit = collider.gameObject;
		// Ball enters playbox
		if (thingHit.GetComponent<Ball> ()) {
			ballEnteredBox = true;
			standingDisplay.color = Color.red;
		}
	}

	void OnTriggerExit(Collider collider) {
		GameObject thingLeft = collider.gameObject;
		if (thingLeft.tag == "Pin") {
			print ("Pin Destroy");
			Destroy (thingLeft);
		}
//		if (thingLeft.GetComponent<Pin> ()) {
//			print ("Pin Destroy");
//			Destroy (thingLeft);
//		}
	}

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		standingDisplay.text = CountStanding ().ToString ();
	}
}
