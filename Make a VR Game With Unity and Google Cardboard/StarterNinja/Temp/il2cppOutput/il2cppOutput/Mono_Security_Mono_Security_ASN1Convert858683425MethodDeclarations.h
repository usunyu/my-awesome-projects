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

// Mono.Security.ASN1
struct ASN1_t311288114_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_DateTime_818288618.h"

// Mono.Security.ASN1 Mono.Security.ASN1Convert::FromInt32(System.Int32)
extern "C"  ASN1_t311288114_0 * ASN1Convert_FromInt32_m570537577_0 (Object_t * __this /* static, unused */, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.ASN1 Mono.Security.ASN1Convert::FromOid(System.String)
extern "C"  ASN1_t311288114_0 * ASN1Convert_FromOid_m1663059922_0 (Object_t * __this /* static, unused */, String_t* ___oid, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.ASN1Convert::ToInt32(Mono.Security.ASN1)
extern "C"  int32_t ASN1Convert_ToInt32_m_2019634696_0 (Object_t * __this /* static, unused */, ASN1_t311288114_0 * ___asn1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.ASN1Convert::ToOid(Mono.Security.ASN1)
extern "C"  String_t* ASN1Convert_ToOid_m581448231_0 (Object_t * __this /* static, unused */, ASN1_t311288114_0 * ___asn1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime Mono.Security.ASN1Convert::ToDateTime(Mono.Security.ASN1)
extern "C"  DateTime_t_818288618_0  ASN1Convert_ToDateTime_m864003254_0 (Object_t * __this /* static, unused */, ASN1_t311288114_0 * ___time, const MethodInfo* method) IL2CPP_METHOD_ATTR;
