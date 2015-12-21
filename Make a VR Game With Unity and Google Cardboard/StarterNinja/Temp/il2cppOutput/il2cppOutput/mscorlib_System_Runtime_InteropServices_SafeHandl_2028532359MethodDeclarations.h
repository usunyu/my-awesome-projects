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

// System.Runtime.InteropServices.SafeHandle
struct SafeHandle_t_2028532359_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"

// System.Void System.Runtime.InteropServices.SafeHandle::.ctor(System.IntPtr,System.Boolean)
extern "C"  void SafeHandle__ctor_m1568307360_0 (SafeHandle_t_2028532359_0 * __this, IntPtr_t ___invalidHandleValue, bool ___ownsHandle, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.InteropServices.SafeHandle::Close()
extern "C"  void SafeHandle_Close_m_1599772275_0 (SafeHandle_t_2028532359_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.InteropServices.SafeHandle::DangerousAddRef(System.Boolean&)
extern "C"  void SafeHandle_DangerousAddRef_m2051469412_0 (SafeHandle_t_2028532359_0 * __this, bool* ___success, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.IntPtr System.Runtime.InteropServices.SafeHandle::DangerousGetHandle()
extern "C"  IntPtr_t SafeHandle_DangerousGetHandle_m_181382644_0 (SafeHandle_t_2028532359_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.InteropServices.SafeHandle::DangerousRelease()
extern "C"  void SafeHandle_DangerousRelease_m_1743679734_0 (SafeHandle_t_2028532359_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.InteropServices.SafeHandle::Dispose()
extern "C"  void SafeHandle_Dispose_m951873268_0 (SafeHandle_t_2028532359_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.InteropServices.SafeHandle::Dispose(System.Boolean)
extern "C"  void SafeHandle_Dispose_m787212651_0 (SafeHandle_t_2028532359_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.InteropServices.SafeHandle::SetHandle(System.IntPtr)
extern "C"  void SafeHandle_SetHandle_m1470505077_0 (SafeHandle_t_2028532359_0 * __this, IntPtr_t ___handle, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.InteropServices.SafeHandle::Finalize()
extern "C"  void SafeHandle_Finalize_m_1595935605_0 (SafeHandle_t_2028532359_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
