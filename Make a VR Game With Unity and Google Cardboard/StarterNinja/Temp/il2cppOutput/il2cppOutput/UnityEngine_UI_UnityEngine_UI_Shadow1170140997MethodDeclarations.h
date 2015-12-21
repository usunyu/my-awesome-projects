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

// UnityEngine.UI.Shadow
struct Shadow_t1170140997_0;
// System.Collections.Generic.List`1<UnityEngine.UIVertex>
struct List_1_t757324127_0;
// UnityEngine.UI.VertexHelper
struct VertexHelper_t786786519_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Color_388944582.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"
#include "UnityEngine_UnityEngine_Color32_113586919.h"

// System.Void UnityEngine.UI.Shadow::.ctor()
extern "C"  void Shadow__ctor_m_1350317653_0 (Shadow_t1170140997_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Color UnityEngine.UI.Shadow::get_effectColor()
extern "C"  Color_t_388944582_0  Shadow_get_effectColor_m_1340977511_0 (Shadow_t1170140997_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Shadow::set_effectColor(UnityEngine.Color)
extern "C"  void Shadow_set_effectColor_m1407835720_0 (Shadow_t1170140997_0 * __this, Color_t_388944582_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.UI.Shadow::get_effectDistance()
extern "C"  Vector2_t_725341338_0  Shadow_get_effectDistance_m1102454733_0 (Shadow_t1170140997_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Shadow::set_effectDistance(UnityEngine.Vector2)
extern "C"  void Shadow_set_effectDistance_m192801982_0 (Shadow_t1170140997_0 * __this, Vector2_t_725341338_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.Shadow::get_useGraphicAlpha()
extern "C"  bool Shadow_get_useGraphicAlpha_m_607333173_0 (Shadow_t1170140997_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Shadow::set_useGraphicAlpha(System.Boolean)
extern "C"  void Shadow_set_useGraphicAlpha_m_480837824_0 (Shadow_t1170140997_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Shadow::ApplyShadowZeroAlloc(System.Collections.Generic.List`1<UnityEngine.UIVertex>,UnityEngine.Color32,System.Int32,System.Int32,System.Single,System.Single)
extern "C"  void Shadow_ApplyShadowZeroAlloc_m338158484_0 (Shadow_t1170140997_0 * __this, List_1_t757324127_0 * ___verts, Color32_t_113586919_0  ___color, int32_t ___start, int32_t ___end, float ___x, float ___y, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Shadow::ApplyShadow(System.Collections.Generic.List`1<UnityEngine.UIVertex>,UnityEngine.Color32,System.Int32,System.Int32,System.Single,System.Single)
extern "C"  void Shadow_ApplyShadow_m_760963755_0 (Shadow_t1170140997_0 * __this, List_1_t757324127_0 * ___verts, Color32_t_113586919_0  ___color, int32_t ___start, int32_t ___end, float ___x, float ___y, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Shadow::ModifyMesh(UnityEngine.UI.VertexHelper)
extern "C"  void Shadow_ModifyMesh_m111179421_0 (Shadow_t1170140997_0 * __this, VertexHelper_t786786519_0 * ___vh, const MethodInfo* method) IL2CPP_METHOD_ATTR;
