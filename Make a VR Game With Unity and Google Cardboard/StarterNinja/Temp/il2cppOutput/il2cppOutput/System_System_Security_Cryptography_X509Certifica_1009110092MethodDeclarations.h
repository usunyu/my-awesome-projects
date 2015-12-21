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

// System.Security.Cryptography.X509Certificates.X509ChainElement
struct X509ChainElement_t_1009110092_0;
// System.Security.Cryptography.X509Certificates.X509Certificate2
struct X509Certificate2_t1644507188_0;
// System.Security.Cryptography.X509Certificates.X509ChainStatus[]
struct X509ChainStatusU5BU5D_t109390108_0;

#include "codegen/il2cpp-codegen.h"
#include "System_System_Security_Cryptography_X509Certifica_1058320787.h"

// System.Void System.Security.Cryptography.X509Certificates.X509ChainElement::.ctor(System.Security.Cryptography.X509Certificates.X509Certificate2)
extern "C"  void X509ChainElement__ctor_m1605854504_0 (X509ChainElement_t_1009110092_0 * __this, X509Certificate2_t1644507188_0 * ___certificate, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509Certificate2 System.Security.Cryptography.X509Certificates.X509ChainElement::get_Certificate()
extern "C"  X509Certificate2_t1644507188_0 * X509ChainElement_get_Certificate_m_1310525399_0 (X509ChainElement_t_1009110092_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509ChainStatus[] System.Security.Cryptography.X509Certificates.X509ChainElement::get_ChainElementStatus()
extern "C"  X509ChainStatusU5BU5D_t109390108_0* X509ChainElement_get_ChainElementStatus_m1337819701_0 (X509ChainElement_t_1009110092_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509ChainStatusFlags System.Security.Cryptography.X509Certificates.X509ChainElement::get_StatusFlags()
extern "C"  int32_t X509ChainElement_get_StatusFlags_m_2025154880_0 (X509ChainElement_t_1009110092_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509ChainElement::set_StatusFlags(System.Security.Cryptography.X509Certificates.X509ChainStatusFlags)
extern "C"  void X509ChainElement_set_StatusFlags_m_1615511355_0 (X509ChainElement_t_1009110092_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Security.Cryptography.X509Certificates.X509ChainElement::Count(System.Security.Cryptography.X509Certificates.X509ChainStatusFlags)
extern "C"  int32_t X509ChainElement_Count_m466237836_0 (X509ChainElement_t_1009110092_0 * __this, int32_t ___flags, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509ChainElement::Set(System.Security.Cryptography.X509Certificates.X509ChainStatus[],System.Int32&,System.Security.Cryptography.X509Certificates.X509ChainStatusFlags,System.Security.Cryptography.X509Certificates.X509ChainStatusFlags)
extern "C"  void X509ChainElement_Set_m2091040175_0 (X509ChainElement_t_1009110092_0 * __this, X509ChainStatusU5BU5D_t109390108_0* ___status, int32_t* ___position, int32_t ___flags, int32_t ___mask, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509ChainElement::UncompressFlags()
extern "C"  void X509ChainElement_UncompressFlags_m_1168993588_0 (X509ChainElement_t_1009110092_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
