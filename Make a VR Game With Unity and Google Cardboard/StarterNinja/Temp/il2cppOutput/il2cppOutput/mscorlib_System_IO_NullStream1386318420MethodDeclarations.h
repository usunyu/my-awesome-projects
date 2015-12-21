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

// System.IO.NullStream
struct NullStream_t1386318420_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IO_SeekOrigin_1060652501.h"

// System.Void System.IO.NullStream::.ctor()
extern "C"  void NullStream__ctor_m_768649918_0 (NullStream_t1386318420_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.IO.NullStream::get_CanRead()
extern "C"  bool NullStream_get_CanRead_m2080377659_0 (NullStream_t1386318420_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.IO.NullStream::get_CanSeek()
extern "C"  bool NullStream_get_CanSeek_m2109132701_0 (NullStream_t1386318420_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.IO.NullStream::get_CanWrite()
extern "C"  bool NullStream_get_CanWrite_m589851516_0 (NullStream_t1386318420_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.IO.NullStream::get_Length()
extern "C"  int64_t NullStream_get_Length_m_543293554_0 (NullStream_t1386318420_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.IO.NullStream::get_Position()
extern "C"  int64_t NullStream_get_Position_m2102405969_0 (NullStream_t1386318420_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.NullStream::set_Position(System.Int64)
extern "C"  void NullStream_set_Position_m_1190902150_0 (NullStream_t1386318420_0 * __this, int64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.NullStream::Flush()
extern "C"  void NullStream_Flush_m_684702620_0 (NullStream_t1386318420_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.NullStream::Read(System.Byte[],System.Int32,System.Int32)
extern "C"  int32_t NullStream_Read_m1573364597_0 (NullStream_t1386318420_0 * __this, ByteU5BU5D_t_1238178395_0* ___buffer, int32_t ___offset, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.NullStream::ReadByte()
extern "C"  int32_t NullStream_ReadByte_m1443497884_0 (NullStream_t1386318420_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.IO.NullStream::Seek(System.Int64,System.IO.SeekOrigin)
extern "C"  int64_t NullStream_Seek_m57934742_0 (NullStream_t1386318420_0 * __this, int64_t ___offset, int32_t ___origin, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.NullStream::SetLength(System.Int64)
extern "C"  void NullStream_SetLength_m76840858_0 (NullStream_t1386318420_0 * __this, int64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.NullStream::Write(System.Byte[],System.Int32,System.Int32)
extern "C"  void NullStream_Write_m1714447498_0 (NullStream_t1386318420_0 * __this, ByteU5BU5D_t_1238178395_0* ___buffer, int32_t ___offset, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.NullStream::WriteByte(System.Byte)
extern "C"  void NullStream_WriteByte_m62142052_0 (NullStream_t1386318420_0 * __this, uint8_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
