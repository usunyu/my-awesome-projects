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

// System.Text.StringBuilder
struct StringBuilder_t586045924_0;
// System.String
struct String_t;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;
// System.Object
struct Object_t;
// System.Char[]
struct CharU5BU5D_t_1225802637_0;
// System.Object[]
struct ObjectU5BU5D_t1774424924_0;
// System.IFormatProvider
struct IFormatProvider_t_1172917514_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"

// System.Void System.Text.StringBuilder::.ctor(System.String,System.Int32,System.Int32,System.Int32)
extern "C"  void StringBuilder__ctor_m_263667039_0 (StringBuilder_t586045924_0 * __this, String_t* ___value, int32_t ___startIndex, int32_t ___length, int32_t ___capacity, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.StringBuilder::.ctor(System.String,System.Int32,System.Int32,System.Int32,System.Int32)
extern "C"  void StringBuilder__ctor_m_752785450_0 (StringBuilder_t586045924_0 * __this, String_t* ___value, int32_t ___startIndex, int32_t ___length, int32_t ___capacity, int32_t ___maxCapacity, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.StringBuilder::.ctor()
extern "C"  void StringBuilder__ctor_m135953004_0 (StringBuilder_t586045924_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.StringBuilder::.ctor(System.Int32)
extern "C"  void StringBuilder__ctor_m_670569027_0 (StringBuilder_t586045924_0 * __this, int32_t ___capacity, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.StringBuilder::.ctor(System.String)
extern "C"  void StringBuilder__ctor_m1143895062_0 (StringBuilder_t586045924_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.StringBuilder::.ctor(System.String,System.Int32)
extern "C"  void StringBuilder__ctor_m1310751873_0 (StringBuilder_t586045924_0 * __this, String_t* ___value, int32_t ___capacity, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.StringBuilder::.ctor(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void StringBuilder__ctor_m_511557203_0 (StringBuilder_t586045924_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.StringBuilder::System.Runtime.Serialization.ISerializable.GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void StringBuilder_System_Runtime_Serialization_ISerializable_GetObjectData_m_1385070433_0 (StringBuilder_t586045924_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.StringBuilder::get_Capacity()
extern "C"  int32_t StringBuilder_get_Capacity_m884438143_0 (StringBuilder_t586045924_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.StringBuilder::set_Capacity(System.Int32)
extern "C"  void StringBuilder_set_Capacity_m519605088_0 (StringBuilder_t586045924_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.StringBuilder::get_Length()
extern "C"  int32_t StringBuilder_get_Length_m_1851834197_0 (StringBuilder_t586045924_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.StringBuilder::set_Length(System.Int32)
extern "C"  void StringBuilder_set_Length_m1952332172_0 (StringBuilder_t586045924_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Char System.Text.StringBuilder::get_Chars(System.Int32)
extern "C"  uint16_t StringBuilder_get_Chars_m1670994701_0 (StringBuilder_t586045924_0 * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.StringBuilder::set_Chars(System.Int32,System.Char)
extern "C"  void StringBuilder_set_Chars_m1845996850_0 (StringBuilder_t586045924_0 * __this, int32_t ___index, uint16_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Text.StringBuilder::ToString()
extern "C"  String_t* StringBuilder_ToString_m350379841_0 (StringBuilder_t586045924_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Text.StringBuilder::ToString(System.Int32,System.Int32)
extern "C"  String_t* StringBuilder_ToString_m_673911035_0 (StringBuilder_t586045924_0 * __this, int32_t ___startIndex, int32_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.StringBuilder System.Text.StringBuilder::Remove(System.Int32,System.Int32)
extern "C"  StringBuilder_t586045924_0 * StringBuilder_Remove_m970775893_0 (StringBuilder_t586045924_0 * __this, int32_t ___startIndex, int32_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.StringBuilder System.Text.StringBuilder::Replace(System.String,System.String)
extern "C"  StringBuilder_t586045924_0 * StringBuilder_Replace_m118777941_0 (StringBuilder_t586045924_0 * __this, String_t* ___oldValue, String_t* ___newValue, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.StringBuilder System.Text.StringBuilder::Replace(System.String,System.String,System.Int32,System.Int32)
extern "C"  StringBuilder_t586045924_0 * StringBuilder_Replace_m1895746933_0 (StringBuilder_t586045924_0 * __this, String_t* ___oldValue, String_t* ___newValue, int32_t ___startIndex, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.StringBuilder System.Text.StringBuilder::Append(System.String)
extern "C"  StringBuilder_t586045924_0 * StringBuilder_Append_m_396877221_0 (StringBuilder_t586045924_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.StringBuilder System.Text.StringBuilder::Append(System.Int32)
extern "C"  StringBuilder_t586045924_0 * StringBuilder_Append_m_2105744680_0 (StringBuilder_t586045924_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.StringBuilder System.Text.StringBuilder::Append(System.Int64)
extern "C"  StringBuilder_t586045924_0 * StringBuilder_Append_m_2105741735_0 (StringBuilder_t586045924_0 * __this, int64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.StringBuilder System.Text.StringBuilder::Append(System.Object)
extern "C"  StringBuilder_t586045924_0 * StringBuilder_Append_m_174766867_0 (StringBuilder_t586045924_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.StringBuilder System.Text.StringBuilder::Append(System.Char)
extern "C"  StringBuilder_t586045924_0 * StringBuilder_Append_m2143093878_0 (StringBuilder_t586045924_0 * __this, uint16_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.StringBuilder System.Text.StringBuilder::Append(System.Char,System.Int32)
extern "C"  StringBuilder_t586045924_0 * StringBuilder_Append_m1038583841_0 (StringBuilder_t586045924_0 * __this, uint16_t ___value, int32_t ___repeatCount, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.StringBuilder System.Text.StringBuilder::Append(System.Char[],System.Int32,System.Int32)
extern "C"  StringBuilder_t586045924_0 * StringBuilder_Append_m_1671812492_0 (StringBuilder_t586045924_0 * __this, CharU5BU5D_t_1225802637_0* ___value, int32_t ___startIndex, int32_t ___charCount, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.StringBuilder System.Text.StringBuilder::Append(System.String,System.Int32,System.Int32)
extern "C"  StringBuilder_t586045924_0 * StringBuilder_Append_m_1298895877_0 (StringBuilder_t586045924_0 * __this, String_t* ___value, int32_t ___startIndex, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.StringBuilder System.Text.StringBuilder::AppendLine()
extern "C"  StringBuilder_t586045924_0 * StringBuilder_AppendLine_m568622107_0 (StringBuilder_t586045924_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.StringBuilder System.Text.StringBuilder::AppendLine(System.String)
extern "C"  StringBuilder_t586045924_0 * StringBuilder_AppendLine_m655025863_0 (StringBuilder_t586045924_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.StringBuilder System.Text.StringBuilder::AppendFormat(System.String,System.Object[])
extern "C"  StringBuilder_t586045924_0 * StringBuilder_AppendFormat_m279545936_0 (StringBuilder_t586045924_0 * __this, String_t* ___format, ObjectU5BU5D_t1774424924_0* ___args, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.StringBuilder System.Text.StringBuilder::AppendFormat(System.IFormatProvider,System.String,System.Object[])
extern "C"  StringBuilder_t586045924_0 * StringBuilder_AppendFormat_m259793396_0 (StringBuilder_t586045924_0 * __this, Object_t * ___provider, String_t* ___format, ObjectU5BU5D_t1774424924_0* ___args, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.StringBuilder System.Text.StringBuilder::AppendFormat(System.String,System.Object)
extern "C"  StringBuilder_t586045924_0 * StringBuilder_AppendFormat_m_571775566_0 (StringBuilder_t586045924_0 * __this, String_t* ___format, Object_t * ___arg0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.StringBuilder System.Text.StringBuilder::AppendFormat(System.String,System.Object,System.Object)
extern "C"  StringBuilder_t586045924_0 * StringBuilder_AppendFormat_m_807612160_0 (StringBuilder_t586045924_0 * __this, String_t* ___format, Object_t * ___arg0, Object_t * ___arg1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.StringBuilder System.Text.StringBuilder::AppendFormat(System.String,System.Object,System.Object,System.Object)
extern "C"  StringBuilder_t586045924_0 * StringBuilder_AppendFormat_m508648398_0 (StringBuilder_t586045924_0 * __this, String_t* ___format, Object_t * ___arg0, Object_t * ___arg1, Object_t * ___arg2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.StringBuilder System.Text.StringBuilder::Insert(System.Int32,System.String)
extern "C"  StringBuilder_t586045924_0 * StringBuilder_Insert_m745836595_0 (StringBuilder_t586045924_0 * __this, int32_t ___index, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.StringBuilder System.Text.StringBuilder::Insert(System.Int32,System.Char)
extern "C"  StringBuilder_t586045924_0 * StringBuilder_Insert_m1867188302_0 (StringBuilder_t586045924_0 * __this, int32_t ___index, uint16_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.StringBuilder System.Text.StringBuilder::Insert(System.Int32,System.String,System.Int32)
extern "C"  StringBuilder_t586045924_0 * StringBuilder_Insert_m1606924164_0 (StringBuilder_t586045924_0 * __this, int32_t ___index, String_t* ___value, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.StringBuilder::InternalEnsureCapacity(System.Int32)
extern "C"  void StringBuilder_InternalEnsureCapacity_m_369051298_0 (StringBuilder_t586045924_0 * __this, int32_t ___size, const MethodInfo* method) IL2CPP_METHOD_ATTR;
