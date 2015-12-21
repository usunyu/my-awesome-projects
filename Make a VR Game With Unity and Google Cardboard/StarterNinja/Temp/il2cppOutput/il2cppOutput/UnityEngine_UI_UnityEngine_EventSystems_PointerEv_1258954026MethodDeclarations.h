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

// UnityEngine.EventSystems.PointerEventData
struct PointerEventData_t_1258954026_0;
// UnityEngine.EventSystems.EventSystem
struct EventSystem_t813375706_0;
// UnityEngine.GameObject
struct GameObject_t_184308134_0;
// UnityEngine.Camera
struct Camera_t814710830_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UI_UnityEngine_EventSystems_RaycastRes1433838359.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"
#include "UnityEngine_UnityEngine_Vector3_725341337.h"
#include "UnityEngine_UI_UnityEngine_EventSystems_PointerEv_1735310909.h"

// System.Void UnityEngine.EventSystems.PointerEventData::.ctor(UnityEngine.EventSystems.EventSystem)
extern "C"  void PointerEventData__ctor_m82194942_0 (PointerEventData_t_1258954026_0 * __this, EventSystem_t813375706_0 * ___eventSystem, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.EventSystems.PointerEventData::get_pointerEnter()
extern "C"  GameObject_t_184308134_0 * PointerEventData_get_pointerEnter_m1754340511_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerEventData::set_pointerEnter(UnityEngine.GameObject)
extern "C"  void PointerEventData_set_pointerEnter_m_385422598_0 (PointerEventData_t_1258954026_0 * __this, GameObject_t_184308134_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.EventSystems.PointerEventData::get_lastPress()
extern "C"  GameObject_t_184308134_0 * PointerEventData_get_lastPress_m_612571093_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerEventData::set_lastPress(UnityEngine.GameObject)
extern "C"  void PointerEventData_set_lastPress_m1523028000_0 (PointerEventData_t_1258954026_0 * __this, GameObject_t_184308134_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.EventSystems.PointerEventData::get_rawPointerPress()
extern "C"  GameObject_t_184308134_0 * PointerEventData_get_rawPointerPress_m_289425620_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerEventData::set_rawPointerPress(UnityEngine.GameObject)
extern "C"  void PointerEventData_set_rawPointerPress_m505214625_0 (PointerEventData_t_1258954026_0 * __this, GameObject_t_184308134_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.EventSystems.PointerEventData::get_pointerDrag()
extern "C"  GameObject_t_184308134_0 * PointerEventData_get_pointerDrag_m2109300143_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerEventData::set_pointerDrag(UnityEngine.GameObject)
extern "C"  void PointerEventData_set_pointerDrag_m1194168164_0 (PointerEventData_t_1258954026_0 * __this, GameObject_t_184308134_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.RaycastResult UnityEngine.EventSystems.PointerEventData::get_pointerCurrentRaycast()
extern "C"  RaycastResult_t1433838359_0  PointerEventData_get_pointerCurrentRaycast_m874132826_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerEventData::set_pointerCurrentRaycast(UnityEngine.EventSystems.RaycastResult)
extern "C"  void PointerEventData_set_pointerCurrentRaycast_m_1410869489_0 (PointerEventData_t_1258954026_0 * __this, RaycastResult_t1433838359_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.RaycastResult UnityEngine.EventSystems.PointerEventData::get_pointerPressRaycast()
extern "C"  RaycastResult_t1433838359_0  PointerEventData_get_pointerPressRaycast_m990488592_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerEventData::set_pointerPressRaycast(UnityEngine.EventSystems.RaycastResult)
extern "C"  void PointerEventData_set_pointerPressRaycast_m126348485_0 (PointerEventData_t_1258954026_0 * __this, RaycastResult_t1433838359_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.PointerEventData::get_eligibleForClick()
extern "C"  bool PointerEventData_get_eligibleForClick_m804806107_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerEventData::set_eligibleForClick(System.Boolean)
extern "C"  void PointerEventData_set_eligibleForClick_m_170297196_0 (PointerEventData_t_1258954026_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.EventSystems.PointerEventData::get_pointerId()
extern "C"  int32_t PointerEventData_get_pointerId_m315063471_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerEventData::set_pointerId(System.Int32)
extern "C"  void PointerEventData_set_pointerId_m204336548_0 (PointerEventData_t_1258954026_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.EventSystems.PointerEventData::get_position()
extern "C"  Vector2_t_725341338_0  PointerEventData_get_position_m_2031843935_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerEventData::set_position(UnityEngine.Vector2)
extern "C"  void PointerEventData_set_position_m1287828138_0 (PointerEventData_t_1258954026_0 * __this, Vector2_t_725341338_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.EventSystems.PointerEventData::get_delta()
extern "C"  Vector2_t_725341338_0  PointerEventData_get_delta_m_182724510_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerEventData::set_delta(UnityEngine.Vector2)
extern "C"  void PointerEventData_set_delta_m_814864505_0 (PointerEventData_t_1258954026_0 * __this, Vector2_t_725341338_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.EventSystems.PointerEventData::get_pressPosition()
extern "C"  Vector2_t_725341338_0  PointerEventData_get_pressPosition_m_1576817354_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerEventData::set_pressPosition(UnityEngine.Vector2)
extern "C"  void PointerEventData_set_pressPosition_m_1238336717_0 (PointerEventData_t_1258954026_0 * __this, Vector2_t_725341338_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector3 UnityEngine.EventSystems.PointerEventData::get_worldPosition()
extern "C"  Vector3_t_725341337_0  PointerEventData_get_worldPosition_m489722276_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerEventData::set_worldPosition(UnityEngine.Vector3)
extern "C"  void PointerEventData_set_worldPosition_m914315875_0 (PointerEventData_t_1258954026_0 * __this, Vector3_t_725341337_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector3 UnityEngine.EventSystems.PointerEventData::get_worldNormal()
extern "C"  Vector3_t_725341337_0  PointerEventData_get_worldNormal_m_824581022_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerEventData::set_worldNormal(UnityEngine.Vector3)
extern "C"  void PointerEventData_set_worldNormal_m2060170853_0 (PointerEventData_t_1258954026_0 * __this, Vector3_t_725341337_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.EventSystems.PointerEventData::get_clickTime()
extern "C"  float PointerEventData_get_clickTime_m_1765297200_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerEventData::set_clickTime(System.Single)
extern "C"  void PointerEventData_set_clickTime_m_807316005_0 (PointerEventData_t_1258954026_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.EventSystems.PointerEventData::get_clickCount()
extern "C"  int32_t PointerEventData_get_clickCount_m341347570_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerEventData::set_clickCount(System.Int32)
extern "C"  void PointerEventData_set_clickCount_m_2015862369_0 (PointerEventData_t_1258954026_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.EventSystems.PointerEventData::get_scrollDelta()
extern "C"  Vector2_t_725341338_0  PointerEventData_get_scrollDelta_m_692185579_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerEventData::set_scrollDelta(UnityEngine.Vector2)
extern "C"  void PointerEventData_set_scrollDelta_m_787341388_0 (PointerEventData_t_1258954026_0 * __this, Vector2_t_725341338_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.PointerEventData::get_useDragThreshold()
extern "C"  bool PointerEventData_get_useDragThreshold_m_1545283211_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerEventData::set_useDragThreshold(System.Boolean)
extern "C"  void PointerEventData_set_useDragThreshold_m_1764712786_0 (PointerEventData_t_1258954026_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.PointerEventData::get_dragging()
extern "C"  bool PointerEventData_get_dragging_m_975747148_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerEventData::set_dragging(System.Boolean)
extern "C"  void PointerEventData_set_dragging_m1730892973_0 (PointerEventData_t_1258954026_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.PointerEventData/InputButton UnityEngine.EventSystems.PointerEventData::get_button()
extern "C"  int32_t PointerEventData_get_button_m796143251_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerEventData::set_button(UnityEngine.EventSystems.PointerEventData/InputButton)
extern "C"  void PointerEventData_set_button_m_1574679304_0 (PointerEventData_t_1258954026_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.PointerEventData::IsPointerMoving()
extern "C"  bool PointerEventData_IsPointerMoving_m1462208007_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.PointerEventData::IsScrolling()
extern "C"  bool PointerEventData_IsScrolling_m2052637201_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Camera UnityEngine.EventSystems.PointerEventData::get_enterEventCamera()
extern "C"  Camera_t814710830_0 * PointerEventData_get_enterEventCamera_m1535306943_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Camera UnityEngine.EventSystems.PointerEventData::get_pressEventCamera()
extern "C"  Camera_t814710830_0 * PointerEventData_get_pressEventCamera_m_1530874572_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.EventSystems.PointerEventData::get_pointerPress()
extern "C"  GameObject_t_184308134_0 * PointerEventData_get_pointerPress_m_1266939062_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PointerEventData::set_pointerPress(UnityEngine.GameObject)
extern "C"  void PointerEventData_set_pointerPress_m_1257457819_0 (PointerEventData_t_1258954026_0 * __this, GameObject_t_184308134_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.EventSystems.PointerEventData::ToString()
extern "C"  String_t* PointerEventData_ToString_m746384051_0 (PointerEventData_t_1258954026_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
