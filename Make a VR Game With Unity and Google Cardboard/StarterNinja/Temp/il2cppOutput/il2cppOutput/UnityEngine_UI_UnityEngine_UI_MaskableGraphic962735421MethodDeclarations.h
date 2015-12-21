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

// UnityEngine.UI.MaskableGraphic
struct MaskableGraphic_t962735421_0;
// UnityEngine.UI.MaskableGraphic/CullStateChangedEvent
struct CullStateChangedEvent_t282446003_0;
// UnityEngine.Material
struct Material_t1701708784_0;
// UnityEngine.RectTransform
struct RectTransform_t212748479_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Rect_981940947.h"

// System.Void UnityEngine.UI.MaskableGraphic::.ctor()
extern "C"  void MaskableGraphic__ctor_m_780733511_0 (MaskableGraphic_t962735421_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.UI.MaskableGraphic/CullStateChangedEvent UnityEngine.UI.MaskableGraphic::get_onCullStateChanged()
extern "C"  CullStateChangedEvent_t282446003_0 * MaskableGraphic_get_onCullStateChanged_m_2001868374_0 (MaskableGraphic_t962735421_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.MaskableGraphic::set_onCullStateChanged(UnityEngine.UI.MaskableGraphic/CullStateChangedEvent)
extern "C"  void MaskableGraphic_set_onCullStateChanged_m1901835143_0 (MaskableGraphic_t962735421_0 * __this, CullStateChangedEvent_t282446003_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.MaskableGraphic::get_maskable()
extern "C"  bool MaskableGraphic_get_maskable_m_2068785304_0 (MaskableGraphic_t962735421_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.MaskableGraphic::set_maskable(System.Boolean)
extern "C"  void MaskableGraphic_set_maskable_m_1206779387_0 (MaskableGraphic_t962735421_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Material UnityEngine.UI.MaskableGraphic::GetModifiedMaterial(UnityEngine.Material)
extern "C"  Material_t1701708784_0 * MaskableGraphic_GetModifiedMaterial_m_1872810394_0 (MaskableGraphic_t962735421_0 * __this, Material_t1701708784_0 * ___baseMaterial, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.MaskableGraphic::Cull(UnityEngine.Rect,System.Boolean)
extern "C"  void MaskableGraphic_Cull_m1710243867_0 (MaskableGraphic_t962735421_0 * __this, Rect_t_981940947_0  ___clipRect, bool ___validRect, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.MaskableGraphic::SetClipRect(UnityEngine.Rect,System.Boolean)
extern "C"  void MaskableGraphic_SetClipRect_m_324273461_0 (MaskableGraphic_t962735421_0 * __this, Rect_t_981940947_0  ___clipRect, bool ___validRect, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.MaskableGraphic::OnEnable()
extern "C"  void MaskableGraphic_OnEnable_m487460141_0 (MaskableGraphic_t962735421_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.MaskableGraphic::OnDisable()
extern "C"  void MaskableGraphic_OnDisable_m_1627667552_0 (MaskableGraphic_t962735421_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.MaskableGraphic::OnTransformParentChanged()
extern "C"  void MaskableGraphic_OnTransformParentChanged_m_1458074232_0 (MaskableGraphic_t962735421_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.MaskableGraphic::ParentMaskStateChanged()
extern "C"  void MaskableGraphic_ParentMaskStateChanged_m_793608092_0 (MaskableGraphic_t962735421_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.MaskableGraphic::OnCanvasHierarchyChanged()
extern "C"  void MaskableGraphic_OnCanvasHierarchyChanged_m_1264806687_0 (MaskableGraphic_t962735421_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Rect UnityEngine.UI.MaskableGraphic::get_canvasRect()
extern "C"  Rect_t_981940947_0  MaskableGraphic_get_canvasRect_m_2110567348_0 (MaskableGraphic_t962735421_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.MaskableGraphic::UpdateClipParent()
extern "C"  void MaskableGraphic_UpdateClipParent_m_1957694354_0 (MaskableGraphic_t962735421_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.MaskableGraphic::RecalculateClipping()
extern "C"  void MaskableGraphic_RecalculateClipping_m400162188_0 (MaskableGraphic_t962735421_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.MaskableGraphic::RecalculateMasking()
extern "C"  void MaskableGraphic_RecalculateMasking_m_2044442738_0 (MaskableGraphic_t962735421_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.RectTransform UnityEngine.UI.MaskableGraphic::UnityEngine.UI.IClippable.get_rectTransform()
extern "C"  RectTransform_t212748479_0 * MaskableGraphic_UnityEngine_UI_IClippable_get_rectTransform_m_438365510_0 (MaskableGraphic_t962735421_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
