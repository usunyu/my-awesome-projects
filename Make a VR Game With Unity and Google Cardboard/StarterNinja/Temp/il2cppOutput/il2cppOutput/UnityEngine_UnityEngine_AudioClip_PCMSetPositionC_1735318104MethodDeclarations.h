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

// UnityEngine.AudioClip/PCMSetPositionCallback
struct PCMSetPositionCallback_t_1735318104_0;
// System.Object
struct Object_t;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"

// System.Void UnityEngine.AudioClip/PCMSetPositionCallback::.ctor(System.Object,System.IntPtr)
extern "C"  void PCMSetPositionCallback__ctor_m_1308466444_0 (PCMSetPositionCallback_t_1735318104_0 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.AudioClip/PCMSetPositionCallback::Invoke(System.Int32)
extern "C"  void PCMSetPositionCallback_Invoke_m1757186207_0 (PCMSetPositionCallback_t_1735318104_0 * __this, int32_t ___position, const MethodInfo* method) IL2CPP_METHOD_ATTR;
extern "C" void pinvoke_delegate_wrapper_PCMSetPositionCallback_t_1735318104_0(Il2CppObject* delegate, int32_t ___position);
// System.IAsyncResult UnityEngine.AudioClip/PCMSetPositionCallback::BeginInvoke(System.Int32,System.AsyncCallback,System.Object)
extern "C"  Object_t * PCMSetPositionCallback_BeginInvoke_m_335628264_0 (PCMSetPositionCallback_t_1735318104_0 * __this, int32_t ___position, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___object, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.AudioClip/PCMSetPositionCallback::EndInvoke(System.IAsyncResult)
extern "C"  void PCMSetPositionCallback_EndInvoke_m239431428_0 (PCMSetPositionCallback_t_1735318104_0 * __this, Object_t * ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
