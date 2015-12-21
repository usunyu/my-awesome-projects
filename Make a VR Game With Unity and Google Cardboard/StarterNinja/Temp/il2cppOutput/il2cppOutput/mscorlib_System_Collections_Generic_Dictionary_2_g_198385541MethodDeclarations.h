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

// System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>
struct Dictionary_2_t_1201087663_0;
// System.Collections.Generic.IEqualityComparer`1<System.Int32>
struct IEqualityComparer_1_t_177649431_0;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;
// System.Object
struct Object_t;
// System.Collections.Generic.KeyValuePair`2<System.Int32,System.Int32>[]
struct KeyValuePair_2U5BU5D_t1674237287_0;
// System.Array
struct Array_t;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;
// System.Collections.Generic.IEnumerator`1<System.Collections.Generic.KeyValuePair`2<System.Int32,System.Int32>>
struct IEnumerator_1_t1676334036_0;
// System.Collections.IDictionaryEnumerator
struct IDictionaryEnumerator_t_855216337_0;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.Int32,System.Int32>
struct ValueCollection_t_1824475205_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"
#include "mscorlib_System_Collections_Generic_KeyValuePair__1987082427.h"
#include "mscorlib_System_Collections_Generic_Dictionary_2_E1395614990.h"
#include "mscorlib_System_Collections_DictionaryEntry_1842557272.h"

// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::.ctor()
extern "C"  void Dictionary_2__ctor_m2091315643_0_gshared (Dictionary_2_t_1201087663_0 * __this, const MethodInfo* method);
#define Dictionary_2__ctor_m2091315643_0(__this, method) ((  void (*) (Dictionary_2_t_1201087663_0 *, const MethodInfo*))Dictionary_2__ctor_m2091315643_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::.ctor(System.Collections.Generic.IEqualityComparer`1<TKey>)
extern "C"  void Dictionary_2__ctor_m_707579726_0_gshared (Dictionary_2_t_1201087663_0 * __this, Object_t* ___comparer, const MethodInfo* method);
#define Dictionary_2__ctor_m_707579726_0(__this, ___comparer, method) ((  void (*) (Dictionary_2_t_1201087663_0 *, Object_t*, const MethodInfo*))Dictionary_2__ctor_m_707579726_0_gshared)(__this, ___comparer, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::.ctor(System.Int32)
extern "C"  void Dictionary_2__ctor_m1560864396_0_gshared (Dictionary_2_t_1201087663_0 * __this, int32_t ___capacity, const MethodInfo* method);
#define Dictionary_2__ctor_m1560864396_0(__this, ___capacity, method) ((  void (*) (Dictionary_2_t_1201087663_0 *, int32_t, const MethodInfo*))Dictionary_2__ctor_m1560864396_0_gshared)(__this, ___capacity, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::.ctor(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void Dictionary_2__ctor_m1945093244_0_gshared (Dictionary_2_t_1201087663_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method);
#define Dictionary_2__ctor_m1945093244_0(__this, ___info, ___context, method) ((  void (*) (Dictionary_2_t_1201087663_0 *, SerializationInfo_t526833679_0 *, StreamingContext_t_1216992900_0 , const MethodInfo*))Dictionary_2__ctor_m1945093244_0_gshared)(__this, ___info, ___context, method)
// System.Object System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::System.Collections.IDictionary.get_Item(System.Object)
extern "C"  Object_t * Dictionary_2_System_Collections_IDictionary_get_Item_m422025389_0_gshared (Dictionary_2_t_1201087663_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_get_Item_m422025389_0(__this, ___key, method) ((  Object_t * (*) (Dictionary_2_t_1201087663_0 *, Object_t *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_get_Item_m422025389_0_gshared)(__this, ___key, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::System.Collections.IDictionary.set_Item(System.Object,System.Object)
extern "C"  void Dictionary_2_System_Collections_IDictionary_set_Item_m_1499852462_0_gshared (Dictionary_2_t_1201087663_0 * __this, Object_t * ___key, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_set_Item_m_1499852462_0(__this, ___key, ___value, method) ((  void (*) (Dictionary_2_t_1201087663_0 *, Object_t *, Object_t *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_set_Item_m_1499852462_0_gshared)(__this, ___key, ___value, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::System.Collections.IDictionary.Add(System.Object,System.Object)
extern "C"  void Dictionary_2_System_Collections_IDictionary_Add_m_587783745_0_gshared (Dictionary_2_t_1201087663_0 * __this, Object_t * ___key, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_Add_m_587783745_0(__this, ___key, ___value, method) ((  void (*) (Dictionary_2_t_1201087663_0 *, Object_t *, Object_t *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_Add_m_587783745_0_gshared)(__this, ___key, ___value, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::System.Collections.IDictionary.Contains(System.Object)
extern "C"  bool Dictionary_2_System_Collections_IDictionary_Contains_m_1052001065_0_gshared (Dictionary_2_t_1201087663_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_Contains_m_1052001065_0(__this, ___key, method) ((  bool (*) (Dictionary_2_t_1201087663_0 *, Object_t *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_Contains_m_1052001065_0_gshared)(__this, ___key, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::System.Collections.IDictionary.Remove(System.Object)
extern "C"  void Dictionary_2_System_Collections_IDictionary_Remove_m1869442960_0_gshared (Dictionary_2_t_1201087663_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_Remove_m1869442960_0(__this, ___key, method) ((  void (*) (Dictionary_2_t_1201087663_0 *, Object_t *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_Remove_m1869442960_0_gshared)(__this, ___key, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::System.Collections.ICollection.get_IsSynchronized()
extern "C"  bool Dictionary_2_System_Collections_ICollection_get_IsSynchronized_m_870843939_0_gshared (Dictionary_2_t_1201087663_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_ICollection_get_IsSynchronized_m_870843939_0(__this, method) ((  bool (*) (Dictionary_2_t_1201087663_0 *, const MethodInfo*))Dictionary_2_System_Collections_ICollection_get_IsSynchronized_m_870843939_0_gshared)(__this, method)
// System.Object System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::System.Collections.ICollection.get_SyncRoot()
extern "C"  Object_t * Dictionary_2_System_Collections_ICollection_get_SyncRoot_m_1226897335_0_gshared (Dictionary_2_t_1201087663_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_ICollection_get_SyncRoot_m_1226897335_0(__this, method) ((  Object_t * (*) (Dictionary_2_t_1201087663_0 *, const MethodInfo*))Dictionary_2_System_Collections_ICollection_get_SyncRoot_m_1226897335_0_gshared)(__this, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<TKey,TValue>>.get_IsReadOnly()
extern "C"  bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_get_IsReadOnly_m961836001_0_gshared (Dictionary_2_t_1201087663_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_get_IsReadOnly_m961836001_0(__this, method) ((  bool (*) (Dictionary_2_t_1201087663_0 *, const MethodInfo*))Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_get_IsReadOnly_m961836001_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<TKey,TValue>>.Add(System.Collections.Generic.KeyValuePair`2<TKey,TValue>)
extern "C"  void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Add_m1158681638_0_gshared (Dictionary_2_t_1201087663_0 * __this, KeyValuePair_2_t_1987082427_0  ___keyValuePair, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Add_m1158681638_0(__this, ___keyValuePair, method) ((  void (*) (Dictionary_2_t_1201087663_0 *, KeyValuePair_2_t_1987082427_0 , const MethodInfo*))Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Add_m1158681638_0_gshared)(__this, ___keyValuePair, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<TKey,TValue>>.Contains(System.Collections.Generic.KeyValuePair`2<TKey,TValue>)
extern "C"  bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Contains_m_317862308_0_gshared (Dictionary_2_t_1201087663_0 * __this, KeyValuePair_2_t_1987082427_0  ___keyValuePair, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Contains_m_317862308_0(__this, ___keyValuePair, method) ((  bool (*) (Dictionary_2_t_1201087663_0 *, KeyValuePair_2_t_1987082427_0 , const MethodInfo*))Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Contains_m_317862308_0_gshared)(__this, ___keyValuePair, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<TKey,TValue>>.CopyTo(System.Collections.Generic.KeyValuePair`2<TKey,TValue>[],System.Int32)
extern "C"  void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_CopyTo_m_988117366_0_gshared (Dictionary_2_t_1201087663_0 * __this, KeyValuePair_2U5BU5D_t1674237287_0* ___array, int32_t ___index, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_CopyTo_m_988117366_0(__this, ___array, ___index, method) ((  void (*) (Dictionary_2_t_1201087663_0 *, KeyValuePair_2U5BU5D_t1674237287_0*, int32_t, const MethodInfo*))Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_CopyTo_m_988117366_0_gshared)(__this, ___array, ___index, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<TKey,TValue>>.Remove(System.Collections.Generic.KeyValuePair`2<TKey,TValue>)
extern "C"  bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Remove_m859036801_0_gshared (Dictionary_2_t_1201087663_0 * __this, KeyValuePair_2_t_1987082427_0  ___keyValuePair, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Remove_m859036801_0(__this, ___keyValuePair, method) ((  bool (*) (Dictionary_2_t_1201087663_0 *, KeyValuePair_2_t_1987082427_0 , const MethodInfo*))Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Remove_m859036801_0_gshared)(__this, ___keyValuePair, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::System.Collections.ICollection.CopyTo(System.Array,System.Int32)
extern "C"  void Dictionary_2_System_Collections_ICollection_CopyTo_m_245682199_0_gshared (Dictionary_2_t_1201087663_0 * __this, Array_t * ___array, int32_t ___index, const MethodInfo* method);
#define Dictionary_2_System_Collections_ICollection_CopyTo_m_245682199_0(__this, ___array, ___index, method) ((  void (*) (Dictionary_2_t_1201087663_0 *, Array_t *, int32_t, const MethodInfo*))Dictionary_2_System_Collections_ICollection_CopyTo_m_245682199_0_gshared)(__this, ___array, ___index, method)
// System.Collections.IEnumerator System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::System.Collections.IEnumerable.GetEnumerator()
extern "C"  Object_t * Dictionary_2_System_Collections_IEnumerable_GetEnumerator_m1239622564_0_gshared (Dictionary_2_t_1201087663_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_IEnumerable_GetEnumerator_m1239622564_0(__this, method) ((  Object_t * (*) (Dictionary_2_t_1201087663_0 *, const MethodInfo*))Dictionary_2_System_Collections_IEnumerable_GetEnumerator_m1239622564_0_gshared)(__this, method)
// System.Collections.Generic.IEnumerator`1<System.Collections.Generic.KeyValuePair`2<TKey,TValue>> System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::System.Collections.Generic.IEnumerable<System.Collections.Generic.KeyValuePair<TKey,TValue>>.GetEnumerator()
extern "C"  Object_t* Dictionary_2_System_Collections_Generic_IEnumerableU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_GetEnumerator_m1602271841_0_gshared (Dictionary_2_t_1201087663_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_IEnumerableU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_GetEnumerator_m1602271841_0(__this, method) ((  Object_t* (*) (Dictionary_2_t_1201087663_0 *, const MethodInfo*))Dictionary_2_System_Collections_Generic_IEnumerableU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_GetEnumerator_m1602271841_0_gshared)(__this, method)
// System.Collections.IDictionaryEnumerator System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::System.Collections.IDictionary.GetEnumerator()
extern "C"  Object_t * Dictionary_2_System_Collections_IDictionary_GetEnumerator_m_1819168324_0_gshared (Dictionary_2_t_1201087663_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_GetEnumerator_m_1819168324_0(__this, method) ((  Object_t * (*) (Dictionary_2_t_1201087663_0 *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_GetEnumerator_m_1819168324_0_gshared)(__this, method)
// System.Int32 System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::get_Count()
extern "C"  int32_t Dictionary_2_get_Count_m_1975882589_0_gshared (Dictionary_2_t_1201087663_0 * __this, const MethodInfo* method);
#define Dictionary_2_get_Count_m_1975882589_0(__this, method) ((  int32_t (*) (Dictionary_2_t_1201087663_0 *, const MethodInfo*))Dictionary_2_get_Count_m_1975882589_0_gshared)(__this, method)
// TValue System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::get_Item(TKey)
extern "C"  int32_t Dictionary_2_get_Item_m_1377366680_0_gshared (Dictionary_2_t_1201087663_0 * __this, int32_t ___key, const MethodInfo* method);
#define Dictionary_2_get_Item_m_1377366680_0(__this, ___key, method) ((  int32_t (*) (Dictionary_2_t_1201087663_0 *, int32_t, const MethodInfo*))Dictionary_2_get_Item_m_1377366680_0_gshared)(__this, ___key, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::set_Item(TKey,TValue)
extern "C"  void Dictionary_2_set_Item_m1952973883_0_gshared (Dictionary_2_t_1201087663_0 * __this, int32_t ___key, int32_t ___value, const MethodInfo* method);
#define Dictionary_2_set_Item_m1952973883_0(__this, ___key, ___value, method) ((  void (*) (Dictionary_2_t_1201087663_0 *, int32_t, int32_t, const MethodInfo*))Dictionary_2_set_Item_m1952973883_0_gshared)(__this, ___key, ___value, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::Init(System.Int32,System.Collections.Generic.IEqualityComparer`1<TKey>)
extern "C"  void Dictionary_2_Init_m_1146064589_0_gshared (Dictionary_2_t_1201087663_0 * __this, int32_t ___capacity, Object_t* ___hcp, const MethodInfo* method);
#define Dictionary_2_Init_m_1146064589_0(__this, ___capacity, ___hcp, method) ((  void (*) (Dictionary_2_t_1201087663_0 *, int32_t, Object_t*, const MethodInfo*))Dictionary_2_Init_m_1146064589_0_gshared)(__this, ___capacity, ___hcp, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::InitArrays(System.Int32)
extern "C"  void Dictionary_2_InitArrays_m386103012_0_gshared (Dictionary_2_t_1201087663_0 * __this, int32_t ___size, const MethodInfo* method);
#define Dictionary_2_InitArrays_m386103012_0(__this, ___size, method) ((  void (*) (Dictionary_2_t_1201087663_0 *, int32_t, const MethodInfo*))Dictionary_2_InitArrays_m386103012_0_gshared)(__this, ___size, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::CopyToCheck(System.Array,System.Int32)
extern "C"  void Dictionary_2_CopyToCheck_m195720160_0_gshared (Dictionary_2_t_1201087663_0 * __this, Array_t * ___array, int32_t ___index, const MethodInfo* method);
#define Dictionary_2_CopyToCheck_m195720160_0(__this, ___array, ___index, method) ((  void (*) (Dictionary_2_t_1201087663_0 *, Array_t *, int32_t, const MethodInfo*))Dictionary_2_CopyToCheck_m195720160_0_gshared)(__this, ___array, ___index, method)
// System.Collections.Generic.KeyValuePair`2<TKey,TValue> System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::make_pair(TKey,TValue)
extern "C"  KeyValuePair_2_t_1987082427_0  Dictionary_2_make_pair_m_1211254228_0_gshared (Object_t * __this /* static, unused */, int32_t ___key, int32_t ___value, const MethodInfo* method);
#define Dictionary_2_make_pair_m_1211254228_0(__this /* static, unused */, ___key, ___value, method) ((  KeyValuePair_2_t_1987082427_0  (*) (Object_t * /* static, unused */, int32_t, int32_t, const MethodInfo*))Dictionary_2_make_pair_m_1211254228_0_gshared)(__this /* static, unused */, ___key, ___value, method)
// TValue System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::pick_value(TKey,TValue)
extern "C"  int32_t Dictionary_2_pick_value_m375615498_0_gshared (Object_t * __this /* static, unused */, int32_t ___key, int32_t ___value, const MethodInfo* method);
#define Dictionary_2_pick_value_m375615498_0(__this /* static, unused */, ___key, ___value, method) ((  int32_t (*) (Object_t * /* static, unused */, int32_t, int32_t, const MethodInfo*))Dictionary_2_pick_value_m375615498_0_gshared)(__this /* static, unused */, ___key, ___value, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::CopyTo(System.Collections.Generic.KeyValuePair`2<TKey,TValue>[],System.Int32)
extern "C"  void Dictionary_2_CopyTo_m810992623_0_gshared (Dictionary_2_t_1201087663_0 * __this, KeyValuePair_2U5BU5D_t1674237287_0* ___array, int32_t ___index, const MethodInfo* method);
#define Dictionary_2_CopyTo_m810992623_0(__this, ___array, ___index, method) ((  void (*) (Dictionary_2_t_1201087663_0 *, KeyValuePair_2U5BU5D_t1674237287_0*, int32_t, const MethodInfo*))Dictionary_2_CopyTo_m810992623_0_gshared)(__this, ___array, ___index, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::Resize()
extern "C"  void Dictionary_2_Resize_m464072157_0_gshared (Dictionary_2_t_1201087663_0 * __this, const MethodInfo* method);
#define Dictionary_2_Resize_m464072157_0(__this, method) ((  void (*) (Dictionary_2_t_1201087663_0 *, const MethodInfo*))Dictionary_2_Resize_m464072157_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::Add(TKey,TValue)
extern "C"  void Dictionary_2_Add_m1598358874_0_gshared (Dictionary_2_t_1201087663_0 * __this, int32_t ___key, int32_t ___value, const MethodInfo* method);
#define Dictionary_2_Add_m1598358874_0(__this, ___key, ___value, method) ((  void (*) (Dictionary_2_t_1201087663_0 *, int32_t, int32_t, const MethodInfo*))Dictionary_2_Add_m1598358874_0_gshared)(__this, ___key, ___value, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::Clear()
extern "C"  void Dictionary_2_Clear_m_502551066_0_gshared (Dictionary_2_t_1201087663_0 * __this, const MethodInfo* method);
#define Dictionary_2_Clear_m_502551066_0(__this, method) ((  void (*) (Dictionary_2_t_1201087663_0 *, const MethodInfo*))Dictionary_2_Clear_m_502551066_0_gshared)(__this, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::ContainsKey(TKey)
extern "C"  bool Dictionary_2_ContainsKey_m747492044_0_gshared (Dictionary_2_t_1201087663_0 * __this, int32_t ___key, const MethodInfo* method);
#define Dictionary_2_ContainsKey_m747492044_0(__this, ___key, method) ((  bool (*) (Dictionary_2_t_1201087663_0 *, int32_t, const MethodInfo*))Dictionary_2_ContainsKey_m747492044_0_gshared)(__this, ___key, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::ContainsValue(TValue)
extern "C"  bool Dictionary_2_ContainsValue_m_1393893172_0_gshared (Dictionary_2_t_1201087663_0 * __this, int32_t ___value, const MethodInfo* method);
#define Dictionary_2_ContainsValue_m_1393893172_0(__this, ___value, method) ((  bool (*) (Dictionary_2_t_1201087663_0 *, int32_t, const MethodInfo*))Dictionary_2_ContainsValue_m_1393893172_0_gshared)(__this, ___value, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void Dictionary_2_GetObjectData_m_883765287_0_gshared (Dictionary_2_t_1201087663_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method);
#define Dictionary_2_GetObjectData_m_883765287_0(__this, ___info, ___context, method) ((  void (*) (Dictionary_2_t_1201087663_0 *, SerializationInfo_t526833679_0 *, StreamingContext_t_1216992900_0 , const MethodInfo*))Dictionary_2_GetObjectData_m_883765287_0_gshared)(__this, ___info, ___context, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::OnDeserialization(System.Object)
extern "C"  void Dictionary_2_OnDeserialization_m1998440491_0_gshared (Dictionary_2_t_1201087663_0 * __this, Object_t * ___sender, const MethodInfo* method);
#define Dictionary_2_OnDeserialization_m1998440491_0(__this, ___sender, method) ((  void (*) (Dictionary_2_t_1201087663_0 *, Object_t *, const MethodInfo*))Dictionary_2_OnDeserialization_m1998440491_0_gshared)(__this, ___sender, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::Remove(TKey)
extern "C"  bool Dictionary_2_Remove_m575985316_0_gshared (Dictionary_2_t_1201087663_0 * __this, int32_t ___key, const MethodInfo* method);
#define Dictionary_2_Remove_m575985316_0(__this, ___key, method) ((  bool (*) (Dictionary_2_t_1201087663_0 *, int32_t, const MethodInfo*))Dictionary_2_Remove_m575985316_0_gshared)(__this, ___key, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::TryGetValue(TKey,TValue&)
extern "C"  bool Dictionary_2_TryGetValue_m_1464819931_0_gshared (Dictionary_2_t_1201087663_0 * __this, int32_t ___key, int32_t* ___value, const MethodInfo* method);
#define Dictionary_2_TryGetValue_m_1464819931_0(__this, ___key, ___value, method) ((  bool (*) (Dictionary_2_t_1201087663_0 *, int32_t, int32_t*, const MethodInfo*))Dictionary_2_TryGetValue_m_1464819931_0_gshared)(__this, ___key, ___value, method)
// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::get_Values()
extern "C"  ValueCollection_t_1824475205_0 * Dictionary_2_get_Values_m46175482_0_gshared (Dictionary_2_t_1201087663_0 * __this, const MethodInfo* method);
#define Dictionary_2_get_Values_m46175482_0(__this, method) ((  ValueCollection_t_1824475205_0 * (*) (Dictionary_2_t_1201087663_0 *, const MethodInfo*))Dictionary_2_get_Values_m46175482_0_gshared)(__this, method)
// TKey System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::ToTKey(System.Object)
extern "C"  int32_t Dictionary_2_ToTKey_m170528421_0_gshared (Dictionary_2_t_1201087663_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_ToTKey_m170528421_0(__this, ___key, method) ((  int32_t (*) (Dictionary_2_t_1201087663_0 *, Object_t *, const MethodInfo*))Dictionary_2_ToTKey_m170528421_0_gshared)(__this, ___key, method)
// TValue System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::ToTValue(System.Object)
extern "C"  int32_t Dictionary_2_ToTValue_m_1312070363_0_gshared (Dictionary_2_t_1201087663_0 * __this, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_ToTValue_m_1312070363_0(__this, ___value, method) ((  int32_t (*) (Dictionary_2_t_1201087663_0 *, Object_t *, const MethodInfo*))Dictionary_2_ToTValue_m_1312070363_0_gshared)(__this, ___value, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::ContainsKeyValuePair(System.Collections.Generic.KeyValuePair`2<TKey,TValue>)
extern "C"  bool Dictionary_2_ContainsKeyValuePair_m_1586568057_0_gshared (Dictionary_2_t_1201087663_0 * __this, KeyValuePair_2_t_1987082427_0  ___pair, const MethodInfo* method);
#define Dictionary_2_ContainsKeyValuePair_m_1586568057_0(__this, ___pair, method) ((  bool (*) (Dictionary_2_t_1201087663_0 *, KeyValuePair_2_t_1987082427_0 , const MethodInfo*))Dictionary_2_ContainsKeyValuePair_m_1586568057_0_gshared)(__this, ___pair, method)
// System.Collections.Generic.Dictionary`2/Enumerator<TKey,TValue> System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::GetEnumerator()
extern "C"  Enumerator_t1395614990_0  Dictionary_2_GetEnumerator_m1357252096_0_gshared (Dictionary_2_t_1201087663_0 * __this, const MethodInfo* method);
#define Dictionary_2_GetEnumerator_m1357252096_0(__this, method) ((  Enumerator_t1395614990_0  (*) (Dictionary_2_t_1201087663_0 *, const MethodInfo*))Dictionary_2_GetEnumerator_m1357252096_0_gshared)(__this, method)
// System.Collections.DictionaryEntry System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>::<CopyTo>m__0(TKey,TValue)
extern "C"  DictionaryEntry_t_1842557272_0  Dictionary_2_U3CCopyToU3Em__0_m438114639_0_gshared (Object_t * __this /* static, unused */, int32_t ___key, int32_t ___value, const MethodInfo* method);
#define Dictionary_2_U3CCopyToU3Em__0_m438114639_0(__this /* static, unused */, ___key, ___value, method) ((  DictionaryEntry_t_1842557272_0  (*) (Object_t * /* static, unused */, int32_t, int32_t, const MethodInfo*))Dictionary_2_U3CCopyToU3Em__0_m438114639_0_gshared)(__this /* static, unused */, ___key, ___value, method)
