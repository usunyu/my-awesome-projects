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

// System.Collections.BitArray
struct BitArray_t588948896_0;
// System.Object
struct Object_t;
// System.Array
struct Array_t;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Collections.BitArray::.ctor(System.Collections.BitArray)
extern "C"  void BitArray__ctor_m_1093443202_0 (BitArray_t588948896_0 * __this, BitArray_t588948896_0 * ___bits, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.BitArray::.ctor(System.Int32)
extern "C"  void BitArray__ctor_m_96153535_0 (BitArray_t588948896_0 * __this, int32_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte System.Collections.BitArray::getByte(System.Int32)
extern "C"  uint8_t BitArray_getByte_m_1149939127_0 (BitArray_t588948896_0 * __this, int32_t ___byteIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.BitArray::get_Count()
extern "C"  int32_t BitArray_get_Count_m_933223664_0 (BitArray_t588948896_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.BitArray::get_IsSynchronized()
extern "C"  bool BitArray_get_IsSynchronized_m1429626361_0 (BitArray_t588948896_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.BitArray::get_Item(System.Int32)
extern "C"  bool BitArray_get_Item_m_1884372673_0 (BitArray_t588948896_0 * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.BitArray::set_Item(System.Int32,System.Boolean)
extern "C"  void BitArray_set_Item_m_347643928_0 (BitArray_t588948896_0 * __this, int32_t ___index, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.BitArray::get_Length()
extern "C"  int32_t BitArray_get_Length_m_851648089_0 (BitArray_t588948896_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Collections.BitArray::get_SyncRoot()
extern "C"  Object_t * BitArray_get_SyncRoot_m_1579544795_0 (BitArray_t588948896_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Collections.BitArray::Clone()
extern "C"  Object_t * BitArray_Clone_m_1433785824_0 (BitArray_t588948896_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.BitArray::CopyTo(System.Array,System.Int32)
extern "C"  void BitArray_CopyTo_m_280944691_0 (BitArray_t588948896_0 * __this, Array_t * ___array, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.BitArray::Get(System.Int32)
extern "C"  bool BitArray_Get_m_403610633_0 (BitArray_t588948896_0 * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.BitArray::Set(System.Int32,System.Boolean)
extern "C"  void BitArray_Set_m_977813284_0 (BitArray_t588948896_0 * __this, int32_t ___index, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator System.Collections.BitArray::GetEnumerator()
extern "C"  Object_t * BitArray_GetEnumerator_m_316806178_0 (BitArray_t588948896_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
