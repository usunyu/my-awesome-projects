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

// UnityEngine.iOS.ADInterstitialAd/InterstitialWasViewedDelegate
struct InterstitialWasViewedDelegate_t115473043_0;
// System.Object
struct Object_t;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"

// System.Void UnityEngine.iOS.ADInterstitialAd/InterstitialWasViewedDelegate::.ctor(System.Object,System.IntPtr)
extern "C"  void InterstitialWasViewedDelegate__ctor_m_1542949601_0 (InterstitialWasViewedDelegate_t115473043_0 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.ADInterstitialAd/InterstitialWasViewedDelegate::Invoke()
extern "C"  void InterstitialWasViewedDelegate_Invoke_m_1256338887_0 (InterstitialWasViewedDelegate_t115473043_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
extern "C" void pinvoke_delegate_wrapper_InterstitialWasViewedDelegate_t115473043_0(Il2CppObject* delegate);
// System.IAsyncResult UnityEngine.iOS.ADInterstitialAd/InterstitialWasViewedDelegate::BeginInvoke(System.AsyncCallback,System.Object)
extern "C"  Object_t * InterstitialWasViewedDelegate_BeginInvoke_m_1153662294_0 (InterstitialWasViewedDelegate_t115473043_0 * __this, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___object, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.ADInterstitialAd/InterstitialWasViewedDelegate::EndInvoke(System.IAsyncResult)
extern "C"  void InterstitialWasViewedDelegate_EndInvoke_m971591343_0 (InterstitialWasViewedDelegate_t115473043_0 * __this, Object_t * ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
