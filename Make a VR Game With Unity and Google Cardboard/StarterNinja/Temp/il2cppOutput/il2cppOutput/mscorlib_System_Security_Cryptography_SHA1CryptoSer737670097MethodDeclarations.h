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

// System.Security.Cryptography.SHA1CryptoServiceProvider
struct SHA1CryptoServiceProvider_t737670097_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Security.Cryptography.SHA1CryptoServiceProvider::.ctor()
extern "C"  void SHA1CryptoServiceProvider__ctor_m2094228389_0 (SHA1CryptoServiceProvider_t737670097_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SHA1CryptoServiceProvider::Finalize()
extern "C"  void SHA1CryptoServiceProvider_Finalize_m565501597_0 (SHA1CryptoServiceProvider_t737670097_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SHA1CryptoServiceProvider::Dispose(System.Boolean)
extern "C"  void SHA1CryptoServiceProvider_Dispose_m1115384985_0 (SHA1CryptoServiceProvider_t737670097_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SHA1CryptoServiceProvider::HashCore(System.Byte[],System.Int32,System.Int32)
extern "C"  void SHA1CryptoServiceProvider_HashCore_m221312477_0 (SHA1CryptoServiceProvider_t737670097_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgb, int32_t ___ibStart, int32_t ___cbSize, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Security.Cryptography.SHA1CryptoServiceProvider::HashFinal()
extern "C"  ByteU5BU5D_t_1238178395_0* SHA1CryptoServiceProvider_HashFinal_m642464225_0 (SHA1CryptoServiceProvider_t737670097_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SHA1CryptoServiceProvider::Initialize()
extern "C"  void SHA1CryptoServiceProvider_Initialize_m_858885617_0 (SHA1CryptoServiceProvider_t737670097_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
