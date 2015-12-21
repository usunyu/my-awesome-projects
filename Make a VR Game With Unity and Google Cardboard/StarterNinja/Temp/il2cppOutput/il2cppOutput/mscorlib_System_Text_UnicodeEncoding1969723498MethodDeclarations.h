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

// System.Text.UnicodeEncoding
struct UnicodeEncoding_t1969723498_0;
// System.Char[]
struct CharU5BU5D_t_1225802637_0;
// System.String
struct String_t;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Text.Decoder
struct Decoder_t_2100355234_0;
// System.Object
struct Object_t;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Text.UnicodeEncoding::.ctor()
extern "C"  void UnicodeEncoding__ctor_m_1830120602_0 (UnicodeEncoding_t1969723498_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.UnicodeEncoding::.ctor(System.Boolean,System.Boolean)
extern "C"  void UnicodeEncoding__ctor_m628477824_0 (UnicodeEncoding_t1969723498_0 * __this, bool ___bigEndian, bool ___byteOrderMark, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.UnicodeEncoding::.ctor(System.Boolean,System.Boolean,System.Boolean)
extern "C"  void UnicodeEncoding__ctor_m1753322493_0 (UnicodeEncoding_t1969723498_0 * __this, bool ___bigEndian, bool ___byteOrderMark, bool ___throwOnInvalidBytes, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UnicodeEncoding::GetByteCount(System.Char[],System.Int32,System.Int32)
extern "C"  int32_t UnicodeEncoding_GetByteCount_m1713744008_0 (UnicodeEncoding_t1969723498_0 * __this, CharU5BU5D_t_1225802637_0* ___chars, int32_t ___index, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UnicodeEncoding::GetByteCount(System.String)
extern "C"  int32_t UnicodeEncoding_GetByteCount_m_341110417_0 (UnicodeEncoding_t1969723498_0 * __this, String_t* ___s, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UnicodeEncoding::GetByteCount(System.Char*,System.Int32)
extern "C"  int32_t UnicodeEncoding_GetByteCount_m_1930575719_0 (UnicodeEncoding_t1969723498_0 * __this, uint16_t* ___chars, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UnicodeEncoding::GetBytes(System.Char[],System.Int32,System.Int32,System.Byte[],System.Int32)
extern "C"  int32_t UnicodeEncoding_GetBytes_m1303521840_0 (UnicodeEncoding_t1969723498_0 * __this, CharU5BU5D_t_1225802637_0* ___chars, int32_t ___charIndex, int32_t ___charCount, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___byteIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UnicodeEncoding::GetBytes(System.String,System.Int32,System.Int32,System.Byte[],System.Int32)
extern "C"  int32_t UnicodeEncoding_GetBytes_m877800521_0 (UnicodeEncoding_t1969723498_0 * __this, String_t* ___s, int32_t ___charIndex, int32_t ___charCount, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___byteIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UnicodeEncoding::GetBytes(System.Char*,System.Int32,System.Byte*,System.Int32)
extern "C"  int32_t UnicodeEncoding_GetBytes_m1942137033_0 (UnicodeEncoding_t1969723498_0 * __this, uint16_t* ___chars, int32_t ___charCount, uint8_t* ___bytes, int32_t ___byteCount, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UnicodeEncoding::GetBytesInternal(System.Char*,System.Int32,System.Byte*,System.Int32)
extern "C"  int32_t UnicodeEncoding_GetBytesInternal_m_1079598068_0 (UnicodeEncoding_t1969723498_0 * __this, uint16_t* ___chars, int32_t ___charCount, uint8_t* ___bytes, int32_t ___byteCount, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UnicodeEncoding::GetCharCount(System.Byte[],System.Int32,System.Int32)
extern "C"  int32_t UnicodeEncoding_GetCharCount_m515156452_0 (UnicodeEncoding_t1969723498_0 * __this, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___index, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UnicodeEncoding::GetChars(System.Byte[],System.Int32,System.Int32,System.Char[],System.Int32)
extern "C"  int32_t UnicodeEncoding_GetChars_m_651194718_0 (UnicodeEncoding_t1969723498_0 * __this, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___byteIndex, int32_t ___byteCount, CharU5BU5D_t_1225802637_0* ___chars, int32_t ___charIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Text.UnicodeEncoding::GetString(System.Byte[],System.Int32,System.Int32)
extern "C"  String_t* UnicodeEncoding_GetString_m254667515_0 (UnicodeEncoding_t1969723498_0 * __this, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___index, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UnicodeEncoding::GetCharsInternal(System.Byte*,System.Int32,System.Char*,System.Int32)
extern "C"  int32_t UnicodeEncoding_GetCharsInternal_m801541210_0 (UnicodeEncoding_t1969723498_0 * __this, uint8_t* ___bytes, int32_t ___byteCount, uint16_t* ___chars, int32_t ___charCount, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UnicodeEncoding::GetMaxByteCount(System.Int32)
extern "C"  int32_t UnicodeEncoding_GetMaxByteCount_m_2123951158_0 (UnicodeEncoding_t1969723498_0 * __this, int32_t ___charCount, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UnicodeEncoding::GetMaxCharCount(System.Int32)
extern "C"  int32_t UnicodeEncoding_GetMaxCharCount_m_1332415812_0 (UnicodeEncoding_t1969723498_0 * __this, int32_t ___byteCount, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.Decoder System.Text.UnicodeEncoding::GetDecoder()
extern "C"  Decoder_t_2100355234_0 * UnicodeEncoding_GetDecoder_m_833792773_0 (UnicodeEncoding_t1969723498_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Text.UnicodeEncoding::GetPreamble()
extern "C"  ByteU5BU5D_t_1238178395_0* UnicodeEncoding_GetPreamble_m_2039444400_0 (UnicodeEncoding_t1969723498_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.UnicodeEncoding::Equals(System.Object)
extern "C"  bool UnicodeEncoding_Equals_m258981209_0 (UnicodeEncoding_t1969723498_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UnicodeEncoding::GetHashCode()
extern "C"  int32_t UnicodeEncoding_GetHashCode_m_1589539663_0 (UnicodeEncoding_t1969723498_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.UnicodeEncoding::CopyChars(System.Byte*,System.Byte*,System.Int32,System.Boolean)
extern "C"  void UnicodeEncoding_CopyChars_m137508992_0 (Object_t * __this /* static, unused */, uint8_t* ___src, uint8_t* ___dest, int32_t ___count, bool ___bigEndian, const MethodInfo* method) IL2CPP_METHOD_ATTR;
