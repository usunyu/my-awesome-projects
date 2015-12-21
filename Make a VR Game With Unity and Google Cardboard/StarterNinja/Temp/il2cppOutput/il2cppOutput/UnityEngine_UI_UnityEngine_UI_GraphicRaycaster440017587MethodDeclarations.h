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

// UnityEngine.UI.GraphicRaycaster
struct GraphicRaycaster_t440017587_0;
// UnityEngine.Canvas
struct Canvas_t814756449_0;
// UnityEngine.EventSystems.PointerEventData
struct PointerEventData_t_1258954026_0;
// System.Collections.Generic.List`1<UnityEngine.EventSystems.RaycastResult>
struct List_1_t1613808521_0;
// UnityEngine.Camera
struct Camera_t814710830_0;
// System.Collections.Generic.List`1<UnityEngine.UI.Graphic>
struct List_1_t_1261145411_0;
// UnityEngine.UI.Graphic
struct Graphic_t141164899_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UI_UnityEngine_UI_GraphicRaycaster_Bl_1913877597.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"

// System.Void UnityEngine.UI.GraphicRaycaster::.ctor()
extern "C"  void GraphicRaycaster__ctor_m361051581_0 (GraphicRaycaster_t440017587_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.GraphicRaycaster::.cctor()
extern "C"  void GraphicRaycaster__cctor_m2120568208_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.UI.GraphicRaycaster::get_sortOrderPriority()
extern "C"  int32_t GraphicRaycaster_get_sortOrderPriority_m_1468209522_0 (GraphicRaycaster_t440017587_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.UI.GraphicRaycaster::get_renderOrderPriority()
extern "C"  int32_t GraphicRaycaster_get_renderOrderPriority_m_161222314_0 (GraphicRaycaster_t440017587_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.GraphicRaycaster::get_ignoreReversedGraphics()
extern "C"  bool GraphicRaycaster_get_ignoreReversedGraphics_m_222163679_0 (GraphicRaycaster_t440017587_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.GraphicRaycaster::set_ignoreReversedGraphics(System.Boolean)
extern "C"  void GraphicRaycaster_set_ignoreReversedGraphics_m1428686170_0 (GraphicRaycaster_t440017587_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.UI.GraphicRaycaster/BlockingObjects UnityEngine.UI.GraphicRaycaster::get_blockingObjects()
extern "C"  int32_t GraphicRaycaster_get_blockingObjects_m_639375901_0 (GraphicRaycaster_t440017587_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.GraphicRaycaster::set_blockingObjects(UnityEngine.UI.GraphicRaycaster/BlockingObjects)
extern "C"  void GraphicRaycaster_set_blockingObjects_m421631540_0 (GraphicRaycaster_t440017587_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Canvas UnityEngine.UI.GraphicRaycaster::get_canvas()
extern "C"  Canvas_t814756449_0 * GraphicRaycaster_get_canvas_m1333156416_0 (GraphicRaycaster_t440017587_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.GraphicRaycaster::Raycast(UnityEngine.EventSystems.PointerEventData,System.Collections.Generic.List`1<UnityEngine.EventSystems.RaycastResult>)
extern "C"  void GraphicRaycaster_Raycast_m1880111711_0 (GraphicRaycaster_t440017587_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, List_1_t1613808521_0 * ___resultAppendList, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Camera UnityEngine.UI.GraphicRaycaster::get_eventCamera()
extern "C"  Camera_t814710830_0 * GraphicRaycaster_get_eventCamera_m_1772412116_0 (GraphicRaycaster_t440017587_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.GraphicRaycaster::Raycast(UnityEngine.Canvas,UnityEngine.Camera,UnityEngine.Vector2,System.Collections.Generic.List`1<UnityEngine.UI.Graphic>)
extern "C"  void GraphicRaycaster_Raycast_m_1103666278_0 (Object_t * __this /* static, unused */, Canvas_t814756449_0 * ___canvas, Camera_t814710830_0 * ___eventCamera, Vector2_t_725341338_0  ___pointerPosition, List_1_t_1261145411_0 * ___results, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.UI.GraphicRaycaster::<Raycast>m__3(UnityEngine.UI.Graphic,UnityEngine.UI.Graphic)
extern "C"  int32_t GraphicRaycaster_U3CRaycastU3Em__3_m_304377812_0 (Object_t * __this /* static, unused */, Graphic_t141164899_0 * ___g1, Graphic_t141164899_0 * ___g2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
