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

// System.String
struct String_t;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// Mono.Security.Protocol.Tls.ClientSessionInfo
struct ClientSessionInfo_t1452700657_0;
// Mono.Security.Protocol.Tls.Context
struct Context_t_1281777657_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.Protocol.Tls.ClientSessionCache::.cctor()
extern "C"  void ClientSessionCache__cctor_m_1072767172_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.ClientSessionCache::Add(System.String,System.Byte[])
extern "C"  void ClientSessionCache_Add_m1176188661_0 (Object_t * __this /* static, unused */, String_t* ___host, ByteU5BU5D_t_1238178395_0* ___id, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.ClientSessionCache::FromHost(System.String)
extern "C"  ByteU5BU5D_t_1238178395_0* ClientSessionCache_FromHost_m_795306425_0 (Object_t * __this /* static, unused */, String_t* ___host, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.ClientSessionInfo Mono.Security.Protocol.Tls.ClientSessionCache::FromContext(Mono.Security.Protocol.Tls.Context,System.Boolean)
extern "C"  ClientSessionInfo_t1452700657_0 * ClientSessionCache_FromContext_m1274339950_0 (Object_t * __this /* static, unused */, Context_t_1281777657_0 * ___context, bool ___checkValidity, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.ClientSessionCache::SetContextInCache(Mono.Security.Protocol.Tls.Context)
extern "C"  bool ClientSessionCache_SetContextInCache_m1823103460_0 (Object_t * __this /* static, unused */, Context_t_1281777657_0 * ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.ClientSessionCache::SetContextFromCache(Mono.Security.Protocol.Tls.Context)
extern "C"  bool ClientSessionCache_SetContextFromCache_m_2045882049_0 (Object_t * __this /* static, unused */, Context_t_1281777657_0 * ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
