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

// System.Security.Cryptography.DSACryptoServiceProvider
struct DSACryptoServiceProvider_t_754499326_0;
// System.Security.Cryptography.CspParameters
struct CspParameters_t_1753320293_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Object
struct Object_t;
// System.EventArgs
struct EventArgs_t693055868_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Security_Cryptography_DSAParameters969932237.h"

// System.Void System.Security.Cryptography.DSACryptoServiceProvider::.ctor()
extern "C"  void DSACryptoServiceProvider__ctor_m515501966_0 (DSACryptoServiceProvider_t_754499326_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.DSACryptoServiceProvider::.ctor(System.Int32)
extern "C"  void DSACryptoServiceProvider__ctor_m_2021212193_0 (DSACryptoServiceProvider_t_754499326_0 * __this, int32_t ___dwKeySize, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.DSACryptoServiceProvider::.ctor(System.Int32,System.Security.Cryptography.CspParameters)
extern "C"  void DSACryptoServiceProvider__ctor_m_1245695952_0 (DSACryptoServiceProvider_t_754499326_0 * __this, int32_t ___dwKeySize, CspParameters_t_1753320293_0 * ___parameters, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.DSACryptoServiceProvider::.cctor()
extern "C"  void DSACryptoServiceProvider__cctor_m_1681404449_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.DSACryptoServiceProvider::Finalize()
extern "C"  void DSACryptoServiceProvider_Finalize_m_1381474796_0 (DSACryptoServiceProvider_t_754499326_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Security.Cryptography.DSACryptoServiceProvider::get_KeySize()
extern "C"  int32_t DSACryptoServiceProvider_get_KeySize_m1055041503_0 (DSACryptoServiceProvider_t_754499326_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Security.Cryptography.DSACryptoServiceProvider::get_PublicOnly()
extern "C"  bool DSACryptoServiceProvider_get_PublicOnly_m1018144562_0 (DSACryptoServiceProvider_t_754499326_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.DSAParameters System.Security.Cryptography.DSACryptoServiceProvider::ExportParameters(System.Boolean)
extern "C"  DSAParameters_t969932237_0  DSACryptoServiceProvider_ExportParameters_m1890915433_0 (DSACryptoServiceProvider_t_754499326_0 * __this, bool ___includePrivateParameters, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.DSACryptoServiceProvider::ImportParameters(System.Security.Cryptography.DSAParameters)
extern "C"  void DSACryptoServiceProvider_ImportParameters_m_1957994660_0 (DSACryptoServiceProvider_t_754499326_0 * __this, DSAParameters_t969932237_0  ___parameters, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Security.Cryptography.DSACryptoServiceProvider::CreateSignature(System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* DSACryptoServiceProvider_CreateSignature_m1822226263_0 (DSACryptoServiceProvider_t_754499326_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgbHash, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Security.Cryptography.DSACryptoServiceProvider::VerifySignature(System.Byte[],System.Byte[])
extern "C"  bool DSACryptoServiceProvider_VerifySignature_m_267543425_0 (DSACryptoServiceProvider_t_754499326_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgbHash, ByteU5BU5D_t_1238178395_0* ___rgbSignature, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.DSACryptoServiceProvider::Dispose(System.Boolean)
extern "C"  void DSACryptoServiceProvider_Dispose_m_24705406_0 (DSACryptoServiceProvider_t_754499326_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.DSACryptoServiceProvider::OnKeyGenerated(System.Object,System.EventArgs)
extern "C"  void DSACryptoServiceProvider_OnKeyGenerated_m_666843777_0 (DSACryptoServiceProvider_t_754499326_0 * __this, Object_t * ___sender, EventArgs_t693055868_0 * ___e, const MethodInfo* method) IL2CPP_METHOD_ATTR;
