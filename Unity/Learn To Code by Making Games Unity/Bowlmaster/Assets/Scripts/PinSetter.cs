using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class PinSetter : MonoBehaviour {
	public Text standingDisplay;

	public int CountStanding() {
		int standing = 0;
		foreach (Pin pin in GameObject.FindObjectsOfType<Pin>()) {
			if (pin.IsStanding ()) {
				standing++;
			}
		}
		return standing;
	}

	// Use this for initialization
	void Start () {
//		Debug.Log(CountStanding ());
	}
	
	// Update is called once per frame
	void Update () {
		standingDisplay.text = CountStanding ().ToString ();
	}
}
