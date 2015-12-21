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

// Mono.Security.X509.X509Extension
struct X509Extension_t_556260338_0;
// Mono.Security.ASN1
struct ASN1_t311288114_0;
// System.String
struct String_t;
// System.Object
struct Object_t;
// System.Text.StringBuilder
struct StringBuilder_t586045924_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.X509.X509Extension::.ctor(Mono.Security.ASN1)
extern "C"  void X509Extension__ctor_m_1406445396_0 (X509Extension_t_556260338_0 * __this, ASN1_t311288114_0 * ___asn1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.X509Extension::.ctor(Mono.Security.X509.X509Extension)
extern "C"  void X509Extension__ctor_m_996949872_0 (X509Extension_t_556260338_0 * __this, X509Extension_t_556260338_0 * ___extension, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.X509Extension::Decode()
extern "C"  void X509Extension_Decode_m_28098162_0 (X509Extension_t_556260338_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.X509Extension::Encode()
extern "C"  void X509Extension_Encode_m1112310710_0 (X509Extension_t_556260338_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.X509.X509Extension::get_Oid()
extern "C"  String_t* X509Extension_get_Oid_m1309247492_0 (X509Extension_t_556260338_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.X509.X509Extension::get_Critical()
extern "C"  bool X509Extension_get_Critical_m_1284508422_0 (X509Extension_t_556260338_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.ASN1 Mono.Security.X509.X509Extension::get_Value()
extern "C"  ASN1_t311288114_0 * X509Extension_get_Value_m1722264871_0 (X509Extension_t_556260338_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.X509.X509Extension::Equals(System.Object)
extern "C"  bool X509Extension_Equals_m131878599_0 (X509Extension_t_556260338_0 * __this, Object_t * ___obj, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.X509.X509Extension::GetHashCode()
extern "C"  int32_t X509Extension_GetHashCode_m1621273003_0 (X509Extension_t_556260338_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.X509Extension::WriteLine(System.Text.StringBuilder,System.Int32,System.Int32)
extern "C"  void X509Extension_WriteLine_m_29864843_0 (X509Extension_t_556260338_0 * __this, StringBuilder_t586045924_0 * ___sb, int32_t ___n, int32_t ___pos, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.X509.X509Extension::ToString()
extern "C"  String_t* X509Extension_ToString_m1923324847_0 (X509Extension_t_556260338_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
