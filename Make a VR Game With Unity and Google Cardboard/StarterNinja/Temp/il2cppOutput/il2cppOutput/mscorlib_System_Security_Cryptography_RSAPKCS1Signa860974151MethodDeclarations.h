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

// System.Security.Cryptography.RSAPKCS1SignatureFormatter
struct RSAPKCS1SignatureFormatter_t860974151_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.String
struct String_t;
// System.Security.Cryptography.AsymmetricAlgorithm
struct AsymmetricAlgorithm_t1451338986_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Security.Cryptography.RSAPKCS1SignatureFormatter::.ctor()
extern "C"  void RSAPKCS1SignatureFormatter__ctor_m_1083612503_0 (RSAPKCS1SignatureFormatter_t860974151_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Security.Cryptography.RSAPKCS1SignatureFormatter::CreateSignature(System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* RSAPKCS1SignatureFormatter_CreateSignature_m894707804_0 (RSAPKCS1SignatureFormatter_t860974151_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgbHash, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RSAPKCS1SignatureFormatter::SetHashAlgorithm(System.String)
extern "C"  void RSAPKCS1SignatureFormatter_SetHashAlgorithm_m15087816_0 (RSAPKCS1SignatureFormatter_t860974151_0 * __this, String_t* ___strName, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RSAPKCS1SignatureFormatter::SetKey(System.Security.Cryptography.AsymmetricAlgorithm)
extern "C"  void RSAPKCS1SignatureFormatter_SetKey_m862512146_0 (RSAPKCS1SignatureFormatter_t860974151_0 * __this, AsymmetricAlgorithm_t1451338986_0 * ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
