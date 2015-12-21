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

// Mono.Security.Protocol.Tls.Handshake.Client.TlsClientKeyExchange
struct TlsClientKeyExchange_t1866634816_0;
// Mono.Security.Protocol.Tls.Context
struct Context_t_1281777657_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.Protocol.Tls.Handshake.Client.TlsClientKeyExchange::.ctor(Mono.Security.Protocol.Tls.Context)
extern "C"  void TlsClientKeyExchange__ctor_m2125938125_0 (TlsClientKeyExchange_t1866634816_0 * __this, Context_t_1281777657_0 * ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Handshake.Client.TlsClientKeyExchange::ProcessAsSsl3()
extern "C"  void TlsClientKeyExchange_ProcessAsSsl3_m1953591228_0 (TlsClientKeyExchange_t1866634816_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Handshake.Client.TlsClientKeyExchange::ProcessAsTls1()
extern "C"  void TlsClientKeyExchange_ProcessAsTls1_m1975962347_0 (TlsClientKeyExchange_t1866634816_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Handshake.Client.TlsClientKeyExchange::ProcessCommon(System.Boolean)
extern "C"  void TlsClientKeyExchange_ProcessCommon_m_247408859_0 (TlsClientKeyExchange_t1866634816_0 * __this, bool ___sendLength, const MethodInfo* method) IL2CPP_METHOD_ATTR;
