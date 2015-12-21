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

// UnityEngine.EventSystems.PointerInputModule
struct PointerInputModule_t1182973896_0;
// UnityEngine.EventSystems.PointerEventData
struct PointerEventData_t_1258954026_0;
// UnityEngine.EventSystems.PointerInputModule/MouseState
struct MouseState_t_1985972301_0;
// System.String
struct String_t;
// UnityEngine.GameObject
struct GameObject_t_184308134_0;
// UnityEngine.EventSystems.BaseEventData
struct BaseEventData_t_273923900_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Touch_373236458.h"
#include "UnityEngine_UI_UnityEngine_EventSystems_PointerEve1773448706.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"

// System.Void UnityEngine.EventSystems.PointerInputModule::.ctor()
extern "C"  void PointerInputModule__ctor_m_1546840888_0 (PointerInputModule_t1182973896_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.PointerInputModule::GetPointerData(System.Int32,UnityEngine.EventSystems.PointerEventData&,System.Boolean)
extern "C"  bool PointerInputModule_GetPointerData_m1554981113_0 (PointerInputModule_t1182973896_0 * __this, int32_t ___id, PointerEventData_t_1258954026_0 ** ___data, bool ___create, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerInputModule::RemovePointerData(UnityEngine.EventSystems.PointerEventData)
extern "C"  void PointerInputModule_RemovePointerData_m_1193507435_0 (PointerInputModule_t1182973896_0 * __this, PointerEventData_t_1258954026_0 * ___data, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.PointerEventData UnityEngine.EventSystems.PointerInputModule::GetTouchPointerEventData(UnityEngine.Touch,System.Boolean&,System.Boolean&)
extern "C"  PointerEventData_t_1258954026_0 * PointerInputModule_GetTouchPointerEventData_m_2100208837_0 (PointerInputModule_t1182973896_0 * __this, Touch_t_373236458_0  ___input, bool* ___pressed, bool* ___released, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerInputModule::CopyFromTo(UnityEngine.EventSystems.PointerEventData,UnityEngine.EventSystems.PointerEventData)
extern "C"  void PointerInputModule_CopyFromTo_m431867808_0 (PointerInputModule_t1182973896_0 * __this, PointerEventData_t_1258954026_0 * ___from, PointerEventData_t_1258954026_0 * ___to, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.PointerEventData/FramePressState UnityEngine.EventSystems.PointerInputModule::StateForMouseButton(System.Int32)
extern "C"  int32_t PointerInputModule_StateForMouseButton_m1241430345_0 (Object_t * __this /* static, unused */, int32_t ___buttonId, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.PointerInputModule/MouseState UnityEngine.EventSystems.PointerInputModule::GetMousePointerEventData()
extern "C"  MouseState_t_1985972301_0 * PointerInputModule_GetMousePointerEventData_m1489718224_0 (PointerInputModule_t1182973896_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.PointerInputModule/MouseState UnityEngine.EventSystems.PointerInputModule::GetMousePointerEventData(System.Int32)
extern "C"  MouseState_t_1985972301_0 * PointerInputModule_GetMousePointerEventData_m_1003108063_0 (PointerInputModule_t1182973896_0 * __this, int32_t ___id, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.PointerEventData UnityEngine.EventSystems.PointerInputModule::GetLastPointerEventData(System.Int32)
extern "C"  PointerEventData_t_1258954026_0 * PointerInputModule_GetLastPointerEventData_m238778665_0 (PointerInputModule_t1182973896_0 * __this, int32_t ___id, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.PointerInputModule::ShouldStartDrag(UnityEngine.Vector2,UnityEngine.Vector2,System.Single,System.Boolean)
extern "C"  bool PointerInputModule_ShouldStartDrag_m1910083073_0 (Object_t * __this /* static, unused */, Vector2_t_725341338_0  ___pressPos, Vector2_t_725341338_0  ___currentPos, float ___threshold, bool ___useDragThreshold, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerInputModule::ProcessMove(UnityEngine.EventSystems.PointerEventData)
extern "C"  void PointerInputModule_ProcessMove_m_1912278216_0 (PointerInputModule_t1182973896_0 * __this, PointerEventData_t_1258954026_0 * ___pointerEvent, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerInputModule::ProcessDrag(UnityEngine.EventSystems.PointerEventData)
extern "C"  void PointerInputModule_ProcessDrag_m1875452405_0 (PointerInputModule_t1182973896_0 * __this, PointerEventData_t_1258954026_0 * ___pointerEvent, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.PointerInputModule::IsPointerOverGameObject(System.Int32)
extern "C"  bool PointerInputModule_IsPointerOverGameObject_m1132541469_0 (PointerInputModule_t1182973896_0 * __this, int32_t ___pointerId, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerInputModule::ClearSelection()
extern "C"  void PointerInputModule_ClearSelection_m1490775995_0 (PointerInputModule_t1182973896_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.EventSystems.PointerInputModule::ToString()
extern "C"  String_t* PointerInputModule_ToString_m1837754533_0 (PointerInputModule_t1182973896_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerInputModule::DeselectIfSelectionChanged(UnityEngine.GameObject,UnityEngine.EventSystems.BaseEventData)
extern "C"  void PointerInputModule_DeselectIfSelectionChanged_m522880394_0 (PointerInputModule_t1182973896_0 * __this, GameObject_t_184308134_0 * ___currentOverGo, BaseEventData_t_273923900_0 * ___pointerEvent, const MethodInfo* method) IL2CPP_METHOD_ATTR;
