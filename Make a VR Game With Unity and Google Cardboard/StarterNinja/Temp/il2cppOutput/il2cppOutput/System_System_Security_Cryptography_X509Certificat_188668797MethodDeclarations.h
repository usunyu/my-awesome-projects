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

// System.Security.Cryptography.X509Certificates.PublicKey
struct PublicKey_t_188668797_0;
// Mono.Security.X509.X509Certificate
struct X509Certificate_t219648422_0;
// System.Security.Cryptography.AsnEncodedData
struct AsnEncodedData_t_194939595_0;
// System.Security.Cryptography.AsymmetricAlgorithm
struct AsymmetricAlgorithm_t1451338986_0;
// System.Security.Cryptography.Oid
struct Oid_t1024680945_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Security.Cryptography.DSA
struct DSA_t1573103491_0;
// System.Security.Cryptography.RSA
struct RSA_t1573116945_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Security.Cryptography.X509Certificates.PublicKey::.ctor(Mono.Security.X509.X509Certificate)
extern "C"  void PublicKey__ctor_m1299060097_0 (PublicKey_t_188668797_0 * __this, X509Certificate_t219648422_0 * ___certificate, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.AsnEncodedData System.Security.Cryptography.X509Certificates.PublicKey::get_EncodedKeyValue()
extern "C"  AsnEncodedData_t_194939595_0 * PublicKey_get_EncodedKeyValue_m334858790_0 (PublicKey_t_188668797_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.AsnEncodedData System.Security.Cryptography.X509Certificates.PublicKey::get_EncodedParameters()
extern "C"  AsnEncodedData_t_194939595_0 * PublicKey_get_EncodedParameters_m_616556802_0 (PublicKey_t_188668797_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.AsymmetricAlgorithm System.Security.Cryptography.X509Certificates.PublicKey::get_Key()
extern "C"  AsymmetricAlgorithm_t1451338986_0 * PublicKey_get_Key_m_2000693542_0 (PublicKey_t_188668797_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.Oid System.Security.Cryptography.X509Certificates.PublicKey::get_Oid()
extern "C"  Oid_t1024680945_0 * PublicKey_get_Oid_m100819764_0 (PublicKey_t_188668797_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Security.Cryptography.X509Certificates.PublicKey::GetUnsignedBigInteger(System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* PublicKey_GetUnsignedBigInteger_m_1563069781_0 (Object_t * __this /* static, unused */, ByteU5BU5D_t_1238178395_0* ___integer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.DSA System.Security.Cryptography.X509Certificates.PublicKey::DecodeDSA(System.Byte[],System.Byte[])
extern "C"  DSA_t1573103491_0 * PublicKey_DecodeDSA_m_1594122979_0 (Object_t * __this /* static, unused */, ByteU5BU5D_t_1238178395_0* ___rawPublicKey, ByteU5BU5D_t_1238178395_0* ___rawParameters, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.RSA System.Security.Cryptography.X509Certificates.PublicKey::DecodeRSA(System.Byte[])
extern "C"  RSA_t1573116945_0 * PublicKey_DecodeRSA_m_459258790_0 (Object_t * __this /* static, unused */, ByteU5BU5D_t_1238178395_0* ___rawPublicKey, const MethodInfo* method) IL2CPP_METHOD_ATTR;
