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

// System.Collections.Generic.Dictionary`2<System.Int32,System.Object>
struct Dictionary_2_t_1176176332_0;
// System.Collections.Generic.IEqualityComparer`1<System.Int32>
struct IEqualityComparer_1_t_177649431_0;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;
// System.Object
struct Object_t;
// System.Collections.Generic.KeyValuePair`2<System.Int32,System.Object>[]
struct KeyValuePair_2U5BU5D_t_138742644_0;
// System.Array
struct Array_t;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;
// System.Collections.Generic.IEnumerator`1<System.Collections.Generic.KeyValuePair`2<System.Int32,System.Object>>
struct IEnumerator_1_t_5038343_0;
// System.Collections.IDictionaryEnumerator
struct IDictionaryEnumerator_t_855216337_0;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.Int32,System.Object>
struct ValueCollection_t_45348364_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"
#include "mscorlib_System_Collections_Generic_KeyValuePair_2_791204950.h"
#include "mscorlib_System_Collections_Generic_Dictionary_2_En993199873.h"
#include "mscorlib_System_Collections_DictionaryEntry_1842557272.h"

// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::.ctor()
extern "C"  void Dictionary_2__ctor_m1859298524_0_gshared (Dictionary_2_t_1176176332_0 * __this, const MethodInfo* method);
#define Dictionary_2__ctor_m1859298524_0(__this, method) ((  void (*) (Dictionary_2_t_1176176332_0 *, const MethodInfo*))Dictionary_2__ctor_m1859298524_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::.ctor(System.Collections.Generic.IEqualityComparer`1<TKey>)
extern "C"  void Dictionary_2__ctor_m_684964525_0_gshared (Dictionary_2_t_1176176332_0 * __this, Object_t* ___comparer, const MethodInfo* method);
#define Dictionary_2__ctor_m_684964525_0(__this, ___comparer, method) ((  void (*) (Dictionary_2_t_1176176332_0 *, Object_t*, const MethodInfo*))Dictionary_2__ctor_m_684964525_0_gshared)(__this, ___comparer, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::.ctor(System.Int32)
extern "C"  void Dictionary_2__ctor_m_1021054931_0_gshared (Dictionary_2_t_1176176332_0 * __this, int32_t ___capacity, const MethodInfo* method);
#define Dictionary_2__ctor_m_1021054931_0(__this, ___capacity, method) ((  void (*) (Dictionary_2_t_1176176332_0 *, int32_t, const MethodInfo*))Dictionary_2__ctor_m_1021054931_0_gshared)(__this, ___capacity, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::.ctor(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void Dictionary_2__ctor_m1549788189_0_gshared (Dictionary_2_t_1176176332_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method);
#define Dictionary_2__ctor_m1549788189_0(__this, ___info, ___context, method) ((  void (*) (Dictionary_2_t_1176176332_0 *, SerializationInfo_t526833679_0 *, StreamingContext_t_1216992900_0 , const MethodInfo*))Dictionary_2__ctor_m1549788189_0_gshared)(__this, ___info, ___context, method)
// System.Object System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::System.Collections.IDictionary.get_Item(System.Object)
extern "C"  Object_t * Dictionary_2_System_Collections_IDictionary_get_Item_m_1451911774_0_gshared (Dictionary_2_t_1176176332_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_get_Item_m_1451911774_0(__this, ___key, method) ((  Object_t * (*) (Dictionary_2_t_1176176332_0 *, Object_t *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_get_Item_m_1451911774_0_gshared)(__this, ___key, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::System.Collections.IDictionary.set_Item(System.Object,System.Object)
extern "C"  void Dictionary_2_System_Collections_IDictionary_set_Item_m2020057553_0_gshared (Dictionary_2_t_1176176332_0 * __this, Object_t * ___key, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_set_Item_m2020057553_0(__this, ___key, ___value, method) ((  void (*) (Dictionary_2_t_1176176332_0 *, Object_t *, Object_t *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_set_Item_m2020057553_0_gshared)(__this, ___key, ___value, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::System.Collections.IDictionary.Add(System.Object,System.Object)
extern "C"  void Dictionary_2_System_Collections_IDictionary_Add_m_1400701472_0_gshared (Dictionary_2_t_1176176332_0 * __this, Object_t * ___key, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_Add_m_1400701472_0(__this, ___key, ___value, method) ((  void (*) (Dictionary_2_t_1176176332_0 *, Object_t *, Object_t *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_Add_m_1400701472_0_gshared)(__this, ___key, ___value, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::System.Collections.IDictionary.Contains(System.Object)
extern "C"  bool Dictionary_2_System_Collections_IDictionary_Contains_m2093434578_0_gshared (Dictionary_2_t_1176176332_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_Contains_m2093434578_0(__this, ___key, method) ((  bool (*) (Dictionary_2_t_1176176332_0 *, Object_t *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_Contains_m2093434578_0_gshared)(__this, ___key, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::System.Collections.IDictionary.Remove(System.Object)
extern "C"  void Dictionary_2_System_Collections_IDictionary_Remove_m127000079_0_gshared (Dictionary_2_t_1176176332_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_Remove_m127000079_0(__this, ___key, method) ((  void (*) (Dictionary_2_t_1176176332_0 *, Object_t *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_Remove_m127000079_0_gshared)(__this, ___key, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::System.Collections.ICollection.get_IsSynchronized()
extern "C"  bool Dictionary_2_System_Collections_ICollection_get_IsSynchronized_m_232642110_0_gshared (Dictionary_2_t_1176176332_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_ICollection_get_IsSynchronized_m_232642110_0(__this, method) ((  bool (*) (Dictionary_2_t_1176176332_0 *, const MethodInfo*))Dictionary_2_System_Collections_ICollection_get_IsSynchronized_m_232642110_0_gshared)(__this, method)
// System.Object System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::System.Collections.ICollection.get_SyncRoot()
extern "C"  Object_t * Dictionary_2_System_Collections_ICollection_get_SyncRoot_m_229395532_0_gshared (Dictionary_2_t_1176176332_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_ICollection_get_SyncRoot_m_229395532_0(__this, method) ((  Object_t * (*) (Dictionary_2_t_1176176332_0 *, const MethodInfo*))Dictionary_2_System_Collections_ICollection_get_SyncRoot_m_229395532_0_gshared)(__this, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<TKey,TValue>>.get_IsReadOnly()
extern "C"  bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_get_IsReadOnly_m840305542_0_gshared (Dictionary_2_t_1176176332_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_get_IsReadOnly_m840305542_0(__this, method) ((  bool (*) (Dictionary_2_t_1176176332_0 *, const MethodInfo*))Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_get_IsReadOnly_m840305542_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<TKey,TValue>>.Add(System.Collections.Generic.KeyValuePair`2<TKey,TValue>)
extern "C"  void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Add_m_2109737179_0_gshared (Dictionary_2_t_1176176332_0 * __this, KeyValuePair_2_t_791204950_0  ___keyValuePair, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Add_m_2109737179_0(__this, ___keyValuePair, method) ((  void (*) (Dictionary_2_t_1176176332_0 *, KeyValuePair_2_t_791204950_0 , const MethodInfo*))Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Add_m_2109737179_0_gshared)(__this, ___keyValuePair, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<TKey,TValue>>.Contains(System.Collections.Generic.KeyValuePair`2<TKey,TValue>)
extern "C"  bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Contains_m_581588991_0_gshared (Dictionary_2_t_1176176332_0 * __this, KeyValuePair_2_t_791204950_0  ___keyValuePair, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Contains_m_581588991_0(__this, ___keyValuePair, method) ((  bool (*) (Dictionary_2_t_1176176332_0 *, KeyValuePair_2_t_791204950_0 , const MethodInfo*))Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Contains_m_581588991_0_gshared)(__this, ___keyValuePair, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<TKey,TValue>>.CopyTo(System.Collections.Generic.KeyValuePair`2<TKey,TValue>[],System.Int32)
extern "C"  void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_CopyTo_m_74627127_0_gshared (Dictionary_2_t_1176176332_0 * __this, KeyValuePair_2U5BU5D_t_138742644_0* ___array, int32_t ___index, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_CopyTo_m_74627127_0(__this, ___array, ___index, method) ((  void (*) (Dictionary_2_t_1176176332_0 *, KeyValuePair_2U5BU5D_t_138742644_0*, int32_t, const MethodInfo*))Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_CopyTo_m_74627127_0_gshared)(__this, ___array, ___index, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<TKey,TValue>>.Remove(System.Collections.Generic.KeyValuePair`2<TKey,TValue>)
extern "C"  bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Remove_m_964699290_0_gshared (Dictionary_2_t_1176176332_0 * __this, KeyValuePair_2_t_791204950_0  ___keyValuePair, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Remove_m_964699290_0(__this, ___keyValuePair, method) ((  bool (*) (Dictionary_2_t_1176176332_0 *, KeyValuePair_2_t_791204950_0 , const MethodInfo*))Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Remove_m_964699290_0_gshared)(__this, ___keyValuePair, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::System.Collections.ICollection.CopyTo(System.Array,System.Int32)
extern "C"  void Dictionary_2_System_Collections_ICollection_CopyTo_m323672040_0_gshared (Dictionary_2_t_1176176332_0 * __this, Array_t * ___array, int32_t ___index, const MethodInfo* method);
#define Dictionary_2_System_Collections_ICollection_CopyTo_m323672040_0(__this, ___array, ___index, method) ((  void (*) (Dictionary_2_t_1176176332_0 *, Array_t *, int32_t, const MethodInfo*))Dictionary_2_System_Collections_ICollection_CopyTo_m323672040_0_gshared)(__this, ___array, ___index, method)
// System.Collections.IEnumerator System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::System.Collections.IEnumerable.GetEnumerator()
extern "C"  Object_t * Dictionary_2_System_Collections_IEnumerable_GetEnumerator_m464503287_0_gshared (Dictionary_2_t_1176176332_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_IEnumerable_GetEnumerator_m464503287_0(__this, method) ((  Object_t * (*) (Dictionary_2_t_1176176332_0 *, const MethodInfo*))Dictionary_2_System_Collections_IEnumerable_GetEnumerator_m464503287_0_gshared)(__this, method)
// System.Collections.Generic.IEnumerator`1<System.Collections.Generic.KeyValuePair`2<TKey,TValue>> System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::System.Collections.Generic.IEnumerable<System.Collections.Generic.KeyValuePair<TKey,TValue>>.GetEnumerator()
extern "C"  Object_t* Dictionary_2_System_Collections_Generic_IEnumerableU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_GetEnumerator_m1289662318_0_gshared (Dictionary_2_t_1176176332_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_Generic_IEnumerableU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_GetEnumerator_m1289662318_0(__this, method) ((  Object_t* (*) (Dictionary_2_t_1176176332_0 *, const MethodInfo*))Dictionary_2_System_Collections_Generic_IEnumerableU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_GetEnumerator_m1289662318_0_gshared)(__this, method)
// System.Collections.IDictionaryEnumerator System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::System.Collections.IDictionary.GetEnumerator()
extern "C"  Object_t * Dictionary_2_System_Collections_IDictionary_GetEnumerator_m_1107304773_0_gshared (Dictionary_2_t_1176176332_0 * __this, const MethodInfo* method);
#define Dictionary_2_System_Collections_IDictionary_GetEnumerator_m_1107304773_0(__this, method) ((  Object_t * (*) (Dictionary_2_t_1176176332_0 *, const MethodInfo*))Dictionary_2_System_Collections_IDictionary_GetEnumerator_m_1107304773_0_gshared)(__this, method)
// System.Int32 System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::get_Count()
extern "C"  int32_t Dictionary_2_get_Count_m655926012_0_gshared (Dictionary_2_t_1176176332_0 * __this, const MethodInfo* method);
#define Dictionary_2_get_Count_m655926012_0(__this, method) ((  int32_t (*) (Dictionary_2_t_1176176332_0 *, const MethodInfo*))Dictionary_2_get_Count_m655926012_0_gshared)(__this, method)
// TValue System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::get_Item(TKey)
extern "C"  Object_t * Dictionary_2_get_Item_m542157067_0_gshared (Dictionary_2_t_1176176332_0 * __this, int32_t ___key, const MethodInfo* method);
#define Dictionary_2_get_Item_m542157067_0(__this, ___key, method) ((  Object_t * (*) (Dictionary_2_t_1176176332_0 *, int32_t, const MethodInfo*))Dictionary_2_get_Item_m542157067_0_gshared)(__this, ___key, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::set_Item(TKey,TValue)
extern "C"  void Dictionary_2_set_Item_m_1075369572_0_gshared (Dictionary_2_t_1176176332_0 * __this, int32_t ___key, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_set_Item_m_1075369572_0(__this, ___key, ___value, method) ((  void (*) (Dictionary_2_t_1176176332_0 *, int32_t, Object_t *, const MethodInfo*))Dictionary_2_set_Item_m_1075369572_0_gshared)(__this, ___key, ___value, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::Init(System.Int32,System.Collections.Generic.IEqualityComparer`1<TKey>)
extern "C"  void Dictionary_2_Init_m_1133339564_0_gshared (Dictionary_2_t_1176176332_0 * __this, int32_t ___capacity, Object_t* ___hcp, const MethodInfo* method);
#define Dictionary_2_Init_m_1133339564_0(__this, ___capacity, ___hcp, method) ((  void (*) (Dictionary_2_t_1176176332_0 *, int32_t, Object_t*, const MethodInfo*))Dictionary_2_Init_m_1133339564_0_gshared)(__this, ___capacity, ___hcp, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::InitArrays(System.Int32)
extern "C"  void Dictionary_2_InitArrays_m_1205712413_0_gshared (Dictionary_2_t_1176176332_0 * __this, int32_t ___size, const MethodInfo* method);
#define Dictionary_2_InitArrays_m_1205712413_0(__this, ___size, method) ((  void (*) (Dictionary_2_t_1176176332_0 *, int32_t, const MethodInfo*))Dictionary_2_InitArrays_m_1205712413_0_gshared)(__this, ___size, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::CopyToCheck(System.Array,System.Int32)
extern "C"  void Dictionary_2_CopyToCheck_m_553608033_0_gshared (Dictionary_2_t_1176176332_0 * __this, Array_t * ___array, int32_t ___index, const MethodInfo* method);
#define Dictionary_2_CopyToCheck_m_553608033_0(__this, ___array, ___index, method) ((  void (*) (Dictionary_2_t_1176176332_0 *, Array_t *, int32_t, const MethodInfo*))Dictionary_2_CopyToCheck_m_553608033_0_gshared)(__this, ___array, ___index, method)
// System.Collections.Generic.KeyValuePair`2<TKey,TValue> System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::make_pair(TKey,TValue)
extern "C"  KeyValuePair_2_t_791204950_0  Dictionary_2_make_pair_m_1956795597_0_gshared (Object_t * __this /* static, unused */, int32_t ___key, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_make_pair_m_1956795597_0(__this /* static, unused */, ___key, ___value, method) ((  KeyValuePair_2_t_791204950_0  (*) (Object_t * /* static, unused */, int32_t, Object_t *, const MethodInfo*))Dictionary_2_make_pair_m_1956795597_0_gshared)(__this /* static, unused */, ___key, ___value, method)
// TValue System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::pick_value(TKey,TValue)
extern "C"  Object_t * Dictionary_2_pick_value_m1281047495_0_gshared (Object_t * __this /* static, unused */, int32_t ___key, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_pick_value_m1281047495_0(__this /* static, unused */, ___key, ___value, method) ((  Object_t * (*) (Object_t * /* static, unused */, int32_t, Object_t *, const MethodInfo*))Dictionary_2_pick_value_m1281047495_0_gshared)(__this /* static, unused */, ___key, ___value, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::CopyTo(System.Collections.Generic.KeyValuePair`2<TKey,TValue>[],System.Int32)
extern "C"  void Dictionary_2_CopyTo_m_1791339952_0_gshared (Dictionary_2_t_1176176332_0 * __this, KeyValuePair_2U5BU5D_t_138742644_0* ___array, int32_t ___index, const MethodInfo* method);
#define Dictionary_2_CopyTo_m_1791339952_0(__this, ___array, ___index, method) ((  void (*) (Dictionary_2_t_1176176332_0 *, KeyValuePair_2U5BU5D_t_138742644_0*, int32_t, const MethodInfo*))Dictionary_2_CopyTo_m_1791339952_0_gshared)(__this, ___array, ___index, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::Resize()
extern "C"  void Dictionary_2_Resize_m1861476060_0_gshared (Dictionary_2_t_1176176332_0 * __this, const MethodInfo* method);
#define Dictionary_2_Resize_m1861476060_0(__this, method) ((  void (*) (Dictionary_2_t_1176176332_0 *, const MethodInfo*))Dictionary_2_Resize_m1861476060_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::Add(TKey,TValue)
extern "C"  void Dictionary_2_Add_m_2062923943_0_gshared (Dictionary_2_t_1176176332_0 * __this, int32_t ___key, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_Add_m_2062923943_0(__this, ___key, ___value, method) ((  void (*) (Dictionary_2_t_1176176332_0 *, int32_t, Object_t *, const MethodInfo*))Dictionary_2_Add_m_2062923943_0_gshared)(__this, ___key, ___value, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::Clear()
extern "C"  void Dictionary_2_Clear_m_734568185_0_gshared (Dictionary_2_t_1176176332_0 * __this, const MethodInfo* method);
#define Dictionary_2_Clear_m_734568185_0(__this, method) ((  void (*) (Dictionary_2_t_1176176332_0 *, const MethodInfo*))Dictionary_2_Clear_m_734568185_0_gshared)(__this, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::ContainsKey(TKey)
extern "C"  bool Dictionary_2_ContainsKey_m_1682797583_0_gshared (Dictionary_2_t_1176176332_0 * __this, int32_t ___key, const MethodInfo* method);
#define Dictionary_2_ContainsKey_m_1682797583_0(__this, ___key, method) ((  bool (*) (Dictionary_2_t_1176176332_0 *, int32_t, const MethodInfo*))Dictionary_2_ContainsKey_m_1682797583_0_gshared)(__this, ___key, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::ContainsValue(TValue)
extern "C"  bool Dictionary_2_ContainsValue_m454328177_0_gshared (Dictionary_2_t_1176176332_0 * __this, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_ContainsValue_m454328177_0(__this, ___value, method) ((  bool (*) (Dictionary_2_t_1176176332_0 *, Object_t *, const MethodInfo*))Dictionary_2_ContainsValue_m454328177_0_gshared)(__this, ___value, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void Dictionary_2_GetObjectData_m_868368774_0_gshared (Dictionary_2_t_1176176332_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method);
#define Dictionary_2_GetObjectData_m_868368774_0(__this, ___info, ___context, method) ((  void (*) (Dictionary_2_t_1176176332_0 *, SerializationInfo_t526833679_0 *, StreamingContext_t_1216992900_0 , const MethodInfo*))Dictionary_2_GetObjectData_m_868368774_0_gshared)(__this, ___info, ___context, method)
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::OnDeserialization(System.Object)
extern "C"  void Dictionary_2_OnDeserialization_m_311088086_0_gshared (Dictionary_2_t_1176176332_0 * __this, Object_t * ___sender, const MethodInfo* method);
#define Dictionary_2_OnDeserialization_m_311088086_0(__this, ___sender, method) ((  void (*) (Dictionary_2_t_1176176332_0 *, Object_t *, const MethodInfo*))Dictionary_2_OnDeserialization_m_311088086_0_gshared)(__this, ___sender, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::Remove(TKey)
extern "C"  bool Dictionary_2_Remove_m183515743_0_gshared (Dictionary_2_t_1176176332_0 * __this, int32_t ___key, const MethodInfo* method);
#define Dictionary_2_Remove_m183515743_0(__this, ___key, method) ((  bool (*) (Dictionary_2_t_1176176332_0 *, int32_t, const MethodInfo*))Dictionary_2_Remove_m183515743_0_gshared)(__this, ___key, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::TryGetValue(TKey,TValue&)
extern "C"  bool Dictionary_2_TryGetValue_m_1779408054_0_gshared (Dictionary_2_t_1176176332_0 * __this, int32_t ___key, Object_t ** ___value, const MethodInfo* method);
#define Dictionary_2_TryGetValue_m_1779408054_0(__this, ___key, ___value, method) ((  bool (*) (Dictionary_2_t_1176176332_0 *, int32_t, Object_t **, const MethodInfo*))Dictionary_2_TryGetValue_m_1779408054_0_gshared)(__this, ___key, ___value, method)
// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::get_Values()
extern "C"  ValueCollection_t_45348364_0 * Dictionary_2_get_Values_m1815086189_0_gshared (Dictionary_2_t_1176176332_0 * __this, const MethodInfo* method);
#define Dictionary_2_get_Values_m1815086189_0(__this, method) ((  ValueCollection_t_45348364_0 * (*) (Dictionary_2_t_1176176332_0 *, const MethodInfo*))Dictionary_2_get_Values_m1815086189_0_gshared)(__this, method)
// TKey System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::ToTKey(System.Object)
extern "C"  int32_t Dictionary_2_ToTKey_m844610694_0_gshared (Dictionary_2_t_1176176332_0 * __this, Object_t * ___key, const MethodInfo* method);
#define Dictionary_2_ToTKey_m844610694_0(__this, ___key, method) ((  int32_t (*) (Dictionary_2_t_1176176332_0 *, Object_t *, const MethodInfo*))Dictionary_2_ToTKey_m844610694_0_gshared)(__this, ___key, method)
// TValue System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::ToTValue(System.Object)
extern "C"  Object_t * Dictionary_2_ToTValue_m_406638366_0_gshared (Dictionary_2_t_1176176332_0 * __this, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_ToTValue_m_406638366_0(__this, ___value, method) ((  Object_t * (*) (Dictionary_2_t_1176176332_0 *, Object_t *, const MethodInfo*))Dictionary_2_ToTValue_m_406638366_0_gshared)(__this, ___value, method)
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::ContainsKeyValuePair(System.Collections.Generic.KeyValuePair`2<TKey,TValue>)
extern "C"  bool Dictionary_2_ContainsKeyValuePair_m139391042_0_gshared (Dictionary_2_t_1176176332_0 * __this, KeyValuePair_2_t_791204950_0  ___pair, const MethodInfo* method);
#define Dictionary_2_ContainsKeyValuePair_m139391042_0(__this, ___pair, method) ((  bool (*) (Dictionary_2_t_1176176332_0 *, KeyValuePair_2_t_791204950_0 , const MethodInfo*))Dictionary_2_ContainsKeyValuePair_m139391042_0_gshared)(__this, ___pair, method)
// System.Collections.Generic.Dictionary`2/Enumerator<TKey,TValue> System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::GetEnumerator()
extern "C"  Enumerator_t993199873_0  Dictionary_2_GetEnumerator_m_573978137_0_gshared (Dictionary_2_t_1176176332_0 * __this, const MethodInfo* method);
#define Dictionary_2_GetEnumerator_m_573978137_0(__this, method) ((  Enumerator_t993199873_0  (*) (Dictionary_2_t_1176176332_0 *, const MethodInfo*))Dictionary_2_GetEnumerator_m_573978137_0_gshared)(__this, method)
// System.Collections.DictionaryEntry System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::<CopyTo>m__0(TKey,TValue)
extern "C"  DictionaryEntry_t_1842557272_0  Dictionary_2_U3CCopyToU3Em__0_m_1357863266_0_gshared (Object_t * __this /* static, unused */, int32_t ___key, Object_t * ___value, const MethodInfo* method);
#define Dictionary_2_U3CCopyToU3Em__0_m_1357863266_0(__this /* static, unused */, ___key, ___value, method) ((  DictionaryEntry_t_1842557272_0  (*) (Object_t * /* static, unused */, int32_t, Object_t *, const MethodInfo*))Dictionary_2_U3CCopyToU3Em__0_m_1357863266_0_gshared)(__this /* static, unused */, ___key, ___value, method)
