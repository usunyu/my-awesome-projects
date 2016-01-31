using UnityEngine;
using System.Collections;

public class EnemyMover : MonoBehaviour {

	public float speedMin;
	public float speedMax;
	
	
	enum EnemyState { Normal, Dying};
	
	private EnemyState _state;

	// Use this for initialization.
	void Start () {
		_state = EnemyState.Normal;
		float thisSpeed = Random.Range(speedMin, speedMax);
		this.GetComponent<Rigidbody>().velocity = transform.forward * thisSpeed;
	}
	
	
	/// <summary>
	/// Check and see if our enemy is in a dying state. We need this because occasionally
	/// momentum drives a "dead" enemy through the end zone.
	/// </summary>
	/// <returns><c>true</c> if this enemy is dying; otherwise, <c>false</c>.</returns>
	public bool IsDying() {
		return (_state == EnemyState.Dying);
	}
	
	
	/// <summary>
	/// Remove the game object after a short moment so we can watch it get knocked around.
	/// </summary>
	public void DieSoon() {
		if (_state == EnemyState.Normal) {
			// Let's let the enemy get knocked back a bit.
			_state = EnemyState.Dying;
			GameController gameController = FindObjectOfType<GameController>();
			gameController.GotOne();
			this.GetComponent<AudioSource>().Play();
			Destroy(gameObject, 1.5f);
		}
	}

	
	
}

