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

// System.Reflection.CustomAttributeData
struct CustomAttributeData_t_1653164979_0;
// System.Reflection.ConstructorInfo
struct ConstructorInfo_t1048289184_0;
// System.Object[]
struct ObjectU5BU5D_t1774424924_0;
// System.Collections.Generic.IList`1<System.Reflection.CustomAttributeTypedArgument>
struct IList_1_t1426551311_0;
// System.Collections.Generic.IList`1<System.Reflection.CustomAttributeNamedArgument>
struct IList_1_t_1770574816_0;
// System.Collections.Generic.IList`1<System.Reflection.CustomAttributeData>
struct IList_1_t_780809060_0;
// System.Reflection.Assembly
struct Assembly_t_957553394_0;
// System.Reflection.MemberInfo
struct MemberInfo_t;
// System.Reflection.Module
struct Module_t_2083915884_0;
// System.Reflection.ParameterInfo
struct ParameterInfo_t1451303375_0;
// System.String
struct String_t;
// System.Object
struct Object_t;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Reflection.CustomAttributeData::.ctor(System.Reflection.ConstructorInfo,System.Object[],System.Object[])
extern "C"  void CustomAttributeData__ctor_m1024003907_0 (CustomAttributeData_t_1653164979_0 * __this, ConstructorInfo_t1048289184_0 * ___ctorInfo, ObjectU5BU5D_t1774424924_0* ___ctorArgs, ObjectU5BU5D_t1774424924_0* ___namedArgs, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.ConstructorInfo System.Reflection.CustomAttributeData::get_Constructor()
extern "C"  ConstructorInfo_t1048289184_0 * CustomAttributeData_get_Constructor_m624500001_0 (CustomAttributeData_t_1653164979_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.Generic.IList`1<System.Reflection.CustomAttributeTypedArgument> System.Reflection.CustomAttributeData::get_ConstructorArguments()
extern "C"  Object_t* CustomAttributeData_get_ConstructorArguments_m_809423034_0 (CustomAttributeData_t_1653164979_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.Generic.IList`1<System.Reflection.CustomAttributeNamedArgument> System.Reflection.CustomAttributeData::get_NamedArguments()
extern "C"  Object_t* CustomAttributeData_get_NamedArguments_m_1259606024_0 (CustomAttributeData_t_1653164979_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.Generic.IList`1<System.Reflection.CustomAttributeData> System.Reflection.CustomAttributeData::GetCustomAttributes(System.Reflection.Assembly)
extern "C"  Object_t* CustomAttributeData_GetCustomAttributes_m1041584968_0 (Object_t * __this /* static, unused */, Assembly_t_957553394_0 * ___target, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.Generic.IList`1<System.Reflection.CustomAttributeData> System.Reflection.CustomAttributeData::GetCustomAttributes(System.Reflection.MemberInfo)
extern "C"  Object_t* CustomAttributeData_GetCustomAttributes_m1840127430_0 (Object_t * __this /* static, unused */, MemberInfo_t * ___target, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.Generic.IList`1<System.Reflection.CustomAttributeData> System.Reflection.CustomAttributeData::GetCustomAttributes(System.Reflection.Module)
extern "C"  Object_t* CustomAttributeData_GetCustomAttributes_m_1003009854_0 (Object_t * __this /* static, unused */, Module_t_2083915884_0 * ___target, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.Generic.IList`1<System.Reflection.CustomAttributeData> System.Reflection.CustomAttributeData::GetCustomAttributes(System.Reflection.ParameterInfo)
extern "C"  Object_t* CustomAttributeData_GetCustomAttributes_m_632586771_0 (Object_t * __this /* static, unused */, ParameterInfo_t1451303375_0 * ___target, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.CustomAttributeData::ToString()
extern "C"  String_t* CustomAttributeData_ToString_m440699946_0 (CustomAttributeData_t_1653164979_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.CustomAttributeData::Equals(System.Object)
extern "C"  bool CustomAttributeData_Equals_m613333846_0 (CustomAttributeData_t_1653164979_0 * __this, Object_t * ___obj, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Reflection.CustomAttributeData::GetHashCode()
extern "C"  int32_t CustomAttributeData_GetHashCode_m_1813946578_0 (CustomAttributeData_t_1653164979_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
