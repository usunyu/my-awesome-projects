using UnityEngine;
using System.Collections;

/// <summary>
/// Enemy spawner. Creates a new enemy once every few seconds, assuming we're not in a game over state.
/// </summary>
public class EnemySpawner : MonoBehaviour {
	
	public float maxZSpawn;
	public float minZSpawn;
	public float xSpawn;
	public float launchRangeMinTime;
	public float launchRangeMaxTime;
	public GameObject enemyPrefab;
	
	private float _nextLaunchTime;
	private float _ySpawn = 0.4f;
	private GameController _gameController;
	private Quaternion _launchRotation;

	void Start () {
		SetNextLaunch();
		_gameController = this.GetComponent<GameController>();
		_launchRotation = Quaternion.Euler(new Vector3(0.0f, -90.0f, 0.0f));
	}
	
	void SetNextLaunch() {
		float launchInterval = Random.Range(launchRangeMinTime, launchRangeMaxTime);
		_nextLaunchTime = Time.time + launchInterval;
	}
	
	void Update () {
		if (Time.time > _nextLaunchTime && !_gameController.isGameOver) {
			Vector3 launchPosition = new Vector3(xSpawn, _ySpawn, Random.Range(minZSpawn, maxZSpawn));
			Instantiate(enemyPrefab, launchPosition, _launchRotation);
			SetNextLaunch();
		}
	}
}
