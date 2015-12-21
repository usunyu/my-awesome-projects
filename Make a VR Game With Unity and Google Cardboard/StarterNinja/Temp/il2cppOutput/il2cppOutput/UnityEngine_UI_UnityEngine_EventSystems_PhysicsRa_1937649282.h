#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.Camera
struct Camera_t814710830_0;
// System.Comparison`1<UnityEngine.RaycastHit>
struct Comparison_1_t_1393202468_0;

#include "UnityEngine_UI_UnityEngine_EventSystems_BaseRaycaste_1151946.h"
#include "UnityEngine_UnityEngine_LayerMask_1132430796.h"

// UnityEngine.EventSystems.PhysicsRaycaster
struct  PhysicsRaycaster_t_1937649282_0  : public BaseRaycaster_t_1151946_0
{
	// UnityEngine.Camera UnityEngine.EventSystems.PhysicsRaycaster::m_EventCamera
	Camera_t814710830_0 * ___m_EventCamera_3;
	// UnityEngine.LayerMask UnityEngine.EventSystems.PhysicsRaycaster::m_EventMask
	LayerMask_t_1132430796_0  ___m_EventMask_4;
};
struct PhysicsRaycaster_t_1937649282_0_StaticFields{
	// System.Comparison`1<UnityEngine.RaycastHit> UnityEngine.EventSystems.PhysicsRaycaster::<>f__am$cache2
	Comparison_1_t_1393202468_0 * ___U3CU3Ef__amU24cache2_5;
};
