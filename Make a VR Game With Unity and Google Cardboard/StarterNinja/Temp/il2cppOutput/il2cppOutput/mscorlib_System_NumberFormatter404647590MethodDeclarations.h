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

// System.NumberFormatter
struct NumberFormatter_t404647590_0;
// System.Threading.Thread
struct Thread_t_702325573_0;
// System.String
struct String_t;
// System.Globalization.NumberFormatInfo
struct NumberFormatInfo_t746228406_0;
// System.IFormatProvider
struct IFormatProvider_t_1172917514_0;
// System.Globalization.CultureInfo
struct CultureInfo_t_1039475404_0;
// System.Text.StringBuilder
struct StringBuilder_t586045924_0;
// System.Int32[]
struct Int32U5BU5D_t1872284309_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Decimal1458036598.h"

// System.Void System.NumberFormatter::.ctor(System.Threading.Thread)
extern "C"  void NumberFormatter__ctor_m2111196867_0 (NumberFormatter_t404647590_0 * __this, Thread_t_702325573_0 * ___current, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::.cctor()
extern "C"  void NumberFormatter__cctor_m1125188925_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::GetFormatterTables(System.UInt64*&,System.Int32*&,System.Char*&,System.Char*&,System.Int64*&,System.Int32*&)
extern "C"  void NumberFormatter_GetFormatterTables_m1004885150_0 (Object_t * __this /* static, unused */, uint64_t** ___MantissaBitsTable, int32_t** ___TensExponentTable, uint16_t** ___DigitLowerTable, uint16_t** ___DigitUpperTable, int64_t** ___TenPowersList, int32_t** ___DecHexDigits, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.NumberFormatter::GetTenPowerOf(System.Int32)
extern "C"  int64_t NumberFormatter_GetTenPowerOf_m_1071266761_0 (Object_t * __this /* static, unused */, int32_t ___i, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::InitDecHexDigits(System.UInt32)
extern "C"  void NumberFormatter_InitDecHexDigits_m_2130181097_0 (NumberFormatter_t404647590_0 * __this, uint32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::InitDecHexDigits(System.UInt64)
extern "C"  void NumberFormatter_InitDecHexDigits_m_2130178152_0 (NumberFormatter_t404647590_0 * __this, uint64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::InitDecHexDigits(System.UInt32,System.UInt64)
extern "C"  void NumberFormatter_InitDecHexDigits_m_1005021812_0 (NumberFormatter_t404647590_0 * __this, uint32_t ___hi, uint64_t ___lo, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt32 System.NumberFormatter::FastToDecHex(System.Int32)
extern "C"  uint32_t NumberFormatter_FastToDecHex_m84047568_0 (Object_t * __this /* static, unused */, int32_t ___val, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt32 System.NumberFormatter::ToDecHex(System.Int32)
extern "C"  uint32_t NumberFormatter_ToDecHex_m_1519532460_0 (Object_t * __this /* static, unused */, int32_t ___val, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.NumberFormatter::FastDecHexLen(System.Int32)
extern "C"  int32_t NumberFormatter_FastDecHexLen_m_968249885_0 (Object_t * __this /* static, unused */, int32_t ___val, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.NumberFormatter::DecHexLen(System.UInt32)
extern "C"  int32_t NumberFormatter_DecHexLen_m1305612716_0 (Object_t * __this /* static, unused */, uint32_t ___val, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.NumberFormatter::DecHexLen()
extern "C"  int32_t NumberFormatter_DecHexLen_m1385571854_0 (NumberFormatter_t404647590_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.NumberFormatter::ScaleOrder(System.Int64)
extern "C"  int32_t NumberFormatter_ScaleOrder_m_1626352474_0 (Object_t * __this /* static, unused */, int64_t ___hi, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.NumberFormatter::InitialFloatingPrecision()
extern "C"  int32_t NumberFormatter_InitialFloatingPrecision_m1576619940_0 (NumberFormatter_t404647590_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.NumberFormatter::ParsePrecision(System.String)
extern "C"  int32_t NumberFormatter_ParsePrecision_m1776481127_0 (Object_t * __this /* static, unused */, String_t* ___format, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::Init(System.String)
extern "C"  void NumberFormatter_Init_m796042654_0 (NumberFormatter_t404647590_0 * __this, String_t* ___format, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::InitHex(System.UInt64)
extern "C"  void NumberFormatter_InitHex_m673436066_0 (NumberFormatter_t404647590_0 * __this, uint64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::Init(System.String,System.Int32,System.Int32)
extern "C"  void NumberFormatter_Init_m1761120638_0 (NumberFormatter_t404647590_0 * __this, String_t* ___format, int32_t ___value, int32_t ___defPrecision, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::Init(System.String,System.UInt32,System.Int32)
extern "C"  void NumberFormatter_Init_m_394912059_0 (NumberFormatter_t404647590_0 * __this, String_t* ___format, uint32_t ___value, int32_t ___defPrecision, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::Init(System.String,System.Int64)
extern "C"  void NumberFormatter_Init_m1120342906_0 (NumberFormatter_t404647590_0 * __this, String_t* ___format, int64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::Init(System.String,System.UInt64)
extern "C"  void NumberFormatter_Init_m1368030931_0 (NumberFormatter_t404647590_0 * __this, String_t* ___format, uint64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::Init(System.String,System.Double,System.Int32)
extern "C"  void NumberFormatter_Init_m_499283587_0 (NumberFormatter_t404647590_0 * __this, String_t* ___format, double ___value, int32_t ___defPrecision, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::Init(System.String,System.Decimal)
extern "C"  void NumberFormatter_Init_m_1346814954_0 (NumberFormatter_t404647590_0 * __this, String_t* ___format, Decimal_t1458036598_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::ResetCharBuf(System.Int32)
extern "C"  void NumberFormatter_ResetCharBuf_m213960083_0 (NumberFormatter_t404647590_0 * __this, int32_t ___size, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::Resize(System.Int32)
extern "C"  void NumberFormatter_Resize_m_847221991_0 (NumberFormatter_t404647590_0 * __this, int32_t ___len, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::Append(System.Char)
extern "C"  void NumberFormatter_Append_m_176204945_0 (NumberFormatter_t404647590_0 * __this, uint16_t ___c, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::Append(System.Char,System.Int32)
extern "C"  void NumberFormatter_Append_m_141748792_0 (NumberFormatter_t404647590_0 * __this, uint16_t ___c, int32_t ___cnt, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::Append(System.String)
extern "C"  void NumberFormatter_Append_m_155019500_0 (NumberFormatter_t404647590_0 * __this, String_t* ___s, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.NumberFormatInfo System.NumberFormatter::GetNumberFormatInstance(System.IFormatProvider)
extern "C"  NumberFormatInfo_t746228406_0 * NumberFormatter_GetNumberFormatInstance_m958950318_0 (NumberFormatter_t404647590_0 * __this, Object_t * ___fp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::set_CurrentCulture(System.Globalization.CultureInfo)
extern "C"  void NumberFormatter_set_CurrentCulture_m_1527517898_0 (NumberFormatter_t404647590_0 * __this, CultureInfo_t_1039475404_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.NumberFormatter::get_IntegerDigits()
extern "C"  int32_t NumberFormatter_get_IntegerDigits_m1728967757_0 (NumberFormatter_t404647590_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.NumberFormatter::get_DecimalDigits()
extern "C"  int32_t NumberFormatter_get_DecimalDigits_m799523680_0 (NumberFormatter_t404647590_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.NumberFormatter::get_IsFloatingSource()
extern "C"  bool NumberFormatter_get_IsFloatingSource_m_329225046_0 (NumberFormatter_t404647590_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.NumberFormatter::get_IsZero()
extern "C"  bool NumberFormatter_get_IsZero_m1430003665_0 (NumberFormatter_t404647590_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.NumberFormatter::get_IsZeroInteger()
extern "C"  bool NumberFormatter_get_IsZeroInteger_m1771268559_0 (NumberFormatter_t404647590_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::RoundPos(System.Int32)
extern "C"  void NumberFormatter_RoundPos_m_1320719349_0 (NumberFormatter_t404647590_0 * __this, int32_t ___pos, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.NumberFormatter::RoundDecimal(System.Int32)
extern "C"  bool NumberFormatter_RoundDecimal_m_1031983542_0 (NumberFormatter_t404647590_0 * __this, int32_t ___decimals, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.NumberFormatter::RoundBits(System.Int32)
extern "C"  bool NumberFormatter_RoundBits_m1678805201_0 (NumberFormatter_t404647590_0 * __this, int32_t ___shift, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::RemoveTrailingZeros()
extern "C"  void NumberFormatter_RemoveTrailingZeros_m_553576967_0 (NumberFormatter_t404647590_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::AddOneToDecHex()
extern "C"  void NumberFormatter_AddOneToDecHex_m_521559027_0 (NumberFormatter_t404647590_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt32 System.NumberFormatter::AddOneToDecHex(System.UInt32)
extern "C"  uint32_t NumberFormatter_AddOneToDecHex_m_2081673454_0 (Object_t * __this /* static, unused */, uint32_t ___val, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.NumberFormatter::CountTrailingZeros()
extern "C"  int32_t NumberFormatter_CountTrailingZeros_m208778992_0 (NumberFormatter_t404647590_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.NumberFormatter::CountTrailingZeros(System.UInt32)
extern "C"  int32_t NumberFormatter_CountTrailingZeros_m_687046646_0 (Object_t * __this /* static, unused */, uint32_t ___val, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.NumberFormatter System.NumberFormatter::GetInstance()
extern "C"  NumberFormatter_t404647590_0 * NumberFormatter_GetInstance_m1116912880_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::Release()
extern "C"  void NumberFormatter_Release_m_1976759147_0 (NumberFormatter_t404647590_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::SetThreadCurrentCulture(System.Globalization.CultureInfo)
extern "C"  void NumberFormatter_SetThreadCurrentCulture_m27395807_0 (Object_t * __this /* static, unused */, CultureInfo_t_1039475404_0 * ___culture, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::NumberToString(System.String,System.SByte,System.IFormatProvider)
extern "C"  String_t* NumberFormatter_NumberToString_m1767037120_0 (Object_t * __this /* static, unused */, String_t* ___format, int8_t ___value, Object_t * ___fp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::NumberToString(System.String,System.Byte,System.IFormatProvider)
extern "C"  String_t* NumberFormatter_NumberToString_m_562386567_0 (Object_t * __this /* static, unused */, String_t* ___format, uint8_t ___value, Object_t * ___fp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::NumberToString(System.String,System.UInt16,System.IFormatProvider)
extern "C"  String_t* NumberFormatter_NumberToString_m575932624_0 (Object_t * __this /* static, unused */, String_t* ___format, uint16_t ___value, Object_t * ___fp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::NumberToString(System.String,System.Int16,System.IFormatProvider)
extern "C"  String_t* NumberFormatter_NumberToString_m1355610105_0 (Object_t * __this /* static, unused */, String_t* ___format, int16_t ___value, Object_t * ___fp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::NumberToString(System.String,System.UInt32,System.IFormatProvider)
extern "C"  String_t* NumberFormatter_NumberToString_m356875018_0 (Object_t * __this /* static, unused */, String_t* ___format, uint32_t ___value, Object_t * ___fp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::NumberToString(System.String,System.Int32,System.IFormatProvider)
extern "C"  String_t* NumberFormatter_NumberToString_m1136552499_0 (Object_t * __this /* static, unused */, String_t* ___format, int32_t ___value, Object_t * ___fp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::NumberToString(System.String,System.UInt64,System.IFormatProvider)
extern "C"  String_t* NumberFormatter_NumberToString_m590483049_0 (Object_t * __this /* static, unused */, String_t* ___format, uint64_t ___value, Object_t * ___fp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::NumberToString(System.String,System.Int64,System.IFormatProvider)
extern "C"  String_t* NumberFormatter_NumberToString_m1370160530_0 (Object_t * __this /* static, unused */, String_t* ___format, int64_t ___value, Object_t * ___fp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::NumberToString(System.String,System.Single,System.IFormatProvider)
extern "C"  String_t* NumberFormatter_NumberToString_m332247865_0 (Object_t * __this /* static, unused */, String_t* ___format, float ___value, Object_t * ___fp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::NumberToString(System.String,System.Double,System.IFormatProvider)
extern "C"  String_t* NumberFormatter_NumberToString_m2024857538_0 (Object_t * __this /* static, unused */, String_t* ___format, double ___value, Object_t * ___fp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::NumberToString(System.String,System.Decimal,System.IFormatProvider)
extern "C"  String_t* NumberFormatter_NumberToString_m1355083638_0 (Object_t * __this /* static, unused */, String_t* ___format, Decimal_t1458036598_0  ___value, Object_t * ___fp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::NumberToString(System.UInt32,System.IFormatProvider)
extern "C"  String_t* NumberFormatter_NumberToString_m_850235322_0 (Object_t * __this /* static, unused */, uint32_t ___value, Object_t * ___fp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::NumberToString(System.Int32,System.IFormatProvider)
extern "C"  String_t* NumberFormatter_NumberToString_m266329463_0 (Object_t * __this /* static, unused */, int32_t ___value, Object_t * ___fp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::NumberToString(System.UInt64,System.IFormatProvider)
extern "C"  String_t* NumberFormatter_NumberToString_m_616627291_0 (Object_t * __this /* static, unused */, uint64_t ___value, Object_t * ___fp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::NumberToString(System.Int64,System.IFormatProvider)
extern "C"  String_t* NumberFormatter_NumberToString_m499937494_0 (Object_t * __this /* static, unused */, int64_t ___value, Object_t * ___fp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::NumberToString(System.Single,System.IFormatProvider)
extern "C"  String_t* NumberFormatter_NumberToString_m_874862475_0 (Object_t * __this /* static, unused */, float ___value, Object_t * ___fp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::NumberToString(System.Double,System.IFormatProvider)
extern "C"  String_t* NumberFormatter_NumberToString_m817747198_0 (Object_t * __this /* static, unused */, double ___value, Object_t * ___fp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::FastIntegerToString(System.Int32,System.IFormatProvider)
extern "C"  String_t* NumberFormatter_FastIntegerToString_m2015857610_0 (NumberFormatter_t404647590_0 * __this, int32_t ___value, Object_t * ___fp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::IntegerToString(System.String,System.IFormatProvider)
extern "C"  String_t* NumberFormatter_IntegerToString_m_1378545337_0 (NumberFormatter_t404647590_0 * __this, String_t* ___format, Object_t * ___fp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::NumberToString(System.String,System.Globalization.NumberFormatInfo)
extern "C"  String_t* NumberFormatter_NumberToString_m913039240_0 (NumberFormatter_t404647590_0 * __this, String_t* ___format, NumberFormatInfo_t746228406_0 * ___nfi, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::FormatCurrency(System.Int32,System.Globalization.NumberFormatInfo)
extern "C"  String_t* NumberFormatter_FormatCurrency_m852663042_0 (NumberFormatter_t404647590_0 * __this, int32_t ___precision, NumberFormatInfo_t746228406_0 * ___nfi, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::FormatDecimal(System.Int32,System.Globalization.NumberFormatInfo)
extern "C"  String_t* NumberFormatter_FormatDecimal_m1996938888_0 (NumberFormatter_t404647590_0 * __this, int32_t ___precision, NumberFormatInfo_t746228406_0 * ___nfi, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::FormatHexadecimal(System.Int32)
extern "C"  String_t* NumberFormatter_FormatHexadecimal_m386310032_0 (NumberFormatter_t404647590_0 * __this, int32_t ___precision, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::FormatFixedPoint(System.Int32,System.Globalization.NumberFormatInfo)
extern "C"  String_t* NumberFormatter_FormatFixedPoint_m336450221_0 (NumberFormatter_t404647590_0 * __this, int32_t ___precision, NumberFormatInfo_t746228406_0 * ___nfi, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::FormatRoundtrip(System.Double,System.Globalization.NumberFormatInfo)
extern "C"  String_t* NumberFormatter_FormatRoundtrip_m_727234259_0 (NumberFormatter_t404647590_0 * __this, double ___origval, NumberFormatInfo_t746228406_0 * ___nfi, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::FormatRoundtrip(System.Single,System.Globalization.NumberFormatInfo)
extern "C"  String_t* NumberFormatter_FormatRoundtrip_m850933974_0 (NumberFormatter_t404647590_0 * __this, float ___origval, NumberFormatInfo_t746228406_0 * ___nfi, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::FormatGeneral(System.Int32,System.Globalization.NumberFormatInfo)
extern "C"  String_t* NumberFormatter_FormatGeneral_m273745567_0 (NumberFormatter_t404647590_0 * __this, int32_t ___precision, NumberFormatInfo_t746228406_0 * ___nfi, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::FormatNumber(System.Int32,System.Globalization.NumberFormatInfo)
extern "C"  String_t* NumberFormatter_FormatNumber_m_1394951814_0 (NumberFormatter_t404647590_0 * __this, int32_t ___precision, NumberFormatInfo_t746228406_0 * ___nfi, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::FormatPercent(System.Int32,System.Globalization.NumberFormatInfo)
extern "C"  String_t* NumberFormatter_FormatPercent_m_561291908_0 (NumberFormatter_t404647590_0 * __this, int32_t ___precision, NumberFormatInfo_t746228406_0 * ___nfi, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::FormatExponential(System.Int32,System.Globalization.NumberFormatInfo)
extern "C"  String_t* NumberFormatter_FormatExponential_m_791707396_0 (NumberFormatter_t404647590_0 * __this, int32_t ___precision, NumberFormatInfo_t746228406_0 * ___nfi, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::FormatExponential(System.Int32,System.Globalization.NumberFormatInfo,System.Int32)
extern "C"  String_t* NumberFormatter_FormatExponential_m1641420123_0 (NumberFormatter_t404647590_0 * __this, int32_t ___precision, NumberFormatInfo_t746228406_0 * ___nfi, int32_t ___expDigits, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.NumberFormatter::FormatCustom(System.String,System.Globalization.NumberFormatInfo)
extern "C"  String_t* NumberFormatter_FormatCustom_m619514485_0 (NumberFormatter_t404647590_0 * __this, String_t* ___format, NumberFormatInfo_t746228406_0 * ___nfi, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::ZeroTrimEnd(System.Text.StringBuilder,System.Boolean)
extern "C"  void NumberFormatter_ZeroTrimEnd_m858705010_0 (Object_t * __this /* static, unused */, StringBuilder_t586045924_0 * ___sb, bool ___canEmpty, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.NumberFormatter::IsZeroOnly(System.Text.StringBuilder)
extern "C"  bool NumberFormatter_IsZeroOnly_m898090390_0 (Object_t * __this /* static, unused */, StringBuilder_t586045924_0 * ___sb, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::AppendNonNegativeNumber(System.Text.StringBuilder,System.Int32)
extern "C"  void NumberFormatter_AppendNonNegativeNumber_m_1126354420_0 (Object_t * __this /* static, unused */, StringBuilder_t586045924_0 * ___sb, int32_t ___v, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::AppendIntegerString(System.Int32,System.Text.StringBuilder)
extern "C"  void NumberFormatter_AppendIntegerString_m666371448_0 (NumberFormatter_t404647590_0 * __this, int32_t ___minLength, StringBuilder_t586045924_0 * ___sb, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::AppendIntegerString(System.Int32)
extern "C"  void NumberFormatter_AppendIntegerString_m_1816870828_0 (NumberFormatter_t404647590_0 * __this, int32_t ___minLength, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::AppendDecimalString(System.Int32,System.Text.StringBuilder)
extern "C"  void NumberFormatter_AppendDecimalString_m1754328651_0 (NumberFormatter_t404647590_0 * __this, int32_t ___precision, StringBuilder_t586045924_0 * ___sb, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::AppendDecimalString(System.Int32)
extern "C"  void NumberFormatter_AppendDecimalString_m_456553753_0 (NumberFormatter_t404647590_0 * __this, int32_t ___precision, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::AppendIntegerStringWithGroupSeparator(System.Int32[],System.String)
extern "C"  void NumberFormatter_AppendIntegerStringWithGroupSeparator_m_146162854_0 (NumberFormatter_t404647590_0 * __this, Int32U5BU5D_t1872284309_0* ___groups, String_t* ___groupSeparator, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::AppendExponent(System.Globalization.NumberFormatInfo,System.Int32,System.Int32)
extern "C"  void NumberFormatter_AppendExponent_m163214555_0 (NumberFormatter_t404647590_0 * __this, NumberFormatInfo_t746228406_0 * ___nfi, int32_t ___exponent, int32_t ___minDigits, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::AppendOneDigit(System.Int32)
extern "C"  void NumberFormatter_AppendOneDigit_m_247346106_0 (NumberFormatter_t404647590_0 * __this, int32_t ___start, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::FastAppendDigits(System.Int32,System.Boolean)
extern "C"  void NumberFormatter_FastAppendDigits_m_162042468_0 (NumberFormatter_t404647590_0 * __this, int32_t ___val, bool ___force, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::AppendDigits(System.Int32,System.Int32)
extern "C"  void NumberFormatter_AppendDigits_m_533434062_0 (NumberFormatter_t404647590_0 * __this, int32_t ___start, int32_t ___end, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::AppendDigits(System.Int32,System.Int32,System.Text.StringBuilder)
extern "C"  void NumberFormatter_AppendDigits_m860372182_0 (NumberFormatter_t404647590_0 * __this, int32_t ___start, int32_t ___end, StringBuilder_t586045924_0 * ___sb, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::Multiply10(System.Int32)
extern "C"  void NumberFormatter_Multiply10_m_29894168_0 (NumberFormatter_t404647590_0 * __this, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.NumberFormatter::Divide10(System.Int32)
extern "C"  void NumberFormatter_Divide10_m1709051645_0 (NumberFormatter_t404647590_0 * __this, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.NumberFormatter System.NumberFormatter::GetClone()
extern "C"  NumberFormatter_t404647590_0 * NumberFormatter_GetClone_m_1763123004_0 (NumberFormatter_t404647590_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
