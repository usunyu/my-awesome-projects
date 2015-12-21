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

// System.Security.Cryptography.X509Certificates.X509ExtensionCollection
struct X509ExtensionCollection_t_424340636_0;
// Mono.Security.X509.X509Certificate
struct X509Certificate_t219648422_0;
// System.Array
struct Array_t;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;
// System.Object
struct Object_t;
// System.Security.Cryptography.X509Certificates.X509Extension
struct X509Extension_t_1686437850_0;
// System.String
struct String_t;
// System.Security.Cryptography.X509Certificates.X509ExtensionEnumerator
struct X509ExtensionEnumerator_t396311690_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Security.Cryptography.X509Certificates.X509ExtensionCollection::.ctor(Mono.Security.X509.X509Certificate)
extern "C"  void X509ExtensionCollection__ctor_m_406226624_0 (X509ExtensionCollection_t_424340636_0 * __this, X509Certificate_t219648422_0 * ___cert, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509ExtensionCollection::System.Collections.ICollection.CopyTo(System.Array,System.Int32)
extern "C"  void X509ExtensionCollection_System_Collections_ICollection_CopyTo_m_1432715688_0 (X509ExtensionCollection_t_424340636_0 * __this, Array_t * ___array, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator System.Security.Cryptography.X509Certificates.X509ExtensionCollection::System.Collections.IEnumerable.GetEnumerator()
extern "C"  Object_t * X509ExtensionCollection_System_Collections_IEnumerable_GetEnumerator_m1951031507_0 (X509ExtensionCollection_t_424340636_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Security.Cryptography.X509Certificates.X509ExtensionCollection::get_Count()
extern "C"  int32_t X509ExtensionCollection_get_Count_m_1673707872_0 (X509ExtensionCollection_t_424340636_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Security.Cryptography.X509Certificates.X509ExtensionCollection::get_IsSynchronized()
extern "C"  bool X509ExtensionCollection_get_IsSynchronized_m_1093527959_0 (X509ExtensionCollection_t_424340636_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Security.Cryptography.X509Certificates.X509ExtensionCollection::get_SyncRoot()
extern "C"  Object_t * X509ExtensionCollection_get_SyncRoot_m736404969_0 (X509ExtensionCollection_t_424340636_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509Extension System.Security.Cryptography.X509Certificates.X509ExtensionCollection::get_Item(System.String)
extern "C"  X509Extension_t_1686437850_0 * X509ExtensionCollection_get_Item_m_1953551359_0 (X509ExtensionCollection_t_424340636_0 * __this, String_t* ___oid, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509ExtensionEnumerator System.Security.Cryptography.X509Certificates.X509ExtensionCollection::GetEnumerator()
extern "C"  X509ExtensionEnumerator_t396311690_0 * X509ExtensionCollection_GetEnumerator_m_215497837_0 (X509ExtensionCollection_t_424340636_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
