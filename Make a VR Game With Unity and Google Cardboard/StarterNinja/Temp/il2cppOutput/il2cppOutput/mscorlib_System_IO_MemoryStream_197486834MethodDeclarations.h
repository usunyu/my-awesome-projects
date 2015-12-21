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

// System.IO.MemoryStream
struct MemoryStream_t_197486834_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IO_SeekOrigin_1060652501.h"

// System.Void System.IO.MemoryStream::.ctor()
extern "C"  void MemoryStream__ctor_m_691789560_0 (MemoryStream_t_197486834_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.MemoryStream::.ctor(System.Int32)
extern "C"  void MemoryStream__ctor_m1061194329_0 (MemoryStream_t_197486834_0 * __this, int32_t ___capacity, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.MemoryStream::.ctor(System.Byte[])
extern "C"  void MemoryStream__ctor_m1231145921_0 (MemoryStream_t_197486834_0 * __this, ByteU5BU5D_t_1238178395_0* ___buffer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.MemoryStream::InternalConstructor(System.Byte[],System.Int32,System.Int32,System.Boolean,System.Boolean)
extern "C"  void MemoryStream_InternalConstructor_m661185350_0 (MemoryStream_t_197486834_0 * __this, ByteU5BU5D_t_1238178395_0* ___buffer, int32_t ___index, int32_t ___count, bool ___writable, bool ___publicallyVisible, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.MemoryStream::CheckIfClosedThrowDisposed()
extern "C"  void MemoryStream_CheckIfClosedThrowDisposed_m1053557526_0 (MemoryStream_t_197486834_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.IO.MemoryStream::get_CanRead()
extern "C"  bool MemoryStream_get_CanRead_m_503516415_0 (MemoryStream_t_197486834_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.IO.MemoryStream::get_CanSeek()
extern "C"  bool MemoryStream_get_CanSeek_m_474761373_0 (MemoryStream_t_197486834_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.IO.MemoryStream::get_CanWrite()
extern "C"  bool MemoryStream_get_CanWrite_m2093513846_0 (MemoryStream_t_197486834_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.MemoryStream::set_Capacity(System.Int32)
extern "C"  void MemoryStream_set_Capacity_m760203076_0 (MemoryStream_t_197486834_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.IO.MemoryStream::get_Length()
extern "C"  int64_t MemoryStream_get_Length_m588315720_0 (MemoryStream_t_197486834_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.IO.MemoryStream::get_Position()
extern "C"  int64_t MemoryStream_get_Position_m_1342774901_0 (MemoryStream_t_197486834_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.MemoryStream::set_Position(System.Int64)
extern "C"  void MemoryStream_set_Position_m_1608947468_0 (MemoryStream_t_197486834_0 * __this, int64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.MemoryStream::Dispose(System.Boolean)
extern "C"  void MemoryStream_Dispose_m1459815420_0 (MemoryStream_t_197486834_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.MemoryStream::Flush()
extern "C"  void MemoryStream_Flush_m_607842262_0 (MemoryStream_t_197486834_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.MemoryStream::Read(System.Byte[],System.Int32,System.Int32)
extern "C"  int32_t MemoryStream_Read_m_1094360645_0 (MemoryStream_t_197486834_0 * __this, ByteU5BU5D_t_1238178395_0* ___buffer, int32_t ___offset, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.MemoryStream::ReadByte()
extern "C"  int32_t MemoryStream_ReadByte_m_1862482154_0 (MemoryStream_t_197486834_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.IO.MemoryStream::Seek(System.Int64,System.IO.SeekOrigin)
extern "C"  int64_t MemoryStream_Seek_m_471670116_0 (MemoryStream_t_197486834_0 * __this, int64_t ___offset, int32_t ___loc, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.MemoryStream::CalculateNewCapacity(System.Int32)
extern "C"  int32_t MemoryStream_CalculateNewCapacity_m358068701_0 (MemoryStream_t_197486834_0 * __this, int32_t ___minimum, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.MemoryStream::Expand(System.Int32)
extern "C"  void MemoryStream_Expand_m292277479_0 (MemoryStream_t_197486834_0 * __this, int32_t ___newSize, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.MemoryStream::SetLength(System.Int64)
extern "C"  void MemoryStream_SetLength_m2006253408_0 (MemoryStream_t_197486834_0 * __this, int64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.IO.MemoryStream::ToArray()
extern "C"  ByteU5BU5D_t_1238178395_0* MemoryStream_ToArray_m_450311526_0 (MemoryStream_t_197486834_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.MemoryStream::Write(System.Byte[],System.Int32,System.Int32)
extern "C"  void MemoryStream_Write_m1111852548_0 (MemoryStream_t_197486834_0 * __this, ByteU5BU5D_t_1238178395_0* ___buffer, int32_t ___offset, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.MemoryStream::WriteByte(System.Byte)
extern "C"  void MemoryStream_WriteByte_m_429808162_0 (MemoryStream_t_197486834_0 * __this, uint8_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
