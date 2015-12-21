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

// System.Runtime.Remoting.Proxies.RealProxy
struct RealProxy_t_1812550060_0;
// System.Type
struct Type_t;
// System.Runtime.Remoting.ClientIdentity
struct ClientIdentity_t_958138237_0;
// System.Object
struct Object_t;
// System.Runtime.Remoting.Identity
struct Identity_t_1227012328_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"

// System.Void System.Runtime.Remoting.Proxies.RealProxy::.ctor(System.Type)
extern "C"  void RealProxy__ctor_m1052917757_0 (RealProxy_t_1812550060_0 * __this, Type_t * ___classToProxy, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Proxies.RealProxy::.ctor(System.Type,System.Runtime.Remoting.ClientIdentity)
extern "C"  void RealProxy__ctor_m353424490_0 (RealProxy_t_1812550060_0 * __this, Type_t * ___classToProxy, ClientIdentity_t_958138237_0 * ___identity, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Proxies.RealProxy::.ctor(System.Type,System.IntPtr,System.Object)
extern "C"  void RealProxy__ctor_m_1241925031_0 (RealProxy_t_1812550060_0 * __this, Type_t * ___classToProxy, IntPtr_t ___stub, Object_t * ___stubData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Runtime.Remoting.Proxies.RealProxy::InternalGetProxyType(System.Object)
extern "C"  Type_t * RealProxy_InternalGetProxyType_m1321633559_0 (Object_t * __this /* static, unused */, Object_t * ___transparentProxy, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Runtime.Remoting.Proxies.RealProxy::GetProxiedType()
extern "C"  Type_t * RealProxy_GetProxiedType_m_508785009_0 (RealProxy_t_1812550060_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Identity System.Runtime.Remoting.Proxies.RealProxy::get_ObjectIdentity()
extern "C"  Identity_t_1227012328_0 * RealProxy_get_ObjectIdentity_m347429559_0 (RealProxy_t_1812550060_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Runtime.Remoting.Proxies.RealProxy::InternalGetTransparentProxy(System.String)
extern "C"  Object_t * RealProxy_InternalGetTransparentProxy_m1628758334_0 (RealProxy_t_1812550060_0 * __this, String_t* ___className, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Runtime.Remoting.Proxies.RealProxy::GetTransparentProxy()
extern "C"  Object_t * RealProxy_GetTransparentProxy_m1295804673_0 (RealProxy_t_1812550060_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Proxies.RealProxy::SetTargetDomain(System.Int32)
extern "C"  void RealProxy_SetTargetDomain_m1954293026_0 (RealProxy_t_1812550060_0 * __this, int32_t ___domainId, const MethodInfo* method) IL2CPP_METHOD_ATTR;
