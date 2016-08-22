using UnityEngine;
using System.Collections;

public class DemoTimeOfDay : MonoBehaviour {

	public Light lightSource;
	public float minAngle = -15;
	public float cycleDuration = 10;
	
	float maxAngle = 50;
	float yAngle = 60;
	float maxIntensity = 1;
	
	// Use this for initialization
	void Start () {
		if (!lightSource)
			enabled = false;
		
		maxAngle = transform.eulerAngles.x;
		yAngle = transform.eulerAngles.y;
		maxIntensity = lightSource.intensity;
	}
	
	// Update is called once per frame
	void Update () {
		float cycleValue = Time.time / cycleDuration;
		float normalizedHeight = Mathf.Cos (cycleValue * Mathf.PI * 2) * 0.5f + 0.5f;
		
		lightSource.intensity = normalizedHeight * maxIntensity;
		
		float angle = minAngle + normalizedHeight * (maxAngle - minAngle);
		transform.eulerAngles = new Vector3 (angle, yAngle, 0);
		
		DynamicGI.UpdateEnvironment ();
	}
}
