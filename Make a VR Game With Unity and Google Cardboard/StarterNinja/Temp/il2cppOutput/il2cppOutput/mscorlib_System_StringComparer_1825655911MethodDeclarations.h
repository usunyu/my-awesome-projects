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

// System.StringComparer
struct StringComparer_t_1825655911_0;
// System.Object
struct Object_t;

#include "codegen/il2cpp-codegen.h"

// System.Void System.StringComparer::.ctor()
extern "C"  void StringComparer__ctor_m50784983_0 (StringComparer_t_1825655911_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.StringComparer::.cctor()
extern "C"  void StringComparer__cctor_m1092238262_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.StringComparer System.StringComparer::get_InvariantCultureIgnoreCase()
extern "C"  StringComparer_t_1825655911_0 * StringComparer_get_InvariantCultureIgnoreCase_m_776458384_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.StringComparer System.StringComparer::get_OrdinalIgnoreCase()
extern "C"  StringComparer_t_1825655911_0 * StringComparer_get_OrdinalIgnoreCase_m_1781814027_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.StringComparer::Compare(System.Object,System.Object)
extern "C"  int32_t StringComparer_Compare_m_363327252_0 (StringComparer_t_1825655911_0 * __this, Object_t * ___x, Object_t * ___y, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.StringComparer::Equals(System.Object,System.Object)
extern "C"  bool StringComparer_Equals_m1694946776_0 (StringComparer_t_1825655911_0 * __this, Object_t * ___x, Object_t * ___y, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.StringComparer::GetHashCode(System.Object)
extern "C"  int32_t StringComparer_GetHashCode_m1067393138_0 (StringComparer_t_1825655911_0 * __this, Object_t * ___obj, const MethodInfo* method) IL2CPP_METHOD_ATTR;
