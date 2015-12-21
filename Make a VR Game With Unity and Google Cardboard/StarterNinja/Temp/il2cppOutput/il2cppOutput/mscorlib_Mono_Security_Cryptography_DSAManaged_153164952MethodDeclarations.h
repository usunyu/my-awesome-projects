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

// Mono.Security.Cryptography.DSAManaged
struct DSAManaged_t_153164952_0;
// Mono.Security.Cryptography.DSAManaged/KeyGeneratedEventHandler
struct KeyGeneratedEventHandler_t_498956729_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Security.Cryptography.RandomNumberGenerator
struct RandomNumberGenerator_t1902086616_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Security_Cryptography_DSAParameters969932237.h"

// System.Void Mono.Security.Cryptography.DSAManaged::.ctor(System.Int32)
extern "C"  void DSAManaged__ctor_m1342239545_0 (DSAManaged_t_153164952_0 * __this, int32_t ___dwKeySize, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.DSAManaged::add_KeyGenerated(Mono.Security.Cryptography.DSAManaged/KeyGeneratedEventHandler)
extern "C"  void DSAManaged_add_KeyGenerated_m1677002343_0 (DSAManaged_t_153164952_0 * __this, KeyGeneratedEventHandler_t_498956729_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.DSAManaged::remove_KeyGenerated(Mono.Security.Cryptography.DSAManaged/KeyGeneratedEventHandler)
extern "C"  void DSAManaged_remove_KeyGenerated_m_430206322_0 (DSAManaged_t_153164952_0 * __this, KeyGeneratedEventHandler_t_498956729_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.DSAManaged::Finalize()
extern "C"  void DSAManaged_Finalize_m_961012358_0 (DSAManaged_t_153164952_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.DSAManaged::Generate()
extern "C"  void DSAManaged_Generate_m1196580113_0 (DSAManaged_t_153164952_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.DSAManaged::GenerateKeyPair()
extern "C"  void DSAManaged_GenerateKeyPair_m414103146_0 (DSAManaged_t_153164952_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.DSAManaged::add(System.Byte[],System.Byte[],System.Int32)
extern "C"  void DSAManaged_add_m_654300910_0 (DSAManaged_t_153164952_0 * __this, ByteU5BU5D_t_1238178395_0* ___a, ByteU5BU5D_t_1238178395_0* ___b, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.DSAManaged::GenerateParams(System.Int32)
extern "C"  void DSAManaged_GenerateParams_m_1452949496_0 (DSAManaged_t_153164952_0 * __this, int32_t ___keyLength, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.RandomNumberGenerator Mono.Security.Cryptography.DSAManaged::get_Random()
extern "C"  RandomNumberGenerator_t1902086616_0 * DSAManaged_get_Random_m1436172465_0 (DSAManaged_t_153164952_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Cryptography.DSAManaged::get_KeySize()
extern "C"  int32_t DSAManaged_get_KeySize_m_995320135_0 (DSAManaged_t_153164952_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Cryptography.DSAManaged::get_PublicOnly()
extern "C"  bool DSAManaged_get_PublicOnly_m_1914110440_0 (DSAManaged_t_153164952_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Cryptography.DSAManaged::NormalizeArray(System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* DSAManaged_NormalizeArray_m_1978843253_0 (DSAManaged_t_153164952_0 * __this, ByteU5BU5D_t_1238178395_0* ___array, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.DSAParameters Mono.Security.Cryptography.DSAManaged::ExportParameters(System.Boolean)
extern "C"  DSAParameters_t969932237_0  DSAManaged_ExportParameters_m_77930673_0 (DSAManaged_t_153164952_0 * __this, bool ___includePrivateParameters, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.DSAManaged::ImportParameters(System.Security.Cryptography.DSAParameters)
extern "C"  void DSAManaged_ImportParameters_m_683984574_0 (DSAManaged_t_153164952_0 * __this, DSAParameters_t969932237_0  ___parameters, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Cryptography.DSAManaged::CreateSignature(System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* DSAManaged_CreateSignature_m_1459948611_0 (DSAManaged_t_153164952_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgbHash, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Cryptography.DSAManaged::VerifySignature(System.Byte[],System.Byte[])
extern "C"  bool DSAManaged_VerifySignature_m_1773060507_0 (DSAManaged_t_153164952_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgbHash, ByteU5BU5D_t_1238178395_0* ___rgbSignature, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.DSAManaged::Dispose(System.Boolean)
extern "C"  void DSAManaged_Dispose_m_844890916_0 (DSAManaged_t_153164952_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
