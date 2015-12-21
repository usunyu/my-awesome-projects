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

// Mono.Security.Cryptography.HMAC
struct HMAC_t386776168_0;
// System.String
struct String_t;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.Cryptography.HMAC::.ctor(System.String,System.Byte[])
extern "C"  void HMAC__ctor_m_325223459_0 (HMAC_t386776168_0 * __this, String_t* ___hashName, ByteU5BU5D_t_1238178395_0* ___rgbKey, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Cryptography.HMAC::get_Key()
extern "C"  ByteU5BU5D_t_1238178395_0* HMAC_get_Key_m_1534759514_0 (HMAC_t386776168_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.HMAC::set_Key(System.Byte[])
extern "C"  void HMAC_set_Key_m1481428161_0 (HMAC_t386776168_0 * __this, ByteU5BU5D_t_1238178395_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.HMAC::Initialize()
extern "C"  void HMAC_Initialize_m1123559404_0 (HMAC_t386776168_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Cryptography.HMAC::HashFinal()
extern "C"  ByteU5BU5D_t_1238178395_0* HMAC_HashFinal_m_796690312_0 (HMAC_t386776168_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.HMAC::HashCore(System.Byte[],System.Int32,System.Int32)
extern "C"  void HMAC_HashCore_m_642410976_0 (HMAC_t386776168_0 * __this, ByteU5BU5D_t_1238178395_0* ___array, int32_t ___ibStart, int32_t ___cbSize, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.HMAC::initializePad()
extern "C"  void HMAC_initializePad_m_1981176311_0 (HMAC_t386776168_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
