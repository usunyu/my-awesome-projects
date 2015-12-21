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

// System.Collections.CollectionBase
struct CollectionBase_t_1398170653_0;
// System.Array
struct Array_t;
// System.Object
struct Object_t;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;
// System.Collections.ArrayList
struct ArrayList_t536890563_0;
// System.Collections.IList
struct IList_t_1078834989_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Collections.CollectionBase::.ctor()
extern "C"  void CollectionBase__ctor_m_1113953715_0 (CollectionBase_t_1398170653_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.CollectionBase::System.Collections.ICollection.CopyTo(System.Array,System.Int32)
extern "C"  void CollectionBase_System_Collections_ICollection_CopyTo_m634775447_0 (CollectionBase_t_1398170653_0 * __this, Array_t * ___array, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Collections.CollectionBase::System.Collections.ICollection.get_SyncRoot()
extern "C"  Object_t * CollectionBase_System_Collections_ICollection_get_SyncRoot_m_333956699_0 (CollectionBase_t_1398170653_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.CollectionBase::System.Collections.ICollection.get_IsSynchronized()
extern "C"  bool CollectionBase_System_Collections_ICollection_get_IsSynchronized_m1284188723_0 (CollectionBase_t_1398170653_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.CollectionBase::System.Collections.IList.Add(System.Object)
extern "C"  int32_t CollectionBase_System_Collections_IList_Add_m161097623_0 (CollectionBase_t_1398170653_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.CollectionBase::System.Collections.IList.Contains(System.Object)
extern "C"  bool CollectionBase_System_Collections_IList_Contains_m_1733167991_0 (CollectionBase_t_1398170653_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.CollectionBase::System.Collections.IList.IndexOf(System.Object)
extern "C"  int32_t CollectionBase_System_Collections_IList_IndexOf_m_1983989137_0 (CollectionBase_t_1398170653_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.CollectionBase::System.Collections.IList.Insert(System.Int32,System.Object)
extern "C"  void CollectionBase_System_Collections_IList_Insert_m917928546_0 (CollectionBase_t_1398170653_0 * __this, int32_t ___index, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.CollectionBase::System.Collections.IList.Remove(System.Object)
extern "C"  void CollectionBase_System_Collections_IList_Remove_m872150918_0 (CollectionBase_t_1398170653_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.CollectionBase::System.Collections.IList.get_IsFixedSize()
extern "C"  bool CollectionBase_System_Collections_IList_get_IsFixedSize_m_1370882376_0 (CollectionBase_t_1398170653_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.CollectionBase::System.Collections.IList.get_IsReadOnly()
extern "C"  bool CollectionBase_System_Collections_IList_get_IsReadOnly_m271239489_0 (CollectionBase_t_1398170653_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Collections.CollectionBase::System.Collections.IList.get_Item(System.Int32)
extern "C"  Object_t * CollectionBase_System_Collections_IList_get_Item_m_2039196180_0 (CollectionBase_t_1398170653_0 * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.CollectionBase::System.Collections.IList.set_Item(System.Int32,System.Object)
extern "C"  void CollectionBase_System_Collections_IList_set_Item_m_2019977799_0 (CollectionBase_t_1398170653_0 * __this, int32_t ___index, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.CollectionBase::get_Count()
extern "C"  int32_t CollectionBase_get_Count_m313265901_0 (CollectionBase_t_1398170653_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator System.Collections.CollectionBase::GetEnumerator()
extern "C"  Object_t * CollectionBase_GetEnumerator_m661855675_0 (CollectionBase_t_1398170653_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.CollectionBase::Clear()
extern "C"  void CollectionBase_Clear_m587146872_0 (CollectionBase_t_1398170653_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.CollectionBase::RemoveAt(System.Int32)
extern "C"  void CollectionBase_RemoveAt_m_998047553_0 (CollectionBase_t_1398170653_0 * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.ArrayList System.Collections.CollectionBase::get_InnerList()
extern "C"  ArrayList_t536890563_0 * CollectionBase_get_InnerList_m_1454087326_0 (CollectionBase_t_1398170653_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IList System.Collections.CollectionBase::get_List()
extern "C"  Object_t * CollectionBase_get_List_m_1763701054_0 (CollectionBase_t_1398170653_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.CollectionBase::OnClear()
extern "C"  void CollectionBase_OnClear_m777794841_0 (CollectionBase_t_1398170653_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.CollectionBase::OnClearComplete()
extern "C"  void CollectionBase_OnClearComplete_m606486578_0 (CollectionBase_t_1398170653_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.CollectionBase::OnInsert(System.Int32,System.Object)
extern "C"  void CollectionBase_OnInsert_m_21270674_0 (CollectionBase_t_1398170653_0 * __this, int32_t ___index, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.CollectionBase::OnInsertComplete(System.Int32,System.Object)
extern "C"  void CollectionBase_OnInsertComplete_m722388807_0 (CollectionBase_t_1398170653_0 * __this, int32_t ___index, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.CollectionBase::OnRemove(System.Int32,System.Object)
extern "C"  void CollectionBase_OnRemove_m_281127239_0 (CollectionBase_t_1398170653_0 * __this, int32_t ___index, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.CollectionBase::OnRemoveComplete(System.Int32,System.Object)
extern "C"  void CollectionBase_OnRemoveComplete_m_1446562926_0 (CollectionBase_t_1398170653_0 * __this, int32_t ___index, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.CollectionBase::OnSet(System.Int32,System.Object,System.Object)
extern "C"  void CollectionBase_OnSet_m_719642213_0 (CollectionBase_t_1398170653_0 * __this, int32_t ___index, Object_t * ___oldValue, Object_t * ___newValue, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.CollectionBase::OnSetComplete(System.Int32,System.Object,System.Object)
extern "C"  void CollectionBase_OnSetComplete_m_2089485644_0 (CollectionBase_t_1398170653_0 * __this, int32_t ___index, Object_t * ___oldValue, Object_t * ___newValue, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.CollectionBase::OnValidate(System.Object)
extern "C"  void CollectionBase_OnValidate_m_1862475416_0 (CollectionBase_t_1398170653_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
