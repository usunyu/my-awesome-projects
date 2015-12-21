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

// UnityEngine.iOS.ADInterstitialAd/InterstitialWasLoadedDelegate
struct InterstitialWasLoadedDelegate_t_1618319468_0;
// System.Object
struct Object_t;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"

// System.Void UnityEngine.iOS.ADInterstitialAd/InterstitialWasLoadedDelegate::.ctor(System.Object,System.IntPtr)
extern "C"  void InterstitialWasLoadedDelegate__ctor_m_1855572576_0 (InterstitialWasLoadedDelegate_t_1618319468_0 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.ADInterstitialAd/InterstitialWasLoadedDelegate::Invoke()
extern "C"  void InterstitialWasLoadedDelegate_Invoke_m_1866028550_0 (InterstitialWasLoadedDelegate_t_1618319468_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
extern "C" void pinvoke_delegate_wrapper_InterstitialWasLoadedDelegate_t_1618319468_0(Il2CppObject* delegate);
// System.IAsyncResult UnityEngine.iOS.ADInterstitialAd/InterstitialWasLoadedDelegate::BeginInvoke(System.AsyncCallback,System.Object)
extern "C"  Object_t * InterstitialWasLoadedDelegate_BeginInvoke_m1425628105_0 (InterstitialWasLoadedDelegate_t_1618319468_0 * __this, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___object, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.ADInterstitialAd/InterstitialWasLoadedDelegate::EndInvoke(System.IAsyncResult)
extern "C"  void InterstitialWasLoadedDelegate_EndInvoke_m_1955235920_0 (InterstitialWasLoadedDelegate_t_1618319468_0 * __this, Object_t * ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
