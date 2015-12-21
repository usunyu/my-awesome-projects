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

// System.Security.Cryptography.X509Certificates.X509EnhancedKeyUsageExtension
struct X509EnhancedKeyUsageExtension_t_923707154_0;
// System.Security.Cryptography.AsnEncodedData
struct AsnEncodedData_t_194939595_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "System_System_Security_Cryptography_AsnDecodeStatus968051651.h"

// System.Void System.Security.Cryptography.X509Certificates.X509EnhancedKeyUsageExtension::.ctor(System.Security.Cryptography.AsnEncodedData,System.Boolean)
extern "C"  void X509EnhancedKeyUsageExtension__ctor_m1143045852_0 (X509EnhancedKeyUsageExtension_t_923707154_0 * __this, AsnEncodedData_t_194939595_0 * ___encodedEnhancedKeyUsages, bool ___critical, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509EnhancedKeyUsageExtension::CopyFrom(System.Security.Cryptography.AsnEncodedData)
extern "C"  void X509EnhancedKeyUsageExtension_CopyFrom_m_735892382_0 (X509EnhancedKeyUsageExtension_t_923707154_0 * __this, AsnEncodedData_t_194939595_0 * ___asnEncodedData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.AsnDecodeStatus System.Security.Cryptography.X509Certificates.X509EnhancedKeyUsageExtension::Decode(System.Byte[])
extern "C"  int32_t X509EnhancedKeyUsageExtension_Decode_m_381719441_0 (X509EnhancedKeyUsageExtension_t_923707154_0 * __this, ByteU5BU5D_t_1238178395_0* ___extension, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509EnhancedKeyUsageExtension::ToString(System.Boolean)
extern "C"  String_t* X509EnhancedKeyUsageExtension_ToString_m554823682_0 (X509EnhancedKeyUsageExtension_t_923707154_0 * __this, bool ___multiLine, const MethodInfo* method) IL2CPP_METHOD_ATTR;
