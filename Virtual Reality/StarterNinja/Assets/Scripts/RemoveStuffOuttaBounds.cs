using UnityEngine;
using System.Collections;

public class RemoveStuffOuttaBounds : MonoBehaviour {

	// Clever idea taken from Unity's spaceship shooter tutorial to remove objects that
	// are out of bounds.

	void OnTriggerExit (Collider other) 
	{
		Destroy(other.gameObject);
	}
}

