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

// System.Runtime.Remoting.Contexts.Context
struct Context_t_1732618593_0;
// System.Runtime.Remoting.Contexts.IContextProperty[]
struct IContextPropertyU5BU5D_t_421743955_0;
// System.Runtime.Remoting.Contexts.IDynamicProperty
struct IDynamicProperty_t1753651355_0;
// System.ContextBoundObject
struct ContextBoundObject_t_453301271_0;
// System.String
struct String_t;
// System.Runtime.Remoting.Contexts.DynamicPropertyCollection
struct DynamicPropertyCollection_t_668741150_0;
// System.Runtime.Remoting.Messaging.IMessage
struct IMessage_t840298754_0;
// System.Runtime.Remoting.Contexts.IContextProperty
struct IContextProperty_t1340341771_0;
// System.Runtime.Remoting.Messaging.IMessageSink
struct IMessageSink_t1677259445_0;
// System.MarshalByRefObject
struct MarshalByRefObject_t1484498776_0;
// System.Runtime.Remoting.Activation.IConstructionCallMessage
struct IConstructionCallMessage_t_1303764243_0;
// System.Runtime.Remoting.Contexts.CrossContextDelegate
struct CrossContextDelegate_t2085016836_0;
// System.LocalDataStoreSlot
struct LocalDataStoreSlot_t_1838694651_0;
// System.Object
struct Object_t;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Runtime.Remoting.Contexts.Context::.ctor()
extern "C"  void Context__ctor_m_437705257_0 (Context_t_1732618593_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Contexts.Context::.cctor()
extern "C"  void Context__cctor_m_1166057290_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Contexts.Context::Finalize()
extern "C"  void Context_Finalize_m_54094037_0 (Context_t_1732618593_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Contexts.Context System.Runtime.Remoting.Contexts.Context::get_DefaultContext()
extern "C"  Context_t_1732618593_0 * Context_get_DefaultContext_m1729123572_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Runtime.Remoting.Contexts.Context::get_ContextID()
extern "C"  int32_t Context_get_ContextID_m632177530_0 (Context_t_1732618593_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Contexts.IContextProperty[] System.Runtime.Remoting.Contexts.Context::get_ContextProperties()
extern "C"  IContextPropertyU5BU5D_t_421743955_0* Context_get_ContextProperties_m407806956_0 (Context_t_1732618593_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Remoting.Contexts.Context::get_IsDefaultContext()
extern "C"  bool Context_get_IsDefaultContext_m1317738768_0 (Context_t_1732618593_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Remoting.Contexts.Context::get_NeedsContextSink()
extern "C"  bool Context_get_NeedsContextSink_m1407125469_0 (Context_t_1732618593_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Remoting.Contexts.Context::RegisterDynamicProperty(System.Runtime.Remoting.Contexts.IDynamicProperty,System.ContextBoundObject,System.Runtime.Remoting.Contexts.Context)
extern "C"  bool Context_RegisterDynamicProperty_m1382511581_0 (Object_t * __this /* static, unused */, Object_t * ___prop, ContextBoundObject_t_453301271_0 * ___obj, Context_t_1732618593_0 * ___ctx, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Remoting.Contexts.Context::UnregisterDynamicProperty(System.String,System.ContextBoundObject,System.Runtime.Remoting.Contexts.Context)
extern "C"  bool Context_UnregisterDynamicProperty_m_1581902187_0 (Object_t * __this /* static, unused */, String_t* ___name, ContextBoundObject_t_453301271_0 * ___obj, Context_t_1732618593_0 * ___ctx, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Contexts.DynamicPropertyCollection System.Runtime.Remoting.Contexts.Context::GetDynamicPropertyCollection(System.ContextBoundObject,System.Runtime.Remoting.Contexts.Context)
extern "C"  DynamicPropertyCollection_t_668741150_0 * Context_GetDynamicPropertyCollection_m762082460_0 (Object_t * __this /* static, unused */, ContextBoundObject_t_453301271_0 * ___obj, Context_t_1732618593_0 * ___ctx, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Contexts.Context::NotifyGlobalDynamicSinks(System.Boolean,System.Runtime.Remoting.Messaging.IMessage,System.Boolean,System.Boolean)
extern "C"  void Context_NotifyGlobalDynamicSinks_m_46237577_0 (Object_t * __this /* static, unused */, bool ___start, Object_t * ___req_msg, bool ___client_site, bool ___async, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Remoting.Contexts.Context::get_HasGlobalDynamicSinks()
extern "C"  bool Context_get_HasGlobalDynamicSinks_m_569966456_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Contexts.Context::NotifyDynamicSinks(System.Boolean,System.Runtime.Remoting.Messaging.IMessage,System.Boolean,System.Boolean)
extern "C"  void Context_NotifyDynamicSinks_m1548895898_0 (Context_t_1732618593_0 * __this, bool ___start, Object_t * ___req_msg, bool ___client_site, bool ___async, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Remoting.Contexts.Context::get_HasDynamicSinks()
extern "C"  bool Context_get_HasDynamicSinks_m1961314373_0 (Context_t_1732618593_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Remoting.Contexts.Context::get_HasExitSinks()
extern "C"  bool Context_get_HasExitSinks_m1034415328_0 (Context_t_1732618593_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Contexts.IContextProperty System.Runtime.Remoting.Contexts.Context::GetProperty(System.String)
extern "C"  Object_t * Context_GetProperty_m_947206778_0 (Context_t_1732618593_0 * __this, String_t* ___name, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Contexts.Context::SetProperty(System.Runtime.Remoting.Contexts.IContextProperty)
extern "C"  void Context_SetProperty_m_771565417_0 (Context_t_1732618593_0 * __this, Object_t * ___prop, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Contexts.Context::Freeze()
extern "C"  void Context_Freeze_m_1816908188_0 (Context_t_1732618593_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Runtime.Remoting.Contexts.Context::ToString()
extern "C"  String_t* Context_ToString_m185373276_0 (Context_t_1732618593_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Messaging.IMessageSink System.Runtime.Remoting.Contexts.Context::GetServerContextSinkChain()
extern "C"  Object_t * Context_GetServerContextSinkChain_m_1566019341_0 (Context_t_1732618593_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Messaging.IMessageSink System.Runtime.Remoting.Contexts.Context::GetClientContextSinkChain()
extern "C"  Object_t * Context_GetClientContextSinkChain_m420750203_0 (Context_t_1732618593_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Messaging.IMessageSink System.Runtime.Remoting.Contexts.Context::CreateServerObjectSinkChain(System.MarshalByRefObject,System.Boolean)
extern "C"  Object_t * Context_CreateServerObjectSinkChain_m_1642991630_0 (Context_t_1732618593_0 * __this, MarshalByRefObject_t1484498776_0 * ___obj, bool ___forceInternalExecute, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Messaging.IMessageSink System.Runtime.Remoting.Contexts.Context::CreateEnvoySink(System.MarshalByRefObject)
extern "C"  Object_t * Context_CreateEnvoySink_m_2070539443_0 (Context_t_1732618593_0 * __this, MarshalByRefObject_t1484498776_0 * ___serverObject, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Contexts.Context System.Runtime.Remoting.Contexts.Context::SwitchToContext(System.Runtime.Remoting.Contexts.Context)
extern "C"  Context_t_1732618593_0 * Context_SwitchToContext_m_1758435446_0 (Object_t * __this /* static, unused */, Context_t_1732618593_0 * ___newContext, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Contexts.Context System.Runtime.Remoting.Contexts.Context::CreateNewContext(System.Runtime.Remoting.Activation.IConstructionCallMessage)
extern "C"  Context_t_1732618593_0 * Context_CreateNewContext_m_560215815_0 (Object_t * __this /* static, unused */, Object_t * ___msg, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Contexts.Context::DoCallBack(System.Runtime.Remoting.Contexts.CrossContextDelegate)
extern "C"  void Context_DoCallBack_m1407016397_0 (Context_t_1732618593_0 * __this, CrossContextDelegate_t2085016836_0 * ___deleg, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.LocalDataStoreSlot System.Runtime.Remoting.Contexts.Context::AllocateDataSlot()
extern "C"  LocalDataStoreSlot_t_1838694651_0 * Context_AllocateDataSlot_m_1950765892_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.LocalDataStoreSlot System.Runtime.Remoting.Contexts.Context::AllocateNamedDataSlot(System.String)
extern "C"  LocalDataStoreSlot_t_1838694651_0 * Context_AllocateNamedDataSlot_m_1564312429_0 (Object_t * __this /* static, unused */, String_t* ___name, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Contexts.Context::FreeNamedDataSlot(System.String)
extern "C"  void Context_FreeNamedDataSlot_m_1427486856_0 (Object_t * __this /* static, unused */, String_t* ___name, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Runtime.Remoting.Contexts.Context::GetData(System.LocalDataStoreSlot)
extern "C"  Object_t * Context_GetData_m_1686612631_0 (Object_t * __this /* static, unused */, LocalDataStoreSlot_t_1838694651_0 * ___slot, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.LocalDataStoreSlot System.Runtime.Remoting.Contexts.Context::GetNamedDataSlot(System.String)
extern "C"  LocalDataStoreSlot_t_1838694651_0 * Context_GetNamedDataSlot_m1654679232_0 (Object_t * __this /* static, unused */, String_t* ___name, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Contexts.Context::SetData(System.LocalDataStoreSlot,System.Object)
extern "C"  void Context_SetData_m750447798_0 (Object_t * __this /* static, unused */, LocalDataStoreSlot_t_1838694651_0 * ___slot, Object_t * ___data, const MethodInfo* method) IL2CPP_METHOD_ATTR;
