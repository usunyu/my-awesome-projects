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

// Mono.Security.Cryptography.RSAManaged
struct RSAManaged_t_108115836_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.String
struct String_t;
// Mono.Math.BigInteger
struct BigInteger_t_19408649_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Security_Cryptography_RSAParameter1157257435.h"

// System.Void Mono.Security.Cryptography.RSAManaged::.ctor()
extern "C"  void RSAManaged__ctor_m_916231120_0 (RSAManaged_t_108115836_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.RSAManaged::.ctor(System.Int32)
extern "C"  void RSAManaged__ctor_m_490710655_0 (RSAManaged_t_108115836_0 * __this, int32_t ___keySize, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.RSAManaged::Finalize()
extern "C"  void RSAManaged_Finalize_m_821623246_0 (RSAManaged_t_108115836_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.RSAManaged::GenerateKeyPair()
extern "C"  void RSAManaged_GenerateKeyPair_m1998786226_0 (RSAManaged_t_108115836_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Cryptography.RSAManaged::get_KeySize()
extern "C"  int32_t RSAManaged_get_KeySize_m_433449523_0 (RSAManaged_t_108115836_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Cryptography.RSAManaged::get_PublicOnly()
extern "C"  bool RSAManaged_get_PublicOnly_m_1228012256_0 (RSAManaged_t_108115836_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Cryptography.RSAManaged::DecryptValue(System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* RSAManaged_DecryptValue_m_549236869_0 (RSAManaged_t_108115836_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgb, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Cryptography.RSAManaged::EncryptValue(System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* RSAManaged_EncryptValue_m691555411_0 (RSAManaged_t_108115836_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgb, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.RSAParameters Mono.Security.Cryptography.RSAManaged::ExportParameters(System.Boolean)
extern "C"  RSAParameters_t1157257435_0  RSAManaged_ExportParameters_m447046473_0 (RSAManaged_t_108115836_0 * __this, bool ___includePrivateParameters, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.RSAManaged::ImportParameters(System.Security.Cryptography.RSAParameters)
extern "C"  void RSAManaged_ImportParameters_m_383874388_0 (RSAManaged_t_108115836_0 * __this, RSAParameters_t1157257435_0  ___parameters, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.RSAManaged::Dispose(System.Boolean)
extern "C"  void RSAManaged_Dispose_m_1976107228_0 (RSAManaged_t_108115836_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.Cryptography.RSAManaged::ToXmlString(System.Boolean)
extern "C"  String_t* RSAManaged_ToXmlString_m_1325065739_0 (RSAManaged_t_108115836_0 * __this, bool ___includePrivateParameters, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Cryptography.RSAManaged::GetPaddedValue(Mono.Math.BigInteger,System.Int32)
extern "C"  ByteU5BU5D_t_1238178395_0* RSAManaged_GetPaddedValue_m_349041573_0 (RSAManaged_t_108115836_0 * __this, BigInteger_t_19408649_0 * ___value, int32_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
