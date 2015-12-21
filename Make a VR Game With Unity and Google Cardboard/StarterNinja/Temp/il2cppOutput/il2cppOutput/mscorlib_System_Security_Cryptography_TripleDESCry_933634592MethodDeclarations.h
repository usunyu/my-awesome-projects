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

// System.Security.Cryptography.TripleDESCryptoServiceProvider
struct TripleDESCryptoServiceProvider_t_933634592_0;
// System.Security.Cryptography.ICryptoTransform
struct ICryptoTransform_t_754437679_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Security.Cryptography.TripleDESCryptoServiceProvider::.ctor()
extern "C"  void TripleDESCryptoServiceProvider__ctor_m_1756062032_0 (TripleDESCryptoServiceProvider_t_933634592_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.TripleDESCryptoServiceProvider::GenerateIV()
extern "C"  void TripleDESCryptoServiceProvider_GenerateIV_m1507918646_0 (TripleDESCryptoServiceProvider_t_933634592_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.TripleDESCryptoServiceProvider::GenerateKey()
extern "C"  void TripleDESCryptoServiceProvider_GenerateKey_m_496790472_0 (TripleDESCryptoServiceProvider_t_933634592_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.ICryptoTransform System.Security.Cryptography.TripleDESCryptoServiceProvider::CreateDecryptor(System.Byte[],System.Byte[])
extern "C"  Object_t * TripleDESCryptoServiceProvider_CreateDecryptor_m_1117726100_0 (TripleDESCryptoServiceProvider_t_933634592_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgbKey, ByteU5BU5D_t_1238178395_0* ___rgbIV, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.ICryptoTransform System.Security.Cryptography.TripleDESCryptoServiceProvider::CreateEncryptor(System.Byte[],System.Byte[])
extern "C"  Object_t * TripleDESCryptoServiceProvider_CreateEncryptor_m_811997548_0 (TripleDESCryptoServiceProvider_t_933634592_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgbKey, ByteU5BU5D_t_1238178395_0* ___rgbIV, const MethodInfo* method) IL2CPP_METHOD_ATTR;
