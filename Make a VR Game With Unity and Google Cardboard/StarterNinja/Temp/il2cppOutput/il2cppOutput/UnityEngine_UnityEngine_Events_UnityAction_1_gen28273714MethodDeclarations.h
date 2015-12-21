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

// UnityEngine.Events.UnityAction`1<UnityEngine.Color>
struct UnityAction_1_t28273714_0;
// System.Object
struct Object_t;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"
#include "UnityEngine_UnityEngine_Color_388944582.h"

// System.Void UnityEngine.Events.UnityAction`1<UnityEngine.Color>::.ctor(System.Object,System.IntPtr)
extern "C"  void UnityAction_1__ctor_m_942864700_0_gshared (UnityAction_1_t28273714_0 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method);
#define UnityAction_1__ctor_m_942864700_0(__this, ___object, ___method, method) ((  void (*) (UnityAction_1_t28273714_0 *, Object_t *, IntPtr_t, const MethodInfo*))UnityAction_1__ctor_m_942864700_0_gshared)(__this, ___object, ___method, method)
// System.Void UnityEngine.Events.UnityAction`1<UnityEngine.Color>::Invoke(T0)
extern "C"  void UnityAction_1_Invoke_m_541928434_0_gshared (UnityAction_1_t28273714_0 * __this, Color_t_388944582_0  ___arg0, const MethodInfo* method);
#define UnityAction_1_Invoke_m_541928434_0(__this, ___arg0, method) ((  void (*) (UnityAction_1_t28273714_0 *, Color_t_388944582_0 , const MethodInfo*))UnityAction_1_Invoke_m_541928434_0_gshared)(__this, ___arg0, method)
// System.IAsyncResult UnityEngine.Events.UnityAction`1<UnityEngine.Color>::BeginInvoke(T0,System.AsyncCallback,System.Object)
extern "C"  Object_t * UnityAction_1_BeginInvoke_m_1228981191_0_gshared (UnityAction_1_t28273714_0 * __this, Color_t_388944582_0  ___arg0, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___object, const MethodInfo* method);
#define UnityAction_1_BeginInvoke_m_1228981191_0(__this, ___arg0, ___callback, ___object, method) ((  Object_t * (*) (UnityAction_1_t28273714_0 *, Color_t_388944582_0 , AsyncCallback_t_266361018_0 *, Object_t *, const MethodInfo*))UnityAction_1_BeginInvoke_m_1228981191_0_gshared)(__this, ___arg0, ___callback, ___object, method)
// System.Void UnityEngine.Events.UnityAction`1<UnityEngine.Color>::EndInvoke(System.IAsyncResult)
extern "C"  void UnityAction_1_EndInvoke_m_83158816_0_gshared (UnityAction_1_t28273714_0 * __this, Object_t * ___result, const MethodInfo* method);
#define UnityAction_1_EndInvoke_m_83158816_0(__this, ___result, method) ((  void (*) (UnityAction_1_t28273714_0 *, Object_t *, const MethodInfo*))UnityAction_1_EndInvoke_m_83158816_0_gshared)(__this, ___result, method)
