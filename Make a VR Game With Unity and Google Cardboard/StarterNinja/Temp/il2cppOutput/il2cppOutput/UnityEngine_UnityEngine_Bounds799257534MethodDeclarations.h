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

// System.Object
struct Object_t;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Bounds799257534.h"
#include "UnityEngine_UnityEngine_Vector3_725341337.h"

// System.Void UnityEngine.Bounds::.ctor(UnityEngine.Vector3,UnityEngine.Vector3)
extern "C"  void Bounds__ctor_m_134673644_0 (Bounds_t799257534_0 * __this, Vector3_t_725341337_0  ___center, Vector3_t_725341337_0  ___size, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.Bounds::GetHashCode()
extern "C"  int32_t Bounds_GetHashCode_m_1227578617_0 (Bounds_t799257534_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Bounds::Equals(System.Object)
extern "C"  bool Bounds_Equals_m_1777515357_0 (Bounds_t799257534_0 * __this, Object_t * ___other, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector3 UnityEngine.Bounds::get_center()
extern "C"  Vector3_t_725341337_0  Bounds_get_center_m_210356892_0 (Bounds_t799257534_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Bounds::set_center(UnityEngine.Vector3)
extern "C"  void Bounds_set_center_m_1689323589_0 (Bounds_t799257534_0 * __this, Vector3_t_725341337_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector3 UnityEngine.Bounds::get_size()
extern "C"  Vector3_t_725341337_0  Bounds_get_size_m_628618864_0 (Bounds_t799257534_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Bounds::set_size(UnityEngine.Vector3)
extern "C"  void Bounds_set_size_m_185158257_0 (Bounds_t799257534_0 * __this, Vector3_t_725341337_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector3 UnityEngine.Bounds::get_extents()
extern "C"  Vector3_t_725341337_0  Bounds_get_extents_m2111648188_0 (Bounds_t799257534_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Bounds::set_extents(UnityEngine.Vector3)
extern "C"  void Bounds_set_extents_m_1691130473_0 (Bounds_t799257534_0 * __this, Vector3_t_725341337_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector3 UnityEngine.Bounds::get_min()
extern "C"  Vector3_t_725341337_0  Bounds_get_min_m_1965495227_0 (Bounds_t799257534_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector3 UnityEngine.Bounds::get_max()
extern "C"  Vector3_t_725341337_0  Bounds_get_max_m_1965723945_0 (Bounds_t799257534_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Bounds::SetMinMax(UnityEngine.Vector3,UnityEngine.Vector3)
extern "C"  void Bounds_SetMinMax_m_2108946302_0 (Bounds_t799257534_0 * __this, Vector3_t_725341337_0  ___min, Vector3_t_725341337_0  ___max, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Bounds::Encapsulate(UnityEngine.Vector3)
extern "C"  void Bounds_Encapsulate_m_670282062_0 (Bounds_t799257534_0 * __this, Vector3_t_725341337_0  ___point, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.Bounds::ToString()
extern "C"  String_t* Bounds_ToString_m1795228795_0 (Bounds_t799257534_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Bounds::op_Equality(UnityEngine.Bounds,UnityEngine.Bounds)
extern "C"  bool Bounds_op_Equality_m_1439000674_0 (Object_t * __this /* static, unused */, Bounds_t799257534_0  ___lhs, Bounds_t799257534_0  ___rhs, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Bounds::op_Inequality(UnityEngine.Bounds,UnityEngine.Bounds)
extern "C"  bool Bounds_op_Inequality_m_2674919_0 (Object_t * __this /* static, unused */, Bounds_t799257534_0  ___lhs, Bounds_t799257534_0  ___rhs, const MethodInfo* method) IL2CPP_METHOD_ATTR;
