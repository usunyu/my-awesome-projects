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

// Mono.Security.X509.X509CertificateCollection
struct X509CertificateCollection_t_865204850_0;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;
// Mono.Security.X509.X509Certificate
struct X509Certificate_t_1016414512_0;
// Mono.Security.X509.X509CertificateCollection/X509CertificateEnumerator
struct X509CertificateEnumerator_t_1965417100_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.X509.X509CertificateCollection::.ctor()
extern "C"  void X509CertificateCollection__ctor_m_1355476408_0 (X509CertificateCollection_t_865204850_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator Mono.Security.X509.X509CertificateCollection::System.Collections.IEnumerable.GetEnumerator()
extern "C"  Object_t * X509CertificateCollection_System_Collections_IEnumerable_GetEnumerator_m2090803959_0 (X509CertificateCollection_t_865204850_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.X509.X509Certificate Mono.Security.X509.X509CertificateCollection::get_Item(System.Int32)
extern "C"  X509Certificate_t_1016414512_0 * X509CertificateCollection_get_Item_m1700022920_0 (X509CertificateCollection_t_865204850_0 * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.X509.X509CertificateCollection::Add(Mono.Security.X509.X509Certificate)
extern "C"  int32_t X509CertificateCollection_Add_m_961347457_0 (X509CertificateCollection_t_865204850_0 * __this, X509Certificate_t_1016414512_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.X509.X509CertificateCollection/X509CertificateEnumerator Mono.Security.X509.X509CertificateCollection::GetEnumerator()
extern "C"  X509CertificateEnumerator_t_1965417100_0 * X509CertificateCollection_GetEnumerator_m_1801128251_0 (X509CertificateCollection_t_865204850_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.X509.X509CertificateCollection::GetHashCode()
extern "C"  int32_t X509CertificateCollection_GetHashCode_m_1909439653_0 (X509CertificateCollection_t_865204850_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
