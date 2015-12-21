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

// System.Security.Cryptography.RijndaelManaged
struct RijndaelManaged_t_870856495_0;
// System.Security.Cryptography.ICryptoTransform
struct ICryptoTransform_t_754437679_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Security.Cryptography.RijndaelManaged::.ctor()
extern "C"  void RijndaelManaged__ctor_m504318565_0 (RijndaelManaged_t_870856495_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RijndaelManaged::GenerateIV()
extern "C"  void RijndaelManaged_GenerateIV_m_118071135_0 (RijndaelManaged_t_870856495_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.RijndaelManaged::GenerateKey()
extern "C"  void RijndaelManaged_GenerateKey_m637133869_0 (RijndaelManaged_t_870856495_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.ICryptoTransform System.Security.Cryptography.RijndaelManaged::CreateDecryptor(System.Byte[],System.Byte[])
extern "C"  Object_t * RijndaelManaged_CreateDecryptor_m382017683_0 (RijndaelManaged_t_870856495_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgbKey, ByteU5BU5D_t_1238178395_0* ___rgbIV, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.ICryptoTransform System.Security.Cryptography.RijndaelManaged::CreateEncryptor(System.Byte[],System.Byte[])
extern "C"  Object_t * RijndaelManaged_CreateEncryptor_m687746235_0 (RijndaelManaged_t_870856495_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgbKey, ByteU5BU5D_t_1238178395_0* ___rgbIV, const MethodInfo* method) IL2CPP_METHOD_ATTR;
