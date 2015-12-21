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

// System.Security.Cryptography.MD5CryptoServiceProvider
struct MD5CryptoServiceProvider_t132680854_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Security.Cryptography.MD5CryptoServiceProvider::.ctor()
extern "C"  void MD5CryptoServiceProvider__ctor_m_1785566598_0 (MD5CryptoServiceProvider_t132680854_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.MD5CryptoServiceProvider::.cctor()
extern "C"  void MD5CryptoServiceProvider__cctor_m_85901_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.MD5CryptoServiceProvider::Finalize()
extern "C"  void MD5CryptoServiceProvider_Finalize_m_542053464_0 (MD5CryptoServiceProvider_t132680854_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.MD5CryptoServiceProvider::Dispose(System.Boolean)
extern "C"  void MD5CryptoServiceProvider_Dispose_m365177198_0 (MD5CryptoServiceProvider_t132680854_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.MD5CryptoServiceProvider::HashCore(System.Byte[],System.Int32,System.Int32)
extern "C"  void MD5CryptoServiceProvider_HashCore_m255435378_0 (MD5CryptoServiceProvider_t132680854_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgb, int32_t ___ibStart, int32_t ___cbSize, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Security.Cryptography.MD5CryptoServiceProvider::HashFinal()
extern "C"  ByteU5BU5D_t_1238178395_0* MD5CryptoServiceProvider_HashFinal_m430218570_0 (MD5CryptoServiceProvider_t132680854_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.MD5CryptoServiceProvider::Initialize()
extern "C"  void MD5CryptoServiceProvider_Initialize_m_67409830_0 (MD5CryptoServiceProvider_t132680854_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.MD5CryptoServiceProvider::ProcessBlock(System.Byte[],System.Int32)
extern "C"  void MD5CryptoServiceProvider_ProcessBlock_m1355255830_0 (MD5CryptoServiceProvider_t132680854_0 * __this, ByteU5BU5D_t_1238178395_0* ___inputBuffer, int32_t ___inputOffset, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.MD5CryptoServiceProvider::ProcessFinalBlock(System.Byte[],System.Int32,System.Int32)
extern "C"  void MD5CryptoServiceProvider_ProcessFinalBlock_m_1836723701_0 (MD5CryptoServiceProvider_t132680854_0 * __this, ByteU5BU5D_t_1238178395_0* ___inputBuffer, int32_t ___inputOffset, int32_t ___inputCount, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.MD5CryptoServiceProvider::AddLength(System.UInt64,System.Byte[],System.Int32)
extern "C"  void MD5CryptoServiceProvider_AddLength_m_1070062184_0 (MD5CryptoServiceProvider_t132680854_0 * __this, uint64_t ___length, ByteU5BU5D_t_1238178395_0* ___buffer, int32_t ___position, const MethodInfo* method) IL2CPP_METHOD_ATTR;
