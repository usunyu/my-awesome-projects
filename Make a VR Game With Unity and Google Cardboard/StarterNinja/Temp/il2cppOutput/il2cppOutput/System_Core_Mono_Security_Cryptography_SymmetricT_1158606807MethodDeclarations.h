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

// Mono.Security.Cryptography.SymmetricTransform
struct SymmetricTransform_t_1158606807_0;
// System.Security.Cryptography.SymmetricAlgorithm
struct SymmetricAlgorithm_t_896426745_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Security_Cryptography_PaddingMode305282597.h"

// System.Void Mono.Security.Cryptography.SymmetricTransform::.ctor(System.Security.Cryptography.SymmetricAlgorithm,System.Boolean,System.Byte[])
extern "C"  void SymmetricTransform__ctor_m1205754880_0 (SymmetricTransform_t_1158606807_0 * __this, SymmetricAlgorithm_t_896426745_0 * ___symmAlgo, bool ___encryption, ByteU5BU5D_t_1238178395_0* ___rgbIV, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.SymmetricTransform::System.IDisposable.Dispose()
extern "C"  void SymmetricTransform_System_IDisposable_Dispose_m455424824_0 (SymmetricTransform_t_1158606807_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.SymmetricTransform::Finalize()
extern "C"  void SymmetricTransform_Finalize_m1432383547_0 (SymmetricTransform_t_1158606807_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.SymmetricTransform::Dispose(System.Boolean)
extern "C"  void SymmetricTransform_Dispose_m_1564087365_0 (SymmetricTransform_t_1158606807_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Cryptography.SymmetricTransform::get_CanReuseTransform()
extern "C"  bool SymmetricTransform_get_CanReuseTransform_m725989976_0 (SymmetricTransform_t_1158606807_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.SymmetricTransform::Transform(System.Byte[],System.Byte[])
extern "C"  void SymmetricTransform_Transform_m_391393253_0 (SymmetricTransform_t_1158606807_0 * __this, ByteU5BU5D_t_1238178395_0* ___input, ByteU5BU5D_t_1238178395_0* ___output, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.SymmetricTransform::CBC(System.Byte[],System.Byte[])
extern "C"  void SymmetricTransform_CBC_m_2077501533_0 (SymmetricTransform_t_1158606807_0 * __this, ByteU5BU5D_t_1238178395_0* ___input, ByteU5BU5D_t_1238178395_0* ___output, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.SymmetricTransform::CFB(System.Byte[],System.Byte[])
extern "C"  void SymmetricTransform_CFB_m_685617912_0 (SymmetricTransform_t_1158606807_0 * __this, ByteU5BU5D_t_1238178395_0* ___input, ByteU5BU5D_t_1238178395_0* ___output, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.SymmetricTransform::OFB(System.Byte[],System.Byte[])
extern "C"  void SymmetricTransform_OFB_m962939772_0 (SymmetricTransform_t_1158606807_0 * __this, ByteU5BU5D_t_1238178395_0* ___input, ByteU5BU5D_t_1238178395_0* ___output, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.SymmetricTransform::CTS(System.Byte[],System.Byte[])
extern "C"  void SymmetricTransform_CTS_m122988069_0 (SymmetricTransform_t_1158606807_0 * __this, ByteU5BU5D_t_1238178395_0* ___input, ByteU5BU5D_t_1238178395_0* ___output, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.SymmetricTransform::CheckInput(System.Byte[],System.Int32,System.Int32)
extern "C"  void SymmetricTransform_CheckInput_m_788488374_0 (SymmetricTransform_t_1158606807_0 * __this, ByteU5BU5D_t_1238178395_0* ___inputBuffer, int32_t ___inputOffset, int32_t ___inputCount, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Cryptography.SymmetricTransform::TransformBlock(System.Byte[],System.Int32,System.Int32,System.Byte[],System.Int32)
extern "C"  int32_t SymmetricTransform_TransformBlock_m1944043099_0 (SymmetricTransform_t_1158606807_0 * __this, ByteU5BU5D_t_1238178395_0* ___inputBuffer, int32_t ___inputOffset, int32_t ___inputCount, ByteU5BU5D_t_1238178395_0* ___outputBuffer, int32_t ___outputOffset, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Cryptography.SymmetricTransform::get_KeepLastBlock()
extern "C"  bool SymmetricTransform_get_KeepLastBlock_m_2121109086_0 (SymmetricTransform_t_1158606807_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Cryptography.SymmetricTransform::InternalTransformBlock(System.Byte[],System.Int32,System.Int32,System.Byte[],System.Int32)
extern "C"  int32_t SymmetricTransform_InternalTransformBlock_m_914475528_0 (SymmetricTransform_t_1158606807_0 * __this, ByteU5BU5D_t_1238178395_0* ___inputBuffer, int32_t ___inputOffset, int32_t ___inputCount, ByteU5BU5D_t_1238178395_0* ___outputBuffer, int32_t ___outputOffset, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.SymmetricTransform::Random(System.Byte[],System.Int32,System.Int32)
extern "C"  void SymmetricTransform_Random_m_879186615_0 (SymmetricTransform_t_1158606807_0 * __this, ByteU5BU5D_t_1238178395_0* ___buffer, int32_t ___start, int32_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.SymmetricTransform::ThrowBadPaddingException(System.Security.Cryptography.PaddingMode,System.Int32,System.Int32)
extern "C"  void SymmetricTransform_ThrowBadPaddingException_m2083216889_0 (SymmetricTransform_t_1158606807_0 * __this, int32_t ___padding, int32_t ___length, int32_t ___position, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Cryptography.SymmetricTransform::FinalEncrypt(System.Byte[],System.Int32,System.Int32)
extern "C"  ByteU5BU5D_t_1238178395_0* SymmetricTransform_FinalEncrypt_m975601255_0 (SymmetricTransform_t_1158606807_0 * __this, ByteU5BU5D_t_1238178395_0* ___inputBuffer, int32_t ___inputOffset, int32_t ___inputCount, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Cryptography.SymmetricTransform::FinalDecrypt(System.Byte[],System.Int32,System.Int32)
extern "C"  ByteU5BU5D_t_1238178395_0* SymmetricTransform_FinalDecrypt_m_552565697_0 (SymmetricTransform_t_1158606807_0 * __this, ByteU5BU5D_t_1238178395_0* ___inputBuffer, int32_t ___inputOffset, int32_t ___inputCount, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Cryptography.SymmetricTransform::TransformFinalBlock(System.Byte[],System.Int32,System.Int32)
extern "C"  ByteU5BU5D_t_1238178395_0* SymmetricTransform_TransformFinalBlock_m_1770578857_0 (SymmetricTransform_t_1158606807_0 * __this, ByteU5BU5D_t_1238178395_0* ___inputBuffer, int32_t ___inputOffset, int32_t ___inputCount, const MethodInfo* method) IL2CPP_METHOD_ATTR;
