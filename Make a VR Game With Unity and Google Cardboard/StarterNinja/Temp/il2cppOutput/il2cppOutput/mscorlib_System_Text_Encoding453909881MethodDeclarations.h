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

// System.Text.Encoding
struct Encoding_t453909881_0;
// System.String
struct String_t;
// System.Text.DecoderFallback
struct DecoderFallback_t798682208_0;
// System.Text.EncoderFallback
struct EncoderFallback_t2051173688_0;
// System.Object
struct Object_t;
// System.Char[]
struct CharU5BU5D_t_1225802637_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Text.Decoder
struct Decoder_t_2100355234_0;
// System.Object[]
struct ObjectU5BU5D_t1774424924_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Text.Encoding::.ctor()
extern "C"  void Encoding__ctor_m1037401021_0 (Encoding_t453909881_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.Encoding::.ctor(System.Int32)
extern "C"  void Encoding__ctor_m1203666318_0 (Encoding_t453909881_0 * __this, int32_t ___codePage, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.Encoding::.cctor()
extern "C"  void Encoding__cctor_m1612564368_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Text.Encoding::_(System.String)
extern "C"  String_t* Encoding___m_2147456949_0 (Object_t * __this /* static, unused */, String_t* ___arg, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.Encoding::get_IsReadOnly()
extern "C"  bool Encoding_get_IsReadOnly_m1827016926_0 (Encoding_t453909881_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.DecoderFallback System.Text.Encoding::get_DecoderFallback()
extern "C"  DecoderFallback_t798682208_0 * Encoding_get_DecoderFallback_m_885765175_0 (Encoding_t453909881_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.Encoding::set_DecoderFallback(System.Text.DecoderFallback)
extern "C"  void Encoding_set_DecoderFallback_m_766983510_0 (Encoding_t453909881_0 * __this, DecoderFallback_t798682208_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.EncoderFallback System.Text.Encoding::get_EncoderFallback()
extern "C"  EncoderFallback_t2051173688_0 * Encoding_get_EncoderFallback_m252351353_0 (Encoding_t453909881_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.Encoding::SetFallbackInternal(System.Text.EncoderFallback,System.Text.DecoderFallback)
extern "C"  void Encoding_SetFallbackInternal_m1712004450_0 (Encoding_t453909881_0 * __this, EncoderFallback_t2051173688_0 * ___e, DecoderFallback_t798682208_0 * ___d, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.Encoding::Equals(System.Object)
extern "C"  bool Encoding_Equals_m_1027605844_0 (Encoding_t453909881_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.Encoding::GetByteCount(System.String)
extern "C"  int32_t Encoding_GetByteCount_m_433004658_0 (Encoding_t453909881_0 * __this, String_t* ___s, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.Encoding::GetByteCount(System.Char[])
extern "C"  int32_t Encoding_GetByteCount_m_2107161785_0 (Encoding_t453909881_0 * __this, CharU5BU5D_t_1225802637_0* ___chars, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.Encoding::GetBytes(System.String,System.Int32,System.Int32,System.Byte[],System.Int32)
extern "C"  int32_t Encoding_GetBytes_m_1884996598_0 (Encoding_t453909881_0 * __this, String_t* ___s, int32_t ___charIndex, int32_t ___charCount, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___byteIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Text.Encoding::GetBytes(System.String)
extern "C"  ByteU5BU5D_t_1238178395_0* Encoding_GetBytes_m_1662823492_0 (Encoding_t453909881_0 * __this, String_t* ___s, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Text.Encoding::GetBytes(System.Char[],System.Int32,System.Int32)
extern "C"  ByteU5BU5D_t_1238178395_0* Encoding_GetBytes_m_1525582699_0 (Encoding_t453909881_0 * __this, CharU5BU5D_t_1225802637_0* ___chars, int32_t ___index, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Text.Encoding::GetBytes(System.Char[])
extern "C"  ByteU5BU5D_t_1238178395_0* Encoding_GetBytes_m957986677_0 (Encoding_t453909881_0 * __this, CharU5BU5D_t_1225802637_0* ___chars, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Char[] System.Text.Encoding::GetChars(System.Byte[],System.Int32,System.Int32)
extern "C"  CharU5BU5D_t_1225802637_0* Encoding_GetChars_m468469183_0 (Encoding_t453909881_0 * __this, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___index, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.Decoder System.Text.Encoding::GetDecoder()
extern "C"  Decoder_t_2100355234_0 * Encoding_GetDecoder_m_614321210_0 (Encoding_t453909881_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Text.Encoding::InvokeI18N(System.String,System.Object[])
extern "C"  Object_t * Encoding_InvokeI18N_m_1481803012_0 (Object_t * __this /* static, unused */, String_t* ___name, ObjectU5BU5D_t1774424924_0* ___args, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.Encoding System.Text.Encoding::GetEncoding(System.Int32)
extern "C"  Encoding_t453909881_0 * Encoding_GetEncoding_m_1408085217_0 (Object_t * __this /* static, unused */, int32_t ___codepage, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Text.Encoding::Clone()
extern "C"  Object_t * Encoding_Clone_m_137237341_0 (Encoding_t453909881_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.Encoding System.Text.Encoding::GetEncoding(System.String)
extern "C"  Encoding_t453909881_0 * Encoding_GetEncoding_m_244270348_0 (Object_t * __this /* static, unused */, String_t* ___name, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.Encoding::GetHashCode()
extern "C"  int32_t Encoding_GetHashCode_m_1857884912_0 (Encoding_t453909881_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Text.Encoding::GetPreamble()
extern "C"  ByteU5BU5D_t_1238178395_0* Encoding_GetPreamble_m1160659539_0 (Encoding_t453909881_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Text.Encoding::GetString(System.Byte[],System.Int32,System.Int32)
extern "C"  String_t* Encoding_GetString_m565750122_0 (Encoding_t453909881_0 * __this, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___index, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Text.Encoding::GetString(System.Byte[])
extern "C"  String_t* Encoding_GetString_m_486880118_0 (Encoding_t453909881_0 * __this, ByteU5BU5D_t_1238178395_0* ___bytes, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.Encoding System.Text.Encoding::get_ASCII()
extern "C"  Encoding_t453909881_0 * Encoding_get_ASCII_m1425378925_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.Encoding System.Text.Encoding::get_BigEndianUnicode()
extern "C"  Encoding_t453909881_0 * Encoding_get_BigEndianUnicode_m1578127592_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Text.Encoding::InternalCodePage(System.Int32&)
extern "C"  String_t* Encoding_InternalCodePage_m1810234872_0 (Object_t * __this /* static, unused */, int32_t* ___code_page, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.Encoding System.Text.Encoding::get_Default()
extern "C"  Encoding_t453909881_0 * Encoding_get_Default_m1600689821_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.Encoding System.Text.Encoding::get_ISOLatin1()
extern "C"  Encoding_t453909881_0 * Encoding_get_ISOLatin1_m_159687698_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.Encoding System.Text.Encoding::get_UTF7()
extern "C"  Encoding_t453909881_0 * Encoding_get_UTF7_m619557558_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.Encoding System.Text.Encoding::get_UTF8()
extern "C"  Encoding_t453909881_0 * Encoding_get_UTF8_m619558519_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.Encoding System.Text.Encoding::get_UTF8Unmarked()
extern "C"  Encoding_t453909881_0 * Encoding_get_UTF8Unmarked_m1891261276_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.Encoding System.Text.Encoding::get_UTF8UnmarkedUnsafe()
extern "C"  Encoding_t453909881_0 * Encoding_get_UTF8UnmarkedUnsafe_m_1519495326_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.Encoding System.Text.Encoding::get_Unicode()
extern "C"  Encoding_t453909881_0 * Encoding_get_Unicode_m_2136832967_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.Encoding System.Text.Encoding::get_UTF32()
extern "C"  Encoding_t453909881_0 * Encoding_get_UTF32_m2026305570_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.Encoding System.Text.Encoding::get_BigEndianUTF32()
extern "C"  Encoding_t453909881_0 * Encoding_get_BigEndianUTF32_m_615635823_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.Encoding::GetByteCount(System.Char*,System.Int32)
extern "C"  int32_t Encoding_GetByteCount_m957110328_0 (Encoding_t453909881_0 * __this, uint16_t* ___chars, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.Encoding::GetBytes(System.Char*,System.Int32,System.Byte*,System.Int32)
extern "C"  int32_t Encoding_GetBytes_m1804873512_0 (Encoding_t453909881_0 * __this, uint16_t* ___chars, int32_t ___charCount, uint8_t* ___bytes, int32_t ___byteCount, const MethodInfo* method) IL2CPP_METHOD_ATTR;
