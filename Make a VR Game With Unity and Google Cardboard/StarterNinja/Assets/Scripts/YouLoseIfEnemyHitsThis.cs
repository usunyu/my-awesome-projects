using UnityEngine;
using System.Collections;

public class YouLoseIfEnemyHitsThis : MonoBehaviour {

	public GameController gameController;
	
	
	void OnTriggerEnter (Collider other) 
	{
		// End the game if an enemy not in the dying state hits us.
		if (other.tag == "Enemy") {
			EnemyMover badGuy = other.gameObject.GetComponent<EnemyMover>();
			if (!badGuy.IsDying()) {
				gameController.GameOver(false);
			}
		}
	}	

}
