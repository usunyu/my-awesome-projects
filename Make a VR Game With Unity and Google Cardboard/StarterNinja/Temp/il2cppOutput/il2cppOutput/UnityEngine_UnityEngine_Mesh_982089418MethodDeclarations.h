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

// UnityEngine.Mesh
struct Mesh_t_982089418_0;
// UnityEngine.Vector3[]
struct Vector3U5BU5D_t_1268319991_0;
// System.Collections.Generic.List`1<UnityEngine.Vector3>
struct List_1_t_429089675_0;
// System.Object
struct Object_t;
// UnityEngine.Vector4[]
struct Vector4U5BU5D_t_1268319030_0;
// System.Collections.Generic.List`1<UnityEngine.Vector4>
struct List_1_t_429089644_0;
// UnityEngine.Vector2[]
struct Vector2U5BU5D_t_1268320952_0;
// System.Array
struct Array_t;
// System.Collections.Generic.List`1<UnityEngine.Vector2>
struct List_1_t_429089706_0;
// UnityEngine.Color[]
struct ColorU5BU5D_t_113585636_0;
// UnityEngine.Color32[]
struct Color32U5BU5D_t_1782843845_0;
// System.Collections.Generic.List`1<UnityEngine.Color32>
struct List_1_t1355428099_0;
// System.Int32[]
struct Int32U5BU5D_t1872284309_0;
// System.Collections.Generic.List`1<System.Int32>
struct List_1_t_1321712961_0;

#include "codegen/il2cpp-codegen.h"

// System.Void UnityEngine.Mesh::.ctor()
extern "C"  void Mesh__ctor_m_1610763488_0 (Mesh_t_982089418_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::Internal_Create(UnityEngine.Mesh)
extern "C"  void Mesh_Internal_Create_m_545236936_0 (Object_t * __this /* static, unused */, Mesh_t_982089418_0 * ___mono, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::Clear(System.Boolean)
extern "C"  void Mesh_Clear_m1789068674_0 (Mesh_t_982089418_0 * __this, bool ___keepVertexLayout, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::Clear()
extern "C"  void Mesh_Clear_m90337099_0 (Mesh_t_982089418_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector3[] UnityEngine.Mesh::get_vertices()
extern "C"  Vector3U5BU5D_t_1268319991_0* Mesh_get_vertices_m_609481122_0 (Mesh_t_982089418_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::set_vertices(UnityEngine.Vector3[])
extern "C"  void Mesh_set_vertices_m_1666101187_0 (Mesh_t_982089418_0 * __this, Vector3U5BU5D_t_1268319991_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::SetVertices(System.Collections.Generic.List`1<UnityEngine.Vector3>)
extern "C"  void Mesh_SetVertices_m701834806_0 (Mesh_t_982089418_0 * __this, List_1_t_429089675_0 * ___inVertices, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::SetVerticesInternal(System.Object)
extern "C"  void Mesh_SetVerticesInternal_m1274639230_0 (Mesh_t_982089418_0 * __this, Object_t * ___vertices, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector3[] UnityEngine.Mesh::get_normals()
extern "C"  Vector3U5BU5D_t_1268319991_0* Mesh_get_normals_m_898057655_0 (Mesh_t_982089418_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::SetNormals(System.Collections.Generic.List`1<UnityEngine.Vector3>)
extern "C"  void Mesh_SetNormals_m2039144779_0 (Mesh_t_982089418_0 * __this, List_1_t_429089675_0 * ___inNormals, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::SetNormalsInternal(System.Object)
extern "C"  void Mesh_SetNormalsInternal_m1710845385_0 (Mesh_t_982089418_0 * __this, Object_t * ___normals, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector4[] UnityEngine.Mesh::get_tangents()
extern "C"  Vector4U5BU5D_t_1268319030_0* Mesh_get_tangents_m_1059101614_0 (Mesh_t_982089418_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::SetTangents(System.Collections.Generic.List`1<UnityEngine.Vector4>)
extern "C"  void Mesh_SetTangents_m2005345740_0 (Mesh_t_982089418_0 * __this, List_1_t_429089644_0 * ___inTangents, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::SetTangentsInternal(System.Object)
extern "C"  void Mesh_SetTangentsInternal_m763303177_0 (Mesh_t_982089418_0 * __this, Object_t * ___tangents, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2[] UnityEngine.Mesh::get_uv()
extern "C"  Vector2U5BU5D_t_1268320952_0* Mesh_get_uv_m558008935_0 (Mesh_t_982089418_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::set_uv(UnityEngine.Vector2[])
extern "C"  void Mesh_set_uv_m498907190_0 (Mesh_t_982089418_0 * __this, Vector2U5BU5D_t_1268320952_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2[] UnityEngine.Mesh::get_uv2()
extern "C"  Vector2U5BU5D_t_1268320952_0* Mesh_get_uv2_m118417421_0 (Mesh_t_982089418_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Array UnityEngine.Mesh::ExtractListData(System.Object)
extern "C"  Array_t * Mesh_ExtractListData_m_1841406398_0 (Object_t * __this /* static, unused */, Object_t * ___list, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::SetUVsInternal(System.Array,System.Int32,System.Int32,System.Int32)
extern "C"  void Mesh_SetUVsInternal_m_280345120_0 (Mesh_t_982089418_0 * __this, Array_t * ___uvs, int32_t ___channel, int32_t ___dim, int32_t ___arraySize, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::SetUVs(System.Int32,System.Collections.Generic.List`1<UnityEngine.Vector2>)
extern "C"  void Mesh_SetUVs_m116216925_0 (Mesh_t_982089418_0 * __this, int32_t ___channel, List_1_t_429089706_0 * ___uvs, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::set_colors(UnityEngine.Color[])
extern "C"  void Mesh_set_colors_m1701609395_0 (Mesh_t_982089418_0 * __this, ColorU5BU5D_t_113585636_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Color32[] UnityEngine.Mesh::get_colors32()
extern "C"  Color32U5BU5D_t_1782843845_0* Mesh_get_colors32_m192356802_0 (Mesh_t_982089418_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::SetColors(System.Collections.Generic.List`1<UnityEngine.Color32>)
extern "C"  void Mesh_SetColors_m_981259361_0 (Mesh_t_982089418_0 * __this, List_1_t1355428099_0 * ___inColors, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::SetColors32Internal(System.Object)
extern "C"  void Mesh_SetColors32Internal_m1830241000_0 (Mesh_t_982089418_0 * __this, Object_t * ___colors, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::RecalculateBounds()
extern "C"  void Mesh_RecalculateBounds_m_540630554_0 (Mesh_t_982089418_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::Optimize()
extern "C"  void Mesh_Optimize_m386784321_0 (Mesh_t_982089418_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::set_triangles(System.Int32[])
extern "C"  void Mesh_set_triangles_m_1953627429_0 (Mesh_t_982089418_0 * __this, Int32U5BU5D_t1872284309_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::SetTriangles(System.Collections.Generic.List`1<System.Int32>,System.Int32)
extern "C"  void Mesh_SetTriangles_m456382467_0 (Mesh_t_982089418_0 * __this, List_1_t_1321712961_0 * ___inTriangles, int32_t ___submesh, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::SetTrianglesInternal(System.Object,System.Int32)
extern "C"  void Mesh_SetTrianglesInternal_m_1339192083_0 (Mesh_t_982089418_0 * __this, Object_t * ___triangles, int32_t ___submesh, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32[] UnityEngine.Mesh::GetIndices(System.Int32)
extern "C"  Int32U5BU5D_t1872284309_0* Mesh_GetIndices_m637494532_0 (Mesh_t_982089418_0 * __this, int32_t ___submesh, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Mesh::UploadMeshData(System.Boolean)
extern "C"  void Mesh_UploadMeshData_m_779359949_0 (Mesh_t_982089418_0 * __this, bool ___markNoLogerReadable, const MethodInfo* method) IL2CPP_METHOD_ATTR;
