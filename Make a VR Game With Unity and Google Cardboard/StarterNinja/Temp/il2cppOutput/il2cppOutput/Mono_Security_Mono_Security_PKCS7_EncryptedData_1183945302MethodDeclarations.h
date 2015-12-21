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

// Mono.Security.PKCS7/EncryptedData
struct EncryptedData_t_1183945302_0;
// Mono.Security.ASN1
struct ASN1_t311288114_0;
// Mono.Security.PKCS7/ContentInfo
struct ContentInfo_t851923427_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.PKCS7/EncryptedData::.ctor()
extern "C"  void EncryptedData__ctor_m1149165926_0 (EncryptedData_t_1183945302_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.PKCS7/EncryptedData::.ctor(Mono.Security.ASN1)
extern "C"  void EncryptedData__ctor_m794340270_0 (EncryptedData_t_1183945302_0 * __this, ASN1_t311288114_0 * ___asn1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.PKCS7/ContentInfo Mono.Security.PKCS7/EncryptedData::get_EncryptionAlgorithm()
extern "C"  ContentInfo_t851923427_0 * EncryptedData_get_EncryptionAlgorithm_m_295921991_0 (EncryptedData_t_1183945302_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.PKCS7/EncryptedData::get_EncryptedContent()
extern "C"  ByteU5BU5D_t_1238178395_0* EncryptedData_get_EncryptedContent_m_1519760750_0 (EncryptedData_t_1183945302_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
