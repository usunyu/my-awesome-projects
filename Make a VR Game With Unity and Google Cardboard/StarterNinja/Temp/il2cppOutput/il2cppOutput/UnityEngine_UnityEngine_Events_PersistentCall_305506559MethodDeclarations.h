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

// UnityEngine.Events.PersistentCall
struct PersistentCall_t_305506559_0;
// UnityEngine.Object
struct Object_t1159094344_0;
struct Object_t1159094344_0_marshaled;
// System.String
struct String_t;
// UnityEngine.Events.ArgumentCache
struct ArgumentCache_t_1701071911_0;
// UnityEngine.Events.BaseInvokableCall
struct BaseInvokableCall_t_1020700888_0;
// UnityEngine.Events.UnityEventBase
struct UnityEventBase_t2037213698_0;
// System.Reflection.MethodInfo
struct MethodInfo_t;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Events_PersistentListenerMod_2457062.h"

// System.Void UnityEngine.Events.PersistentCall::.ctor()
extern "C"  void PersistentCall__ctor_m_931628049_0 (PersistentCall_t_305506559_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Object UnityEngine.Events.PersistentCall::get_target()
extern "C"  Object_t1159094344_0 * PersistentCall_get_target_m_894077546_0 (PersistentCall_t_305506559_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.Events.PersistentCall::get_methodName()
extern "C"  String_t* PersistentCall_get_methodName_m_1272993945_0 (PersistentCall_t_305506559_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Events.PersistentListenerMode UnityEngine.Events.PersistentCall::get_mode()
extern "C"  int32_t PersistentCall_get_mode_m1522877562_0 (PersistentCall_t_305506559_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Events.ArgumentCache UnityEngine.Events.PersistentCall::get_arguments()
extern "C"  ArgumentCache_t_1701071911_0 * PersistentCall_get_arguments_m1871980514_0 (PersistentCall_t_305506559_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Events.PersistentCall::IsValid()
extern "C"  bool PersistentCall_IsValid_m1010437221_0 (PersistentCall_t_305506559_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Events.BaseInvokableCall UnityEngine.Events.PersistentCall::GetRuntimeCall(UnityEngine.Events.UnityEventBase)
extern "C"  BaseInvokableCall_t_1020700888_0 * PersistentCall_GetRuntimeCall_m_382106686_0 (PersistentCall_t_305506559_0 * __this, UnityEventBase_t2037213698_0 * ___theEvent, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Events.BaseInvokableCall UnityEngine.Events.PersistentCall::GetObjectCall(UnityEngine.Object,System.Reflection.MethodInfo,UnityEngine.Events.ArgumentCache)
extern "C"  BaseInvokableCall_t_1020700888_0 * PersistentCall_GetObjectCall_m1043326447_0 (Object_t * __this /* static, unused */, Object_t1159094344_0 * ___target, MethodInfo_t * ___method, ArgumentCache_t_1701071911_0 * ___arguments, const MethodInfo* method) IL2CPP_METHOD_ATTR;
