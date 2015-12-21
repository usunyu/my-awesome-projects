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

// System.Text.Encoding/ForwardingDecoder
struct ForwardingDecoder_t_1815027887_0;
// System.Text.Encoding
struct Encoding_t453909881_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Char[]
struct CharU5BU5D_t_1225802637_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Text.Encoding/ForwardingDecoder::.ctor(System.Text.Encoding)
extern "C"  void ForwardingDecoder__ctor_m_1364904144_0 (ForwardingDecoder_t_1815027887_0 * __this, Encoding_t453909881_0 * ___enc, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.Encoding/ForwardingDecoder::GetChars(System.Byte[],System.Int32,System.Int32,System.Char[],System.Int32)
extern "C"  int32_t ForwardingDecoder_GetChars_m_904225285_0 (ForwardingDecoder_t_1815027887_0 * __this, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___byteIndex, int32_t ___byteCount, CharU5BU5D_t_1225802637_0* ___chars, int32_t ___charIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
