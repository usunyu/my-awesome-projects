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

// System.Collections.Hashtable
struct Hashtable_t_2004451924_0;
// System.Collections.IHashCodeProvider
struct IHashCodeProvider_t_124535839_0;
// System.Collections.IComparer
struct IComparer_t622777826_0;
// System.Collections.IDictionary
struct IDictionary_t_1514320629_0;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;
// System.Collections.IEqualityComparer
struct IEqualityComparer_t_555839492_0;
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
// System.Collections.Hashtable/Slot[]
struct SlotU5BU5D_t_50707517_0;
// System.Int32[]
struct Int32U5BU5D_t1872284309_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"
#include "mscorlib_System_Collections_Hashtable_EnumeratorM_1477753238.h"

// System.Void System.Collections.Hashtable::.ctor()
extern "C"  void Hashtable__ctor_m1514037738_0 (Hashtable_t_2004451924_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::.ctor(System.Int32,System.Single,System.Collections.IHashCodeProvider,System.Collections.IComparer)
extern "C"  void Hashtable__ctor_m880032671_0 (Hashtable_t_2004451924_0 * __this, int32_t ___capacity, float ___loadFactor, Object_t * ___hcp, Object_t * ___comparer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::.ctor(System.Int32,System.Single)
extern "C"  void Hashtable__ctor_m_1375432736_0 (Hashtable_t_2004451924_0 * __this, int32_t ___capacity, float ___loadFactor, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::.ctor(System.Int32)
extern "C"  void Hashtable__ctor_m_1392080837_0 (Hashtable_t_2004451924_0 * __this, int32_t ___capacity, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::.ctor(System.Collections.Hashtable)
extern "C"  void Hashtable__ctor_m556844962_0 (Hashtable_t_2004451924_0 * __this, Hashtable_t_2004451924_0 * ___source, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::.ctor(System.Int32,System.Collections.IHashCodeProvider,System.Collections.IComparer)
extern "C"  void Hashtable__ctor_m2095001914_0 (Hashtable_t_2004451924_0 * __this, int32_t ___capacity, Object_t * ___hcp, Object_t * ___comparer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::.ctor(System.Collections.IDictionary,System.Single,System.Collections.IHashCodeProvider,System.Collections.IComparer)
extern "C"  void Hashtable__ctor_m775991879_0 (Hashtable_t_2004451924_0 * __this, Object_t * ___d, float ___loadFactor, Object_t * ___hcp, Object_t * ___comparer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::.ctor(System.Collections.IDictionary,System.Collections.IHashCodeProvider,System.Collections.IComparer)
extern "C"  void Hashtable__ctor_m1961291234_0 (Hashtable_t_2004451924_0 * __this, Object_t * ___d, Object_t * ___hcp, Object_t * ___comparer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::.ctor(System.Collections.IHashCodeProvider,System.Collections.IComparer)
extern "C"  void Hashtable__ctor_m346689243_0 (Hashtable_t_2004451924_0 * __this, Object_t * ___hcp, Object_t * ___comparer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::.ctor(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void Hashtable__ctor_m_2081083349_0 (Hashtable_t_2004451924_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::.ctor(System.Int32,System.Collections.IEqualityComparer)
extern "C"  void Hashtable__ctor_m553622419_0 (Hashtable_t_2004451924_0 * __this, int32_t ___capacity, Object_t * ___equalityComparer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::.ctor(System.Int32,System.Single,System.Collections.IEqualityComparer)
extern "C"  void Hashtable__ctor_m_2092374258_0 (Hashtable_t_2004451924_0 * __this, int32_t ___capacity, float ___loadFactor, Object_t * ___equalityComparer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::.cctor()
extern "C"  void Hashtable__cctor_m_791566589_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator System.Collections.Hashtable::System.Collections.IEnumerable.GetEnumerator()
extern "C"  Object_t * Hashtable_System_Collections_IEnumerable_GetEnumerator_m2131971349_0 (Hashtable_t_2004451924_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::set_comparer(System.Collections.IComparer)
extern "C"  void Hashtable_set_comparer_m_1102013658_0 (Hashtable_t_2004451924_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::set_hcp(System.Collections.IHashCodeProvider)
extern "C"  void Hashtable_set_hcp_m_990185725_0 (Hashtable_t_2004451924_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.Hashtable::get_Count()
extern "C"  int32_t Hashtable_get_Count_m_957491118_0 (Hashtable_t_2004451924_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.Hashtable::get_IsSynchronized()
extern "C"  bool Hashtable_get_IsSynchronized_m1352381059_0 (Hashtable_t_2004451924_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Collections.Hashtable::get_SyncRoot()
extern "C"  Object_t * Hashtable_get_SyncRoot_m_1674413195_0 (Hashtable_t_2004451924_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.ICollection System.Collections.Hashtable::get_Keys()
extern "C"  Object_t * Hashtable_get_Keys_m17177747_0 (Hashtable_t_2004451924_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.ICollection System.Collections.Hashtable::get_Values()
extern "C"  Object_t * Hashtable_get_Values_m1695500481_0 (Hashtable_t_2004451924_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Collections.Hashtable::get_Item(System.Object)
extern "C"  Object_t * Hashtable_get_Item_m492674313_0 (Hashtable_t_2004451924_0 * __this, Object_t * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::set_Item(System.Object,System.Object)
extern "C"  void Hashtable_set_Item_m1018975416_0 (Hashtable_t_2004451924_0 * __this, Object_t * ___key, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::CopyTo(System.Array,System.Int32)
extern "C"  void Hashtable_CopyTo_m_713270713_0 (Hashtable_t_2004451924_0 * __this, Array_t * ___array, int32_t ___arrayIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::Add(System.Object,System.Object)
extern "C"  void Hashtable_Add_m_2014980455_0 (Hashtable_t_2004451924_0 * __this, Object_t * ___key, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::Clear()
extern "C"  void Hashtable_Clear_m_1079828971_0 (Hashtable_t_2004451924_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.Hashtable::Contains(System.Object)
extern "C"  bool Hashtable_Contains_m1066475641_0 (Hashtable_t_2004451924_0 * __this, Object_t * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IDictionaryEnumerator System.Collections.Hashtable::GetEnumerator()
extern "C"  Object_t * Hashtable_GetEnumerator_m737865954_0 (Hashtable_t_2004451924_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::Remove(System.Object)
extern "C"  void Hashtable_Remove_m_1990246666_0 (Hashtable_t_2004451924_0 * __this, Object_t * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.Hashtable::ContainsKey(System.Object)
extern "C"  bool Hashtable_ContainsKey_m1913745934_0 (Hashtable_t_2004451924_0 * __this, Object_t * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Collections.Hashtable::Clone()
extern "C"  Object_t * Hashtable_Clone_m_732956720_0 (Hashtable_t_2004451924_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void Hashtable_GetObjectData_m_75162488_0 (Hashtable_t_2004451924_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::OnDeserialization(System.Object)
extern "C"  void Hashtable_OnDeserialization_m_1398105380_0 (Hashtable_t_2004451924_0 * __this, Object_t * ___sender, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.Hashtable System.Collections.Hashtable::Synchronized(System.Collections.Hashtable)
extern "C"  Hashtable_t_2004451924_0 * Hashtable_Synchronized_m_289120407_0 (Object_t * __this /* static, unused */, Hashtable_t_2004451924_0 * ___table, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.Hashtable::GetHash(System.Object)
extern "C"  int32_t Hashtable_GetHash_m527227236_0 (Hashtable_t_2004451924_0 * __this, Object_t * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.Hashtable::KeyEquals(System.Object,System.Object)
extern "C"  bool Hashtable_KeyEquals_m1149622430_0 (Hashtable_t_2004451924_0 * __this, Object_t * ___item, Object_t * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::AdjustThreshold()
extern "C"  void Hashtable_AdjustThreshold_m_2125066012_0 (Hashtable_t_2004451924_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::SetTable(System.Collections.Hashtable/Slot[],System.Int32[])
extern "C"  void Hashtable_SetTable_m463771856_0 (Hashtable_t_2004451924_0 * __this, SlotU5BU5D_t_50707517_0* ___table, Int32U5BU5D_t1872284309_0* ___hashes, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.Hashtable::Find(System.Object)
extern "C"  int32_t Hashtable_Find_m_851548603_0 (Hashtable_t_2004451924_0 * __this, Object_t * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::Rehash()
extern "C"  void Hashtable_Rehash_m_574188197_0 (Hashtable_t_2004451924_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::PutImpl(System.Object,System.Object,System.Boolean)
extern "C"  void Hashtable_PutImpl_m_845750158_0 (Hashtable_t_2004451924_0 * __this, Object_t * ___key, Object_t * ___value, bool ___overwrite, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.Hashtable::CopyToArray(System.Array,System.Int32,System.Collections.Hashtable/EnumeratorMode)
extern "C"  void Hashtable_CopyToArray_m_611056002_0 (Hashtable_t_2004451924_0 * __this, Array_t * ___arr, int32_t ___i, int32_t ___mode, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.Hashtable::TestPrime(System.Int32)
extern "C"  bool Hashtable_TestPrime_m2080981348_0 (Object_t * __this /* static, unused */, int32_t ___x, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.Hashtable::CalcPrime(System.Int32)
extern "C"  int32_t Hashtable_CalcPrime_m1477965287_0 (Object_t * __this /* static, unused */, int32_t ___x, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.Hashtable::ToPrime(System.Int32)
extern "C"  int32_t Hashtable_ToPrime_m840372929_0 (Object_t * __this /* static, unused */, int32_t ___x, const MethodInfo* method) IL2CPP_METHOD_ATTR;
