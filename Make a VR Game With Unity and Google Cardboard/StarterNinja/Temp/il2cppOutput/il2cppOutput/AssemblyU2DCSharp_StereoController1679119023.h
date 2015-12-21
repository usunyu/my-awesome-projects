#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.Transform
struct Transform_t1584899523_0;
// CardboardEye[]
struct CardboardEyeU5BU5D_t_1244247848_0;
// CardboardHead
struct CardboardHead_t_732803653_0;
// UnityEngine.Camera
struct Camera_t814710830_0;
// System.Func`2<CardboardEye,CardboardHead>
struct Func_2_t776257015_0;

#include "UnityEngine_UnityEngine_MonoBehaviour_92453903.h"

// StereoController
struct  StereoController_t1679119023_0  : public MonoBehaviour_t_92453903_0
{
	// System.Boolean StereoController::directRender
	bool ___directRender_2;
	// System.Boolean StereoController::keepStereoUpdated
	bool ___keepStereoUpdated_3;
	// System.Single StereoController::stereoMultiplier
	float ___stereoMultiplier_4;
	// System.Single StereoController::matchMonoFOV
	float ___matchMonoFOV_5;
	// System.Single StereoController::matchByZoom
	float ___matchByZoom_6;
	// UnityEngine.Transform StereoController::centerOfInterest
	Transform_t1584899523_0 * ___centerOfInterest_7;
	// System.Single StereoController::radiusOfInterest
	float ___radiusOfInterest_8;
	// System.Boolean StereoController::checkStereoComfort
	bool ___checkStereoComfort_9;
	// System.Single StereoController::stereoAdjustSmoothing
	float ___stereoAdjustSmoothing_10;
	// System.Single StereoController::screenParallax
	float ___screenParallax_11;
	// System.Single StereoController::stereoPaddingX
	float ___stereoPaddingX_12;
	// System.Single StereoController::stereoPaddingY
	float ___stereoPaddingY_13;
	// System.Boolean StereoController::renderedStereo
	bool ___renderedStereo_14;
	// CardboardEye[] StereoController::eyes
	CardboardEyeU5BU5D_t_1244247848_0* ___eyes_15;
	// CardboardHead StereoController::head
	CardboardHead_t_732803653_0 * ___head_16;
	// UnityEngine.Camera StereoController::<camera>k__BackingField
	Camera_t814710830_0 * ___U3CcameraU3Ek__BackingField_17;
};
struct StereoController_t1679119023_0_StaticFields{
	// System.Func`2<CardboardEye,CardboardHead> StereoController::<>f__am$cache10
	Func_2_t776257015_0 * ___U3CU3Ef__amU24cache10_18;
};
