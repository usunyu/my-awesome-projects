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

// System.Collections.ArrayList/ArrayListWrapper
struct ArrayListWrapper_t1873545704_0;
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

// System.Void System.Collections.ArrayList/ArrayListWrapper::.ctor(System.Collections.ArrayList)
extern "C"  void ArrayListWrapper__ctor_m_1763846423_0 (ArrayListWrapper_t1873545704_0 * __this, ArrayList_t536890563_0 * ___innerArrayList, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Collections.ArrayList/ArrayListWrapper::get_Item(System.Int32)
extern "C"  Object_t * ArrayListWrapper_get_Item_m_236989516_0 (ArrayListWrapper_t1873545704_0 * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/ArrayListWrapper::set_Item(System.Int32,System.Object)
extern "C"  void ArrayListWrapper_set_Item_m602076299_0 (ArrayListWrapper_t1873545704_0 * __this, int32_t ___index, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.ArrayList/ArrayListWrapper::get_Count()
extern "C"  int32_t ArrayListWrapper_get_Count_m452148104_0 (ArrayListWrapper_t1873545704_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.ArrayList/ArrayListWrapper::get_Capacity()
extern "C"  int32_t ArrayListWrapper_get_Capacity_m1260206851_0 (ArrayListWrapper_t1873545704_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/ArrayListWrapper::set_Capacity(System.Int32)
extern "C"  void ArrayListWrapper_set_Capacity_m_2106243612_0 (ArrayListWrapper_t1873545704_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.ArrayList/ArrayListWrapper::get_IsFixedSize()
extern "C"  bool ArrayListWrapper_get_IsFixedSize_m_924801046_0 (ArrayListWrapper_t1873545704_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.ArrayList/ArrayListWrapper::get_IsReadOnly()
extern "C"  bool ArrayListWrapper_get_IsReadOnly_m2086744527_0 (ArrayListWrapper_t1873545704_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.ArrayList/ArrayListWrapper::get_IsSynchronized()
extern "C"  bool ArrayListWrapper_get_IsSynchronized_m109922817_0 (ArrayListWrapper_t1873545704_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Collections.ArrayList/ArrayListWrapper::get_SyncRoot()
extern "C"  Object_t * ArrayListWrapper_get_SyncRoot_m427241453_0 (ArrayListWrapper_t1873545704_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.ArrayList/ArrayListWrapper::Add(System.Object)
extern "C"  int32_t ArrayListWrapper_Add_m_136617167_0 (ArrayListWrapper_t1873545704_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/ArrayListWrapper::Clear()
extern "C"  void ArrayListWrapper_Clear_m_764697965_0 (ArrayListWrapper_t1873545704_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.ArrayList/ArrayListWrapper::Contains(System.Object)
extern "C"  bool ArrayListWrapper_Contains_m1021145147_0 (ArrayListWrapper_t1873545704_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.ArrayList/ArrayListWrapper::IndexOf(System.Object)
extern "C"  int32_t ArrayListWrapper_IndexOf_m_1218143991_0 (ArrayListWrapper_t1873545704_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.ArrayList/ArrayListWrapper::IndexOf(System.Object,System.Int32)
extern "C"  int32_t ArrayListWrapper_IndexOf_m_661964178_0 (ArrayListWrapper_t1873545704_0 * __this, Object_t * ___value, int32_t ___startIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.ArrayList/ArrayListWrapper::IndexOf(System.Object,System.Int32,System.Int32)
extern "C"  int32_t ArrayListWrapper_IndexOf_m_579680983_0 (ArrayListWrapper_t1873545704_0 * __this, Object_t * ___value, int32_t ___startIndex, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/ArrayListWrapper::Insert(System.Int32,System.Object)
extern "C"  void ArrayListWrapper_Insert_m218981812_0 (ArrayListWrapper_t1873545704_0 * __this, int32_t ___index, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/ArrayListWrapper::InsertRange(System.Int32,System.Collections.ICollection)
extern "C"  void ArrayListWrapper_InsertRange_m1261127932_0 (ArrayListWrapper_t1873545704_0 * __this, int32_t ___index, Object_t * ___c, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/ArrayListWrapper::Remove(System.Object)
extern "C"  void ArrayListWrapper_Remove_m2062487284_0 (ArrayListWrapper_t1873545704_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/ArrayListWrapper::RemoveAt(System.Int32)
extern "C"  void ArrayListWrapper_RemoveAt_m1097952068_0 (ArrayListWrapper_t1873545704_0 * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/ArrayListWrapper::CopyTo(System.Array)
extern "C"  void ArrayListWrapper_CopyTo_m26666194_0 (ArrayListWrapper_t1873545704_0 * __this, Array_t * ___array, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/ArrayListWrapper::CopyTo(System.Array,System.Int32)
extern "C"  void ArrayListWrapper_CopyTo_m_2133975739_0 (ArrayListWrapper_t1873545704_0 * __this, Array_t * ___array, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/ArrayListWrapper::CopyTo(System.Int32,System.Array,System.Int32,System.Int32)
extern "C"  void ArrayListWrapper_CopyTo_m127332079_0 (ArrayListWrapper_t1873545704_0 * __this, int32_t ___index, Array_t * ___array, int32_t ___arrayIndex, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator System.Collections.ArrayList/ArrayListWrapper::GetEnumerator()
extern "C"  Object_t * ArrayListWrapper_GetEnumerator_m568286678_0 (ArrayListWrapper_t1873545704_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/ArrayListWrapper::AddRange(System.Collections.ICollection)
extern "C"  void ArrayListWrapper_AddRange_m819293673_0 (ArrayListWrapper_t1873545704_0 * __this, Object_t * ___c, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Collections.ArrayList/ArrayListWrapper::Clone()
extern "C"  Object_t * ArrayListWrapper_Clone_m1229511256_0 (ArrayListWrapper_t1873545704_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/ArrayListWrapper::Sort()
extern "C"  void ArrayListWrapper_Sort_m20930554_0 (ArrayListWrapper_t1873545704_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.ArrayList/ArrayListWrapper::Sort(System.Collections.IComparer)
extern "C"  void ArrayListWrapper_Sort_m408534076_0 (ArrayListWrapper_t1873545704_0 * __this, Object_t * ___comparer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.Collections.ArrayList/ArrayListWrapper::ToArray()
extern "C"  ObjectU5BU5D_t1774424924_0* ArrayListWrapper_ToArray_m1651255351_0 (ArrayListWrapper_t1873545704_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Array System.Collections.ArrayList/ArrayListWrapper::ToArray(System.Type)
extern "C"  Array_t * ArrayListWrapper_ToArray_m_1519665596_0 (ArrayListWrapper_t1873545704_0 * __this, Type_t * ___elementType, const MethodInfo* method) IL2CPP_METHOD_ATTR;
