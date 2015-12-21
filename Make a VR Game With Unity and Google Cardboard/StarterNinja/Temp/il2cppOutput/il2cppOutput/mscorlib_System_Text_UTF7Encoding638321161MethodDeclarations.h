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

// System.Text.UTF7Encoding
struct UTF7Encoding_t638321161_0;
// System.Object
struct Object_t;
// System.Char[]
struct CharU5BU5D_t_1225802637_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Text.Decoder
struct Decoder_t_2100355234_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Text.UTF7Encoding::.ctor()
extern "C"  void UTF7Encoding__ctor_m_1075628115_0 (UTF7Encoding_t638321161_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.UTF7Encoding::.ctor(System.Boolean)
extern "C"  void UTF7Encoding__ctor_m_1775994268_0 (UTF7Encoding_t638321161_0 * __this, bool ___allowOptionals, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.UTF7Encoding::.cctor()
extern "C"  void UTF7Encoding__cctor_m533170592_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UTF7Encoding::GetHashCode()
extern "C"  int32_t UTF7Encoding_GetHashCode_m_512089344_0 (UTF7Encoding_t638321161_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.UTF7Encoding::Equals(System.Object)
extern "C"  bool UTF7Encoding_Equals_m85066652_0 (UTF7Encoding_t638321161_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UTF7Encoding::InternalGetByteCount(System.Char[],System.Int32,System.Int32,System.Boolean,System.Int32,System.Boolean,System.Boolean)
extern "C"  int32_t UTF7Encoding_InternalGetByteCount_m_1601386508_0 (Object_t * __this /* static, unused */, CharU5BU5D_t_1225802637_0* ___chars, int32_t ___index, int32_t ___count, bool ___flush, int32_t ___leftOver, bool ___isInShifted, bool ___allowOptionals, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UTF7Encoding::GetByteCount(System.Char[],System.Int32,System.Int32)
extern "C"  int32_t UTF7Encoding_GetByteCount_m1291682775_0 (UTF7Encoding_t638321161_0 * __this, CharU5BU5D_t_1225802637_0* ___chars, int32_t ___index, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UTF7Encoding::InternalGetBytes(System.Char[],System.Int32,System.Int32,System.Byte[],System.Int32,System.Boolean,System.Int32&,System.Boolean&,System.Boolean)
extern "C"  int32_t UTF7Encoding_InternalGetBytes_m_547161798_0 (Object_t * __this /* static, unused */, CharU5BU5D_t_1225802637_0* ___chars, int32_t ___charIndex, int32_t ___charCount, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___byteIndex, bool ___flush, int32_t* ___leftOver, bool* ___isInShifted, bool ___allowOptionals, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UTF7Encoding::GetBytes(System.Char[],System.Int32,System.Int32,System.Byte[],System.Int32)
extern "C"  int32_t UTF7Encoding_GetBytes_m_1095825919_0 (UTF7Encoding_t638321161_0 * __this, CharU5BU5D_t_1225802637_0* ___chars, int32_t ___charIndex, int32_t ___charCount, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___byteIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UTF7Encoding::InternalGetCharCount(System.Byte[],System.Int32,System.Int32,System.Int32)
extern "C"  int32_t UTF7Encoding_InternalGetCharCount_m_1967697887_0 (Object_t * __this /* static, unused */, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___index, int32_t ___count, int32_t ___leftOver, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UTF7Encoding::GetCharCount(System.Byte[],System.Int32,System.Int32)
extern "C"  int32_t UTF7Encoding_GetCharCount_m93095219_0 (UTF7Encoding_t638321161_0 * __this, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___index, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UTF7Encoding::InternalGetChars(System.Byte[],System.Int32,System.Int32,System.Char[],System.Int32,System.Int32&)
extern "C"  int32_t UTF7Encoding_InternalGetChars_m504744357_0 (Object_t * __this /* static, unused */, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___byteIndex, int32_t ___byteCount, CharU5BU5D_t_1225802637_0* ___chars, int32_t ___charIndex, int32_t* ___leftOver, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UTF7Encoding::GetChars(System.Byte[],System.Int32,System.Int32,System.Char[],System.Int32)
extern "C"  int32_t UTF7Encoding_GetChars_m1244424819_0 (UTF7Encoding_t638321161_0 * __this, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___byteIndex, int32_t ___byteCount, CharU5BU5D_t_1225802637_0* ___chars, int32_t ___charIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UTF7Encoding::GetMaxByteCount(System.Int32)
extern "C"  int32_t UTF7Encoding_GetMaxByteCount_m_1105253351_0 (UTF7Encoding_t638321161_0 * __this, int32_t ___charCount, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UTF7Encoding::GetMaxCharCount(System.Int32)
extern "C"  int32_t UTF7Encoding_GetMaxCharCount_m_313718005_0 (UTF7Encoding_t638321161_0 * __this, int32_t ___byteCount, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.Decoder System.Text.UTF7Encoding::GetDecoder()
extern "C"  Decoder_t_2100355234_0 * UTF7Encoding_GetDecoder_m292232534_0 (UTF7Encoding_t638321161_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UTF7Encoding::GetByteCount(System.Char*,System.Int32)
extern "C"  int32_t UTF7Encoding_GetByteCount_m_1493499352_0 (UTF7Encoding_t638321161_0 * __this, uint16_t* ___chars, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UTF7Encoding::GetByteCount(System.String)
extern "C"  int32_t UTF7Encoding_GetByteCount_m_1260719746_0 (UTF7Encoding_t638321161_0 * __this, String_t* ___s, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UTF7Encoding::GetBytes(System.Char*,System.Int32,System.Byte*,System.Int32)
extern "C"  int32_t UTF7Encoding_GetBytes_m_542259944_0 (UTF7Encoding_t638321161_0 * __this, uint16_t* ___chars, int32_t ___charCount, uint8_t* ___bytes, int32_t ___byteCount, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.UTF7Encoding::GetBytes(System.String,System.Int32,System.Int32,System.Byte[],System.Int32)
extern "C"  int32_t UTF7Encoding_GetBytes_m_1521547238_0 (UTF7Encoding_t638321161_0 * __this, String_t* ___s, int32_t ___charIndex, int32_t ___charCount, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___byteIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Text.UTF7Encoding::GetString(System.Byte[],System.Int32,System.Int32)
extern "C"  String_t* UTF7Encoding_GetString_m138259962_0 (UTF7Encoding_t638321161_0 * __this, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___index, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
