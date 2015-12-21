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

// System.CurrentSystemTimeZone
struct CurrentSystemTimeZone_t1381702822_0;
// System.Object
struct Object_t;
// System.Int64[]
struct Int64U5BU5D_t1872375604_0;
// System.String[]
struct StringU5BU5D_t_816028754_0;
// System.Globalization.DaylightTime
struct DaylightTime_t_1917202897_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_TimeSpan_393459662.h"
#include "mscorlib_System_DateTime_818288618.h"

// System.Void System.CurrentSystemTimeZone::.ctor()
extern "C"  void CurrentSystemTimeZone__ctor_m1114897456_0 (CurrentSystemTimeZone_t1381702822_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.CurrentSystemTimeZone::.ctor(System.Int64)
extern "C"  void CurrentSystemTimeZone__ctor_m_143067902_0 (CurrentSystemTimeZone_t1381702822_0 * __this, int64_t ___lnow, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.CurrentSystemTimeZone::System.Runtime.Serialization.IDeserializationCallback.OnDeserialization(System.Object)
extern "C"  void CurrentSystemTimeZone_System_Runtime_Serialization_IDeserializationCallback_OnDeserialization_m167746118_0 (CurrentSystemTimeZone_t1381702822_0 * __this, Object_t * ___sender, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.CurrentSystemTimeZone::GetTimeZoneData(System.Int32,System.Int64[]&,System.String[]&)
extern "C"  bool CurrentSystemTimeZone_GetTimeZoneData_m615725030_0 (Object_t * __this /* static, unused */, int32_t ___year, Int64U5BU5D_t1872375604_0** ___data, StringU5BU5D_t_816028754_0** ___names, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.DaylightTime System.CurrentSystemTimeZone::GetDaylightChanges(System.Int32)
extern "C"  DaylightTime_t_1917202897_0 * CurrentSystemTimeZone_GetDaylightChanges_m_1944667784_0 (CurrentSystemTimeZone_t1381702822_0 * __this, int32_t ___year, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.TimeSpan System.CurrentSystemTimeZone::GetUtcOffset(System.DateTime)
extern "C"  TimeSpan_t_393459662_0  CurrentSystemTimeZone_GetUtcOffset_m376788806_0 (CurrentSystemTimeZone_t1381702822_0 * __this, DateTime_t_818288618_0  ___time, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.CurrentSystemTimeZone::OnDeserialization(System.Globalization.DaylightTime)
extern "C"  void CurrentSystemTimeZone_OnDeserialization_m_299489087_0 (CurrentSystemTimeZone_t1381702822_0 * __this, DaylightTime_t_1917202897_0 * ___dlt, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.DaylightTime System.CurrentSystemTimeZone::GetDaylightTimeFromData(System.Int64[])
extern "C"  DaylightTime_t_1917202897_0 * CurrentSystemTimeZone_GetDaylightTimeFromData_m_861588337_0 (CurrentSystemTimeZone_t1381702822_0 * __this, Int64U5BU5D_t1872375604_0* ___data, const MethodInfo* method) IL2CPP_METHOD_ATTR;
