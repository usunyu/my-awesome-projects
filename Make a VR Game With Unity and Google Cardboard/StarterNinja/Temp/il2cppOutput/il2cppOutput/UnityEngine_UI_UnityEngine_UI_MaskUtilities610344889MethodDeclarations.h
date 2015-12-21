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

// UnityEngine.UI.MaskUtilities
struct MaskUtilities_t610344889_0;
// UnityEngine.Component
struct Component_t_867674284_0;
// UnityEngine.Transform
struct Transform_t1584899523_0;
// UnityEngine.UI.RectMask2D
struct RectMask2D_t_1803147033_0;
// UnityEngine.UI.IClippable
struct IClippable_t_362467914_0;
// System.Collections.Generic.List`1<UnityEngine.UI.RectMask2D>
struct List_1_t_2080217739_0;

#include "codegen/il2cpp-codegen.h"

// System.Void UnityEngine.UI.MaskUtilities::.ctor()
extern "C"  void MaskUtilities__ctor_m1166009725_0 (MaskUtilities_t610344889_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.MaskUtilities::Notify2DMaskStateChanged(UnityEngine.Component)
extern "C"  void MaskUtilities_Notify2DMaskStateChanged_m_2095416741_0 (Object_t * __this /* static, unused */, Component_t_867674284_0 * ___mask, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.MaskUtilities::NotifyStencilStateChanged(UnityEngine.Component)
extern "C"  void MaskUtilities_NotifyStencilStateChanged_m_2135093861_0 (Object_t * __this /* static, unused */, Component_t_867674284_0 * ___mask, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Transform UnityEngine.UI.MaskUtilities::FindRootSortOverrideCanvas(UnityEngine.Transform)
extern "C"  Transform_t1584899523_0 * MaskUtilities_FindRootSortOverrideCanvas_m_75012645_0 (Object_t * __this /* static, unused */, Transform_t1584899523_0 * ___start, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.UI.MaskUtilities::GetStencilDepth(UnityEngine.Transform,UnityEngine.Transform)
extern "C"  int32_t MaskUtilities_GetStencilDepth_m_1508473308_0 (Object_t * __this /* static, unused */, Transform_t1584899523_0 * ___transform, Transform_t1584899523_0 * ___stopAfter, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.UI.RectMask2D UnityEngine.UI.MaskUtilities::GetRectMaskForClippable(UnityEngine.UI.IClippable)
extern "C"  RectMask2D_t_1803147033_0 * MaskUtilities_GetRectMaskForClippable_m396614586_0 (Object_t * __this /* static, unused */, Object_t * ___transform, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.MaskUtilities::GetRectMasksForClip(UnityEngine.UI.RectMask2D,System.Collections.Generic.List`1<UnityEngine.UI.RectMask2D>)
extern "C"  void MaskUtilities_GetRectMasksForClip_m447525417_0 (Object_t * __this /* static, unused */, RectMask2D_t_1803147033_0 * ___clipper, List_1_t_2080217739_0 * ___masks, const MethodInfo* method) IL2CPP_METHOD_ATTR;
