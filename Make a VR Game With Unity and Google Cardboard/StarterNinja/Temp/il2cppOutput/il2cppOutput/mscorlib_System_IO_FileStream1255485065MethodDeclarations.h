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

// System.IO.FileStream
struct FileStream_t1255485065_0;
// System.String
struct String_t;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;
// System.Object
struct Object_t;
// System.IO.Stream
struct Stream_t463444077_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"
#include "mscorlib_System_IO_FileAccess724014189.h"
#include "mscorlib_System_IO_FileMode461457132.h"
#include "mscorlib_System_IO_FileShare1425599414.h"
#include "mscorlib_System_IO_FileOptions897747125.h"
#include "mscorlib_System_IO_SeekOrigin_1060652501.h"

// System.Void System.IO.FileStream::.ctor(System.IntPtr,System.IO.FileAccess,System.Boolean,System.Int32,System.Boolean,System.Boolean)
extern "C"  void FileStream__ctor_m_639585776_0 (FileStream_t1255485065_0 * __this, IntPtr_t ___handle, int32_t ___access, bool ___ownsHandle, int32_t ___bufferSize, bool ___isAsync, bool ___noBuffering, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.FileStream::.ctor(System.String,System.IO.FileMode,System.IO.FileAccess)
extern "C"  void FileStream__ctor_m_917462124_0 (FileStream_t1255485065_0 * __this, String_t* ___path, int32_t ___mode, int32_t ___access, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.FileStream::.ctor(System.String,System.IO.FileMode,System.IO.FileAccess,System.IO.FileShare)
extern "C"  void FileStream__ctor_m_637914266_0 (FileStream_t1255485065_0 * __this, String_t* ___path, int32_t ___mode, int32_t ___access, int32_t ___share, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.FileStream::.ctor(System.String,System.IO.FileMode,System.IO.FileAccess,System.IO.FileShare,System.Int32,System.Boolean,System.Boolean)
extern "C"  void FileStream__ctor_m_848746031_0 (FileStream_t1255485065_0 * __this, String_t* ___path, int32_t ___mode, int32_t ___access, int32_t ___share, int32_t ___bufferSize, bool ___isAsync, bool ___anonymous, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.FileStream::.ctor(System.String,System.IO.FileMode,System.IO.FileAccess,System.IO.FileShare,System.Int32,System.Boolean,System.IO.FileOptions)
extern "C"  void FileStream__ctor_m1468472351_0 (FileStream_t1255485065_0 * __this, String_t* ___path, int32_t ___mode, int32_t ___access, int32_t ___share, int32_t ___bufferSize, bool ___anonymous, int32_t ___options, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.IO.FileStream::get_CanRead()
extern "C"  bool FileStream_get_CanRead_m_591210906_0 (FileStream_t1255485065_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.IO.FileStream::get_CanWrite()
extern "C"  bool FileStream_get_CanWrite_m_625015375_0 (FileStream_t1255485065_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.IO.FileStream::get_CanSeek()
extern "C"  bool FileStream_get_CanSeek_m_562455864_0 (FileStream_t1255485065_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.IO.FileStream::get_Length()
extern "C"  int64_t FileStream_get_Length_m755999491_0 (FileStream_t1255485065_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.IO.FileStream::get_Position()
extern "C"  int64_t FileStream_get_Position_m887539078_0 (FileStream_t1255485065_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.FileStream::set_Position(System.Int64)
extern "C"  void FileStream_set_Position_m_224118481_0 (FileStream_t1255485065_0 * __this, int64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.FileStream::ReadByte()
extern "C"  int32_t FileStream_ReadByte_m_351796143_0 (FileStream_t1255485065_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.FileStream::WriteByte(System.Byte)
extern "C"  void FileStream_WriteByte_m_1573139559_0 (FileStream_t1255485065_0 * __this, uint8_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.FileStream::Read(System.Byte[],System.Int32,System.Int32)
extern "C"  int32_t FileStream_Read_m1809515168_0 (FileStream_t1255485065_0 * __this, ByteU5BU5D_t_1238178395_0* ___array, int32_t ___offset, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.FileStream::ReadInternal(System.Byte[],System.Int32,System.Int32)
extern "C"  int32_t FileStream_ReadInternal_m_537224093_0 (FileStream_t1255485065_0 * __this, ByteU5BU5D_t_1238178395_0* ___dest, int32_t ___offset, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.IAsyncResult System.IO.FileStream::BeginRead(System.Byte[],System.Int32,System.Int32,System.AsyncCallback,System.Object)
extern "C"  Object_t * FileStream_BeginRead_m_285111409_0 (FileStream_t1255485065_0 * __this, ByteU5BU5D_t_1238178395_0* ___array, int32_t ___offset, int32_t ___numBytes, AsyncCallback_t_266361018_0 * ___userCallback, Object_t * ___stateObject, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.FileStream::EndRead(System.IAsyncResult)
extern "C"  int32_t FileStream_EndRead_m1164505443_0 (FileStream_t1255485065_0 * __this, Object_t * ___asyncResult, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.FileStream::Write(System.Byte[],System.Int32,System.Int32)
extern "C"  void FileStream_Write_m445180607_0 (FileStream_t1255485065_0 * __this, ByteU5BU5D_t_1238178395_0* ___array, int32_t ___offset, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.FileStream::WriteInternal(System.Byte[],System.Int32,System.Int32)
extern "C"  void FileStream_WriteInternal_m_1970670206_0 (FileStream_t1255485065_0 * __this, ByteU5BU5D_t_1238178395_0* ___src, int32_t ___offset, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.IAsyncResult System.IO.FileStream::BeginWrite(System.Byte[],System.Int32,System.Int32,System.AsyncCallback,System.Object)
extern "C"  Object_t * FileStream_BeginWrite_m_2070989798_0 (FileStream_t1255485065_0 * __this, ByteU5BU5D_t_1238178395_0* ___array, int32_t ___offset, int32_t ___numBytes, AsyncCallback_t_266361018_0 * ___userCallback, Object_t * ___stateObject, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.FileStream::EndWrite(System.IAsyncResult)
extern "C"  void FileStream_EndWrite_m_761415864_0 (FileStream_t1255485065_0 * __this, Object_t * ___asyncResult, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.IO.FileStream::Seek(System.Int64,System.IO.SeekOrigin)
extern "C"  int64_t FileStream_Seek_m_23273727_0 (FileStream_t1255485065_0 * __this, int64_t ___offset, int32_t ___origin, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.FileStream::SetLength(System.Int64)
extern "C"  void FileStream_SetLength_m922718469_0 (FileStream_t1255485065_0 * __this, int64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.FileStream::Flush()
extern "C"  void FileStream_Flush_m134843343_0 (FileStream_t1255485065_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.FileStream::Finalize()
extern "C"  void FileStream_Finalize_m223127701_0 (FileStream_t1255485065_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.FileStream::Dispose(System.Boolean)
extern "C"  void FileStream_Dispose_m376280481_0 (FileStream_t1255485065_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.FileStream::ReadSegment(System.Byte[],System.Int32,System.Int32)
extern "C"  int32_t FileStream_ReadSegment_m570180669_0 (FileStream_t1255485065_0 * __this, ByteU5BU5D_t_1238178395_0* ___dest, int32_t ___dest_offset, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.FileStream::WriteSegment(System.Byte[],System.Int32,System.Int32)
extern "C"  int32_t FileStream_WriteSegment_m_1735350878_0 (FileStream_t1255485065_0 * __this, ByteU5BU5D_t_1238178395_0* ___src, int32_t ___src_offset, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.FileStream::FlushBuffer(System.IO.Stream)
extern "C"  void FileStream_FlushBuffer_m_397432250_0 (FileStream_t1255485065_0 * __this, Stream_t463444077_0 * ___st, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.FileStream::FlushBuffer()
extern "C"  void FileStream_FlushBuffer_m_625827409_0 (FileStream_t1255485065_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.FileStream::FlushBufferIfDirty()
extern "C"  void FileStream_FlushBufferIfDirty_m1568636904_0 (FileStream_t1255485065_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.FileStream::RefillBuffer()
extern "C"  void FileStream_RefillBuffer_m_735775347_0 (FileStream_t1255485065_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.FileStream::ReadData(System.IntPtr,System.Byte[],System.Int32,System.Int32)
extern "C"  int32_t FileStream_ReadData_m410796132_0 (FileStream_t1255485065_0 * __this, IntPtr_t ___handle, ByteU5BU5D_t_1238178395_0* ___buf, int32_t ___offset, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.FileStream::InitBuffer(System.Int32,System.Boolean)
extern "C"  void FileStream_InitBuffer_m157631941_0 (FileStream_t1255485065_0 * __this, int32_t ___size, bool ___noBuffering, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.IO.FileStream::GetSecureFileName(System.String)
extern "C"  String_t* FileStream_GetSecureFileName_m778676102_0 (FileStream_t1255485065_0 * __this, String_t* ___filename, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.IO.FileStream::GetSecureFileName(System.String,System.Boolean)
extern "C"  String_t* FileStream_GetSecureFileName_m1473113911_0 (FileStream_t1255485065_0 * __this, String_t* ___filename, bool ___full, const MethodInfo* method) IL2CPP_METHOD_ATTR;
