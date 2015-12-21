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

// Mono.Security.Protocol.Tls.TlsStream
struct TlsStream_t_1516681037_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IO_SeekOrigin_1060652501.h"

// System.Void Mono.Security.Protocol.Tls.TlsStream::.ctor()
extern "C"  void TlsStream__ctor_m_1699024189_0 (TlsStream_t_1516681037_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.TlsStream::.ctor(System.Byte[])
extern "C"  void TlsStream__ctor_m868803046_0 (TlsStream_t_1516681037_0 * __this, ByteU5BU5D_t_1238178395_0* ___data, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.TlsStream::get_EOF()
extern "C"  bool TlsStream_get_EOF_m_538594394_0 (TlsStream_t_1516681037_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.TlsStream::get_CanWrite()
extern "C"  bool TlsStream_get_CanWrite_m_835250137_0 (TlsStream_t_1516681037_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.TlsStream::get_CanRead()
extern "C"  bool TlsStream_get_CanRead_m_43803344_0 (TlsStream_t_1516681037_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.TlsStream::get_CanSeek()
extern "C"  bool TlsStream_get_CanSeek_m_15048302_0 (TlsStream_t_1516681037_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 Mono.Security.Protocol.Tls.TlsStream::get_Position()
extern "C"  int64_t TlsStream_get_Position_m872901500_0 (TlsStream_t_1516681037_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.TlsStream::set_Position(System.Int64)
extern "C"  void TlsStream_set_Position_m1335791449_0 (TlsStream_t_1516681037_0 * __this, int64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 Mono.Security.Protocol.Tls.TlsStream::get_Length()
extern "C"  int64_t TlsStream_get_Length_m_1393734023_0 (TlsStream_t_1516681037_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.TlsStream::ReadSmallValue(System.Int32)
extern "C"  ByteU5BU5D_t_1238178395_0* TlsStream_ReadSmallValue_m1160118396_0 (TlsStream_t_1516681037_0 * __this, int32_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte Mono.Security.Protocol.Tls.TlsStream::ReadByte()
extern "C"  uint8_t TlsStream_ReadByte_m_170469013_0 (TlsStream_t_1516681037_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int16 Mono.Security.Protocol.Tls.TlsStream::ReadInt16()
extern "C"  int16_t TlsStream_ReadInt16_m_1235888867_0 (TlsStream_t_1516681037_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Protocol.Tls.TlsStream::ReadInt24()
extern "C"  int32_t TlsStream_ReadInt24_m64683956_0 (TlsStream_t_1516681037_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.TlsStream::ReadBytes(System.Int32)
extern "C"  ByteU5BU5D_t_1238178395_0* TlsStream_ReadBytes_m_603586179_0 (TlsStream_t_1516681037_0 * __this, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.TlsStream::Write(System.Byte)
extern "C"  void TlsStream_Write_m1211282283_0 (TlsStream_t_1516681037_0 * __this, uint8_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.TlsStream::Write(System.Int16)
extern "C"  void TlsStream_Write_m_914759093_0 (TlsStream_t_1516681037_0 * __this, int16_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.TlsStream::WriteInt24(System.Int32)
extern "C"  void TlsStream_WriteInt24_m_350905276_0 (TlsStream_t_1516681037_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.TlsStream::Write(System.Int32)
extern "C"  void TlsStream_Write_m_914757295_0 (TlsStream_t_1516681037_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.TlsStream::Write(System.Byte[])
extern "C"  void TlsStream_Write_m106187721_0 (TlsStream_t_1516681037_0 * __this, ByteU5BU5D_t_1238178395_0* ___buffer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.TlsStream::Reset()
extern "C"  void TlsStream_Reset_m242376048_0 (TlsStream_t_1516681037_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.TlsStream::ToArray()
extern "C"  ByteU5BU5D_t_1238178395_0* TlsStream_ToArray_m613486997_0 (TlsStream_t_1516681037_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.TlsStream::Flush()
extern "C"  void TlsStream_Flush_m_1615076891_0 (TlsStream_t_1516681037_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.TlsStream::SetLength(System.Int64)
extern "C"  void TlsStream_SetLength_m702479131_0 (TlsStream_t_1516681037_0 * __this, int64_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 Mono.Security.Protocol.Tls.TlsStream::Seek(System.Int64,System.IO.SeekOrigin)
extern "C"  int64_t TlsStream_Seek_m484817355_0 (TlsStream_t_1516681037_0 * __this, int64_t ___offset, int32_t ___loc, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Protocol.Tls.TlsStream::Read(System.Byte[],System.Int32,System.Int32)
extern "C"  int32_t TlsStream_Read_m_859128854_0 (TlsStream_t_1516681037_0 * __this, ByteU5BU5D_t_1238178395_0* ___buffer, int32_t ___offset, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.TlsStream::Write(System.Byte[],System.Int32,System.Int32)
extern "C"  void TlsStream_Write_m_1441495063_0 (TlsStream_t_1516681037_0 * __this, ByteU5BU5D_t_1238178395_0* ___buffer, int32_t ___offset, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
