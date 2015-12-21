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

// UnityEngine.iOS.ADBannerView/BannerFailedToLoadDelegate
struct BannerFailedToLoadDelegate_t_2063426560_0;
// System.Object
struct Object_t;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"

// System.Void UnityEngine.iOS.ADBannerView/BannerFailedToLoadDelegate::.ctor(System.Object,System.IntPtr)
extern "C"  void BannerFailedToLoadDelegate__ctor_m_1665395694_0 (BannerFailedToLoadDelegate_t_2063426560_0 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.ADBannerView/BannerFailedToLoadDelegate::Invoke()
extern "C"  void BannerFailedToLoadDelegate_Invoke_m_1032539412_0 (BannerFailedToLoadDelegate_t_2063426560_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
extern "C" void pinvoke_delegate_wrapper_BannerFailedToLoadDelegate_t_2063426560_0(Il2CppObject* delegate);
// System.IAsyncResult UnityEngine.iOS.ADBannerView/BannerFailedToLoadDelegate::BeginInvoke(System.AsyncCallback,System.Object)
extern "C"  Object_t * BannerFailedToLoadDelegate_BeginInvoke_m1073531935_0 (BannerFailedToLoadDelegate_t_2063426560_0 * __this, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___object, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.ADBannerView/BannerFailedToLoadDelegate::EndInvoke(System.IAsyncResult)
extern "C"  void BannerFailedToLoadDelegate_EndInvoke_m_699375838_0 (BannerFailedToLoadDelegate_t_2063426560_0 * __this, Object_t * ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
