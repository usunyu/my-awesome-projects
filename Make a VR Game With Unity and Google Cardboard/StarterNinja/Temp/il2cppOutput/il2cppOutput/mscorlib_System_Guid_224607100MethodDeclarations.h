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

// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Object
struct Object_t;
// System.Text.StringBuilder
struct StringBuilder_t586045924_0;
// System.String
struct String_t;
// System.IFormatProvider
struct IFormatProvider_t_1172917514_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Guid_224607100.h"

// System.Void System.Guid::.ctor(System.Byte[])
extern "C"  void Guid__ctor_m_63118147_0 (Guid_t_224607100_0 * __this, ByteU5BU5D_t_1238178395_0* ___b, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Guid::.ctor(System.Int32,System.Int16,System.Int16,System.Byte,System.Byte,System.Byte,System.Byte,System.Byte,System.Byte,System.Byte,System.Byte)
extern "C"  void Guid__ctor_m1439809125_0 (Guid_t_224607100_0 * __this, int32_t ___a, int16_t ___b, int16_t ___c, uint8_t ___d, uint8_t ___e, uint8_t ___f, uint8_t ___g, uint8_t ___h, uint8_t ___i, uint8_t ___j, uint8_t ___k, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Guid::.cctor()
extern "C"  void Guid__cctor_m_1528856927_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Guid::CheckNull(System.Object)
extern "C"  void Guid_CheckNull_m_1463599077_0 (Object_t * __this /* static, unused */, Object_t * ___o, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Guid::CheckLength(System.Byte[],System.Int32)
extern "C"  void Guid_CheckLength_m1965613350_0 (Object_t * __this /* static, unused */, ByteU5BU5D_t_1238178395_0* ___o, int32_t ___l, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Guid::CheckArray(System.Byte[],System.Int32)
extern "C"  void Guid_CheckArray_m_1960981417_0 (Object_t * __this /* static, unused */, ByteU5BU5D_t_1238178395_0* ___o, int32_t ___l, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Guid::Compare(System.Int32,System.Int32)
extern "C"  int32_t Guid_Compare_m_617786021_0 (Object_t * __this /* static, unused */, int32_t ___x, int32_t ___y, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Guid::CompareTo(System.Object)
extern "C"  int32_t Guid_CompareTo_m899467726_0 (Guid_t_224607100_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Guid::Equals(System.Object)
extern "C"  bool Guid_Equals_m1613304319_0 (Guid_t_224607100_0 * __this, Object_t * ___o, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Guid::CompareTo(System.Guid)
extern "C"  int32_t Guid_CompareTo_m_131026748_0 (Guid_t_224607100_0 * __this, Guid_t_224607100_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Guid::Equals(System.Guid)
extern "C"  bool Guid_Equals_m_2065477323_0 (Guid_t_224607100_0 * __this, Guid_t_224607100_0  ___g, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Guid::GetHashCode()
extern "C"  int32_t Guid_GetHashCode_m885349207_0 (Guid_t_224607100_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Char System.Guid::ToHex(System.Int32)
extern "C"  uint16_t Guid_ToHex_m1518905113_0 (Object_t * __this /* static, unused */, int32_t ___b, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Guid System.Guid::NewGuid()
extern "C"  Guid_t_224607100_0  Guid_NewGuid_m_734237986_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Guid::AppendInt(System.Text.StringBuilder,System.Int32)
extern "C"  void Guid_AppendInt_m60474956_0 (Object_t * __this /* static, unused */, StringBuilder_t586045924_0 * ___builder, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Guid::AppendShort(System.Text.StringBuilder,System.Int16)
extern "C"  void Guid_AppendShort_m_1528292589_0 (Object_t * __this /* static, unused */, StringBuilder_t586045924_0 * ___builder, int16_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Guid::AppendByte(System.Text.StringBuilder,System.Byte)
extern "C"  void Guid_AppendByte_m1375613333_0 (Object_t * __this /* static, unused */, StringBuilder_t586045924_0 * ___builder, uint8_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Guid::BaseToString(System.Boolean,System.Boolean,System.Boolean)
extern "C"  String_t* Guid_BaseToString_m_1389609943_0 (Guid_t_224607100_0 * __this, bool ___h, bool ___p, bool ___b, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Guid::ToString()
extern "C"  String_t* Guid_ToString_m_1766435359_0 (Guid_t_224607100_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Guid::ToString(System.String)
extern "C"  String_t* Guid_ToString_m2135662273_0 (Guid_t_224607100_0 * __this, String_t* ___format, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Guid::ToString(System.String,System.IFormatProvider)
extern "C"  String_t* Guid_ToString_m_1117719277_0 (Guid_t_224607100_0 * __this, String_t* ___format, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
