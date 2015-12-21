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

// Mono.Security.Protocol.Tls.CipherSuite
struct CipherSuite_t_1835594235_0;
// System.String
struct String_t;
// System.Security.Cryptography.ICryptoTransform
struct ICryptoTransform_t_754437679_0;
// System.Security.Cryptography.KeyedHashAlgorithm
struct KeyedHashAlgorithm_t1340577394_0;
// Mono.Security.Protocol.Tls.Context
struct Context_t_1281777657_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;

#include "codegen/il2cpp-codegen.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_CipherAl_2011610538.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_HashAlgor_103851469.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_ExchangeAl701975358.h"
#include "mscorlib_System_Security_Cryptography_CipherMode1234727773.h"

// System.Void Mono.Security.Protocol.Tls.CipherSuite::.ctor(System.Int16,System.String,Mono.Security.Protocol.Tls.CipherAlgorithmType,Mono.Security.Protocol.Tls.HashAlgorithmType,Mono.Security.Protocol.Tls.ExchangeAlgorithmType,System.Boolean,System.Boolean,System.Byte,System.Byte,System.Int16,System.Byte,System.Byte)
extern "C"  void CipherSuite__ctor_m658209606_0 (CipherSuite_t_1835594235_0 * __this, int16_t ___code, String_t* ___name, int32_t ___cipherAlgorithmType, int32_t ___hashAlgorithmType, int32_t ___exchangeAlgorithmType, bool ___exportable, bool ___blockMode, uint8_t ___keyMaterialSize, uint8_t ___expandedKeyMaterialSize, int16_t ___effectiveKeyBits, uint8_t ___ivSize, uint8_t ___blockSize, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.CipherSuite::.cctor()
extern "C"  void CipherSuite__cctor_m_1464796964_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.ICryptoTransform Mono.Security.Protocol.Tls.CipherSuite::get_EncryptionCipher()
extern "C"  Object_t * CipherSuite_get_EncryptionCipher_m_343469912_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.ICryptoTransform Mono.Security.Protocol.Tls.CipherSuite::get_DecryptionCipher()
extern "C"  Object_t * CipherSuite_get_DecryptionCipher_m1358717056_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.KeyedHashAlgorithm Mono.Security.Protocol.Tls.CipherSuite::get_ClientHMAC()
extern "C"  KeyedHashAlgorithm_t1340577394_0 * CipherSuite_get_ClientHMAC_m_376580821_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.KeyedHashAlgorithm Mono.Security.Protocol.Tls.CipherSuite::get_ServerHMAC()
extern "C"  KeyedHashAlgorithm_t1340577394_0 * CipherSuite_get_ServerHMAC_m_1328507229_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.CipherAlgorithmType Mono.Security.Protocol.Tls.CipherSuite::get_CipherAlgorithmType()
extern "C"  int32_t CipherSuite_get_CipherAlgorithmType_m_5534747_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.Protocol.Tls.CipherSuite::get_HashAlgorithmName()
extern "C"  String_t* CipherSuite_get_HashAlgorithmName_m1304664079_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.HashAlgorithmType Mono.Security.Protocol.Tls.CipherSuite::get_HashAlgorithmType()
extern "C"  int32_t CipherSuite_get_HashAlgorithmType_m687406047_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Protocol.Tls.CipherSuite::get_HashSize()
extern "C"  int32_t CipherSuite_get_HashSize_m_1810742765_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.ExchangeAlgorithmType Mono.Security.Protocol.Tls.CipherSuite::get_ExchangeAlgorithmType()
extern "C"  int32_t CipherSuite_get_ExchangeAlgorithmType_m987153461_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.CipherMode Mono.Security.Protocol.Tls.CipherSuite::get_CipherMode()
extern "C"  int32_t CipherSuite_get_CipherMode_m2092929468_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int16 Mono.Security.Protocol.Tls.CipherSuite::get_Code()
extern "C"  int16_t CipherSuite_get_Code_m_982324661_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.Protocol.Tls.CipherSuite::get_Name()
extern "C"  String_t* CipherSuite_get_Name_m1995865258_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.CipherSuite::get_IsExportable()
extern "C"  bool CipherSuite_get_IsExportable_m534474210_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte Mono.Security.Protocol.Tls.CipherSuite::get_KeyMaterialSize()
extern "C"  uint8_t CipherSuite_get_KeyMaterialSize_m166819169_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Protocol.Tls.CipherSuite::get_KeyBlockSize()
extern "C"  int32_t CipherSuite_get_KeyBlockSize_m_602273549_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte Mono.Security.Protocol.Tls.CipherSuite::get_ExpandedKeyMaterialSize()
extern "C"  uint8_t CipherSuite_get_ExpandedKeyMaterialSize_m_1921873752_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int16 Mono.Security.Protocol.Tls.CipherSuite::get_EffectiveKeyBits()
extern "C"  int16_t CipherSuite_get_EffectiveKeyBits_m1093264636_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte Mono.Security.Protocol.Tls.CipherSuite::get_IvSize()
extern "C"  uint8_t CipherSuite_get_IvSize_m633403350_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.Context Mono.Security.Protocol.Tls.CipherSuite::get_Context()
extern "C"  Context_t_1281777657_0 * CipherSuite_get_Context_m_345311929_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.CipherSuite::set_Context(Mono.Security.Protocol.Tls.Context)
extern "C"  void CipherSuite_set_Context_m_1887141992_0 (CipherSuite_t_1835594235_0 * __this, Context_t_1281777657_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.CipherSuite::Write(System.Byte[],System.Int32,System.Int16)
extern "C"  void CipherSuite_Write_m920521461_0 (CipherSuite_t_1835594235_0 * __this, ByteU5BU5D_t_1238178395_0* ___array, int32_t ___offset, int16_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.CipherSuite::Write(System.Byte[],System.Int32,System.UInt64)
extern "C"  void CipherSuite_Write_m_531319535_0 (CipherSuite_t_1835594235_0 * __this, ByteU5BU5D_t_1238178395_0* ___array, int32_t ___offset, uint64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.CipherSuite::InitializeCipher()
extern "C"  void CipherSuite_InitializeCipher_m1046105646_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.CipherSuite::EncryptRecord(System.Byte[],System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* CipherSuite_EncryptRecord_m1686609905_0 (CipherSuite_t_1835594235_0 * __this, ByteU5BU5D_t_1238178395_0* ___fragment, ByteU5BU5D_t_1238178395_0* ___mac, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.CipherSuite::DecryptRecord(System.Byte[],System.Byte[]&,System.Byte[]&)
extern "C"  void CipherSuite_DecryptRecord_m_741695492_0 (CipherSuite_t_1835594235_0 * __this, ByteU5BU5D_t_1238178395_0* ___fragment, ByteU5BU5D_t_1238178395_0** ___dcrFragment, ByteU5BU5D_t_1238178395_0** ___dcrMAC, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.CipherSuite::CreatePremasterSecret()
extern "C"  ByteU5BU5D_t_1238178395_0* CipherSuite_CreatePremasterSecret_m_49257058_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.CipherSuite::PRF(System.Byte[],System.String,System.Byte[],System.Int32)
extern "C"  ByteU5BU5D_t_1238178395_0* CipherSuite_PRF_m_214325800_0 (CipherSuite_t_1835594235_0 * __this, ByteU5BU5D_t_1238178395_0* ___secret, String_t* ___label, ByteU5BU5D_t_1238178395_0* ___data, int32_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.CipherSuite::Expand(System.String,System.Byte[],System.Byte[],System.Int32)
extern "C"  ByteU5BU5D_t_1238178395_0* CipherSuite_Expand_m_124167738_0 (CipherSuite_t_1835594235_0 * __this, String_t* ___hashName, ByteU5BU5D_t_1238178395_0* ___secret, ByteU5BU5D_t_1238178395_0* ___seed, int32_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.CipherSuite::createEncryptionCipher()
extern "C"  void CipherSuite_createEncryptionCipher_m347042717_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.CipherSuite::createDecryptionCipher()
extern "C"  void CipherSuite_createDecryptionCipher_m2049229685_0 (CipherSuite_t_1835594235_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
