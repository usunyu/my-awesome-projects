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

// UnityEngine.Events.InvokableCallList
struct InvokableCallList_t1016904887_0;
// UnityEngine.Events.BaseInvokableCall
struct BaseInvokableCall_t_1020700888_0;
// System.Object
struct Object_t;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// System.Object[]
struct ObjectU5BU5D_t1774424924_0;

#include "codegen/il2cpp-codegen.h"

// System.Void UnityEngine.Events.InvokableCallList::.ctor()
extern "C"  void InvokableCallList__ctor_m_1881632449_0 (InvokableCallList_t1016904887_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Events.InvokableCallList::AddPersistentInvokableCall(UnityEngine.Events.BaseInvokableCall)
extern "C"  void InvokableCallList_AddPersistentInvokableCall_m_74341956_0 (InvokableCallList_t1016904887_0 * __this, BaseInvokableCall_t_1020700888_0 * ___call, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Events.InvokableCallList::AddListener(UnityEngine.Events.BaseInvokableCall)
extern "C"  void InvokableCallList_AddListener_m1356872764_0 (InvokableCallList_t1016904887_0 * __this, BaseInvokableCall_t_1020700888_0 * ___call, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Events.InvokableCallList::RemoveListener(System.Object,System.Reflection.MethodInfo)
extern "C"  void InvokableCallList_RemoveListener_m855004700_0 (InvokableCallList_t1016904887_0 * __this, Object_t * ___targetObj, MethodInfo_t * ___method, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Events.InvokableCallList::ClearPersistent()
extern "C"  void InvokableCallList_ClearPersistent_m1690187553_0 (InvokableCallList_t1016904887_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Events.InvokableCallList::Invoke(System.Object[])
extern "C"  void InvokableCallList_Invoke_m575840373_0 (InvokableCallList_t1016904887_0 * __this, ObjectU5BU5D_t1774424924_0* ___parameters, const MethodInfo* method) IL2CPP_METHOD_ATTR;
