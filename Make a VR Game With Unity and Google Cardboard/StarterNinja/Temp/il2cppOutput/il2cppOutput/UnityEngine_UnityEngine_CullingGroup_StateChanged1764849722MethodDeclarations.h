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

// UnityEngine.CullingGroup/StateChanged
struct StateChanged_t1764849722_0;
// System.Object
struct Object_t;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"
#include "UnityEngine_UnityEngine_CullingGroupEvent_2104861694.h"

// System.Void UnityEngine.CullingGroup/StateChanged::.ctor(System.Object,System.IntPtr)
extern "C"  void StateChanged__ctor_m_1027941876_0 (StateChanged_t1764849722_0 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CullingGroup/StateChanged::Invoke(UnityEngine.CullingGroupEvent)
extern "C"  void StateChanged_Invoke_m_1120436680_0 (StateChanged_t1764849722_0 * __this, CullingGroupEvent_t_2104861694_0  ___sphere, const MethodInfo* method) IL2CPP_METHOD_ATTR;
extern "C" void pinvoke_delegate_wrapper_StateChanged_t1764849722_0(Il2CppObject* delegate, CullingGroupEvent_t_2104861694_0  ___sphere);
// System.IAsyncResult UnityEngine.CullingGroup/StateChanged::BeginInvoke(UnityEngine.CullingGroupEvent,System.AsyncCallback,System.Object)
extern "C"  Object_t * StateChanged_BeginInvoke_m163021837_0 (StateChanged_t1764849722_0 * __this, CullingGroupEvent_t_2104861694_0  ___sphere, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___object, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.CullingGroup/StateChanged::EndInvoke(System.IAsyncResult)
extern "C"  void StateChanged_EndInvoke_m_112905700_0 (StateChanged_t1764849722_0 * __this, Object_t * ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
