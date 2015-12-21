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

// UnityEngine.UI.Scrollbar
struct Scrollbar_t_188636703_0;
// UnityEngine.RectTransform
struct RectTransform_t212748479_0;
// UnityEngine.UI.Scrollbar/ScrollEvent
struct ScrollEvent_t708227199_0;
// UnityEngine.EventSystems.PointerEventData
struct PointerEventData_t_1258954026_0;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;
// UnityEngine.EventSystems.AxisEventData
struct AxisEventData_t1026836980_0;
// UnityEngine.UI.Selectable
struct Selectable_t1019922427_0;
// UnityEngine.Transform
struct Transform_t1584899523_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UI_UnityEngine_UI_Scrollbar_Direction_2139395919.h"
#include "UnityEngine_UI_UnityEngine_UI_CanvasUpdate256425638.h"
#include "UnityEngine_UI_UnityEngine_UI_Scrollbar_Axis448991023.h"

// System.Void UnityEngine.UI.Scrollbar::.ctor()
extern "C"  void Scrollbar__ctor_m842961365_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.RectTransform UnityEngine.UI.Scrollbar::get_handleRect()
extern "C"  RectTransform_t212748479_0 * Scrollbar_get_handleRect_m2010533702_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::set_handleRect(UnityEngine.RectTransform)
extern "C"  void Scrollbar_set_handleRect_m_1919411671_0 (Scrollbar_t_188636703_0 * __this, RectTransform_t212748479_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.UI.Scrollbar/Direction UnityEngine.UI.Scrollbar::get_direction()
extern "C"  int32_t Scrollbar_get_direction_m_2136416763_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::set_direction(UnityEngine.UI.Scrollbar/Direction)
extern "C"  void Scrollbar_set_direction_m1167543746_0 (Scrollbar_t_188636703_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.Scrollbar::get_value()
extern "C"  float Scrollbar_get_value_m_896704817_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::set_value(System.Single)
extern "C"  void Scrollbar_set_value_m1765490852_0 (Scrollbar_t_188636703_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.Scrollbar::get_size()
extern "C"  float Scrollbar_get_size_m1139900549_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::set_size(System.Single)
extern "C"  void Scrollbar_set_size_m298852062_0 (Scrollbar_t_188636703_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.UI.Scrollbar::get_numberOfSteps()
extern "C"  int32_t Scrollbar_get_numberOfSteps_m1873821577_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::set_numberOfSteps(System.Int32)
extern "C"  void Scrollbar_set_numberOfSteps_m_1789466034_0 (Scrollbar_t_188636703_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.UI.Scrollbar/ScrollEvent UnityEngine.UI.Scrollbar::get_onValueChanged()
extern "C"  ScrollEvent_t708227199_0 * Scrollbar_get_onValueChanged_m312588368_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::set_onValueChanged(UnityEngine.UI.Scrollbar/ScrollEvent)
extern "C"  void Scrollbar_set_onValueChanged_m_1353054803_0 (Scrollbar_t_188636703_0 * __this, ScrollEvent_t708227199_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.Scrollbar::get_stepSize()
extern "C"  float Scrollbar_get_stepSize_m1660915953_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::Rebuild(UnityEngine.UI.CanvasUpdate)
extern "C"  void Scrollbar_Rebuild_m36029024_0 (Scrollbar_t_188636703_0 * __this, int32_t ___executing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::LayoutComplete()
extern "C"  void Scrollbar_LayoutComplete_m_198421230_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::GraphicUpdateComplete()
extern "C"  void Scrollbar_GraphicUpdateComplete_m_349884771_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::OnEnable()
extern "C"  void Scrollbar_OnEnable_m2059823505_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::OnDisable()
extern "C"  void Scrollbar_OnDisable_m_129043524_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::UpdateCachedReferences()
extern "C"  void Scrollbar_UpdateCachedReferences_m1478280386_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::Set(System.Single)
extern "C"  void Scrollbar_Set_m_1706926986_0 (Scrollbar_t_188636703_0 * __this, float ___input, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::Set(System.Single,System.Boolean)
extern "C"  void Scrollbar_Set_m_910771129_0 (Scrollbar_t_188636703_0 * __this, float ___input, bool ___sendCallback, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::OnRectTransformDimensionsChange()
extern "C"  void Scrollbar_OnRectTransformDimensionsChange_m1089670457_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.UI.Scrollbar/Axis UnityEngine.UI.Scrollbar::get_axis()
extern "C"  int32_t Scrollbar_get_axis_m_869135297_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.Scrollbar::get_reverseValue()
extern "C"  bool Scrollbar_get_reverseValue_m581327093_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::UpdateVisuals()
extern "C"  void Scrollbar_UpdateVisuals_m_1541374307_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::UpdateDrag(UnityEngine.EventSystems.PointerEventData)
extern "C"  void Scrollbar_UpdateDrag_m494154322_0 (Scrollbar_t_188636703_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.Scrollbar::MayDrag(UnityEngine.EventSystems.PointerEventData)
extern "C"  bool Scrollbar_MayDrag_m_1425994784_0 (Scrollbar_t_188636703_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::OnBeginDrag(UnityEngine.EventSystems.PointerEventData)
extern "C"  void Scrollbar_OnBeginDrag_m1703358541_0 (Scrollbar_t_188636703_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::OnDrag(UnityEngine.EventSystems.PointerEventData)
extern "C"  void Scrollbar_OnDrag_m_271536260_0 (Scrollbar_t_188636703_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::OnPointerDown(UnityEngine.EventSystems.PointerEventData)
extern "C"  void Scrollbar_OnPointerDown_m984641739_0 (Scrollbar_t_188636703_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator UnityEngine.UI.Scrollbar::ClickRepeat(UnityEngine.EventSystems.PointerEventData)
extern "C"  Object_t * Scrollbar_ClickRepeat_m1553202218_0 (Scrollbar_t_188636703_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::OnPointerUp(UnityEngine.EventSystems.PointerEventData)
extern "C"  void Scrollbar_OnPointerUp_m_2045286094_0 (Scrollbar_t_188636703_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::OnMove(UnityEngine.EventSystems.AxisEventData)
extern "C"  void Scrollbar_OnMove_m_1788900471_0 (Scrollbar_t_188636703_0 * __this, AxisEventData_t1026836980_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.UI.Selectable UnityEngine.UI.Scrollbar::FindSelectableOnLeft()
extern "C"  Selectable_t1019922427_0 * Scrollbar_FindSelectableOnLeft_m976215998_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.UI.Selectable UnityEngine.UI.Scrollbar::FindSelectableOnRight()
extern "C"  Selectable_t1019922427_0 * Scrollbar_FindSelectableOnRight_m1343135335_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.UI.Selectable UnityEngine.UI.Scrollbar::FindSelectableOnUp()
extern "C"  Selectable_t1019922427_0 * Scrollbar_FindSelectableOnUp_m_1326080302_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.UI.Selectable UnityEngine.UI.Scrollbar::FindSelectableOnDown()
extern "C"  Selectable_t1019922427_0 * Scrollbar_FindSelectableOnDown_m756918681_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::OnInitializePotentialDrag(UnityEngine.EventSystems.PointerEventData)
extern "C"  void Scrollbar_OnInitializePotentialDrag_m_1887536856_0 (Scrollbar_t_188636703_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Scrollbar::SetDirection(UnityEngine.UI.Scrollbar/Direction,System.Boolean)
extern "C"  void Scrollbar_SetDirection_m826288644_0 (Scrollbar_t_188636703_0 * __this, int32_t ___direction, bool ___includeRectLayouts, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.Scrollbar::UnityEngine.UI.ICanvasElement.IsDestroyed()
extern "C"  bool Scrollbar_UnityEngine_UI_ICanvasElement_IsDestroyed_m_1065258524_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Transform UnityEngine.UI.Scrollbar::UnityEngine.UI.ICanvasElement.get_transform()
extern "C"  Transform_t1584899523_0 * Scrollbar_UnityEngine_UI_ICanvasElement_get_transform_m1065549160_0 (Scrollbar_t_188636703_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
