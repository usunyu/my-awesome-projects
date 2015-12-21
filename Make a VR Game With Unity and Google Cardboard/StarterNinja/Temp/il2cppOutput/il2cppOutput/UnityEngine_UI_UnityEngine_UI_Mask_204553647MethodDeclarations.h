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

// UnityEngine.UI.Mask
struct Mask_t_204553647_0;
// UnityEngine.RectTransform
struct RectTransform_t212748479_0;
// UnityEngine.UI.Graphic
struct Graphic_t141164899_0;
// UnityEngine.Camera
struct Camera_t814710830_0;
// UnityEngine.Material
struct Material_t1701708784_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"

// System.Void UnityEngine.UI.Mask::.ctor()
extern "C"  void Mask__ctor_m_377293985_0 (Mask_t_204553647_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.RectTransform UnityEngine.UI.Mask::get_rectTransform()
extern "C"  RectTransform_t212748479_0 * Mask_get_rectTransform_m950047934_0 (Mask_t_204553647_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.Mask::get_showMaskGraphic()
extern "C"  bool Mask_get_showMaskGraphic_m_1686337759_0 (Mask_t_204553647_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Mask::set_showMaskGraphic(System.Boolean)
extern "C"  void Mask_set_showMaskGraphic_m218433430_0 (Mask_t_204553647_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.UI.Graphic UnityEngine.UI.Mask::get_graphic()
extern "C"  Graphic_t141164899_0 * Mask_get_graphic_m2101144526_0 (Mask_t_204553647_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.Mask::MaskEnabled()
extern "C"  bool Mask_MaskEnabled_m1398570944_0 (Mask_t_204553647_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Mask::OnSiblingGraphicEnabledDisabled()
extern "C"  void Mask_OnSiblingGraphicEnabledDisabled_m1780324373_0 (Mask_t_204553647_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Mask::OnEnable()
extern "C"  void Mask_OnEnable_m2035884999_0 (Mask_t_204553647_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Mask::OnDisable()
extern "C"  void Mask_OnDisable_m_871137210_0 (Mask_t_204553647_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.Mask::IsRaycastLocationValid(UnityEngine.Vector2,UnityEngine.Camera)
extern "C"  bool Mask_IsRaycastLocationValid_m_241830001_0 (Mask_t_204553647_0 * __this, Vector2_t_725341338_0  ___sp, Camera_t814710830_0 * ___eventCamera, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Material UnityEngine.UI.Mask::GetModifiedMaterial(UnityEngine.Material)
extern "C"  Material_t1701708784_0 * Mask_GetModifiedMaterial_m_468793954_0 (Mask_t_204553647_0 * __this, Material_t1701708784_0 * ___baseMaterial, const MethodInfo* method) IL2CPP_METHOD_ATTR;
