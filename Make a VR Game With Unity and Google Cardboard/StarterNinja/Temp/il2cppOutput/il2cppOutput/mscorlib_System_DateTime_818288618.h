#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.String[]
struct StringU5BU5D_t_816028754_0;
// System.Int32[]
struct Int32U5BU5D_t1872284309_0;
// System.Object
struct Object_t;

#include "mscorlib_System_ValueType_103494864.h"
#include "mscorlib_System_TimeSpan_393459662.h"
#include "mscorlib_System_DateTimeKind1365220554.h"
#include "mscorlib_System_DateTime_818288618.h"

// System.DateTime
struct  DateTime_t_818288618_0 
{
	// System.TimeSpan System.DateTime::ticks
	TimeSpan_t_393459662_0  ___ticks_0;
	// System.DateTimeKind System.DateTime::kind
	int32_t ___kind_1;
};
struct DateTime_t_818288618_0_StaticFields{
	// System.DateTime System.DateTime::MaxValue
	DateTime_t_818288618_0  ___MaxValue_2;
	// System.DateTime System.DateTime::MinValue
	DateTime_t_818288618_0  ___MinValue_3;
	// System.String[] System.DateTime::ParseTimeFormats
	StringU5BU5D_t_816028754_0* ___ParseTimeFormats_4;
	// System.String[] System.DateTime::ParseYearDayMonthFormats
	StringU5BU5D_t_816028754_0* ___ParseYearDayMonthFormats_5;
	// System.String[] System.DateTime::ParseYearMonthDayFormats
	StringU5BU5D_t_816028754_0* ___ParseYearMonthDayFormats_6;
	// System.String[] System.DateTime::ParseDayMonthYearFormats
	StringU5BU5D_t_816028754_0* ___ParseDayMonthYearFormats_7;
	// System.String[] System.DateTime::ParseMonthDayYearFormats
	StringU5BU5D_t_816028754_0* ___ParseMonthDayYearFormats_8;
	// System.String[] System.DateTime::MonthDayShortFormats
	StringU5BU5D_t_816028754_0* ___MonthDayShortFormats_9;
	// System.String[] System.DateTime::DayMonthShortFormats
	StringU5BU5D_t_816028754_0* ___DayMonthShortFormats_10;
	// System.Int32[] System.DateTime::daysmonth
	Int32U5BU5D_t1872284309_0* ___daysmonth_11;
	// System.Int32[] System.DateTime::daysmonthleap
	Int32U5BU5D_t1872284309_0* ___daysmonthleap_12;
	// System.Object System.DateTime::to_local_time_span_object
	Object_t * ___to_local_time_span_object_13;
	// System.Int64 System.DateTime::last_now
	int64_t ___last_now_14;
};
