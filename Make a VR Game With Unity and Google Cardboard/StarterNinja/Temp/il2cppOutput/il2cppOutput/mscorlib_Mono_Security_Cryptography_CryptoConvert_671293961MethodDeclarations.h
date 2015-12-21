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
// System.Security.Cryptography.RSA
struct RSA_t1573116945_0;

#include "codegen/il2cpp-codegen.h"

// System.Int32 Mono.Security.Cryptography.CryptoConvert::ToInt32LE(System.Byte[],System.Int32)
extern "C"  int32_t CryptoConvert_ToInt32LE_m2023521787_0 (Object_t * __this /* static, unused */, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___offset, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt32 Mono.Security.Cryptography.CryptoConvert::ToUInt32LE(System.Byte[],System.Int32)
extern "C"  uint32_t CryptoConvert_ToUInt32LE_m558101659_0 (Object_t * __this /* static, unused */, ByteU5BU5D_t_1238178395_0* ___bytes, int32_t ___offset, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Cryptography.CryptoConvert::GetBytesLE(System.Int32)
extern "C"  ByteU5BU5D_t_1238178395_0* CryptoConvert_GetBytesLE_m62772046_0 (Object_t * __this /* static, unused */, int32_t ___val, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Cryptography.CryptoConvert::ToCapiPrivateKeyBlob(System.Security.Cryptography.RSA)
extern "C"  ByteU5BU5D_t_1238178395_0* CryptoConvert_ToCapiPrivateKeyBlob_m1139689325_0 (Object_t * __this /* static, unused */, RSA_t1573116945_0 * ___rsa, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.RSA Mono.Security.Cryptography.CryptoConvert::FromCapiPublicKeyBlob(System.Byte[])
extern "C"  RSA_t1573116945_0 * CryptoConvert_FromCapiPublicKeyBlob_m_1521265288_0 (Object_t * __this /* static, unused */, ByteU5BU5D_t_1238178395_0* ___blob, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.RSA Mono.Security.Cryptography.CryptoConvert::FromCapiPublicKeyBlob(System.Byte[],System.Int32)
extern "C"  RSA_t1573116945_0 * CryptoConvert_FromCapiPublicKeyBlob_m1285057119_0 (Object_t * __this /* static, unused */, ByteU5BU5D_t_1238178395_0* ___blob, int32_t ___offset, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Cryptography.CryptoConvert::ToCapiPublicKeyBlob(System.Security.Cryptography.RSA)
extern "C"  ByteU5BU5D_t_1238178395_0* CryptoConvert_ToCapiPublicKeyBlob_m_153423353_0 (Object_t * __this /* static, unused */, RSA_t1573116945_0 * ___rsa, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Cryptography.CryptoConvert::ToCapiKeyBlob(System.Security.Cryptography.RSA,System.Boolean)
extern "C"  ByteU5BU5D_t_1238178395_0* CryptoConvert_ToCapiKeyBlob_m_1683528947_0 (Object_t * __this /* static, unused */, RSA_t1573116945_0 * ___rsa, bool ___includePrivateKey, const MethodInfo* method) IL2CPP_METHOD_ATTR;
