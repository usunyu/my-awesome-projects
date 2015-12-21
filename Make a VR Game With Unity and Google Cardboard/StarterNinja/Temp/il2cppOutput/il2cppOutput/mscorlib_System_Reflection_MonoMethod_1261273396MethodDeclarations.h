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

// System.Reflection.MonoMethod
struct MonoMethod_t;
// System.String
struct String_t;
// System.Reflection.MethodBase
struct MethodBase_t553742458_0;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// System.Type
struct Type_t;
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
// System.Runtime.InteropServices.DllImportAttribute
struct DllImportAttribute_t_592257961_0;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;
// System.Type[]
struct TypeU5BU5D_t_722972841_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Reflection_BindingFlags_1175949782.h"
#include "mscorlib_System_RuntimeMethodHandle_762307834.h"
#include "mscorlib_System_Reflection_MethodAttributes1762357312.h"
#include "mscorlib_System_Reflection_CallingConventions732533990.h"
#include "mscorlib_System_IntPtr_1047952454.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"

// System.Void System.Reflection.MonoMethod::.ctor()
extern "C"  void MonoMethod__ctor_m370255050_0 (MonoMethod_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.MonoMethod::get_name(System.Reflection.MethodBase)
extern "C"  String_t* MonoMethod_get_name_m439428219_0 (Object_t * __this /* static, unused */, MethodBase_t553742458_0 * ___method, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MonoMethod System.Reflection.MonoMethod::get_base_definition(System.Reflection.MonoMethod)
extern "C"  MonoMethod_t * MonoMethod_get_base_definition_m1389391157_0 (Object_t * __this /* static, unused */, MonoMethod_t * ___method, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodInfo System.Reflection.MonoMethod::GetBaseDefinition()
extern "C"  MethodInfo_t * MonoMethod_GetBaseDefinition_m_417517142_0 (MonoMethod_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Reflection.MonoMethod::get_ReturnType()
extern "C"  Type_t * MonoMethod_get_ReturnType_m_1928338969_0 (MonoMethod_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.ParameterInfo[] System.Reflection.MonoMethod::GetParameters()
extern "C"  ParameterInfoU5BU5D_t_1161824911_0* MonoMethod_GetParameters_m1957703466_0 (MonoMethod_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Reflection.MonoMethod::InternalInvoke(System.Object,System.Object[],System.Exception&)
extern "C"  Object_t * MonoMethod_InternalInvoke_m_72677678_0 (MonoMethod_t * __this, Object_t * ___obj, ObjectU5BU5D_t1774424924_0* ___parameters, Exception_t2143823668_0 ** ___exc, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Reflection.MonoMethod::Invoke(System.Object,System.Reflection.BindingFlags,System.Reflection.Binder,System.Object[],System.Globalization.CultureInfo)
extern "C"  Object_t * MonoMethod_Invoke_m240151045_0 (MonoMethod_t * __this, Object_t * ___obj, int32_t ___invokeAttr, Binder_t1890870994_0 * ___binder, ObjectU5BU5D_t1774424924_0* ___parameters, CultureInfo_t_1039475404_0 * ___culture, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.RuntimeMethodHandle System.Reflection.MonoMethod::get_MethodHandle()
extern "C"  RuntimeMethodHandle_t_762307834_0  MonoMethod_get_MethodHandle_m_919234731_0 (MonoMethod_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodAttributes System.Reflection.MonoMethod::get_Attributes()
extern "C"  int32_t MonoMethod_get_Attributes_m_727169783_0 (MonoMethod_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.CallingConventions System.Reflection.MonoMethod::get_CallingConvention()
extern "C"  int32_t MonoMethod_get_CallingConvention_m1596053931_0 (MonoMethod_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Reflection.MonoMethod::get_ReflectedType()
extern "C"  Type_t * MonoMethod_get_ReflectedType_m64213147_0 (MonoMethod_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Reflection.MonoMethod::get_DeclaringType()
extern "C"  Type_t * MonoMethod_get_DeclaringType_m833766374_0 (MonoMethod_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.MonoMethod::get_Name()
extern "C"  String_t* MonoMethod_get_Name_m_994028431_0 (MonoMethod_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.MonoMethod::IsDefined(System.Type,System.Boolean)
extern "C"  bool MonoMethod_IsDefined_m1598659081_0 (MonoMethod_t * __this, Type_t * ___attributeType, bool ___inherit, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.Reflection.MonoMethod::GetCustomAttributes(System.Boolean)
extern "C"  ObjectU5BU5D_t1774424924_0* MonoMethod_GetCustomAttributes_m534554826_0 (MonoMethod_t * __this, bool ___inherit, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.Reflection.MonoMethod::GetCustomAttributes(System.Type,System.Boolean)
extern "C"  ObjectU5BU5D_t1774424924_0* MonoMethod_GetCustomAttributes_m673046967_0 (MonoMethod_t * __this, Type_t * ___attributeType, bool ___inherit, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.InteropServices.DllImportAttribute System.Reflection.MonoMethod::GetDllImportAttribute(System.IntPtr)
extern "C"  DllImportAttribute_t_592257961_0 * MonoMethod_GetDllImportAttribute_m_897036389_0 (Object_t * __this /* static, unused */, IntPtr_t ___mhandle, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.Reflection.MonoMethod::GetPseudoCustomAttributes()
extern "C"  ObjectU5BU5D_t1774424924_0* MonoMethod_GetPseudoCustomAttributes_m_61250703_0 (MonoMethod_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.MonoMethod::ShouldPrintFullName(System.Type)
extern "C"  bool MonoMethod_ShouldPrintFullName_m401880127_0 (Object_t * __this /* static, unused */, Type_t * ___type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.MonoMethod::ToString()
extern "C"  String_t* MonoMethod_ToString_m_1632303351_0 (MonoMethod_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Reflection.MonoMethod::GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void MonoMethod_GetObjectData_m1160867688_0 (MonoMethod_t * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodInfo System.Reflection.MonoMethod::MakeGenericMethod(System.Type[])
extern "C"  MethodInfo_t * MonoMethod_MakeGenericMethod_m_2044460387_0 (MonoMethod_t * __this, TypeU5BU5D_t_722972841_0* ___methodInstantiation, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodInfo System.Reflection.MonoMethod::MakeGenericMethod_impl(System.Type[])
extern "C"  MethodInfo_t * MonoMethod_MakeGenericMethod_impl_m_2134378800_0 (MonoMethod_t * __this, TypeU5BU5D_t_722972841_0* ___types, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type[] System.Reflection.MonoMethod::GetGenericArguments()
extern "C"  TypeU5BU5D_t_722972841_0* MonoMethod_GetGenericArguments_m978560229_0 (MonoMethod_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.MonoMethod::get_IsGenericMethodDefinition()
extern "C"  bool MonoMethod_get_IsGenericMethodDefinition_m279322622_0 (MonoMethod_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.MonoMethod::get_IsGenericMethod()
extern "C"  bool MonoMethod_get_IsGenericMethod_m1007555531_0 (MonoMethod_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.MonoMethod::get_ContainsGenericParameters()
extern "C"  bool MonoMethod_get_ContainsGenericParameters_m1023389183_0 (MonoMethod_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
