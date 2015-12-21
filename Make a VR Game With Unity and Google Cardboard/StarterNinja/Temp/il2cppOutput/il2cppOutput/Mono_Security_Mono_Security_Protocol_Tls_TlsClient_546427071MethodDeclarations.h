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

// Mono.Security.Protocol.Tls.TlsClientSettings
struct TlsClientSettings_t_546427071_0;
// System.String
struct String_t;
// System.Security.Cryptography.X509Certificates.X509CertificateCollection
struct X509CertificateCollection_t_798278404_0;
// System.Security.Cryptography.X509Certificates.X509Certificate
struct X509Certificate_t1524084820_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.Protocol.Tls.TlsClientSettings::.ctor()
extern "C"  void TlsClientSettings__ctor_m929581301_0 (TlsClientSettings_t_546427071_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.Protocol.Tls.TlsClientSettings::get_TargetHost()
extern "C"  String_t* TlsClientSettings_get_TargetHost_m_142128844_0 (TlsClientSettings_t_546427071_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.TlsClientSettings::set_TargetHost(System.String)
extern "C"  void TlsClientSettings_set_TargetHost_m2074298781_0 (TlsClientSettings_t_546427071_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509CertificateCollection Mono.Security.Protocol.Tls.TlsClientSettings::get_Certificates()
extern "C"  X509CertificateCollection_t_798278404_0 * TlsClientSettings_get_Certificates_m_718615983_0 (TlsClientSettings_t_546427071_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.TlsClientSettings::set_Certificates(System.Security.Cryptography.X509Certificates.X509CertificateCollection)
extern "C"  void TlsClientSettings_set_Certificates_m_2098433324_0 (TlsClientSettings_t_546427071_0 * __this, X509CertificateCollection_t_798278404_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509Certificate Mono.Security.Protocol.Tls.TlsClientSettings::get_ClientCertificate()
extern "C"  X509Certificate_t1524084820_0 * TlsClientSettings_get_ClientCertificate_m1621563643_0 (TlsClientSettings_t_546427071_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.TlsClientSettings::set_ClientCertificate(System.Security.Cryptography.X509Certificates.X509Certificate)
extern "C"  void TlsClientSettings_set_ClientCertificate_m1801603000_0 (TlsClientSettings_t_546427071_0 * __this, X509Certificate_t1524084820_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.TlsClientSettings::UpdateCertificateRSA()
extern "C"  void TlsClientSettings_UpdateCertificateRSA_m715783041_0 (TlsClientSettings_t_546427071_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
