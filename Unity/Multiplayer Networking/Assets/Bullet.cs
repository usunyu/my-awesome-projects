using UnityEngine;
using System.Collections;

public class Bullet : MonoBehaviour {

    void OnCollisionEnter(Collision collision) {
        var hit = collision.gameObject;
        var health = hit.GetComponent<Health>();
        if (health != null) {
            health.TakeDamage(10);
        }

        Destroy(gameObject);
    }
}