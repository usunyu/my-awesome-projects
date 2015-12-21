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

// Mono.Security.Cryptography.ARC4Managed
struct ARC4Managed_t994587996_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Security.Cryptography.ICryptoTransform
struct ICryptoTransform_t_754437679_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.Cryptography.ARC4Managed::.ctor()
extern "C"  void ARC4Managed__ctor_m340859770_0 (ARC4Managed_t994587996_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.ARC4Managed::Finalize()
extern "C"  void ARC4Managed_Finalize_m1353226920_0 (ARC4Managed_t994587996_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.ARC4Managed::Dispose(System.Boolean)
extern "C"  void ARC4Managed_Dispose_m_889136530_0 (ARC4Managed_t994587996_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Cryptography.ARC4Managed::get_Key()
extern "C"  ByteU5BU5D_t_1238178395_0* ARC4Managed_get_Key_m_1830646172_0 (ARC4Managed_t994587996_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.ARC4Managed::set_Key(System.Byte[])
extern "C"  void ARC4Managed_set_Key_m1483606703_0 (ARC4Managed_t994587996_0 * __this, ByteU5BU5D_t_1238178395_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Cryptography.ARC4Managed::get_CanReuseTransform()
extern "C"  bool ARC4Managed_get_CanReuseTransform_m1071201641_0 (ARC4Managed_t994587996_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.ICryptoTransform Mono.Security.Cryptography.ARC4Managed::CreateEncryptor(System.Byte[],System.Byte[])
extern "C"  Object_t * ARC4Managed_CreateEncryptor_m_2116387642_0 (ARC4Managed_t994587996_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgbKey, ByteU5BU5D_t_1238178395_0* ___rgvIV, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.ICryptoTransform Mono.Security.Cryptography.ARC4Managed::CreateDecryptor(System.Byte[],System.Byte[])
extern "C"  Object_t * ARC4Managed_CreateDecryptor_m1872851102_0 (ARC4Managed_t994587996_0 * __this, ByteU5BU5D_t_1238178395_0* ___rgbKey, ByteU5BU5D_t_1238178395_0* ___rgvIV, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.ARC4Managed::GenerateIV()
extern "C"  void ARC4Managed_GenerateIV_m_1945832276_0 (ARC4Managed_t994587996_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.ARC4Managed::GenerateKey()
extern "C"  void ARC4Managed_GenerateKey_m_188886654_0 (ARC4Managed_t994587996_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.ARC4Managed::KeySetup(System.Byte[])
extern "C"  void ARC4Managed_KeySetup_m705764065_0 (ARC4Managed_t994587996_0 * __this, ByteU5BU5D_t_1238178395_0* ___key, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.ARC4Managed::CheckInput(System.Byte[],System.Int32,System.Int32)
extern "C"  void ARC4Managed_CheckInput_m_410561667_0 (ARC4Managed_t994587996_0 * __this, ByteU5BU5D_t_1238178395_0* ___inputBuffer, int32_t ___inputOffset, int32_t ___inputCount, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Cryptography.ARC4Managed::TransformBlock(System.Byte[],System.Int32,System.Int32,System.Byte[],System.Int32)
extern "C"  int32_t ARC4Managed_TransformBlock_m961675998_0 (ARC4Managed_t994587996_0 * __this, ByteU5BU5D_t_1238178395_0* ___inputBuffer, int32_t ___inputOffset, int32_t ___inputCount, ByteU5BU5D_t_1238178395_0* ___outputBuffer, int32_t ___outputOffset, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Cryptography.ARC4Managed::InternalTransformBlock(System.Byte[],System.Int32,System.Int32,System.Byte[],System.Int32)
extern "C"  int32_t ARC4Managed_InternalTransformBlock_m158418811_0 (ARC4Managed_t994587996_0 * __this, ByteU5BU5D_t_1238178395_0* ___inputBuffer, int32_t ___inputOffset, int32_t ___inputCount, ByteU5BU5D_t_1238178395_0* ___outputBuffer, int32_t ___outputOffset, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Cryptography.ARC4Managed::TransformFinalBlock(System.Byte[],System.Int32,System.Int32)
extern "C"  ByteU5BU5D_t_1238178395_0* ARC4Managed_TransformFinalBlock_m1879343064_0 (ARC4Managed_t994587996_0 * __this, ByteU5BU5D_t_1238178395_0* ___inputBuffer, int32_t ___inputOffset, int32_t ___inputCount, const MethodInfo* method) IL2CPP_METHOD_ATTR;
