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

// UnityEngine.UI.ScrollRect
struct ScrollRect_t_1553243658_0;
// UnityEngine.RectTransform
struct RectTransform_t212748479_0;
// UnityEngine.UI.Scrollbar
struct Scrollbar_t_188636703_0;
// UnityEngine.UI.ScrollRect/ScrollRectEvent
struct ScrollRectEvent_t1460433040_0;
// UnityEngine.EventSystems.PointerEventData
struct PointerEventData_t_1258954026_0;
// UnityEngine.Transform
struct Transform_t1584899523_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UI_UnityEngine_UI_ScrollRect_MovementTy896505890.h"
#include "UnityEngine_UI_UnityEngine_UI_ScrollRect_Scrollbar1713978399.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"
#include "UnityEngine_UI_UnityEngine_UI_CanvasUpdate256425638.h"
#include "UnityEngine_UnityEngine_Bounds799257534.h"

// System.Void UnityEngine.UI.ScrollRect::.ctor()
extern "C"  void ScrollRect__ctor_m_1181835366_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.RectTransform UnityEngine.UI.ScrollRect::get_content()
extern "C"  RectTransform_t212748479_0 * ScrollRect_get_content_m_593334966_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::set_content(UnityEngine.RectTransform)
extern "C"  void ScrollRect_set_content_m234982541_0 (ScrollRect_t_1553243658_0 * __this, RectTransform_t212748479_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.ScrollRect::get_horizontal()
extern "C"  bool ScrollRect_get_horizontal_m_614924951_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::set_horizontal(System.Boolean)
extern "C"  void ScrollRect_set_horizontal_m943369506_0 (ScrollRect_t_1553243658_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.ScrollRect::get_vertical()
extern "C"  bool ScrollRect_get_vertical_m135712059_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::set_vertical(System.Boolean)
extern "C"  void ScrollRect_set_vertical_m_531300876_0 (ScrollRect_t_1553243658_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.UI.ScrollRect/MovementType UnityEngine.UI.ScrollRect::get_movementType()
extern "C"  int32_t ScrollRect_get_movementType_m_280767639_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::set_movementType(UnityEngine.UI.ScrollRect/MovementType)
extern "C"  void ScrollRect_set_movementType_m_61576372_0 (ScrollRect_t_1553243658_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.ScrollRect::get_elasticity()
extern "C"  float ScrollRect_get_elasticity_m1540742464_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::set_elasticity(System.Single)
extern "C"  void ScrollRect_set_elasticity_m957382251_0 (ScrollRect_t_1553243658_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.ScrollRect::get_inertia()
extern "C"  bool ScrollRect_get_inertia_m723925623_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::set_inertia(System.Boolean)
extern "C"  void ScrollRect_set_inertia_m_17154836_0 (ScrollRect_t_1553243658_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.ScrollRect::get_decelerationRate()
extern "C"  float ScrollRect_get_decelerationRate_m_1531602650_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::set_decelerationRate(System.Single)
extern "C"  void ScrollRect_set_decelerationRate_m1911965765_0 (ScrollRect_t_1553243658_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.ScrollRect::get_scrollSensitivity()
extern "C"  float ScrollRect_get_scrollSensitivity_m1352024717_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::set_scrollSensitivity(System.Single)
extern "C"  void ScrollRect_set_scrollSensitivity_m310245950_0 (ScrollRect_t_1553243658_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.RectTransform UnityEngine.UI.ScrollRect::get_viewport()
extern "C"  RectTransform_t212748479_0 * ScrollRect_get_viewport_m1780465687_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::set_viewport(UnityEngine.RectTransform)
extern "C"  void ScrollRect_set_viewport_m1031184500_0 (ScrollRect_t_1553243658_0 * __this, RectTransform_t212748479_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.UI.Scrollbar UnityEngine.UI.ScrollRect::get_horizontalScrollbar()
extern "C"  Scrollbar_t_188636703_0 * ScrollRect_get_horizontalScrollbar_m_1911702139_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::set_horizontalScrollbar(UnityEngine.UI.Scrollbar)
extern "C"  void ScrollRect_set_horizontalScrollbar_m2130920826_0 (ScrollRect_t_1553243658_0 * __this, Scrollbar_t_188636703_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.UI.Scrollbar UnityEngine.UI.ScrollRect::get_verticalScrollbar()
extern "C"  Scrollbar_t_188636703_0 * ScrollRect_get_verticalScrollbar_m801913715_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::set_verticalScrollbar(UnityEngine.UI.Scrollbar)
extern "C"  void ScrollRect_set_verticalScrollbar_m845729640_0 (ScrollRect_t_1553243658_0 * __this, Scrollbar_t_188636703_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.UI.ScrollRect/ScrollbarVisibility UnityEngine.UI.ScrollRect::get_horizontalScrollbarVisibility()
extern "C"  int32_t ScrollRect_get_horizontalScrollbarVisibility_m_1489684167_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::set_horizontalScrollbarVisibility(UnityEngine.UI.ScrollRect/ScrollbarVisibility)
extern "C"  void ScrollRect_set_horizontalScrollbarVisibility_m1831067046_0 (ScrollRect_t_1553243658_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.UI.ScrollRect/ScrollbarVisibility UnityEngine.UI.ScrollRect::get_verticalScrollbarVisibility()
extern "C"  int32_t ScrollRect_get_verticalScrollbarVisibility_m1678458407_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::set_verticalScrollbarVisibility(UnityEngine.UI.ScrollRect/ScrollbarVisibility)
extern "C"  void ScrollRect_set_verticalScrollbarVisibility_m_64449032_0 (ScrollRect_t_1553243658_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.ScrollRect::get_horizontalScrollbarSpacing()
extern "C"  float ScrollRect_get_horizontalScrollbarSpacing_m_1427821304_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::set_horizontalScrollbarSpacing(System.Single)
extern "C"  void ScrollRect_set_horizontalScrollbarSpacing_m1996166051_0 (ScrollRect_t_1553243658_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.ScrollRect::get_verticalScrollbarSpacing()
extern "C"  float ScrollRect_get_verticalScrollbarSpacing_m1095438682_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::set_verticalScrollbarSpacing(System.Single)
extern "C"  void ScrollRect_set_verticalScrollbarSpacing_m_157367151_0 (ScrollRect_t_1553243658_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.UI.ScrollRect/ScrollRectEvent UnityEngine.UI.ScrollRect::get_onValueChanged()
extern "C"  ScrollRectEvent_t1460433040_0 * ScrollRect_get_onValueChanged_m_175570736_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::set_onValueChanged(UnityEngine.UI.ScrollRect/ScrollRectEvent)
extern "C"  void ScrollRect_set_onValueChanged_m499269979_0 (ScrollRect_t_1553243658_0 * __this, ScrollRectEvent_t1460433040_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.RectTransform UnityEngine.UI.ScrollRect::get_viewRect()
extern "C"  RectTransform_t212748479_0 * ScrollRect_get_viewRect_m911909082_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.UI.ScrollRect::get_velocity()
extern "C"  Vector2_t_725341338_0  ScrollRect_get_velocity_m_76907659_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::set_velocity(UnityEngine.Vector2)
extern "C"  void ScrollRect_set_velocity_m_291565994_0 (ScrollRect_t_1553243658_0 * __this, Vector2_t_725341338_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.RectTransform UnityEngine.UI.ScrollRect::get_rectTransform()
extern "C"  RectTransform_t212748479_0 * ScrollRect_get_rectTransform_m836427513_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::Rebuild(UnityEngine.UI.CanvasUpdate)
extern "C"  void ScrollRect_Rebuild_m_965941573_0 (ScrollRect_t_1553243658_0 * __this, int32_t ___executing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::LayoutComplete()
extern "C"  void ScrollRect_LayoutComplete_m1579087085_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::GraphicUpdateComplete()
extern "C"  void ScrollRect_GraphicUpdateComplete_m_2056056222_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::UpdateCachedData()
extern "C"  void ScrollRect_UpdateCachedData_m_13075137_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::OnEnable()
extern "C"  void ScrollRect_OnEnable_m_138884692_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::OnDisable()
extern "C"  void ScrollRect_OnDisable_m430479105_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.ScrollRect::IsActive()
extern "C"  bool ScrollRect_IsActive_m1128064300_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::EnsureLayoutHasRebuilt()
extern "C"  void ScrollRect_EnsureLayoutHasRebuilt_m1972800323_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::StopMovement()
extern "C"  void ScrollRect_StopMovement_m_85715973_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::OnScroll(UnityEngine.EventSystems.PointerEventData)
extern "C"  void ScrollRect_OnScroll_m_1661734456_0 (ScrollRect_t_1553243658_0 * __this, PointerEventData_t_1258954026_0 * ___data, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::OnInitializePotentialDrag(UnityEngine.EventSystems.PointerEventData)
extern "C"  void ScrollRect_OnInitializePotentialDrag_m_1981451901_0 (ScrollRect_t_1553243658_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::OnBeginDrag(UnityEngine.EventSystems.PointerEventData)
extern "C"  void ScrollRect_OnBeginDrag_m1465783272_0 (ScrollRect_t_1553243658_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::OnEndDrag(UnityEngine.EventSystems.PointerEventData)
extern "C"  void ScrollRect_OnEndDrag_m1604287350_0 (ScrollRect_t_1553243658_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::OnDrag(UnityEngine.EventSystems.PointerEventData)
extern "C"  void ScrollRect_OnDrag_m286963457_0 (ScrollRect_t_1553243658_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::SetContentAnchoredPosition(UnityEngine.Vector2)
extern "C"  void ScrollRect_SetContentAnchoredPosition_m716182300_0 (ScrollRect_t_1553243658_0 * __this, Vector2_t_725341338_0  ___position, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::LateUpdate()
extern "C"  void ScrollRect_LateUpdate_m_514041095_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::UpdatePrevData()
extern "C"  void ScrollRect_UpdatePrevData_m454081040_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::UpdateScrollbars(UnityEngine.Vector2)
extern "C"  void ScrollRect_UpdateScrollbars_m_1382430822_0 (ScrollRect_t_1553243658_0 * __this, Vector2_t_725341338_0  ___offset, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.UI.ScrollRect::get_normalizedPosition()
extern "C"  Vector2_t_725341338_0  ScrollRect_get_normalizedPosition_m1721330264_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::set_normalizedPosition(UnityEngine.Vector2)
extern "C"  void ScrollRect_set_normalizedPosition_m_1321947821_0 (ScrollRect_t_1553243658_0 * __this, Vector2_t_725341338_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.ScrollRect::get_horizontalNormalizedPosition()
extern "C"  float ScrollRect_get_horizontalNormalizedPosition_m1672288203_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::set_horizontalNormalizedPosition(System.Single)
extern "C"  void ScrollRect_set_horizontalNormalizedPosition_m2007203264_0 (ScrollRect_t_1553243658_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.ScrollRect::get_verticalNormalizedPosition()
extern "C"  float ScrollRect_get_verticalNormalizedPosition_m_131387491_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::set_verticalNormalizedPosition(System.Single)
extern "C"  void ScrollRect_set_verticalNormalizedPosition_m_1658934482_0 (ScrollRect_t_1553243658_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::SetHorizontalNormalizedPosition(System.Single)
extern "C"  void ScrollRect_SetHorizontalNormalizedPosition_m653475821_0 (ScrollRect_t_1553243658_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::SetVerticalNormalizedPosition(System.Single)
extern "C"  void ScrollRect_SetVerticalNormalizedPosition_m_337439589_0 (ScrollRect_t_1553243658_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::SetNormalizedPosition(System.Single,System.Int32)
extern "C"  void ScrollRect_SetNormalizedPosition_m_98267130_0 (ScrollRect_t_1553243658_0 * __this, float ___value, int32_t ___axis, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.ScrollRect::RubberDelta(System.Single,System.Single)
extern "C"  float ScrollRect_RubberDelta_m403235940_0 (Object_t * __this /* static, unused */, float ___overStretching, float ___viewSize, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::OnRectTransformDimensionsChange()
extern "C"  void ScrollRect_OnRectTransformDimensionsChange_m2105458366_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.ScrollRect::get_hScrollingNeeded()
extern "C"  bool ScrollRect_get_hScrollingNeeded_m1668641607_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.ScrollRect::get_vScrollingNeeded()
extern "C"  bool ScrollRect_get_vScrollingNeeded_m594530553_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::CalculateLayoutInputHorizontal()
extern "C"  void ScrollRect_CalculateLayoutInputHorizontal_m_258944792_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::CalculateLayoutInputVertical()
extern "C"  void ScrollRect_CalculateLayoutInputVertical_m_69503878_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.ScrollRect::get_minWidth()
extern "C"  float ScrollRect_get_minWidth_m525847771_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.ScrollRect::get_preferredWidth()
extern "C"  float ScrollRect_get_preferredWidth_m_2081056948_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.ScrollRect::get_flexibleWidth()
extern "C"  float ScrollRect_get_flexibleWidth_m_1541788554_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.ScrollRect::get_minHeight()
extern "C"  float ScrollRect_get_minHeight_m_374773932_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.ScrollRect::get_preferredHeight()
extern "C"  float ScrollRect_get_preferredHeight_m415558403_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.ScrollRect::get_flexibleHeight()
extern "C"  float ScrollRect_get_flexibleHeight_m_46990567_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.UI.ScrollRect::get_layoutPriority()
extern "C"  int32_t ScrollRect_get_layoutPriority_m_613929511_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::SetLayoutHorizontal()
extern "C"  void ScrollRect_SetLayoutHorizontal_m1751158760_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::SetLayoutVertical()
extern "C"  void ScrollRect_SetLayoutVertical_m1385100154_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::UpdateScrollbarVisibility()
extern "C"  void ScrollRect_UpdateScrollbarVisibility_m_1485973049_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::UpdateScrollbarLayout()
extern "C"  void ScrollRect_UpdateScrollbarLayout_m_1715206689_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::UpdateBounds()
extern "C"  void ScrollRect_UpdateBounds_m1752242888_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Bounds UnityEngine.UI.ScrollRect::GetBounds()
extern "C"  Bounds_t799257534_0  ScrollRect_GetBounds_m1535126094_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.UI.ScrollRect::CalculateOffset(UnityEngine.Vector2)
extern "C"  Vector2_t_725341338_0  ScrollRect_CalculateOffset_m224839950_0 (ScrollRect_t_1553243658_0 * __this, Vector2_t_725341338_0  ___delta, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::SetDirty()
extern "C"  void ScrollRect_SetDirty_m93607546_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.ScrollRect::SetDirtyCaching()
extern "C"  void ScrollRect_SetDirtyCaching_m_79435449_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.ScrollRect::UnityEngine.UI.ICanvasElement.IsDestroyed()
extern "C"  bool ScrollRect_UnityEngine_UI_ICanvasElement_IsDestroyed_m1861319301_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Transform UnityEngine.UI.ScrollRect::UnityEngine.UI.ICanvasElement.get_transform()
extern "C"  Transform_t1584899523_0 * ScrollRect_UnityEngine_UI_ICanvasElement_get_transform_m_978435991_0 (ScrollRect_t_1553243658_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
