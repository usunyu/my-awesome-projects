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
#include "mscorlib_System_TimeSpan_393459662.h"

// System.Void System.TimeSpan::.ctor(System.Int64)
extern "C"  void TimeSpan__ctor_m477860848_0 (TimeSpan_t_393459662_0 * __this, int64_t ___ticks, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.TimeSpan::.ctor(System.Int32,System.Int32,System.Int32)
extern "C"  void TimeSpan__ctor_m_134635249_0 (TimeSpan_t_393459662_0 * __this, int32_t ___hours, int32_t ___minutes, int32_t ___seconds, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.TimeSpan::.ctor(System.Int32,System.Int32,System.Int32,System.Int32,System.Int32)
extern "C"  void TimeSpan__ctor_m_1103875665_0 (TimeSpan_t_393459662_0 * __this, int32_t ___days, int32_t ___hours, int32_t ___minutes, int32_t ___seconds, int32_t ___milliseconds, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.TimeSpan::.cctor()
extern "C"  void TimeSpan__cctor_m_1376075953_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.TimeSpan::CalculateTicks(System.Int32,System.Int32,System.Int32,System.Int32,System.Int32)
extern "C"  int64_t TimeSpan_CalculateTicks_m897131370_0 (Object_t * __this /* static, unused */, int32_t ___days, int32_t ___hours, int32_t ___minutes, int32_t ___seconds, int32_t ___milliseconds, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.TimeSpan::get_Days()
extern "C"  int32_t TimeSpan_get_Days_m1311834346_0 (TimeSpan_t_393459662_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.TimeSpan::get_Hours()
extern "C"  int32_t TimeSpan_get_Hours_m1664362814_0 (TimeSpan_t_393459662_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.TimeSpan::get_Milliseconds()
extern "C"  int32_t TimeSpan_get_Milliseconds_m424744421_0 (TimeSpan_t_393459662_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.TimeSpan::get_Minutes()
extern "C"  int32_t TimeSpan_get_Minutes_m1876674446_0 (TimeSpan_t_393459662_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.TimeSpan::get_Seconds()
extern "C"  int32_t TimeSpan_get_Seconds_m_109376210_0 (TimeSpan_t_393459662_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.TimeSpan::get_Ticks()
extern "C"  int64_t TimeSpan_get_Ticks_m315930342_0 (TimeSpan_t_393459662_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Double System.TimeSpan::get_TotalDays()
extern "C"  double TimeSpan_get_TotalDays_m_771023375_0 (TimeSpan_t_393459662_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Double System.TimeSpan::get_TotalHours()
extern "C"  double TimeSpan_get_TotalHours_m1520282903_0 (TimeSpan_t_393459662_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Double System.TimeSpan::get_TotalMilliseconds()
extern "C"  double TimeSpan_get_TotalMilliseconds_m_241353748_0 (TimeSpan_t_393459662_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Double System.TimeSpan::get_TotalMinutes()
extern "C"  double TimeSpan_get_TotalMinutes_m854833447_0 (TimeSpan_t_393459662_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Double System.TimeSpan::get_TotalSeconds()
extern "C"  double TimeSpan_get_TotalSeconds_m_1131217209_0 (TimeSpan_t_393459662_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.TimeSpan System.TimeSpan::Add(System.TimeSpan)
extern "C"  TimeSpan_t_393459662_0  TimeSpan_Add_m1523355138_0 (TimeSpan_t_393459662_0 * __this, TimeSpan_t_393459662_0  ___ts, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.TimeSpan::Compare(System.TimeSpan,System.TimeSpan)
extern "C"  int32_t TimeSpan_Compare_m206019349_0 (Object_t * __this /* static, unused */, TimeSpan_t_393459662_0  ___t1, TimeSpan_t_393459662_0  ___t2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.TimeSpan::CompareTo(System.Object)
extern "C"  int32_t TimeSpan_CompareTo_m_257713028_0 (TimeSpan_t_393459662_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.TimeSpan::CompareTo(System.TimeSpan)
extern "C"  int32_t TimeSpan_CompareTo_m_1333978492_0 (TimeSpan_t_393459662_0 * __this, TimeSpan_t_393459662_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.TimeSpan::Equals(System.TimeSpan)
extern "C"  bool TimeSpan_Equals_m_1023019047_0 (TimeSpan_t_393459662_0 * __this, TimeSpan_t_393459662_0  ___obj, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.TimeSpan System.TimeSpan::Duration()
extern "C"  TimeSpan_t_393459662_0  TimeSpan_Duration_m_117906019_0 (TimeSpan_t_393459662_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.TimeSpan::Equals(System.Object)
extern "C"  bool TimeSpan_Equals_m_1325544687_0 (TimeSpan_t_393459662_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.TimeSpan System.TimeSpan::FromDays(System.Double)
extern "C"  TimeSpan_t_393459662_0  TimeSpan_FromDays_m_1987926120_0 (Object_t * __this /* static, unused */, double ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.TimeSpan System.TimeSpan::FromHours(System.Double)
extern "C"  TimeSpan_t_393459662_0  TimeSpan_FromHours_m_490338876_0 (Object_t * __this /* static, unused */, double ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.TimeSpan System.TimeSpan::FromMinutes(System.Double)
extern "C"  TimeSpan_t_393459662_0  TimeSpan_FromMinutes_m785017204_0 (Object_t * __this /* static, unused */, double ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.TimeSpan System.TimeSpan::FromSeconds(System.Double)
extern "C"  TimeSpan_t_393459662_0  TimeSpan_FromSeconds_m1904297940_0 (Object_t * __this /* static, unused */, double ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.TimeSpan System.TimeSpan::FromMilliseconds(System.Double)
extern "C"  TimeSpan_t_393459662_0  TimeSpan_FromMilliseconds_m1386660477_0 (Object_t * __this /* static, unused */, double ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.TimeSpan System.TimeSpan::From(System.Double,System.Int64)
extern "C"  TimeSpan_t_393459662_0  TimeSpan_From_m739812553_0 (Object_t * __this /* static, unused */, double ___value, int64_t ___tickMultiplicator, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.TimeSpan::GetHashCode()
extern "C"  int32_t TimeSpan_GetHashCode_m_1106810519_0 (TimeSpan_t_393459662_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.TimeSpan System.TimeSpan::Negate()
extern "C"  TimeSpan_t_393459662_0  TimeSpan_Negate_m_783090293_0 (TimeSpan_t_393459662_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.TimeSpan System.TimeSpan::Subtract(System.TimeSpan)
extern "C"  TimeSpan_t_393459662_0  TimeSpan_Subtract_m1410255071_0 (TimeSpan_t_393459662_0 * __this, TimeSpan_t_393459662_0  ___ts, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.TimeSpan::ToString()
extern "C"  String_t* TimeSpan_ToString_m_1490977649_0 (TimeSpan_t_393459662_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.TimeSpan System.TimeSpan::op_Addition(System.TimeSpan,System.TimeSpan)
extern "C"  TimeSpan_t_393459662_0  TimeSpan_op_Addition_m141072959_0 (Object_t * __this /* static, unused */, TimeSpan_t_393459662_0  ___t1, TimeSpan_t_393459662_0  ___t2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.TimeSpan::op_Equality(System.TimeSpan,System.TimeSpan)
extern "C"  bool TimeSpan_op_Equality_m_2081588516_0 (Object_t * __this /* static, unused */, TimeSpan_t_393459662_0  ___t1, TimeSpan_t_393459662_0  ___t2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.TimeSpan::op_GreaterThan(System.TimeSpan,System.TimeSpan)
extern "C"  bool TimeSpan_op_GreaterThan_m_374515311_0 (Object_t * __this /* static, unused */, TimeSpan_t_393459662_0  ___t1, TimeSpan_t_393459662_0  ___t2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.TimeSpan::op_GreaterThanOrEqual(System.TimeSpan,System.TimeSpan)
extern "C"  bool TimeSpan_op_GreaterThanOrEqual_m_2141983936_0 (Object_t * __this /* static, unused */, TimeSpan_t_393459662_0  ___t1, TimeSpan_t_393459662_0  ___t2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.TimeSpan::op_Inequality(System.TimeSpan,System.TimeSpan)
extern "C"  bool TimeSpan_op_Inequality_m_2110530025_0 (Object_t * __this /* static, unused */, TimeSpan_t_393459662_0  ___t1, TimeSpan_t_393459662_0  ___t2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.TimeSpan::op_LessThan(System.TimeSpan,System.TimeSpan)
extern "C"  bool TimeSpan_op_LessThan_m_28984068_0 (Object_t * __this /* static, unused */, TimeSpan_t_393459662_0  ___t1, TimeSpan_t_393459662_0  ___t2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.TimeSpan::op_LessThanOrEqual(System.TimeSpan,System.TimeSpan)
extern "C"  bool TimeSpan_op_LessThanOrEqual_m271837557_0 (Object_t * __this /* static, unused */, TimeSpan_t_393459662_0  ___t1, TimeSpan_t_393459662_0  ___t2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.TimeSpan System.TimeSpan::op_Subtraction(System.TimeSpan,System.TimeSpan)
extern "C"  TimeSpan_t_393459662_0  TimeSpan_op_Subtraction_m_608176717_0 (Object_t * __this /* static, unused */, TimeSpan_t_393459662_0  ___t1, TimeSpan_t_393459662_0  ___t2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
