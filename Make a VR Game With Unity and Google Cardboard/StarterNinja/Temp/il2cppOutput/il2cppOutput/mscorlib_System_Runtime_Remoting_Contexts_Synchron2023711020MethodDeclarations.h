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

// System.Runtime.Remoting.Contexts.SynchronizationAttribute
struct SynchronizationAttribute_t2023711020_0;
// System.Runtime.Remoting.Activation.IConstructionCallMessage
struct IConstructionCallMessage_t_1303764243_0;
// System.Runtime.Remoting.Messaging.IMessageSink
struct IMessageSink_t1677259445_0;
// System.Runtime.Remoting.Contexts.Context
struct Context_t_1732618593_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Runtime.Remoting.Contexts.SynchronizationAttribute::.ctor()
extern "C"  void SynchronizationAttribute__ctor_m_2118078428_0 (SynchronizationAttribute_t2023711020_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Contexts.SynchronizationAttribute::.ctor(System.Int32,System.Boolean)
extern "C"  void SynchronizationAttribute__ctor_m_489714840_0 (SynchronizationAttribute_t2023711020_0 * __this, int32_t ___flag, bool ___reEntrant, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Contexts.SynchronizationAttribute::set_Locked(System.Boolean)
extern "C"  void SynchronizationAttribute_set_Locked_m233834078_0 (SynchronizationAttribute_t2023711020_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Contexts.SynchronizationAttribute::ReleaseLock()
extern "C"  void SynchronizationAttribute_ReleaseLock_m_687408684_0 (SynchronizationAttribute_t2023711020_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Contexts.SynchronizationAttribute::GetPropertiesForNewContext(System.Runtime.Remoting.Activation.IConstructionCallMessage)
extern "C"  void SynchronizationAttribute_GetPropertiesForNewContext_m275738322_0 (SynchronizationAttribute_t2023711020_0 * __this, Object_t * ___ctorMsg, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Messaging.IMessageSink System.Runtime.Remoting.Contexts.SynchronizationAttribute::GetClientContextSink(System.Runtime.Remoting.Messaging.IMessageSink)
extern "C"  Object_t * SynchronizationAttribute_GetClientContextSink_m197546806_0 (SynchronizationAttribute_t2023711020_0 * __this, Object_t * ___nextSink, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Messaging.IMessageSink System.Runtime.Remoting.Contexts.SynchronizationAttribute::GetServerContextSink(System.Runtime.Remoting.Messaging.IMessageSink)
extern "C"  Object_t * SynchronizationAttribute_GetServerContextSink_m1092455614_0 (SynchronizationAttribute_t2023711020_0 * __this, Object_t * ___nextSink, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Remoting.Contexts.SynchronizationAttribute::IsContextOK(System.Runtime.Remoting.Contexts.Context,System.Runtime.Remoting.Activation.IConstructionCallMessage)
extern "C"  bool SynchronizationAttribute_IsContextOK_m_142200027_0 (SynchronizationAttribute_t2023711020_0 * __this, Context_t_1732618593_0 * ___ctx, Object_t * ___msg, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Contexts.SynchronizationAttribute::ExitContext()
extern "C"  void SynchronizationAttribute_ExitContext_m_25465101_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Contexts.SynchronizationAttribute::EnterContext()
extern "C"  void SynchronizationAttribute_EnterContext_m_1143723113_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
