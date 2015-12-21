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

// Mono.Security.X509.PKCS12
struct PKCS12_t_683319955_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.String
struct String_t;
// Mono.Security.X509.X509CertificateCollection
struct X509CertificateCollection_t_865204850_0;
// System.Security.Cryptography.RandomNumberGenerator
struct RandomNumberGenerator_t1902086616_0;
// System.Security.Cryptography.SymmetricAlgorithm
struct SymmetricAlgorithm_t_896426745_0;
// Mono.Security.PKCS7/EncryptedData
struct EncryptedData_t1811911844_0;
// Mono.Security.Cryptography.PKCS8/PrivateKeyInfo
struct PrivateKeyInfo_t584431911_0;
// Mono.Security.ASN1
struct ASN1_t1755619932_0;
// Mono.Security.X509.X509Certificate
struct X509Certificate_t_1016414512_0;
// System.Collections.IDictionary
struct IDictionary_t_1514320629_0;
// Mono.Security.PKCS7/ContentInfo
struct ContentInfo_t193589085_0;
// System.Object
struct Object_t;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Security_Cryptography_DSAParameters969932237.h"

// System.Void Mono.Security.X509.PKCS12::.ctor()
extern "C"  void PKCS12__ctor_m_582721277_0 (PKCS12_t_683319955_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.PKCS12::.ctor(System.Byte[])
extern "C"  void PKCS12__ctor_m_604726362_0 (PKCS12_t_683319955_0 * __this, ByteU5BU5D_t_1238178395_0* ___data, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.PKCS12::.ctor(System.Byte[],System.String)
extern "C"  void PKCS12__ctor_m252275042_0 (PKCS12_t_683319955_0 * __this, ByteU5BU5D_t_1238178395_0* ___data, String_t* ___password, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.PKCS12::.cctor()
extern "C"  void PKCS12__cctor_m_1366586614_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.PKCS12::Decode(System.Byte[])
extern "C"  void PKCS12_Decode_m1208795610_0 (PKCS12_t_683319955_0 * __this, ByteU5BU5D_t_1238178395_0* ___data, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.PKCS12::Finalize()
extern "C"  void PKCS12_Finalize_m510753919_0 (PKCS12_t_683319955_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.PKCS12::set_Password(System.String)
extern "C"  void PKCS12_set_Password_m451279849_0 (PKCS12_t_683319955_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.X509.PKCS12::get_IterationCount()
extern "C"  int32_t PKCS12_get_IterationCount_m_512468544_0 (PKCS12_t_683319955_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.PKCS12::set_IterationCount(System.Int32)
extern "C"  void PKCS12_set_IterationCount_m_1464841439_0 (PKCS12_t_683319955_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.X509.X509CertificateCollection Mono.Security.X509.PKCS12::get_Certificates()
extern "C"  X509CertificateCollection_t_865204850_0 * PKCS12_get_Certificates_m_359515547_0 (PKCS12_t_683319955_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.RandomNumberGenerator Mono.Security.X509.PKCS12::get_RNG()
extern "C"  RandomNumberGenerator_t1902086616_0 * PKCS12_get_RNG_m_1792975302_0 (PKCS12_t_683319955_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.X509.PKCS12::Compare(System.Byte[],System.Byte[])
extern "C"  bool PKCS12_Compare_m143948868_0 (PKCS12_t_683319955_0 * __this, ByteU5BU5D_t_1238178395_0* ___expected, ByteU5BU5D_t_1238178395_0* ___actual, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.SymmetricAlgorithm Mono.Security.X509.PKCS12::GetSymmetricAlgorithm(System.String,System.Byte[],System.Int32)
extern "C"  SymmetricAlgorithm_t_896426745_0 * PKCS12_GetSymmetricAlgorithm_m1131954313_0 (PKCS12_t_683319955_0 * __this, String_t* ___algorithmOid, ByteU5BU5D_t_1238178395_0* ___salt, int32_t ___iterationCount, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.X509.PKCS12::Decrypt(System.String,System.Byte[],System.Int32,System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* PKCS12_Decrypt_m1846702093_0 (PKCS12_t_683319955_0 * __this, String_t* ___algorithmOid, ByteU5BU5D_t_1238178395_0* ___salt, int32_t ___iterationCount, ByteU5BU5D_t_1238178395_0* ___encryptedData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.X509.PKCS12::Decrypt(Mono.Security.PKCS7/EncryptedData)
extern "C"  ByteU5BU5D_t_1238178395_0* PKCS12_Decrypt_m232511250_0 (PKCS12_t_683319955_0 * __this, EncryptedData_t1811911844_0 * ___ed, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.X509.PKCS12::Encrypt(System.String,System.Byte[],System.Int32,System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* PKCS12_Encrypt_m_1747722011_0 (PKCS12_t_683319955_0 * __this, String_t* ___algorithmOid, ByteU5BU5D_t_1238178395_0* ___salt, int32_t ___iterationCount, ByteU5BU5D_t_1238178395_0* ___data, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.DSAParameters Mono.Security.X509.PKCS12::GetExistingParameters(System.Boolean&)
extern "C"  DSAParameters_t969932237_0  PKCS12_GetExistingParameters_m713420615_0 (PKCS12_t_683319955_0 * __this, bool* ___found, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.PKCS12::AddPrivateKey(Mono.Security.Cryptography.PKCS8/PrivateKeyInfo)
extern "C"  void PKCS12_AddPrivateKey_m_1691322551_0 (PKCS12_t_683319955_0 * __this, PrivateKeyInfo_t584431911_0 * ___pki, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.PKCS12::ReadSafeBag(Mono.Security.ASN1)
extern "C"  void PKCS12_ReadSafeBag_m_2130644498_0 (PKCS12_t_683319955_0 * __this, ASN1_t1755619932_0 * ___safeBag, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.ASN1 Mono.Security.X509.PKCS12::CertificateSafeBag(Mono.Security.X509.X509Certificate,System.Collections.IDictionary)
extern "C"  ASN1_t1755619932_0 * PKCS12_CertificateSafeBag_m_331964135_0 (PKCS12_t_683319955_0 * __this, X509Certificate_t_1016414512_0 * ___x509, Object_t * ___attributes, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.X509.PKCS12::MAC(System.Byte[],System.Byte[],System.Int32,System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* PKCS12_MAC_m1584310760_0 (PKCS12_t_683319955_0 * __this, ByteU5BU5D_t_1238178395_0* ___password, ByteU5BU5D_t_1238178395_0* ___salt, int32_t ___iterations, ByteU5BU5D_t_1238178395_0* ___data, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.X509.PKCS12::GetBytes()
extern "C"  ByteU5BU5D_t_1238178395_0* PKCS12_GetBytes_m683139820_0 (PKCS12_t_683319955_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.PKCS7/ContentInfo Mono.Security.X509.PKCS12::EncryptedContentInfo(Mono.Security.ASN1,System.String)
extern "C"  ContentInfo_t193589085_0 * PKCS12_EncryptedContentInfo_m_857357866_0 (PKCS12_t_683319955_0 * __this, ASN1_t1755619932_0 * ___safeBags, String_t* ___algorithmOid, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.PKCS12::AddCertificate(Mono.Security.X509.X509Certificate)
extern "C"  void PKCS12_AddCertificate_m1604686507_0 (PKCS12_t_683319955_0 * __this, X509Certificate_t_1016414512_0 * ___cert, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.PKCS12::AddCertificate(Mono.Security.X509.X509Certificate,System.Collections.IDictionary)
extern "C"  void PKCS12_AddCertificate_m_1090220940_0 (PKCS12_t_683319955_0 * __this, X509Certificate_t_1016414512_0 * ___cert, Object_t * ___attributes, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.PKCS12::RemoveCertificate(Mono.Security.X509.X509Certificate)
extern "C"  void PKCS12_RemoveCertificate_m1503902376_0 (PKCS12_t_683319955_0 * __this, X509Certificate_t_1016414512_0 * ___cert, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.PKCS12::RemoveCertificate(Mono.Security.X509.X509Certificate,System.Collections.IDictionary)
extern "C"  void PKCS12_RemoveCertificate_m_156195625_0 (PKCS12_t_683319955_0 * __this, X509Certificate_t_1016414512_0 * ___cert, Object_t * ___attrs, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object Mono.Security.X509.PKCS12::Clone()
extern "C"  Object_t * PKCS12_Clone_m_796524173_0 (PKCS12_t_683319955_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.X509.PKCS12::get_MaximumPasswordLength()
extern "C"  int32_t PKCS12_get_MaximumPasswordLength_m_1425510731_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
