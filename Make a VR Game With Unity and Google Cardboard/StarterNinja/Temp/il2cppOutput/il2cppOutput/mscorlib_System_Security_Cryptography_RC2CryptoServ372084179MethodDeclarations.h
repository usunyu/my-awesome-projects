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

// System.Security.Cryptography.RC2CryptoServiceProvider
struct RC2CryptoServiceProvider_t372084179_0;
// System.Security.Cryptography.ICryptoTransform
struct ICryptoTransform_t_754437679_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Security.Cryptography.RC2CryptoServiceProvider::.ctor()
extern "C"  void RC2CryptoServiceProvider__ctor_m1138654685_0 (RC2CryptoServiceProvider_t372084179_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Security.Cryptography.RC2CryptoServiceProvider::get_EffectiveKeySize()
extern "C"  int32_t RC2CryptoServiceProvider_get_EffectiveKeySize_m741031373_0 (RC2CryptoServiceProvider_t372084179_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.ICryptoTransform System.Security.Cryptography.RC2CryptoServiceProvider::CreateDecryptor(System.Byte[],System.Byte[])
extern "C"  Object_t * RC2CryptoServiceProvider_CreateDecryptor_m1062427871_0 (RC2CryptoServiceProvider_t372084179_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgbKey, ByteU5BU5D_t_1238178395_0* ___rgbIV, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.ICryptoTransform System.Security.Cryptography.RC2CryptoServiceProvider::CreateEncryptor(System.Byte[],System.Byte[])
extern "C"  Object_t * RC2CryptoServiceProvider_CreateEncryptor_m1368156423_0 (RC2CryptoServiceProvider_t372084179_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgbKey, ByteU5BU5D_t_1238178395_0* ___rgbIV, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RC2CryptoServiceProvider::GenerateIV()
extern "C"  void RC2CryptoServiceProvider_GenerateIV_m_260794327_0 (RC2CryptoServiceProvider_t372084179_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RC2CryptoServiceProvider::GenerateKey()
extern "C"  void RC2CryptoServiceProvider_GenerateKey_m507682213_0 (RC2CryptoServiceProvider_t372084179_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
