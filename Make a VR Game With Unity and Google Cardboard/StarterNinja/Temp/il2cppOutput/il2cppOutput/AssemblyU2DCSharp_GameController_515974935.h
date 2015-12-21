#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.UI.Text
struct Text_t_204341102_0;
// UnityEngine.Canvas
struct Canvas_t814756449_0;

#include "UnityEngine_UnityEngine_MonoBehaviour_92453903.h"

// GameController
struct  GameController_t_515974935_0  : public MonoBehaviour_t_92453903_0
{
	// System.Boolean GameController::isGameOver
	bool ___isGameOver_2;
	// UnityEngine.UI.Text GameController::scoreTxt
	Text_t_204341102_0 * ___scoreTxt_3;
	// UnityEngine.UI.Text GameController::gameOverTxt
	Text_t_204341102_0 * ___gameOverTxt_4;
	// UnityEngine.Canvas GameController::gameOverCanvas
	Canvas_t814756449_0 * ___gameOverCanvas_5;
	// System.Int32 GameController::_currScore
	int32_t ____currScore_6;
	// System.Int32 GameController::_scoreToWin
	int32_t ____scoreToWin_7;
	// System.Boolean GameController::_didIWin
	bool ____didIWin_8;
};
