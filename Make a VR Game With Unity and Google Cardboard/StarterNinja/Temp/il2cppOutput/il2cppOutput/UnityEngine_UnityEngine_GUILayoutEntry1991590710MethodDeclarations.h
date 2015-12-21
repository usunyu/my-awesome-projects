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

// UnityEngine.GUILayoutEntry
struct GUILayoutEntry_t1991590710_0;
// UnityEngine.GUIStyle
struct GUIStyle_t822037503_0;
// UnityEngine.RectOffset
struct RectOffset_t_802832352_0;
// UnityEngine.GUILayoutOption[]
struct GUILayoutOptionU5BU5D_t_1479612077_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"

// System.Void UnityEngine.GUILayoutEntry::.ctor(System.Single,System.Single,System.Single,System.Single,UnityEngine.GUIStyle)
extern "C"  void GUILayoutEntry__ctor_m_708886145_0 (GUILayoutEntry_t1991590710_0 * __this, float ____minWidth, float ____maxWidth, float ____minHeight, float ____maxHeight, GUIStyle_t822037503_0 * ____style, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUILayoutEntry::.cctor()
extern "C"  void GUILayoutEntry__cctor_m_187252147_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GUIStyle UnityEngine.GUILayoutEntry::get_style()
extern "C"  GUIStyle_t822037503_0 * GUILayoutEntry_get_style_m_787069308_0 (GUILayoutEntry_t1991590710_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUILayoutEntry::set_style(UnityEngine.GUIStyle)
extern "C"  void GUILayoutEntry_set_style_m706118245_0 (GUILayoutEntry_t1991590710_0 * __this, GUIStyle_t822037503_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.RectOffset UnityEngine.GUILayoutEntry::get_margin()
extern "C"  RectOffset_t_802832352_0 * GUILayoutEntry_get_margin_m_589860260_0 (GUILayoutEntry_t1991590710_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUILayoutEntry::CalcWidth()
extern "C"  void GUILayoutEntry_CalcWidth_m_924799953_0 (GUILayoutEntry_t1991590710_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUILayoutEntry::CalcHeight()
extern "C"  void GUILayoutEntry_CalcHeight_m1899786880_0 (GUILayoutEntry_t1991590710_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUILayoutEntry::SetHorizontal(System.Single,System.Single)
extern "C"  void GUILayoutEntry_SetHorizontal_m_484630356_0 (GUILayoutEntry_t1991590710_0 * __this, float ___x, float ___width, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUILayoutEntry::SetVertical(System.Single,System.Single)
extern "C"  void GUILayoutEntry_SetVertical_m880890586_0 (GUILayoutEntry_t1991590710_0 * __this, float ___y, float ___height, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUILayoutEntry::ApplyStyleSettings(UnityEngine.GUIStyle)
extern "C"  void GUILayoutEntry_ApplyStyleSettings_m937804029_0 (GUILayoutEntry_t1991590710_0 * __this, GUIStyle_t822037503_0 * ___style, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUILayoutEntry::ApplyOptions(UnityEngine.GUILayoutOption[])
extern "C"  void GUILayoutEntry_ApplyOptions_m_1869165831_0 (GUILayoutEntry_t1991590710_0 * __this, GUILayoutOptionU5BU5D_t_1479612077_0* ___options, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.GUILayoutEntry::ToString()
extern "C"  String_t* GUILayoutEntry_ToString_m_273010701_0 (GUILayoutEntry_t1991590710_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
