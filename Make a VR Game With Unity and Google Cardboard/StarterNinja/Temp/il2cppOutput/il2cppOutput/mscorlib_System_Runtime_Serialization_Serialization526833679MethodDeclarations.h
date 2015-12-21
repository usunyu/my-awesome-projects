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

// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;
// System.Type
struct Type_t;
// System.Runtime.Serialization.IFormatterConverter
struct IFormatterConverter_t1329793872_0;
// System.String
struct String_t;
// System.Object
struct Object_t;
// System.Runtime.Serialization.SerializationInfoEnumerator
struct SerializationInfoEnumerator_t_2012150477_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_DateTime_818288618.h"

// System.Void System.Runtime.Serialization.SerializationInfo::.ctor(System.Type,System.Runtime.Serialization.IFormatterConverter)
extern "C"  void SerializationInfo__ctor_m_1711742488_0 (SerializationInfo_t526833679_0 * __this, Type_t * ___type, Object_t * ___converter, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Serialization.SerializationInfo::AddValue(System.String,System.Object,System.Type)
extern "C"  void SerializationInfo_AddValue_m_953030314_0 (SerializationInfo_t526833679_0 * __this, String_t* ___name, Object_t * ___value, Type_t * ___type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Runtime.Serialization.SerializationInfo::GetValue(System.String,System.Type)
extern "C"  Object_t * SerializationInfo_GetValue_m_169495960_0 (SerializationInfo_t526833679_0 * __this, String_t* ___name, Type_t * ___type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Serialization.SerializationInfo::SetType(System.Type)
extern "C"  void SerializationInfo_SetType_m_1079912232_0 (SerializationInfo_t526833679_0 * __this, Type_t * ___type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Serialization.SerializationInfoEnumerator System.Runtime.Serialization.SerializationInfo::GetEnumerator()
extern "C"  SerializationInfoEnumerator_t_2012150477_0 * SerializationInfo_GetEnumerator_m_1663059933_0 (SerializationInfo_t526833679_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Serialization.SerializationInfo::AddValue(System.String,System.Int16)
extern "C"  void SerializationInfo_AddValue_m_1946428580_0 (SerializationInfo_t526833679_0 * __this, String_t* ___name, int16_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Serialization.SerializationInfo::AddValue(System.String,System.Int32)
extern "C"  void SerializationInfo_AddValue_m_1946426782_0 (SerializationInfo_t526833679_0 * __this, String_t* ___name, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Serialization.SerializationInfo::AddValue(System.String,System.Boolean)
extern "C"  void SerializationInfo_AddValue_m_721558968_0 (SerializationInfo_t526833679_0 * __this, String_t* ___name, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Serialization.SerializationInfo::AddValue(System.String,System.DateTime)
extern "C"  void SerializationInfo_AddValue_m1083712391_0 (SerializationInfo_t526833679_0 * __this, String_t* ___name, DateTime_t_818288618_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Serialization.SerializationInfo::AddValue(System.String,System.Single)
extern "C"  void SerializationInfo_AddValue_m_71665990_0 (SerializationInfo_t526833679_0 * __this, String_t* ___name, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Serialization.SerializationInfo::AddValue(System.String,System.Int64)
extern "C"  void SerializationInfo_AddValue_m_1946423837_0 (SerializationInfo_t526833679_0 * __this, String_t* ___name, int64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Serialization.SerializationInfo::AddValue(System.String,System.UInt64)
extern "C"  void SerializationInfo_AddValue_m787542410_0 (SerializationInfo_t526833679_0 * __this, String_t* ___name, uint64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Serialization.SerializationInfo::AddValue(System.String,System.Object)
extern "C"  void SerializationInfo_AddValue_m469120675_0 (SerializationInfo_t526833679_0 * __this, String_t* ___name, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Serialization.SerializationInfo::GetBoolean(System.String)
extern "C"  bool SerializationInfo_GetBoolean_m1462266865_0 (SerializationInfo_t526833679_0 * __this, String_t* ___name, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int16 System.Runtime.Serialization.SerializationInfo::GetInt16(System.String)
extern "C"  int16_t SerializationInfo_GetInt16_m_1115060815_0 (SerializationInfo_t526833679_0 * __this, String_t* ___name, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Runtime.Serialization.SerializationInfo::GetInt32(System.String)
extern "C"  int32_t SerializationInfo_GetInt32_m_246931343_0 (SerializationInfo_t526833679_0 * __this, String_t* ___name, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.Runtime.Serialization.SerializationInfo::GetInt64(System.String)
extern "C"  int64_t SerializationInfo_GetInt64_m_2083246191_0 (SerializationInfo_t526833679_0 * __this, String_t* ___name, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Runtime.Serialization.SerializationInfo::GetString(System.String)
extern "C"  String_t* SerializationInfo_GetString_m52579033_0 (SerializationInfo_t526833679_0 * __this, String_t* ___name, const MethodInfo* method) IL2CPP_METHOD_ATTR;
