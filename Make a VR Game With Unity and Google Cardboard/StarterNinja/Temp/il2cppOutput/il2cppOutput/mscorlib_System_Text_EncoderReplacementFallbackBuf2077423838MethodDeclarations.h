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

// System.Text.EncoderReplacementFallbackBuffer
struct EncoderReplacementFallbackBuffer_t2077423838_0;
// System.Text.EncoderReplacementFallback
struct EncoderReplacementFallback_t_1610731778_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Text.EncoderReplacementFallbackBuffer::.ctor(System.Text.EncoderReplacementFallback)
extern "C"  void EncoderReplacementFallbackBuffer__ctor_m1930588894_0 (EncoderReplacementFallbackBuffer_t2077423838_0 * __this, EncoderReplacementFallback_t_1610731778_0 * ___fallback, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.EncoderReplacementFallbackBuffer::get_Remaining()
extern "C"  int32_t EncoderReplacementFallbackBuffer_get_Remaining_m_331806841_0 (EncoderReplacementFallbackBuffer_t2077423838_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.EncoderReplacementFallbackBuffer::Fallback(System.Char,System.Int32)
extern "C"  bool EncoderReplacementFallbackBuffer_Fallback_m1355578442_0 (EncoderReplacementFallbackBuffer_t2077423838_0 * __this, uint16_t ___charUnknown, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.EncoderReplacementFallbackBuffer::Fallback(System.Char,System.Char,System.Int32)
extern "C"  bool EncoderReplacementFallbackBuffer_Fallback_m_1829599597_0 (EncoderReplacementFallbackBuffer_t2077423838_0 * __this, uint16_t ___charUnknownHigh, uint16_t ___charUnknownLow, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.EncoderReplacementFallbackBuffer::Fallback(System.Int32)
extern "C"  bool EncoderReplacementFallbackBuffer_Fallback_m_1789391743_0 (EncoderReplacementFallbackBuffer_t2077423838_0 * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Char System.Text.EncoderReplacementFallbackBuffer::GetNextChar()
extern "C"  uint16_t EncoderReplacementFallbackBuffer_GetNextChar_m491962295_0 (EncoderReplacementFallbackBuffer_t2077423838_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
