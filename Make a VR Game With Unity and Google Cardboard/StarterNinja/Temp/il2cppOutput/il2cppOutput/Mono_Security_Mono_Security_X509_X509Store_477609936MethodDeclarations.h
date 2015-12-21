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

// Mono.Security.X509.X509Store
struct X509Store_t_477609936_0;
// System.String
struct String_t;
// Mono.Security.X509.X509CertificateCollection
struct X509CertificateCollection_t15320292_0;
// System.Collections.ArrayList
struct ArrayList_t536890563_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// Mono.Security.X509.X509Certificate
struct X509Certificate_t219648422_0;
// Mono.Security.X509.X509Crl
struct X509Crl_t_956935956_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.X509.X509Store::.ctor(System.String,System.Boolean)
extern "C"  void X509Store__ctor_m_554294083_0 (X509Store_t_477609936_0 * __this, String_t* ___path, bool ___crl, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.X509.X509CertificateCollection Mono.Security.X509.X509Store::get_Certificates()
extern "C"  X509CertificateCollection_t15320292_0 * X509Store_get_Certificates_m_477213992_0 (X509Store_t_477609936_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.ArrayList Mono.Security.X509.X509Store::get_Crls()
extern "C"  ArrayList_t536890563_0 * X509Store_get_Crls_m_2073308099_0 (X509Store_t_477609936_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.X509.X509Store::Load(System.String)
extern "C"  ByteU5BU5D_t_1238178395_0* X509Store_Load_m507057712_0 (X509Store_t_477609936_0 * __this, String_t* ___filename, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.X509.X509Certificate Mono.Security.X509.X509Store::LoadCertificate(System.String)
extern "C"  X509Certificate_t219648422_0 * X509Store_LoadCertificate_m_2013700388_0 (X509Store_t_477609936_0 * __this, String_t* ___filename, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.X509.X509Crl Mono.Security.X509.X509Store::LoadCrl(System.String)
extern "C"  X509Crl_t_956935956_0 * X509Store_LoadCrl_m371472464_0 (X509Store_t_477609936_0 * __this, String_t* ___filename, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.X509.X509Store::CheckStore(System.String,System.Boolean)
extern "C"  bool X509Store_CheckStore_m_97822524_0 (X509Store_t_477609936_0 * __this, String_t* ___path, bool ___throwException, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.X509.X509CertificateCollection Mono.Security.X509.X509Store::BuildCertificatesCollection(System.String)
extern "C"  X509CertificateCollection_t15320292_0 * X509Store_BuildCertificatesCollection_m1851273927_0 (X509Store_t_477609936_0 * __this, String_t* ___storeName, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.ArrayList Mono.Security.X509.X509Store::BuildCrlsCollection(System.String)
extern "C"  ArrayList_t536890563_0 * X509Store_BuildCrlsCollection_m_1743160584_0 (X509Store_t_477609936_0 * __this, String_t* ___storeName, const MethodInfo* method) IL2CPP_METHOD_ATTR;
