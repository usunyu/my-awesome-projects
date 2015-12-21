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

// Mono.Security.X509.SafeBag
struct SafeBag_t_1736577900_0;
// System.String
struct String_t;
// Mono.Security.ASN1
struct ASN1_t311288114_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.X509.SafeBag::.ctor(System.String,Mono.Security.ASN1)
extern "C"  void SafeBag__ctor_m_1583165362_0 (SafeBag_t_1736577900_0 * __this, String_t* ___bagOID, ASN1_t311288114_0 * ___asn1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.X509.SafeBag::get_BagOID()
extern "C"  String_t* SafeBag_get_BagOID_m_2038509104_0 (SafeBag_t_1736577900_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.ASN1 Mono.Security.X509.SafeBag::get_ASN1()
extern "C"  ASN1_t311288114_0 * SafeBag_get_ASN1_m_929013345_0 (SafeBag_t_1736577900_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
