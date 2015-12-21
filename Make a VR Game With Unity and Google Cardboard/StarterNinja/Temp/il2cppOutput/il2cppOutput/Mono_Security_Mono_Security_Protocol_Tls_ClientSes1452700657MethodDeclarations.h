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

// Mono.Security.Protocol.Tls.ClientSessionInfo
struct ClientSessionInfo_t1452700657_0;
// System.String
struct String_t;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// Mono.Security.Protocol.Tls.Context
struct Context_t_1281777657_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.Protocol.Tls.ClientSessionInfo::.ctor(System.String,System.Byte[])
extern "C"  void ClientSessionInfo__ctor_m_308924640_0 (ClientSessionInfo_t1452700657_0 * __this, String_t* ___hostname, ByteU5BU5D_t_1238178395_0* ___id, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.ClientSessionInfo::.cctor()
extern "C"  void ClientSessionInfo__cctor_m1522715144_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.ClientSessionInfo::Finalize()
extern "C"  void ClientSessionInfo_Finalize_m_1714097155_0 (ClientSessionInfo_t1452700657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.Protocol.Tls.ClientSessionInfo::get_HostName()
extern "C"  String_t* ClientSessionInfo_get_HostName_m_9569442_0 (ClientSessionInfo_t1452700657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.ClientSessionInfo::get_Id()
extern "C"  ByteU5BU5D_t_1238178395_0* ClientSessionInfo_get_Id_m277031725_0 (ClientSessionInfo_t1452700657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.ClientSessionInfo::get_Valid()
extern "C"  bool ClientSessionInfo_get_Valid_m_996365080_0 (ClientSessionInfo_t1452700657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.ClientSessionInfo::GetContext(Mono.Security.Protocol.Tls.Context)
extern "C"  void ClientSessionInfo_GetContext_m_23821553_0 (ClientSessionInfo_t1452700657_0 * __this, Context_t_1281777657_0 * ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.ClientSessionInfo::SetContext(Mono.Security.Protocol.Tls.Context)
extern "C"  void ClientSessionInfo_SetContext_m_1339087229_0 (ClientSessionInfo_t1452700657_0 * __this, Context_t_1281777657_0 * ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.ClientSessionInfo::KeepAlive()
extern "C"  void ClientSessionInfo_KeepAlive_m_1183800149_0 (ClientSessionInfo_t1452700657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.ClientSessionInfo::Dispose()
extern "C"  void ClientSessionInfo_Dispose_m1917892930_0 (ClientSessionInfo_t1452700657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.ClientSessionInfo::Dispose(System.Boolean)
extern "C"  void ClientSessionInfo_Dispose_m_485420231_0 (ClientSessionInfo_t1452700657_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.ClientSessionInfo::CheckDisposed()
extern "C"  void ClientSessionInfo_CheckDisposed_m_765989520_0 (ClientSessionInfo_t1452700657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
