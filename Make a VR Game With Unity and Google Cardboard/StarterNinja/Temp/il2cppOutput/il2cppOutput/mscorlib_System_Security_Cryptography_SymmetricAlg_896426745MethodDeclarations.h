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

// System.Security.Cryptography.SymmetricAlgorithm
struct SymmetricAlgorithm_t_896426745_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Security.Cryptography.KeySizes[]
struct KeySizesU5BU5D_t_232190684_0;
// System.Security.Cryptography.ICryptoTransform
struct ICryptoTransform_t_754437679_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Security_Cryptography_CipherMode1234727773.h"
#include "mscorlib_System_Security_Cryptography_PaddingMode305282597.h"

// System.Void System.Security.Cryptography.SymmetricAlgorithm::.ctor()
extern "C"  void SymmetricAlgorithm__ctor_m_1279924503_0 (SymmetricAlgorithm_t_896426745_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SymmetricAlgorithm::System.IDisposable.Dispose()
extern "C"  void SymmetricAlgorithm_System_IDisposable_Dispose_m1612088406_0 (SymmetricAlgorithm_t_896426745_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SymmetricAlgorithm::Finalize()
extern "C"  void SymmetricAlgorithm_Finalize_m591291609_0 (SymmetricAlgorithm_t_896426745_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SymmetricAlgorithm::Clear()
extern "C"  void SymmetricAlgorithm_Clear_m421176084_0 (SymmetricAlgorithm_t_896426745_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SymmetricAlgorithm::Dispose(System.Boolean)
extern "C"  void SymmetricAlgorithm_Dispose_m_820582435_0 (SymmetricAlgorithm_t_896426745_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Security.Cryptography.SymmetricAlgorithm::get_BlockSize()
extern "C"  int32_t SymmetricAlgorithm_get_BlockSize_m_196385432_0 (SymmetricAlgorithm_t_896426745_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SymmetricAlgorithm::set_BlockSize(System.Int32)
extern "C"  void SymmetricAlgorithm_set_BlockSize_m_2021091927_0 (SymmetricAlgorithm_t_896426745_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Security.Cryptography.SymmetricAlgorithm::get_FeedbackSize()
extern "C"  int32_t SymmetricAlgorithm_get_FeedbackSize_m_47474610_0 (SymmetricAlgorithm_t_896426745_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Security.Cryptography.SymmetricAlgorithm::get_IV()
extern "C"  ByteU5BU5D_t_1238178395_0* SymmetricAlgorithm_get_IV_m_1895400857_0 (SymmetricAlgorithm_t_896426745_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SymmetricAlgorithm::set_IV(System.Byte[])
extern "C"  void SymmetricAlgorithm_set_IV_m870580644_0 (SymmetricAlgorithm_t_896426745_0 * __this, ByteU5BU5D_t_1238178395_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Security.Cryptography.SymmetricAlgorithm::get_Key()
extern "C"  ByteU5BU5D_t_1238178395_0* SymmetricAlgorithm_get_Key_m1374487335_0 (SymmetricAlgorithm_t_896426745_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SymmetricAlgorithm::set_Key(System.Byte[])
extern "C"  void SymmetricAlgorithm_set_Key_m_38202528_0 (SymmetricAlgorithm_t_896426745_0 * __this, ByteU5BU5D_t_1238178395_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Security.Cryptography.SymmetricAlgorithm::get_KeySize()
extern "C"  int32_t SymmetricAlgorithm_get_KeySize_m_645123078_0 (SymmetricAlgorithm_t_896426745_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SymmetricAlgorithm::set_KeySize(System.Int32)
extern "C"  void SymmetricAlgorithm_set_KeySize_m1757877563_0 (SymmetricAlgorithm_t_896426745_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.KeySizes[] System.Security.Cryptography.SymmetricAlgorithm::get_LegalKeySizes()
extern "C"  KeySizesU5BU5D_t_232190684_0* SymmetricAlgorithm_get_LegalKeySizes_m472333301_0 (SymmetricAlgorithm_t_896426745_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.CipherMode System.Security.Cryptography.SymmetricAlgorithm::get_Mode()
extern "C"  int32_t SymmetricAlgorithm_get_Mode_m595116277_0 (SymmetricAlgorithm_t_896426745_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SymmetricAlgorithm::set_Mode(System.Security.Cryptography.CipherMode)
extern "C"  void SymmetricAlgorithm_set_Mode_m_649398058_0 (SymmetricAlgorithm_t_896426745_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.PaddingMode System.Security.Cryptography.SymmetricAlgorithm::get_Padding()
extern "C"  int32_t SymmetricAlgorithm_get_Padding_m_1025804199_0 (SymmetricAlgorithm_t_896426745_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.SymmetricAlgorithm::set_Padding(System.Security.Cryptography.PaddingMode)
extern "C"  void SymmetricAlgorithm_set_Padding_m_1643413606_0 (SymmetricAlgorithm_t_896426745_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.ICryptoTransform System.Security.Cryptography.SymmetricAlgorithm::CreateDecryptor()
extern "C"  Object_t * SymmetricAlgorithm_CreateDecryptor_m861706393_0 (SymmetricAlgorithm_t_896426745_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.ICryptoTransform System.Security.Cryptography.SymmetricAlgorithm::CreateEncryptor()
extern "C"  Object_t * SymmetricAlgorithm_CreateEncryptor_m1591100785_0 (SymmetricAlgorithm_t_896426745_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.SymmetricAlgorithm System.Security.Cryptography.SymmetricAlgorithm::Create(System.String)
extern "C"  SymmetricAlgorithm_t_896426745_0 * SymmetricAlgorithm_Create_m1327881011_0 (Object_t * __this /* static, unused */, String_t* ___algName, const MethodInfo* method) IL2CPP_METHOD_ATTR;
