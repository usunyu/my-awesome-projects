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

// Mono.Security.X509.X509ExtensionCollection
struct X509ExtensionCollection_t_1920699060_0;
// Mono.Security.ASN1
struct ASN1_t311288114_0;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;
// System.String
struct String_t;
// Mono.Security.X509.X509Extension
struct X509Extension_t_556260338_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.X509.X509ExtensionCollection::.ctor()
extern "C"  void X509ExtensionCollection__ctor_m_517498970_0 (X509ExtensionCollection_t_1920699060_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.X509ExtensionCollection::.ctor(Mono.Security.ASN1)
extern "C"  void X509ExtensionCollection__ctor_m2115523054_0 (X509ExtensionCollection_t_1920699060_0 * __this, ASN1_t311288114_0 * ___asn1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator Mono.Security.X509.X509ExtensionCollection::System.Collections.IEnumerable.GetEnumerator()
extern "C"  Object_t * X509ExtensionCollection_System_Collections_IEnumerable_GetEnumerator_m_1706374747_0 (X509ExtensionCollection_t_1920699060_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.X509.X509ExtensionCollection::IndexOf(System.String)
extern "C"  int32_t X509ExtensionCollection_IndexOf_m1626273533_0 (X509ExtensionCollection_t_1920699060_0 * __this, String_t* ___oid, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.X509.X509Extension Mono.Security.X509.X509ExtensionCollection::get_Item(System.String)
extern "C"  X509Extension_t_556260338_0 * X509ExtensionCollection_get_Item_m2008681985_0 (X509ExtensionCollection_t_1920699060_0 * __this, String_t* ___oid, const MethodInfo* method) IL2CPP_METHOD_ATTR;
