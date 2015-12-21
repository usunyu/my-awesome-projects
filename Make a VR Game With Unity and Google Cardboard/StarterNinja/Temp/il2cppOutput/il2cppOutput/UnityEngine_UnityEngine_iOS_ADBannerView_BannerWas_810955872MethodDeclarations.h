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

// UnityEngine.iOS.ADBannerView/BannerWasClickedDelegate
struct BannerWasClickedDelegate_t_810955872_0;
// System.Object
struct Object_t;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"

// System.Void UnityEngine.iOS.ADBannerView/BannerWasClickedDelegate::.ctor(System.Object,System.IntPtr)
extern "C"  void BannerWasClickedDelegate__ctor_m1483041906_0 (BannerWasClickedDelegate_t_810955872_0 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.ADBannerView/BannerWasClickedDelegate::Invoke()
extern "C"  void BannerWasClickedDelegate_Invoke_m1164690252_0 (BannerWasClickedDelegate_t_810955872_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
extern "C" void pinvoke_delegate_wrapper_BannerWasClickedDelegate_t_810955872_0(Il2CppObject* delegate);
// System.IAsyncResult UnityEngine.iOS.ADBannerView/BannerWasClickedDelegate::BeginInvoke(System.AsyncCallback,System.Object)
extern "C"  Object_t * BannerWasClickedDelegate_BeginInvoke_m_1831247681_0 (BannerWasClickedDelegate_t_810955872_0 * __this, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___object, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.ADBannerView/BannerWasClickedDelegate::EndInvoke(System.IAsyncResult)
extern "C"  void BannerWasClickedDelegate_EndInvoke_m_1573591166_0 (BannerWasClickedDelegate_t_810955872_0 * __this, Object_t * ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
