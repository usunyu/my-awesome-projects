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

// System.Runtime.Remoting.Messaging.ReturnMessage
struct ReturnMessage_t754030995_0;
// System.Object
struct Object_t;
// System.Object[]
struct ObjectU5BU5D_t1774424924_0;
// System.Runtime.Remoting.Messaging.LogicalCallContext
struct LogicalCallContext_t_459661748_0;
// System.Runtime.Remoting.Messaging.IMethodCallMessage
struct IMethodCallMessage_t818199395_0;
// System.Exception
struct Exception_t2143823668_0;
// System.String
struct String_t;
// System.Reflection.MethodBase
struct MethodBase_t553742458_0;
// System.Collections.IDictionary
struct IDictionary_t_1514320629_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Runtime.Remoting.Messaging.ReturnMessage::.ctor(System.Object,System.Object[],System.Int32,System.Runtime.Remoting.Messaging.LogicalCallContext,System.Runtime.Remoting.Messaging.IMethodCallMessage)
extern "C"  void ReturnMessage__ctor_m1311493117_0 (ReturnMessage_t754030995_0 * __this, Object_t * ___ret, ObjectU5BU5D_t1774424924_0* ___outArgs, int32_t ___outArgsCount, LogicalCallContext_t_459661748_0 * ___callCtx, Object_t * ___mcm, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.ReturnMessage::.ctor(System.Exception,System.Runtime.Remoting.Messaging.IMethodCallMessage)
extern "C"  void ReturnMessage__ctor_m_535975430_0 (ReturnMessage_t754030995_0 * __this, Exception_t2143823668_0 * ___e, Object_t * ___mcm, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.ReturnMessage::System.Runtime.Remoting.Messaging.IInternalMessage.set_Uri(System.String)
extern "C"  void ReturnMessage_System_Runtime_Remoting_Messaging_IInternalMessage_set_Uri_m1208934489_0 (ReturnMessage_t754030995_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.Runtime.Remoting.Messaging.ReturnMessage::get_Args()
extern "C"  ObjectU5BU5D_t1774424924_0* ReturnMessage_get_Args_m1415412666_0 (ReturnMessage_t754030995_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Messaging.LogicalCallContext System.Runtime.Remoting.Messaging.ReturnMessage::get_LogicalCallContext()
extern "C"  LogicalCallContext_t_459661748_0 * ReturnMessage_get_LogicalCallContext_m_1736143947_0 (ReturnMessage_t754030995_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodBase System.Runtime.Remoting.Messaging.ReturnMessage::get_MethodBase()
extern "C"  MethodBase_t553742458_0 * ReturnMessage_get_MethodBase_m1896590733_0 (ReturnMessage_t754030995_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Runtime.Remoting.Messaging.ReturnMessage::get_MethodName()
extern "C"  String_t* ReturnMessage_get_MethodName_m_1646483175_0 (ReturnMessage_t754030995_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Runtime.Remoting.Messaging.ReturnMessage::get_MethodSignature()
extern "C"  Object_t * ReturnMessage_get_MethodSignature_m_1619151714_0 (ReturnMessage_t754030995_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IDictionary System.Runtime.Remoting.Messaging.ReturnMessage::get_Properties()
extern "C"  Object_t * ReturnMessage_get_Properties_m_924432513_0 (ReturnMessage_t754030995_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Runtime.Remoting.Messaging.ReturnMessage::get_TypeName()
extern "C"  String_t* ReturnMessage_get_TypeName_m_383904846_0 (ReturnMessage_t754030995_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Runtime.Remoting.Messaging.ReturnMessage::get_Uri()
extern "C"  String_t* ReturnMessage_get_Uri_m1363018977_0 (ReturnMessage_t754030995_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Messaging.ReturnMessage::set_Uri(System.String)
extern "C"  void ReturnMessage_set_Uri_m_248772488_0 (ReturnMessage_t754030995_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Exception System.Runtime.Remoting.Messaging.ReturnMessage::get_Exception()
extern "C"  Exception_t2143823668_0 * ReturnMessage_get_Exception_m564038940_0 (ReturnMessage_t754030995_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.Runtime.Remoting.Messaging.ReturnMessage::get_OutArgs()
extern "C"  ObjectU5BU5D_t1774424924_0* ReturnMessage_get_OutArgs_m1555180784_0 (ReturnMessage_t754030995_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Runtime.Remoting.Messaging.ReturnMessage::get_ReturnValue()
extern "C"  Object_t * ReturnMessage_get_ReturnValue_m_242447768_0 (ReturnMessage_t754030995_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
