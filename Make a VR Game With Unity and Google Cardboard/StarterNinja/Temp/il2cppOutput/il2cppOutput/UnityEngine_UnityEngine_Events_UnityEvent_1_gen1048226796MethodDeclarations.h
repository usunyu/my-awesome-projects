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

// UnityEngine.Events.UnityEvent`1<UnityEngine.Vector2>
struct UnityEvent_1_t1048226796_0;
// UnityEngine.Events.UnityAction`1<UnityEngine.Vector2>
struct UnityAction_1_t1710169362_0;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// System.String
struct String_t;
// System.Object
struct Object_t;
// UnityEngine.Events.BaseInvokableCall
struct BaseInvokableCall_t_1020700888_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"

// System.Void UnityEngine.Events.UnityEvent`1<UnityEngine.Vector2>::.ctor()
extern "C"  void UnityEvent_1__ctor_m99457450_0_gshared (UnityEvent_1_t1048226796_0 * __this, const MethodInfo* method);
#define UnityEvent_1__ctor_m99457450_0(__this, method) ((  void (*) (UnityEvent_1_t1048226796_0 *, const MethodInfo*))UnityEvent_1__ctor_m99457450_0_gshared)(__this, method)
// System.Void UnityEngine.Events.UnityEvent`1<UnityEngine.Vector2>::AddListener(UnityEngine.Events.UnityAction`1<T0>)
extern "C"  void UnityEvent_1_AddListener_m274807813_0_gshared (UnityEvent_1_t1048226796_0 * __this, UnityAction_1_t1710169362_0 * ___call, const MethodInfo* method);
#define UnityEvent_1_AddListener_m274807813_0(__this, ___call, method) ((  void (*) (UnityEvent_1_t1048226796_0 *, UnityAction_1_t1710169362_0 *, const MethodInfo*))UnityEvent_1_AddListener_m274807813_0_gshared)(__this, ___call, method)
// System.Void UnityEngine.Events.UnityEvent`1<UnityEngine.Vector2>::RemoveListener(UnityEngine.Events.UnityAction`1<T0>)
extern "C"  void UnityEvent_1_RemoveListener_m_1568962654_0_gshared (UnityEvent_1_t1048226796_0 * __this, UnityAction_1_t1710169362_0 * ___call, const MethodInfo* method);
#define UnityEvent_1_RemoveListener_m_1568962654_0(__this, ___call, method) ((  void (*) (UnityEvent_1_t1048226796_0 *, UnityAction_1_t1710169362_0 *, const MethodInfo*))UnityEvent_1_RemoveListener_m_1568962654_0_gshared)(__this, ___call, method)
// System.Reflection.MethodInfo UnityEngine.Events.UnityEvent`1<UnityEngine.Vector2>::FindMethod_Impl(System.String,System.Object)
extern "C"  MethodInfo_t * UnityEvent_1_FindMethod_Impl_m_363306477_0_gshared (UnityEvent_1_t1048226796_0 * __this, String_t* ___name, Object_t * ___targetObj, const MethodInfo* method);
#define UnityEvent_1_FindMethod_Impl_m_363306477_0(__this, ___name, ___targetObj, method) ((  MethodInfo_t * (*) (UnityEvent_1_t1048226796_0 *, String_t*, Object_t *, const MethodInfo*))UnityEvent_1_FindMethod_Impl_m_363306477_0_gshared)(__this, ___name, ___targetObj, method)
// UnityEngine.Events.BaseInvokableCall UnityEngine.Events.UnityEvent`1<UnityEngine.Vector2>::GetDelegate(System.Object,System.Reflection.MethodInfo)
extern "C"  BaseInvokableCall_t_1020700888_0 * UnityEvent_1_GetDelegate_m1046909621_0_gshared (UnityEvent_1_t1048226796_0 * __this, Object_t * ___target, MethodInfo_t * ___theFunction, const MethodInfo* method);
#define UnityEvent_1_GetDelegate_m1046909621_0(__this, ___target, ___theFunction, method) ((  BaseInvokableCall_t_1020700888_0 * (*) (UnityEvent_1_t1048226796_0 *, Object_t *, MethodInfo_t *, const MethodInfo*))UnityEvent_1_GetDelegate_m1046909621_0_gshared)(__this, ___target, ___theFunction, method)
// UnityEngine.Events.BaseInvokableCall UnityEngine.Events.UnityEvent`1<UnityEngine.Vector2>::GetDelegate(UnityEngine.Events.UnityAction`1<T0>)
extern "C"  BaseInvokableCall_t_1020700888_0 * UnityEvent_1_GetDelegate_m_1932071662_0_gshared (Object_t * __this /* static, unused */, UnityAction_1_t1710169362_0 * ___action, const MethodInfo* method);
#define UnityEvent_1_GetDelegate_m_1932071662_0(__this /* static, unused */, ___action, method) ((  BaseInvokableCall_t_1020700888_0 * (*) (Object_t * /* static, unused */, UnityAction_1_t1710169362_0 *, const MethodInfo*))UnityEvent_1_GetDelegate_m_1932071662_0_gshared)(__this /* static, unused */, ___action, method)
// System.Void UnityEngine.Events.UnityEvent`1<UnityEngine.Vector2>::Invoke(T0)
extern "C"  void UnityEvent_1_Invoke_m_962013693_0_gshared (UnityEvent_1_t1048226796_0 * __this, Vector2_t_725341338_0  ___arg0, const MethodInfo* method);
#define UnityEvent_1_Invoke_m_962013693_0(__this, ___arg0, method) ((  void (*) (UnityEvent_1_t1048226796_0 *, Vector2_t_725341338_0 , const MethodInfo*))UnityEvent_1_Invoke_m_962013693_0_gshared)(__this, ___arg0, method)
