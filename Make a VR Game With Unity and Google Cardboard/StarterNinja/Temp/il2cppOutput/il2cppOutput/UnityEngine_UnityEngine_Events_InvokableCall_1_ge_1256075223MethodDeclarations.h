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

// UnityEngine.Events.InvokableCall`1<System.Single>
struct InvokableCall_1_t_1256075223_0;
// System.Object
struct Object_t;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// UnityEngine.Events.UnityAction`1<System.Single>
struct UnityAction_1_t_1952876745_0;
// System.Object[]
struct ObjectU5BU5D_t1774424924_0;

#include "codegen/il2cpp-codegen.h"

// System.Void UnityEngine.Events.InvokableCall`1<System.Single>::.ctor(System.Object,System.Reflection.MethodInfo)
extern "C"  void InvokableCall_1__ctor_m119008486_0_gshared (InvokableCall_1_t_1256075223_0 * __this, Object_t * ___target, MethodInfo_t * ___theFunction, const MethodInfo* method);
#define InvokableCall_1__ctor_m119008486_0(__this, ___target, ___theFunction, method) ((  void (*) (InvokableCall_1_t_1256075223_0 *, Object_t *, MethodInfo_t *, const MethodInfo*))InvokableCall_1__ctor_m119008486_0_gshared)(__this, ___target, ___theFunction, method)
// System.Void UnityEngine.Events.InvokableCall`1<System.Single>::.ctor(UnityEngine.Events.UnityAction`1<T1>)
extern "C"  void InvokableCall_1__ctor_m593494980_0_gshared (InvokableCall_1_t_1256075223_0 * __this, UnityAction_1_t_1952876745_0 * ___action, const MethodInfo* method);
#define InvokableCall_1__ctor_m593494980_0(__this, ___action, method) ((  void (*) (InvokableCall_1_t_1256075223_0 *, UnityAction_1_t_1952876745_0 *, const MethodInfo*))InvokableCall_1__ctor_m593494980_0_gshared)(__this, ___action, method)
// System.Void UnityEngine.Events.InvokableCall`1<System.Single>::Invoke(System.Object[])
extern "C"  void InvokableCall_1_Invoke_m1294505213_0_gshared (InvokableCall_1_t_1256075223_0 * __this, ObjectU5BU5D_t1774424924_0* ___args, const MethodInfo* method);
#define InvokableCall_1_Invoke_m1294505213_0(__this, ___args, method) ((  void (*) (InvokableCall_1_t_1256075223_0 *, ObjectU5BU5D_t1774424924_0*, const MethodInfo*))InvokableCall_1_Invoke_m1294505213_0_gshared)(__this, ___args, method)
// System.Boolean UnityEngine.Events.InvokableCall`1<System.Single>::Find(System.Object,System.Reflection.MethodInfo)
extern "C"  bool InvokableCall_1_Find_m270750159_0_gshared (InvokableCall_1_t_1256075223_0 * __this, Object_t * ___targetObj, MethodInfo_t * ___method, const MethodInfo* method);
#define InvokableCall_1_Find_m270750159_0(__this, ___targetObj, ___method, method) ((  bool (*) (InvokableCall_1_t_1256075223_0 *, Object_t *, MethodInfo_t *, const MethodInfo*))InvokableCall_1_Find_m270750159_0_gshared)(__this, ___targetObj, ___method, method)
