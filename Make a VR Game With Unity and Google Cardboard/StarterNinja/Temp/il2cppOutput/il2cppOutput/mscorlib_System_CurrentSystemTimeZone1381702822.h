#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.String
struct String_t;
// System.Collections.Hashtable
struct Hashtable_t_2004451924_0;
// System.Globalization.DaylightTime
struct DaylightTime_t_1917202897_0;

#include "mscorlib_System_TimeZone_393251692.h"
#include "mscorlib_System_TimeSpan_393459662.h"

// System.CurrentSystemTimeZone
struct  CurrentSystemTimeZone_t1381702822_0  : public TimeZone_t_393251692_0
{
	// System.String System.CurrentSystemTimeZone::m_standardName
	String_t* ___m_standardName_1;
	// System.String System.CurrentSystemTimeZone::m_daylightName
	String_t* ___m_daylightName_2;
	// System.Collections.Hashtable System.CurrentSystemTimeZone::m_CachedDaylightChanges
	Hashtable_t_2004451924_0 * ___m_CachedDaylightChanges_3;
	// System.Int64 System.CurrentSystemTimeZone::m_ticksOffset
	int64_t ___m_ticksOffset_4;
	// System.TimeSpan System.CurrentSystemTimeZone::utcOffsetWithOutDLS
	TimeSpan_t_393459662_0  ___utcOffsetWithOutDLS_5;
	// System.TimeSpan System.CurrentSystemTimeZone::utcOffsetWithDLS
	TimeSpan_t_393459662_0  ___utcOffsetWithDLS_6;
};
struct CurrentSystemTimeZone_t1381702822_0_StaticFields{
	// System.Int32 System.CurrentSystemTimeZone::this_year
	int32_t ___this_year_7;
	// System.Globalization.DaylightTime System.CurrentSystemTimeZone::this_year_dlt
	DaylightTime_t_1917202897_0 * ___this_year_dlt_8;
};
