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

// System.Security.Cryptography.OidCollection
struct OidCollection_t_322472593_0;
// System.Array
struct Array_t;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;
// System.Security.Cryptography.Oid
struct Oid_t1024680945_0;
// System.Object
struct Object_t;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Security.Cryptography.OidCollection::.ctor()
extern "C"  void OidCollection__ctor_m_702469817_0 (OidCollection_t_322472593_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.OidCollection::System.Collections.ICollection.CopyTo(System.Array,System.Int32)
extern "C"  void OidCollection_System_Collections_ICollection_CopyTo_m_1094615587_0 (OidCollection_t_322472593_0 * __this, Array_t * ___array, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator System.Security.Cryptography.OidCollection::System.Collections.IEnumerable.GetEnumerator()
extern "C"  Object_t * OidCollection_System_Collections_IEnumerable_GetEnumerator_m494890284_0 (OidCollection_t_322472593_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Security.Cryptography.OidCollection::get_Count()
extern "C"  int32_t OidCollection_get_Count_m924395419_0 (OidCollection_t_322472593_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Security.Cryptography.OidCollection::get_IsSynchronized()
extern "C"  bool OidCollection_get_IsSynchronized_m_1310398374_0 (OidCollection_t_322472593_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.Oid System.Security.Cryptography.OidCollection::get_Item(System.Int32)
extern "C"  Oid_t1024680945_0 * OidCollection_get_Item_m1851824850_0 (OidCollection_t_322472593_0 * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Security.Cryptography.OidCollection::get_SyncRoot()
extern "C"  Object_t * OidCollection_get_SyncRoot_m887599928_0 (OidCollection_t_322472593_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Security.Cryptography.OidCollection::Add(System.Security.Cryptography.Oid)
extern "C"  int32_t OidCollection_Add_m1834548415_0 (OidCollection_t_322472593_0 * __this, Oid_t1024680945_0 * ___oid, const MethodInfo* method) IL2CPP_METHOD_ATTR;
