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

// System.Security.Cryptography.X509Certificates.X509Certificate
struct X509Certificate_t1524084820_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;
// System.Object
struct Object_t;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"
#include "mscorlib_System_Security_Cryptography_X509Certifi_1476250360.h"

// System.Void System.Security.Cryptography.X509Certificates.X509Certificate::.ctor(System.Byte[],System.Boolean)
extern "C"  void X509Certificate__ctor_m1909610000_0 (X509Certificate_t1524084820_0 * __this, ByteU5BU5D_t_1238178395_0* ___data, bool ___dates, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Certificate::.ctor(System.Byte[])
extern "C"  void X509Certificate__ctor_m_1109816883_0 (X509Certificate_t1524084820_0 * __this, ByteU5BU5D_t_1238178395_0* ___data, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Certificate::.ctor()
extern "C"  void X509Certificate__ctor_m_2066448516_0 (X509Certificate_t1524084820_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Certificate::.ctor(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void X509Certificate__ctor_m1187024573_0 (X509Certificate_t1524084820_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Certificate::System.Runtime.Serialization.IDeserializationCallback.OnDeserialization(System.Object)
extern "C"  void X509Certificate_System_Runtime_Serialization_IDeserializationCallback_OnDeserialization_m755168634_0 (X509Certificate_t1524084820_0 * __this, Object_t * ___sender, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Certificate::System.Runtime.Serialization.ISerializable.GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void X509Certificate_System_Runtime_Serialization_ISerializable_GetObjectData_m_1888765553_0 (X509Certificate_t1524084820_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509Certificate::tostr(System.Byte[])
extern "C"  String_t* X509Certificate_tostr_m1883898870_0 (X509Certificate_t1524084820_0 * __this, ByteU5BU5D_t_1238178395_0* ___data, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Security.Cryptography.X509Certificates.X509Certificate::Equals(System.Security.Cryptography.X509Certificates.X509Certificate)
extern "C"  bool X509Certificate_Equals_m_1784056875_0 (X509Certificate_t1524084820_0 * __this, X509Certificate_t1524084820_0 * ___other, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Security.Cryptography.X509Certificates.X509Certificate::GetCertHash()
extern "C"  ByteU5BU5D_t_1238178395_0* X509Certificate_GetCertHash_m_1422187444_0 (X509Certificate_t1524084820_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509Certificate::GetCertHashString()
extern "C"  String_t* X509Certificate_GetCertHashString_m539795190_0 (X509Certificate_t1524084820_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509Certificate::GetEffectiveDateString()
extern "C"  String_t* X509Certificate_GetEffectiveDateString_m523012725_0 (X509Certificate_t1524084820_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509Certificate::GetExpirationDateString()
extern "C"  String_t* X509Certificate_GetExpirationDateString_m1866410017_0 (X509Certificate_t1524084820_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Security.Cryptography.X509Certificates.X509Certificate::GetHashCode()
extern "C"  int32_t X509Certificate_GetHashCode_m1423591751_0 (X509Certificate_t1524084820_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509Certificate::GetIssuerName()
extern "C"  String_t* X509Certificate_GetIssuerName_m1001053335_0 (X509Certificate_t1524084820_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509Certificate::GetName()
extern "C"  String_t* X509Certificate_GetName_m_1558947330_0 (X509Certificate_t1524084820_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Security.Cryptography.X509Certificates.X509Certificate::GetPublicKey()
extern "C"  ByteU5BU5D_t_1238178395_0* X509Certificate_GetPublicKey_m_537874594_0 (X509Certificate_t1524084820_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Security.Cryptography.X509Certificates.X509Certificate::GetRawCertData()
extern "C"  ByteU5BU5D_t_1238178395_0* X509Certificate_GetRawCertData_m86483614_0 (X509Certificate_t1524084820_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509Certificate::ToString()
extern "C"  String_t* X509Certificate_ToString_m_2066545231_0 (X509Certificate_t1524084820_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509Certificate::ToString(System.Boolean)
extern "C"  String_t* X509Certificate_ToString_m_2084474520_0 (X509Certificate_t1524084820_0 * __this, bool ___fVerbose, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509Certificate::get_Issuer()
extern "C"  String_t* X509Certificate_get_Issuer_m681285767_0 (X509Certificate_t1524084820_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509Certificate::get_Subject()
extern "C"  String_t* X509Certificate_get_Subject_m_281987648_0 (X509Certificate_t1524084820_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Security.Cryptography.X509Certificates.X509Certificate::Equals(System.Object)
extern "C"  bool X509Certificate_Equals_m_1329419665_0 (X509Certificate_t1524084820_0 * __this, Object_t * ___obj, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Certificate::Import(System.Byte[],System.String,System.Security.Cryptography.X509Certificates.X509KeyStorageFlags)
extern "C"  void X509Certificate_Import_m2045724600_0 (X509Certificate_t1524084820_0 * __this, ByteU5BU5D_t_1238178395_0* ___rawData, String_t* ___password, int32_t ___keyStorageFlags, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Certificate::Reset()
extern "C"  void X509Certificate_Reset_m_125048279_0 (X509Certificate_t1524084820_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
