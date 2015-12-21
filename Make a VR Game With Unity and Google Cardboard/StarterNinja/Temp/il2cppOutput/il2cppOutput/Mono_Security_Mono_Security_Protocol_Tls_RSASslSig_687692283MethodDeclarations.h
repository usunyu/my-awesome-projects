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

// Mono.Security.Protocol.Tls.RSASslSignatureDeformatter
struct RSASslSignatureDeformatter_t_687692283_0;
// System.Security.Cryptography.AsymmetricAlgorithm
struct AsymmetricAlgorithm_t1451338986_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.Protocol.Tls.RSASslSignatureDeformatter::.ctor(System.Security.Cryptography.AsymmetricAlgorithm)
extern "C"  void RSASslSignatureDeformatter__ctor_m_54613339_0 (RSASslSignatureDeformatter_t_687692283_0 * __this, AsymmetricAlgorithm_t1451338986_0 * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.RSASslSignatureDeformatter::VerifySignature(System.Byte[],System.Byte[])
extern "C"  bool RSASslSignatureDeformatter_VerifySignature_m_882902922_0 (RSASslSignatureDeformatter_t_687692283_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgbHash, ByteU5BU5D_t_1238178395_0* ___rgbSignature, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.RSASslSignatureDeformatter::SetHashAlgorithm(System.String)
extern "C"  void RSASslSignatureDeformatter_SetHashAlgorithm_m1915873034_0 (RSASslSignatureDeformatter_t_687692283_0 * __this, String_t* ___strName, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.RSASslSignatureDeformatter::SetKey(System.Security.Cryptography.AsymmetricAlgorithm)
extern "C"  void RSASslSignatureDeformatter_SetKey_m1829004304_0 (RSASslSignatureDeformatter_t_687692283_0 * __this, AsymmetricAlgorithm_t1451338986_0 * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
