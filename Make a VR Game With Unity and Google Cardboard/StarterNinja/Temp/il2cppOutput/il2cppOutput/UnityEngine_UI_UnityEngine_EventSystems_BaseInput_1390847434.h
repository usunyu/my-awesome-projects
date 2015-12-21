#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Collections.Generic.List`1<UnityEngine.EventSystems.RaycastResult>
struct List_1_t1613808521_0;
// UnityEngine.EventSystems.AxisEventData
struct AxisEventData_t1026836980_0;
// UnityEngine.EventSystems.EventSystem
struct EventSystem_t813375706_0;
// UnityEngine.EventSystems.BaseEventData
struct BaseEventData_t_273923900_0;

#include "UnityEngine_UI_UnityEngine_EventSystems_UIBehaviou1048696858.h"

// UnityEngine.EventSystems.BaseInputModule
struct  BaseInputModule_t_1390847434_0  : public UIBehaviour_t1048696858_0
{
	// System.Collections.Generic.List`1<UnityEngine.EventSystems.RaycastResult> UnityEngine.EventSystems.BaseInputModule::m_RaycastResultCache
	List_1_t1613808521_0 * ___m_RaycastResultCache_2;
	// UnityEngine.EventSystems.AxisEventData UnityEngine.EventSystems.BaseInputModule::m_AxisEventData
	AxisEventData_t1026836980_0 * ___m_AxisEventData_3;
	// UnityEngine.EventSystems.EventSystem UnityEngine.EventSystems.BaseInputModule::m_EventSystem
	EventSystem_t813375706_0 * ___m_EventSystem_4;
	// UnityEngine.EventSystems.BaseEventData UnityEngine.EventSystems.BaseInputModule::m_BaseEventData
	BaseEventData_t_273923900_0 * ___m_BaseEventData_5;
};
