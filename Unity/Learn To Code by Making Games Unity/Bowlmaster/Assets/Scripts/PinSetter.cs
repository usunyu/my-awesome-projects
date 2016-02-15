using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class PinSetter : MonoBehaviour {
	public int lastStandingCount = -1;
	public Text standingDisplay;
	public float distanceToRaise = 40f;

	private Ball ball;
	private float lastChangeTime;
	private bool ballEnteredBox = false;

	public void RaisePins() {
		// raise standing pins
		foreach (Pin pin in GameObject.FindObjectsOfType<Pin>()) {
			if (pin.IsStanding ()) {
				pin.transform.Translate (new Vector3 (0, distanceToRaise, 0));
			}
		}
	}

	public void LowerPins() {
		Debug.Log("LowerPins");
	}

	public void RenewPins() {
		Debug.Log("RenewPins");
	}

	void CheckStanding() {
		// Update lastStandingCount
		// Call PinHaveSettled() when they have
		int currentStanding = CountStanding();

		if (currentStanding != lastStandingCount) {
			lastChangeTime = Time.time;
			lastStandingCount = currentStanding;
			return;
		}

		float settleTime = 3f; // How long to wait to consider pins settled
		if (Time.time - lastChangeTime > settleTime) { // If last change > 3s ago
			PinHaveSettled();
		}
	}

	void PinHaveSettled() {
		ball.Reset ();
		lastStandingCount = -1; // Indicate pins have settled, and ball not back into box
		ballEnteredBox = false;
		standingDisplay.color = Color.green;
	}

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
//			print ("Pin Destroy");
			Destroy (thingLeft.transform.parent.gameObject);
		}
//		if (thingLeft.GetComponent<Pin> ()) {
//			print ("Pin Destroy");
//			Destroy (thingLeft);
//		}
	}

	// Use this for initialization
	void Start () {
		ball = GameObject.FindObjectOfType<Ball> ();
	}
	
	// Update is called once per frame
	void Update () {
//		standingDisplay.text = CountStanding ().ToString ();

		if (ballEnteredBox) {
			standingDisplay.text = CountStanding ().ToString ();
			CheckStanding ();
		}
	}
}
