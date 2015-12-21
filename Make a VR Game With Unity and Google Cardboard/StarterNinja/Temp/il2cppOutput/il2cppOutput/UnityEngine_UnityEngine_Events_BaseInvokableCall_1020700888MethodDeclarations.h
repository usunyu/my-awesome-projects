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

// UnityEngine.Events.BaseInvokableCall
struct BaseInvokableCall_t_1020700888_0;
// System.Object
struct Object_t;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// System.Delegate
struct Delegate_t_1791715840_0;

#include "codegen/il2cpp-codegen.h"

// System.Void UnityEngine.Events.BaseInvokableCall::.ctor()
extern "C"  void BaseInvokableCall__ctor_m_1455151634_0 (BaseInvokableCall_t_1020700888_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Events.BaseInvokableCall::.ctor(System.Object,System.Reflection.MethodInfo)
extern "C"  void BaseInvokableCall__ctor_m1692884045_0 (BaseInvokableCall_t_1020700888_0 * __this, Object_t * ___target, MethodInfo_t * ___function, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Events.BaseInvokableCall::AllowInvoke(System.Delegate)
extern "C"  bool BaseInvokableCall_AllowInvoke_m_1353306201_0 (Object_t * __this /* static, unused */, Delegate_t_1791715840_0 * ___delegate, const MethodInfo* method) IL2CPP_METHOD_ATTR;
