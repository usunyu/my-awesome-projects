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

// Mono.Security.Protocol.Tls.ClientContext
struct ClientContext_t517167036_0;
// Mono.Security.Protocol.Tls.SslClientStream
struct SslClientStream_t_297869905_0;
// System.String
struct String_t;
// System.Security.Cryptography.X509Certificates.X509CertificateCollection
struct X509CertificateCollection_t_798278404_0;

#include "codegen/il2cpp-codegen.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_SecurityP_942303750.h"

// System.Void Mono.Security.Protocol.Tls.ClientContext::.ctor(Mono.Security.Protocol.Tls.SslClientStream,Mono.Security.Protocol.Tls.SecurityProtocolType,System.String,System.Security.Cryptography.X509Certificates.X509CertificateCollection)
extern "C"  void ClientContext__ctor_m483520879_0 (ClientContext_t517167036_0 * __this, SslClientStream_t_297869905_0 * ___stream, int32_t ___securityProtocolType, String_t* ___targetHost, X509CertificateCollection_t_798278404_0 * ___clientCertificates, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.SslClientStream Mono.Security.Protocol.Tls.ClientContext::get_SslStream()
extern "C"  SslClientStream_t_297869905_0 * ClientContext_get_SslStream_m714880213_0 (ClientContext_t517167036_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int16 Mono.Security.Protocol.Tls.ClientContext::get_ClientHelloProtocol()
extern "C"  int16_t ClientContext_get_ClientHelloProtocol_m_1211330516_0 (ClientContext_t517167036_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.ClientContext::set_ClientHelloProtocol(System.Int16)
extern "C"  void ClientContext_set_ClientHelloProtocol_m31446181_0 (ClientContext_t517167036_0 * __this, int16_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.ClientContext::Clear()
extern "C"  void ClientContext_Clear_m_1585547131_0 (ClientContext_t517167036_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
