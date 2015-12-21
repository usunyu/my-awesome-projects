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

// Mono.Security.Protocol.Tls.Handshake.Client.TlsClientCertificateVerify
struct TlsClientCertificateVerify_t97275662_0;
// Mono.Security.Protocol.Tls.Context
struct Context_t_1281777657_0;
// System.Security.Cryptography.RSA
struct RSA_t1573116945_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.Protocol.Tls.Handshake.Client.TlsClientCertificateVerify::.ctor(Mono.Security.Protocol.Tls.Context)
extern "C"  void TlsClientCertificateVerify__ctor_m_1288894977_0 (TlsClientCertificateVerify_t97275662_0 * __this, Context_t_1281777657_0 * ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Handshake.Client.TlsClientCertificateVerify::Update()
extern "C"  void TlsClientCertificateVerify_Update_m1777063429_0 (TlsClientCertificateVerify_t97275662_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Handshake.Client.TlsClientCertificateVerify::ProcessAsSsl3()
extern "C"  void TlsClientCertificateVerify_ProcessAsSsl3_m1668289134_0 (TlsClientCertificateVerify_t97275662_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Handshake.Client.TlsClientCertificateVerify::ProcessAsTls1()
extern "C"  void TlsClientCertificateVerify_ProcessAsTls1_m1690660253_0 (TlsClientCertificateVerify_t97275662_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.RSA Mono.Security.Protocol.Tls.Handshake.Client.TlsClientCertificateVerify::getClientCertRSA(System.Security.Cryptography.RSA)
extern "C"  RSA_t1573116945_0 * TlsClientCertificateVerify_getClientCertRSA_m_708814636_0 (TlsClientCertificateVerify_t97275662_0 * __this, RSA_t1573116945_0 * ___privKey, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.Handshake.Client.TlsClientCertificateVerify::getUnsignedBigInteger(System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* TlsClientCertificateVerify_getUnsignedBigInteger_m1216540004_0 (TlsClientCertificateVerify_t97275662_0 * __this, ByteU5BU5D_t_1238178395_0* ___integer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
