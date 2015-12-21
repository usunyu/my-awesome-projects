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

// Mono.Security.X509.X509Certificate
struct X509Certificate_t219648422_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Security.Cryptography.DSA
struct DSA_t1573103491_0;
// Mono.Security.X509.X509ExtensionCollection
struct X509ExtensionCollection_t_1920699060_0;
// System.String
struct String_t;
// System.Security.Cryptography.RSA
struct RSA_t1573116945_0;
// System.Security.Cryptography.AsymmetricAlgorithm
struct AsymmetricAlgorithm_t1451338986_0;
// Mono.Security.ASN1
struct ASN1_t311288114_0;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_DateTime_818288618.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"

// System.Void Mono.Security.X509.X509Certificate::.ctor(System.Byte[])
extern "C"  void X509Certificate__ctor_m1688356825_0 (X509Certificate_t219648422_0 * __this, ByteU5BU5D_t_1238178395_0* ___data, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.X509Certificate::.cctor()
extern "C"  void X509Certificate__cctor_m_337076831_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.X509Certificate::Parse(System.Byte[])
extern "C"  void X509Certificate_Parse_m1221896268_0 (X509Certificate_t219648422_0 * __this, ByteU5BU5D_t_1238178395_0* ___data, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.X509.X509Certificate::GetUnsignedBigInteger(System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* X509Certificate_GetUnsignedBigInteger_m_1237587072_0 (X509Certificate_t219648422_0 * __this, ByteU5BU5D_t_1238178395_0* ___integer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.DSA Mono.Security.X509.X509Certificate::get_DSA()
extern "C"  DSA_t1573103491_0 * X509Certificate_get_DSA_m1952040247_0 (X509Certificate_t219648422_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.X509Certificate::set_DSA(System.Security.Cryptography.DSA)
extern "C"  void X509Certificate_set_DSA_m1562150692_0 (X509Certificate_t219648422_0 * __this, DSA_t1573103491_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.X509.X509ExtensionCollection Mono.Security.X509.X509Certificate::get_Extensions()
extern "C"  X509ExtensionCollection_t_1920699060_0 * X509Certificate_get_Extensions_m577630462_0 (X509Certificate_t219648422_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.X509.X509Certificate::get_Hash()
extern "C"  ByteU5BU5D_t_1238178395_0* X509Certificate_get_Hash_m_1369138183_0 (X509Certificate_t219648422_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.X509.X509Certificate::get_IssuerName()
extern "C"  String_t* X509Certificate_get_IssuerName_m_1059190904_0 (X509Certificate_t219648422_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.X509.X509Certificate::get_KeyAlgorithm()
extern "C"  String_t* X509Certificate_get_KeyAlgorithm_m_633261132_0 (X509Certificate_t219648422_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.X509.X509Certificate::get_KeyAlgorithmParameters()
extern "C"  ByteU5BU5D_t_1238178395_0* X509Certificate_get_KeyAlgorithmParameters_m_1586389947_0 (X509Certificate_t219648422_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.X509Certificate::set_KeyAlgorithmParameters(System.Byte[])
extern "C"  void X509Certificate_set_KeyAlgorithmParameters_m769560986_0 (X509Certificate_t219648422_0 * __this, ByteU5BU5D_t_1238178395_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.X509.X509Certificate::get_PublicKey()
extern "C"  ByteU5BU5D_t_1238178395_0* X509Certificate_get_PublicKey_m835022733_0 (X509Certificate_t219648422_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.RSA Mono.Security.X509.X509Certificate::get_RSA()
extern "C"  RSA_t1573116945_0 * X509Certificate_get_RSA_m842279223_0 (X509Certificate_t219648422_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.X509Certificate::set_RSA(System.Security.Cryptography.RSA)
extern "C"  void X509Certificate_set_RSA_m547377152_0 (X509Certificate_t219648422_0 * __this, RSA_t1573116945_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.X509.X509Certificate::get_RawData()
extern "C"  ByteU5BU5D_t_1238178395_0* X509Certificate_get_RawData_m_1306507575_0 (X509Certificate_t219648422_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.X509.X509Certificate::get_SerialNumber()
extern "C"  ByteU5BU5D_t_1238178395_0* X509Certificate_get_SerialNumber_m1906128776_0 (X509Certificate_t219648422_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.X509.X509Certificate::get_Signature()
extern "C"  ByteU5BU5D_t_1238178395_0* X509Certificate_get_Signature_m_1438596977_0 (X509Certificate_t219648422_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.X509.X509Certificate::get_SignatureAlgorithm()
extern "C"  String_t* X509Certificate_get_SignatureAlgorithm_m_1666891397_0 (X509Certificate_t219648422_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.X509.X509Certificate::get_SubjectName()
extern "C"  String_t* X509Certificate_get_SubjectName_m_67682603_0 (X509Certificate_t219648422_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime Mono.Security.X509.X509Certificate::get_ValidFrom()
extern "C"  DateTime_t_818288618_0  X509Certificate_get_ValidFrom_m_484307826_0 (X509Certificate_t219648422_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime Mono.Security.X509.X509Certificate::get_ValidUntil()
extern "C"  DateTime_t_818288618_0  X509Certificate_get_ValidUntil_m_1810940196_0 (X509Certificate_t219648422_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.X509.X509Certificate::get_Version()
extern "C"  int32_t X509Certificate_get_Version_m1452122189_0 (X509Certificate_t219648422_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.X509.X509Certificate::get_IsCurrent()
extern "C"  bool X509Certificate_get_IsCurrent_m_1230083998_0 (X509Certificate_t219648422_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.X509.X509Certificate::WasCurrent(System.DateTime)
extern "C"  bool X509Certificate_WasCurrent_m_494241822_0 (X509Certificate_t219648422_0 * __this, DateTime_t_818288618_0  ___instant, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.X509.X509Certificate::VerifySignature(System.Security.Cryptography.DSA)
extern "C"  bool X509Certificate_VerifySignature_m120457372_0 (X509Certificate_t219648422_0 * __this, DSA_t1573103491_0 * ___dsa, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.X509.X509Certificate::VerifySignature(System.Security.Cryptography.RSA)
extern "C"  bool X509Certificate_VerifySignature_m120874446_0 (X509Certificate_t219648422_0 * __this, RSA_t1573116945_0 * ___rsa, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.X509.X509Certificate::VerifySignature(System.Security.Cryptography.AsymmetricAlgorithm)
extern "C"  bool X509Certificate_VerifySignature_m1482842161_0 (X509Certificate_t219648422_0 * __this, AsymmetricAlgorithm_t1451338986_0 * ___aa, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.X509.X509Certificate::get_IsSelfSigned()
extern "C"  bool X509Certificate_get_IsSelfSigned_m_379956383_0 (X509Certificate_t219648422_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.ASN1 Mono.Security.X509.X509Certificate::GetIssuerName()
extern "C"  ASN1_t311288114_0 * X509Certificate_GetIssuerName_m_720687711_0 (X509Certificate_t219648422_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.ASN1 Mono.Security.X509.X509Certificate::GetSubjectName()
extern "C"  ASN1_t311288114_0 * X509Certificate_GetSubjectName_m1835981788_0 (X509Certificate_t219648422_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.X509Certificate::GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void X509Certificate_GetObjectData_m_1335287510_0 (X509Certificate_t219648422_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.X509.X509Certificate::PEM(System.String,System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* X509Certificate_PEM_m_415864211_0 (Object_t * __this /* static, unused */, String_t* ___type, ByteU5BU5D_t_1238178395_0* ___data, const MethodInfo* method) IL2CPP_METHOD_ATTR;
