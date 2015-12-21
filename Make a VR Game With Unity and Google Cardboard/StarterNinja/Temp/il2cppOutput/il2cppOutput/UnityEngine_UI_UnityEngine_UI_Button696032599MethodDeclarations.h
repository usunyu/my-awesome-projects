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

// UnityEngine.UI.Button
struct Button_t696032599_0;
// UnityEngine.UI.Button/ButtonClickedEvent
struct ButtonClickedEvent_t19529437_0;
// UnityEngine.EventSystems.PointerEventData
struct PointerEventData_t_1258954026_0;
// UnityEngine.EventSystems.BaseEventData
struct BaseEventData_t_273923900_0;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;

#include "codegen/il2cpp-codegen.h"

// System.Void UnityEngine.UI.Button::.ctor()
extern "C"  void Button__ctor_m_931934247_0 (Button_t696032599_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.UI.Button/ButtonClickedEvent UnityEngine.UI.Button::get_onClick()
extern "C"  ButtonClickedEvent_t19529437_0 * Button_get_onClick_m1145127631_0 (Button_t696032599_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Button::set_onClick(UnityEngine.UI.Button/ButtonClickedEvent)
extern "C"  void Button_set_onClick_m_1799723836_0 (Button_t696032599_0 * __this, ButtonClickedEvent_t19529437_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Button::Press()
extern "C"  void Button_Press_m_405875590_0 (Button_t696032599_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Button::OnPointerClick(UnityEngine.EventSystems.PointerEventData)
extern "C"  void Button_OnPointerClick_m_1931390711_0 (Button_t696032599_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Button::OnSubmit(UnityEngine.EventSystems.BaseEventData)
extern "C"  void Button_OnSubmit_m_378693828_0 (Button_t696032599_0 * __this, BaseEventData_t_273923900_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator UnityEngine.UI.Button::OnFinishSubmit()
extern "C"  Object_t * Button_OnFinishSubmit_m46760755_0 (Button_t696032599_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
