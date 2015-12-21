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

// System.Globalization.CultureInfo
struct CultureInfo_t_1039475404_0;
// System.String
struct String_t;
// System.Globalization.TextInfo
struct TextInfo_t_2130369341_0;
// System.Object
struct Object_t;
// System.Globalization.CompareInfo
struct CompareInfo_t_619360021_0;
// System.Globalization.NumberFormatInfo
struct NumberFormatInfo_t746228406_0;
// System.Globalization.DateTimeFormatInfo
struct DateTimeFormatInfo_t_147657080_0;
// System.Type
struct Type_t;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Globalization.CultureInfo::.ctor(System.Int32)
extern "C"  void CultureInfo__ctor_m_310776781_0 (CultureInfo_t_1039475404_0 * __this, int32_t ___culture, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Globalization.CultureInfo::.ctor(System.Int32,System.Boolean)
extern "C"  void CultureInfo__ctor_m_985654550_0 (CultureInfo_t_1039475404_0 * __this, int32_t ___culture, bool ___useUserOverride, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Globalization.CultureInfo::.ctor(System.Int32,System.Boolean,System.Boolean)
extern "C"  void CultureInfo__ctor_m501073747_0 (CultureInfo_t_1039475404_0 * __this, int32_t ___culture, bool ___useUserOverride, bool ___read_only, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Globalization.CultureInfo::.ctor(System.String,System.Boolean,System.Boolean)
extern "C"  void CultureInfo__ctor_m799101632_0 (CultureInfo_t_1039475404_0 * __this, String_t* ___name, bool ___useUserOverride, bool ___read_only, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Globalization.CultureInfo::.ctor()
extern "C"  void CultureInfo__ctor_m_1855063582_0 (CultureInfo_t_1039475404_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Globalization.CultureInfo::.cctor()
extern "C"  void CultureInfo__cctor_m2140474891_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.CultureInfo System.Globalization.CultureInfo::get_InvariantCulture()
extern "C"  CultureInfo_t_1039475404_0 * CultureInfo_get_InvariantCulture_m764001524_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.CultureInfo System.Globalization.CultureInfo::get_CurrentCulture()
extern "C"  CultureInfo_t_1039475404_0 * CultureInfo_get_CurrentCulture_m_1389468517_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.CultureInfo System.Globalization.CultureInfo::get_CurrentUICulture()
extern "C"  CultureInfo_t_1039475404_0 * CultureInfo_get_CurrentUICulture_m1742589319_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.CultureInfo System.Globalization.CultureInfo::ConstructCurrentCulture()
extern "C"  CultureInfo_t_1039475404_0 * CultureInfo_ConstructCurrentCulture_m_1202060271_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.CultureInfo System.Globalization.CultureInfo::ConstructCurrentUICulture()
extern "C"  CultureInfo_t_1039475404_0 * CultureInfo_ConstructCurrentUICulture_m1453287293_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Globalization.CultureInfo::get_LCID()
extern "C"  int32_t CultureInfo_get_LCID_m1645560313_0 (CultureInfo_t_1039475404_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.CultureInfo::get_Name()
extern "C"  String_t* CultureInfo_get_Name_m1067687641_0 (CultureInfo_t_1039475404_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.CultureInfo System.Globalization.CultureInfo::get_Parent()
extern "C"  CultureInfo_t_1039475404_0 * CultureInfo_get_Parent_m451838736_0 (CultureInfo_t_1039475404_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.TextInfo System.Globalization.CultureInfo::get_TextInfo()
extern "C"  TextInfo_t_2130369341_0 * CultureInfo_get_TextInfo_m_870856526_0 (CultureInfo_t_1039475404_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.CultureInfo::get_IcuName()
extern "C"  String_t* CultureInfo_get_IcuName_m794066458_0 (CultureInfo_t_1039475404_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Globalization.CultureInfo::Clone()
extern "C"  Object_t * CultureInfo_Clone_m1893614152_0 (CultureInfo_t_1039475404_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Globalization.CultureInfo::Equals(System.Object)
extern "C"  bool CultureInfo_Equals_m_1483430127_0 (CultureInfo_t_1039475404_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Globalization.CultureInfo::GetHashCode()
extern "C"  int32_t CultureInfo_GetHashCode_m1389692277_0 (CultureInfo_t_1039475404_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.CultureInfo::ToString()
extern "C"  String_t* CultureInfo_ToString_m429412721_0 (CultureInfo_t_1039475404_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.CompareInfo System.Globalization.CultureInfo::get_CompareInfo()
extern "C"  CompareInfo_t_619360021_0 * CultureInfo_get_CompareInfo_m1894655206_0 (CultureInfo_t_1039475404_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Globalization.CultureInfo::get_IsNeutralCulture()
extern "C"  bool CultureInfo_get_IsNeutralCulture_m_1013949666_0 (CultureInfo_t_1039475404_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Globalization.CultureInfo::CheckNeutral()
extern "C"  void CultureInfo_CheckNeutral_m_1953666559_0 (CultureInfo_t_1039475404_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.NumberFormatInfo System.Globalization.CultureInfo::get_NumberFormat()
extern "C"  NumberFormatInfo_t746228406_0 * CultureInfo_get_NumberFormat_m149371268_0 (CultureInfo_t_1039475404_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Globalization.CultureInfo::set_NumberFormat(System.Globalization.NumberFormatInfo)
extern "C"  void CultureInfo_set_NumberFormat_m929801593_0 (CultureInfo_t_1039475404_0 * __this, NumberFormatInfo_t746228406_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.DateTimeFormatInfo System.Globalization.CultureInfo::get_DateTimeFormat()
extern "C"  DateTimeFormatInfo_t_147657080_0 * CultureInfo_get_DateTimeFormat_m1881597700_0 (CultureInfo_t_1039475404_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Globalization.CultureInfo::set_DateTimeFormat(System.Globalization.DateTimeFormatInfo)
extern "C"  void CultureInfo_set_DateTimeFormat_m1095763797_0 (CultureInfo_t_1039475404_0 * __this, DateTimeFormatInfo_t_147657080_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Globalization.CultureInfo::get_IsReadOnly()
extern "C"  bool CultureInfo_get_IsReadOnly_m_1141474983_0 (CultureInfo_t_1039475404_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Globalization.CultureInfo::GetFormat(System.Type)
extern "C"  Object_t * CultureInfo_GetFormat_m1536954785_0 (CultureInfo_t_1039475404_0 * __this, Type_t * ___formatType, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Globalization.CultureInfo::Construct()
extern "C"  void CultureInfo_Construct_m_1865870953_0 (CultureInfo_t_1039475404_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Globalization.CultureInfo::ConstructInternalLocaleFromName(System.String)
extern "C"  bool CultureInfo_ConstructInternalLocaleFromName_m_1215863103_0 (CultureInfo_t_1039475404_0 * __this, String_t* ___locale, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Globalization.CultureInfo::ConstructInternalLocaleFromLcid(System.Int32)
extern "C"  bool CultureInfo_ConstructInternalLocaleFromLcid_m332238777_0 (CultureInfo_t_1039475404_0 * __this, int32_t ___lcid, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Globalization.CultureInfo::ConstructInternalLocaleFromCurrentLocale(System.Globalization.CultureInfo)
extern "C"  bool CultureInfo_ConstructInternalLocaleFromCurrentLocale_m39643311_0 (Object_t * __this /* static, unused */, CultureInfo_t_1039475404_0 * ___ci, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Globalization.CultureInfo::construct_internal_locale_from_lcid(System.Int32)
extern "C"  bool CultureInfo_construct_internal_locale_from_lcid_m1451282539_0 (CultureInfo_t_1039475404_0 * __this, int32_t ___lcid, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Globalization.CultureInfo::construct_internal_locale_from_name(System.String)
extern "C"  bool CultureInfo_construct_internal_locale_from_name_m_885244849_0 (CultureInfo_t_1039475404_0 * __this, String_t* ___name, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Globalization.CultureInfo::construct_internal_locale_from_current_locale(System.Globalization.CultureInfo)
extern "C"  bool CultureInfo_construct_internal_locale_from_current_locale_m_1715779176_0 (Object_t * __this /* static, unused */, CultureInfo_t_1039475404_0 * ___ci, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Globalization.CultureInfo::construct_datetime_format()
extern "C"  void CultureInfo_construct_datetime_format_m650587571_0 (CultureInfo_t_1039475404_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Globalization.CultureInfo::construct_number_format()
extern "C"  void CultureInfo_construct_number_format_m650450789_0 (CultureInfo_t_1039475404_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Globalization.CultureInfo::ConstructInvariant(System.Boolean)
extern "C"  void CultureInfo_ConstructInvariant_m_1296609534_0 (CultureInfo_t_1039475404_0 * __this, bool ___read_only, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.TextInfo System.Globalization.CultureInfo::CreateTextInfo(System.Boolean)
extern "C"  TextInfo_t_2130369341_0 * CultureInfo_CreateTextInfo_m_1793599556_0 (CultureInfo_t_1039475404_0 * __this, bool ___readOnly, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.CultureInfo System.Globalization.CultureInfo::CreateCulture(System.String,System.Boolean)
extern "C"  CultureInfo_t_1039475404_0 * CultureInfo_CreateCulture_m_39731534_0 (Object_t * __this /* static, unused */, String_t* ___name, bool ___reference, const MethodInfo* method) IL2CPP_METHOD_ATTR;
