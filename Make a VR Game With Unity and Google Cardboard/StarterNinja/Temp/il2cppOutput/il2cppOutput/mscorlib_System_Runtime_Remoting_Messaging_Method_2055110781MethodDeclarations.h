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

// System.Runtime.Remoting.Messaging.MethodCall
struct MethodCall_t_2055110781_0;
// System.Runtime.Remoting.Messaging.Header[]
struct HeaderU5BU5D_t_1206030253_0;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;
// System.String
struct String_t;
// System.Object
struct Object_t;
// System.Object[]
struct ObjectU5BU5D_t1774424924_0;
// System.Runtime.Remoting.Messaging.LogicalCallContext
struct LogicalCallContext_t_459661748_0;
// System.Reflection.MethodBase
struct MethodBase_t553742458_0;
// System.Collections.IDictionary
struct IDictionary_t_1514320629_0;
// System.Type
struct Type_t;
// System.Type[]
struct TypeU5BU5D_t_722972841_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"

// System.Void System.Runtime.Remoting.Messaging.MethodCall::.ctor(System.Runtime.Remoting.Messaging.Header[])
extern "C"  void MethodCall__ctor_m_2014419996_0 (MethodCall_t_2055110781_0 * __this, HeaderU5BU5D_t_1206030253_0* ___h1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.MethodCall::.ctor(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void MethodCall__ctor_m_1062925644_0 (MethodCall_t_2055110781_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.MethodCall::.ctor()
extern "C"  void MethodCall__ctor_m_62718989_0 (MethodCall_t_2055110781_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.MethodCall::System.Runtime.Remoting.Messaging.IInternalMessage.set_Uri(System.String)
extern "C"  void MethodCall_System_Runtime_Remoting_Messaging_IInternalMessage_set_Uri_m75118319_0 (MethodCall_t_2055110781_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.MethodCall::InitMethodProperty(System.String,System.Object)
extern "C"  void MethodCall_InitMethodProperty_m_1915937927_0 (MethodCall_t_2055110781_0 * __this, String_t* ___key, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.MethodCall::GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void MethodCall_GetObjectData_m_1202037231_0 (MethodCall_t_2055110781_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.Runtime.Remoting.Messaging.MethodCall::get_Args()
extern "C"  ObjectU5BU5D_t1774424924_0* MethodCall_get_Args_m_1517617558_0 (MethodCall_t_2055110781_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Messaging.LogicalCallContext System.Runtime.Remoting.Messaging.MethodCall::get_LogicalCallContext()
extern "C"  LogicalCallContext_t_459661748_0 * MethodCall_get_LogicalCallContext_m_536264059_0 (MethodCall_t_2055110781_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodBase System.Runtime.Remoting.Messaging.MethodCall::get_MethodBase()
extern "C"  MethodBase_t553742458_0 * MethodCall_get_MethodBase_m1563575745_0 (MethodCall_t_2055110781_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Runtime.Remoting.Messaging.MethodCall::get_MethodName()
extern "C"  String_t* MethodCall_get_MethodName_m703141353_0 (MethodCall_t_2055110781_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Runtime.Remoting.Messaging.MethodCall::get_MethodSignature()
extern "C"  Object_t * MethodCall_get_MethodSignature_m_789677846_0 (MethodCall_t_2055110781_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IDictionary System.Runtime.Remoting.Messaging.MethodCall::get_Properties()
extern "C"  Object_t * MethodCall_get_Properties_m_800276303_0 (MethodCall_t_2055110781_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.MethodCall::InitDictionary()
extern "C"  void MethodCall_InitDictionary_m1823571767_0 (MethodCall_t_2055110781_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Runtime.Remoting.Messaging.MethodCall::get_TypeName()
extern "C"  String_t* MethodCall_get_TypeName_m_1476430718_0 (MethodCall_t_2055110781_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Runtime.Remoting.Messaging.MethodCall::get_Uri()
extern "C"  String_t* MethodCall_get_Uri_m110584337_0 (MethodCall_t_2055110781_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.MethodCall::set_Uri(System.String)
extern "C"  void MethodCall_set_Uri_m_665918046_0 (MethodCall_t_2055110781_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.MethodCall::Init()
extern "C"  void MethodCall_Init_m1334986753_0 (MethodCall_t_2055110781_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.MethodCall::ResolveMethod()
extern "C"  void MethodCall_ResolveMethod_m_2103531586_0 (MethodCall_t_2055110781_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Runtime.Remoting.Messaging.MethodCall::CastTo(System.String,System.Type)
extern "C"  Type_t * MethodCall_CastTo_m2140135600_0 (MethodCall_t_2055110781_0 * __this, String_t* ___clientType, Type_t * ___serverType, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Runtime.Remoting.Messaging.MethodCall::GetTypeNameFromAssemblyQualifiedName(System.String)
extern "C"  String_t* MethodCall_GetTypeNameFromAssemblyQualifiedName_m148372306_0 (Object_t * __this /* static, unused */, String_t* ___aqname, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type[] System.Runtime.Remoting.Messaging.MethodCall::get_GenericArguments()
extern "C"  TypeU5BU5D_t_722972841_0* MethodCall_get_GenericArguments_m_1201414863_0 (MethodCall_t_2055110781_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
