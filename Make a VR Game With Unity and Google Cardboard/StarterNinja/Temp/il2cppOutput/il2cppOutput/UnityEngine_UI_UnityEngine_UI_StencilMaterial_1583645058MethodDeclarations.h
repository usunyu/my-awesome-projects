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

// UnityEngine.Material
struct Material_t1701708784_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Rendering_StencilOp_1675874990.h"
#include "UnityEngine_UnityEngine_Rendering_CompareFunction2140467378.h"
#include "UnityEngine_UnityEngine_Rendering_ColorWriteMask_1368925229.h"

// System.Void UnityEngine.UI.StencilMaterial::.cctor()
extern "C"  void StencilMaterial__cctor_m_1606106347_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Material UnityEngine.UI.StencilMaterial::Add(UnityEngine.Material,System.Int32)
extern "C"  Material_t1701708784_0 * StencilMaterial_Add_m1399519863_0 (Object_t * __this /* static, unused */, Material_t1701708784_0 * ___baseMat, int32_t ___stencilID, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Material UnityEngine.UI.StencilMaterial::Add(UnityEngine.Material,System.Int32,UnityEngine.Rendering.StencilOp,UnityEngine.Rendering.CompareFunction,UnityEngine.Rendering.ColorWriteMask)
extern "C"  Material_t1701708784_0 * StencilMaterial_Add_m310944030_0 (Object_t * __this /* static, unused */, Material_t1701708784_0 * ___baseMat, int32_t ___stencilID, int32_t ___operation, int32_t ___compareFunction, int32_t ___colorWriteMask, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Material UnityEngine.UI.StencilMaterial::Add(UnityEngine.Material,System.Int32,UnityEngine.Rendering.StencilOp,UnityEngine.Rendering.CompareFunction,UnityEngine.Rendering.ColorWriteMask,System.Int32,System.Int32)
extern "C"  Material_t1701708784_0 * StencilMaterial_Add_m264449278_0 (Object_t * __this /* static, unused */, Material_t1701708784_0 * ___baseMat, int32_t ___stencilID, int32_t ___operation, int32_t ___compareFunction, int32_t ___colorWriteMask, int32_t ___readMask, int32_t ___writeMask, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.StencilMaterial::Remove(UnityEngine.Material)
extern "C"  void StencilMaterial_Remove_m1013236306_0 (Object_t * __this /* static, unused */, Material_t1701708784_0 * ___customMat, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.StencilMaterial::ClearAll()
extern "C"  void StencilMaterial_ClearAll_m_943298496_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
