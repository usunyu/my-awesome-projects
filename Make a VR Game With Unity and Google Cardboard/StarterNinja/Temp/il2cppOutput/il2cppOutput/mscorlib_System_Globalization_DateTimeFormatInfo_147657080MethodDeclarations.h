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

// System.Globalization.DateTimeFormatInfo
struct DateTimeFormatInfo_t_147657080_0;
// System.IFormatProvider
struct IFormatProvider_t_1172917514_0;
// System.Object
struct Object_t;
// System.Type
struct Type_t;
// System.String
struct String_t;
// System.String[]
struct StringU5BU5D_t_816028754_0;
// System.Globalization.Calendar
struct Calendar_t_1304731514_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_DayOfWeek_68354036.h"

// System.Void System.Globalization.DateTimeFormatInfo::.ctor(System.Boolean)
extern "C"  void DateTimeFormatInfo__ctor_m476740351_0 (DateTimeFormatInfo_t_147657080_0 * __this, bool ___read_only, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Globalization.DateTimeFormatInfo::.ctor()
extern "C"  void DateTimeFormatInfo__ctor_m594580360_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Globalization.DateTimeFormatInfo::.cctor()
extern "C"  void DateTimeFormatInfo__cctor_m770025765_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.DateTimeFormatInfo System.Globalization.DateTimeFormatInfo::GetInstance(System.IFormatProvider)
extern "C"  DateTimeFormatInfo_t_147657080_0 * DateTimeFormatInfo_GetInstance_m619500550_0 (Object_t * __this /* static, unused */, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Globalization.DateTimeFormatInfo::get_IsReadOnly()
extern "C"  bool DateTimeFormatInfo_get_IsReadOnly_m1677012783_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.DateTimeFormatInfo System.Globalization.DateTimeFormatInfo::ReadOnly(System.Globalization.DateTimeFormatInfo)
extern "C"  DateTimeFormatInfo_t_147657080_0 * DateTimeFormatInfo_ReadOnly_m_683316849_0 (Object_t * __this /* static, unused */, DateTimeFormatInfo_t_147657080_0 * ___dtfi, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Globalization.DateTimeFormatInfo::Clone()
extern "C"  Object_t * DateTimeFormatInfo_Clone_m1570337592_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Globalization.DateTimeFormatInfo::GetFormat(System.Type)
extern "C"  Object_t * DateTimeFormatInfo_GetFormat_m_740629839_0 (DateTimeFormatInfo_t_147657080_0 * __this, Type_t * ___formatType, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.DateTimeFormatInfo::GetAbbreviatedMonthName(System.Int32)
extern "C"  String_t* DateTimeFormatInfo_GetAbbreviatedMonthName_m_963116190_0 (DateTimeFormatInfo_t_147657080_0 * __this, int32_t ___month, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.DateTimeFormatInfo::GetEraName(System.Int32)
extern "C"  String_t* DateTimeFormatInfo_GetEraName_m766646867_0 (DateTimeFormatInfo_t_147657080_0 * __this, int32_t ___era, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.DateTimeFormatInfo::GetMonthName(System.Int32)
extern "C"  String_t* DateTimeFormatInfo_GetMonthName_m_1565861889_0 (DateTimeFormatInfo_t_147657080_0 * __this, int32_t ___month, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String[] System.Globalization.DateTimeFormatInfo::get_RawAbbreviatedDayNames()
extern "C"  StringU5BU5D_t_816028754_0* DateTimeFormatInfo_get_RawAbbreviatedDayNames_m771068001_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String[] System.Globalization.DateTimeFormatInfo::get_RawAbbreviatedMonthNames()
extern "C"  StringU5BU5D_t_816028754_0* DateTimeFormatInfo_get_RawAbbreviatedMonthNames_m_607116291_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String[] System.Globalization.DateTimeFormatInfo::get_RawDayNames()
extern "C"  StringU5BU5D_t_816028754_0* DateTimeFormatInfo_get_RawDayNames_m_1021238766_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String[] System.Globalization.DateTimeFormatInfo::get_RawMonthNames()
extern "C"  StringU5BU5D_t_816028754_0* DateTimeFormatInfo_get_RawMonthNames_m_732033682_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.DateTimeFormatInfo::get_AMDesignator()
extern "C"  String_t* DateTimeFormatInfo_get_AMDesignator_m878927810_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.DateTimeFormatInfo::get_PMDesignator()
extern "C"  String_t* DateTimeFormatInfo_get_PMDesignator_m1885483027_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.DateTimeFormatInfo::get_DateSeparator()
extern "C"  String_t* DateTimeFormatInfo_get_DateSeparator_m_1461691209_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.DateTimeFormatInfo::get_TimeSeparator()
extern "C"  String_t* DateTimeFormatInfo_get_TimeSeparator_m_806346696_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.DateTimeFormatInfo::get_LongDatePattern()
extern "C"  String_t* DateTimeFormatInfo_get_LongDatePattern_m_650263994_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.DateTimeFormatInfo::get_ShortDatePattern()
extern "C"  String_t* DateTimeFormatInfo_get_ShortDatePattern_m1215316584_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.DateTimeFormatInfo::get_ShortTimePattern()
extern "C"  String_t* DateTimeFormatInfo_get_ShortTimePattern_m1542255145_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.DateTimeFormatInfo::get_LongTimePattern()
extern "C"  String_t* DateTimeFormatInfo_get_LongTimePattern_m_323325433_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.DateTimeFormatInfo::get_MonthDayPattern()
extern "C"  String_t* DateTimeFormatInfo_get_MonthDayPattern_m1446747604_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.DateTimeFormatInfo::get_YearMonthPattern()
extern "C"  String_t* DateTimeFormatInfo_get_YearMonthPattern_m_2080510833_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.DateTimeFormatInfo::get_FullDateTimePattern()
extern "C"  String_t* DateTimeFormatInfo_get_FullDateTimePattern_m1244884934_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.DateTimeFormatInfo System.Globalization.DateTimeFormatInfo::get_CurrentInfo()
extern "C"  DateTimeFormatInfo_t_147657080_0 * DateTimeFormatInfo_get_CurrentInfo_m_1862160725_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.DateTimeFormatInfo System.Globalization.DateTimeFormatInfo::get_InvariantInfo()
extern "C"  DateTimeFormatInfo_t_147657080_0 * DateTimeFormatInfo_get_InvariantInfo_m1430381298_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.Calendar System.Globalization.DateTimeFormatInfo::get_Calendar()
extern "C"  Calendar_t_1304731514_0 * DateTimeFormatInfo_get_Calendar_m1179014650_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Globalization.DateTimeFormatInfo::set_Calendar(System.Globalization.Calendar)
extern "C"  void DateTimeFormatInfo_set_Calendar_m_2041043727_0 (DateTimeFormatInfo_t_147657080_0 * __this, Calendar_t_1304731514_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.DateTimeFormatInfo::get_RFC1123Pattern()
extern "C"  String_t* DateTimeFormatInfo_get_RFC1123Pattern_m_363602398_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.DateTimeFormatInfo::get_RoundtripPattern()
extern "C"  String_t* DateTimeFormatInfo_get_RoundtripPattern_m_782908385_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.DateTimeFormatInfo::get_SortableDateTimePattern()
extern "C"  String_t* DateTimeFormatInfo_get_SortableDateTimePattern_m1830034941_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.DateTimeFormatInfo::get_UniversalSortableDateTimePattern()
extern "C"  String_t* DateTimeFormatInfo_get_UniversalSortableDateTimePattern_m1771717908_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String[] System.Globalization.DateTimeFormatInfo::GetAllDateTimePatternsInternal()
extern "C"  StringU5BU5D_t_816028754_0* DateTimeFormatInfo_GetAllDateTimePatternsInternal_m1326261985_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Globalization.DateTimeFormatInfo::FillAllDateTimePatterns()
extern "C"  void DateTimeFormatInfo_FillAllDateTimePatterns_m1091470146_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String[] System.Globalization.DateTimeFormatInfo::GetAllRawDateTimePatterns(System.Char)
extern "C"  StringU5BU5D_t_816028754_0* DateTimeFormatInfo_GetAllRawDateTimePatterns_m655159675_0 (DateTimeFormatInfo_t_147657080_0 * __this, uint16_t ___format, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.DateTimeFormatInfo::GetDayName(System.DayOfWeek)
extern "C"  String_t* DateTimeFormatInfo_GetDayName_m186743586_0 (DateTimeFormatInfo_t_147657080_0 * __this, int32_t ___dayofweek, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.DateTimeFormatInfo::GetAbbreviatedDayName(System.DayOfWeek)
extern "C"  String_t* DateTimeFormatInfo_GetAbbreviatedDayName_m_395224635_0 (DateTimeFormatInfo_t_147657080_0 * __this, int32_t ___dayofweek, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Globalization.DateTimeFormatInfo::FillInvariantPatterns()
extern "C"  void DateTimeFormatInfo_FillInvariantPatterns_m1116985894_0 (DateTimeFormatInfo_t_147657080_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String[] System.Globalization.DateTimeFormatInfo::PopulateCombinedList(System.String[],System.String[])
extern "C"  StringU5BU5D_t_816028754_0* DateTimeFormatInfo_PopulateCombinedList_m498527762_0 (DateTimeFormatInfo_t_147657080_0 * __this, StringU5BU5D_t_816028754_0* ___dates, StringU5BU5D_t_816028754_0* ___times, const MethodInfo* method) IL2CPP_METHOD_ATTR;
