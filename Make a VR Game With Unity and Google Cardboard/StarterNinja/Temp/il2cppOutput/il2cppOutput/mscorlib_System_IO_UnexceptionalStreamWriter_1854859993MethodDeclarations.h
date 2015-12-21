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

// System.IO.UnexceptionalStreamWriter
struct UnexceptionalStreamWriter_t_1854859993_0;
// System.IO.Stream
struct Stream_t463444077_0;
// System.Text.Encoding
struct Encoding_t453909881_0;
// System.Char[]
struct CharU5BU5D_t_1225802637_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"

// System.Void System.IO.UnexceptionalStreamWriter::.ctor(System.IO.Stream,System.Text.Encoding)
extern "C"  void UnexceptionalStreamWriter__ctor_m_1343944655_0 (UnexceptionalStreamWriter_t_1854859993_0 * __this, Stream_t463444077_0 * ___stream, Encoding_t453909881_0 * ___encoding, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.UnexceptionalStreamWriter::Flush()
extern "C"  void UnexceptionalStreamWriter_Flush_m_806113941_0 (UnexceptionalStreamWriter_t_1854859993_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.UnexceptionalStreamWriter::Write(System.Char[],System.Int32,System.Int32)
extern "C"  void UnexceptionalStreamWriter_Write_m2144061973_0 (UnexceptionalStreamWriter_t_1854859993_0 * __this, CharU5BU5D_t_1225802637_0* ___buffer, int32_t ___index, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.UnexceptionalStreamWriter::Write(System.Char)
extern "C"  void UnexceptionalStreamWriter_Write_m_2067746921_0 (UnexceptionalStreamWriter_t_1854859993_0 * __this, uint16_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.UnexceptionalStreamWriter::Write(System.Char[])
extern "C"  void UnexceptionalStreamWriter_Write_m1465117941_0 (UnexceptionalStreamWriter_t_1854859993_0 * __this, CharU5BU5D_t_1225802637_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.UnexceptionalStreamWriter::Write(System.String)
extern "C"  void UnexceptionalStreamWriter_Write_m_1155692228_0 (UnexceptionalStreamWriter_t_1854859993_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
