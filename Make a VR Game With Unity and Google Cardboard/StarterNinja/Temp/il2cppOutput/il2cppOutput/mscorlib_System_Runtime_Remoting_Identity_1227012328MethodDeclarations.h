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

// System.Runtime.Remoting.Identity
struct Identity_t_1227012328_0;
// System.String
struct String_t;
// System.Runtime.Remoting.Messaging.IMessageSink
struct IMessageSink_t1677259445_0;
// System.Runtime.Remoting.Contexts.DynamicPropertyCollection
struct DynamicPropertyCollection_t_668741150_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Runtime.Remoting.Identity::.ctor(System.String)
extern "C"  void Identity__ctor_m_195663036_0 (Identity_t_1227012328_0 * __this, String_t* ___objectUri, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Messaging.IMessageSink System.Runtime.Remoting.Identity::get_ChannelSink()
extern "C"  Object_t * Identity_get_ChannelSink_m1983774607_0 (Identity_t_1227012328_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Identity::set_ChannelSink(System.Runtime.Remoting.Messaging.IMessageSink)
extern "C"  void Identity_set_ChannelSink_m_1164119356_0 (Identity_t_1227012328_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Runtime.Remoting.Identity::get_ObjectUri()
extern "C"  String_t* Identity_get_ObjectUri_m_1851523043_0 (Identity_t_1227012328_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Remoting.Identity::get_Disposed()
extern "C"  bool Identity_get_Disposed_m1911726198_0 (Identity_t_1227012328_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Identity::set_Disposed(System.Boolean)
extern "C"  void Identity_set_Disposed_m1071218783_0 (Identity_t_1227012328_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Contexts.DynamicPropertyCollection System.Runtime.Remoting.Identity::get_ClientDynamicProperties()
extern "C"  DynamicPropertyCollection_t_668741150_0 * Identity_get_ClientDynamicProperties_m_1993318771_0 (Identity_t_1227012328_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Contexts.DynamicPropertyCollection System.Runtime.Remoting.Identity::get_ServerDynamicProperties()
extern "C"  DynamicPropertyCollection_t_668741150_0 * Identity_get_ServerDynamicProperties_m841334805_0 (Identity_t_1227012328_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
