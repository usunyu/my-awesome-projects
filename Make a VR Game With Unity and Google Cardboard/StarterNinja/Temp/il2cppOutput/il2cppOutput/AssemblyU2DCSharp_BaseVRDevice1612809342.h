#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// BaseVRDevice
struct BaseVRDevice_t1612809342_0;
// MutablePose3D
struct MutablePose3D_t1860023917_0;
// CardboardProfile
struct CardboardProfile_t_739493906_0;

#include "mscorlib_System_Object_887538054.h"
#include "UnityEngine_UnityEngine_Matrix4x41577636070.h"
#include "UnityEngine_UnityEngine_Rect_981940947.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"

// BaseVRDevice
struct  BaseVRDevice_t1612809342_0  : public Object_t
{
	// MutablePose3D BaseVRDevice::headPose
	MutablePose3D_t1860023917_0 * ___headPose_1;
	// MutablePose3D BaseVRDevice::leftEyePose
	MutablePose3D_t1860023917_0 * ___leftEyePose_2;
	// MutablePose3D BaseVRDevice::rightEyePose
	MutablePose3D_t1860023917_0 * ___rightEyePose_3;
	// UnityEngine.Matrix4x4 BaseVRDevice::leftEyeDistortedProjection
	Matrix4x4_t1577636070_0  ___leftEyeDistortedProjection_4;
	// UnityEngine.Matrix4x4 BaseVRDevice::rightEyeDistortedProjection
	Matrix4x4_t1577636070_0  ___rightEyeDistortedProjection_5;
	// UnityEngine.Matrix4x4 BaseVRDevice::leftEyeUndistortedProjection
	Matrix4x4_t1577636070_0  ___leftEyeUndistortedProjection_6;
	// UnityEngine.Matrix4x4 BaseVRDevice::rightEyeUndistortedProjection
	Matrix4x4_t1577636070_0  ___rightEyeUndistortedProjection_7;
	// UnityEngine.Rect BaseVRDevice::leftEyeDistortedViewport
	Rect_t_981940947_0  ___leftEyeDistortedViewport_8;
	// UnityEngine.Rect BaseVRDevice::rightEyeDistortedViewport
	Rect_t_981940947_0  ___rightEyeDistortedViewport_9;
	// UnityEngine.Rect BaseVRDevice::leftEyeUndistortedViewport
	Rect_t_981940947_0  ___leftEyeUndistortedViewport_10;
	// UnityEngine.Rect BaseVRDevice::rightEyeUndistortedViewport
	Rect_t_981940947_0  ___rightEyeUndistortedViewport_11;
	// UnityEngine.Vector2 BaseVRDevice::recommendedTextureSize
	Vector2_t_725341338_0  ___recommendedTextureSize_12;
	// System.Boolean BaseVRDevice::triggered
	bool ___triggered_13;
	// System.Boolean BaseVRDevice::tilted
	bool ___tilted_14;
	// System.Boolean BaseVRDevice::profileChanged
	bool ___profileChanged_15;
	// System.Boolean BaseVRDevice::backButtonPressed
	bool ___backButtonPressed_16;
	// CardboardProfile BaseVRDevice::<Profile>k__BackingField
	CardboardProfile_t_739493906_0 * ___U3CProfileU3Ek__BackingField_17;
};
struct BaseVRDevice_t1612809342_0_StaticFields{
	// BaseVRDevice BaseVRDevice::device
	BaseVRDevice_t1612809342_0 * ___device_0;
};
