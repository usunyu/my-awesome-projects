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

// System.Globalization.TextInfo
struct TextInfo_t_2130369341_0;
// System.Globalization.CultureInfo
struct CultureInfo_t_1039475404_0;
// System.Object
struct Object_t;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Void_224166001.h"

// System.Void System.Globalization.TextInfo::.ctor(System.Globalization.CultureInfo,System.Int32,System.Void*,System.Boolean)
extern "C"  void TextInfo__ctor_m_892814168_0 (TextInfo_t_2130369341_0 * __this, CultureInfo_t_1039475404_0 * ___ci, int32_t ___lcid, void* ___data, bool ___read_only, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Globalization.TextInfo::.ctor(System.Globalization.TextInfo)
extern "C"  void TextInfo__ctor_m100037022_0 (TextInfo_t_2130369341_0 * __this, TextInfo_t_2130369341_0 * ___textInfo, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Globalization.TextInfo::System.Runtime.Serialization.IDeserializationCallback.OnDeserialization(System.Object)
extern "C"  void TextInfo_System_Runtime_Serialization_IDeserializationCallback_OnDeserialization_m_552738583_0 (TextInfo_t_2130369341_0 * __this, Object_t * ___sender, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.TextInfo::get_ListSeparator()
extern "C"  String_t* TextInfo_get_ListSeparator_m_590840212_0 (TextInfo_t_2130369341_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.TextInfo::get_CultureName()
extern "C"  String_t* TextInfo_get_CultureName_m346063966_0 (TextInfo_t_2130369341_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Globalization.TextInfo::Equals(System.Object)
extern "C"  bool TextInfo_Equals_m_2012502752_0 (TextInfo_t_2130369341_0 * __this, Object_t * ___obj, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Globalization.TextInfo::GetHashCode()
extern "C"  int32_t TextInfo_GetHashCode_m265055480_0 (TextInfo_t_2130369341_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.TextInfo::ToString()
extern "C"  String_t* TextInfo_ToString_m2104789920_0 (TextInfo_t_2130369341_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Char System.Globalization.TextInfo::ToLower(System.Char)
extern "C"  uint16_t TextInfo_ToLower_m_160434002_0 (TextInfo_t_2130369341_0 * __this, uint16_t ___c, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Char System.Globalization.TextInfo::ToUpper(System.Char)
extern "C"  uint16_t TextInfo_ToUpper_m87931053_0 (TextInfo_t_2130369341_0 * __this, uint16_t ___c, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.TextInfo::ToLower(System.String)
extern "C"  String_t* TextInfo_ToLower_m1323104334_0 (TextInfo_t_2130369341_0 * __this, String_t* ___str, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Globalization.TextInfo::Clone()
extern "C"  Object_t * TextInfo_Clone_m_1498150435_0 (TextInfo_t_2130369341_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
