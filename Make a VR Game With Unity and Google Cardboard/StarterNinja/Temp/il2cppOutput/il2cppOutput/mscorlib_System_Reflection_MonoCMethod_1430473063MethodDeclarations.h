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

// System.Reflection.MonoCMethod
struct MonoCMethod_t_1430473063_0;
// System.Reflection.ParameterInfo[]
struct ParameterInfoU5BU5D_t_1161824911_0;
// System.Object
struct Object_t;
// System.Object[]
struct ObjectU5BU5D_t1774424924_0;
// System.Exception
struct Exception_t2143823668_0;
// System.Reflection.Binder
struct Binder_t1890870994_0;
// System.Globalization.CultureInfo
struct CultureInfo_t_1039475404_0;
// System.Type
struct Type_t;
// System.String
struct String_t;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Reflection_BindingFlags_1175949782.h"
#include "mscorlib_System_RuntimeMethodHandle_762307834.h"
#include "mscorlib_System_Reflection_MethodAttributes1762357312.h"
#include "mscorlib_System_Reflection_CallingConventions732533990.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"

// System.Void System.Reflection.MonoCMethod::.ctor()
extern "C"  void MonoCMethod__ctor_m1949313751_0 (MonoCMethod_t_1430473063_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.ParameterInfo[] System.Reflection.MonoCMethod::GetParameters()
extern "C"  ParameterInfoU5BU5D_t_1161824911_0* MonoCMethod_GetParameters_m993439667_0 (MonoCMethod_t_1430473063_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Reflection.MonoCMethod::InternalInvoke(System.Object,System.Object[],System.Exception&)
extern "C"  Object_t * MonoCMethod_InternalInvoke_m1703330793_0 (MonoCMethod_t_1430473063_0 * __this, Object_t * ___obj, ObjectU5BU5D_t1774424924_0* ___parameters, Exception_t2143823668_0 ** ___exc, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Reflection.MonoCMethod::Invoke(System.Object,System.Reflection.BindingFlags,System.Reflection.Binder,System.Object[],System.Globalization.CultureInfo)
extern "C"  Object_t * MonoCMethod_Invoke_m_811047410_0 (MonoCMethod_t_1430473063_0 * __this, Object_t * ___obj, int32_t ___invokeAttr, Binder_t1890870994_0 * ___binder, ObjectU5BU5D_t1774424924_0* ___parameters, CultureInfo_t_1039475404_0 * ___culture, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Reflection.MonoCMethod::Invoke(System.Reflection.BindingFlags,System.Reflection.Binder,System.Object[],System.Globalization.CultureInfo)
extern "C"  Object_t * MonoCMethod_Invoke_m_1821621604_0 (MonoCMethod_t_1430473063_0 * __this, int32_t ___invokeAttr, Binder_t1890870994_0 * ___binder, ObjectU5BU5D_t1774424924_0* ___parameters, CultureInfo_t_1039475404_0 * ___culture, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.RuntimeMethodHandle System.Reflection.MonoCMethod::get_MethodHandle()
extern "C"  RuntimeMethodHandle_t_762307834_0  MonoCMethod_get_MethodHandle_m1736599926_0 (MonoCMethod_t_1430473063_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodAttributes System.Reflection.MonoCMethod::get_Attributes()
extern "C"  int32_t MonoCMethod_get_Attributes_m_1802326754_0 (MonoCMethod_t_1430473063_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.CallingConventions System.Reflection.MonoCMethod::get_CallingConvention()
extern "C"  int32_t MonoCMethod_get_CallingConvention_m_882652054_0 (MonoCMethod_t_1430473063_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Reflection.MonoCMethod::get_ReflectedType()
extern "C"  Type_t * MonoCMethod_get_ReflectedType_m_1085071460_0 (MonoCMethod_t_1430473063_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Reflection.MonoCMethod::get_DeclaringType()
extern "C"  Type_t * MonoCMethod_get_DeclaringType_m_315518233_0 (MonoCMethod_t_1430473063_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.MonoCMethod::get_Name()
extern "C"  String_t* MonoCMethod_get_Name_m_1964156450_0 (MonoCMethod_t_1430473063_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.MonoCMethod::IsDefined(System.Type,System.Boolean)
extern "C"  bool MonoCMethod_IsDefined_m_1615556710_0 (MonoCMethod_t_1430473063_0 * __this, Type_t * ___attributeType, bool ___inherit, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.Reflection.MonoCMethod::GetCustomAttributes(System.Boolean)
extern "C"  ObjectU5BU5D_t1774424924_0* MonoCMethod_GetCustomAttributes_m_854359587_0 (MonoCMethod_t_1430473063_0 * __this, bool ___inherit, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.Reflection.MonoCMethod::GetCustomAttributes(System.Type,System.Boolean)
extern "C"  ObjectU5BU5D_t1774424924_0* MonoCMethod_GetCustomAttributes_m2022749770_0 (MonoCMethod_t_1430473063_0 * __this, Type_t * ___attributeType, bool ___inherit, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.MonoCMethod::ToString()
extern "C"  String_t* MonoCMethod_ToString_m1692535926_0 (MonoCMethod_t_1430473063_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Reflection.MonoCMethod::GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void MonoCMethod_GetObjectData_m_345519371_0 (MonoCMethod_t_1430473063_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
