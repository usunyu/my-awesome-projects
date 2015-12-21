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

// System.Runtime.Remoting.Messaging.ConstructionCall
struct ConstructionCall_t521026675_0;
// System.Type
struct Type_t;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;
// System.String
struct String_t;
// System.Runtime.Remoting.Activation.IActivator
struct IActivator_t_815190902_0;
// System.Object[]
struct ObjectU5BU5D_t1774424924_0;
// System.Collections.IList
struct IList_t_1078834989_0;
// System.Object
struct Object_t;
// System.Collections.IDictionary
struct IDictionary_t_1514320629_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"

// System.Void System.Runtime.Remoting.Messaging.ConstructionCall::.ctor(System.Type)
extern "C"  void ConstructionCall__ctor_m1901864150_0 (ConstructionCall_t521026675_0 * __this, Type_t * ___type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.ConstructionCall::.ctor(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void ConstructionCall__ctor_m_1962358396_0 (ConstructionCall_t521026675_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.ConstructionCall::InitDictionary()
extern "C"  void ConstructionCall_InitDictionary_m600871527_0 (ConstructionCall_t521026675_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.ConstructionCall::set_IsContextOk(System.Boolean)
extern "C"  void ConstructionCall_set_IsContextOk_m1331988764_0 (ConstructionCall_t521026675_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Runtime.Remoting.Messaging.ConstructionCall::get_ActivationType()
extern "C"  Type_t * ConstructionCall_get_ActivationType_m242799220_0 (ConstructionCall_t521026675_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Runtime.Remoting.Messaging.ConstructionCall::get_ActivationTypeName()
extern "C"  String_t* ConstructionCall_get_ActivationTypeName_m_2034587608_0 (ConstructionCall_t521026675_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Activation.IActivator System.Runtime.Remoting.Messaging.ConstructionCall::get_Activator()
extern "C"  Object_t * ConstructionCall_get_Activator_m521493960_0 (ConstructionCall_t521026675_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.ConstructionCall::set_Activator(System.Runtime.Remoting.Activation.IActivator)
extern "C"  void ConstructionCall_set_Activator_m1743955147_0 (ConstructionCall_t521026675_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.Runtime.Remoting.Messaging.ConstructionCall::get_CallSiteActivationAttributes()
extern "C"  ObjectU5BU5D_t1774424924_0* ConstructionCall_get_CallSiteActivationAttributes_m_1515673937_0 (ConstructionCall_t521026675_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.ConstructionCall::SetActivationAttributes(System.Object[])
extern "C"  void ConstructionCall_SetActivationAttributes_m_744843518_0 (ConstructionCall_t521026675_0 * __this, ObjectU5BU5D_t1774424924_0* ___attributes, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IList System.Runtime.Remoting.Messaging.ConstructionCall::get_ContextProperties()
extern "C"  Object_t * ConstructionCall_get_ContextProperties_m_112416642_0 (ConstructionCall_t521026675_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.ConstructionCall::InitMethodProperty(System.String,System.Object)
extern "C"  void ConstructionCall_InitMethodProperty_m_795368887_0 (ConstructionCall_t521026675_0 * __this, String_t* ___key, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.ConstructionCall::GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void ConstructionCall_GetObjectData_m_1313190687_0 (ConstructionCall_t521026675_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IDictionary System.Runtime.Remoting.Messaging.ConstructionCall::get_Properties()
extern "C"  Object_t * ConstructionCall_get_Properties_m690127073_0 (ConstructionCall_t521026675_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
