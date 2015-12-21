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

// UnityEngine.UI.GraphicRegistry
struct GraphicRegistry_t1946583744_0;
// UnityEngine.Canvas
struct Canvas_t814756449_0;
// UnityEngine.UI.Graphic
struct Graphic_t141164899_0;
// System.Collections.Generic.IList`1<UnityEngine.UI.Graphic>
struct IList_1_t385558724_0;

#include "codegen/il2cpp-codegen.h"

// System.Void UnityEngine.UI.GraphicRegistry::.ctor()
extern "C"  void GraphicRegistry__ctor_m_1284038250_0 (GraphicRegistry_t1946583744_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.GraphicRegistry::.cctor()
extern "C"  void GraphicRegistry__cctor_m_1632576297_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.UI.GraphicRegistry UnityEngine.UI.GraphicRegistry::get_instance()
extern "C"  GraphicRegistry_t1946583744_0 * GraphicRegistry_get_instance_m_1989025119_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.GraphicRegistry::RegisterGraphicForCanvas(UnityEngine.Canvas,UnityEngine.UI.Graphic)
extern "C"  void GraphicRegistry_RegisterGraphicForCanvas_m977086278_0 (Object_t * __this /* static, unused */, Canvas_t814756449_0 * ___c, Graphic_t141164899_0 * ___graphic, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.GraphicRegistry::UnregisterGraphicForCanvas(UnityEngine.Canvas,UnityEngine.UI.Graphic)
extern "C"  void GraphicRegistry_UnregisterGraphicForCanvas_m707013965_0 (Object_t * __this /* static, unused */, Canvas_t814756449_0 * ___c, Graphic_t141164899_0 * ___graphic, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.Generic.IList`1<UnityEngine.UI.Graphic> UnityEngine.UI.GraphicRegistry::GetGraphicsForCanvas(UnityEngine.Canvas)
extern "C"  Object_t* GraphicRegistry_GetGraphicsForCanvas_m_1554938384_0 (Object_t * __this /* static, unused */, Canvas_t814756449_0 * ___canvas, const MethodInfo* method) IL2CPP_METHOD_ATTR;
