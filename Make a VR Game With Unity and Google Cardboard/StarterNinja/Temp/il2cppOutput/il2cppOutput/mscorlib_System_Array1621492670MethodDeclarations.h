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

// System.Array
struct Array_t;
// System.Object
struct Object_t;
// System.Int32[]
struct Int32U5BU5D_t1872284309_0;
// System.Type
struct Type_t;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;
// System.Int64[]
struct Int64U5BU5D_t1872375604_0;
// System.Collections.IComparer
struct IComparer_t622777826_0;
// System.Array/Swapper
struct Swapper_t1012272441_0;
// System.Double[]
struct DoubleU5BU5D_t_1251569810_0;
// System.Char[]
struct CharU5BU5D_t_1225802637_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Array::.ctor()
extern "C"  void Array__ctor_m497751576_0 (Array_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Array::System.Collections.IList.get_Item(System.Int32)
extern "C"  Object_t * Array_System_Collections_IList_get_Item_m_1879401171_0 (Array_t * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::System.Collections.IList.set_Item(System.Int32,System.Object)
extern "C"  void Array_System_Collections_IList_set_Item_m1450941252_0 (Array_t * __this, int32_t ___index, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::System.Collections.IList.Add(System.Object)
extern "C"  int32_t Array_System_Collections_IList_Add_m_1195697622_0 (Array_t * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::System.Collections.IList.Clear()
extern "C"  void Array_System_Collections_IList_Clear_m412725562_0 (Array_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Array::System.Collections.IList.Contains(System.Object)
extern "C"  bool Array_System_Collections_IList_Contains_m_548015390_0 (Array_t * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::System.Collections.IList.IndexOf(System.Object)
extern "C"  int32_t Array_System_Collections_IList_IndexOf_m53357442_0 (Array_t * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::System.Collections.IList.Insert(System.Int32,System.Object)
extern "C"  void Array_System_Collections_IList_Insert_m_522033491_0 (Array_t * __this, int32_t ___index, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::System.Collections.IList.Remove(System.Object)
extern "C"  void Array_System_Collections_IList_Remove_m_158405285_0 (Array_t * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::System.Collections.IList.RemoveAt(System.Int32)
extern "C"  void Array_System_Collections_IList_RemoveAt_m969759165_0 (Array_t * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::System.Collections.ICollection.get_Count()
extern "C"  int32_t Array_System_Collections_ICollection_get_Count_m1062882991_0 (Array_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::InternalArray__ICollection_get_Count()
extern "C"  int32_t Array_InternalArray__ICollection_get_Count_m1680332058_0 (Array_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Array::InternalArray__ICollection_get_IsReadOnly()
extern "C"  bool Array_InternalArray__ICollection_get_IsReadOnly_m1501007613_0 (Array_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::InternalArray__ICollection_Clear()
extern "C"  void Array_InternalArray__ICollection_Clear_m474435621_0 (Array_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::InternalArray__RemoveAt(System.Int32)
extern "C"  void Array_InternalArray__RemoveAt_m907509114_0 (Array_t * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::get_Length()
extern "C"  int32_t Array_get_Length_m1203127607_0 (Array_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.Array::get_LongLength()
extern "C"  int64_t Array_get_LongLength_m1209728916_0 (Array_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::get_Rank()
extern "C"  int32_t Array_get_Rank_m1671008509_0 (Array_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::GetRank()
extern "C"  int32_t Array_GetRank_m_1486660996_0 (Array_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::GetLength(System.Int32)
extern "C"  int32_t Array_GetLength_m1450876743_0 (Array_t * __this, int32_t ___dimension, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.Array::GetLongLength(System.Int32)
extern "C"  int64_t Array_GetLongLength_m1044315650_0 (Array_t * __this, int32_t ___dimension, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::GetLowerBound(System.Int32)
extern "C"  int32_t Array_GetLowerBound_m_1925830754_0 (Array_t * __this, int32_t ___dimension, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Array::GetValue(System.Int32[])
extern "C"  Object_t * Array_GetValue_m_1538050485_0 (Array_t * __this, Int32U5BU5D_t1872284309_0* ___indices, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::SetValue(System.Object,System.Int32[])
extern "C"  void Array_SetValue_m_1992593220_0 (Array_t * __this, Object_t * ___value, Int32U5BU5D_t1872284309_0* ___indices, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Array::GetValueImpl(System.Int32)
extern "C"  Object_t * Array_GetValueImpl_m_959252691_0 (Array_t * __this, int32_t ___pos, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::SetValueImpl(System.Object,System.Int32)
extern "C"  void Array_SetValueImpl_m111809118_0 (Array_t * __this, Object_t * ___value, int32_t ___pos, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Array::FastCopy(System.Array,System.Int32,System.Array,System.Int32,System.Int32)
extern "C"  bool Array_FastCopy_m256067930_0 (Object_t * __this /* static, unused */, Array_t * ___source, int32_t ___source_idx, Array_t * ___dest, int32_t ___dest_idx, int32_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Array System.Array::CreateInstanceImpl(System.Type,System.Int32[],System.Int32[])
extern "C"  Array_t * Array_CreateInstanceImpl_m_984256693_0 (Object_t * __this /* static, unused */, Type_t * ___elementType, Int32U5BU5D_t1872284309_0* ___lengths, Int32U5BU5D_t1872284309_0* ___bounds, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Array::get_IsSynchronized()
extern "C"  bool Array_get_IsSynchronized_m_502858475_0 (Array_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Array::get_SyncRoot()
extern "C"  Object_t * Array_get_SyncRoot_m_447749753_0 (Array_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Array::get_IsFixedSize()
extern "C"  bool Array_get_IsFixedSize_m_1932137130_0 (Array_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Array::get_IsReadOnly()
extern "C"  bool Array_get_IsReadOnly_m_1825075485_0 (Array_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator System.Array::GetEnumerator()
extern "C"  Object_t * Array_GetEnumerator_m_1566232934_0 (Array_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::GetUpperBound(System.Int32)
extern "C"  int32_t Array_GetUpperBound_m97365085_0 (Array_t * __this, int32_t ___dimension, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Array::GetValue(System.Int32)
extern "C"  Object_t * Array_GetValue_m244209261_0 (Array_t * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Array::GetValue(System.Int32,System.Int32)
extern "C"  Object_t * Array_GetValue_m612327306_0 (Array_t * __this, int32_t ___index1, int32_t ___index2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Array::GetValue(System.Int32,System.Int32,System.Int32)
extern "C"  Object_t * Array_GetValue_m1617218957_0 (Array_t * __this, int32_t ___index1, int32_t ___index2, int32_t ___index3, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Array::GetValue(System.Int64)
extern "C"  Object_t * Array_GetValue_m244212206_0 (Array_t * __this, int64_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Array::GetValue(System.Int64,System.Int64)
extern "C"  Object_t * Array_GetValue_m2095831338_0 (Array_t * __this, int64_t ___index1, int64_t ___index2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Array::GetValue(System.Int64,System.Int64,System.Int64)
extern "C"  Object_t * Array_GetValue_m375587694_0 (Array_t * __this, int64_t ___index1, int64_t ___index2, int64_t ___index3, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::SetValue(System.Object,System.Int64)
extern "C"  void Array_SetValue_m_730561377_0 (Array_t * __this, Object_t * ___value, int64_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::SetValue(System.Object,System.Int64,System.Int64)
extern "C"  void Array_SetValue_m_1679466983_0 (Array_t * __this, Object_t * ___value, int64_t ___index1, int64_t ___index2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::SetValue(System.Object,System.Int64,System.Int64,System.Int64)
extern "C"  void Array_SetValue_m235879135_0 (Array_t * __this, Object_t * ___value, int64_t ___index1, int64_t ___index2, int64_t ___index3, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::SetValue(System.Object,System.Int32)
extern "C"  void Array_SetValue_m_730564322_0 (Array_t * __this, Object_t * ___value, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::SetValue(System.Object,System.Int32,System.Int32)
extern "C"  void Array_SetValue_m1131996281_0 (Array_t * __this, Object_t * ___value, int32_t ___index1, int32_t ___index2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::SetValue(System.Object,System.Int32,System.Int32,System.Int32)
extern "C"  void Array_SetValue_m1477510398_0 (Array_t * __this, Object_t * ___value, int32_t ___index1, int32_t ___index2, int32_t ___index3, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Array System.Array::CreateInstance(System.Type,System.Int32)
extern "C"  Array_t * Array_CreateInstance_m1364223436_0 (Object_t * __this /* static, unused */, Type_t * ___elementType, int32_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Array System.Array::CreateInstance(System.Type,System.Int32,System.Int32)
extern "C"  Array_t * Array_CreateInstance_m_1122270581_0 (Object_t * __this /* static, unused */, Type_t * ___elementType, int32_t ___length1, int32_t ___length2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Array System.Array::CreateInstance(System.Type,System.Int32,System.Int32,System.Int32)
extern "C"  Array_t * Array_CreateInstance_m_642296788_0 (Object_t * __this /* static, unused */, Type_t * ___elementType, int32_t ___length1, int32_t ___length2, int32_t ___length3, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Array System.Array::CreateInstance(System.Type,System.Int32[])
extern "C"  Array_t * Array_CreateInstance_m1053747690_0 (Object_t * __this /* static, unused */, Type_t * ___elementType, Int32U5BU5D_t1872284309_0* ___lengths, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Array System.Array::CreateInstance(System.Type,System.Int32[],System.Int32[])
extern "C"  Array_t * Array_CreateInstance_m814141195_0 (Object_t * __this /* static, unused */, Type_t * ___elementType, Int32U5BU5D_t1872284309_0* ___lengths, Int32U5BU5D_t1872284309_0* ___lowerBounds, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32[] System.Array::GetIntArray(System.Int64[])
extern "C"  Int32U5BU5D_t1872284309_0* Array_GetIntArray_m_1048363764_0 (Object_t * __this /* static, unused */, Int64U5BU5D_t1872375604_0* ___values, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Array System.Array::CreateInstance(System.Type,System.Int64[])
extern "C"  Array_t * Array_CreateInstance_m1056577835_0 (Object_t * __this /* static, unused */, Type_t * ___elementType, Int64U5BU5D_t1872375604_0* ___lengths, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Array::GetValue(System.Int64[])
extern "C"  Object_t * Array_GetValue_m_1535220340_0 (Array_t * __this, Int64U5BU5D_t1872375604_0* ___indices, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::SetValue(System.Object,System.Int64[])
extern "C"  void Array_SetValue_m_1989763075_0 (Array_t * __this, Object_t * ___value, Int64U5BU5D_t1872375604_0* ___indices, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::BinarySearch(System.Array,System.Object)
extern "C"  int32_t Array_BinarySearch_m183313925_0 (Object_t * __this /* static, unused */, Array_t * ___array, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::BinarySearch(System.Array,System.Object,System.Collections.IComparer)
extern "C"  int32_t Array_BinarySearch_m_1163442461_0 (Object_t * __this /* static, unused */, Array_t * ___array, Object_t * ___value, Object_t * ___comparer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::BinarySearch(System.Array,System.Int32,System.Int32,System.Object)
extern "C"  int32_t Array_BinarySearch_m2035084453_0 (Object_t * __this /* static, unused */, Array_t * ___array, int32_t ___index, int32_t ___length, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::BinarySearch(System.Array,System.Int32,System.Int32,System.Object,System.Collections.IComparer)
extern "C"  int32_t Array_BinarySearch_m_1253014461_0 (Object_t * __this /* static, unused */, Array_t * ___array, int32_t ___index, int32_t ___length, Object_t * ___value, Object_t * ___comparer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::DoBinarySearch(System.Array,System.Int32,System.Int32,System.Object,System.Collections.IComparer)
extern "C"  int32_t Array_DoBinarySearch_m1921037304_0 (Object_t * __this /* static, unused */, Array_t * ___array, int32_t ___index, int32_t ___length, Object_t * ___value, Object_t * ___comparer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::Clear(System.Array,System.Int32,System.Int32)
extern "C"  void Array_Clear_m_1795390263_0 (Object_t * __this /* static, unused */, Array_t * ___array, int32_t ___index, int32_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::ClearInternal(System.Array,System.Int32,System.Int32)
extern "C"  void Array_ClearInternal_m1225452710_0 (Object_t * __this /* static, unused */, Array_t * ___a, int32_t ___index, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Array::Clone()
extern "C"  Object_t * Array_Clone_m1369268734_0 (Array_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::Copy(System.Array,System.Array,System.Int32)
extern "C"  void Array_Copy_m_495658254_0 (Object_t * __this /* static, unused */, Array_t * ___sourceArray, Array_t * ___destinationArray, int32_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::Copy(System.Array,System.Int32,System.Array,System.Int32,System.Int32)
extern "C"  void Array_Copy_m_1696350628_0 (Object_t * __this /* static, unused */, Array_t * ___sourceArray, int32_t ___sourceIndex, Array_t * ___destinationArray, int32_t ___destinationIndex, int32_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::Copy(System.Array,System.Int64,System.Array,System.Int64,System.Int64)
extern "C"  void Array_Copy_m583019867_0 (Object_t * __this /* static, unused */, Array_t * ___sourceArray, int64_t ___sourceIndex, Array_t * ___destinationArray, int64_t ___destinationIndex, int64_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::Copy(System.Array,System.Array,System.Int64)
extern "C"  void Array_Copy_m_495655309_0 (Object_t * __this /* static, unused */, Array_t * ___sourceArray, Array_t * ___destinationArray, int64_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::IndexOf(System.Array,System.Object)
extern "C"  int32_t Array_IndexOf_m480670679_0 (Object_t * __this /* static, unused */, Array_t * ___array, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::IndexOf(System.Array,System.Object,System.Int32)
extern "C"  int32_t Array_IndexOf_m1662246496_0 (Object_t * __this /* static, unused */, Array_t * ___array, Object_t * ___value, int32_t ___startIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::IndexOf(System.Array,System.Object,System.Int32,System.Int32)
extern "C"  int32_t Array_IndexOf_m1794349687_0 (Object_t * __this /* static, unused */, Array_t * ___array, Object_t * ___value, int32_t ___startIndex, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::Initialize()
extern "C"  void Array_Initialize_m_1657581700_0 (Array_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::LastIndexOf(System.Array,System.Object)
extern "C"  int32_t Array_LastIndexOf_m673447137_0 (Object_t * __this /* static, unused */, Array_t * ___array, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::LastIndexOf(System.Array,System.Object,System.Int32)
extern "C"  int32_t Array_LastIndexOf_m776394134_0 (Object_t * __this /* static, unused */, Array_t * ___array, Object_t * ___value, int32_t ___startIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::LastIndexOf(System.Array,System.Object,System.Int32,System.Int32)
extern "C"  int32_t Array_LastIndexOf_m_2091742463_0 (Object_t * __this /* static, unused */, Array_t * ___array, Object_t * ___value, int32_t ___startIndex, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Array/Swapper System.Array::get_swapper(System.Array)
extern "C"  Swapper_t1012272441_0 * Array_get_swapper_m896107047_0 (Object_t * __this /* static, unused */, Array_t * ___array, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::Reverse(System.Array)
extern "C"  void Array_Reverse_m_864928962_0 (Object_t * __this /* static, unused */, Array_t * ___array, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::Reverse(System.Array,System.Int32,System.Int32)
extern "C"  void Array_Reverse_m_1230872802_0 (Object_t * __this /* static, unused */, Array_t * ___array, int32_t ___index, int32_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::Sort(System.Array)
extern "C"  void Array_Sort_m_678005200_0 (Object_t * __this /* static, unused */, Array_t * ___array, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::Sort(System.Array,System.Array)
extern "C"  void Array_Sort_m576952892_0 (Object_t * __this /* static, unused */, Array_t * ___keys, Array_t * ___items, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::Sort(System.Array,System.Collections.IComparer)
extern "C"  void Array_Sort_m_851391848_0 (Object_t * __this /* static, unused */, Array_t * ___array, Object_t * ___comparer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::Sort(System.Array,System.Int32,System.Int32)
extern "C"  void Array_Sort_m_382472304_0 (Object_t * __this /* static, unused */, Array_t * ___array, int32_t ___index, int32_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::Sort(System.Array,System.Array,System.Collections.IComparer)
extern "C"  void Array_Sort_m_2117193204_0 (Object_t * __this /* static, unused */, Array_t * ___keys, Array_t * ___items, Object_t * ___comparer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::Sort(System.Array,System.Array,System.Int32,System.Int32)
extern "C"  void Array_Sort_m870898844_0 (Object_t * __this /* static, unused */, Array_t * ___keys, Array_t * ___items, int32_t ___index, int32_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::Sort(System.Array,System.Int32,System.Int32,System.Collections.IComparer)
extern "C"  void Array_Sort_m2057456952_0 (Object_t * __this /* static, unused */, Array_t * ___array, int32_t ___index, int32_t ___length, Object_t * ___comparer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::Sort(System.Array,System.Array,System.Int32,System.Int32,System.Collections.IComparer)
extern "C"  void Array_Sort_m_9925716_0 (Object_t * __this /* static, unused */, Array_t * ___keys, Array_t * ___items, int32_t ___index, int32_t ___length, Object_t * ___comparer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::int_swapper(System.Int32,System.Int32)
extern "C"  void Array_int_swapper_m_1261208138_0 (Array_t * __this, int32_t ___i, int32_t ___j, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::obj_swapper(System.Int32,System.Int32)
extern "C"  void Array_obj_swapper_m_2039673938_0 (Array_t * __this, int32_t ___i, int32_t ___j, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::slow_swapper(System.Int32,System.Int32)
extern "C"  void Array_slow_swapper_m1091278254_0 (Array_t * __this, int32_t ___i, int32_t ___j, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::double_swapper(System.Int32,System.Int32)
extern "C"  void Array_double_swapper_m1951199390_0 (Array_t * __this, int32_t ___i, int32_t ___j, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::new_gap(System.Int32)
extern "C"  int32_t Array_new_gap_m_641580990_0 (Object_t * __this /* static, unused */, int32_t ___gap, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::combsort(System.Double[],System.Int32,System.Int32,System.Array/Swapper)
extern "C"  void Array_combsort_m_504936004_0 (Object_t * __this /* static, unused */, DoubleU5BU5D_t_1251569810_0* ___array, int32_t ___start, int32_t ___size, Swapper_t1012272441_0 * ___swap_items, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::combsort(System.Int32[],System.Int32,System.Int32,System.Array/Swapper)
extern "C"  void Array_combsort_m1119151831_0 (Object_t * __this /* static, unused */, Int32U5BU5D_t1872284309_0* ___array, int32_t ___start, int32_t ___size, Swapper_t1012272441_0 * ___swap_items, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::combsort(System.Char[],System.Int32,System.Int32,System.Array/Swapper)
extern "C"  void Array_combsort_m_43308479_0 (Object_t * __this /* static, unused */, CharU5BU5D_t_1225802637_0* ___array, int32_t ___start, int32_t ___size, Swapper_t1012272441_0 * ___swap_items, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::qsort(System.Array,System.Array,System.Int32,System.Int32,System.Collections.IComparer)
extern "C"  void Array_qsort_m_1676692345_0 (Object_t * __this /* static, unused */, Array_t * ___keys, Array_t * ___items, int32_t ___low0, int32_t ___high0, Object_t * ___comparer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::swap(System.Array,System.Array,System.Int32,System.Int32)
extern "C"  void Array_swap_m_921374745_0 (Object_t * __this /* static, unused */, Array_t * ___keys, Array_t * ___items, int32_t ___i, int32_t ___j, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Array::compare(System.Object,System.Object,System.Collections.IComparer)
extern "C"  int32_t Array_compare_m_434060859_0 (Object_t * __this /* static, unused */, Object_t * ___value1, Object_t * ___value2, Object_t * ___comparer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::CopyTo(System.Array,System.Int32)
extern "C"  void Array_CopyTo_m910233845_0 (Array_t * __this, Array_t * ___array, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::CopyTo(System.Array,System.Int64)
extern "C"  void Array_CopyTo_m910236790_0 (Array_t * __this, Array_t * ___array, int64_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Array::ConstrainedCopy(System.Array,System.Int32,System.Array,System.Int32,System.Int32)
extern "C"  void Array_ConstrainedCopy_m695713564_0 (Object_t * __this /* static, unused */, Array_t * ___sourceArray, int32_t ___sourceIndex, Array_t * ___destinationArray, int32_t ___destinationIndex, int32_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
