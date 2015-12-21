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

// UnityEngine.Shader
struct Shader_t1278883054_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Color_388944582.h"
#include "UnityEngine_UnityEngine_Vector4_725341336.h"
#include "UnityEngine_UnityEngine_Matrix4x41577636070.h"

// UnityEngine.Shader UnityEngine.Shader::Find(System.String)
extern "C"  Shader_t1278883054_0 * Shader_Find_m_246919718_0 (Object_t * __this /* static, unused */, String_t* ___name, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Shader::SetGlobalColor(System.String,UnityEngine.Color)
extern "C"  void Shader_SetGlobalColor_m1669397640_0 (Object_t * __this /* static, unused */, String_t* ___propertyName, Color_t_388944582_0  ___color, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Shader::SetGlobalColor(System.Int32,UnityEngine.Color)
extern "C"  void Shader_SetGlobalColor_m1709492491_0 (Object_t * __this /* static, unused */, int32_t ___nameID, Color_t_388944582_0  ___color, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Shader::INTERNAL_CALL_SetGlobalColor(System.Int32,UnityEngine.Color&)
extern "C"  void Shader_INTERNAL_CALL_SetGlobalColor_m1549785026_0 (Object_t * __this /* static, unused */, int32_t ___nameID, Color_t_388944582_0 * ___color, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Shader::SetGlobalVector(System.String,UnityEngine.Vector4)
extern "C"  void Shader_SetGlobalVector_m1990013606_0 (Object_t * __this /* static, unused */, String_t* ___propertyName, Vector4_t_725341336_0  ___vec, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Shader::SetGlobalFloat(System.String,System.Single)
extern "C"  void Shader_SetGlobalFloat_m_1509347148_0 (Object_t * __this /* static, unused */, String_t* ___propertyName, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Shader::SetGlobalFloat(System.Int32,System.Single)
extern "C"  void Shader_SetGlobalFloat_m_741495159_0 (Object_t * __this /* static, unused */, int32_t ___nameID, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Shader::SetGlobalMatrix(System.String,UnityEngine.Matrix4x4)
extern "C"  void Shader_SetGlobalMatrix_m_601638934_0 (Object_t * __this /* static, unused */, String_t* ___propertyName, Matrix4x4_t1577636070_0  ___mat, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Shader::SetGlobalMatrix(System.Int32,UnityEngine.Matrix4x4)
extern "C"  void Shader_SetGlobalMatrix_m_169929455_0 (Object_t * __this /* static, unused */, int32_t ___nameID, Matrix4x4_t1577636070_0  ___mat, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Shader::INTERNAL_CALL_SetGlobalMatrix(System.Int32,UnityEngine.Matrix4x4&)
extern "C"  void Shader_INTERNAL_CALL_SetGlobalMatrix_m1567336922_0 (Object_t * __this /* static, unused */, int32_t ___nameID, Matrix4x4_t1577636070_0 * ___mat, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.Shader::PropertyToID(System.String)
extern "C"  int32_t Shader_PropertyToID_m_1275625285_0 (Object_t * __this /* static, unused */, String_t* ___name, const MethodInfo* method) IL2CPP_METHOD_ATTR;
