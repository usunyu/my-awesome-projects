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

// System.Resources.ResourceSet
struct ResourceSet_t290886256_0;
// System.IO.Stream
struct Stream_t463444077_0;
// System.IO.UnmanagedMemoryStream
struct UnmanagedMemoryStream_t_1244540582_0;
// System.String
struct String_t;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;
// System.Collections.IDictionaryEnumerator
struct IDictionaryEnumerator_t_855216337_0;
// System.Object
struct Object_t;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Resources.ResourceSet::.ctor()
extern "C"  void ResourceSet__ctor_m_2139133530_0 (ResourceSet_t290886256_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Resources.ResourceSet::.ctor(System.IO.Stream)
extern "C"  void ResourceSet__ctor_m1435739197_0 (ResourceSet_t290886256_0 * __this, Stream_t463444077_0 * ___stream, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Resources.ResourceSet::.ctor(System.IO.UnmanagedMemoryStream)
extern "C"  void ResourceSet__ctor_m1446669582_0 (ResourceSet_t290886256_0 * __this, UnmanagedMemoryStream_t_1244540582_0 * ___stream, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Resources.ResourceSet::.ctor(System.String)
extern "C"  void ResourceSet__ctor_m_909798628_0 (ResourceSet_t290886256_0 * __this, String_t* ___fileName, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator System.Resources.ResourceSet::System.Collections.IEnumerable.GetEnumerator()
extern "C"  Object_t * ResourceSet_System_Collections_IEnumerable_GetEnumerator_m_1924838951_0 (ResourceSet_t290886256_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Resources.ResourceSet::Dispose()
extern "C"  void ResourceSet_Dispose_m1480295523_0 (ResourceSet_t290886256_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Resources.ResourceSet::Dispose(System.Boolean)
extern "C"  void ResourceSet_Dispose_m_1174056806_0 (ResourceSet_t290886256_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IDictionaryEnumerator System.Resources.ResourceSet::GetEnumerator()
extern "C"  Object_t * ResourceSet_GetEnumerator_m1116109982_0 (ResourceSet_t290886256_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Resources.ResourceSet::GetObjectInternal(System.String,System.Boolean)
extern "C"  Object_t * ResourceSet_GetObjectInternal_m_2086243140_0 (ResourceSet_t290886256_0 * __this, String_t* ___name, bool ___ignoreCase, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Resources.ResourceSet::GetObject(System.String)
extern "C"  Object_t * ResourceSet_GetObject_m543692318_0 (ResourceSet_t290886256_0 * __this, String_t* ___name, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Resources.ResourceSet::GetObject(System.String,System.Boolean)
extern "C"  Object_t * ResourceSet_GetObject_m100760991_0 (ResourceSet_t290886256_0 * __this, String_t* ___name, bool ___ignoreCase, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Resources.ResourceSet::ReadResources()
extern "C"  void ResourceSet_ReadResources_m_1705395917_0 (ResourceSet_t290886256_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
