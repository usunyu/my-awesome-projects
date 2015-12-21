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

// System.Security.Cryptography.HMAC
struct HMAC_t1521681430_0;
// System.String
struct String_t;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// Mono.Security.Cryptography.BlockProcessor
struct BlockProcessor_t1173076704_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Security.Cryptography.HMAC::.ctor()
extern "C"  void HMAC__ctor_m1246202746_0 (HMAC_t1521681430_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Security.Cryptography.HMAC::get_BlockSizeValue()
extern "C"  int32_t HMAC_get_BlockSizeValue_m1165487130_0 (HMAC_t1521681430_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.HMAC::set_BlockSizeValue(System.Int32)
extern "C"  void HMAC_set_BlockSizeValue_m_1904227717_0 (HMAC_t1521681430_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.HMAC::set_HashName(System.String)
extern "C"  void HMAC_set_HashName_m876988162_0 (HMAC_t1521681430_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Security.Cryptography.HMAC::get_Key()
extern "C"  ByteU5BU5D_t_1238178395_0* HMAC_get_Key_m1472198904_0 (HMAC_t1521681430_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.HMAC::set_Key(System.Byte[])
extern "C"  void HMAC_set_Key_m_2000053585_0 (HMAC_t1521681430_0 * __this, ByteU5BU5D_t_1238178395_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Cryptography.BlockProcessor System.Security.Cryptography.HMAC::get_Block()
extern "C"  BlockProcessor_t1173076704_0 * HMAC_get_Block_m1790455563_0 (HMAC_t1521681430_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Security.Cryptography.HMAC::KeySetup(System.Byte[],System.Byte)
extern "C"  ByteU5BU5D_t_1238178395_0* HMAC_KeySetup_m198221232_0 (HMAC_t1521681430_0 * __this, ByteU5BU5D_t_1238178395_0* ___key, uint8_t ___padding, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.HMAC::Dispose(System.Boolean)
extern "C"  void HMAC_Dispose_m_1508423058_0 (HMAC_t1521681430_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.HMAC::HashCore(System.Byte[],System.Int32,System.Int32)
extern "C"  void HMAC_HashCore_m_2131393678_0 (HMAC_t1521681430_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgb, int32_t ___ib, int32_t ___cb, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Security.Cryptography.HMAC::HashFinal()
extern "C"  ByteU5BU5D_t_1238178395_0* HMAC_HashFinal_m_1622640822_0 (HMAC_t1521681430_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.HMAC::Initialize()
extern "C"  void HMAC_Initialize_m1079175002_0 (HMAC_t1521681430_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.HMAC System.Security.Cryptography.HMAC::Create()
extern "C"  HMAC_t1521681430_0 * HMAC_Create_m_1075579827_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.HMAC System.Security.Cryptography.HMAC::Create(System.String)
extern "C"  HMAC_t1521681430_0 * HMAC_Create_m_1824534571_0 (Object_t * __this /* static, unused */, String_t* ___algorithmName, const MethodInfo* method) IL2CPP_METHOD_ATTR;
