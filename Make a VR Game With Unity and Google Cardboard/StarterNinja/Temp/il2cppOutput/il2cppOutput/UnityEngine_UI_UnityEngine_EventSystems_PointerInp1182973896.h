#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Collections.Generic.Dictionary`2<System.Int32,UnityEngine.EventSystems.PointerEventData>
struct Dictionary_2_t_1819728604_0;
// UnityEngine.EventSystems.PointerInputModule/MouseState
struct MouseState_t_1985972301_0;

#include "UnityEngine_UI_UnityEngine_EventSystems_BaseInput_1390847434.h"

// UnityEngine.EventSystems.PointerInputModule
struct  PointerInputModule_t1182973896_0  : public BaseInputModule_t_1390847434_0
{
	// System.Collections.Generic.Dictionary`2<System.Int32,UnityEngine.EventSystems.PointerEventData> UnityEngine.EventSystems.PointerInputModule::m_PointerData
	Dictionary_2_t_1819728604_0 * ___m_PointerData_10;
	// UnityEngine.EventSystems.PointerInputModule/MouseState UnityEngine.EventSystems.PointerInputModule::m_MouseState
	MouseState_t_1985972301_0 * ___m_MouseState_11;
};
