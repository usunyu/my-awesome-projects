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

// System.Security.Cryptography.SHA384Managed
struct SHA384Managed_t352992365_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Security.Cryptography.SHA384Managed::.ctor()
extern "C"  void SHA384Managed__ctor_m_322179319_0 (SHA384Managed_t352992365_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SHA384Managed::Initialize(System.Boolean)
extern "C"  void SHA384Managed_Initialize_m2139501410_0 (SHA384Managed_t352992365_0 * __this, bool ___reuse, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SHA384Managed::Initialize()
extern "C"  void SHA384Managed_Initialize_m1947821355_0 (SHA384Managed_t352992365_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SHA384Managed::HashCore(System.Byte[],System.Int32,System.Int32)
extern "C"  void SHA384Managed_HashCore_m467338305_0 (SHA384Managed_t352992365_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgb, int32_t ___ibStart, int32_t ___cbSize, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Security.Cryptography.SHA384Managed::HashFinal()
extern "C"  ByteU5BU5D_t_1238178395_0* SHA384Managed_HashFinal_m_551099323_0 (SHA384Managed_t352992365_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SHA384Managed::update(System.Byte)
extern "C"  void SHA384Managed_update_m_1526727705_0 (SHA384Managed_t352992365_0 * __this, uint8_t ___input, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SHA384Managed::processWord(System.Byte[],System.Int32)
extern "C"  void SHA384Managed_processWord_m_1719821490_0 (SHA384Managed_t352992365_0 * __this, ByteU5BU5D_t_1238178395_0* ___input, int32_t ___inOff, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SHA384Managed::unpackWord(System.UInt64,System.Byte[],System.Int32)
extern "C"  void SHA384Managed_unpackWord_m_1238414032_0 (SHA384Managed_t352992365_0 * __this, uint64_t ___word, ByteU5BU5D_t_1238178395_0* ___output, int32_t ___outOff, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SHA384Managed::adjustByteCounts()
extern "C"  void SHA384Managed_adjustByteCounts_m_1991401322_0 (SHA384Managed_t352992365_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SHA384Managed::processLength(System.UInt64,System.UInt64)
extern "C"  void SHA384Managed_processLength_m_1186425292_0 (SHA384Managed_t352992365_0 * __this, uint64_t ___lowW, uint64_t ___hiW, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SHA384Managed::processBlock()
extern "C"  void SHA384Managed_processBlock_m_1918322983_0 (SHA384Managed_t352992365_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
