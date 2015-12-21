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

// UnityEngine.EventSystems.EventTrigger
struct EventTrigger_t122322029_0;
// System.Collections.Generic.List`1<UnityEngine.EventSystems.EventTrigger/Entry>
struct List_1_t_775499828_0;
// UnityEngine.EventSystems.BaseEventData
struct BaseEventData_t_273923900_0;
// UnityEngine.EventSystems.PointerEventData
struct PointerEventData_t_1258954026_0;
// UnityEngine.EventSystems.AxisEventData
struct AxisEventData_t1026836980_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UI_UnityEngine_EventSystems_EventTrigge735347015.h"

// System.Void UnityEngine.EventSystems.EventTrigger::.ctor()
extern "C"  void EventTrigger__ctor_m_884781181_0 (EventTrigger_t122322029_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.Generic.List`1<UnityEngine.EventSystems.EventTrigger/Entry> UnityEngine.EventSystems.EventTrigger::get_triggers()
extern "C"  List_1_t_775499828_0 * EventTrigger_get_triggers_m900961340_0 (EventTrigger_t122322029_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventTrigger::set_triggers(System.Collections.Generic.List`1<UnityEngine.EventSystems.EventTrigger/Entry>)
extern "C"  void EventTrigger_set_triggers_m_1338327093_0 (EventTrigger_t122322029_0 * __this, List_1_t_775499828_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventTrigger::Execute(UnityEngine.EventSystems.EventTriggerType,UnityEngine.EventSystems.BaseEventData)
extern "C"  void EventTrigger_Execute_m1768335209_0 (EventTrigger_t122322029_0 * __this, int32_t ___id, BaseEventData_t_273923900_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventTrigger::OnPointerEnter(UnityEngine.EventSystems.PointerEventData)
extern "C"  void EventTrigger_OnPointerEnter_m_595992861_0 (EventTrigger_t122322029_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventTrigger::OnPointerExit(UnityEngine.EventSystems.PointerEventData)
extern "C"  void EventTrigger_OnPointerExit_m_225561887_0 (EventTrigger_t122322029_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventTrigger::OnDrag(UnityEngine.EventSystems.PointerEventData)
extern "C"  void EventTrigger_OnDrag_m621966250_0 (EventTrigger_t122322029_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventTrigger::OnDrop(UnityEngine.EventSystems.PointerEventData)
extern "C"  void EventTrigger_OnDrop_m1949092623_0 (EventTrigger_t122322029_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventTrigger::OnPointerDown(UnityEngine.EventSystems.PointerEventData)
extern "C"  void EventTrigger_OnPointerDown_m_618644259_0 (EventTrigger_t122322029_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventTrigger::OnPointerUp(UnityEngine.EventSystems.PointerEventData)
extern "C"  void EventTrigger_OnPointerUp_m902762948_0 (EventTrigger_t122322029_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventTrigger::OnPointerClick(UnityEngine.EventSystems.PointerEventData)
extern "C"  void EventTrigger_OnPointerClick_m_65744333_0 (EventTrigger_t122322029_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventTrigger::OnSelect(UnityEngine.EventSystems.BaseEventData)
extern "C"  void EventTrigger_OnSelect_m_690782282_0 (EventTrigger_t122322029_0 * __this, BaseEventData_t_273923900_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventTrigger::OnDeselect(UnityEngine.EventSystems.BaseEventData)
extern "C"  void EventTrigger_OnDeselect_m1138247351_0 (EventTrigger_t122322029_0 * __this, BaseEventData_t_273923900_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventTrigger::OnScroll(UnityEngine.EventSystems.PointerEventData)
extern "C"  void EventTrigger_OnScroll_m_1846597583_0 (EventTrigger_t122322029_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventTrigger::OnMove(UnityEngine.EventSystems.AxisEventData)
extern "C"  void EventTrigger_OnMove_m_251009509_0 (EventTrigger_t122322029_0 * __this, AxisEventData_t1026836980_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventTrigger::OnUpdateSelected(UnityEngine.EventSystems.BaseEventData)
extern "C"  void EventTrigger_OnUpdateSelected_m1400064574_0 (EventTrigger_t122322029_0 * __this, BaseEventData_t_273923900_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventTrigger::OnInitializePotentialDrag(UnityEngine.EventSystems.PointerEventData)
extern "C"  void EventTrigger_OnInitializePotentialDrag_m802339386_0 (EventTrigger_t122322029_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventTrigger::OnBeginDrag(UnityEngine.EventSystems.PointerEventData)
extern "C"  void EventTrigger_OnBeginDrag_m356440287_0 (EventTrigger_t122322029_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventTrigger::OnEndDrag(UnityEngine.EventSystems.PointerEventData)
extern "C"  void EventTrigger_OnEndDrag_m168497709_0 (EventTrigger_t122322029_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventTrigger::OnSubmit(UnityEngine.EventSystems.BaseEventData)
extern "C"  void EventTrigger_OnSubmit_m974012114_0 (EventTrigger_t122322029_0 * __this, BaseEventData_t_273923900_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventTrigger::OnCancel(UnityEngine.EventSystems.BaseEventData)
extern "C"  void EventTrigger_OnCancel_m972464948_0 (EventTrigger_t122322029_0 * __this, BaseEventData_t_273923900_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
