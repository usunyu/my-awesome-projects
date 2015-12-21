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

// System.Security.Cryptography.Oid
struct Oid_t1024680945_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Security.Cryptography.Oid::.ctor()
extern "C"  void Oid__ctor_m49113285_0 (Oid_t1024680945_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.Oid::.ctor(System.String)
extern "C"  void Oid__ctor_m_1507238307_0 (Oid_t1024680945_0 * __this, String_t* ___oid, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.Oid::.ctor(System.String,System.String)
extern "C"  void Oid__ctor_m1889247193_0 (Oid_t1024680945_0 * __this, String_t* ___value, String_t* ___friendlyName, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.Oid::.ctor(System.Security.Cryptography.Oid)
extern "C"  void Oid__ctor_m_218583058_0 (Oid_t1024680945_0 * __this, Oid_t1024680945_0 * ___oid, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.Oid::get_FriendlyName()
extern "C"  String_t* Oid_get_FriendlyName_m937320993_0 (Oid_t1024680945_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.Oid::get_Value()
extern "C"  String_t* Oid_get_Value_m216923304_0 (Oid_t1024680945_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.Oid::GetName(System.String)
extern "C"  String_t* Oid_GetName_m1845636801_0 (Oid_t1024680945_0 * __this, String_t* ___oid, const MethodInfo* method) IL2CPP_METHOD_ATTR;
