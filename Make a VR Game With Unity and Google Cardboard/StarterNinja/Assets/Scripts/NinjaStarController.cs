using UnityEngine;
using System.Collections;

public class NinjaStarController : MonoBehaviour {

	float starSpeed = 9.0f;
	float rotationSpeed = 8.0f;
	
	void Start () {
		this.GetComponent<Rigidbody>().velocity = this.transform.up * starSpeed;
		this.GetComponent<Rigidbody>().angularVelocity = this.transform.forward * rotationSpeed;
    }
	
	void OnCollisionEnter (Collision collision) {
		if (collision.collider.tag == "Enemy") {
			collision.collider.GetComponent<EnemyMover>().DieSoon();
			Destroy(gameObject);
		}
	}
	
}
