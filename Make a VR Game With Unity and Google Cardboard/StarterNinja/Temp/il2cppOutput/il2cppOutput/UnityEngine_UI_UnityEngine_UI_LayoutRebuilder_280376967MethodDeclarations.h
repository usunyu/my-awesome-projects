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

// UnityEngine.UI.LayoutRebuilder
struct LayoutRebuilder_t_280376967_0;
// UnityEngine.RectTransform
struct RectTransform_t212748479_0;
// UnityEngine.Transform
struct Transform_t1584899523_0;
// System.Collections.Generic.List`1<UnityEngine.Component>
struct List_1_t_503171416_0;
// UnityEngine.Events.UnityAction`1<UnityEngine.Component>
struct UnityAction_1_t559341144_0;
// System.Object
struct Object_t;
// System.String
struct String_t;
// UnityEngine.Component
struct Component_t_867674284_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UI_UnityEngine_UI_CanvasUpdate256425638.h"

// System.Void UnityEngine.UI.LayoutRebuilder::.ctor()
extern "C"  void LayoutRebuilder__ctor_m_778740995_0 (LayoutRebuilder_t_280376967_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.LayoutRebuilder::.cctor()
extern "C"  void LayoutRebuilder__cctor_m1146736720_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.LayoutRebuilder::Initialize(UnityEngine.RectTransform)
extern "C"  void LayoutRebuilder_Initialize_m1265316458_0 (LayoutRebuilder_t_280376967_0 * __this, RectTransform_t212748479_0 * ___controller, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.LayoutRebuilder::Clear()
extern "C"  void LayoutRebuilder_Clear_m922359592_0 (LayoutRebuilder_t_280376967_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.LayoutRebuilder::ReapplyDrivenProperties(UnityEngine.RectTransform)
extern "C"  void LayoutRebuilder_ReapplyDrivenProperties_m965971988_0 (Object_t * __this /* static, unused */, RectTransform_t212748479_0 * ___driven, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Transform UnityEngine.UI.LayoutRebuilder::get_transform()
extern "C"  Transform_t1584899523_0 * LayoutRebuilder_get_transform_m_1063505184_0 (LayoutRebuilder_t_280376967_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.LayoutRebuilder::IsDestroyed()
extern "C"  bool LayoutRebuilder_IsDestroyed_m_290876068_0 (LayoutRebuilder_t_280376967_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.LayoutRebuilder::StripDisabledBehavioursFromList(System.Collections.Generic.List`1<UnityEngine.Component>)
extern "C"  void LayoutRebuilder_StripDisabledBehavioursFromList_m51650679_0 (Object_t * __this /* static, unused */, List_1_t_503171416_0 * ___components, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.LayoutRebuilder::ForceRebuildLayoutImmediate(UnityEngine.RectTransform)
extern "C"  void LayoutRebuilder_ForceRebuildLayoutImmediate_m_593887537_0 (Object_t * __this /* static, unused */, RectTransform_t212748479_0 * ___layoutRoot, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.LayoutRebuilder::Rebuild(UnityEngine.UI.CanvasUpdate)
extern "C"  void LayoutRebuilder_Rebuild_m407530040_0 (LayoutRebuilder_t_280376967_0 * __this, int32_t ___executing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.LayoutRebuilder::PerformLayoutControl(UnityEngine.RectTransform,UnityEngine.Events.UnityAction`1<UnityEngine.Component>)
extern "C"  void LayoutRebuilder_PerformLayoutControl_m724256510_0 (LayoutRebuilder_t_280376967_0 * __this, RectTransform_t212748479_0 * ___rect, UnityAction_1_t559341144_0 * ___action, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.LayoutRebuilder::PerformLayoutCalculation(UnityEngine.RectTransform,UnityEngine.Events.UnityAction`1<UnityEngine.Component>)
extern "C"  void LayoutRebuilder_PerformLayoutCalculation_m941802386_0 (LayoutRebuilder_t_280376967_0 * __this, RectTransform_t212748479_0 * ___rect, UnityAction_1_t559341144_0 * ___action, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.LayoutRebuilder::MarkLayoutForRebuild(UnityEngine.RectTransform)
extern "C"  void LayoutRebuilder_MarkLayoutForRebuild_m901621521_0 (Object_t * __this /* static, unused */, RectTransform_t212748479_0 * ___rect, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.LayoutRebuilder::ValidLayoutGroup(UnityEngine.RectTransform,System.Collections.Generic.List`1<UnityEngine.Component>)
extern "C"  bool LayoutRebuilder_ValidLayoutGroup_m1488924317_0 (Object_t * __this /* static, unused */, RectTransform_t212748479_0 * ___parent, List_1_t_503171416_0 * ___comps, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.LayoutRebuilder::ValidController(UnityEngine.RectTransform,System.Collections.Generic.List`1<UnityEngine.Component>)
extern "C"  bool LayoutRebuilder_ValidController_m_1570284908_0 (Object_t * __this /* static, unused */, RectTransform_t212748479_0 * ___layoutRoot, List_1_t_503171416_0 * ___comps, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.LayoutRebuilder::MarkLayoutRootForRebuild(UnityEngine.RectTransform)
extern "C"  void LayoutRebuilder_MarkLayoutRootForRebuild_m1708966351_0 (Object_t * __this /* static, unused */, RectTransform_t212748479_0 * ___controller, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.LayoutRebuilder::LayoutComplete()
extern "C"  void LayoutRebuilder_LayoutComplete_m182540522_0 (LayoutRebuilder_t_280376967_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.LayoutRebuilder::GraphicUpdateComplete()
extern "C"  void LayoutRebuilder_GraphicUpdateComplete_m408201157_0 (LayoutRebuilder_t_280376967_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.UI.LayoutRebuilder::GetHashCode()
extern "C"  int32_t LayoutRebuilder_GetHashCode_m1333271044_0 (LayoutRebuilder_t_280376967_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.LayoutRebuilder::Equals(System.Object)
extern "C"  bool LayoutRebuilder_Equals_m_719944544_0 (LayoutRebuilder_t_280376967_0 * __this, Object_t * ___obj, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.UI.LayoutRebuilder::ToString()
extern "C"  String_t* LayoutRebuilder_ToString_m_1891152714_0 (LayoutRebuilder_t_280376967_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.LayoutRebuilder::<s_Rebuilders>m__6(UnityEngine.UI.LayoutRebuilder)
extern "C"  void LayoutRebuilder_U3Cs_RebuildersU3Em__6_m831129568_0 (Object_t * __this /* static, unused */, LayoutRebuilder_t_280376967_0 * ___x, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.LayoutRebuilder::<StripDisabledBehavioursFromList>m__7(UnityEngine.Component)
extern "C"  bool LayoutRebuilder_U3CStripDisabledBehavioursFromListU3Em__7_m1620076941_0 (Object_t * __this /* static, unused */, Component_t_867674284_0 * ___e, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.LayoutRebuilder::<Rebuild>m__8(UnityEngine.Component)
extern "C"  void LayoutRebuilder_U3CRebuildU3Em__8_m1336267783_0 (Object_t * __this /* static, unused */, Component_t_867674284_0 * ___e, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.LayoutRebuilder::<Rebuild>m__9(UnityEngine.Component)
extern "C"  void LayoutRebuilder_U3CRebuildU3Em__9_m1269261030_0 (Object_t * __this /* static, unused */, Component_t_867674284_0 * ___e, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.LayoutRebuilder::<Rebuild>m__A(UnityEngine.Component)
extern "C"  void LayoutRebuilder_U3CRebuildU3Em__A_m733207006_0 (Object_t * __this /* static, unused */, Component_t_867674284_0 * ___e, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.LayoutRebuilder::<Rebuild>m__B(UnityEngine.Component)
extern "C"  void LayoutRebuilder_U3CRebuildU3Em__B_m666200253_0 (Object_t * __this /* static, unused */, Component_t_867674284_0 * ___e, const MethodInfo* method) IL2CPP_METHOD_ATTR;
