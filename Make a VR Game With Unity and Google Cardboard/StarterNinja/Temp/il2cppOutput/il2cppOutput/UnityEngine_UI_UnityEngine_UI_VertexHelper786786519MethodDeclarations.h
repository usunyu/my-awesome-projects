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

// UnityEngine.UI.VertexHelper
struct VertexHelper_t786786519_0;
// UnityEngine.Mesh
struct Mesh_t_982089418_0;
// UnityEngine.UIVertex[]
struct UIVertexU5BU5D_t2006642351_0;
// System.Collections.Generic.List`1<UnityEngine.UIVertex>
struct List_1_t757324127_0;
// System.Collections.Generic.List`1<System.Int32>
struct List_1_t_1321712961_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_UIVertex2075173889.h"
#include "UnityEngine_UnityEngine_Vector3_725341337.h"
#include "UnityEngine_UnityEngine_Color32_113586919.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"
#include "UnityEngine_UnityEngine_Vector4_725341336.h"

// System.Void UnityEngine.UI.VertexHelper::.ctor()
extern "C"  void VertexHelper__ctor_m_1288706407_0 (VertexHelper_t786786519_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.VertexHelper::.ctor(UnityEngine.Mesh)
extern "C"  void VertexHelper__ctor_m_54800523_0 (VertexHelper_t786786519_0 * __this, Mesh_t_982089418_0 * ___m, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.VertexHelper::.cctor()
extern "C"  void VertexHelper__cctor_m_1777289164_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.VertexHelper::Clear()
extern "C"  void VertexHelper_Clear_m412394180_0 (VertexHelper_t786786519_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.UI.VertexHelper::get_currentVertCount()
extern "C"  int32_t VertexHelper_get_currentVertCount_m_869636943_0 (VertexHelper_t786786519_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.UI.VertexHelper::get_currentIndexCount()
extern "C"  int32_t VertexHelper_get_currentIndexCount_m_447712628_0 (VertexHelper_t786786519_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.VertexHelper::PopulateUIVertex(UnityEngine.UIVertex&,System.Int32)
extern "C"  void VertexHelper_PopulateUIVertex_m910319817_0 (VertexHelper_t786786519_0 * __this, UIVertex_t2075173889_0 * ___vertex, int32_t ___i, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.VertexHelper::SetUIVertex(UnityEngine.UIVertex,System.Int32)
extern "C"  void VertexHelper_SetUIVertex_m_865484491_0 (VertexHelper_t786786519_0 * __this, UIVertex_t2075173889_0  ___vertex, int32_t ___i, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.VertexHelper::FillMesh(UnityEngine.Mesh)
extern "C"  void VertexHelper_FillMesh_m_1923866249_0 (VertexHelper_t786786519_0 * __this, Mesh_t_982089418_0 * ___mesh, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.VertexHelper::Dispose()
extern "C"  void VertexHelper_Dispose_m_1597992810_0 (VertexHelper_t786786519_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.VertexHelper::AddVert(UnityEngine.Vector3,UnityEngine.Color32,UnityEngine.Vector2,UnityEngine.Vector2,UnityEngine.Vector3,UnityEngine.Vector4)
extern "C"  void VertexHelper_AddVert_m1784639198_0 (VertexHelper_t786786519_0 * __this, Vector3_t_725341337_0  ___position, Color32_t_113586919_0  ___color, Vector2_t_725341338_0  ___uv0, Vector2_t_725341338_0  ___uv1, Vector3_t_725341337_0  ___normal, Vector4_t_725341336_0  ___tangent, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.VertexHelper::AddVert(UnityEngine.Vector3,UnityEngine.Color32,UnityEngine.Vector2)
extern "C"  void VertexHelper_AddVert_m1490065189_0 (VertexHelper_t786786519_0 * __this, Vector3_t_725341337_0  ___position, Color32_t_113586919_0  ___color, Vector2_t_725341338_0  ___uv0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.VertexHelper::AddVert(UnityEngine.UIVertex)
extern "C"  void VertexHelper_AddVert_m1127238042_0 (VertexHelper_t786786519_0 * __this, UIVertex_t2075173889_0  ___v, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.VertexHelper::AddTriangle(System.Int32,System.Int32,System.Int32)
extern "C"  void VertexHelper_AddTriangle_m514578993_0 (VertexHelper_t786786519_0 * __this, int32_t ___idx0, int32_t ___idx1, int32_t ___idx2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.VertexHelper::AddUIVertexQuad(UnityEngine.UIVertex[])
extern "C"  void VertexHelper_AddUIVertexQuad_m765809318_0 (VertexHelper_t786786519_0 * __this, UIVertexU5BU5D_t2006642351_0* ___verts, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.VertexHelper::AddUIVertexStream(System.Collections.Generic.List`1<UnityEngine.UIVertex>,System.Collections.Generic.List`1<System.Int32>)
extern "C"  void VertexHelper_AddUIVertexStream_m1704624332_0 (VertexHelper_t786786519_0 * __this, List_1_t757324127_0 * ___verts, List_1_t_1321712961_0 * ___indices, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.VertexHelper::AddUIVertexTriangleStream(System.Collections.Generic.List`1<UnityEngine.UIVertex>)
extern "C"  void VertexHelper_AddUIVertexTriangleStream_m1263262953_0 (VertexHelper_t786786519_0 * __this, List_1_t757324127_0 * ___verts, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.VertexHelper::GetUIVertexStream(System.Collections.Generic.List`1<UnityEngine.UIVertex>)
extern "C"  void VertexHelper_GetUIVertexStream_m1078623420_0 (VertexHelper_t786786519_0 * __this, List_1_t757324127_0 * ___stream, const MethodInfo* method) IL2CPP_METHOD_ATTR;
