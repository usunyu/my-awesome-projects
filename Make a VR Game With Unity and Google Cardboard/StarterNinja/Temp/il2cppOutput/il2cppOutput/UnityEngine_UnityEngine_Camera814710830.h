#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.Camera/CameraCallback
struct CameraCallback_t667352747_0;

#include "UnityEngine_UnityEngine_Behaviour125883156.h"

// UnityEngine.Camera
struct  Camera_t814710830_0  : public Behaviour_t125883156_0
{
};
struct Camera_t814710830_0_StaticFields{
	// UnityEngine.Camera/CameraCallback UnityEngine.Camera::onPreCull
	CameraCallback_t667352747_0 * ___onPreCull_2;
	// UnityEngine.Camera/CameraCallback UnityEngine.Camera::onPreRender
	CameraCallback_t667352747_0 * ___onPreRender_3;
	// UnityEngine.Camera/CameraCallback UnityEngine.Camera::onPostRender
	CameraCallback_t667352747_0 * ___onPostRender_4;
};
