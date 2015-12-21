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

// System.Security.Cryptography.X509Certificates.X509Certificate2
struct X509Certificate2_t1644507188_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Security.Cryptography.X509Certificates.X509ExtensionCollection
struct X509ExtensionCollection_t_424340636_0;
// System.Security.Cryptography.X509Certificates.X500DistinguishedName
struct X500DistinguishedName_t414226495_0;
// System.Security.Cryptography.AsymmetricAlgorithm
struct AsymmetricAlgorithm_t1451338986_0;
// System.Security.Cryptography.X509Certificates.PublicKey
struct PublicKey_t_188668797_0;
// System.String
struct String_t;
// System.Security.Cryptography.Oid
struct Oid_t1024680945_0;
// Mono.Security.ASN1
struct ASN1_t311288114_0;
// System.Text.StringBuilder
struct StringBuilder_t586045924_0;
// Mono.Security.X509.X509Certificate
struct X509Certificate_t219648422_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_DateTime_818288618.h"
#include "System_System_Security_Cryptography_X509Certificat_133708898.h"
#include "mscorlib_System_Security_Cryptography_X509Certifi_1476250360.h"

// System.Void System.Security.Cryptography.X509Certificates.X509Certificate2::.ctor(System.Byte[])
extern "C"  void X509Certificate2__ctor_m_1960164761_0 (X509Certificate2_t1644507188_0 * __this, ByteU5BU5D_t_1238178395_0* ___rawData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Certificate2::.cctor()
extern "C"  void X509Certificate2__cctor_m1878821707_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509ExtensionCollection System.Security.Cryptography.X509Certificates.X509Certificate2::get_Extensions()
extern "C"  X509ExtensionCollection_t_424340636_0 * X509Certificate2_get_Extensions_m_449572364_0 (X509Certificate2_t1644507188_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X500DistinguishedName System.Security.Cryptography.X509Certificates.X509Certificate2::get_IssuerName()
extern "C"  X500DistinguishedName_t414226495_0 * X509Certificate2_get_IssuerName_m_927345847_0 (X509Certificate2_t1644507188_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.Security.Cryptography.X509Certificates.X509Certificate2::get_NotAfter()
extern "C"  DateTime_t_818288618_0  X509Certificate2_get_NotAfter_m_853905907_0 (X509Certificate2_t1644507188_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.Security.Cryptography.X509Certificates.X509Certificate2::get_NotBefore()
extern "C"  DateTime_t_818288618_0  X509Certificate2_get_NotBefore_m_237486960_0 (X509Certificate2_t1644507188_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.AsymmetricAlgorithm System.Security.Cryptography.X509Certificates.X509Certificate2::get_PrivateKey()
extern "C"  AsymmetricAlgorithm_t1451338986_0 * X509Certificate2_get_PrivateKey_m2043008864_0 (X509Certificate2_t1644507188_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.PublicKey System.Security.Cryptography.X509Certificates.X509Certificate2::get_PublicKey()
extern "C"  PublicKey_t_188668797_0 * X509Certificate2_get_PublicKey_m1236823063_0 (X509Certificate2_t1644507188_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509Certificate2::get_SerialNumber()
extern "C"  String_t* X509Certificate2_get_SerialNumber_m_1022240341_0 (X509Certificate2_t1644507188_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.Oid System.Security.Cryptography.X509Certificates.X509Certificate2::get_SignatureAlgorithm()
extern "C"  Oid_t1024680945_0 * X509Certificate2_get_SignatureAlgorithm_m_969560886_0 (X509Certificate2_t1644507188_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X500DistinguishedName System.Security.Cryptography.X509Certificates.X509Certificate2::get_SubjectName()
extern "C"  X500DistinguishedName_t414226495_0 * X509Certificate2_get_SubjectName_m_275453132_0 (X509Certificate2_t1644507188_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509Certificate2::get_Thumbprint()
extern "C"  String_t* X509Certificate2_get_Thumbprint_m1619061413_0 (X509Certificate2_t1644507188_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Security.Cryptography.X509Certificates.X509Certificate2::get_Version()
extern "C"  int32_t X509Certificate2_get_Version_m_1027313281_0 (X509Certificate2_t1644507188_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509Certificate2::GetNameInfo(System.Security.Cryptography.X509Certificates.X509NameType,System.Boolean)
extern "C"  String_t* X509Certificate2_GetNameInfo_m750863125_0 (X509Certificate2_t1644507188_0 * __this, int32_t ___nameType, bool ___forIssuer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.ASN1 System.Security.Cryptography.X509Certificates.X509Certificate2::Find(System.Byte[],Mono.Security.ASN1)
extern "C"  ASN1_t311288114_0 * X509Certificate2_Find_m_663228825_0 (X509Certificate2_t1644507188_0 * __this, ByteU5BU5D_t_1238178395_0* ___oid, ASN1_t311288114_0 * ___dn, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509Certificate2::GetValueAsString(Mono.Security.ASN1)
extern "C"  String_t* X509Certificate2_GetValueAsString_m_134375477_0 (X509Certificate2_t1644507188_0 * __this, ASN1_t311288114_0 * ___pair, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Certificate2::ImportPkcs12(System.Byte[],System.String)
extern "C"  void X509Certificate2_ImportPkcs12_m976921138_0 (X509Certificate2_t1644507188_0 * __this, ByteU5BU5D_t_1238178395_0* ___rawData, String_t* ___password, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Certificate2::Import(System.Byte[],System.String,System.Security.Cryptography.X509Certificates.X509KeyStorageFlags)
extern "C"  void X509Certificate2_Import_m295659102_0 (X509Certificate2_t1644507188_0 * __this, ByteU5BU5D_t_1238178395_0* ___rawData, String_t* ___password, int32_t ___keyStorageFlags, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Certificate2::Reset()
extern "C"  void X509Certificate2_Reset_m1463369551_0 (X509Certificate2_t1644507188_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509Certificate2::ToString()
extern "C"  String_t* X509Certificate2_ToString_m_1779297807_0 (X509Certificate2_t1644507188_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509Certificate2::ToString(System.Boolean)
extern "C"  String_t* X509Certificate2_ToString_m1920339368_0 (X509Certificate2_t1644507188_0 * __this, bool ___verbose, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Certificate2::AppendBuffer(System.Text.StringBuilder,System.Byte[])
extern "C"  void X509Certificate2_AppendBuffer_m158196497_0 (Object_t * __this /* static, unused */, StringBuilder_t586045924_0 * ___sb, ByteU5BU5D_t_1238178395_0* ___buffer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Security.Cryptography.X509Certificates.X509Certificate2::Verify()
extern "C"  bool X509Certificate2_Verify_m1278605553_0 (X509Certificate2_t1644507188_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.X509.X509Certificate System.Security.Cryptography.X509Certificates.X509Certificate2::get_MonoCertificate()
extern "C"  X509Certificate_t219648422_0 * X509Certificate2_get_MonoCertificate_m_1746327304_0 (X509Certificate2_t1644507188_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
