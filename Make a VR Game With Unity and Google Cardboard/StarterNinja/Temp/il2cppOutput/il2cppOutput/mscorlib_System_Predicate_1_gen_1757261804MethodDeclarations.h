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

// System.Predicate`1<UnityEngine.Vector3>
struct Predicate_1_t_1757261804_0;
// System.Object
struct Object_t;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"
#include "UnityEngine_UnityEngine_Vector3_725341337.h"

// System.Void System.Predicate`1<UnityEngine.Vector3>::.ctor(System.Object,System.IntPtr)
extern "C"  void Predicate_1__ctor_m313728806_0_gshared (Predicate_1_t_1757261804_0 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method);
#define Predicate_1__ctor_m313728806_0(__this, ___object, ___method, method) ((  void (*) (Predicate_1_t_1757261804_0 *, Object_t *, IntPtr_t, const MethodInfo*))Predicate_1__ctor_m313728806_0_gshared)(__this, ___object, ___method, method)
// System.Boolean System.Predicate`1<UnityEngine.Vector3>::Invoke(T)
extern "C"  bool Predicate_1_Invoke_m1923698912_0_gshared (Predicate_1_t_1757261804_0 * __this, Vector3_t_725341337_0  ___obj, const MethodInfo* method);
#define Predicate_1_Invoke_m1923698912_0(__this, ___obj, method) ((  bool (*) (Predicate_1_t_1757261804_0 *, Vector3_t_725341337_0 , const MethodInfo*))Predicate_1_Invoke_m1923698912_0_gshared)(__this, ___obj, method)
// System.IAsyncResult System.Predicate`1<UnityEngine.Vector3>::BeginInvoke(T,System.AsyncCallback,System.Object)
extern "C"  Object_t * Predicate_1_BeginInvoke_m2038491315_0_gshared (Predicate_1_t_1757261804_0 * __this, Vector3_t_725341337_0  ___obj, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___object, const MethodInfo* method);
#define Predicate_1_BeginInvoke_m2038491315_0(__this, ___obj, ___callback, ___object, method) ((  Object_t * (*) (Predicate_1_t_1757261804_0 *, Vector3_t_725341337_0 , AsyncCallback_t_266361018_0 *, Object_t *, const MethodInfo*))Predicate_1_BeginInvoke_m2038491315_0_gshared)(__this, ___obj, ___callback, ___object, method)
// System.Boolean System.Predicate`1<UnityEngine.Vector3>::EndInvoke(System.IAsyncResult)
extern "C"  bool Predicate_1_EndInvoke_m_1088405772_0_gshared (Predicate_1_t_1757261804_0 * __this, Object_t * ___result, const MethodInfo* method);
#define Predicate_1_EndInvoke_m_1088405772_0(__this, ___result, method) ((  bool (*) (Predicate_1_t_1757261804_0 *, Object_t *, const MethodInfo*))Predicate_1_EndInvoke_m_1088405772_0_gshared)(__this, ___result, method)
