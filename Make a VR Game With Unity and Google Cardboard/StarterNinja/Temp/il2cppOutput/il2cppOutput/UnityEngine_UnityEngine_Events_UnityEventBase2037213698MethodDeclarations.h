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

// UnityEngine.Events.UnityEventBase
struct UnityEventBase_t2037213698_0;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// UnityEngine.Events.PersistentCall
struct PersistentCall_t_305506559_0;
// System.String
struct String_t;
// System.Object
struct Object_t;
// System.Type
struct Type_t;
// UnityEngine.Events.BaseInvokableCall
struct BaseInvokableCall_t_1020700888_0;
// System.Object[]
struct ObjectU5BU5D_t1774424924_0;
// System.Type[]
struct TypeU5BU5D_t_722972841_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Events_PersistentListenerMod_2457062.h"

// System.Void UnityEngine.Events.UnityEventBase::.ctor()
extern "C"  void UnityEventBase__ctor_m199506446_0 (UnityEventBase_t2037213698_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Events.UnityEventBase::UnityEngine.ISerializationCallbackReceiver.OnBeforeSerialize()
extern "C"  void UnityEventBase_UnityEngine_ISerializationCallbackReceiver_OnBeforeSerialize_m1699382396_0 (UnityEventBase_t2037213698_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Events.UnityEventBase::UnityEngine.ISerializationCallbackReceiver.OnAfterDeserialize()
extern "C"  void UnityEventBase_UnityEngine_ISerializationCallbackReceiver_OnAfterDeserialize_m1605173738_0 (UnityEventBase_t2037213698_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodInfo UnityEngine.Events.UnityEventBase::FindMethod(UnityEngine.Events.PersistentCall)
extern "C"  MethodInfo_t * UnityEventBase_FindMethod_m1166071979_0 (UnityEventBase_t2037213698_0 * __this, PersistentCall_t_305506559_0 * ___call, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodInfo UnityEngine.Events.UnityEventBase::FindMethod(System.String,System.Object,UnityEngine.Events.PersistentListenerMode,System.Type)
extern "C"  MethodInfo_t * UnityEventBase_FindMethod_m113598831_0 (UnityEventBase_t2037213698_0 * __this, String_t* ___name, Object_t * ___listener, int32_t ___mode, Type_t * ___argumentType, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Events.UnityEventBase::DirtyPersistentCalls()
extern "C"  void UnityEventBase_DirtyPersistentCalls_m1636785090_0 (UnityEventBase_t2037213698_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Events.UnityEventBase::RebuildPersistentCallsIfNeeded()
extern "C"  void UnityEventBase_RebuildPersistentCallsIfNeeded_m_147765205_0 (UnityEventBase_t2037213698_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Events.UnityEventBase::AddCall(UnityEngine.Events.BaseInvokableCall)
extern "C"  void UnityEventBase_AddCall_m1246572149_0 (UnityEventBase_t2037213698_0 * __this, BaseInvokableCall_t_1020700888_0 * ___call, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Events.UnityEventBase::RemoveListener(System.Object,System.Reflection.MethodInfo)
extern "C"  void UnityEventBase_RemoveListener_m276725997_0 (UnityEventBase_t2037213698_0 * __this, Object_t * ___targetObj, MethodInfo_t * ___method, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Events.UnityEventBase::Invoke(System.Object[])
extern "C"  void UnityEventBase_Invoke_m_613889212_0 (UnityEventBase_t2037213698_0 * __this, ObjectU5BU5D_t1774424924_0* ___parameters, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.Events.UnityEventBase::ToString()
extern "C"  String_t* UnityEventBase_ToString_m249191135_0 (UnityEventBase_t2037213698_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodInfo UnityEngine.Events.UnityEventBase::GetValidMethodInfo(System.Object,System.String,System.Type[])
extern "C"  MethodInfo_t * UnityEventBase_GetValidMethodInfo_m_1969666094_0 (Object_t * __this /* static, unused */, Object_t * ___obj, String_t* ___functionName, TypeU5BU5D_t_722972841_0* ___argumentTypes, const MethodInfo* method) IL2CPP_METHOD_ATTR;
