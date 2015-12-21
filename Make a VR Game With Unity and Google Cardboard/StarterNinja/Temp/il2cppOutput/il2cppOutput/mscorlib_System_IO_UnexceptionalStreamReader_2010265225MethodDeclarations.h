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

// System.IO.UnexceptionalStreamReader
struct UnexceptionalStreamReader_t_2010265225_0;
// System.IO.Stream
struct Stream_t463444077_0;
// System.Text.Encoding
struct Encoding_t453909881_0;
// System.Char[]
struct CharU5BU5D_t_1225802637_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"

// System.Void System.IO.UnexceptionalStreamReader::.ctor(System.IO.Stream,System.Text.Encoding)
extern "C"  void UnexceptionalStreamReader__ctor_m_692932479_0 (UnexceptionalStreamReader_t_2010265225_0 * __this, Stream_t463444077_0 * ___stream, Encoding_t453909881_0 * ___encoding, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.UnexceptionalStreamReader::.cctor()
extern "C"  void UnexceptionalStreamReader__cctor_m_2020841772_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.UnexceptionalStreamReader::Peek()
extern "C"  int32_t UnexceptionalStreamReader_Peek_m_1211640022_0 (UnexceptionalStreamReader_t_2010265225_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.UnexceptionalStreamReader::Read()
extern "C"  int32_t UnexceptionalStreamReader_Read_m_1154507611_0 (UnexceptionalStreamReader_t_2010265225_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.UnexceptionalStreamReader::Read(System.Char[],System.Int32,System.Int32)
extern "C"  int32_t UnexceptionalStreamReader_Read_m_869812202_0 (UnexceptionalStreamReader_t_2010265225_0 * __this, CharU5BU5D_t_1225802637_0* ___dest_buffer, int32_t ___index, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.IO.UnexceptionalStreamReader::CheckEOL(System.Char)
extern "C"  bool UnexceptionalStreamReader_CheckEOL_m_1951013702_0 (UnexceptionalStreamReader_t_2010265225_0 * __this, uint16_t ___current, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.IO.UnexceptionalStreamReader::ReadLine()
extern "C"  String_t* UnexceptionalStreamReader_ReadLine_m680275730_0 (UnexceptionalStreamReader_t_2010265225_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.IO.UnexceptionalStreamReader::ReadToEnd()
extern "C"  String_t* UnexceptionalStreamReader_ReadToEnd_m_1741957660_0 (UnexceptionalStreamReader_t_2010265225_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
