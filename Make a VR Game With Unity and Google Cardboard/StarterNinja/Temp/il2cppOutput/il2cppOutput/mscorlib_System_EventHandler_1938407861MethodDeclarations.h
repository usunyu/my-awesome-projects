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

// System.EventHandler
struct EventHandler_t_1938407861_0;
// System.Object
struct Object_t;
// System.EventArgs
struct EventArgs_t693055868_0;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"

// System.Void System.EventHandler::.ctor(System.Object,System.IntPtr)
extern "C"  void EventHandler__ctor_m_198498979_0 (EventHandler_t_1938407861_0 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.EventHandler::Invoke(System.Object,System.EventArgs)
extern "C"  void EventHandler_Invoke_m1659461265_0 (EventHandler_t_1938407861_0 * __this, Object_t * ___sender, EventArgs_t693055868_0 * ___e, const MethodInfo* method) IL2CPP_METHOD_ATTR;
extern "C" void pinvoke_delegate_wrapper_EventHandler_t_1938407861_0(Il2CppObject* delegate, Object_t * ___sender, EventArgs_t693055868_0 * ___e);
// System.IAsyncResult System.EventHandler::BeginInvoke(System.Object,System.EventArgs,System.AsyncCallback,System.Object)
extern "C"  Object_t * EventHandler_BeginInvoke_m76205456_0 (EventHandler_t_1938407861_0 * __this, Object_t * ___sender, EventArgs_t693055868_0 * ___e, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___object, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.EventHandler::EndInvoke(System.IAsyncResult)
extern "C"  void EventHandler_EndInvoke_m_1862677011_0 (EventHandler_t_1938407861_0 * __this, Object_t * ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
