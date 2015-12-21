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

// System.IO.TextWriter
struct TextWriter_t1418103405_0;
// System.Char[]
struct CharU5BU5D_t_1225802637_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"

// System.Void System.IO.TextWriter::.ctor()
extern "C"  void TextWriter__ctor_m_48864951_0 (TextWriter_t1418103405_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.TextWriter::.cctor()
extern "C"  void TextWriter__cctor_m_1996909692_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.TextWriter::Close()
extern "C"  void TextWriter_Close_m1661994591_0 (TextWriter_t1418103405_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.TextWriter::Dispose(System.Boolean)
extern "C"  void TextWriter_Dispose_m_1946770883_0 (TextWriter_t1418103405_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.TextWriter::Dispose()
extern "C"  void TextWriter_Dispose_m183705414_0 (TextWriter_t1418103405_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.TextWriter::Flush()
extern "C"  void TextWriter_Flush_m35082347_0 (TextWriter_t1418103405_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.IO.TextWriter System.IO.TextWriter::Synchronized(System.IO.TextWriter,System.Boolean)
extern "C"  TextWriter_t1418103405_0 * TextWriter_Synchronized_m_2045522667_0 (Object_t * __this /* static, unused */, TextWriter_t1418103405_0 * ___writer, bool ___neverClose, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.TextWriter::Write(System.Char)
extern "C"  void TextWriter_Write_m_888591209_0 (TextWriter_t1418103405_0 * __this, uint16_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.TextWriter::Write(System.Char[])
extern "C"  void TextWriter_Write_m762391029_0 (TextWriter_t1418103405_0 * __this, CharU5BU5D_t_1225802637_0* ___buffer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.TextWriter::Write(System.String)
extern "C"  void TextWriter_Write_m_1858419140_0 (TextWriter_t1418103405_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.TextWriter::Write(System.Char[],System.Int32,System.Int32)
extern "C"  void TextWriter_Write_m212256533_0 (TextWriter_t1418103405_0 * __this, CharU5BU5D_t_1225802637_0* ___buffer, int32_t ___index, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.TextWriter::WriteLine()
extern "C"  void TextWriter_WriteLine_m1071433498_0 (TextWriter_t1418103405_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.TextWriter::WriteLine(System.String)
extern "C"  void TextWriter_WriteLine_m_1807306200_0 (TextWriter_t1418103405_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
