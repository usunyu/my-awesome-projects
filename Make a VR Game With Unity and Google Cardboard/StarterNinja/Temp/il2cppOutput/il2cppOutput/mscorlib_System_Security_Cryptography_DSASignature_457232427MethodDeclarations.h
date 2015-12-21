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

// System.Security.Cryptography.DSASignatureFormatter
struct DSASignatureFormatter_t_457232427_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.String
struct String_t;
// System.Security.Cryptography.AsymmetricAlgorithm
struct AsymmetricAlgorithm_t1451338986_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Security.Cryptography.DSASignatureFormatter::.ctor()
extern "C"  void DSASignatureFormatter__ctor_m1468419489_0 (DSASignatureFormatter_t_457232427_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Security.Cryptography.DSASignatureFormatter::CreateSignature(System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* DSASignatureFormatter_CreateSignature_m_508098440_0 (DSASignatureFormatter_t_457232427_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgbHash, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.DSASignatureFormatter::SetHashAlgorithm(System.String)
extern "C"  void DSASignatureFormatter_SetHashAlgorithm_m976206784_0 (DSASignatureFormatter_t_457232427_0 * __this, String_t* ___strName, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.DSASignatureFormatter::SetKey(System.Security.Cryptography.AsymmetricAlgorithm)
extern "C"  void DSASignatureFormatter_SetKey_m_184670182_0 (DSASignatureFormatter_t_457232427_0 * __this, AsymmetricAlgorithm_t1451338986_0 * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
