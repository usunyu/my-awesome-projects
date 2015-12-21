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

// System.Collections.Generic.Dictionary`2<System.Object,System.Object>
struct Dictionary_2_t_1114179913_0;
// System.Collections.Generic.IEqualityComparer`1<System.Object>
struct IEqualityComparer_1_t_533356922_0;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;
// System.Object
struct Object_t;
// System.Collections.Generic.KeyValuePair`2<System.Object,System.Object>[]
struct KeyValuePair_2U5BU5D_t_160275933_0;
// System.Array
struct Array_t;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;
// System.Collections.Generic.IEnumerator`1<System.Collections.Generic.KeyValuePair`2<System.Object,System.Object>>
struct IEnumerator_1_t393026776_0;
// System.Collections.IDictionaryEnumerator
struct IDictionaryEnumerator_t_855216337_0;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.Object,System.Object>
struct ValueCollection_t_418251273_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"
#include "mscorlib_System_Collections_Generic_KeyValuePair__2064968959.h"
#include "mscorlib_System_Collections_Generic_Dictionary_2_E1711973002.h"
#include "mscorlib_System_Collections_DictionaryEntry_1842557272.h"

// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::.ctor()
extern "C"  void Dictionary_2__ctor_m_500328897_0_gshared (Dictionary_2_t_1114179913_0 * __this, const MethodInfo* method);
#define Dictionary_2__ctor_m_500328897_0(__this, method) ((  void (*) (Dictionary_2_t_1114179913_0 *, const MethodInfo*))Dictionary_2__ctor_m_500328897_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::.ctor(System.Collections.Generic.IEqualityComparer`1<TKey>)
extern "C"  void Dictionary_2__ctor_m273898294_0_gshared (Dictionary_2_t_1114179913_0 * __this, Object_t* ___comparer, const MethodInfo* method);
#define Dictionary_2__ctor_m273898294_0(__this, ___comparer, method) ((  void (*) (Dictionary_2_t_1114179913_0 *, Object_t*, const MethodInfo*))Dictionary_2__ctor_m273898294_0_gshared)(__this, ___comparer, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::.ctor(System.Int32)
extern "C"  void Dictionary_2__ctor_m_1790384880_0_gshared (Dictionary_2_t_1114179913_0 * __this, int32_t ___capacity, const MethodInfo* method);
#define Dictionary_2__ctor_m_1790384880_0(__this, ___capacity, method) ((  void (*) (Dictionary_2_t_1114179913_0 *, int32_t, const MethodInfo*))Dictionary_2__ctor_m_1790384880_0_gshared)(__this, ___capacity, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::.ctor(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void Dictionary_2__ctor_m_132900096_0_gshared (Dictionary_2_t_1114179913_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method);
#define Dictionary_2__ctor_m_132900096_0(__this, ___info, ___context, method) ((  void (*) (Dictionary_2_t_1114179913_0 *, SerializationInfo_t526833679_0 *, StreamingContext_t_1216992900_0 , const MethodInfo*))Dictionary_2__ctor_m_132900096_0_gshared)(__this, ___info, ___context, method)
// System.Object System.Collections.Generic.Dictionary`2<System.Object,System.Object>::System.Collections.IDictionary.get_Item(System.Object)
extern "C"  Object_t * Dictionary_2_System_Collections_IDictionary_get_Item_m1551250025_0_gshared (Dictionary_2_t_1114179913_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_get_Item_m1551250025_0(__this, ___key, method) ((  Object_t * (*) (Dictionary_2_t_1114179913_0 *, Object_t *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_get_Item_m1551250025_0_gshared)(__this, ___key, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::System.Collections.IDictionary.set_Item(System.Object,System.Object)
extern "C"  void Dictionary_2_System_Collections_IDictionary_set_Item_m1049066318_0_gshared (Dictionary_2_t_1114179913_0 * __this, Object_t * ___key, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_set_Item_m1049066318_0(__this, ___key, ___value, method) ((  void (*) (Dictionary_2_t_1114179913_0 *, Object_t *, Object_t *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_set_Item_m1049066318_0_gshared)(__this, ___key, ___value, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::System.Collections.IDictionary.Add(System.Object,System.Object)
extern "C"  void Dictionary_2_System_Collections_IDictionary_Add_m781609539_0_gshared (Dictionary_2_t_1114179913_0 * __this, Object_t * ___key, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_Add_m781609539_0(__this, ___key, ___value, method) ((  void (*) (Dictionary_2_t_1114179913_0 *, Object_t *, Object_t *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_Add_m781609539_0_gshared)(__this, ___key, ___value, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Object>::System.Collections.IDictionary.Contains(System.Object)
extern "C"  bool Dictionary_2_System_Collections_IDictionary_Contains_m1783363411_0_gshared (Dictionary_2_t_1114179913_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_Contains_m1783363411_0(__this, ___key, method) ((  bool (*) (Dictionary_2_t_1114179913_0 *, Object_t *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_Contains_m1783363411_0_gshared)(__this, ___key, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::System.Collections.IDictionary.Remove(System.Object)
extern "C"  void Dictionary_2_System_Collections_IDictionary_Remove_m_2079960692_0_gshared (Dictionary_2_t_1114179913_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_Remove_m_2079960692_0(__this, ___key, method) ((  void (*) (Dictionary_2_t_1114179913_0 *, Object_t *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_Remove_m_2079960692_0_gshared)(__this, ___key, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Object>::System.Collections.ICollection.get_IsSynchronized()
extern "C"  bool Dictionary_2_System_Collections_ICollection_get_IsSynchronized_m1826238689_0_gshared (Dictionary_2_t_1114179913_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_ICollection_get_IsSynchronized_m1826238689_0(__this, method) ((  bool (*) (Dictionary_2_t_1114179913_0 *, const MethodInfo*))Dictionary_2_System_Collections_ICollection_get_IsSynchronized_m1826238689_0_gshared)(__this, method)
// System.Object System.Collections.Generic.Dictionary`2<System.Object,System.Object>::System.Collections.ICollection.get_SyncRoot()
extern "C"  Object_t * Dictionary_2_System_Collections_ICollection_get_SyncRoot_m2075478797_0_gshared (Dictionary_2_t_1114179913_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_ICollection_get_SyncRoot_m2075478797_0(__this, method) ((  Object_t * (*) (Dictionary_2_t_1114179913_0 *, const MethodInfo*))Dictionary_2_System_Collections_ICollection_get_SyncRoot_m2075478797_0_gshared)(__this, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Object>::System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<TKey,TValue>>.get_IsReadOnly()
extern "C"  bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_get_IsReadOnly_m1433083365_0_gshared (Dictionary_2_t_1114179913_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_get_IsReadOnly_m1433083365_0(__this, method) ((  bool (*) (Dictionary_2_t_1114179913_0 *, const MethodInfo*))Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_get_IsReadOnly_m1433083365_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<TKey,TValue>>.Add(System.Collections.Generic.KeyValuePair`2<TKey,TValue>)
extern "C"  void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Add_m_1037907934_0_gshared (Dictionary_2_t_1114179913_0 * __this, KeyValuePair_2_t_2064968959_0  ___keyValuePair, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Add_m_1037907934_0(__this, ___keyValuePair, method) ((  void (*) (Dictionary_2_t_1114179913_0 *, KeyValuePair_2_t_2064968959_0 , const MethodInfo*))Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Add_m_1037907934_0_gshared)(__this, ___keyValuePair, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Object>::System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<TKey,TValue>>.Contains(System.Collections.Generic.KeyValuePair`2<TKey,TValue>)
extern "C"  bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Contains_m_1550917536_0_gshared (Dictionary_2_t_1114179913_0 * __this, KeyValuePair_2_t_2064968959_0  ___keyValuePair, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Contains_m_1550917536_0(__this, ___keyValuePair, method) ((  bool (*) (Dictionary_2_t_1114179913_0 *, KeyValuePair_2_t_2064968959_0 , const MethodInfo*))Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Contains_m_1550917536_0_gshared)(__this, ___keyValuePair, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<TKey,TValue>>.CopyTo(System.Collections.Generic.KeyValuePair`2<TKey,TValue>[],System.Int32)
extern "C"  void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_CopyTo_m2008986502_0_gshared (Dictionary_2_t_1114179913_0 * __this, KeyValuePair_2U5BU5D_t_160275933_0* ___array, int32_t ___index, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_CopyTo_m2008986502_0(__this, ___array, ___index, method) ((  void (*) (Dictionary_2_t_1114179913_0 *, KeyValuePair_2U5BU5D_t_160275933_0*, int32_t, const MethodInfo*))Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_CopyTo_m2008986502_0_gshared)(__this, ___array, ___index, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Object>::System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<TKey,TValue>>.Remove(System.Collections.Generic.KeyValuePair`2<TKey,TValue>)
extern "C"  bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Remove_m_1944477819_0_gshared (Dictionary_2_t_1114179913_0 * __this, KeyValuePair_2_t_2064968959_0  ___keyValuePair, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Remove_m_1944477819_0(__this, ___keyValuePair, method) ((  bool (*) (Dictionary_2_t_1114179913_0 *, KeyValuePair_2_t_2064968959_0 , const MethodInfo*))Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Remove_m_1944477819_0_gshared)(__this, ___keyValuePair, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::System.Collections.ICollection.CopyTo(System.Array,System.Int32)
extern "C"  void Dictionary_2_System_Collections_ICollection_CopyTo_m_744163355_0_gshared (Dictionary_2_t_1114179913_0 * __this, Array_t * ___array, int32_t ___index, const MethodInfo* method);
#define Dictionary_2_System_Collections_ICollection_CopyTo_m_744163355_0(__this, ___array, ___index, method) ((  void (*) (Dictionary_2_t_1114179913_0 *, Array_t *, int32_t, const MethodInfo*))Dictionary_2_System_Collections_ICollection_CopyTo_m_744163355_0_gshared)(__this, ___array, ___index, method)
// System.Collections.IEnumerator System.Collections.Generic.Dictionary`2<System.Object,System.Object>::System.Collections.IEnumerable.GetEnumerator()
extern "C"  Object_t * Dictionary_2_System_Collections_IEnumerable_GetEnumerator_m_179256032_0_gshared (Dictionary_2_t_1114179913_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_IEnumerable_GetEnumerator_m_179256032_0(__this, method) ((  Object_t * (*) (Dictionary_2_t_1114179913_0 *, const MethodInfo*))Dictionary_2_System_Collections_IEnumerable_GetEnumerator_m_179256032_0_gshared)(__this, method)
// System.Collections.Generic.IEnumerator`1<System.Collections.Generic.KeyValuePair`2<TKey,TValue>> System.Collections.Generic.Dictionary`2<System.Object,System.Object>::System.Collections.Generic.IEnumerable<System.Collections.Generic.KeyValuePair<TKey,TValue>>.GetEnumerator()
extern "C"  Object_t* Dictionary_2_System_Collections_Generic_IEnumerableU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_GetEnumerator_m52259357_0_gshared (Dictionary_2_t_1114179913_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_IEnumerableU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_GetEnumerator_m52259357_0(__this, method) ((  Object_t* (*) (Dictionary_2_t_1114179913_0 *, const MethodInfo*))Dictionary_2_System_Collections_Generic_IEnumerableU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_GetEnumerator_m52259357_0_gshared)(__this, method)
// System.Collections.IDictionaryEnumerator System.Collections.Generic.Dictionary`2<System.Object,System.Object>::System.Collections.IDictionary.GetEnumerator()
extern "C"  Object_t * Dictionary_2_System_Collections_IDictionary_GetEnumerator_m1395730616_0_gshared (Dictionary_2_t_1114179913_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_GetEnumerator_m1395730616_0(__this, method) ((  Object_t * (*) (Dictionary_2_t_1114179913_0 *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_GetEnumerator_m1395730616_0_gshared)(__this, method)
// System.Int32 System.Collections.Generic.Dictionary`2<System.Object,System.Object>::get_Count()
extern "C"  int32_t Dictionary_2_get_Count_m1232250407_0_gshared (Dictionary_2_t_1114179913_0 * __this, const MethodInfo* method);
#define Dictionary_2_get_Count_m1232250407_0(__this, method) ((  int32_t (*) (Dictionary_2_t_1114179913_0 *, const MethodInfo*))Dictionary_2_get_Count_m1232250407_0_gshared)(__this, method)
// TValue System.Collections.Generic.Dictionary`2<System.Object,System.Object>::get_Item(TKey)
extern "C"  Object_t * Dictionary_2_get_Item_m_2009610012_0_gshared (Dictionary_2_t_1114179913_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_get_Item_m_2009610012_0(__this, ___key, method) ((  Object_t * (*) (Dictionary_2_t_1114179913_0 *, Object_t *, const MethodInfo*))Dictionary_2_get_Item_m_2009610012_0_gshared)(__this, ___key, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::set_Item(TKey,TValue)
extern "C"  void Dictionary_2_set_Item_m_1667075649_0_gshared (Dictionary_2_t_1114179913_0 * __this, Object_t * ___key, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_set_Item_m_1667075649_0(__this, ___key, ___value, method) ((  void (*) (Dictionary_2_t_1114179913_0 *, Object_t *, Object_t *, const MethodInfo*))Dictionary_2_set_Item_m_1667075649_0_gshared)(__this, ___key, ___value, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::Init(System.Int32,System.Collections.Generic.IEqualityComparer`1<TKey>)
extern "C"  void Dictionary_2_Init_m_1328482889_0_gshared (Dictionary_2_t_1114179913_0 * __this, int32_t ___capacity, Object_t* ___hcp, const MethodInfo* method);
#define Dictionary_2_Init_m_1328482889_0(__this, ___capacity, ___hcp, method) ((  void (*) (Dictionary_2_t_1114179913_0 *, int32_t, Object_t*, const MethodInfo*))Dictionary_2_Init_m_1328482889_0_gshared)(__this, ___capacity, ___hcp, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::InitArrays(System.Int32)
extern "C"  void Dictionary_2_InitArrays_m2119297760_0_gshared (Dictionary_2_t_1114179913_0 * __this, int32_t ___size, const MethodInfo* method);
#define Dictionary_2_InitArrays_m2119297760_0(__this, ___size, method) ((  void (*) (Dictionary_2_t_1114179913_0 *, int32_t, const MethodInfo*))Dictionary_2_InitArrays_m2119297760_0_gshared)(__this, ___size, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::CopyToCheck(System.Array,System.Int32)
extern "C"  void Dictionary_2_CopyToCheck_m_1758445860_0_gshared (Dictionary_2_t_1114179913_0 * __this, Array_t * ___array, int32_t ___index, const MethodInfo* method);
#define Dictionary_2_CopyToCheck_m_1758445860_0(__this, ___array, ___index, method) ((  void (*) (Dictionary_2_t_1114179913_0 *, Array_t *, int32_t, const MethodInfo*))Dictionary_2_CopyToCheck_m_1758445860_0_gshared)(__this, ___array, ___index, method)
// System.Collections.Generic.KeyValuePair`2<TKey,TValue> System.Collections.Generic.Dictionary`2<System.Object,System.Object>::make_pair(TKey,TValue)
extern "C"  KeyValuePair_2_t_2064968959_0  Dictionary_2_make_pair_m2083407400_0_gshared (Object_t * __this /* static, unused */, Object_t * ___key, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_make_pair_m2083407400_0(__this /* static, unused */, ___key, ___value, method) ((  KeyValuePair_2_t_2064968959_0  (*) (Object_t * /* static, unused */, Object_t *, Object_t *, const MethodInfo*))Dictionary_2_make_pair_m2083407400_0_gshared)(__this /* static, unused */, ___key, ___value, method)
// TValue System.Collections.Generic.Dictionary`2<System.Object,System.Object>::pick_value(TKey,TValue)
extern "C"  Object_t * Dictionary_2_pick_value_m_817373170_0_gshared (Object_t * __this /* static, unused */, Object_t * ___key, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_pick_value_m_817373170_0(__this /* static, unused */, ___key, ___value, method) ((  Object_t * (*) (Object_t * /* static, unused */, Object_t *, Object_t *, const MethodInfo*))Dictionary_2_pick_value_m_817373170_0_gshared)(__this /* static, unused */, ___key, ___value, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::CopyTo(System.Collections.Generic.KeyValuePair`2<TKey,TValue>[],System.Int32)
extern "C"  void Dictionary_2_CopyTo_m_893725325_0_gshared (Dictionary_2_t_1114179913_0 * __this, KeyValuePair_2U5BU5D_t_160275933_0* ___array, int32_t ___index, const MethodInfo* method);
#define Dictionary_2_CopyTo_m_893725325_0(__this, ___array, ___index, method) ((  void (*) (Dictionary_2_t_1114179913_0 *, KeyValuePair_2U5BU5D_t_160275933_0*, int32_t, const MethodInfo*))Dictionary_2_CopyTo_m_893725325_0_gshared)(__this, ___array, ___index, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::Resize()
extern "C"  void Dictionary_2_Resize_m1727470041_0_gshared (Dictionary_2_t_1114179913_0 * __this, const MethodInfo* method);
#define Dictionary_2_Resize_m1727470041_0(__this, method) ((  void (*) (Dictionary_2_t_1114179913_0 *, const MethodInfo*))Dictionary_2_Resize_m1727470041_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::Add(TKey,TValue)
extern "C"  void Dictionary_2_Add_m_757779114_0_gshared (Dictionary_2_t_1114179913_0 * __this, Object_t * ___key, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_Add_m_757779114_0(__this, ___key, ___value, method) ((  void (*) (Dictionary_2_t_1114179913_0 *, Object_t *, Object_t *, const MethodInfo*))Dictionary_2_Add_m_757779114_0_gshared)(__this, ___key, ___value, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::Clear()
extern "C"  void Dictionary_2_Clear_m1200771690_0_gshared (Dictionary_2_t_1114179913_0 * __this, const MethodInfo* method);
#define Dictionary_2_Clear_m1200771690_0(__this, method) ((  void (*) (Dictionary_2_t_1114179913_0 *, const MethodInfo*))Dictionary_2_Clear_m1200771690_0_gshared)(__this, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Object>::ContainsKey(TKey)
extern "C"  bool Dictionary_2_ContainsKey_m_1287976240_0_gshared (Dictionary_2_t_1114179913_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_ContainsKey_m_1287976240_0(__this, ___key, method) ((  bool (*) (Dictionary_2_t_1114179913_0 *, Object_t *, const MethodInfo*))Dictionary_2_ContainsKey_m_1287976240_0_gshared)(__this, ___key, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Object>::ContainsValue(TValue)
extern "C"  bool Dictionary_2_ContainsValue_m712275664_0_gshared (Dictionary_2_t_1114179913_0 * __this, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_ContainsValue_m712275664_0(__this, ___value, method) ((  bool (*) (Dictionary_2_t_1114179913_0 *, Object_t *, const MethodInfo*))Dictionary_2_ContainsValue_m712275664_0_gshared)(__this, ___value, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void Dictionary_2_GetObjectData_m1544184413_0_gshared (Dictionary_2_t_1114179913_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method);
#define Dictionary_2_GetObjectData_m1544184413_0(__this, ___info, ___context, method) ((  void (*) (Dictionary_2_t_1114179913_0 *, SerializationInfo_t526833679_0 *, StreamingContext_t_1216992900_0 , const MethodInfo*))Dictionary_2_GetObjectData_m1544184413_0_gshared)(__this, ___info, ___context, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::OnDeserialization(System.Object)
extern "C"  void Dictionary_2_OnDeserialization_m1638301735_0_gshared (Dictionary_2_t_1114179913_0 * __this, Object_t * ___sender, const MethodInfo* method);
#define Dictionary_2_OnDeserialization_m1638301735_0(__this, ___sender, method) ((  void (*) (Dictionary_2_t_1114179913_0 *, Object_t *, const MethodInfo*))Dictionary_2_OnDeserialization_m1638301735_0_gshared)(__this, ___sender, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Object>::Remove(TKey)
extern "C"  bool Dictionary_2_Remove_m_2139247584_0_gshared (Dictionary_2_t_1114179913_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_Remove_m_2139247584_0(__this, ___key, method) ((  bool (*) (Dictionary_2_t_1114179913_0 *, Object_t *, const MethodInfo*))Dictionary_2_Remove_m_2139247584_0_gshared)(__this, ___key, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Object>::TryGetValue(TKey,TValue&)
extern "C"  bool Dictionary_2_TryGetValue_m2075628329_0_gshared (Dictionary_2_t_1114179913_0 * __this, Object_t * ___key, Object_t ** ___value, const MethodInfo* method);
#define Dictionary_2_TryGetValue_m2075628329_0(__this, ___key, ___value, method) ((  bool (*) (Dictionary_2_t_1114179913_0 *, Object_t *, Object_t **, const MethodInfo*))Dictionary_2_TryGetValue_m2075628329_0_gshared)(__this, ___key, ___value, method)
// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2<System.Object,System.Object>::get_Values()
extern "C"  ValueCollection_t_418251273_0 * Dictionary_2_get_Values_m2070602102_0_gshared (Dictionary_2_t_1114179913_0 * __this, const MethodInfo* method);
#define Dictionary_2_get_Values_m2070602102_0(__this, method) ((  ValueCollection_t_418251273_0 * (*) (Dictionary_2_t_1114179913_0 *, const MethodInfo*))Dictionary_2_get_Values_m2070602102_0_gshared)(__this, method)
// TKey System.Collections.Generic.Dictionary`2<System.Object,System.Object>::ToTKey(System.Object)
extern "C"  Object_t * Dictionary_2_ToTKey_m_936014807_0_gshared (Dictionary_2_t_1114179913_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_ToTKey_m_936014807_0(__this, ___key, method) ((  Object_t * (*) (Dictionary_2_t_1114179913_0 *, Object_t *, const MethodInfo*))Dictionary_2_ToTKey_m_936014807_0_gshared)(__this, ___key, method)
// TValue System.Collections.Generic.Dictionary`2<System.Object,System.Object>::ToTValue(System.Object)
extern "C"  Object_t * Dictionary_2_ToTValue_m1789908265_0_gshared (Dictionary_2_t_1114179913_0 * __this, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_ToTValue_m1789908265_0(__this, ___value, method) ((  Object_t * (*) (Dictionary_2_t_1114179913_0 *, Object_t *, const MethodInfo*))Dictionary_2_ToTValue_m1789908265_0_gshared)(__this, ___value, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Object>::ContainsKeyValuePair(System.Collections.Generic.KeyValuePair`2<TKey,TValue>)
extern "C"  bool Dictionary_2_ContainsKeyValuePair_m_1221731837_0_gshared (Dictionary_2_t_1114179913_0 * __this, KeyValuePair_2_t_2064968959_0  ___pair, const MethodInfo* method);
#define Dictionary_2_ContainsKeyValuePair_m_1221731837_0(__this, ___pair, method) ((  bool (*) (Dictionary_2_t_1114179913_0 *, KeyValuePair_2_t_2064968959_0 , const MethodInfo*))Dictionary_2_ContainsKeyValuePair_m_1221731837_0_gshared)(__this, ___pair, method)
// System.Collections.Generic.Dictionary`2/Enumerator<TKey,TValue> System.Collections.Generic.Dictionary`2<System.Object,System.Object>::GetEnumerator()
extern "C"  Enumerator_t1711973002_0  Dictionary_2_GetEnumerator_m65675076_0_gshared (Dictionary_2_t_1114179913_0 * __this, const MethodInfo* method);
#define Dictionary_2_GetEnumerator_m65675076_0(__this, method) ((  Enumerator_t1711973002_0  (*) (Dictionary_2_t_1114179913_0 *, const MethodInfo*))Dictionary_2_GetEnumerator_m65675076_0_gshared)(__this, method)
// System.Collections.DictionaryEntry System.Collections.Generic.Dictionary`2<System.Object,System.Object>::<CopyTo>m__0(TKey,TValue)
extern "C"  DictionaryEntry_t_1842557272_0  Dictionary_2_U3CCopyToU3Em__0_m_476237165_0_gshared (Object_t * __this /* static, unused */, Object_t * ___key, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_U3CCopyToU3Em__0_m_476237165_0(__this /* static, unused */, ___key, ___value, method) ((  DictionaryEntry_t_1842557272_0  (*) (Object_t * /* static, unused */, Object_t *, Object_t *, const MethodInfo*))Dictionary_2_U3CCopyToU3Em__0_m_476237165_0_gshared)(__this /* static, unused */, ___key, ___value, method)
