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

// UnityEngine.Camera/CameraCallback
struct CameraCallback_t667352747_0;
// System.Object
struct Object_t;
// UnityEngine.Camera
struct Camera_t814710830_0;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"

// System.Void UnityEngine.Camera/CameraCallback::.ctor(System.Object,System.IntPtr)
extern "C"  void CameraCallback__ctor_m_318685827_0 (CameraCallback_t667352747_0 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Camera/CameraCallback::Invoke(UnityEngine.Camera)
extern "C"  void CameraCallback_Invoke_m_537556741_0 (CameraCallback_t667352747_0 * __this, Camera_t814710830_0 * ___cam, const MethodInfo* method) IL2CPP_METHOD_ATTR;
extern "C" void pinvoke_delegate_wrapper_CameraCallback_t667352747_0(Il2CppObject* delegate, Camera_t814710830_0 * ___cam);
// System.IAsyncResult UnityEngine.Camera/CameraCallback::BeginInvoke(UnityEngine.Camera,System.AsyncCallback,System.Object)
extern "C"  Object_t * CameraCallback_BeginInvoke_m_575421786_0 (CameraCallback_t667352747_0 * __this, Camera_t814710830_0 * ___cam, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___object, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Camera/CameraCallback::EndInvoke(System.IAsyncResult)
extern "C"  void CameraCallback_EndInvoke_m534836749_0 (CameraCallback_t667352747_0 * __this, Object_t * ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
