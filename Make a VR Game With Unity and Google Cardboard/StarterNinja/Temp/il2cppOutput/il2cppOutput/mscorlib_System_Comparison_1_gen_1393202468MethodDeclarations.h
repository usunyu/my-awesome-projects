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

// System.Comparison`1<UnityEngine.RaycastHit>
struct Comparison_1_t_1393202468_0;
// System.Object
struct Object_t;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"
#include "UnityEngine_UnityEngine_RaycastHit144185587.h"

// System.Void System.Comparison`1<UnityEngine.RaycastHit>::.ctor(System.Object,System.IntPtr)
extern "C"  void Comparison_1__ctor_m_1624573074_0_gshared (Comparison_1_t_1393202468_0 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method);
#define Comparison_1__ctor_m_1624573074_0(__this, ___object, ___method, method) ((  void (*) (Comparison_1_t_1393202468_0 *, Object_t *, IntPtr_t, const MethodInfo*))Comparison_1__ctor_m_1624573074_0_gshared)(__this, ___object, ___method, method)
// System.Int32 System.Comparison`1<UnityEngine.RaycastHit>::Invoke(T,T)
extern "C"  int32_t Comparison_1_Invoke_m1503417360_0_gshared (Comparison_1_t_1393202468_0 * __this, RaycastHit_t144185587_0  ___x, RaycastHit_t144185587_0  ___y, const MethodInfo* method);
#define Comparison_1_Invoke_m1503417360_0(__this, ___x, ___y, method) ((  int32_t (*) (Comparison_1_t_1393202468_0 *, RaycastHit_t144185587_0 , RaycastHit_t144185587_0 , const MethodInfo*))Comparison_1_Invoke_m1503417360_0_gshared)(__this, ___x, ___y, method)
// System.IAsyncResult System.Comparison`1<UnityEngine.RaycastHit>::BeginInvoke(T,T,System.AsyncCallback,System.Object)
extern "C"  Object_t * Comparison_1_BeginInvoke_m589252441_0_gshared (Comparison_1_t_1393202468_0 * __this, RaycastHit_t144185587_0  ___x, RaycastHit_t144185587_0  ___y, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___object, const MethodInfo* method);
#define Comparison_1_BeginInvoke_m589252441_0(__this, ___x, ___y, ___callback, ___object, method) ((  Object_t * (*) (Comparison_1_t_1393202468_0 *, RaycastHit_t144185587_0 , RaycastHit_t144185587_0 , AsyncCallback_t_266361018_0 *, Object_t *, const MethodInfo*))Comparison_1_BeginInvoke_m589252441_0_gshared)(__this, ___x, ___y, ___callback, ___object, method)
// System.Int32 System.Comparison`1<UnityEngine.RaycastHit>::EndInvoke(System.IAsyncResult)
extern "C"  int32_t Comparison_1_EndInvoke_m_1384136100_0_gshared (Comparison_1_t_1393202468_0 * __this, Object_t * ___result, const MethodInfo* method);
#define Comparison_1_EndInvoke_m_1384136100_0(__this, ___result, method) ((  int32_t (*) (Comparison_1_t_1393202468_0 *, Object_t *, const MethodInfo*))Comparison_1_EndInvoke_m_1384136100_0_gshared)(__this, ___result, method)
