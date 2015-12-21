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

// System.Collections.Generic.Dictionary`2/Transform`1<System.Int32,System.Int32,System.Int32>
struct Transform_1_t_316753836_0;
// System.Object
struct Object_t;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"

// System.Void System.Collections.Generic.Dictionary`2/Transform`1<System.Int32,System.Int32,System.Int32>::.ctor(System.Object,System.IntPtr)
extern "C"  void Transform_1__ctor_m_592546842_0_gshared (Transform_1_t_316753836_0 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method);
#define Transform_1__ctor_m_592546842_0(__this, ___object, ___method, method) ((  void (*) (Transform_1_t_316753836_0 *, Object_t *, IntPtr_t, const MethodInfo*))Transform_1__ctor_m_592546842_0_gshared)(__this, ___object, ___method, method)
// TRet System.Collections.Generic.Dictionary`2/Transform`1<System.Int32,System.Int32,System.Int32>::Invoke(TKey,TValue)
extern "C"  int32_t Transform_1_Invoke_m_333841070_0_gshared (Transform_1_t_316753836_0 * __this, int32_t ___key, int32_t ___value, const MethodInfo* method);
#define Transform_1_Invoke_m_333841070_0(__this, ___key, ___value, method) ((  int32_t (*) (Transform_1_t_316753836_0 *, int32_t, int32_t, const MethodInfo*))Transform_1_Invoke_m_333841070_0_gshared)(__this, ___key, ___value, method)
// System.IAsyncResult System.Collections.Generic.Dictionary`2/Transform`1<System.Int32,System.Int32,System.Int32>::BeginInvoke(TKey,TValue,System.AsyncCallback,System.Object)
extern "C"  Object_t * Transform_1_BeginInvoke_m_1614149123_0_gshared (Transform_1_t_316753836_0 * __this, int32_t ___key, int32_t ___value, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___object, const MethodInfo* method);
#define Transform_1_BeginInvoke_m_1614149123_0(__this, ___key, ___value, ___callback, ___object, method) ((  Object_t * (*) (Transform_1_t_316753836_0 *, int32_t, int32_t, AsyncCallback_t_266361018_0 *, Object_t *, const MethodInfo*))Transform_1_BeginInvoke_m_1614149123_0_gshared)(__this, ___key, ___value, ___callback, ___object, method)
// TRet System.Collections.Generic.Dictionary`2/Transform`1<System.Int32,System.Int32,System.Int32>::EndInvoke(System.IAsyncResult)
extern "C"  int32_t Transform_1_EndInvoke_m_867730440_0_gshared (Transform_1_t_316753836_0 * __this, Object_t * ___result, const MethodInfo* method);
#define Transform_1_EndInvoke_m_867730440_0(__this, ___result, method) ((  int32_t (*) (Transform_1_t_316753836_0 *, Object_t *, const MethodInfo*))Transform_1_EndInvoke_m_867730440_0_gshared)(__this, ___result, method)
