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

// Mono.Security.Protocol.Tls.RecordProtocol/SendRecordAsyncResult
struct SendRecordAsyncResult_t854078210_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;
// System.Object
struct Object_t;
// Mono.Security.Protocol.Tls.Handshake.HandshakeMessage
struct HandshakeMessage_t1568425967_0;
// System.Exception
struct Exception_t2143823668_0;
// System.Threading.WaitHandle
struct WaitHandle_t1045483054_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.Protocol.Tls.RecordProtocol/SendRecordAsyncResult::.ctor(System.AsyncCallback,System.Object,Mono.Security.Protocol.Tls.Handshake.HandshakeMessage)
extern "C"  void SendRecordAsyncResult__ctor_m1199829305_0 (SendRecordAsyncResult_t854078210_0 * __this, AsyncCallback_t_266361018_0 * ___userCallback, Object_t * ___userState, HandshakeMessage_t1568425967_0 * ___message, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.Handshake.HandshakeMessage Mono.Security.Protocol.Tls.RecordProtocol/SendRecordAsyncResult::get_Message()
extern "C"  HandshakeMessage_t1568425967_0 * SendRecordAsyncResult_get_Message_m_1529692752_0 (SendRecordAsyncResult_t854078210_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object Mono.Security.Protocol.Tls.RecordProtocol/SendRecordAsyncResult::get_AsyncState()
extern "C"  Object_t * SendRecordAsyncResult_get_AsyncState_m_1629566945_0 (SendRecordAsyncResult_t854078210_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Exception Mono.Security.Protocol.Tls.RecordProtocol/SendRecordAsyncResult::get_AsyncException()
extern "C"  Exception_t2143823668_0 * SendRecordAsyncResult_get_AsyncException_m776645195_0 (SendRecordAsyncResult_t854078210_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.RecordProtocol/SendRecordAsyncResult::get_CompletedWithError()
extern "C"  bool SendRecordAsyncResult_get_CompletedWithError_m771666376_0 (SendRecordAsyncResult_t854078210_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Threading.WaitHandle Mono.Security.Protocol.Tls.RecordProtocol/SendRecordAsyncResult::get_AsyncWaitHandle()
extern "C"  WaitHandle_t1045483054_0 * SendRecordAsyncResult_get_AsyncWaitHandle_m1260948317_0 (SendRecordAsyncResult_t854078210_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.RecordProtocol/SendRecordAsyncResult::get_IsCompleted()
extern "C"  bool SendRecordAsyncResult_get_IsCompleted_m775666514_0 (SendRecordAsyncResult_t854078210_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.RecordProtocol/SendRecordAsyncResult::SetComplete(System.Exception)
extern "C"  void SendRecordAsyncResult_SetComplete_m323449559_0 (SendRecordAsyncResult_t854078210_0 * __this, Exception_t2143823668_0 * ___ex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.RecordProtocol/SendRecordAsyncResult::SetComplete()
extern "C"  void SendRecordAsyncResult_SetComplete_m1807552551_0 (SendRecordAsyncResult_t854078210_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
