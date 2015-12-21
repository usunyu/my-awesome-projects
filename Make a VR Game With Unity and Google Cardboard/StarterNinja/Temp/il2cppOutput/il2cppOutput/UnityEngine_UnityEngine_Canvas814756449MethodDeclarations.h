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

// UnityEngine.Canvas/WillRenderCanvases
struct WillRenderCanvases_t_861268292_0;
// UnityEngine.Canvas
struct Canvas_t814756449_0;
// UnityEngine.Camera
struct Camera_t814710830_0;
// UnityEngine.Material
struct Material_t1701708784_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_RenderMode513230050.h"

// System.Void UnityEngine.Canvas::add_willRenderCanvases(UnityEngine.Canvas/WillRenderCanvases)
extern "C"  void Canvas_add_willRenderCanvases_m716439881_0 (Object_t * __this /* static, unused */, WillRenderCanvases_t_861268292_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Canvas::remove_willRenderCanvases(UnityEngine.Canvas/WillRenderCanvases)
extern "C"  void Canvas_remove_willRenderCanvases_m158291336_0 (Object_t * __this /* static, unused */, WillRenderCanvases_t_861268292_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.RenderMode UnityEngine.Canvas::get_renderMode()
extern "C"  int32_t Canvas_get_renderMode_m_625846096_0 (Canvas_t814756449_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Canvas::get_isRootCanvas()
extern "C"  bool Canvas_get_isRootCanvas_m_264334590_0 (Canvas_t814756449_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Camera UnityEngine.Canvas::get_worldCamera()
extern "C"  Camera_t814710830_0 * Canvas_get_worldCamera_m_1673518066_0 (Canvas_t814756449_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.Canvas::get_scaleFactor()
extern "C"  float Canvas_get_scaleFactor_m1187077271_0 (Canvas_t814756449_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Canvas::set_scaleFactor(System.Single)
extern "C"  void Canvas_set_scaleFactor_m_2088530468_0 (Canvas_t814756449_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.Canvas::get_referencePixelsPerUnit()
extern "C"  float Canvas_get_referencePixelsPerUnit_m_535378099_0 (Canvas_t814756449_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Canvas::set_referencePixelsPerUnit(System.Single)
extern "C"  void Canvas_set_referencePixelsPerUnit_m1910706966_0 (Canvas_t814756449_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Canvas::get_pixelPerfect()
extern "C"  bool Canvas_get_pixelPerfect_m_1446972603_0 (Canvas_t814756449_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.Canvas::get_renderOrder()
extern "C"  int32_t Canvas_get_renderOrder_m_1998997502_0 (Canvas_t814756449_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Canvas::get_overrideSorting()
extern "C"  bool Canvas_get_overrideSorting_m_482082660_0 (Canvas_t814756449_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Canvas::set_overrideSorting(System.Boolean)
extern "C"  void Canvas_set_overrideSorting_m1850487749_0 (Canvas_t814756449_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.Canvas::get_sortingOrder()
extern "C"  int32_t Canvas_get_sortingOrder_m1274160674_0 (Canvas_t814756449_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Canvas::set_sortingOrder(System.Int32)
extern "C"  void Canvas_set_sortingOrder_m1522807655_0 (Canvas_t814756449_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.Canvas::get_targetDisplay()
extern "C"  int32_t Canvas_get_targetDisplay_m_982690277_0 (Canvas_t814756449_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.Canvas::get_sortingLayerID()
extern "C"  int32_t Canvas_get_sortingLayerID_m_869129024_0 (Canvas_t814756449_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Canvas::set_sortingLayerID(System.Int32)
extern "C"  void Canvas_set_sortingLayerID_m_1977464827_0 (Canvas_t814756449_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Material UnityEngine.Canvas::GetDefaultCanvasMaterial()
extern "C"  Material_t1701708784_0 * Canvas_GetDefaultCanvasMaterial_m1655363178_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Canvas::SendWillRenderCanvases()
extern "C"  void Canvas_SendWillRenderCanvases_m1768133093_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Canvas::ForceUpdateCanvases()
extern "C"  void Canvas_ForceUpdateCanvases_m1970133101_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
