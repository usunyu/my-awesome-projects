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

// System.IO.StringReader
struct StringReader_t_849692831_0;
// System.String
struct String_t;
// System.Char[]
struct CharU5BU5D_t_1225802637_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.IO.StringReader::.ctor(System.String)
extern "C"  void StringReader__ctor_m1181104909_0 (StringReader_t_849692831_0 * __this, String_t* ___s, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.StringReader::Dispose(System.Boolean)
extern "C"  void StringReader_Dispose_m_977479927_0 (StringReader_t_849692831_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.StringReader::Peek()
extern "C"  int32_t StringReader_Peek_m_1990692282_0 (StringReader_t_849692831_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.StringReader::Read()
extern "C"  int32_t StringReader_Read_m_1933559871_0 (StringReader_t_849692831_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.StringReader::Read(System.Char[],System.Int32,System.Int32)
extern "C"  int32_t StringReader_Read_m11867514_0 (StringReader_t_849692831_0 * __this, CharU5BU5D_t_1225802637_0* ___buffer, int32_t ___index, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.IO.StringReader::ReadLine()
extern "C"  String_t* StringReader_ReadLine_m1484911836_0 (StringReader_t_849692831_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.IO.StringReader::ReadToEnd()
extern "C"  String_t* StringReader_ReadToEnd_m1726925146_0 (StringReader_t_849692831_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.StringReader::CheckObjectDisposedException()
extern "C"  void StringReader_CheckObjectDisposedException_m2098659794_0 (StringReader_t_849692831_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
