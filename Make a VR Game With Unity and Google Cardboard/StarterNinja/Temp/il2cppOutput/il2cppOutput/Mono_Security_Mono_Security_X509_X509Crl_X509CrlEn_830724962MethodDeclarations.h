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

// Mono.Security.X509.X509Crl/X509CrlEntry
struct X509CrlEntry_t_830724962_0;
// Mono.Security.ASN1
struct ASN1_t311288114_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// Mono.Security.X509.X509ExtensionCollection
struct X509ExtensionCollection_t_1920699060_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_DateTime_818288618.h"

// System.Void Mono.Security.X509.X509Crl/X509CrlEntry::.ctor(Mono.Security.ASN1)
extern "C"  void X509CrlEntry__ctor_m_1574067362_0 (X509CrlEntry_t_830724962_0 * __this, ASN1_t311288114_0 * ___entry, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.X509.X509Crl/X509CrlEntry::get_SerialNumber()
extern "C"  ByteU5BU5D_t_1238178395_0* X509CrlEntry_get_SerialNumber_m2092313770_0 (X509CrlEntry_t_830724962_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime Mono.Security.X509.X509Crl/X509CrlEntry::get_RevocationDate()
extern "C"  DateTime_t_818288618_0  X509CrlEntry_get_RevocationDate_m1346115726_0 (X509CrlEntry_t_830724962_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.X509.X509ExtensionCollection Mono.Security.X509.X509Crl/X509CrlEntry::get_Extensions()
extern "C"  X509ExtensionCollection_t_1920699060_0 * X509CrlEntry_get_Extensions_m_1258637310_0 (X509CrlEntry_t_830724962_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
