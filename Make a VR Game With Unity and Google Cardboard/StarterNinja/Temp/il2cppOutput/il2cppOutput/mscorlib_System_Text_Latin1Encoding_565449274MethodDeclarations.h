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

// System.Text.Latin1Encoding
struct Latin1Encoding_t_565449274_0;
// System.Char[]
struct CharU5BU5D_t_1225802637_0;
// System.String
struct String_t;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Text.EncoderFallbackBuffer
struct EncoderFallbackBuffer_t1369056152_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Text.Latin1Encoding::.ctor()
extern "C"  void Latin1Encoding__ctor_m1980938192_0 (Latin1Encoding_t_565449274_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.Latin1Encoding::GetByteCount(System.Char[],System.Int32,System.Int32)
extern "C"  int32_t Latin1Encoding_GetByteCount_m706721210_0 (Latin1Encoding_t_565449274_0 * __this, CharU5BU5D_t_1225802637_0* ___chars, int32_t ___index, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.Latin1Encoding::GetByteCount(System.String)
extern "C"  int32_t Latin1Encoding_GetByteCount_m_260425439_0 (Latin1Encoding_t_565449274_0 * __this, String_t* ___s, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.Latin1Encoding::GetBytes(System.Char[],System.Int32,System.Int32,System.Byte[],System.Int32)
extern "C"  int32_t Latin1Encoding_GetBytes_m_49847106_0 (Latin1Encoding_t_565449274_0 * __this, CharU5BU5D_t_1225802637_0* ___chars, int32_t ___charIndex, int32_t ___charCount, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___byteIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.Latin1Encoding::GetBytes(System.Char[],System.Int32,System.Int32,System.Byte[],System.Int32,System.Text.EncoderFallbackBuffer&,System.Char[]&)
extern "C"  int32_t Latin1Encoding_GetBytes_m_329589159_0 (Latin1Encoding_t_565449274_0 * __this, CharU5BU5D_t_1225802637_0* ___chars, int32_t ___charIndex, int32_t ___charCount, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___byteIndex, EncoderFallbackBuffer_t1369056152_0 ** ___buffer, CharU5BU5D_t_1225802637_0** ___fallback_chars, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.Latin1Encoding::GetBytes(System.String,System.Int32,System.Int32,System.Byte[],System.Int32)
extern "C"  int32_t Latin1Encoding_GetBytes_m_475568425_0 (Latin1Encoding_t_565449274_0 * __this, String_t* ___s, int32_t ___charIndex, int32_t ___charCount, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___byteIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.Latin1Encoding::GetBytes(System.String,System.Int32,System.Int32,System.Byte[],System.Int32,System.Text.EncoderFallbackBuffer&,System.Char[]&)
extern "C"  int32_t Latin1Encoding_GetBytes_m_1714665422_0 (Latin1Encoding_t_565449274_0 * __this, String_t* ___s, int32_t ___charIndex, int32_t ___charCount, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___byteIndex, EncoderFallbackBuffer_t1369056152_0 ** ___buffer, CharU5BU5D_t_1225802637_0** ___fallback_chars, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.Latin1Encoding::GetCharCount(System.Byte[],System.Int32,System.Int32)
extern "C"  int32_t Latin1Encoding_GetCharCount_m_491866346_0 (Latin1Encoding_t_565449274_0 * __this, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___index, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.Latin1Encoding::GetChars(System.Byte[],System.Int32,System.Int32,System.Char[],System.Int32)
extern "C"  int32_t Latin1Encoding_GetChars_m_2004563664_0 (Latin1Encoding_t_565449274_0 * __this, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___byteIndex, int32_t ___byteCount, CharU5BU5D_t_1225802637_0* ___chars, int32_t ___charIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.Latin1Encoding::GetMaxByteCount(System.Int32)
extern "C"  int32_t Latin1Encoding_GetMaxByteCount_m_1895098628_0 (Latin1Encoding_t_565449274_0 * __this, int32_t ___charCount, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.Latin1Encoding::GetMaxCharCount(System.Int32)
extern "C"  int32_t Latin1Encoding_GetMaxCharCount_m_1103563282_0 (Latin1Encoding_t_565449274_0 * __this, int32_t ___byteCount, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Text.Latin1Encoding::GetString(System.Byte[],System.Int32,System.Int32)
extern "C"  String_t* Latin1Encoding_GetString_m1453607223_0 (Latin1Encoding_t_565449274_0 * __this, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___index, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Text.Latin1Encoding::GetString(System.Byte[])
extern "C"  String_t* Latin1Encoding_GetString_m_1720446313_0 (Latin1Encoding_t_565449274_0 * __this, ByteU5BU5D_t_1238178395_0* ___bytes, const MethodInfo* method) IL2CPP_METHOD_ATTR;
