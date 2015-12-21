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

// System.Text.RegularExpressions.GroupCollection
struct GroupCollection_t304579722_0;
// System.Text.RegularExpressions.Group
struct Group_t933988556_0;
// System.Object
struct Object_t;
// System.Array
struct Array_t;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Text.RegularExpressions.GroupCollection::.ctor(System.Int32,System.Int32)
extern "C"  void GroupCollection__ctor_m1062211994_0 (GroupCollection_t304579722_0 * __this, int32_t ___n, int32_t ___gap, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.RegularExpressions.GroupCollection::get_Count()
extern "C"  int32_t GroupCollection_get_Count_m1046622944_0 (GroupCollection_t304579722_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.GroupCollection::get_IsSynchronized()
extern "C"  bool GroupCollection_get_IsSynchronized_m_707717195_0 (GroupCollection_t304579722_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.RegularExpressions.Group System.Text.RegularExpressions.GroupCollection::get_Item(System.Int32)
extern "C"  Group_t933988556_0 * GroupCollection_get_Item_m_988058318_0 (GroupCollection_t304579722_0 * __this, int32_t ___i, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.GroupCollection::SetValue(System.Text.RegularExpressions.Group,System.Int32)
extern "C"  void GroupCollection_SetValue_m_566554206_0 (GroupCollection_t304579722_0 * __this, Group_t933988556_0 * ___g, int32_t ___i, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Text.RegularExpressions.GroupCollection::get_SyncRoot()
extern "C"  Object_t * GroupCollection_get_SyncRoot_m63200083_0 (GroupCollection_t304579722_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.GroupCollection::CopyTo(System.Array,System.Int32)
extern "C"  void GroupCollection_CopyTo_m_630982423_0 (GroupCollection_t304579722_0 * __this, Array_t * ___array, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator System.Text.RegularExpressions.GroupCollection::GetEnumerator()
extern "C"  Object_t * GroupCollection_GetEnumerator_m1787152634_0 (GroupCollection_t304579722_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
