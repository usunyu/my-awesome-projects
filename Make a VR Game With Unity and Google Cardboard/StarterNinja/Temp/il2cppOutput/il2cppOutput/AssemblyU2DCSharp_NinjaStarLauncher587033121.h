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
// NinjaStarController
struct NinjaStarController_t1588601309_0;
// UnityEngine.AudioSource
struct AudioSource_t812398632_0;
// GameController
struct GameController_t_515974935_0;

#include "UnityEngine_UnityEngine_MonoBehaviour_92453903.h"
#include "UnityEngine_UnityEngine_Vector3_725341337.h"

// NinjaStarLauncher
struct  NinjaStarLauncher_t587033121_0  : public MonoBehaviour_t_92453903_0
{
	// UnityEngine.GameObject NinjaStarLauncher::ninja
	GameObject_t_184308134_0 * ___ninja_2;
	// NinjaStarController NinjaStarLauncher::ninjaStar
	NinjaStarController_t1588601309_0 * ___ninjaStar_3;
	// UnityEngine.AudioSource NinjaStarLauncher::whooshSound
	AudioSource_t812398632_0 * ___whooshSound_4;
	// GameController NinjaStarLauncher::_gameController
	GameController_t_515974935_0 * ____gameController_5;
	// UnityEngine.Vector3 NinjaStarLauncher::_shooterOffset
	Vector3_t_725341337_0  ____shooterOffset_6;
};
