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

// System.IO.StreamReader
struct StreamReader_t1933514640_0;
// System.IO.Stream
struct Stream_t463444077_0;
// System.Text.Encoding
struct Encoding_t453909881_0;
// System.String
struct String_t;
// System.Char[]
struct CharU5BU5D_t_1225802637_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.IO.StreamReader::.ctor()
extern "C"  void StreamReader__ctor_m_1038413114_0 (StreamReader_t1933514640_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.StreamReader::.ctor(System.IO.Stream,System.Text.Encoding)
extern "C"  void StreamReader__ctor_m846704084_0 (StreamReader_t1933514640_0 * __this, Stream_t463444077_0 * ___stream, Encoding_t453909881_0 * ___encoding, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.StreamReader::.ctor(System.IO.Stream,System.Text.Encoding,System.Boolean,System.Int32)
extern "C"  void StreamReader__ctor_m_82279346_0 (StreamReader_t1933514640_0 * __this, Stream_t463444077_0 * ___stream, Encoding_t453909881_0 * ___encoding, bool ___detectEncodingFromByteOrderMarks, int32_t ___bufferSize, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.StreamReader::.ctor(System.String)
extern "C"  void StreamReader__ctor_m_505561604_0 (StreamReader_t1933514640_0 * __this, String_t* ___path, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.StreamReader::.ctor(System.String,System.Text.Encoding,System.Boolean,System.Int32)
extern "C"  void StreamReader__ctor_m_498597489_0 (StreamReader_t1933514640_0 * __this, String_t* ___path, Encoding_t453909881_0 * ___encoding, bool ___detectEncodingFromByteOrderMarks, int32_t ___bufferSize, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.StreamReader::.cctor()
extern "C"  void StreamReader__cctor_m1686835623_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.StreamReader::Initialize(System.IO.Stream,System.Text.Encoding,System.Boolean,System.Int32)
extern "C"  void StreamReader_Initialize_m_1375117178_0 (StreamReader_t1933514640_0 * __this, Stream_t463444077_0 * ___stream, Encoding_t453909881_0 * ___encoding, bool ___detectEncodingFromByteOrderMarks, int32_t ___bufferSize, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.StreamReader::Dispose(System.Boolean)
extern "C"  void StreamReader_Dispose_m_1637172806_0 (StreamReader_t1933514640_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.StreamReader::DoChecks(System.Int32)
extern "C"  int32_t StreamReader_DoChecks_m_2105947903_0 (StreamReader_t1933514640_0 * __this, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.StreamReader::ReadBuffer()
extern "C"  int32_t StreamReader_ReadBuffer_m_1742343664_0 (StreamReader_t1933514640_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.StreamReader::Peek()
extern "C"  int32_t StreamReader_Peek_m_311610507_0 (StreamReader_t1933514640_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.StreamReader::Read()
extern "C"  int32_t StreamReader_Read_m_254478096_0 (StreamReader_t1933514640_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.StreamReader::Read(System.Char[],System.Int32,System.Int32)
extern "C"  int32_t StreamReader_Read_m2134404459_0 (StreamReader_t1933514640_0 * __this, CharU5BU5D_t_1225802637_0* ___buffer, int32_t ___index, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.StreamReader::FindNextEOL()
extern "C"  int32_t StreamReader_FindNextEOL_m809222814_0 (StreamReader_t1933514640_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.IO.StreamReader::ReadLine()
extern "C"  String_t* StreamReader_ReadLine_m887391883_0 (StreamReader_t1933514640_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.IO.StreamReader::ReadToEnd()
extern "C"  String_t* StreamReader_ReadToEnd_m383675787_0 (StreamReader_t1933514640_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
