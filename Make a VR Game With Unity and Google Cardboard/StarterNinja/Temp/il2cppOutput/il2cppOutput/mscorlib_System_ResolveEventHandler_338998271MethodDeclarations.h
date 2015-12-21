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

// System.ResolveEventHandler
struct ResolveEventHandler_t_338998271_0;
// System.Object
struct Object_t;
// System.Reflection.Assembly
struct Assembly_t_957553394_0;
// System.ResolveEventArgs
struct ResolveEventArgs_t362672006_0;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"

// System.Void System.ResolveEventHandler::.ctor(System.Object,System.IntPtr)
extern "C"  void ResolveEventHandler__ctor_m_1870651635_0 (ResolveEventHandler_t_338998271_0 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.Assembly System.ResolveEventHandler::Invoke(System.Object,System.ResolveEventArgs)
extern "C"  Assembly_t_957553394_0 * ResolveEventHandler_Invoke_m_87254130_0 (ResolveEventHandler_t_338998271_0 * __this, Object_t * ___sender, ResolveEventArgs_t362672006_0 * ___args, const MethodInfo* method) IL2CPP_METHOD_ATTR;
extern "C" Assembly_t_957553394_0 * pinvoke_delegate_wrapper_ResolveEventHandler_t_338998271_0(Il2CppObject* delegate, Object_t * ___sender, ResolveEventArgs_t362672006_0 * ___args);
// System.IAsyncResult System.ResolveEventHandler::BeginInvoke(System.Object,System.ResolveEventArgs,System.AsyncCallback,System.Object)
extern "C"  Object_t * ResolveEventHandler_BeginInvoke_m1625165996_0 (ResolveEventHandler_t_338998271_0 * __this, Object_t * ___sender, ResolveEventArgs_t362672006_0 * ___args, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___object, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.Assembly System.ResolveEventHandler::EndInvoke(System.IAsyncResult)
extern "C"  Assembly_t_957553394_0 * ResolveEventHandler_EndInvoke_m_1243316546_0 (ResolveEventHandler_t_338998271_0 * __this, Object_t * ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
