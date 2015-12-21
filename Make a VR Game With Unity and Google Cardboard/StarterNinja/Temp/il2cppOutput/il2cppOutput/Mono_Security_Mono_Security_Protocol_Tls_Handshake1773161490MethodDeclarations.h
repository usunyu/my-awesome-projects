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

// Mono.Security.Protocol.Tls.Handshake.Client.TlsServerCertificateRequest
struct TlsServerCertificateRequest_t1773161490_0;
// Mono.Security.Protocol.Tls.Context
struct Context_t_1281777657_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.Protocol.Tls.Handshake.Client.TlsServerCertificateRequest::.ctor(Mono.Security.Protocol.Tls.Context,System.Byte[])
extern "C"  void TlsServerCertificateRequest__ctor_m_1959315208_0 (TlsServerCertificateRequest_t1773161490_0 * __this, Context_t_1281777657_0 * ___context, ByteU5BU5D_t_1238178395_0* ___buffer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Handshake.Client.TlsServerCertificateRequest::Update()
extern "C"  void TlsServerCertificateRequest_Update_m_1995520881_0 (TlsServerCertificateRequest_t1773161490_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Handshake.Client.TlsServerCertificateRequest::ProcessAsSsl3()
extern "C"  void TlsServerCertificateRequest_ProcessAsSsl3_m_1322806108_0 (TlsServerCertificateRequest_t1773161490_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Handshake.Client.TlsServerCertificateRequest::ProcessAsTls1()
extern "C"  void TlsServerCertificateRequest_ProcessAsTls1_m_1300434989_0 (TlsServerCertificateRequest_t1773161490_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
