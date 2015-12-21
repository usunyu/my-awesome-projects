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

// System.Reflection.MonoProperty/Getter`2<System.Object,System.Object>
struct Getter_2_t_699459842_0;
// System.Object
struct Object_t;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"

// System.Void System.Reflection.MonoProperty/Getter`2<System.Object,System.Object>::.ctor(System.Object,System.IntPtr)
extern "C"  void Getter_2__ctor_m_58040502_0_gshared (Getter_2_t_699459842_0 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method);
#define Getter_2__ctor_m_58040502_0(__this, ___object, ___method, method) ((  void (*) (Getter_2_t_699459842_0 *, Object_t *, IntPtr_t, const MethodInfo*))Getter_2__ctor_m_58040502_0_gshared)(__this, ___object, ___method, method)
// R System.Reflection.MonoProperty/Getter`2<System.Object,System.Object>::Invoke(T)
extern "C"  Object_t * Getter_2_Invoke_m410564889_0_gshared (Getter_2_t_699459842_0 * __this, Object_t * ____this, const MethodInfo* method);
#define Getter_2_Invoke_m410564889_0(__this, ____this, method) ((  Object_t * (*) (Getter_2_t_699459842_0 *, Object_t *, const MethodInfo*))Getter_2_Invoke_m410564889_0_gshared)(__this, ____this, method)
// System.IAsyncResult System.Reflection.MonoProperty/Getter`2<System.Object,System.Object>::BeginInvoke(T,System.AsyncCallback,System.Object)
extern "C"  Object_t * Getter_2_BeginInvoke_m_1148745849_0_gshared (Getter_2_t_699459842_0 * __this, Object_t * ____this, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___object, const MethodInfo* method);
#define Getter_2_BeginInvoke_m_1148745849_0(__this, ____this, ___callback, ___object, method) ((  Object_t * (*) (Getter_2_t_699459842_0 *, Object_t *, AsyncCallback_t_266361018_0 *, Object_t *, const MethodInfo*))Getter_2_BeginInvoke_m_1148745849_0_gshared)(__this, ____this, ___callback, ___object, method)
// R System.Reflection.MonoProperty/Getter`2<System.Object,System.Object>::EndInvoke(System.IAsyncResult)
extern "C"  Object_t * Getter_2_EndInvoke_m1749574747_0_gshared (Getter_2_t_699459842_0 * __this, Object_t * ___result, const MethodInfo* method);
#define Getter_2_EndInvoke_m1749574747_0(__this, ___result, method) ((  Object_t * (*) (Getter_2_t_699459842_0 *, Object_t *, const MethodInfo*))Getter_2_EndInvoke_m1749574747_0_gshared)(__this, ___result, method)
