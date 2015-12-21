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

// Mono.Security.X509.X509Crl
struct X509Crl_t_956935956_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// Mono.Security.X509.X509ExtensionCollection
struct X509ExtensionCollection_t_1920699060_0;
// System.String
struct String_t;
// Mono.Security.X509.X509Crl/X509CrlEntry
struct X509CrlEntry_t_830724962_0;
// Mono.Security.X509.X509Certificate
struct X509Certificate_t219648422_0;
// System.Security.Cryptography.DSA
struct DSA_t1573103491_0;
// System.Security.Cryptography.RSA
struct RSA_t1573116945_0;
// System.Security.Cryptography.AsymmetricAlgorithm
struct AsymmetricAlgorithm_t1451338986_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_DateTime_818288618.h"

// System.Void Mono.Security.X509.X509Crl::.ctor(System.Byte[])
extern "C"  void X509Crl__ctor_m1270803331_0 (X509Crl_t_956935956_0 * __this, ByteU5BU5D_t_1238178395_0* ___crl, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.X509Crl::Parse(System.Byte[])
extern "C"  void X509Crl_Parse_m_1190916078_0 (X509Crl_t_956935956_0 * __this, ByteU5BU5D_t_1238178395_0* ___crl, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.X509.X509ExtensionCollection Mono.Security.X509.X509Crl::get_Extensions()
extern "C"  X509ExtensionCollection_t_1920699060_0 * X509Crl_get_Extensions_m_1915263804_0 (X509Crl_t_956935956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.X509.X509Crl::get_Hash()
extern "C"  ByteU5BU5D_t_1238178395_0* X509Crl_get_Hash_m_2069091009_0 (X509Crl_t_956935956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.X509.X509Crl::get_IssuerName()
extern "C"  String_t* X509Crl_get_IssuerName_m_1274426262_0 (X509Crl_t_956935956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime Mono.Security.X509.X509Crl::get_NextUpdate()
extern "C"  DateTime_t_818288618_0  X509Crl_get_NextUpdate_m1145701656_0 (X509Crl_t_956935956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.X509.X509Crl::Compare(System.Byte[],System.Byte[])
extern "C"  bool X509Crl_Compare_m1588393905_0 (X509Crl_t_956935956_0 * __this, ByteU5BU5D_t_1238178395_0* ___array1, ByteU5BU5D_t_1238178395_0* ___array2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.X509.X509Crl/X509CrlEntry Mono.Security.X509.X509Crl::GetCrlEntry(Mono.Security.X509.X509Certificate)
extern "C"  X509CrlEntry_t_830724962_0 * X509Crl_GetCrlEntry_m698190412_0 (X509Crl_t_956935956_0 * __this, X509Certificate_t219648422_0 * ___x509, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.X509.X509Crl/X509CrlEntry Mono.Security.X509.X509Crl::GetCrlEntry(System.Byte[])
extern "C"  X509CrlEntry_t_830724962_0 * X509Crl_GetCrlEntry_m1555363125_0 (X509Crl_t_956935956_0 * __this, ByteU5BU5D_t_1238178395_0* ___serialNumber, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.X509.X509Crl::GetHashName()
extern "C"  String_t* X509Crl_GetHashName_m_978286256_0 (X509Crl_t_956935956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.X509.X509Crl::VerifySignature(System.Security.Cryptography.DSA)
extern "C"  bool X509Crl_VerifySignature_m1549750422_0 (X509Crl_t_956935956_0 * __this, DSA_t1573103491_0 * ___dsa, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.X509.X509Crl::VerifySignature(System.Security.Cryptography.RSA)
extern "C"  bool X509Crl_VerifySignature_m1550167496_0 (X509Crl_t_956935956_0 * __this, RSA_t1573116945_0 * ___rsa, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.X509.X509Crl::VerifySignature(System.Security.Cryptography.AsymmetricAlgorithm)
extern "C"  bool X509Crl_VerifySignature_m_175878101_0 (X509Crl_t_956935956_0 * __this, AsymmetricAlgorithm_t1451338986_0 * ___aa, const MethodInfo* method) IL2CPP_METHOD_ATTR;
