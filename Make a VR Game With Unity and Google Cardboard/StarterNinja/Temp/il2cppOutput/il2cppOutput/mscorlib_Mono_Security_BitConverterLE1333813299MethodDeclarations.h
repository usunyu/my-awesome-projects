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

#include "codegen/il2cpp-codegen.h"

// System.Byte[] Mono.Security.BitConverterLE::GetUIntBytes(System.Byte*)
extern "C"  ByteU5BU5D_t_1238178395_0* BitConverterLE_GetUIntBytes_m_1583751069_0 (Object_t * __this /* static, unused */, uint8_t* ___bytes, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.BitConverterLE::GetBytes(System.Int32)
extern "C"  ByteU5BU5D_t_1238178395_0* BitConverterLE_GetBytes_m_568258799_0 (Object_t * __this /* static, unused */, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.BitConverterLE::UShortFromBytes(System.Byte*,System.Byte[],System.Int32)
extern "C"  void BitConverterLE_UShortFromBytes_m_2050089860_0 (Object_t * __this /* static, unused */, uint8_t* ___dst, ByteU5BU5D_t_1238178395_0* ___src, int32_t ___startIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.BitConverterLE::UIntFromBytes(System.Byte*,System.Byte[],System.Int32)
extern "C"  void BitConverterLE_UIntFromBytes_m318761967_0 (Object_t * __this /* static, unused */, uint8_t* ___dst, ByteU5BU5D_t_1238178395_0* ___src, int32_t ___startIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.BitConverterLE::ULongFromBytes(System.Byte*,System.Byte[],System.Int32)
extern "C"  void BitConverterLE_ULongFromBytes_m_1578570682_0 (Object_t * __this /* static, unused */, uint8_t* ___dst, ByteU5BU5D_t_1238178395_0* ___src, int32_t ___startIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int16 Mono.Security.BitConverterLE::ToInt16(System.Byte[],System.Int32)
extern "C"  int16_t BitConverterLE_ToInt16_m_2042618990_0 (Object_t * __this /* static, unused */, ByteU5BU5D_t_1238178395_0* ___value, int32_t ___startIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.BitConverterLE::ToInt32(System.Byte[],System.Int32)
extern "C"  int32_t BitConverterLE_ToInt32_m_1406145914_0 (Object_t * __this /* static, unused */, ByteU5BU5D_t_1238178395_0* ___value, int32_t ___startIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single Mono.Security.BitConverterLE::ToSingle(System.Byte[],System.Int32)
extern "C"  float BitConverterLE_ToSingle_m_864938562_0 (Object_t * __this /* static, unused */, ByteU5BU5D_t_1238178395_0* ___value, int32_t ___startIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Double Mono.Security.BitConverterLE::ToDouble(System.Byte[],System.Int32)
extern "C"  double BitConverterLE_ToDouble_m_112751202_0 (Object_t * __this /* static, unused */, ByteU5BU5D_t_1238178395_0* ___value, int32_t ___startIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
