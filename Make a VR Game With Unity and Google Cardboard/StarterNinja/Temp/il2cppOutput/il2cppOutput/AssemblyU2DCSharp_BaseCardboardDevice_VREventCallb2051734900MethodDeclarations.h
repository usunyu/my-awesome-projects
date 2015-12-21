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

// BaseCardboardDevice/VREventCallback
struct VREventCallback_t2051734900_0;
// System.Object
struct Object_t;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"

// System.Void BaseCardboardDevice/VREventCallback::.ctor(System.Object,System.IntPtr)
extern "C"  void VREventCallback__ctor_m618645638_0 (VREventCallback_t2051734900_0 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BaseCardboardDevice/VREventCallback::Invoke(System.Int32)
extern "C"  void VREventCallback_Invoke_m_1495321167_0 (VREventCallback_t2051734900_0 * __this, int32_t ___eventID, const MethodInfo* method) IL2CPP_METHOD_ATTR;
extern "C" void pinvoke_delegate_wrapper_VREventCallback_t2051734900_0(Il2CppObject* delegate, int32_t ___eventID);
// System.IAsyncResult BaseCardboardDevice/VREventCallback::BeginInvoke(System.Int32,System.AsyncCallback,System.Object)
extern "C"  Object_t * VREventCallback_BeginInvoke_m_1889920862_0 (VREventCallback_t2051734900_0 * __this, int32_t ___eventID, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___object, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BaseCardboardDevice/VREventCallback::EndInvoke(System.IAsyncResult)
extern "C"  void VREventCallback_EndInvoke_m_1899467370_0 (VREventCallback_t2051734900_0 * __this, Object_t * ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
