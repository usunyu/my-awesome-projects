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

#include "codegen/il2cpp-codegen.h"
#include "System_System_Text_RegularExpressions_Interval1719079768.h"

// System.Void System.Text.RegularExpressions.Interval::.ctor(System.Int32,System.Int32)
extern "C"  void Interval__ctor_m_140842386_0 (Interval_t1719079768_0 * __this, int32_t ___low, int32_t ___high, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.RegularExpressions.Interval System.Text.RegularExpressions.Interval::get_Empty()
extern "C"  Interval_t1719079768_0  Interval_get_Empty_m_1458221061_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Interval::get_IsDiscontiguous()
extern "C"  bool Interval_get_IsDiscontiguous_m_133712113_0 (Interval_t1719079768_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Interval::get_IsSingleton()
extern "C"  bool Interval_get_IsSingleton_m_250001340_0 (Interval_t1719079768_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Interval::get_IsEmpty()
extern "C"  bool Interval_get_IsEmpty_m2142357766_0 (Interval_t1719079768_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.RegularExpressions.Interval::get_Size()
extern "C"  int32_t Interval_get_Size_m2053259174_0 (Interval_t1719079768_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Interval::IsDisjoint(System.Text.RegularExpressions.Interval)
extern "C"  bool Interval_IsDisjoint_m1461504100_0 (Interval_t1719079768_0 * __this, Interval_t1719079768_0  ___i, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Interval::IsAdjacent(System.Text.RegularExpressions.Interval)
extern "C"  bool Interval_IsAdjacent_m1171307166_0 (Interval_t1719079768_0 * __this, Interval_t1719079768_0  ___i, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Interval::Contains(System.Text.RegularExpressions.Interval)
extern "C"  bool Interval_Contains_m_1409985237_0 (Interval_t1719079768_0 * __this, Interval_t1719079768_0  ___i, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Interval::Contains(System.Int32)
extern "C"  bool Interval_Contains_m724747494_0 (Interval_t1719079768_0 * __this, int32_t ___i, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Interval::Intersects(System.Text.RegularExpressions.Interval)
extern "C"  bool Interval_Intersects_m1836714230_0 (Interval_t1719079768_0 * __this, Interval_t1719079768_0  ___i, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Interval::Merge(System.Text.RegularExpressions.Interval)
extern "C"  void Interval_Merge_m_1671273710_0 (Interval_t1719079768_0 * __this, Interval_t1719079768_0  ___i, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.RegularExpressions.Interval::CompareTo(System.Object)
extern "C"  int32_t Interval_CompareTo_m953943694_0 (Interval_t1719079768_0 * __this, Object_t * ___o, const MethodInfo* method) IL2CPP_METHOD_ATTR;
extern "C" void Interval_t1719079768_0_marshal(const Interval_t1719079768_0& unmarshaled, Interval_t1719079768_0_marshaled& marshaled);
extern "C" void Interval_t1719079768_0_marshal_back(const Interval_t1719079768_0_marshaled& marshaled, Interval_t1719079768_0& unmarshaled);
extern "C" void Interval_t1719079768_0_marshal_cleanup(Interval_t1719079768_0_marshaled& marshaled);
