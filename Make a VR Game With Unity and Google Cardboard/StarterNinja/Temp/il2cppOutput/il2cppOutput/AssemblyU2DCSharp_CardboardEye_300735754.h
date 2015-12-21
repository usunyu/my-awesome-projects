#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// StereoController
struct StereoController_t1679119023_0;
// StereoRenderEffect
struct StereoRenderEffect_t664818970_0;
// UnityEngine.Camera
struct Camera_t814710830_0;

#include "UnityEngine_UnityEngine_MonoBehaviour_92453903.h"
#include "AssemblyU2DCSharp_Cardboard_Eye_733578435.h"
#include "UnityEngine_UnityEngine_LayerMask_1132430796.h"
#include "UnityEngine_UnityEngine_Matrix4x41577636070.h"
#include "UnityEngine_UnityEngine_Vector4_725341336.h"

// CardboardEye
struct  CardboardEye_t_300735754_0  : public MonoBehaviour_t_92453903_0
{
	// Cardboard/Eye CardboardEye::eye
	int32_t ___eye_2;
	// UnityEngine.LayerMask CardboardEye::toggleCullingMask
	LayerMask_t_1132430796_0  ___toggleCullingMask_3;
	// StereoController CardboardEye::controller
	StereoController_t1679119023_0 * ___controller_4;
	// StereoRenderEffect CardboardEye::stereoEffect
	StereoRenderEffect_t664818970_0 * ___stereoEffect_5;
	// UnityEngine.Camera CardboardEye::monoCamera
	Camera_t814710830_0 * ___monoCamera_6;
	// UnityEngine.Matrix4x4 CardboardEye::realProj
	Matrix4x4_t1577636070_0  ___realProj_7;
	// UnityEngine.Vector4 CardboardEye::projvec
	Vector4_t_725341336_0  ___projvec_8;
	// UnityEngine.Vector4 CardboardEye::unprojvec
	Vector4_t_725341336_0  ___unprojvec_9;
	// System.Single CardboardEye::interpPosition
	float ___interpPosition_10;
	// UnityEngine.Camera CardboardEye::<camera>k__BackingField
	Camera_t814710830_0 * ___U3CcameraU3Ek__BackingField_11;
};
