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

// System.Security.Cryptography.X509Certificates.X509KeyUsageExtension
struct X509KeyUsageExtension_t_1020729148_0;
// System.Security.Cryptography.AsnEncodedData
struct AsnEncodedData_t_194939595_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "System_System_Security_Cryptography_X509Certificate729335180.h"
#include "System_System_Security_Cryptography_AsnDecodeStatus968051651.h"

// System.Void System.Security.Cryptography.X509Certificates.X509KeyUsageExtension::.ctor()
extern "C"  void X509KeyUsageExtension__ctor_m_507713972_0 (X509KeyUsageExtension_t_1020729148_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509KeyUsageExtension::.ctor(System.Security.Cryptography.AsnEncodedData,System.Boolean)
extern "C"  void X509KeyUsageExtension__ctor_m_1884904378_0 (X509KeyUsageExtension_t_1020729148_0 * __this, AsnEncodedData_t_194939595_0 * ___encodedKeyUsage, bool ___critical, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509KeyUsageExtension::.ctor(System.Security.Cryptography.X509Certificates.X509KeyUsageFlags,System.Boolean)
extern "C"  void X509KeyUsageExtension__ctor_m_962701795_0 (X509KeyUsageExtension_t_1020729148_0 * __this, int32_t ___keyUsages, bool ___critical, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509KeyUsageFlags System.Security.Cryptography.X509Certificates.X509KeyUsageExtension::get_KeyUsages()
extern "C"  int32_t X509KeyUsageExtension_get_KeyUsages_m_1117935937_0 (X509KeyUsageExtension_t_1020729148_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509KeyUsageExtension::CopyFrom(System.Security.Cryptography.AsnEncodedData)
extern "C"  void X509KeyUsageExtension_CopyFrom_m1769316556_0 (X509KeyUsageExtension_t_1020729148_0 * __this, AsnEncodedData_t_194939595_0 * ___encodedData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509KeyUsageFlags System.Security.Cryptography.X509Certificates.X509KeyUsageExtension::GetValidFlags(System.Security.Cryptography.X509Certificates.X509KeyUsageFlags)
extern "C"  int32_t X509KeyUsageExtension_GetValidFlags_m1081049684_0 (X509KeyUsageExtension_t_1020729148_0 * __this, int32_t ___flags, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.AsnDecodeStatus System.Security.Cryptography.X509Certificates.X509KeyUsageExtension::Decode(System.Byte[])
extern "C"  int32_t X509KeyUsageExtension_Decode_m811458265_0 (X509KeyUsageExtension_t_1020729148_0 * __this, ByteU5BU5D_t_1238178395_0* ___extension, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Security.Cryptography.X509Certificates.X509KeyUsageExtension::Encode()
extern "C"  ByteU5BU5D_t_1238178395_0* X509KeyUsageExtension_Encode_m1941209444_0 (X509KeyUsageExtension_t_1020729148_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509KeyUsageExtension::ToString(System.Boolean)
extern "C"  String_t* X509KeyUsageExtension_ToString_m1884016728_0 (X509KeyUsageExtension_t_1020729148_0 * __this, bool ___multiLine, const MethodInfo* method) IL2CPP_METHOD_ATTR;
