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

// System.IFormatProvider
struct IFormatProvider_t_1172917514_0;
// System.Object
struct Object_t;
// System.Type
struct Type_t;
// System.String
struct String_t;
// System.Exception
struct Exception_t2143823668_0;
// System.String[]
struct StringU5BU5D_t_816028754_0;
// System.Globalization.DateTimeFormatInfo
struct DateTimeFormatInfo_t_147657080_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_DateTime_818288618.h"
#include "mscorlib_System_TimeSpan_393459662.h"
#include "mscorlib_System_DateTimeKind1365220554.h"
#include "mscorlib_System_Decimal1458036598.h"
#include "mscorlib_System_DateTime_Which1193516740.h"
#include "mscorlib_System_DayOfWeek_68354036.h"
#include "mscorlib_System_Globalization_DateTimeStyles_652434523.h"
#include "mscorlib_System_DateTimeOffset2123452489.h"

// System.Void System.DateTime::.ctor(System.Int64)
extern "C"  void DateTime__ctor_m_235828596_0 (DateTime_t_818288618_0 * __this, int64_t ___ticks, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.DateTime::.ctor(System.Int32,System.Int32,System.Int32)
extern "C"  void DateTime__ctor_m145640619_0 (DateTime_t_818288618_0 * __this, int32_t ___year, int32_t ___month, int32_t ___day, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.DateTime::.ctor(System.Int32,System.Int32,System.Int32,System.Int32,System.Int32,System.Int32)
extern "C"  void DateTime__ctor_m580066412_0 (DateTime_t_818288618_0 * __this, int32_t ___year, int32_t ___month, int32_t ___day, int32_t ___hour, int32_t ___minute, int32_t ___second, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.DateTime::.ctor(System.Int32,System.Int32,System.Int32,System.Int32,System.Int32,System.Int32,System.Int32)
extern "C"  void DateTime__ctor_m1594789867_0 (DateTime_t_818288618_0 * __this, int32_t ___year, int32_t ___month, int32_t ___day, int32_t ___hour, int32_t ___minute, int32_t ___second, int32_t ___millisecond, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.DateTime::.ctor(System.Boolean,System.TimeSpan)
extern "C"  void DateTime__ctor_m270463751_0 (DateTime_t_818288618_0 * __this, bool ___check, TimeSpan_t_393459662_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.DateTime::.ctor(System.Int64,System.DateTimeKind)
extern "C"  void DateTime__ctor_m_1547083830_0 (DateTime_t_818288618_0 * __this, int64_t ___ticks, int32_t ___kind, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.DateTime::.ctor(System.Int32,System.Int32,System.Int32,System.Int32,System.Int32,System.Int32,System.DateTimeKind)
extern "C"  void DateTime__ctor_m_489733718_0 (DateTime_t_818288618_0 * __this, int32_t ___year, int32_t ___month, int32_t ___day, int32_t ___hour, int32_t ___minute, int32_t ___second, int32_t ___kind, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.DateTime::.cctor()
extern "C"  void DateTime__cctor_m_2028154317_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.DateTime::System.IConvertible.ToBoolean(System.IFormatProvider)
extern "C"  bool DateTime_System_IConvertible_ToBoolean_m_1687797758_0 (DateTime_t_818288618_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte System.DateTime::System.IConvertible.ToByte(System.IFormatProvider)
extern "C"  uint8_t DateTime_System_IConvertible_ToByte_m_925067486_0 (DateTime_t_818288618_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Char System.DateTime::System.IConvertible.ToChar(System.IFormatProvider)
extern "C"  uint16_t DateTime_System_IConvertible_ToChar_m_209769794_0 (DateTime_t_818288618_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.DateTime::System.IConvertible.ToDateTime(System.IFormatProvider)
extern "C"  DateTime_t_818288618_0  DateTime_System_IConvertible_ToDateTime_m1478929736_0 (DateTime_t_818288618_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.DateTime::System.IConvertible.ToDecimal(System.IFormatProvider)
extern "C"  Decimal_t1458036598_0  DateTime_System_IConvertible_ToDecimal_m53652706_0 (DateTime_t_818288618_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Double System.DateTime::System.IConvertible.ToDouble(System.IFormatProvider)
extern "C"  double DateTime_System_IConvertible_ToDouble_m_802820748_0 (DateTime_t_818288618_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int16 System.DateTime::System.IConvertible.ToInt16(System.IFormatProvider)
extern "C"  int16_t DateTime_System_IConvertible_ToInt16_m_991295230_0 (DateTime_t_818288618_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.DateTime::System.IConvertible.ToInt32(System.IFormatProvider)
extern "C"  int32_t DateTime_System_IConvertible_ToInt32_m_1699651774_0 (DateTime_t_818288618_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.DateTime::System.IConvertible.ToInt64(System.IFormatProvider)
extern "C"  int64_t DateTime_System_IConvertible_ToInt64_m_1008611934_0 (DateTime_t_818288618_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.SByte System.DateTime::System.IConvertible.ToSByte(System.IFormatProvider)
extern "C"  int8_t DateTime_System_IConvertible_ToSByte_m551886946_0 (DateTime_t_818288618_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single System.DateTime::System.IConvertible.ToSingle(System.IFormatProvider)
extern "C"  float DateTime_System_IConvertible_ToSingle_m1051597858_0 (DateTime_t_818288618_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.DateTime::System.IConvertible.ToType(System.Type,System.IFormatProvider)
extern "C"  Object_t * DateTime_System_IConvertible_ToType_m1980756024_0 (DateTime_t_818288618_0 * __this, Type_t * ___targetType, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt16 System.DateTime::System.IConvertible.ToUInt16(System.IFormatProvider)
extern "C"  uint16_t DateTime_System_IConvertible_ToUInt16_m_1157982448_0 (DateTime_t_818288618_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt32 System.DateTime::System.IConvertible.ToUInt32(System.IFormatProvider)
extern "C"  uint32_t DateTime_System_IConvertible_ToUInt32_m634562052_0 (DateTime_t_818288618_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt64 System.DateTime::System.IConvertible.ToUInt64(System.IFormatProvider)
extern "C"  uint64_t DateTime_System_IConvertible_ToUInt64_m_2131313022_0 (DateTime_t_818288618_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.DateTime::AbsoluteDays(System.Int32,System.Int32,System.Int32)
extern "C"  int32_t DateTime_AbsoluteDays_m1774199309_0 (Object_t * __this /* static, unused */, int32_t ___year, int32_t ___month, int32_t ___day, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.DateTime::FromTicks(System.DateTime/Which)
extern "C"  int32_t DateTime_FromTicks_m1238653738_0 (DateTime_t_818288618_0 * __this, int32_t ___what, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.DateTime::get_Month()
extern "C"  int32_t DateTime_get_Month_m1871036171_0 (DateTime_t_818288618_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.DateTime::get_Day()
extern "C"  int32_t DateTime_get_Day_m609985447_0 (DateTime_t_818288618_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DayOfWeek System.DateTime::get_DayOfWeek()
extern "C"  int32_t DateTime_get_DayOfWeek_m1793620473_0 (DateTime_t_818288618_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.DateTime::get_Hour()
extern "C"  int32_t DateTime_get_Hour_m1857077531_0 (DateTime_t_818288618_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.DateTime::get_Minute()
extern "C"  int32_t DateTime_get_Minute_m1138831307_0 (DateTime_t_818288618_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.DateTime::get_Second()
extern "C"  int32_t DateTime_get_Second_m_864897493_0 (DateTime_t_818288618_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.DateTime::GetTimeMonotonic()
extern "C"  int64_t DateTime_GetTimeMonotonic_m_1811106316_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.DateTime::GetNow()
extern "C"  int64_t DateTime_GetNow_m_1542007379_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.DateTime::get_Now()
extern "C"  DateTime_t_818288618_0  DateTime_get_Now_m1812131422_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.DateTime::get_Ticks()
extern "C"  int64_t DateTime_get_Ticks_m386468226_0 (DateTime_t_818288618_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.DateTime::get_Today()
extern "C"  DateTime_t_818288618_0  DateTime_get_Today_m_1284141495_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.DateTime::get_UtcNow()
extern "C"  DateTime_t_818288618_0  DateTime_get_UtcNow_m685282732_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.DateTime::get_Year()
extern "C"  int32_t DateTime_get_Year_m_1961025228_0 (DateTime_t_818288618_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTimeKind System.DateTime::get_Kind()
extern "C"  int32_t DateTime_get_Kind_m_798953694_0 (DateTime_t_818288618_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.DateTime::Add(System.TimeSpan)
extern "C"  DateTime_t_818288618_0  DateTime_Add_m1332740042_0 (DateTime_t_818288618_0 * __this, TimeSpan_t_393459662_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.DateTime::AddTicks(System.Int64)
extern "C"  DateTime_t_818288618_0  DateTime_AddTicks_m_1899510344_0 (DateTime_t_818288618_0 * __this, int64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.DateTime::AddMilliseconds(System.Double)
extern "C"  DateTime_t_818288618_0  DateTime_AddMilliseconds_m1717403134_0 (DateTime_t_818288618_0 * __this, double ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.DateTime::AddSeconds(System.Double)
extern "C"  DateTime_t_818288618_0  DateTime_AddSeconds_m_1779327053_0 (DateTime_t_818288618_0 * __this, double ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.DateTime::Compare(System.DateTime,System.DateTime)
extern "C"  int32_t DateTime_Compare_m1646075697_0 (Object_t * __this /* static, unused */, DateTime_t_818288618_0  ___t1, DateTime_t_818288618_0  ___t2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.DateTime::CompareTo(System.Object)
extern "C"  int32_t DateTime_CompareTo_m246114144_0 (DateTime_t_818288618_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.DateTime::CompareTo(System.DateTime)
extern "C"  int32_t DateTime_CompareTo_m1522800900_0 (DateTime_t_818288618_0 * __this, DateTime_t_818288618_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.DateTime::Equals(System.DateTime)
extern "C"  bool DateTime_Equals_m1479384337_0 (DateTime_t_818288618_0 * __this, DateTime_t_818288618_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.DateTime::FromBinary(System.Int64)
extern "C"  DateTime_t_818288618_0  DateTime_FromBinary_m1447091502_0 (Object_t * __this /* static, unused */, int64_t ___dateData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.DateTime::SpecifyKind(System.DateTime,System.DateTimeKind)
extern "C"  DateTime_t_818288618_0  DateTime_SpecifyKind_m2123544880_0 (Object_t * __this /* static, unused */, DateTime_t_818288618_0  ___value, int32_t ___kind, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.DateTime::DaysInMonth(System.Int32,System.Int32)
extern "C"  int32_t DateTime_DaysInMonth_m1394183022_0 (Object_t * __this /* static, unused */, int32_t ___year, int32_t ___month, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.DateTime::Equals(System.Object)
extern "C"  bool DateTime_Equals_m13666989_0 (DateTime_t_818288618_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.DateTime::CheckDateTimeKind(System.DateTimeKind)
extern "C"  void DateTime_CheckDateTimeKind_m1840811157_0 (DateTime_t_818288618_0 * __this, int32_t ___kind, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.DateTime::GetHashCode()
extern "C"  int32_t DateTime_GetHashCode_m_2039380731_0 (DateTime_t_818288618_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.DateTime::IsLeapYear(System.Int32)
extern "C"  bool DateTime_IsLeapYear_m_890245912_0 (Object_t * __this /* static, unused */, int32_t ___year, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.DateTime::Parse(System.String,System.IFormatProvider)
extern "C"  DateTime_t_818288618_0  DateTime_Parse_m1801557718_0 (Object_t * __this /* static, unused */, String_t* ___s, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.DateTime::Parse(System.String,System.IFormatProvider,System.Globalization.DateTimeStyles)
extern "C"  DateTime_t_818288618_0  DateTime_Parse_m1424797081_0 (Object_t * __this /* static, unused */, String_t* ___s, Object_t * ___provider, int32_t ___styles, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.DateTime::CoreParse(System.String,System.IFormatProvider,System.Globalization.DateTimeStyles,System.DateTime&,System.DateTimeOffset&,System.Boolean,System.Exception&)
extern "C"  bool DateTime_CoreParse_m_1793904195_0 (Object_t * __this /* static, unused */, String_t* ___s, Object_t * ___provider, int32_t ___styles, DateTime_t_818288618_0 * ___result, DateTimeOffset_t2123452489_0 * ___dto, bool ___setExceptionOnError, Exception_t2143823668_0 ** ___exception, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String[] System.DateTime::YearMonthDayFormats(System.Globalization.DateTimeFormatInfo,System.Boolean,System.Exception&)
extern "C"  StringU5BU5D_t_816028754_0* DateTime_YearMonthDayFormats_m200860137_0 (Object_t * __this /* static, unused */, DateTimeFormatInfo_t_147657080_0 * ___dfi, bool ___setExceptionOnError, Exception_t2143823668_0 ** ___exc, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.DateTime::_ParseNumber(System.String,System.Int32,System.Int32,System.Int32,System.Boolean,System.Boolean,System.Int32&)
extern "C"  int32_t DateTime__ParseNumber_m223303221_0 (Object_t * __this /* static, unused */, String_t* ___s, int32_t ___valuePos, int32_t ___min_digits, int32_t ___digits, bool ___leadingzero, bool ___sloppy_parsing, int32_t* ___num_parsed, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.DateTime::_ParseEnum(System.String,System.Int32,System.String[],System.String[],System.Boolean,System.Int32&)
extern "C"  int32_t DateTime__ParseEnum_m780384966_0 (Object_t * __this /* static, unused */, String_t* ___s, int32_t ___sPos, StringU5BU5D_t_816028754_0* ___values, StringU5BU5D_t_816028754_0* ___invValues, bool ___exact, int32_t* ___num_parsed, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.DateTime::_ParseString(System.String,System.Int32,System.Int32,System.String,System.Int32&)
extern "C"  bool DateTime__ParseString_m_534521242_0 (Object_t * __this /* static, unused */, String_t* ___s, int32_t ___sPos, int32_t ___maxlength, String_t* ___value, int32_t* ___num_parsed, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.DateTime::_ParseAmPm(System.String,System.Int32,System.Int32,System.Globalization.DateTimeFormatInfo,System.Boolean,System.Int32&,System.Int32&)
extern "C"  bool DateTime__ParseAmPm_m618382890_0 (Object_t * __this /* static, unused */, String_t* ___s, int32_t ___valuePos, int32_t ___num, DateTimeFormatInfo_t_147657080_0 * ___dfi, bool ___exact, int32_t* ___num_parsed, int32_t* ___ampm, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.DateTime::_ParseTimeSeparator(System.String,System.Int32,System.Globalization.DateTimeFormatInfo,System.Boolean,System.Int32&)
extern "C"  bool DateTime__ParseTimeSeparator_m_126472321_0 (Object_t * __this /* static, unused */, String_t* ___s, int32_t ___sPos, DateTimeFormatInfo_t_147657080_0 * ___dfi, bool ___exact, int32_t* ___num_parsed, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.DateTime::_ParseDateSeparator(System.String,System.Int32,System.Globalization.DateTimeFormatInfo,System.Boolean,System.Int32&)
extern "C"  bool DateTime__ParseDateSeparator_m1287691040_0 (Object_t * __this /* static, unused */, String_t* ___s, int32_t ___sPos, DateTimeFormatInfo_t_147657080_0 * ___dfi, bool ___exact, int32_t* ___num_parsed, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.DateTime::IsLetter(System.String,System.Int32)
extern "C"  bool DateTime_IsLetter_m_311638643_0 (Object_t * __this /* static, unused */, String_t* ___s, int32_t ___pos, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.DateTime::_DoParse(System.String,System.String,System.String,System.Boolean,System.DateTime&,System.DateTimeOffset&,System.Globalization.DateTimeFormatInfo,System.Globalization.DateTimeStyles,System.Boolean,System.Boolean&,System.Boolean&)
extern "C"  bool DateTime__DoParse_m760672305_0 (Object_t * __this /* static, unused */, String_t* ___s, String_t* ___firstPart, String_t* ___secondPart, bool ___exact, DateTime_t_818288618_0 * ___result, DateTimeOffset_t2123452489_0 * ___dto, DateTimeFormatInfo_t_147657080_0 * ___dfi, int32_t ___style, bool ___firstPartIsDate, bool* ___incompleteFormat, bool* ___longYear, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.DateTime::ParseExact(System.String,System.String,System.IFormatProvider,System.Globalization.DateTimeStyles)
extern "C"  DateTime_t_818288618_0  DateTime_ParseExact_m_1136263082_0 (Object_t * __this /* static, unused */, String_t* ___s, String_t* ___format, Object_t * ___provider, int32_t ___style, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.DateTime::ParseExact(System.String,System.String[],System.IFormatProvider,System.Globalization.DateTimeStyles)
extern "C"  DateTime_t_818288618_0  DateTime_ParseExact_m_277069128_0 (Object_t * __this /* static, unused */, String_t* ___s, StringU5BU5D_t_816028754_0* ___formats, Object_t * ___provider, int32_t ___style, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.DateTime::CheckStyle(System.Globalization.DateTimeStyles)
extern "C"  void DateTime_CheckStyle_m1804676438_0 (Object_t * __this /* static, unused */, int32_t ___style, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.DateTime::ParseExact(System.String,System.String[],System.Globalization.DateTimeFormatInfo,System.Globalization.DateTimeStyles,System.DateTime&,System.Boolean,System.Boolean&,System.Boolean,System.Exception&)
extern "C"  bool DateTime_ParseExact_m_718901610_0 (Object_t * __this /* static, unused */, String_t* ___s, StringU5BU5D_t_816028754_0* ___formats, DateTimeFormatInfo_t_147657080_0 * ___dfi, int32_t ___style, DateTime_t_818288618_0 * ___ret, bool ___exact, bool* ___longYear, bool ___setExceptionOnError, Exception_t2143823668_0 ** ___exception, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.DateTime::Subtract(System.TimeSpan)
extern "C"  DateTime_t_818288618_0  DateTime_Subtract_m_164416489_0 (DateTime_t_818288618_0 * __this, TimeSpan_t_393459662_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.DateTime::ToString()
extern "C"  String_t* DateTime_ToString_m_1073060237_0 (DateTime_t_818288618_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.DateTime::ToString(System.IFormatProvider)
extern "C"  String_t* DateTime_ToString_m1268589345_0 (DateTime_t_818288618_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.DateTime::ToString(System.String,System.IFormatProvider)
extern "C"  String_t* DateTime_ToString_m2141430949_0 (DateTime_t_818288618_0 * __this, String_t* ___format, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.DateTime::ToLocalTime()
extern "C"  DateTime_t_818288618_0  DateTime_ToLocalTime_m_665784178_0 (DateTime_t_818288618_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.DateTime::ToUniversalTime()
extern "C"  DateTime_t_818288618_0  DateTime_ToUniversalTime_m691668206_0 (DateTime_t_818288618_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.DateTime::op_Addition(System.DateTime,System.TimeSpan)
extern "C"  DateTime_t_818288618_0  DateTime_op_Addition_m_233383773_0 (Object_t * __this /* static, unused */, DateTime_t_818288618_0  ___d, TimeSpan_t_393459662_0  ___t, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.DateTime::op_Equality(System.DateTime,System.DateTime)
extern "C"  bool DateTime_op_Equality_m_2017530632_0 (Object_t * __this /* static, unused */, DateTime_t_818288618_0  ___d1, DateTime_t_818288618_0  ___d2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.DateTime::op_GreaterThan(System.DateTime,System.DateTime)
extern "C"  bool DateTime_op_GreaterThan_m_448950427_0 (Object_t * __this /* static, unused */, DateTime_t_818288618_0  ___t1, DateTime_t_818288618_0  ___t2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.DateTime::op_GreaterThanOrEqual(System.DateTime,System.DateTime)
extern "C"  bool DateTime_op_GreaterThanOrEqual_m717787228_0 (Object_t * __this /* static, unused */, DateTime_t_818288618_0  ___t1, DateTime_t_818288618_0  ___t2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.DateTime::op_Inequality(System.DateTime,System.DateTime)
extern "C"  bool DateTime_op_Inequality_m_848517325_0 (Object_t * __this /* static, unused */, DateTime_t_818288618_0  ___d1, DateTime_t_818288618_0  ___d2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.DateTime::op_LessThan(System.DateTime,System.DateTime)
extern "C"  bool DateTime_op_LessThan_m35073816_0 (Object_t * __this /* static, unused */, DateTime_t_818288618_0  ___t1, DateTime_t_818288618_0  ___t2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.DateTime::op_LessThanOrEqual(System.DateTime,System.DateTime)
extern "C"  bool DateTime_op_LessThanOrEqual_m354447689_0 (Object_t * __this /* static, unused */, DateTime_t_818288618_0  ___t1, DateTime_t_818288618_0  ___t2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.DateTime::op_Subtraction(System.DateTime,System.TimeSpan)
extern "C"  DateTime_t_818288618_0  DateTime_op_Subtraction_m_685945977_0 (Object_t * __this /* static, unused */, DateTime_t_818288618_0  ___d, TimeSpan_t_393459662_0  ___t, const MethodInfo* method) IL2CPP_METHOD_ATTR;
