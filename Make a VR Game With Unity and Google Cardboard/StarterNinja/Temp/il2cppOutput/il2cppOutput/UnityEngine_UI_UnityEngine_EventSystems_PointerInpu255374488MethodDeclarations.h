#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>
#include <assert.h>
#include <exception>

// UnityEngine.EventSystems.PointerInputModule/ButtonState
struct ButtonState_t255374488_0;
// UnityEngine.EventSystems.PointerInputModule/MouseButtonEventData
struct MouseButtonEventData_t1282251508_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UI_UnityEngine_EventSystems_PointerEv_1735310909.h"

// System.Void UnityEngine.EventSystems.PointerInputModule/ButtonState::.ctor()
extern "C"  void ButtonState__ctor_m858021496_0 (ButtonState_t255374488_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.PointerInputModule/MouseButtonEventData UnityEngine.EventSystems.PointerInputModule/ButtonState::get_eventData()
extern "C"  MouseButtonEventData_t1282251508_0 * ButtonState_get_eventData_m_420171598_0 (ButtonState_t255374488_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerInputModule/ButtonState::set_eventData(UnityEngine.EventSystems.PointerInputModule/MouseButtonEventData)
extern "C"  void ButtonState_set_eventData_m471696551_0 (ButtonState_t255374488_0 * __this, MouseButtonEventData_t1282251508_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.PointerEventData/InputButton UnityEngine.EventSystems.PointerInputModule/ButtonState::get_button()
extern "C"  int32_t ButtonState_get_button_m_1125757163_0 (ButtonState_t255374488_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerInputModule/ButtonState::set_button(UnityEngine.EventSystems.PointerEventData/InputButton)
extern "C"  void ButtonState_set_button_m2005500214_0 (ButtonState_t255374488_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
