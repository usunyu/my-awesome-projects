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

// Mono.Security.Protocol.Tls.RecordProtocol/ReceiveRecordAsyncResult
struct ReceiveRecordAsyncResult_t1151207363_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;
// System.Object
struct Object_t;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.IO.Stream
struct Stream_t463444077_0;
// System.Exception
struct Exception_t2143823668_0;
// System.Threading.WaitHandle
struct WaitHandle_t1045483054_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.Protocol.Tls.RecordProtocol/ReceiveRecordAsyncResult::.ctor(System.AsyncCallback,System.Object,System.Byte[],System.IO.Stream)
extern "C"  void ReceiveRecordAsyncResult__ctor_m_1296385221_0 (ReceiveRecordAsyncResult_t1151207363_0 * __this, AsyncCallback_t_266361018_0 * ___userCallback, Object_t * ___userState, ByteU5BU5D_t_1238178395_0* ___initialBuffer, Stream_t463444077_0 * ___record, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.IO.Stream Mono.Security.Protocol.Tls.RecordProtocol/ReceiveRecordAsyncResult::get_Record()
extern "C"  Stream_t463444077_0 * ReceiveRecordAsyncResult_get_Record_m871815161_0 (ReceiveRecordAsyncResult_t1151207363_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.RecordProtocol/ReceiveRecordAsyncResult::get_ResultingBuffer()
extern "C"  ByteU5BU5D_t_1238178395_0* ReceiveRecordAsyncResult_get_ResultingBuffer_m_474400253_0 (ReceiveRecordAsyncResult_t1151207363_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.RecordProtocol/ReceiveRecordAsyncResult::get_InitialBuffer()
extern "C"  ByteU5BU5D_t_1238178395_0* ReceiveRecordAsyncResult_get_InitialBuffer_m_1516888350_0 (ReceiveRecordAsyncResult_t1151207363_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object Mono.Security.Protocol.Tls.RecordProtocol/ReceiveRecordAsyncResult::get_AsyncState()
extern "C"  Object_t * ReceiveRecordAsyncResult_get_AsyncState_m_1022778268_0 (ReceiveRecordAsyncResult_t1151207363_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Exception Mono.Security.Protocol.Tls.RecordProtocol/ReceiveRecordAsyncResult::get_AsyncException()
extern "C"  Exception_t2143823668_0 * ReceiveRecordAsyncResult_get_AsyncException_m_971873164_0 (ReceiveRecordAsyncResult_t1151207363_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.RecordProtocol/ReceiveRecordAsyncResult::get_CompletedWithError()
extern "C"  bool ReceiveRecordAsyncResult_get_CompletedWithError_m_977944545_0 (ReceiveRecordAsyncResult_t1151207363_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Threading.WaitHandle Mono.Security.Protocol.Tls.RecordProtocol/ReceiveRecordAsyncResult::get_AsyncWaitHandle()
extern "C"  WaitHandle_t1045483054_0 * ReceiveRecordAsyncResult_get_AsyncWaitHandle_m1089809952_0 (ReceiveRecordAsyncResult_t1151207363_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.RecordProtocol/ReceiveRecordAsyncResult::get_IsCompleted()
extern "C"  bool ReceiveRecordAsyncResult_get_IsCompleted_m736891099_0 (ReceiveRecordAsyncResult_t1151207363_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.RecordProtocol/ReceiveRecordAsyncResult::SetComplete(System.Exception,System.Byte[])
extern "C"  void ReceiveRecordAsyncResult_SetComplete_m_339013313_0 (ReceiveRecordAsyncResult_t1151207363_0 * __this, Exception_t2143823668_0 * ___ex, ByteU5BU5D_t_1238178395_0* ___resultingBuffer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.RecordProtocol/ReceiveRecordAsyncResult::SetComplete(System.Exception)
extern "C"  void ReceiveRecordAsyncResult_SetComplete_m1288331580_0 (ReceiveRecordAsyncResult_t1151207363_0 * __this, Exception_t2143823668_0 * ___ex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.RecordProtocol/ReceiveRecordAsyncResult::SetComplete(System.Byte[])
extern "C"  void ReceiveRecordAsyncResult_SetComplete_m652335805_0 (ReceiveRecordAsyncResult_t1151207363_0 * __this, ByteU5BU5D_t_1238178395_0* ___resultingBuffer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
