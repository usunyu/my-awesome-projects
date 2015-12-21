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

// System.Resources.ResourceReader
struct ResourceReader_t_1480646667_0;
// System.IO.Stream
struct Stream_t463444077_0;
// System.String
struct String_t;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;
// System.Object
struct Object_t;
// System.Type
struct Type_t;
// System.Resources.ResourceReader/ResourceCacheItem[]
struct ResourceCacheItemU5BU5D_t1160291759_0;
// System.Collections.IDictionaryEnumerator
struct IDictionaryEnumerator_t_855216337_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Resources_ResourceReader_ResourceI_398941738.h"

// System.Void System.Resources.ResourceReader::.ctor(System.IO.Stream)
extern "C"  void ResourceReader__ctor_m_273679790_0 (ResourceReader_t_1480646667_0 * __this, Stream_t463444077_0 * ___stream, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Resources.ResourceReader::.ctor(System.String)
extern "C"  void ResourceReader__ctor_m_388104921_0 (ResourceReader_t_1480646667_0 * __this, String_t* ___fileName, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator System.Resources.ResourceReader::System.Collections.IEnumerable.GetEnumerator()
extern "C"  Object_t * ResourceReader_System_Collections_IEnumerable_GetEnumerator_m117947704_0 (ResourceReader_t_1480646667_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Resources.ResourceReader::System.IDisposable.Dispose()
extern "C"  void ResourceReader_System_IDisposable_Dispose_m275527876_0 (ResourceReader_t_1480646667_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Resources.ResourceReader::ReadHeaders()
extern "C"  void ResourceReader_ReadHeaders_m1907491305_0 (ResourceReader_t_1480646667_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Resources.ResourceReader::CreateResourceInfo(System.Int64,System.Resources.ResourceReader/ResourceInfo&)
extern "C"  void ResourceReader_CreateResourceInfo_m5769771_0 (ResourceReader_t_1480646667_0 * __this, int64_t ___position, ResourceInfo_t_398941738_0 * ___info, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Resources.ResourceReader::Read7BitEncodedInt()
extern "C"  int32_t ResourceReader_Read7BitEncodedInt_m1807673690_0 (ResourceReader_t_1480646667_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Resources.ResourceReader::ReadValueVer2(System.Int32)
extern "C"  Object_t * ResourceReader_ReadValueVer2_m_1226313943_0 (ResourceReader_t_1480646667_0 * __this, int32_t ___type_index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Resources.ResourceReader::ReadValueVer1(System.Type)
extern "C"  Object_t * ResourceReader_ReadValueVer1_m60842242_0 (ResourceReader_t_1480646667_0 * __this, Type_t * ___type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Resources.ResourceReader::ReadNonPredefinedValue(System.Type)
extern "C"  Object_t * ResourceReader_ReadNonPredefinedValue_m_978149007_0 (ResourceReader_t_1480646667_0 * __this, Type_t * ___exp_type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Resources.ResourceReader::LoadResourceValues(System.Resources.ResourceReader/ResourceCacheItem[])
extern "C"  void ResourceReader_LoadResourceValues_m1190122720_0 (ResourceReader_t_1480646667_0 * __this, ResourceCacheItemU5BU5D_t1160291759_0* ___store, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Resources.ResourceReader::Close()
extern "C"  void ResourceReader_Close_m551956177_0 (ResourceReader_t_1480646667_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IDictionaryEnumerator System.Resources.ResourceReader::GetEnumerator()
extern "C"  Object_t * ResourceReader_GetEnumerator_m1820124275_0 (ResourceReader_t_1480646667_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Resources.ResourceReader::Dispose(System.Boolean)
extern "C"  void ResourceReader_Dispose_m1411491503_0 (ResourceReader_t_1480646667_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
