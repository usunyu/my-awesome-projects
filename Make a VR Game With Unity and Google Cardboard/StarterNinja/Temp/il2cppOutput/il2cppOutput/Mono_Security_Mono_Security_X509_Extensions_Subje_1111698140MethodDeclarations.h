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

// Mono.Security.X509.Extensions.SubjectAltNameExtension
struct SubjectAltNameExtension_t_1111698140_0;
// Mono.Security.X509.X509Extension
struct X509Extension_t_556260338_0;
// System.String[]
struct StringU5BU5D_t_816028754_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.X509.Extensions.SubjectAltNameExtension::.ctor(Mono.Security.X509.X509Extension)
extern "C"  void SubjectAltNameExtension__ctor_m607242584_0 (SubjectAltNameExtension_t_1111698140_0 * __this, X509Extension_t_556260338_0 * ___extension, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.X509.Extensions.SubjectAltNameExtension::Decode()
extern "C"  void SubjectAltNameExtension_Decode_m_821743162_0 (SubjectAltNameExtension_t_1111698140_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String[] Mono.Security.X509.Extensions.SubjectAltNameExtension::get_DNSNames()
extern "C"  StringU5BU5D_t_816028754_0* SubjectAltNameExtension_get_DNSNames_m_642319265_0 (SubjectAltNameExtension_t_1111698140_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String[] Mono.Security.X509.Extensions.SubjectAltNameExtension::get_IPAddresses()
extern "C"  StringU5BU5D_t_816028754_0* SubjectAltNameExtension_get_IPAddresses_m_1142861635_0 (SubjectAltNameExtension_t_1111698140_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.X509.Extensions.SubjectAltNameExtension::ToString()
extern "C"  String_t* SubjectAltNameExtension_ToString_m_1314209791_0 (SubjectAltNameExtension_t_1111698140_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
