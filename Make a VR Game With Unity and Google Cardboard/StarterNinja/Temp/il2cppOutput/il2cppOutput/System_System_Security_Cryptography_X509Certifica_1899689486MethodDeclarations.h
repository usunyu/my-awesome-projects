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

// System.Security.Cryptography.X509Certificates.X509Certificate2Collection
struct X509Certificate2Collection_t_1899689486_0;
// System.Security.Cryptography.X509Certificates.X509Certificate2
struct X509Certificate2_t1644507188_0;
// System.Object
struct Object_t;
// System.Security.Cryptography.X509Certificates.X509Certificate2Enumerator
struct X509Certificate2Enumerator_t_1079037160_0;

#include "codegen/il2cpp-codegen.h"
#include "System_System_Security_Cryptography_X509Certificat1641478092.h"

// System.Void System.Security.Cryptography.X509Certificates.X509Certificate2Collection::.ctor()
extern "C"  void X509Certificate2Collection__ctor_m769271012_0 (X509Certificate2Collection_t_1899689486_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Certificate2Collection::.ctor(System.Security.Cryptography.X509Certificates.X509Certificate2Collection)
extern "C"  void X509Certificate2Collection__ctor_m576565548_0 (X509Certificate2Collection_t_1899689486_0 * __this, X509Certificate2Collection_t_1899689486_0 * ___certificates, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509Certificate2 System.Security.Cryptography.X509Certificates.X509Certificate2Collection::get_Item(System.Int32)
extern "C"  X509Certificate2_t1644507188_0 * X509Certificate2Collection_get_Item_m1131271090_0 (X509Certificate2Collection_t_1899689486_0 * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Security.Cryptography.X509Certificates.X509Certificate2Collection::Add(System.Security.Cryptography.X509Certificates.X509Certificate2)
extern "C"  int32_t X509Certificate2Collection_Add_m1268164793_0 (X509Certificate2Collection_t_1899689486_0 * __this, X509Certificate2_t1644507188_0 * ___certificate, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Certificate2Collection::AddRange(System.Security.Cryptography.X509Certificates.X509Certificate2Collection)
extern "C"  void X509Certificate2Collection_AddRange_m1617477316_0 (X509Certificate2Collection_t_1899689486_0 * __this, X509Certificate2Collection_t_1899689486_0 * ___certificates, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Security.Cryptography.X509Certificates.X509Certificate2Collection::Contains(System.Security.Cryptography.X509Certificates.X509Certificate2)
extern "C"  bool X509Certificate2Collection_Contains_m1344146715_0 (X509Certificate2Collection_t_1899689486_0 * __this, X509Certificate2_t1644507188_0 * ___certificate, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509Certificate2Collection System.Security.Cryptography.X509Certificates.X509Certificate2Collection::Find(System.Security.Cryptography.X509Certificates.X509FindType,System.Object,System.Boolean)
extern "C"  X509Certificate2Collection_t_1899689486_0 * X509Certificate2Collection_Find_m162772545_0 (X509Certificate2Collection_t_1899689486_0 * __this, int32_t ___findType, Object_t * ___findValue, bool ___validOnly, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509Certificate2Enumerator System.Security.Cryptography.X509Certificates.X509Certificate2Collection::GetEnumerator()
extern "C"  X509Certificate2Enumerator_t_1079037160_0 * X509Certificate2Collection_GetEnumerator_m_92618981_0 (X509Certificate2Collection_t_1899689486_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
