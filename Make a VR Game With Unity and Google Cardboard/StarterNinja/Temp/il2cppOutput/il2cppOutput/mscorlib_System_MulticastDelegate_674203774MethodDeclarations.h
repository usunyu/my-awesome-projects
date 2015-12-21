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

// System.MulticastDelegate
struct MulticastDelegate_t_674203774_0;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;
// System.Object
struct Object_t;
// System.Delegate[]
struct DelegateU5BU5D_t442966370_0;
// System.Delegate
struct Delegate_t_1791715840_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"

// System.Void System.MulticastDelegate::GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void MulticastDelegate_GetObjectData_m_1335830542_0 (MulticastDelegate_t_674203774_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.MulticastDelegate::Equals(System.Object)
extern "C"  bool MulticastDelegate_Equals_m1775662595_0 (MulticastDelegate_t_674203774_0 * __this, Object_t * ___obj, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.MulticastDelegate::GetHashCode()
extern "C"  int32_t MulticastDelegate_GetHashCode_m932113511_0 (MulticastDelegate_t_674203774_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Delegate[] System.MulticastDelegate::GetInvocationList()
extern "C"  DelegateU5BU5D_t442966370_0* MulticastDelegate_GetInvocationList_m_2066044983_0 (MulticastDelegate_t_674203774_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Delegate System.MulticastDelegate::CombineImpl(System.Delegate)
extern "C"  Delegate_t_1791715840_0 * MulticastDelegate_CombineImpl_m_1061378836_0 (MulticastDelegate_t_674203774_0 * __this, Delegate_t_1791715840_0 * ___follow, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.MulticastDelegate::BaseEquals(System.MulticastDelegate)
extern "C"  bool MulticastDelegate_BaseEquals_m_659036732_0 (MulticastDelegate_t_674203774_0 * __this, MulticastDelegate_t_674203774_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.MulticastDelegate System.MulticastDelegate::KPM(System.MulticastDelegate,System.MulticastDelegate,System.MulticastDelegate&)
extern "C"  MulticastDelegate_t_674203774_0 * MulticastDelegate_KPM_m466375933_0 (Object_t * __this /* static, unused */, MulticastDelegate_t_674203774_0 * ___needle, MulticastDelegate_t_674203774_0 * ___haystack, MulticastDelegate_t_674203774_0 ** ___tail, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Delegate System.MulticastDelegate::RemoveImpl(System.Delegate)
extern "C"  Delegate_t_1791715840_0 * MulticastDelegate_RemoveImpl_m112886219_0 (MulticastDelegate_t_674203774_0 * __this, Delegate_t_1791715840_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
