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

// UnityEngine.EventSystems.PointerInputModule/MouseState
struct MouseState_t_1985972301_0;
// UnityEngine.EventSystems.PointerInputModule/ButtonState
struct ButtonState_t255374488_0;
// UnityEngine.EventSystems.PointerEventData
struct PointerEventData_t_1258954026_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UI_UnityEngine_EventSystems_PointerEv_1735310909.h"
#include "UnityEngine_UI_UnityEngine_EventSystems_PointerEve1773448706.h"

// System.Void UnityEngine.EventSystems.PointerInputModule/MouseState::.ctor()
extern "C"  void MouseState__ctor_m_1673755389_0 (MouseState_t_1985972301_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.PointerInputModule/MouseState::AnyPressesThisFrame()
extern "C"  bool MouseState_AnyPressesThisFrame_m_373383587_0 (MouseState_t_1985972301_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.PointerInputModule/MouseState::AnyReleasesThisFrame()
extern "C"  bool MouseState_AnyReleasesThisFrame_m_1622842138_0 (MouseState_t_1985972301_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.PointerInputModule/ButtonState UnityEngine.EventSystems.PointerInputModule/MouseState::GetButtonState(UnityEngine.EventSystems.PointerEventData/InputButton)
extern "C"  ButtonState_t255374488_0 * MouseState_GetButtonState_m96912714_0 (MouseState_t_1985972301_0 * __this, int32_t ___button, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerInputModule/MouseState::SetButtonState(UnityEngine.EventSystems.PointerEventData/InputButton,UnityEngine.EventSystems.PointerEventData/FramePressState,UnityEngine.EventSystems.PointerEventData)
extern "C"  void MouseState_SetButtonState_m_824545705_0 (MouseState_t_1985972301_0 * __this, int32_t ___button, int32_t ___stateForMouseButton, PointerEventData_t_1258954026_0 * ___data, const MethodInfo* method) IL2CPP_METHOD_ATTR;
