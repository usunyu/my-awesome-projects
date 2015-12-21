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

// System.Security.Cryptography.RijndaelTransform
struct RijndaelTransform_t_2143051746_0;
// System.Security.Cryptography.Rijndael
struct Rijndael_t591714030_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.UInt32[]
struct UInt32U5BU5D_t_1239494474_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Security.Cryptography.RijndaelTransform::.ctor(System.Security.Cryptography.Rijndael,System.Boolean,System.Byte[],System.Byte[])
extern "C"  void RijndaelTransform__ctor_m_82375909_0 (RijndaelTransform_t_2143051746_0 * __this, Rijndael_t591714030_0 * ___algo, bool ___encryption, ByteU5BU5D_t_1238178395_0* ___key, ByteU5BU5D_t_1238178395_0* ___iv, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RijndaelTransform::.cctor()
extern "C"  void RijndaelTransform__cctor_m_1953683019_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RijndaelTransform::Clear()
extern "C"  void RijndaelTransform_Clear_m_286032605_0 (RijndaelTransform_t_2143051746_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RijndaelTransform::ECB(System.Byte[],System.Byte[])
extern "C"  void RijndaelTransform_ECB_m759186162_0 (RijndaelTransform_t_2143051746_0 * __this, ByteU5BU5D_t_1238178395_0* ___input, ByteU5BU5D_t_1238178395_0* ___output, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt32 System.Security.Cryptography.RijndaelTransform::SubByte(System.UInt32)
extern "C"  uint32_t RijndaelTransform_SubByte_m2002058519_0 (RijndaelTransform_t_2143051746_0 * __this, uint32_t ___a, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RijndaelTransform::Encrypt128(System.Byte[],System.Byte[],System.UInt32[])
extern "C"  void RijndaelTransform_Encrypt128_m_376599456_0 (RijndaelTransform_t_2143051746_0 * __this, ByteU5BU5D_t_1238178395_0* ___indata, ByteU5BU5D_t_1238178395_0* ___outdata, UInt32U5BU5D_t_1239494474_0* ___ekey, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RijndaelTransform::Encrypt192(System.Byte[],System.Byte[],System.UInt32[])
extern "C"  void RijndaelTransform_Encrypt192_m_954775955_0 (RijndaelTransform_t_2143051746_0 * __this, ByteU5BU5D_t_1238178395_0* ___indata, ByteU5BU5D_t_1238178395_0* ___outdata, UInt32U5BU5D_t_1239494474_0* ___ekey, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RijndaelTransform::Encrypt256(System.Byte[],System.Byte[],System.UInt32[])
extern "C"  void RijndaelTransform_Encrypt256_m282559940_0 (RijndaelTransform_t_2143051746_0 * __this, ByteU5BU5D_t_1238178395_0* ___indata, ByteU5BU5D_t_1238178395_0* ___outdata, UInt32U5BU5D_t_1239494474_0* ___ekey, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RijndaelTransform::Decrypt128(System.Byte[],System.Byte[],System.UInt32[])
extern "C"  void RijndaelTransform_Decrypt128_m_717110392_0 (RijndaelTransform_t_2143051746_0 * __this, ByteU5BU5D_t_1238178395_0* ___indata, ByteU5BU5D_t_1238178395_0* ___outdata, UInt32U5BU5D_t_1239494474_0* ___ekey, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RijndaelTransform::Decrypt192(System.Byte[],System.Byte[],System.UInt32[])
extern "C"  void RijndaelTransform_Decrypt192_m_1295286891_0 (RijndaelTransform_t_2143051746_0 * __this, ByteU5BU5D_t_1238178395_0* ___indata, ByteU5BU5D_t_1238178395_0* ___outdata, UInt32U5BU5D_t_1239494474_0* ___ekey, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RijndaelTransform::Decrypt256(System.Byte[],System.Byte[],System.UInt32[])
extern "C"  void RijndaelTransform_Decrypt256_m_57950996_0 (RijndaelTransform_t_2143051746_0 * __this, ByteU5BU5D_t_1238178395_0* ___indata, ByteU5BU5D_t_1238178395_0* ___outdata, UInt32U5BU5D_t_1239494474_0* ___ekey, const MethodInfo* method) IL2CPP_METHOD_ATTR;
