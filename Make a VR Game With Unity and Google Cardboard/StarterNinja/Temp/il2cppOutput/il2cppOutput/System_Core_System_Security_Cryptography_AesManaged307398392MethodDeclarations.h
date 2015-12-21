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

// System.Security.Cryptography.AesManaged
struct AesManaged_t307398392_0;
// System.Security.Cryptography.ICryptoTransform
struct ICryptoTransform_t_754437679_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Security.Cryptography.AesManaged::.ctor()
extern "C"  void AesManaged__ctor_m1572578968_0 (AesManaged_t307398392_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.AesManaged::GenerateIV()
extern "C"  void AesManaged_GenerateIV_m_106255282_0 (AesManaged_t307398392_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.AesManaged::GenerateKey()
extern "C"  void AesManaged_GenerateKey_m1003425312_0 (AesManaged_t307398392_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.ICryptoTransform System.Security.Cryptography.AesManaged::CreateDecryptor(System.Byte[],System.Byte[])
extern "C"  Object_t * AesManaged_CreateDecryptor_m1952358980_0 (AesManaged_t307398392_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgbKey, ByteU5BU5D_t_1238178395_0* ___rgbIV, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.ICryptoTransform System.Security.Cryptography.AesManaged::CreateEncryptor(System.Byte[],System.Byte[])
extern "C"  Object_t * AesManaged_CreateEncryptor_m_2036879764_0 (AesManaged_t307398392_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgbKey, ByteU5BU5D_t_1238178395_0* ___rgbIV, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Security.Cryptography.AesManaged::get_IV()
extern "C"  ByteU5BU5D_t_1238178395_0* AesManaged_get_IV_m_523324328_0 (AesManaged_t307398392_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.AesManaged::set_IV(System.Byte[])
extern "C"  void AesManaged_set_IV_m_1838341357_0 (AesManaged_t307398392_0 * __this, ByteU5BU5D_t_1238178395_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Security.Cryptography.AesManaged::get_Key()
extern "C"  ByteU5BU5D_t_1238178395_0* AesManaged_get_Key_m959186774_0 (AesManaged_t307398392_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.AesManaged::set_Key(System.Byte[])
extern "C"  void AesManaged_set_Key_m1884561361_0 (AesManaged_t307398392_0 * __this, ByteU5BU5D_t_1238178395_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Security.Cryptography.AesManaged::get_KeySize()
extern "C"  int32_t AesManaged_get_KeySize_m1856785595_0 (AesManaged_t307398392_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.AesManaged::set_KeySize(System.Int32)
extern "C"  void AesManaged_set_KeySize_m838068010_0 (AesManaged_t307398392_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.ICryptoTransform System.Security.Cryptography.AesManaged::CreateDecryptor()
extern "C"  Object_t * AesManaged_CreateDecryptor_m_1561479736_0 (AesManaged_t307398392_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.ICryptoTransform System.Security.Cryptography.AesManaged::CreateEncryptor()
extern "C"  Object_t * AesManaged_CreateEncryptor_m_832085344_0 (AesManaged_t307398392_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.AesManaged::Dispose(System.Boolean)
extern "C"  void AesManaged_Dispose_m_1344444020_0 (AesManaged_t307398392_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
