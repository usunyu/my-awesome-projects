using UnityEngine;
using System.Collections;

[ExecuteInEditMode]
public class Colorizer : MonoBehaviour {

    public Color diffuseColor;
    public Material material;

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
        material.SetColor ("_Color", diffuseColor);
	}
}
