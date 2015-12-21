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

// System.Net.IPv6Address
struct IPv6Address_t_1270038473_0;
// System.UInt16[]
struct UInt16U5BU5D_t_1239550212_0;
// System.String
struct String_t;
// System.Object
struct Object_t;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Net.IPv6Address::.ctor(System.UInt16[])
extern "C"  void IPv6Address__ctor_m194879283_0 (IPv6Address_t_1270038473_0 * __this, UInt16U5BU5D_t_1239550212_0* ___addr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Net.IPv6Address::.ctor(System.UInt16[],System.Int32)
extern "C"  void IPv6Address__ctor_m705628292_0 (IPv6Address_t_1270038473_0 * __this, UInt16U5BU5D_t_1239550212_0* ___addr, int32_t ___prefixLength, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Net.IPv6Address::.ctor(System.UInt16[],System.Int32,System.Int32)
extern "C"  void IPv6Address__ctor_m974981843_0 (IPv6Address_t_1270038473_0 * __this, UInt16U5BU5D_t_1239550212_0* ___addr, int32_t ___prefixLength, int32_t ___scopeId, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Net.IPv6Address::.cctor()
extern "C"  void IPv6Address__cctor_m84116622_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Net.IPv6Address System.Net.IPv6Address::Parse(System.String)
extern "C"  IPv6Address_t_1270038473_0 * IPv6Address_Parse_m1303737588_0 (Object_t * __this /* static, unused */, String_t* ___ipString, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Net.IPv6Address::Fill(System.UInt16[],System.String)
extern "C"  int32_t IPv6Address_Fill_m1034015862_0 (Object_t * __this /* static, unused */, UInt16U5BU5D_t_1239550212_0* ___addr, String_t* ___ipString, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Net.IPv6Address::TryParse(System.String,System.Int32&)
extern "C"  bool IPv6Address_TryParse_m895448644_0 (Object_t * __this /* static, unused */, String_t* ___prefix, int32_t* ___res, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Net.IPv6Address::TryParse(System.String,System.Net.IPv6Address&)
extern "C"  bool IPv6Address_TryParse_m711194034_0 (Object_t * __this /* static, unused */, String_t* ___ipString, IPv6Address_t_1270038473_0 ** ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt16[] System.Net.IPv6Address::get_Address()
extern "C"  UInt16U5BU5D_t_1239550212_0* IPv6Address_get_Address_m1909339413_0 (IPv6Address_t_1270038473_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.Net.IPv6Address::get_ScopeId()
extern "C"  int64_t IPv6Address_get_ScopeId_m_1472401614_0 (IPv6Address_t_1270038473_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Net.IPv6Address::set_ScopeId(System.Int64)
extern "C"  void IPv6Address_set_ScopeId_m1866414241_0 (IPv6Address_t_1270038473_0 * __this, int64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Net.IPv6Address::IsLoopback(System.Net.IPv6Address)
extern "C"  bool IPv6Address_IsLoopback_m_735600269_0 (Object_t * __this /* static, unused */, IPv6Address_t_1270038473_0 * ___addr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt16 System.Net.IPv6Address::SwapUShort(System.UInt16)
extern "C"  uint16_t IPv6Address_SwapUShort_m_583095744_0 (Object_t * __this /* static, unused */, uint16_t ___number, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Net.IPv6Address::AsIPv4Int()
extern "C"  int32_t IPv6Address_AsIPv4Int_m_2073310907_0 (IPv6Address_t_1270038473_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Net.IPv6Address::IsIPv4Compatible()
extern "C"  bool IPv6Address_IsIPv4Compatible_m_520093954_0 (IPv6Address_t_1270038473_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Net.IPv6Address::IsIPv4Mapped()
extern "C"  bool IPv6Address_IsIPv4Mapped_m525075229_0 (IPv6Address_t_1270038473_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Net.IPv6Address::ToString()
extern "C"  String_t* IPv6Address_ToString_m804087156_0 (IPv6Address_t_1270038473_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Net.IPv6Address::ToString(System.Boolean)
extern "C"  String_t* IPv6Address_ToString_m_1746173973_0 (IPv6Address_t_1270038473_0 * __this, bool ___fullLength, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Net.IPv6Address::Equals(System.Object)
extern "C"  bool IPv6Address_Equals_m1266534874_0 (IPv6Address_t_1270038473_0 * __this, Object_t * ___other, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Net.IPv6Address::GetHashCode()
extern "C"  int32_t IPv6Address_GetHashCode_m691770942_0 (IPv6Address_t_1270038473_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Net.IPv6Address::Hash(System.Int32,System.Int32,System.Int32,System.Int32)
extern "C"  int32_t IPv6Address_Hash_m1904786435_0 (Object_t * __this /* static, unused */, int32_t ___i, int32_t ___j, int32_t ___k, int32_t ___l, const MethodInfo* method) IL2CPP_METHOD_ATTR;
