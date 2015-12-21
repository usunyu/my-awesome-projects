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

// UnityEngine.RectTransform
struct RectTransform_t212748479_0;
// UnityEngine.Camera
struct Camera_t814710830_0;
// UnityEngine.Transform
struct Transform_t1584899523_0;
// UnityEngine.Canvas
struct Canvas_t814756449_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"
#include "UnityEngine_UnityEngine_Rect_981940947.h"
#include "UnityEngine_UnityEngine_Vector3_725341337.h"
#include "UnityEngine_UnityEngine_Ray1215250369.h"

// System.Void UnityEngine.RectTransformUtility::.cctor()
extern "C"  void RectTransformUtility__cctor_m_1199036_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.RectTransformUtility::RectangleContainsScreenPoint(UnityEngine.RectTransform,UnityEngine.Vector2,UnityEngine.Camera)
extern "C"  bool RectTransformUtility_RectangleContainsScreenPoint_m1460676684_0 (Object_t * __this /* static, unused */, RectTransform_t212748479_0 * ___rect, Vector2_t_725341338_0  ___screenPoint, Camera_t814710830_0 * ___cam, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.RectTransformUtility::INTERNAL_CALL_RectangleContainsScreenPoint(UnityEngine.RectTransform,UnityEngine.Vector2&,UnityEngine.Camera)
extern "C"  bool RectTransformUtility_INTERNAL_CALL_RectangleContainsScreenPoint_m1592514141_0 (Object_t * __this /* static, unused */, RectTransform_t212748479_0 * ___rect, Vector2_t_725341338_0 * ___screenPoint, Camera_t814710830_0 * ___cam, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.RectTransformUtility::PixelAdjustPoint(UnityEngine.Vector2,UnityEngine.Transform,UnityEngine.Canvas)
extern "C"  Vector2_t_725341338_0  RectTransformUtility_PixelAdjustPoint_m_1776658537_0 (Object_t * __this /* static, unused */, Vector2_t_725341338_0  ___point, Transform_t1584899523_0 * ___elementTransform, Canvas_t814756449_0 * ___canvas, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.RectTransformUtility::PixelAdjustPoint(UnityEngine.Vector2,UnityEngine.Transform,UnityEngine.Canvas,UnityEngine.Vector2&)
extern "C"  void RectTransformUtility_PixelAdjustPoint_m1313063708_0 (Object_t * __this /* static, unused */, Vector2_t_725341338_0  ___point, Transform_t1584899523_0 * ___elementTransform, Canvas_t814756449_0 * ___canvas, Vector2_t_725341338_0 * ___output, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.RectTransformUtility::INTERNAL_CALL_PixelAdjustPoint(UnityEngine.Vector2&,UnityEngine.Transform,UnityEngine.Canvas,UnityEngine.Vector2&)
extern "C"  void RectTransformUtility_INTERNAL_CALL_PixelAdjustPoint_m1509640863_0 (Object_t * __this /* static, unused */, Vector2_t_725341338_0 * ___point, Transform_t1584899523_0 * ___elementTransform, Canvas_t814756449_0 * ___canvas, Vector2_t_725341338_0 * ___output, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Rect UnityEngine.RectTransformUtility::PixelAdjustRect(UnityEngine.RectTransform,UnityEngine.Canvas)
extern "C"  Rect_t_981940947_0  RectTransformUtility_PixelAdjustRect_m_567251166_0 (Object_t * __this /* static, unused */, RectTransform_t212748479_0 * ___rectTransform, Canvas_t814756449_0 * ___canvas, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.RectTransformUtility::INTERNAL_CALL_PixelAdjustRect(UnityEngine.RectTransform,UnityEngine.Canvas,UnityEngine.Rect&)
extern "C"  void RectTransformUtility_INTERNAL_CALL_PixelAdjustRect_m1038323288_0 (Object_t * __this /* static, unused */, RectTransform_t212748479_0 * ___rectTransform, Canvas_t814756449_0 * ___canvas, Rect_t_981940947_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.RectTransformUtility::ScreenPointToWorldPointInRectangle(UnityEngine.RectTransform,UnityEngine.Vector2,UnityEngine.Camera,UnityEngine.Vector3&)
extern "C"  bool RectTransformUtility_ScreenPointToWorldPointInRectangle_m_438765578_0 (Object_t * __this /* static, unused */, RectTransform_t212748479_0 * ___rect, Vector2_t_725341338_0  ___screenPoint, Camera_t814710830_0 * ___cam, Vector3_t_725341337_0 * ___worldPoint, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.RectTransformUtility::ScreenPointToLocalPointInRectangle(UnityEngine.RectTransform,UnityEngine.Vector2,UnityEngine.Camera,UnityEngine.Vector2&)
extern "C"  bool RectTransformUtility_ScreenPointToLocalPointInRectangle_m666650172_0 (Object_t * __this /* static, unused */, RectTransform_t212748479_0 * ___rect, Vector2_t_725341338_0  ___screenPoint, Camera_t814710830_0 * ___cam, Vector2_t_725341338_0 * ___localPoint, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Ray UnityEngine.RectTransformUtility::ScreenPointToRay(UnityEngine.Camera,UnityEngine.Vector2)
extern "C"  Ray_t1215250369_0  RectTransformUtility_ScreenPointToRay_m1216104542_0 (Object_t * __this /* static, unused */, Camera_t814710830_0 * ___cam, Vector2_t_725341338_0  ___screenPos, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.RectTransformUtility::FlipLayoutOnAxis(UnityEngine.RectTransform,System.Int32,System.Boolean,System.Boolean)
extern "C"  void RectTransformUtility_FlipLayoutOnAxis_m_807537944_0 (Object_t * __this /* static, unused */, RectTransform_t212748479_0 * ___rect, int32_t ___axis, bool ___keepPositioning, bool ___recursive, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.RectTransformUtility::FlipLayoutAxes(UnityEngine.RectTransform,System.Boolean,System.Boolean)
extern "C"  void RectTransformUtility_FlipLayoutAxes_m_2131476694_0 (Object_t * __this /* static, unused */, RectTransform_t212748479_0 * ___rect, bool ___keepPositioning, bool ___recursive, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.RectTransformUtility::GetTransposed(UnityEngine.Vector2)
extern "C"  Vector2_t_725341338_0  RectTransformUtility_GetTransposed_m2060823533_0 (Object_t * __this /* static, unused */, Vector2_t_725341338_0  ___input, const MethodInfo* method) IL2CPP_METHOD_ATTR;
