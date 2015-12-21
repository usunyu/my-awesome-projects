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

// System.Security.Cryptography.RSACryptoServiceProvider
struct RSACryptoServiceProvider_t_1692593868_0;
// System.Security.Cryptography.CspParameters
struct CspParameters_t_1753320293_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Object
struct Object_t;
// System.EventArgs
struct EventArgs_t693055868_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Security_Cryptography_RSAParameter1157257435.h"

// System.Void System.Security.Cryptography.RSACryptoServiceProvider::.ctor()
extern "C"  void RSACryptoServiceProvider__ctor_m8796060_0 (RSACryptoServiceProvider_t_1692593868_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RSACryptoServiceProvider::.ctor(System.Security.Cryptography.CspParameters)
extern "C"  void RSACryptoServiceProvider__ctor_m32080133_0 (RSACryptoServiceProvider_t_1692593868_0 * __this, CspParameters_t_1753320293_0 * ___parameters, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RSACryptoServiceProvider::.ctor(System.Int32)
extern "C"  void RSACryptoServiceProvider__ctor_m_61775123_0 (RSACryptoServiceProvider_t_1692593868_0 * __this, int32_t ___dwKeySize, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RSACryptoServiceProvider::.cctor()
extern "C"  void RSACryptoServiceProvider__cctor_m_209418351_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RSACryptoServiceProvider::Common(System.Int32,System.Security.Cryptography.CspParameters)
extern "C"  void RSACryptoServiceProvider_Common_m_485884277_0 (RSACryptoServiceProvider_t_1692593868_0 * __this, int32_t ___dwKeySize, CspParameters_t_1753320293_0 * ___p, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RSACryptoServiceProvider::Finalize()
extern "C"  void RSACryptoServiceProvider_Finalize_m152924998_0 (RSACryptoServiceProvider_t_1692593868_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Security.Cryptography.RSACryptoServiceProvider::get_KeySize()
extern "C"  int32_t RSACryptoServiceProvider_get_KeySize_m1022373229_0 (RSACryptoServiceProvider_t_1692593868_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Security.Cryptography.RSACryptoServiceProvider::get_PublicOnly()
extern "C"  bool RSACryptoServiceProvider_get_PublicOnly_m_1539797276_0 (RSACryptoServiceProvider_t_1692593868_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Security.Cryptography.RSACryptoServiceProvider::DecryptValue(System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* RSACryptoServiceProvider_DecryptValue_m_729292953_0 (RSACryptoServiceProvider_t_1692593868_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgb, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Security.Cryptography.RSACryptoServiceProvider::EncryptValue(System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* RSACryptoServiceProvider_EncryptValue_m511499327_0 (RSACryptoServiceProvider_t_1692593868_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgb, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.RSAParameters System.Security.Cryptography.RSACryptoServiceProvider::ExportParameters(System.Boolean)
extern "C"  RSAParameters_t1157257435_0  RSACryptoServiceProvider_ExportParameters_m71989545_0 (RSACryptoServiceProvider_t_1692593868_0 * __this, bool ___includePrivateParameters, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RSACryptoServiceProvider::ImportParameters(System.Security.Cryptography.RSAParameters)
extern "C"  void RSACryptoServiceProvider_ImportParameters_m_1271002432_0 (RSACryptoServiceProvider_t_1692593868_0 * __this, RSAParameters_t1157257435_0  ___parameters, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RSACryptoServiceProvider::Dispose(System.Boolean)
extern "C"  void RSACryptoServiceProvider_Dispose_m_133336432_0 (RSACryptoServiceProvider_t_1692593868_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RSACryptoServiceProvider::OnKeyGenerated(System.Object,System.EventArgs)
extern "C"  void RSACryptoServiceProvider_OnKeyGenerated_m_128538191_0 (RSACryptoServiceProvider_t_1692593868_0 * __this, Object_t * ___sender, EventArgs_t693055868_0 * ___e, const MethodInfo* method) IL2CPP_METHOD_ATTR;
