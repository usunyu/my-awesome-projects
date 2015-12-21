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

// Mono.Security.Protocol.Tls.SslHandshakeHash
struct SslHandshakeHash_t_50906207_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Security.Cryptography.RSA
struct RSA_t1573116945_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.Protocol.Tls.SslHandshakeHash::.ctor(System.Byte[])
extern "C"  void SslHandshakeHash__ctor_m1720849178_0 (SslHandshakeHash_t_50906207_0 * __this, ByteU5BU5D_t_1238178395_0* ___secret, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslHandshakeHash::Initialize()
extern "C"  void SslHandshakeHash_Initialize_m_1076802843_0 (SslHandshakeHash_t_50906207_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.SslHandshakeHash::HashFinal()
extern "C"  ByteU5BU5D_t_1238178395_0* SslHandshakeHash_HashFinal_m1716921183_0 (SslHandshakeHash_t_50906207_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslHandshakeHash::HashCore(System.Byte[],System.Int32,System.Int32)
extern "C"  void SslHandshakeHash_HashCore_m1118046919_0 (SslHandshakeHash_t_50906207_0 * __this, ByteU5BU5D_t_1238178395_0* ___array, int32_t ___ibStart, int32_t ___cbSize, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.SslHandshakeHash::CreateSignature(System.Security.Cryptography.RSA)
extern "C"  ByteU5BU5D_t_1238178395_0* SslHandshakeHash_CreateSignature_m1753519462_0 (SslHandshakeHash_t_50906207_0 * __this, RSA_t1573116945_0 * ___rsa, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslHandshakeHash::initializePad()
extern "C"  void SslHandshakeHash_initializePad_m1112962160_0 (SslHandshakeHash_t_50906207_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
