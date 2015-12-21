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

// Mono.Security.Protocol.Tls.HttpsClientStream
struct HttpsClientStream_t97885198_0;
// System.IO.Stream
struct Stream_t463444077_0;
// System.Security.Cryptography.X509Certificates.X509CertificateCollection
struct X509CertificateCollection_t_798278404_0;
// System.Net.HttpWebRequest
struct HttpWebRequest_t713113337_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Security.Cryptography.X509Certificates.X509Certificate
struct X509Certificate_t1524084820_0;
// System.Int32[]
struct Int32U5BU5D_t1872284309_0;
// System.String
struct String_t;
// System.Security.Cryptography.AsymmetricAlgorithm
struct AsymmetricAlgorithm_t1451338986_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.Protocol.Tls.HttpsClientStream::.ctor(System.IO.Stream,System.Security.Cryptography.X509Certificates.X509CertificateCollection,System.Net.HttpWebRequest,System.Byte[])
extern "C"  void HttpsClientStream__ctor_m1831138033_0 (HttpsClientStream_t97885198_0 * __this, Stream_t463444077_0 * ___stream, X509CertificateCollection_t_798278404_0 * ___clientCertificates, HttpWebRequest_t713113337_0 * ___request, ByteU5BU5D_t_1238178395_0* ___buffer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.HttpsClientStream::get_TrustFailure()
extern "C"  bool HttpsClientStream_get_TrustFailure_m1743569637_0 (HttpsClientStream_t97885198_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.HttpsClientStream::RaiseServerCertificateValidation(System.Security.Cryptography.X509Certificates.X509Certificate,System.Int32[])
extern "C"  bool HttpsClientStream_RaiseServerCertificateValidation_m1414843622_0 (HttpsClientStream_t97885198_0 * __this, X509Certificate_t1524084820_0 * ___certificate, Int32U5BU5D_t1872284309_0* ___certificateErrors, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509Certificate Mono.Security.Protocol.Tls.HttpsClientStream::<HttpsClientStream>m__0(System.Security.Cryptography.X509Certificates.X509CertificateCollection,System.Security.Cryptography.X509Certificates.X509Certificate,System.String,System.Security.Cryptography.X509Certificates.X509CertificateCollection)
extern "C"  X509Certificate_t1524084820_0 * HttpsClientStream_U3CHttpsClientStreamU3Em__0_m_838940752_0 (Object_t * __this /* static, unused */, X509CertificateCollection_t_798278404_0 * ___clientCerts, X509Certificate_t1524084820_0 * ___serverCertificate, String_t* ___targetHost, X509CertificateCollection_t_798278404_0 * ___serverRequestedCertificates, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.AsymmetricAlgorithm Mono.Security.Protocol.Tls.HttpsClientStream::<HttpsClientStream>m__1(System.Security.Cryptography.X509Certificates.X509Certificate,System.String)
extern "C"  AsymmetricAlgorithm_t1451338986_0 * HttpsClientStream_U3CHttpsClientStreamU3Em__1_m_445463975_0 (Object_t * __this /* static, unused */, X509Certificate_t1524084820_0 * ___certificate, String_t* ___targetHost, const MethodInfo* method) IL2CPP_METHOD_ATTR;
