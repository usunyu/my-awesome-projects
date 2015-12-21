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

// UnityEngine.CanvasRenderer
struct CanvasRenderer_t310896196_0;
// UnityEngine.Material
struct Material_t1701708784_0;
// UnityEngine.Texture
struct Texture_t1814018354_0;
// UnityEngine.Mesh
struct Mesh_t_982089418_0;
// System.Collections.Generic.List`1<UnityEngine.UIVertex>
struct List_1_t757324127_0;
// System.Collections.Generic.List`1<UnityEngine.Vector3>
struct List_1_t_429089675_0;
// System.Collections.Generic.List`1<UnityEngine.Color32>
struct List_1_t1355428099_0;
// System.Collections.Generic.List`1<UnityEngine.Vector2>
struct List_1_t_429089706_0;
// System.Collections.Generic.List`1<UnityEngine.Vector4>
struct List_1_t_429089644_0;
// System.Collections.Generic.List`1<System.Int32>
struct List_1_t_1321712961_0;
// System.Object
struct Object_t;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Color_388944582.h"
#include "UnityEngine_UnityEngine_Rect_981940947.h"

// System.Void UnityEngine.CanvasRenderer::SetColor(UnityEngine.Color)
extern "C"  void CanvasRenderer_SetColor_m_1096888781_0 (CanvasRenderer_t310896196_0 * __this, Color_t_388944582_0  ___color, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CanvasRenderer::INTERNAL_CALL_SetColor(UnityEngine.CanvasRenderer,UnityEngine.Color&)
extern "C"  void CanvasRenderer_INTERNAL_CALL_SetColor_m_1387820532_0 (Object_t * __this /* static, unused */, CanvasRenderer_t310896196_0 * ___self, Color_t_388944582_0 * ___color, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Color UnityEngine.CanvasRenderer::GetColor()
extern "C"  Color_t_388944582_0  CanvasRenderer_GetColor_m_1219573594_0 (CanvasRenderer_t310896196_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CanvasRenderer::INTERNAL_CALL_GetColor(UnityEngine.CanvasRenderer,UnityEngine.Color&)
extern "C"  void CanvasRenderer_INTERNAL_CALL_GetColor_m_1118598400_0 (Object_t * __this /* static, unused */, CanvasRenderer_t310896196_0 * ___self, Color_t_388944582_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CanvasRenderer::EnableRectClipping(UnityEngine.Rect)
extern "C"  void CanvasRenderer_EnableRectClipping_m896218272_0 (CanvasRenderer_t310896196_0 * __this, Rect_t_981940947_0  ___rect, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CanvasRenderer::INTERNAL_CALL_EnableRectClipping(UnityEngine.CanvasRenderer,UnityEngine.Rect&)
extern "C"  void CanvasRenderer_INTERNAL_CALL_EnableRectClipping_m105013257_0 (Object_t * __this /* static, unused */, CanvasRenderer_t310896196_0 * ___self, Rect_t_981940947_0 * ___rect, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CanvasRenderer::DisableRectClipping()
extern "C"  void CanvasRenderer_DisableRectClipping_m_1640579266_0 (CanvasRenderer_t310896196_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CanvasRenderer::set_hasPopInstruction(System.Boolean)
extern "C"  void CanvasRenderer_set_hasPopInstruction_m2112255713_0 (CanvasRenderer_t310896196_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.CanvasRenderer::get_materialCount()
extern "C"  int32_t CanvasRenderer_get_materialCount_m311942031_0 (CanvasRenderer_t310896196_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CanvasRenderer::set_materialCount(System.Int32)
extern "C"  void CanvasRenderer_set_materialCount_m1694897644_0 (CanvasRenderer_t310896196_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CanvasRenderer::SetMaterial(UnityEngine.Material,System.Int32)
extern "C"  void CanvasRenderer_SetMaterial_m355382012_0 (CanvasRenderer_t310896196_0 * __this, Material_t1701708784_0 * ___material, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CanvasRenderer::SetMaterial(UnityEngine.Material,UnityEngine.Texture)
extern "C"  void CanvasRenderer_SetMaterial_m1603188579_0 (CanvasRenderer_t310896196_0 * __this, Material_t1701708784_0 * ___material, Texture_t1814018354_0 * ___texture, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CanvasRenderer::set_popMaterialCount(System.Int32)
extern "C"  void CanvasRenderer_set_popMaterialCount_m589784503_0 (CanvasRenderer_t310896196_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CanvasRenderer::SetPopMaterial(UnityEngine.Material,System.Int32)
extern "C"  void CanvasRenderer_SetPopMaterial_m1315408685_0 (CanvasRenderer_t310896196_0 * __this, Material_t1701708784_0 * ___material, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CanvasRenderer::SetTexture(UnityEngine.Texture)
extern "C"  void CanvasRenderer_SetTexture_m137327939_0 (CanvasRenderer_t310896196_0 * __this, Texture_t1814018354_0 * ___texture, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CanvasRenderer::SetMesh(UnityEngine.Mesh)
extern "C"  void CanvasRenderer_SetMesh_m1150548475_0 (CanvasRenderer_t310896196_0 * __this, Mesh_t_982089418_0 * ___mesh, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CanvasRenderer::Clear()
extern "C"  void CanvasRenderer_Clear_m1606508093_0 (CanvasRenderer_t310896196_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CanvasRenderer::SplitUIVertexStreams(System.Collections.Generic.List`1<UnityEngine.UIVertex>,System.Collections.Generic.List`1<UnityEngine.Vector3>,System.Collections.Generic.List`1<UnityEngine.Color32>,System.Collections.Generic.List`1<UnityEngine.Vector2>,System.Collections.Generic.List`1<UnityEngine.Vector2>,System.Collections.Generic.List`1<UnityEngine.Vector3>,System.Collections.Generic.List`1<UnityEngine.Vector4>,System.Collections.Generic.List`1<System.Int32>)
extern "C"  void CanvasRenderer_SplitUIVertexStreams_m_168873380_0 (Object_t * __this /* static, unused */, List_1_t757324127_0 * ___verts, List_1_t_429089675_0 * ___positions, List_1_t1355428099_0 * ___colors, List_1_t_429089706_0 * ___uv0S, List_1_t_429089706_0 * ___uv1S, List_1_t_429089675_0 * ___normals, List_1_t_429089644_0 * ___tangents, List_1_t_1321712961_0 * ___indicies, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CanvasRenderer::SplitUIVertexStreamsInternal(System.Object,System.Object,System.Object,System.Object,System.Object,System.Object,System.Object)
extern "C"  void CanvasRenderer_SplitUIVertexStreamsInternal_m987675768_0 (Object_t * __this /* static, unused */, Object_t * ___verts, Object_t * ___positions, Object_t * ___colors, Object_t * ___uv0S, Object_t * ___uv1S, Object_t * ___normals, Object_t * ___tangents, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CanvasRenderer::SplitIndiciesStreamsInternal(System.Object,System.Object)
extern "C"  void CanvasRenderer_SplitIndiciesStreamsInternal_m269466040_0 (Object_t * __this /* static, unused */, Object_t * ___verts, Object_t * ___indicies, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CanvasRenderer::CreateUIVertexStream(System.Collections.Generic.List`1<UnityEngine.UIVertex>,System.Collections.Generic.List`1<UnityEngine.Vector3>,System.Collections.Generic.List`1<UnityEngine.Color32>,System.Collections.Generic.List`1<UnityEngine.Vector2>,System.Collections.Generic.List`1<UnityEngine.Vector2>,System.Collections.Generic.List`1<UnityEngine.Vector3>,System.Collections.Generic.List`1<UnityEngine.Vector4>,System.Collections.Generic.List`1<System.Int32>)
extern "C"  void CanvasRenderer_CreateUIVertexStream_m_1592611159_0 (Object_t * __this /* static, unused */, List_1_t757324127_0 * ___verts, List_1_t_429089675_0 * ___positions, List_1_t1355428099_0 * ___colors, List_1_t_429089706_0 * ___uv0S, List_1_t_429089706_0 * ___uv1S, List_1_t_429089675_0 * ___normals, List_1_t_429089644_0 * ___tangents, List_1_t_1321712961_0 * ___indicies, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CanvasRenderer::CreateUIVertexStreamInternal(System.Object,System.Object,System.Object,System.Object,System.Object,System.Object,System.Object,System.Object)
extern "C"  void CanvasRenderer_CreateUIVertexStreamInternal_m997370835_0 (Object_t * __this /* static, unused */, Object_t * ___verts, Object_t * ___positions, Object_t * ___colors, Object_t * ___uv0S, Object_t * ___uv1S, Object_t * ___normals, Object_t * ___tangents, Object_t * ___indicies, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CanvasRenderer::AddUIVertexStream(System.Collections.Generic.List`1<UnityEngine.UIVertex>,System.Collections.Generic.List`1<UnityEngine.Vector3>,System.Collections.Generic.List`1<UnityEngine.Color32>,System.Collections.Generic.List`1<UnityEngine.Vector2>,System.Collections.Generic.List`1<UnityEngine.Vector2>,System.Collections.Generic.List`1<UnityEngine.Vector3>,System.Collections.Generic.List`1<UnityEngine.Vector4>)
extern "C"  void CanvasRenderer_AddUIVertexStream_m1865056747_0 (Object_t * __this /* static, unused */, List_1_t757324127_0 * ___verts, List_1_t_429089675_0 * ___positions, List_1_t1355428099_0 * ___colors, List_1_t_429089706_0 * ___uv0S, List_1_t_429089706_0 * ___uv1S, List_1_t_429089675_0 * ___normals, List_1_t_429089644_0 * ___tangents, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.CanvasRenderer::get_cull()
extern "C"  bool CanvasRenderer_get_cull_m_951111501_0 (CanvasRenderer_t310896196_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CanvasRenderer::set_cull(System.Boolean)
extern "C"  void CanvasRenderer_set_cull_m_861015176_0 (CanvasRenderer_t310896196_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.CanvasRenderer::get_absoluteDepth()
extern "C"  int32_t CanvasRenderer_get_absoluteDepth_m1613567475_0 (CanvasRenderer_t310896196_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.CanvasRenderer::get_hasMoved()
extern "C"  bool CanvasRenderer_get_hasMoved_m1392755130_0 (CanvasRenderer_t310896196_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
