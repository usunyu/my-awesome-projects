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

// System.Runtime.Remoting.Messaging.AsyncResult
struct AsyncResult_t1224533397_0;
// System.Object
struct Object_t;
// System.Threading.WaitHandle
struct WaitHandle_t1045483054_0;
// System.Runtime.Remoting.Messaging.IMessageSink
struct IMessageSink_t1677259445_0;
// System.Runtime.Remoting.Messaging.IMessageCtrl
struct IMessageCtrl_t1676793485_0;
// System.Runtime.Remoting.Messaging.IMessage
struct IMessage_t840298754_0;
// System.Runtime.Remoting.Messaging.MonoMethodMessage
struct MonoMethodMessage_t_663429985_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Runtime.Remoting.Messaging.AsyncResult::.ctor()
extern "C"  void AsyncResult__ctor_m_149037733_0 (AsyncResult_t1224533397_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Runtime.Remoting.Messaging.AsyncResult::get_AsyncState()
extern "C"  Object_t * AsyncResult_get_AsyncState_m1982026226_0 (AsyncResult_t1224533397_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Threading.WaitHandle System.Runtime.Remoting.Messaging.AsyncResult::get_AsyncWaitHandle()
extern "C"  WaitHandle_t1045483054_0 * AsyncResult_get_AsyncWaitHandle_m1919809002_0 (AsyncResult_t1224533397_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Remoting.Messaging.AsyncResult::get_CompletedSynchronously()
extern "C"  bool AsyncResult_get_CompletedSynchronously_m448147035_0 (AsyncResult_t1224533397_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Remoting.Messaging.AsyncResult::get_IsCompleted()
extern "C"  bool AsyncResult_get_IsCompleted_m563284563_0 (AsyncResult_t1224533397_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Remoting.Messaging.AsyncResult::get_EndInvokeCalled()
extern "C"  bool AsyncResult_get_EndInvokeCalled_m130757730_0 (AsyncResult_t1224533397_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.AsyncResult::set_EndInvokeCalled(System.Boolean)
extern "C"  void AsyncResult_set_EndInvokeCalled_m_154910493_0 (AsyncResult_t1224533397_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Runtime.Remoting.Messaging.AsyncResult::get_AsyncDelegate()
extern "C"  Object_t * AsyncResult_get_AsyncDelegate_m1003284646_0 (AsyncResult_t1224533397_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Messaging.IMessageSink System.Runtime.Remoting.Messaging.AsyncResult::get_NextSink()
extern "C"  Object_t * AsyncResult_get_NextSink_m920306782_0 (AsyncResult_t1224533397_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Messaging.IMessageCtrl System.Runtime.Remoting.Messaging.AsyncResult::AsyncProcessMessage(System.Runtime.Remoting.Messaging.IMessage,System.Runtime.Remoting.Messaging.IMessageSink)
extern "C"  Object_t * AsyncResult_AsyncProcessMessage_m1971781732_0 (AsyncResult_t1224533397_0 * __this, Object_t * ___msg, Object_t * ___replySink, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Messaging.IMessage System.Runtime.Remoting.Messaging.AsyncResult::GetReplyMessage()
extern "C"  Object_t * AsyncResult_GetReplyMessage_m1791966425_0 (AsyncResult_t1224533397_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.AsyncResult::SetMessageCtrl(System.Runtime.Remoting.Messaging.IMessageCtrl)
extern "C"  void AsyncResult_SetMessageCtrl_m1503809360_0 (AsyncResult_t1224533397_0 * __this, Object_t * ___mc, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.AsyncResult::SetCompletedSynchronously(System.Boolean)
extern "C"  void AsyncResult_SetCompletedSynchronously_m190268221_0 (AsyncResult_t1224533397_0 * __this, bool ___completed, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Messaging.IMessage System.Runtime.Remoting.Messaging.AsyncResult::EndInvoke()
extern "C"  Object_t * AsyncResult_EndInvoke_m_2025916007_0 (AsyncResult_t1224533397_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Messaging.IMessage System.Runtime.Remoting.Messaging.AsyncResult::SyncProcessMessage(System.Runtime.Remoting.Messaging.IMessage)
extern "C"  Object_t * AsyncResult_SyncProcessMessage_m_1842549263_0 (AsyncResult_t1224533397_0 * __this, Object_t * ___msg, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Messaging.MonoMethodMessage System.Runtime.Remoting.Messaging.AsyncResult::get_CallMessage()
extern "C"  MonoMethodMessage_t_663429985_0 * AsyncResult_get_CallMessage_m1178656201_0 (AsyncResult_t1224533397_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.AsyncResult::set_CallMessage(System.Runtime.Remoting.Messaging.MonoMethodMessage)
extern "C"  void AsyncResult_set_CallMessage_m_1649943734_0 (AsyncResult_t1224533397_0 * __this, MonoMethodMessage_t_663429985_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
