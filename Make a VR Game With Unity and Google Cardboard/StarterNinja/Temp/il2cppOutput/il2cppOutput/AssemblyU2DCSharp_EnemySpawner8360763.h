#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.GameObject
struct GameObject_t_184308134_0;
// GameController
struct GameController_t_515974935_0;

#include "UnityEngine_UnityEngine_MonoBehaviour_92453903.h"
#include "UnityEngine_UnityEngine_Quaternion1989680039.h"

// EnemySpawner
struct  EnemySpawner_t8360763_0  : public MonoBehaviour_t_92453903_0
{
	// System.Single EnemySpawner::maxZSpawn
	float ___maxZSpawn_2;
	// System.Single EnemySpawner::minZSpawn
	float ___minZSpawn_3;
	// System.Single EnemySpawner::xSpawn
	float ___xSpawn_4;
	// System.Single EnemySpawner::launchRangeMinTime
	float ___launchRangeMinTime_5;
	// System.Single EnemySpawner::launchRangeMaxTime
	float ___launchRangeMaxTime_6;
	// UnityEngine.GameObject EnemySpawner::enemyPrefab
	GameObject_t_184308134_0 * ___enemyPrefab_7;
	// System.Single EnemySpawner::_nextLaunchTime
	float ____nextLaunchTime_8;
	// System.Single EnemySpawner::_ySpawn
	float ____ySpawn_9;
	// GameController EnemySpawner::_gameController
	GameController_t_515974935_0 * ____gameController_10;
	// UnityEngine.Quaternion EnemySpawner::_launchRotation
	Quaternion_t1989680039_0  ____launchRotation_11;
};
