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

// Cardboard/StereoScreenChangeDelegate
struct StereoScreenChangeDelegate_t509462125_0;
// System.Object
struct Object_t;
// UnityEngine.RenderTexture
struct RenderTexture_t1203146108_0;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"

// System.Void Cardboard/StereoScreenChangeDelegate::.ctor(System.Object,System.IntPtr)
extern "C"  void StereoScreenChangeDelegate__ctor_m_185041735_0 (StereoScreenChangeDelegate_t509462125_0 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard/StereoScreenChangeDelegate::Invoke(UnityEngine.RenderTexture)
extern "C"  void StereoScreenChangeDelegate_Invoke_m_1149378511_0 (StereoScreenChangeDelegate_t509462125_0 * __this, RenderTexture_t1203146108_0 * ___newStereoScreen, const MethodInfo* method) IL2CPP_METHOD_ATTR;
extern "C" void pinvoke_delegate_wrapper_StereoScreenChangeDelegate_t509462125_0(Il2CppObject* delegate, RenderTexture_t1203146108_0 * ___newStereoScreen);
// System.IAsyncResult Cardboard/StereoScreenChangeDelegate::BeginInvoke(UnityEngine.RenderTexture,System.AsyncCallback,System.Object)
extern "C"  Object_t * StereoScreenChangeDelegate_BeginInvoke_m_261767758_0 (StereoScreenChangeDelegate_t509462125_0 * __this, RenderTexture_t1203146108_0 * ___newStereoScreen, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___object, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard/StereoScreenChangeDelegate::EndInvoke(System.IAsyncResult)
extern "C"  void StereoScreenChangeDelegate_EndInvoke_m_789499063_0 (StereoScreenChangeDelegate_t509462125_0 * __this, Object_t * ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
