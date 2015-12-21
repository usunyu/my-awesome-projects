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

// System.Collections.Hashtable/SyncHashtable
struct SyncHashtable_t355404770_0;
// System.Collections.Hashtable
struct Hashtable_t_2004451924_0;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;
// System.Object
struct Object_t;
// System.Collections.ICollection
struct ICollection_t592284435_0;
// System.Array
struct Array_t;
// System.Collections.IDictionaryEnumerator
struct IDictionaryEnumerator_t_855216337_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"

// System.Void System.Collections.Hashtable/SyncHashtable::.ctor(System.Collections.Hashtable)
extern "C"  void SyncHashtable__ctor_m_578312724_0 (SyncHashtable_t355404770_0 * __this, Hashtable_t_2004451924_0 * ___host, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable/SyncHashtable::.ctor(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void SyncHashtable__ctor_m330612341_0 (SyncHashtable_t355404770_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator System.Collections.Hashtable/SyncHashtable::System.Collections.IEnumerable.GetEnumerator()
extern "C"  Object_t * SyncHashtable_System_Collections_IEnumerable_GetEnumerator_m_268075509_0 (SyncHashtable_t355404770_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable/SyncHashtable::GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void SyncHashtable_GetObjectData_m765378770_0 (SyncHashtable_t355404770_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.Hashtable/SyncHashtable::get_Count()
extern "C"  int32_t SyncHashtable_get_Count_m_731728484_0 (SyncHashtable_t355404770_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.Hashtable/SyncHashtable::get_IsSynchronized()
extern "C"  bool SyncHashtable_get_IsSynchronized_m_793264647_0 (SyncHashtable_t355404770_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Collections.Hashtable/SyncHashtable::get_SyncRoot()
extern "C"  Object_t * SyncHashtable_get_SyncRoot_m513487403_0 (SyncHashtable_t355404770_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.ICollection System.Collections.Hashtable/SyncHashtable::get_Keys()
extern "C"  Object_t * SyncHashtable_get_Keys_m_211655159_0 (SyncHashtable_t355404770_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.ICollection System.Collections.Hashtable/SyncHashtable::get_Values()
extern "C"  Object_t * SyncHashtable_get_Values_m830409911_0 (SyncHashtable_t355404770_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Collections.Hashtable/SyncHashtable::get_Item(System.Object)
extern "C"  Object_t * SyncHashtable_get_Item_m_1298656493_0 (SyncHashtable_t355404770_0 * __this, Object_t * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable/SyncHashtable::set_Item(System.Object,System.Object)
extern "C"  void SyncHashtable_set_Item_m1054132354_0 (SyncHashtable_t355404770_0 * __this, Object_t * ___key, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable/SyncHashtable::CopyTo(System.Array,System.Int32)
extern "C"  void SyncHashtable_CopyTo_m_441826543_0 (SyncHashtable_t355404770_0 * __this, Array_t * ___array, int32_t ___arrayIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable/SyncHashtable::Add(System.Object,System.Object)
extern "C"  void SyncHashtable_Add_m626175119_0 (SyncHashtable_t355404770_0 * __this, Object_t * ___key, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable/SyncHashtable::Clear()
extern "C"  void SyncHashtable_Clear_m1117089631_0 (SyncHashtable_t355404770_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.Hashtable/SyncHashtable::Contains(System.Object)
extern "C"  bool SyncHashtable_Contains_m2133514563_0 (SyncHashtable_t355404770_0 * __this, Object_t * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IDictionaryEnumerator System.Collections.Hashtable/SyncHashtable::GetEnumerator()
extern "C"  Object_t * SyncHashtable_GetEnumerator_m1352826924_0 (SyncHashtable_t355404770_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable/SyncHashtable::Remove(System.Object)
extern "C"  void SyncHashtable_Remove_m1658619584_0 (SyncHashtable_t355404770_0 * __this, Object_t * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.Hashtable/SyncHashtable::ContainsKey(System.Object)
extern "C"  bool SyncHashtable_ContainsKey_m_1277653756_0 (SyncHashtable_t355404770_0 * __this, Object_t * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Collections.Hashtable/SyncHashtable::Clone()
extern "C"  Object_t * SyncHashtable_Clone_m1874575834_0 (SyncHashtable_t355404770_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
