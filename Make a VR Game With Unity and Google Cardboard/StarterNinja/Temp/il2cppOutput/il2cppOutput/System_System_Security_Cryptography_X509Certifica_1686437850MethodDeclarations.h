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

// System.Security.Cryptography.X509Certificates.X509Extension
struct X509Extension_t_1686437850_0;
// System.String
struct String_t;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Security.Cryptography.AsnEncodedData
struct AsnEncodedData_t_194939595_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Security.Cryptography.X509Certificates.X509Extension::.ctor()
extern "C"  void X509Extension__ctor_m1164925482_0 (X509Extension_t_1686437850_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Extension::.ctor(System.String,System.Byte[],System.Boolean)
extern "C"  void X509Extension__ctor_m_2025037310_0 (X509Extension_t_1686437850_0 * __this, String_t* ___oid, ByteU5BU5D_t_1238178395_0* ___rawData, bool ___critical, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Security.Cryptography.X509Certificates.X509Extension::get_Critical()
extern "C"  bool X509Extension_get_Critical_m1925069548_0 (X509Extension_t_1686437850_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Extension::set_Critical(System.Boolean)
extern "C"  void X509Extension_set_Critical_m717701037_0 (X509Extension_t_1686437850_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Extension::CopyFrom(System.Security.Cryptography.AsnEncodedData)
extern "C"  void X509Extension_CopyFrom_m_456916950_0 (X509Extension_t_1686437850_0 * __this, AsnEncodedData_t_194939595_0 * ___asnEncodedData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509Extension::FormatUnkownData(System.Byte[])
extern "C"  String_t* X509Extension_FormatUnkownData_m_60566915_0 (X509Extension_t_1686437850_0 * __this, ByteU5BU5D_t_1238178395_0* ___data, const MethodInfo* method) IL2CPP_METHOD_ATTR;
