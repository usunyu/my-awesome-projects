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

// System.Runtime.Remoting.Messaging.HeaderHandler
struct HeaderHandler_t_1637549863_0;
// System.Object
struct Object_t;
// System.Runtime.Remoting.Messaging.Header[]
struct HeaderU5BU5D_t_1206030253_0;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"

// System.Void System.Runtime.Remoting.Messaging.HeaderHandler::.ctor(System.Object,System.IntPtr)
extern "C"  void HeaderHandler__ctor_m_1768389013_0 (HeaderHandler_t_1637549863_0 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Runtime.Remoting.Messaging.HeaderHandler::Invoke(System.Runtime.Remoting.Messaging.Header[])
extern "C"  Object_t * HeaderHandler_Invoke_m1835336033_0 (HeaderHandler_t_1637549863_0 * __this, HeaderU5BU5D_t_1206030253_0* ___headers, const MethodInfo* method) IL2CPP_METHOD_ATTR;
extern "C" Object_t * pinvoke_delegate_wrapper_HeaderHandler_t_1637549863_0(Il2CppObject* delegate, HeaderU5BU5D_t_1206030253_0* ___headers);
// System.IAsyncResult System.Runtime.Remoting.Messaging.HeaderHandler::BeginInvoke(System.Runtime.Remoting.Messaging.Header[],System.AsyncCallback,System.Object)
extern "C"  Object_t * HeaderHandler_BeginInvoke_m_1414491033_0 (HeaderHandler_t_1637549863_0 * __this, HeaderU5BU5D_t_1206030253_0* ___headers, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___object, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Runtime.Remoting.Messaging.HeaderHandler::EndInvoke(System.IAsyncResult)
extern "C"  Object_t * HeaderHandler_EndInvoke_m_31877402_0 (HeaderHandler_t_1637549863_0 * __this, Object_t * ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
