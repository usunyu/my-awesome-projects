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

// UnityEngine.Application/LogCallback
struct LogCallback_t_1328739487_0;
// System.Object
struct Object_t;
// System.String
struct String_t;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"
#include "UnityEngine_UnityEngine_LogType_721401675.h"
#include "mscorlib_System_String_756155572.h"

// System.Void UnityEngine.Application/LogCallback::.ctor(System.Object,System.IntPtr)
extern "C"  void LogCallback__ctor_m286543475_0 (LogCallback_t_1328739487_0 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Application/LogCallback::Invoke(System.String,System.String,UnityEngine.LogType)
extern "C"  void LogCallback_Invoke_m1886455446_0 (LogCallback_t_1328739487_0 * __this, String_t* ___condition, String_t* ___stackTrace, int32_t ___type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
extern "C" void pinvoke_delegate_wrapper_LogCallback_t_1328739487_0(Il2CppObject* delegate, String_t* ___condition, String_t* ___stackTrace, int32_t ___type);
// System.IAsyncResult UnityEngine.Application/LogCallback::BeginInvoke(System.String,System.String,UnityEngine.LogType,System.AsyncCallback,System.Object)
extern "C"  Object_t * LogCallback_BeginInvoke_m1640350401_0 (LogCallback_t_1328739487_0 * __this, String_t* ___condition, String_t* ___stackTrace, int32_t ___type, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___object, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Application/LogCallback::EndInvoke(System.IAsyncResult)
extern "C"  void LogCallback_EndInvoke_m_1411452413_0 (LogCallback_t_1328739487_0 * __this, Object_t * ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
