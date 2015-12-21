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

// System.IO.SynchronizedReader
struct SynchronizedReader_t_1875904412_0;
// System.IO.TextReader
struct TextReader_t1262698173_0;
// System.String
struct String_t;
// System.Char[]
struct CharU5BU5D_t_1225802637_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.IO.SynchronizedReader::.ctor(System.IO.TextReader)
extern "C"  void SynchronizedReader__ctor_m_1894728199_0 (SynchronizedReader_t_1875904412_0 * __this, TextReader_t1262698173_0 * ___reader, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.SynchronizedReader::Peek()
extern "C"  int32_t SynchronizedReader_Peek_m_1454314103_0 (SynchronizedReader_t_1875904412_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.IO.SynchronizedReader::ReadLine()
extern "C"  String_t* SynchronizedReader_ReadLine_m1313224031_0 (SynchronizedReader_t_1875904412_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.IO.SynchronizedReader::ReadToEnd()
extern "C"  String_t* SynchronizedReader_ReadToEnd_m699570487_0 (SynchronizedReader_t_1875904412_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.SynchronizedReader::Read()
extern "C"  int32_t SynchronizedReader_Read_m_1397181692_0 (SynchronizedReader_t_1875904412_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.SynchronizedReader::Read(System.Char[],System.Int32,System.Int32)
extern "C"  int32_t SynchronizedReader_Read_m_1991359273_0 (SynchronizedReader_t_1875904412_0 * __this, CharU5BU5D_t_1225802637_0* ___buffer, int32_t ___index, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
