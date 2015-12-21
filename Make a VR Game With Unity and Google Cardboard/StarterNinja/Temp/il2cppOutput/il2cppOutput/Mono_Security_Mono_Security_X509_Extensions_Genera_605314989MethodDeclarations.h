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

// Mono.Security.X509.Extensions.GeneralNames
struct GeneralNames_t_605314989_0;
// Mono.Security.ASN1
struct ASN1_t311288114_0;
// System.String[]
struct StringU5BU5D_t_816028754_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.X509.Extensions.GeneralNames::.ctor(Mono.Security.ASN1)
extern "C"  void GeneralNames__ctor_m_1299498517_0 (GeneralNames_t_605314989_0 * __this, ASN1_t311288114_0 * ___sequence, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String[] Mono.Security.X509.Extensions.GeneralNames::get_DNSNames()
extern "C"  StringU5BU5D_t_816028754_0* GeneralNames_get_DNSNames_m_1651232790_0 (GeneralNames_t_605314989_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String[] Mono.Security.X509.Extensions.GeneralNames::get_IPAddresses()
extern "C"  StringU5BU5D_t_816028754_0* GeneralNames_get_IPAddresses_m_1504547502_0 (GeneralNames_t_605314989_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.X509.Extensions.GeneralNames::ToString()
extern "C"  String_t* GeneralNames_ToString_m1119274128_0 (GeneralNames_t_605314989_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
