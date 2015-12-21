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

// UnityEngine.UI.RectMask2D
struct RectMask2D_t_1803147033_0;
// UnityEngine.RectTransform
struct RectTransform_t212748479_0;
// UnityEngine.Camera
struct Camera_t814710830_0;
// UnityEngine.UI.IClippable
struct IClippable_t_362467914_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Rect_981940947.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"

// System.Void UnityEngine.UI.RectMask2D::.ctor()
extern "C"  void RectMask2D__ctor_m743839689_0 (RectMask2D_t_1803147033_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Rect UnityEngine.UI.RectMask2D::get_canvasRect()
extern "C"  Rect_t_981940947_0  RectMask2D_get_canvasRect_m_411422460_0 (RectMask2D_t_1803147033_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.RectTransform UnityEngine.UI.RectMask2D::get_rectTransform()
extern "C"  RectTransform_t212748479_0 * RectMask2D_get_rectTransform_m_415463256_0 (RectMask2D_t_1803147033_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.RectMask2D::OnEnable()
extern "C"  void RectMask2D_OnEnable_m_231493859_0 (RectMask2D_t_1803147033_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.RectMask2D::OnDisable()
extern "C"  void RectMask2D_OnDisable_m1854562224_0 (RectMask2D_t_1803147033_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.RectMask2D::IsRaycastLocationValid(UnityEngine.Vector2,UnityEngine.Camera)
extern "C"  bool RectMask2D_IsRaycastLocationValid_m_1213127067_0 (RectMask2D_t_1803147033_0 * __this, Vector2_t_725341338_0  ___sp, Camera_t814710830_0 * ___eventCamera, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.RectMask2D::PerformClipping()
extern "C"  void RectMask2D_PerformClipping_m2105337834_0 (RectMask2D_t_1803147033_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.RectMask2D::AddClippable(UnityEngine.UI.IClippable)
extern "C"  void RectMask2D_AddClippable_m_1274605014_0 (RectMask2D_t_1803147033_0 * __this, Object_t * ___clippable, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.RectMask2D::RemoveClippable(UnityEngine.UI.IClippable)
extern "C"  void RectMask2D_RemoveClippable_m_1788540159_0 (RectMask2D_t_1803147033_0 * __this, Object_t * ___clippable, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.RectMask2D::OnTransformParentChanged()
extern "C"  void RectMask2D_OnTransformParentChanged_m136007544_0 (RectMask2D_t_1803147033_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.RectMask2D::OnCanvasHierarchyChanged()
extern "C"  void RectMask2D_OnCanvasHierarchyChanged_m329275089_0 (RectMask2D_t_1803147033_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
