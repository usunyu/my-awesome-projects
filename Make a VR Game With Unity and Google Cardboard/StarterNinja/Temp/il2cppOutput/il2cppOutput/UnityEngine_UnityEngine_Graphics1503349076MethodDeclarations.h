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
// UnityEngine.Texture
struct Texture_t1814018354_0;
// UnityEngine.Material
struct Material_t1701708784_0;
// UnityEngine.RenderTexture
struct RenderTexture_t1203146108_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Vector3_725341337.h"
#include "UnityEngine_UnityEngine_Quaternion1989680039.h"
#include "UnityEngine_UnityEngine_Rect_981940947.h"
#include "UnityEngine_UnityEngine_InternalDrawTextureArgumen1216566917.h"

// System.Void UnityEngine.Graphics::DrawMeshNow(UnityEngine.Mesh,UnityEngine.Vector3,UnityEngine.Quaternion)
extern "C"  void Graphics_DrawMeshNow_m872452541_0 (Object_t * __this /* static, unused */, Mesh_t_982089418_0 * ___mesh, Vector3_t_725341337_0  ___position, Quaternion_t1989680039_0  ___rotation, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::Internal_DrawMeshNow1(UnityEngine.Mesh,UnityEngine.Vector3,UnityEngine.Quaternion,System.Int32)
extern "C"  void Graphics_Internal_DrawMeshNow1_m44339171_0 (Object_t * __this /* static, unused */, Mesh_t_982089418_0 * ___mesh, Vector3_t_725341337_0  ___position, Quaternion_t1989680039_0  ___rotation, int32_t ___materialIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::INTERNAL_CALL_Internal_DrawMeshNow1(UnityEngine.Mesh,UnityEngine.Vector3&,UnityEngine.Quaternion&,System.Int32)
extern "C"  void Graphics_INTERNAL_CALL_Internal_DrawMeshNow1_m_1809040850_0 (Object_t * __this /* static, unused */, Mesh_t_982089418_0 * ___mesh, Vector3_t_725341337_0 * ___position, Quaternion_t1989680039_0 * ___rotation, int32_t ___materialIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::DrawTexture(UnityEngine.Rect,UnityEngine.Texture,UnityEngine.Material)
extern "C"  void Graphics_DrawTexture_m_553364124_0 (Object_t * __this /* static, unused */, Rect_t_981940947_0  ___screenRect, Texture_t1814018354_0 * ___texture, Material_t1701708784_0 * ___mat, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::DrawTexture(UnityEngine.Rect,UnityEngine.Texture,System.Int32,System.Int32,System.Int32,System.Int32,UnityEngine.Material)
extern "C"  void Graphics_DrawTexture_m_1975479132_0 (Object_t * __this /* static, unused */, Rect_t_981940947_0  ___screenRect, Texture_t1814018354_0 * ___texture, int32_t ___leftBorder, int32_t ___rightBorder, int32_t ___topBorder, int32_t ___bottomBorder, Material_t1701708784_0 * ___mat, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::DrawTexture(UnityEngine.Rect,UnityEngine.Texture,UnityEngine.Rect,System.Int32,System.Int32,System.Int32,System.Int32,UnityEngine.Material)
extern "C"  void Graphics_DrawTexture_m_853833663_0 (Object_t * __this /* static, unused */, Rect_t_981940947_0  ___screenRect, Texture_t1814018354_0 * ___texture, Rect_t_981940947_0  ___sourceRect, int32_t ___leftBorder, int32_t ___rightBorder, int32_t ___topBorder, int32_t ___bottomBorder, Material_t1701708784_0 * ___mat, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::DrawTexture(UnityEngine.InternalDrawTextureArguments&)
extern "C"  void Graphics_DrawTexture_m_1356916664_0 (Object_t * __this /* static, unused */, InternalDrawTextureArguments_t1216566917_0 * ___arguments, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::Blit(UnityEngine.Texture,UnityEngine.RenderTexture,UnityEngine.Material)
extern "C"  void Graphics_Blit_m_1599513005_0 (Object_t * __this /* static, unused */, Texture_t1814018354_0 * ___source, RenderTexture_t1203146108_0 * ___dest, Material_t1701708784_0 * ___mat, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::Blit(UnityEngine.Texture,UnityEngine.RenderTexture,UnityEngine.Material,System.Int32)
extern "C"  void Graphics_Blit_m336256356_0 (Object_t * __this /* static, unused */, Texture_t1814018354_0 * ___source, RenderTexture_t1203146108_0 * ___dest, Material_t1701708784_0 * ___mat, int32_t ___pass, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Graphics::Internal_BlitMaterial(UnityEngine.Texture,UnityEngine.RenderTexture,UnityEngine.Material,System.Int32,System.Boolean)
extern "C"  void Graphics_Internal_BlitMaterial_m_1481411488_0 (Object_t * __this /* static, unused */, Texture_t1814018354_0 * ___source, RenderTexture_t1203146108_0 * ___dest, Material_t1701708784_0 * ___mat, int32_t ___pass, bool ___setRT, const MethodInfo* method) IL2CPP_METHOD_ATTR;
