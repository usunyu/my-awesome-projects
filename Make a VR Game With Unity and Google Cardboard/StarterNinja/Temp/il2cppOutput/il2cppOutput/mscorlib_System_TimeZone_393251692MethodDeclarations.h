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

// System.TimeZone
struct TimeZone_t_393251692_0;
// System.Globalization.DaylightTime
struct DaylightTime_t_1917202897_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_DateTime_818288618.h"
#include "mscorlib_System_TimeSpan_393459662.h"

// System.Void System.TimeZone::.ctor()
extern "C"  void TimeZone__ctor_m26653180_0 (TimeZone_t_393251692_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.TimeZone::.cctor()
extern "C"  void TimeZone__cctor_m344152369_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.TimeZone System.TimeZone::get_CurrentTimeZone()
extern "C"  TimeZone_t_393251692_0 * TimeZone_get_CurrentTimeZone_m_1308719554_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.TimeZone::IsDaylightSavingTime(System.DateTime)
extern "C"  bool TimeZone_IsDaylightSavingTime_m_1049191929_0 (TimeZone_t_393251692_0 * __this, DateTime_t_818288618_0  ___time, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.TimeZone::IsDaylightSavingTime(System.DateTime,System.Globalization.DaylightTime)
extern "C"  bool TimeZone_IsDaylightSavingTime_m_276011904_0 (Object_t * __this /* static, unused */, DateTime_t_818288618_0  ___time, DaylightTime_t_1917202897_0 * ___daylightTimes, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.TimeZone::ToLocalTime(System.DateTime)
extern "C"  DateTime_t_818288618_0  TimeZone_ToLocalTime_m_1953565720_0 (TimeZone_t_393251692_0 * __this, DateTime_t_818288618_0  ___time, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.TimeZone::ToUniversalTime(System.DateTime)
extern "C"  DateTime_t_818288618_0  TimeZone_ToUniversalTime_m1686398088_0 (TimeZone_t_393251692_0 * __this, DateTime_t_818288618_0  ___time, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.TimeSpan System.TimeZone::GetLocalTimeDiff(System.DateTime)
extern "C"  TimeSpan_t_393459662_0  TimeZone_GetLocalTimeDiff_m1562801158_0 (TimeZone_t_393251692_0 * __this, DateTime_t_818288618_0  ___time, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.TimeSpan System.TimeZone::GetLocalTimeDiff(System.DateTime,System.TimeSpan)
extern "C"  TimeSpan_t_393459662_0  TimeZone_GetLocalTimeDiff_m290923612_0 (TimeZone_t_393251692_0 * __this, DateTime_t_818288618_0  ___time, TimeSpan_t_393459662_0  ___utc_offset, const MethodInfo* method) IL2CPP_METHOD_ATTR;
