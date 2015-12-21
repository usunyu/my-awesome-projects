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

// System.Collections.ArrayList/SynchronizedArrayListWrapper
struct SynchronizedArrayListWrapper_t1148234012_0;
// System.Collections.ArrayList
struct ArrayList_t536890563_0;
// System.Object
struct Object_t;
// System.Collections.ICollection
struct ICollection_t592284435_0;
// System.Array
struct Array_t;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;
// System.Collections.IComparer
struct IComparer_t622777826_0;
// System.Object[]
struct ObjectU5BU5D_t1774424924_0;
// System.Type
struct Type_t;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Collections.ArrayList/SynchronizedArrayListWrapper::.ctor(System.Collections.ArrayList)
extern "C"  void SynchronizedArrayListWrapper__ctor_m_153232203_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, ArrayList_t536890563_0 * ___innerArrayList, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Collections.ArrayList/SynchronizedArrayListWrapper::get_Item(System.Int32)
extern "C"  Object_t * SynchronizedArrayListWrapper_get_Item_m678734312_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/SynchronizedArrayListWrapper::set_Item(System.Int32,System.Object)
extern "C"  void SynchronizedArrayListWrapper_set_Item_m_1008490433_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, int32_t ___index, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.ArrayList/SynchronizedArrayListWrapper::get_Count()
extern "C"  int32_t SynchronizedArrayListWrapper_get_Count_m_604234924_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.ArrayList/SynchronizedArrayListWrapper::get_Capacity()
extern "C"  int32_t SynchronizedArrayListWrapper_get_Capacity_m_221202505_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/SynchronizedArrayListWrapper::set_Capacity(System.Int32)
extern "C"  void SynchronizedArrayListWrapper_set_Capacity_m_1059239272_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.ArrayList/SynchronizedArrayListWrapper::get_IsFixedSize()
extern "C"  bool SynchronizedArrayListWrapper_get_IsFixedSize_m954881462_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.ArrayList/SynchronizedArrayListWrapper::get_IsReadOnly()
extern "C"  bool SynchronizedArrayListWrapper_get_IsReadOnly_m_1731945853_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.ArrayList/SynchronizedArrayListWrapper::get_IsSynchronized()
extern "C"  bool SynchronizedArrayListWrapper_get_IsSynchronized_m_52086603_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Collections.ArrayList/SynchronizedArrayListWrapper::get_SyncRoot()
extern "C"  Object_t * SynchronizedArrayListWrapper_get_SyncRoot_m_2112914911_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.ArrayList/SynchronizedArrayListWrapper::Add(System.Object)
extern "C"  int32_t SynchronizedArrayListWrapper_Add_m1801020901_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/SynchronizedArrayListWrapper::Clear()
extern "C"  void SynchronizedArrayListWrapper_Clear_m967709279_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.ArrayList/SynchronizedArrayListWrapper::Contains(System.Object)
extern "C"  bool SynchronizedArrayListWrapper_Contains_m2141754631_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.ArrayList/SynchronizedArrayListWrapper::IndexOf(System.Object)
extern "C"  int32_t SynchronizedArrayListWrapper_IndexOf_m1643782589_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.ArrayList/SynchronizedArrayListWrapper::IndexOf(System.Object,System.Int32)
extern "C"  int32_t SynchronizedArrayListWrapper_IndexOf_m1797551674_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, Object_t * ___value, int32_t ___startIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.ArrayList/SynchronizedArrayListWrapper::IndexOf(System.Object,System.Int32,System.Int32)
extern "C"  int32_t SynchronizedArrayListWrapper_IndexOf_m632165597_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, Object_t * ___value, int32_t ___startIndex, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/SynchronizedArrayListWrapper::Insert(System.Int32,System.Object)
extern "C"  void SynchronizedArrayListWrapper_Insert_m_1253083544_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, int32_t ___index, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/SynchronizedArrayListWrapper::InsertRange(System.Int32,System.Collections.ICollection)
extern "C"  void SynchronizedArrayListWrapper_InsertRange_m_1168041296_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, int32_t ___index, Object_t * ___c, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/SynchronizedArrayListWrapper::Remove(System.Object)
extern "C"  void SynchronizedArrayListWrapper_Remove_m_996415040_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/SynchronizedArrayListWrapper::RemoveAt(System.Int32)
extern "C"  void SynchronizedArrayListWrapper_RemoveAt_m761260536_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/SynchronizedArrayListWrapper::CopyTo(System.Array)
extern "C"  void SynchronizedArrayListWrapper_CopyTo_m482181254_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, Array_t * ___array, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/SynchronizedArrayListWrapper::CopyTo(System.Array,System.Int32)
extern "C"  void SynchronizedArrayListWrapper_CopyTo_m1282221585_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, Array_t * ___array, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/SynchronizedArrayListWrapper::CopyTo(System.Int32,System.Array,System.Int32,System.Int32)
extern "C"  void SynchronizedArrayListWrapper_CopyTo_m_1349168965_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, int32_t ___index, Array_t * ___array, int32_t ___arrayIndex, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator System.Collections.ArrayList/SynchronizedArrayListWrapper::GetEnumerator()
extern "C"  Object_t * SynchronizedArrayListWrapper_GetEnumerator_m1865470114_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/SynchronizedArrayListWrapper::AddRange(System.Collections.ICollection)
extern "C"  void SynchronizedArrayListWrapper_AddRange_m_1255331939_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, Object_t * ___c, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Collections.ArrayList/SynchronizedArrayListWrapper::Clone()
extern "C"  Object_t * SynchronizedArrayListWrapper_Clone_m_202317148_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/SynchronizedArrayListWrapper::Sort()
extern "C"  void SynchronizedArrayListWrapper_Sort_m_615922002_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/SynchronizedArrayListWrapper::Sort(System.Collections.IComparer)
extern "C"  void SynchronizedArrayListWrapper_Sort_m_1063531280_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, Object_t * ___comparer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.Collections.ArrayList/SynchronizedArrayListWrapper::ToArray()
extern "C"  ObjectU5BU5D_t1774424924_0* SynchronizedArrayListWrapper_ToArray_m1930965123_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Array System.Collections.ArrayList/SynchronizedArrayListWrapper::ToArray(System.Type)
extern "C"  Array_t * SynchronizedArrayListWrapper_ToArray_m_1204171912_0 (SynchronizedArrayListWrapper_t1148234012_0 * __this, Type_t * ___elementType, const MethodInfo* method) IL2CPP_METHOD_ATTR;
