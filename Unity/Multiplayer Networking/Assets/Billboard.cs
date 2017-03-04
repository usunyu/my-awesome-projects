using UnityEngine;
using System.Collections;

public class Billboard : MonoBehaviour {

    void Update() {
        transform.LookAt(Camera.main.transform);
    }
}