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

// System.Func`2<System.Object,System.Object>
struct Func_2_t790463728_0;
// System.Object
struct Object_t;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"

// System.Void System.Func`2<System.Object,System.Object>::.ctor(System.Object,System.IntPtr)
extern "C"  void Func_2__ctor_m_350443252_0_gshared (Func_2_t790463728_0 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method);
#define Func_2__ctor_m_350443252_0(__this, ___object, ___method, method) ((  void (*) (Func_2_t790463728_0 *, Object_t *, IntPtr_t, const MethodInfo*))Func_2__ctor_m_350443252_0_gshared)(__this, ___object, ___method, method)
// TResult System.Func`2<System.Object,System.Object>::Invoke(T)
extern "C"  Object_t * Func_2_Invoke_m1924616534_0_gshared (Func_2_t790463728_0 * __this, Object_t * ___arg1, const MethodInfo* method);
#define Func_2_Invoke_m1924616534_0(__this, ___arg1, method) ((  Object_t * (*) (Func_2_t790463728_0 *, Object_t *, const MethodInfo*))Func_2_Invoke_m1924616534_0_gshared)(__this, ___arg1, method)
// System.IAsyncResult System.Func`2<System.Object,System.Object>::BeginInvoke(T,System.AsyncCallback,System.Object)
extern "C"  Object_t * Func_2_BeginInvoke_m_13263995_0_gshared (Func_2_t790463728_0 * __this, Object_t * ___arg1, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___object, const MethodInfo* method);
#define Func_2_BeginInvoke_m_13263995_0(__this, ___arg1, ___callback, ___object, method) ((  Object_t * (*) (Func_2_t790463728_0 *, Object_t *, AsyncCallback_t_266361018_0 *, Object_t *, const MethodInfo*))Func_2_BeginInvoke_m_13263995_0_gshared)(__this, ___arg1, ___callback, ___object, method)
// TResult System.Func`2<System.Object,System.Object>::EndInvoke(System.IAsyncResult)
extern "C"  Object_t * Func_2_EndInvoke_m_176798658_0_gshared (Func_2_t790463728_0 * __this, Object_t * ___result, const MethodInfo* method);
#define Func_2_EndInvoke_m_176798658_0(__this, ___result, method) ((  Object_t * (*) (Func_2_t790463728_0 *, Object_t *, const MethodInfo*))Func_2_EndInvoke_m_176798658_0_gshared)(__this, ___result, method)
