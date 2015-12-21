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

// UnityEngine.RectTransform/ReapplyDrivenProperties
struct ReapplyDrivenProperties_t_1640169918_0;
// System.Object
struct Object_t;
// UnityEngine.RectTransform
struct RectTransform_t212748479_0;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"

// System.Void UnityEngine.RectTransform/ReapplyDrivenProperties::.ctor(System.Object,System.IntPtr)
extern "C"  void ReapplyDrivenProperties__ctor_m_584058988_0 (ReapplyDrivenProperties_t_1640169918_0 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.RectTransform/ReapplyDrivenProperties::Invoke(UnityEngine.RectTransform)
extern "C"  void ReapplyDrivenProperties_Invoke_m_414332141_0 (ReapplyDrivenProperties_t_1640169918_0 * __this, RectTransform_t212748479_0 * ___driven, const MethodInfo* method) IL2CPP_METHOD_ATTR;
extern "C" void pinvoke_delegate_wrapper_ReapplyDrivenProperties_t_1640169918_0(Il2CppObject* delegate, RectTransform_t212748479_0 * ___driven);
// System.IAsyncResult UnityEngine.RectTransform/ReapplyDrivenProperties::BeginInvoke(UnityEngine.RectTransform,System.AsyncCallback,System.Object)
extern "C"  Object_t * ReapplyDrivenProperties_BeginInvoke_m1851329218_0 (ReapplyDrivenProperties_t_1640169918_0 * __this, RectTransform_t212748479_0 * ___driven, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___object, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.RectTransform/ReapplyDrivenProperties::EndInvoke(System.IAsyncResult)
extern "C"  void ReapplyDrivenProperties_EndInvoke_m_608808028_0 (ReapplyDrivenProperties_t_1640169918_0 * __this, Object_t * ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
