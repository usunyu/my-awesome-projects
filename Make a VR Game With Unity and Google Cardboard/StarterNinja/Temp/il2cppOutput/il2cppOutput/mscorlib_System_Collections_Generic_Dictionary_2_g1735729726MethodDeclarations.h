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

// System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>
struct Dictionary_2_t1735729726_0;
// System.Collections.Generic.IEqualityComparer`1<System.Object>
struct IEqualityComparer_1_t_533356922_0;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;
// System.Object
struct Object_t;
// System.Collections.Generic.KeyValuePair`2<System.Object,System.Boolean>[]
struct KeyValuePair_2U5BU5D_t1941806486_0;
// System.Array
struct Array_t;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;
// System.Collections.Generic.IEnumerator`1<System.Collections.Generic.KeyValuePair`2<System.Object,System.Boolean>>
struct IEnumerator_1_t_1447987345_0;
// System.Collections.IDictionaryEnumerator
struct IDictionaryEnumerator_t_855216337_0;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.Object,System.Boolean>
struct ValueCollection_t1834681086_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"
#include "mscorlib_System_Collections_Generic_KeyValuePair__1968926924.h"
#include "mscorlib_System_Collections_Generic_Dictionary_2_E_847843125.h"
#include "mscorlib_System_Collections_DictionaryEntry_1842557272.h"

// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::.ctor()
extern "C"  void Dictionary_2__ctor_m_2102626350_0_gshared (Dictionary_2_t1735729726_0 * __this, const MethodInfo* method);
#define Dictionary_2__ctor_m_2102626350_0(__this, method) ((  void (*) (Dictionary_2_t1735729726_0 *, const MethodInfo*))Dictionary_2__ctor_m_2102626350_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::.ctor(System.Collections.Generic.IEqualityComparer`1<TKey>)
extern "C"  void Dictionary_2__ctor_m_1131959991_0_gshared (Dictionary_2_t1735729726_0 * __this, Object_t* ___comparer, const MethodInfo* method);
#define Dictionary_2__ctor_m_1131959991_0(__this, ___comparer, method) ((  void (*) (Dictionary_2_t1735729726_0 *, Object_t*, const MethodInfo*))Dictionary_2__ctor_m_1131959991_0_gshared)(__this, ___comparer, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::.ctor(System.Int32)
extern "C"  void Dictionary_2__ctor_m_2034564573_0_gshared (Dictionary_2_t1735729726_0 * __this, int32_t ___capacity, const MethodInfo* method);
#define Dictionary_2__ctor_m_2034564573_0(__this, ___capacity, method) ((  void (*) (Dictionary_2_t1735729726_0 *, int32_t, const MethodInfo*))Dictionary_2__ctor_m_2034564573_0_gshared)(__this, ___capacity, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::.ctor(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void Dictionary_2__ctor_m_1656382957_0_gshared (Dictionary_2_t1735729726_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method);
#define Dictionary_2__ctor_m_1656382957_0(__this, ___info, ___context, method) ((  void (*) (Dictionary_2_t1735729726_0 *, SerializationInfo_t526833679_0 *, StreamingContext_t_1216992900_0 , const MethodInfo*))Dictionary_2__ctor_m_1656382957_0_gshared)(__this, ___info, ___context, method)
// System.Object System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::System.Collections.IDictionary.get_Item(System.Object)
extern "C"  Object_t * Dictionary_2_System_Collections_IDictionary_get_Item_m1767874860_0_gshared (Dictionary_2_t1735729726_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_get_Item_m1767874860_0(__this, ___key, method) ((  Object_t * (*) (Dictionary_2_t1735729726_0 *, Object_t *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_get_Item_m1767874860_0_gshared)(__this, ___key, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::System.Collections.IDictionary.set_Item(System.Object,System.Object)
extern "C"  void Dictionary_2_System_Collections_IDictionary_set_Item_m_1900129637_0_gshared (Dictionary_2_t1735729726_0 * __this, Object_t * ___key, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_set_Item_m_1900129637_0(__this, ___key, ___value, method) ((  void (*) (Dictionary_2_t1735729726_0 *, Object_t *, Object_t *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_set_Item_m_1900129637_0_gshared)(__this, ___key, ___value, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::System.Collections.IDictionary.Add(System.Object,System.Object)
extern "C"  void Dictionary_2_System_Collections_IDictionary_Add_m_318802218_0_gshared (Dictionary_2_t1735729726_0 * __this, Object_t * ___key, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_Add_m_318802218_0(__this, ___key, ___value, method) ((  void (*) (Dictionary_2_t1735729726_0 *, Object_t *, Object_t *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_Add_m_318802218_0_gshared)(__this, ___key, ___value, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::System.Collections.IDictionary.Contains(System.Object)
extern "C"  bool Dictionary_2_System_Collections_IDictionary_Contains_m_1925985892_0_gshared (Dictionary_2_t1735729726_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_Contains_m_1925985892_0(__this, ___key, method) ((  bool (*) (Dictionary_2_t1735729726_0 *, Object_t *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_Contains_m_1925985892_0_gshared)(__this, ___key, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::System.Collections.IDictionary.Remove(System.Object)
extern "C"  void Dictionary_2_System_Collections_IDictionary_Remove_m728195801_0_gshared (Dictionary_2_t1735729726_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_Remove_m728195801_0(__this, ___key, method) ((  void (*) (Dictionary_2_t1735729726_0 *, Object_t *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_Remove_m728195801_0_gshared)(__this, ___key, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::System.Collections.ICollection.get_IsSynchronized()
extern "C"  bool Dictionary_2_System_Collections_ICollection_get_IsSynchronized_m1030728504_0_gshared (Dictionary_2_t1735729726_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_ICollection_get_IsSynchronized_m1030728504_0(__this, method) ((  bool (*) (Dictionary_2_t1735729726_0 *, const MethodInfo*))Dictionary_2_System_Collections_ICollection_get_IsSynchronized_m1030728504_0_gshared)(__this, method)
// System.Object System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::System.Collections.ICollection.get_SyncRoot()
extern "C"  Object_t * Dictionary_2_System_Collections_ICollection_get_SyncRoot_m_106519318_0_gshared (Dictionary_2_t1735729726_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_ICollection_get_SyncRoot_m_106519318_0(__this, method) ((  Object_t * (*) (Dictionary_2_t1735729726_0 *, const MethodInfo*))Dictionary_2_System_Collections_ICollection_get_SyncRoot_m_106519318_0_gshared)(__this, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<TKey,TValue>>.get_IsReadOnly()
extern "C"  bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_get_IsReadOnly_m_1558401668_0_gshared (Dictionary_2_t1735729726_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_get_IsReadOnly_m_1558401668_0(__this, method) ((  bool (*) (Dictionary_2_t1735729726_0 *, const MethodInfo*))Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_get_IsReadOnly_m_1558401668_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<TKey,TValue>>.Add(System.Collections.Generic.KeyValuePair`2<TKey,TValue>)
extern "C"  void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Add_m225251055_0_gshared (Dictionary_2_t1735729726_0 * __this, KeyValuePair_2_t_1968926924_0  ___keyValuePair, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Add_m225251055_0(__this, ___keyValuePair, method) ((  void (*) (Dictionary_2_t1735729726_0 *, KeyValuePair_2_t_1968926924_0 , const MethodInfo*))Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Add_m225251055_0_gshared)(__this, ___keyValuePair, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<TKey,TValue>>.Contains(System.Collections.Generic.KeyValuePair`2<TKey,TValue>)
extern "C"  bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Contains_m40912375_0_gshared (Dictionary_2_t1735729726_0 * __this, KeyValuePair_2_t_1968926924_0  ___keyValuePair, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Contains_m40912375_0(__this, ___keyValuePair, method) ((  bool (*) (Dictionary_2_t1735729726_0 *, KeyValuePair_2_t_1968926924_0 , const MethodInfo*))Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Contains_m40912375_0_gshared)(__this, ___keyValuePair, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<TKey,TValue>>.CopyTo(System.Collections.Generic.KeyValuePair`2<TKey,TValue>[],System.Int32)
extern "C"  void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_CopyTo_m_1934376685_0_gshared (Dictionary_2_t1735729726_0 * __this, KeyValuePair_2U5BU5D_t1941806486_0* ___array, int32_t ___index, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_CopyTo_m_1934376685_0(__this, ___array, ___index, method) ((  void (*) (Dictionary_2_t1735729726_0 *, KeyValuePair_2U5BU5D_t1941806486_0*, int32_t, const MethodInfo*))Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_CopyTo_m_1934376685_0_gshared)(__this, ___array, ___index, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<TKey,TValue>>.Remove(System.Collections.Generic.KeyValuePair`2<TKey,TValue>)
extern "C"  bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Remove_m309690076_0_gshared (Dictionary_2_t1735729726_0 * __this, KeyValuePair_2_t_1968926924_0  ___keyValuePair, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Remove_m309690076_0(__this, ___keyValuePair, method) ((  bool (*) (Dictionary_2_t1735729726_0 *, KeyValuePair_2_t_1968926924_0 , const MethodInfo*))Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Remove_m309690076_0_gshared)(__this, ___keyValuePair, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::System.Collections.ICollection.CopyTo(System.Array,System.Int32)
extern "C"  void Dictionary_2_System_Collections_ICollection_CopyTo_m_497189454_0_gshared (Dictionary_2_t1735729726_0 * __this, Array_t * ___array, int32_t ___index, const MethodInfo* method);
#define Dictionary_2_System_Collections_ICollection_CopyTo_m_497189454_0(__this, ___array, ___index, method) ((  void (*) (Dictionary_2_t1735729726_0 *, Array_t *, int32_t, const MethodInfo*))Dictionary_2_System_Collections_ICollection_CopyTo_m_497189454_0_gshared)(__this, ___array, ___index, method)
// System.Collections.IEnumerator System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::System.Collections.IEnumerable.GetEnumerator()
extern "C"  Object_t * Dictionary_2_System_Collections_IEnumerable_GetEnumerator_m_659495999_0_gshared (Dictionary_2_t1735729726_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_IEnumerable_GetEnumerator_m_659495999_0(__this, method) ((  Object_t * (*) (Dictionary_2_t1735729726_0 *, const MethodInfo*))Dictionary_2_System_Collections_IEnumerable_GetEnumerator_m_659495999_0_gshared)(__this, method)
// System.Collections.Generic.IEnumerator`1<System.Collections.Generic.KeyValuePair`2<TKey,TValue>> System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::System.Collections.Generic.IEnumerable<System.Collections.Generic.KeyValuePair<TKey,TValue>>.GetEnumerator()
extern "C"  Object_t* Dictionary_2_System_Collections_Generic_IEnumerableU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_GetEnumerator_m2013500536_0_gshared (Dictionary_2_t1735729726_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_IEnumerableU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_GetEnumerator_m2013500536_0(__this, method) ((  Object_t* (*) (Dictionary_2_t1735729726_0 *, const MethodInfo*))Dictionary_2_System_Collections_Generic_IEnumerableU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_GetEnumerator_m2013500536_0_gshared)(__this, method)
// System.Collections.IDictionaryEnumerator System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::System.Collections.IDictionary.GetEnumerator()
extern "C"  Object_t * Dictionary_2_System_Collections_IDictionary_GetEnumerator_m_318121211_0_gshared (Dictionary_2_t1735729726_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_GetEnumerator_m_318121211_0(__this, method) ((  Object_t * (*) (Dictionary_2_t1735729726_0 *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_GetEnumerator_m_318121211_0_gshared)(__this, method)
// System.Int32 System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::get_Count()
extern "C"  int32_t Dictionary_2_get_Count_m_1865190414_0_gshared (Dictionary_2_t1735729726_0 * __this, const MethodInfo* method);
#define Dictionary_2_get_Count_m_1865190414_0(__this, method) ((  int32_t (*) (Dictionary_2_t1735729726_0 *, const MethodInfo*))Dictionary_2_get_Count_m_1865190414_0_gshared)(__this, method)
// TValue System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::get_Item(TKey)
extern "C"  bool Dictionary_2_get_Item_m_446527275_0_gshared (Dictionary_2_t1735729726_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_get_Item_m_446527275_0(__this, ___key, method) ((  bool (*) (Dictionary_2_t1735729726_0 *, Object_t *, const MethodInfo*))Dictionary_2_get_Item_m_446527275_0_gshared)(__this, ___key, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::set_Item(TKey,TValue)
extern "C"  void Dictionary_2_set_Item_m_100559342_0_gshared (Dictionary_2_t1735729726_0 * __this, Object_t * ___key, bool ___value, const MethodInfo* method);
#define Dictionary_2_set_Item_m_100559342_0(__this, ___key, ___value, method) ((  void (*) (Dictionary_2_t1735729726_0 *, Object_t *, bool, const MethodInfo*))Dictionary_2_set_Item_m_100559342_0_gshared)(__this, ___key, ___value, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::Init(System.Int32,System.Collections.Generic.IEqualityComparer`1<TKey>)
extern "C"  void Dictionary_2_Init_m1320795978_0_gshared (Dictionary_2_t1735729726_0 * __this, int32_t ___capacity, Object_t* ___hcp, const MethodInfo* method);
#define Dictionary_2_Init_m1320795978_0(__this, ___capacity, ___hcp, method) ((  void (*) (Dictionary_2_t1735729726_0 *, int32_t, Object_t*, const MethodInfo*))Dictionary_2_Init_m1320795978_0_gshared)(__this, ___capacity, ___hcp, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::InitArrays(System.Int32)
extern "C"  void Dictionary_2_InitArrays_m1091961261_0_gshared (Dictionary_2_t1735729726_0 * __this, int32_t ___size, const MethodInfo* method);
#define Dictionary_2_InitArrays_m1091961261_0(__this, ___size, method) ((  void (*) (Dictionary_2_t1735729726_0 *, int32_t, const MethodInfo*))Dictionary_2_InitArrays_m1091961261_0_gshared)(__this, ___size, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::CopyToCheck(System.Array,System.Int32)
extern "C"  void Dictionary_2_CopyToCheck_m46787305_0_gshared (Dictionary_2_t1735729726_0 * __this, Array_t * ___array, int32_t ___index, const MethodInfo* method);
#define Dictionary_2_CopyToCheck_m46787305_0(__this, ___array, ___index, method) ((  void (*) (Dictionary_2_t1735729726_0 *, Array_t *, int32_t, const MethodInfo*))Dictionary_2_CopyToCheck_m46787305_0_gshared)(__this, ___array, ___index, method)
// System.Collections.Generic.KeyValuePair`2<TKey,TValue> System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::make_pair(TKey,TValue)
extern "C"  KeyValuePair_2_t_1968926924_0  Dictionary_2_make_pair_m1491903613_0_gshared (Object_t * __this /* static, unused */, Object_t * ___key, bool ___value, const MethodInfo* method);
#define Dictionary_2_make_pair_m1491903613_0(__this /* static, unused */, ___key, ___value, method) ((  KeyValuePair_2_t_1968926924_0  (*) (Object_t * /* static, unused */, Object_t *, bool, const MethodInfo*))Dictionary_2_make_pair_m1491903613_0_gshared)(__this /* static, unused */, ___key, ___value, method)
// TValue System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::pick_value(TKey,TValue)
extern "C"  bool Dictionary_2_pick_value_m1709670205_0_gshared (Object_t * __this /* static, unused */, Object_t * ___key, bool ___value, const MethodInfo* method);
#define Dictionary_2_pick_value_m1709670205_0(__this /* static, unused */, ___key, ___value, method) ((  bool (*) (Object_t * /* static, unused */, Object_t *, bool, const MethodInfo*))Dictionary_2_pick_value_m1709670205_0_gshared)(__this /* static, unused */, ___key, ___value, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::CopyTo(System.Collections.Generic.KeyValuePair`2<TKey,TValue>[],System.Int32)
extern "C"  void Dictionary_2_CopyTo_m2136794310_0_gshared (Dictionary_2_t1735729726_0 * __this, KeyValuePair_2U5BU5D_t1941806486_0* ___array, int32_t ___index, const MethodInfo* method);
#define Dictionary_2_CopyTo_m2136794310_0(__this, ___array, ___index, method) ((  void (*) (Dictionary_2_t1735729726_0 *, KeyValuePair_2U5BU5D_t1941806486_0*, int32_t, const MethodInfo*))Dictionary_2_CopyTo_m2136794310_0_gshared)(__this, ___array, ___index, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::Resize()
extern "C"  void Dictionary_2_Resize_m_699110746_0_gshared (Dictionary_2_t1735729726_0 * __this, const MethodInfo* method);
#define Dictionary_2_Resize_m_699110746_0(__this, method) ((  void (*) (Dictionary_2_t1735729726_0 *, const MethodInfo*))Dictionary_2_Resize_m_699110746_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::Add(TKey,TValue)
extern "C"  void Dictionary_2_Add_m_1297127133_0_gshared (Dictionary_2_t1735729726_0 * __this, Object_t * ___key, bool ___value, const MethodInfo* method);
#define Dictionary_2_Add_m_1297127133_0(__this, ___key, ___value, method) ((  void (*) (Dictionary_2_t1735729726_0 *, Object_t *, bool, const MethodInfo*))Dictionary_2_Add_m_1297127133_0_gshared)(__this, ___key, ___value, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::Clear()
extern "C"  void Dictionary_2_Clear_m_401525763_0_gshared (Dictionary_2_t1735729726_0 * __this, const MethodInfo* method);
#define Dictionary_2_Clear_m_401525763_0(__this, method) ((  void (*) (Dictionary_2_t1735729726_0 *, const MethodInfo*))Dictionary_2_Clear_m_401525763_0_gshared)(__this, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::ContainsKey(TKey)
extern "C"  bool Dictionary_2_ContainsKey_m_1587066137_0_gshared (Dictionary_2_t1735729726_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_ContainsKey_m_1587066137_0(__this, ___key, method) ((  bool (*) (Dictionary_2_t1735729726_0 *, Object_t *, const MethodInfo*))Dictionary_2_ContainsKey_m_1587066137_0_gshared)(__this, ___key, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::ContainsValue(TValue)
extern "C"  bool Dictionary_2_ContainsValue_m_1446718617_0_gshared (Dictionary_2_t1735729726_0 * __this, bool ___value, const MethodInfo* method);
#define Dictionary_2_ContainsValue_m_1446718617_0(__this, ___value, method) ((  bool (*) (Dictionary_2_t1735729726_0 *, bool, const MethodInfo*))Dictionary_2_ContainsValue_m_1446718617_0_gshared)(__this, ___value, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void Dictionary_2_GetObjectData_m878780016_0_gshared (Dictionary_2_t1735729726_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method);
#define Dictionary_2_GetObjectData_m878780016_0(__this, ___info, ___context, method) ((  void (*) (Dictionary_2_t1735729726_0 *, SerializationInfo_t526833679_0 *, StreamingContext_t_1216992900_0 , const MethodInfo*))Dictionary_2_GetObjectData_m878780016_0_gshared)(__this, ___info, ___context, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::OnDeserialization(System.Object)
extern "C"  void Dictionary_2_OnDeserialization_m_1128171020_0_gshared (Dictionary_2_t1735729726_0 * __this, Object_t * ___sender, const MethodInfo* method);
#define Dictionary_2_OnDeserialization_m_1128171020_0(__this, ___sender, method) ((  void (*) (Dictionary_2_t1735729726_0 *, Object_t *, const MethodInfo*))Dictionary_2_OnDeserialization_m_1128171020_0_gshared)(__this, ___sender, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::Remove(TKey)
extern "C"  bool Dictionary_2_Remove_m1836153257_0_gshared (Dictionary_2_t1735729726_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_Remove_m1836153257_0(__this, ___key, method) ((  bool (*) (Dictionary_2_t1735729726_0 *, Object_t *, const MethodInfo*))Dictionary_2_Remove_m1836153257_0_gshared)(__this, ___key, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::TryGetValue(TKey,TValue&)
extern "C"  bool Dictionary_2_TryGetValue_m_339096512_0_gshared (Dictionary_2_t1735729726_0 * __this, Object_t * ___key, bool* ___value, const MethodInfo* method);
#define Dictionary_2_TryGetValue_m_339096512_0(__this, ___key, ___value, method) ((  bool (*) (Dictionary_2_t1735729726_0 *, Object_t *, bool*, const MethodInfo*))Dictionary_2_TryGetValue_m_339096512_0_gshared)(__this, ___key, ___value, method)
// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::get_Values()
extern "C"  ValueCollection_t1834681086_0 * Dictionary_2_get_Values_m73313463_0_gshared (Dictionary_2_t1735729726_0 * __this, const MethodInfo* method);
#define Dictionary_2_get_Values_m73313463_0(__this, method) ((  ValueCollection_t1834681086_0 * (*) (Dictionary_2_t1735729726_0 *, const MethodInfo*))Dictionary_2_get_Values_m73313463_0_gshared)(__this, method)
// TKey System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::ToTKey(System.Object)
extern "C"  Object_t * Dictionary_2_ToTKey_m_1866262276_0_gshared (Dictionary_2_t1735729726_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_ToTKey_m_1866262276_0(__this, ___key, method) ((  Object_t * (*) (Dictionary_2_t1735729726_0 *, Object_t *, const MethodInfo*))Dictionary_2_ToTKey_m_1866262276_0_gshared)(__this, ___key, method)
// TValue System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::ToTValue(System.Object)
extern "C"  bool Dictionary_2_ToTValue_m21984344_0_gshared (Dictionary_2_t1735729726_0 * __this, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_ToTValue_m21984344_0(__this, ___value, method) ((  bool (*) (Dictionary_2_t1735729726_0 *, Object_t *, const MethodInfo*))Dictionary_2_ToTValue_m21984344_0_gshared)(__this, ___value, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::ContainsKeyValuePair(System.Collections.Generic.KeyValuePair`2<TKey,TValue>)
extern "C"  bool Dictionary_2_ContainsKeyValuePair_m2058411916_0_gshared (Dictionary_2_t1735729726_0 * __this, KeyValuePair_2_t_1968926924_0  ___pair, const MethodInfo* method);
#define Dictionary_2_ContainsKeyValuePair_m2058411916_0(__this, ___pair, method) ((  bool (*) (Dictionary_2_t1735729726_0 *, KeyValuePair_2_t_1968926924_0 , const MethodInfo*))Dictionary_2_ContainsKeyValuePair_m2058411916_0_gshared)(__this, ___pair, method)
// System.Collections.Generic.Dictionary`2/Enumerator<TKey,TValue> System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::GetEnumerator()
extern "C"  Enumerator_t_847843125_0  Dictionary_2_GetEnumerator_m_547150307_0_gshared (Dictionary_2_t1735729726_0 * __this, const MethodInfo* method);
#define Dictionary_2_GetEnumerator_m_547150307_0(__this, method) ((  Enumerator_t_847843125_0  (*) (Dictionary_2_t1735729726_0 *, const MethodInfo*))Dictionary_2_GetEnumerator_m_547150307_0_gshared)(__this, method)
// System.Collections.DictionaryEntry System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>::<CopyTo>m__0(TKey,TValue)
extern "C"  DictionaryEntry_t_1842557272_0  Dictionary_2_U3CCopyToU3Em__0_m_577400236_0_gshared (Object_t * __this /* static, unused */, Object_t * ___key, bool ___value, const MethodInfo* method);
#define Dictionary_2_U3CCopyToU3Em__0_m_577400236_0(__this /* static, unused */, ___key, ___value, method) ((  DictionaryEntry_t_1842557272_0  (*) (Object_t * /* static, unused */, Object_t *, bool, const MethodInfo*))Dictionary_2_U3CCopyToU3Em__0_m_577400236_0_gshared)(__this /* static, unused */, ___key, ___value, method)
