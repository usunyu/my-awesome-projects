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

// System.Security.Cryptography.AsnEncodedData
struct AsnEncodedData_t_194939595_0;
// System.String
struct String_t;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Security.Cryptography.Oid
struct Oid_t1024680945_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Security.Cryptography.AsnEncodedData::.ctor()
extern "C"  void AsnEncodedData__ctor_m_78913541_0 (AsnEncodedData_t_194939595_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.AsnEncodedData::.ctor(System.String,System.Byte[])
extern "C"  void AsnEncodedData__ctor_m_1453672534_0 (AsnEncodedData_t_194939595_0 * __this, String_t* ___oid, ByteU5BU5D_t_1238178395_0* ___rawData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.AsnEncodedData::.ctor(System.Security.Cryptography.Oid,System.Byte[])
extern "C"  void AsnEncodedData__ctor_m299043111_0 (AsnEncodedData_t_194939595_0 * __this, Oid_t1024680945_0 * ___oid, ByteU5BU5D_t_1238178395_0* ___rawData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.Oid System.Security.Cryptography.AsnEncodedData::get_Oid()
extern "C"  Oid_t1024680945_0 * AsnEncodedData_get_Oid_m_2033850686_0 (AsnEncodedData_t_194939595_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.AsnEncodedData::set_Oid(System.Security.Cryptography.Oid)
extern "C"  void AsnEncodedData_set_Oid_m865125231_0 (AsnEncodedData_t_194939595_0 * __this, Oid_t1024680945_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Security.Cryptography.AsnEncodedData::get_RawData()
extern "C"  ByteU5BU5D_t_1238178395_0* AsnEncodedData_get_RawData_m334685068_0 (AsnEncodedData_t_194939595_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.AsnEncodedData::set_RawData(System.Byte[])
extern "C"  void AsnEncodedData_set_RawData_m839792539_0 (AsnEncodedData_t_194939595_0 * __this, ByteU5BU5D_t_1238178395_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.AsnEncodedData::CopyFrom(System.Security.Cryptography.AsnEncodedData)
extern "C"  void AsnEncodedData_CopyFrom_m406388795_0 (AsnEncodedData_t_194939595_0 * __this, AsnEncodedData_t_194939595_0 * ___asnEncodedData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.AsnEncodedData::ToString(System.Boolean)
extern "C"  String_t* AsnEncodedData_ToString_m_1296109175_0 (AsnEncodedData_t_194939595_0 * __this, bool ___multiLine, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.AsnEncodedData::Default(System.Boolean)
extern "C"  String_t* AsnEncodedData_Default_m_2112707084_0 (AsnEncodedData_t_194939595_0 * __this, bool ___multiLine, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.AsnEncodedData::BasicConstraintsExtension(System.Boolean)
extern "C"  String_t* AsnEncodedData_BasicConstraintsExtension_m1615975146_0 (AsnEncodedData_t_194939595_0 * __this, bool ___multiLine, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.AsnEncodedData::EnhancedKeyUsageExtension(System.Boolean)
extern "C"  String_t* AsnEncodedData_EnhancedKeyUsageExtension_m45972986_0 (AsnEncodedData_t_194939595_0 * __this, bool ___multiLine, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.AsnEncodedData::KeyUsageExtension(System.Boolean)
extern "C"  String_t* AsnEncodedData_KeyUsageExtension_m_1234029104_0 (AsnEncodedData_t_194939595_0 * __this, bool ___multiLine, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.AsnEncodedData::SubjectKeyIdentifierExtension(System.Boolean)
extern "C"  String_t* AsnEncodedData_SubjectKeyIdentifierExtension_m_569599370_0 (AsnEncodedData_t_194939595_0 * __this, bool ___multiLine, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.AsnEncodedData::SubjectAltName(System.Boolean)
extern "C"  String_t* AsnEncodedData_SubjectAltName_m1574931557_0 (AsnEncodedData_t_194939595_0 * __this, bool ___multiLine, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.AsnEncodedData::NetscapeCertType(System.Boolean)
extern "C"  String_t* AsnEncodedData_NetscapeCertType_m_1847274236_0 (AsnEncodedData_t_194939595_0 * __this, bool ___multiLine, const MethodInfo* method) IL2CPP_METHOD_ATTR;
