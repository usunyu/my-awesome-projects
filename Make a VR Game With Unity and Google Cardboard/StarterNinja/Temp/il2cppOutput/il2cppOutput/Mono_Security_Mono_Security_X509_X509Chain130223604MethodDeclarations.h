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

// Mono.Security.X509.X509Chain
struct X509Chain_t130223604_0;
// Mono.Security.X509.X509CertificateCollection
struct X509CertificateCollection_t15320292_0;
// Mono.Security.X509.X509Certificate
struct X509Certificate_t219648422_0;

#include "codegen/il2cpp-codegen.h"
#include "Mono_Security_Mono_Security_X509_X509ChainStatusFla402353953.h"

// System.Void Mono.Security.X509.X509Chain::.ctor()
extern "C"  void X509Chain__ctor_m_55260766_0 (X509Chain_t130223604_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.X509Chain::.ctor(Mono.Security.X509.X509CertificateCollection)
extern "C"  void X509Chain__ctor_m_1476655688_0 (X509Chain_t130223604_0 * __this, X509CertificateCollection_t15320292_0 * ___chain, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.X509.X509ChainStatusFlags Mono.Security.X509.X509Chain::get_Status()
extern "C"  int32_t X509Chain_get_Status_m_294130863_0 (X509Chain_t130223604_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.X509.X509CertificateCollection Mono.Security.X509.X509Chain::get_TrustAnchors()
extern "C"  X509CertificateCollection_t15320292_0 * X509Chain_get_TrustAnchors_m885238782_0 (X509Chain_t130223604_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.X509.X509Chain::Build(Mono.Security.X509.X509Certificate)
extern "C"  bool X509Chain_Build_m_1755777036_0 (X509Chain_t130223604_0 * __this, X509Certificate_t219648422_0 * ___leaf, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.X509.X509Chain::IsValid(Mono.Security.X509.X509Certificate)
extern "C"  bool X509Chain_IsValid_m122831928_0 (X509Chain_t130223604_0 * __this, X509Certificate_t219648422_0 * ___cert, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.X509.X509Certificate Mono.Security.X509.X509Chain::FindCertificateParent(Mono.Security.X509.X509Certificate)
extern "C"  X509Certificate_t219648422_0 * X509Chain_FindCertificateParent_m_635589775_0 (X509Chain_t130223604_0 * __this, X509Certificate_t219648422_0 * ___child, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.X509.X509Certificate Mono.Security.X509.X509Chain::FindCertificateRoot(Mono.Security.X509.X509Certificate)
extern "C"  X509Certificate_t219648422_0 * X509Chain_FindCertificateRoot_m_868578263_0 (X509Chain_t130223604_0 * __this, X509Certificate_t219648422_0 * ___potentialRoot, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.X509.X509Chain::IsTrusted(Mono.Security.X509.X509Certificate)
extern "C"  bool X509Chain_IsTrusted_m622221811_0 (X509Chain_t130223604_0 * __this, X509Certificate_t219648422_0 * ___potentialTrusted, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.X509.X509Chain::IsParent(Mono.Security.X509.X509Certificate,Mono.Security.X509.X509Certificate)
extern "C"  bool X509Chain_IsParent_m_486965150_0 (X509Chain_t130223604_0 * __this, X509Certificate_t219648422_0 * ___child, X509Certificate_t219648422_0 * ___parent, const MethodInfo* method) IL2CPP_METHOD_ATTR;
