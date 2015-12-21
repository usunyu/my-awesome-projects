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

// System.Collections.SortedList
struct SortedList_t480267343_0;
// System.Collections.IComparer
struct IComparer_t622777826_0;
// System.Collections.IDictionary
struct IDictionary_t_1514320629_0;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;
// System.Object
struct Object_t;
// System.Collections.IDictionaryEnumerator
struct IDictionaryEnumerator_t_855216337_0;
// System.Array
struct Array_t;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Collections.SortedList::.ctor()
extern "C"  void SortedList__ctor_m_591748639_0 (SortedList_t480267343_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.SortedList::.ctor(System.Int32)
extern "C"  void SortedList__ctor_m_1266184782_0 (SortedList_t480267343_0 * __this, int32_t ___initialCapacity, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.SortedList::.ctor(System.Collections.IComparer,System.Int32)
extern "C"  void SortedList__ctor_m690679828_0 (SortedList_t480267343_0 * __this, Object_t * ___comparer, int32_t ___capacity, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.SortedList::.ctor(System.Collections.IDictionary,System.Collections.IComparer)
extern "C"  void SortedList__ctor_m37047406_0 (SortedList_t480267343_0 * __this, Object_t * ___d, Object_t * ___comparer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.SortedList::.cctor()
extern "C"  void SortedList__cctor_m_1646434836_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator System.Collections.SortedList::System.Collections.IEnumerable.GetEnumerator()
extern "C"  Object_t * SortedList_System_Collections_IEnumerable_GetEnumerator_m76581074_0 (SortedList_t480267343_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.SortedList::get_Count()
extern "C"  int32_t SortedList_get_Count_m418925185_0 (SortedList_t480267343_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.SortedList::get_IsSynchronized()
extern "C"  bool SortedList_get_IsSynchronized_m_1588791512_0 (SortedList_t480267343_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Collections.SortedList::get_SyncRoot()
extern "C"  Object_t * SortedList_get_SyncRoot_m808976468_0 (SortedList_t480267343_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.SortedList::get_IsFixedSize()
extern "C"  bool SortedList_get_IsFixedSize_m296838179_0 (SortedList_t480267343_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.SortedList::get_IsReadOnly()
extern "C"  bool SortedList_get_IsReadOnly_m47942262_0 (SortedList_t480267343_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Collections.SortedList::get_Item(System.Object)
extern "C"  Object_t * SortedList_get_Item_m_381279478_0 (SortedList_t480267343_0 * __this, Object_t * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.SortedList::set_Item(System.Object,System.Object)
extern "C"  void SortedList_set_Item_m_1273394577_0 (SortedList_t480267343_0 * __this, Object_t * ___key, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.SortedList::get_Capacity()
extern "C"  int32_t SortedList_get_Capacity_m_641294998_0 (SortedList_t480267343_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.SortedList::set_Capacity(System.Int32)
extern "C"  void SortedList_set_Capacity_m1257766347_0 (SortedList_t480267343_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.SortedList::Add(System.Object,System.Object)
extern "C"  void SortedList_Add_m_854742398_0 (SortedList_t480267343_0 * __this, Object_t * ___key, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.SortedList::Contains(System.Object)
extern "C"  bool SortedList_Contains_m_2072748620_0 (SortedList_t480267343_0 * __this, Object_t * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IDictionaryEnumerator System.Collections.SortedList::GetEnumerator()
extern "C"  Object_t * SortedList_GetEnumerator_m201395865_0 (SortedList_t480267343_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.SortedList::Remove(System.Object)
extern "C"  void SortedList_Remove_m_1263222099_0 (SortedList_t480267343_0 * __this, Object_t * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.SortedList::CopyTo(System.Array,System.Int32)
extern "C"  void SortedList_CopyTo_m894370686_0 (SortedList_t480267343_0 * __this, Array_t * ___array, int32_t ___arrayIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Collections.SortedList::Clone()
extern "C"  Object_t * SortedList_Clone_m_1310810159_0 (SortedList_t480267343_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.SortedList::RemoveAt(System.Int32)
extern "C"  void SortedList_RemoveAt_m1080176299_0 (SortedList_t480267343_0 * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.SortedList::IndexOfKey(System.Object)
extern "C"  int32_t SortedList_IndexOfKey_m_1280616777_0 (SortedList_t480267343_0 * __this, Object_t * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.SortedList::ContainsKey(System.Object)
extern "C"  bool SortedList_ContainsKey_m_98310413_0 (SortedList_t480267343_0 * __this, Object_t * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Collections.SortedList::GetByIndex(System.Int32)
extern "C"  Object_t * SortedList_GetByIndex_m_968231356_0 (SortedList_t480267343_0 * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.SortedList::EnsureCapacity(System.Int32,System.Int32)
extern "C"  void SortedList_EnsureCapacity_m_831021653_0 (SortedList_t480267343_0 * __this, int32_t ___n, int32_t ___free, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.SortedList::PutImpl(System.Object,System.Object,System.Boolean)
extern "C"  void SortedList_PutImpl_m1191987689_0 (SortedList_t480267343_0 * __this, Object_t * ___key, Object_t * ___value, bool ___overwrite, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Collections.SortedList::GetImpl(System.Object)
extern "C"  Object_t * SortedList_GetImpl_m_576315446_0 (SortedList_t480267343_0 * __this, Object_t * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.SortedList::InitTable(System.Int32,System.Boolean)
extern "C"  void SortedList_InitTable_m1786490575_0 (SortedList_t480267343_0 * __this, int32_t ___capacity, bool ___forceSize, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.SortedList::Find(System.Object)
extern "C"  int32_t SortedList_Find_m658979188_0 (SortedList_t480267343_0 * __this, Object_t * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
