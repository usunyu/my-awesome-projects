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

// UnityEngine.Events.UnityEvent
struct UnityEvent_t158998417_0;
// UnityEngine.Events.UnityAction
struct UnityAction_t502362143_0;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// System.String
struct String_t;
// System.Object
struct Object_t;
// UnityEngine.Events.BaseInvokableCall
struct BaseInvokableCall_t_1020700888_0;

#include "codegen/il2cpp-codegen.h"

// System.Void UnityEngine.Events.UnityEvent::.ctor()
extern "C"  void UnityEvent__ctor_m1715209183_0 (UnityEvent_t158998417_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Events.UnityEvent::AddListener(UnityEngine.Events.UnityAction)
extern "C"  void UnityEvent_AddListener_m_195826427_0 (UnityEvent_t158998417_0 * __this, UnityAction_t502362143_0 * ___call, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodInfo UnityEngine.Events.UnityEvent::FindMethod_Impl(System.String,System.Object)
extern "C"  MethodInfo_t * UnityEvent_FindMethod_Impl_m_1397746478_0 (UnityEvent_t158998417_0 * __this, String_t* ___name, Object_t * ___targetObj, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Events.BaseInvokableCall UnityEngine.Events.UnityEvent::GetDelegate(System.Object,System.Reflection.MethodInfo)
extern "C"  BaseInvokableCall_t_1020700888_0 * UnityEvent_GetDelegate_m2043983920_0 (UnityEvent_t158998417_0 * __this, Object_t * ___target, MethodInfo_t * ___theFunction, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Events.BaseInvokableCall UnityEngine.Events.UnityEvent::GetDelegate(UnityEngine.Events.UnityAction)
extern "C"  BaseInvokableCall_t_1020700888_0 * UnityEvent_GetDelegate_m1012258596_0 (Object_t * __this /* static, unused */, UnityAction_t502362143_0 * ___action, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Events.UnityEvent::Invoke()
extern "C"  void UnityEvent_Invoke_m_1622137091_0 (UnityEvent_t158998417_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
