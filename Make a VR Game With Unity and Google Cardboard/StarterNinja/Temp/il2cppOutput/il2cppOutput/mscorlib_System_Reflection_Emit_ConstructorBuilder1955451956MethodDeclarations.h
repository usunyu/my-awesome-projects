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

// System.Reflection.Emit.ConstructorBuilder
struct ConstructorBuilder_t1955451956_0;
// System.Reflection.Emit.TypeBuilder
struct TypeBuilder_t_1794569106_0;
// System.Type[]
struct TypeU5BU5D_t_722972841_0;
// System.Type[][]
struct TypeU5BU5DU5BU5D_t1007804665_0;
// System.Reflection.ParameterInfo[]
struct ParameterInfoU5BU5D_t_1161824911_0;
// System.Object
struct Object_t;
// System.Reflection.Binder
struct Binder_t1890870994_0;
// System.Object[]
struct ObjectU5BU5D_t1774424924_0;
// System.Globalization.CultureInfo
struct CultureInfo_t_1039475404_0;
// System.Type
struct Type_t;
// System.String
struct String_t;
// System.Reflection.Emit.ILGenerator
struct ILGenerator_t2081778301_0;
// System.Reflection.Module
struct Module_t_2083915884_0;
// System.Exception
struct Exception_t2143823668_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Reflection_MethodAttributes1762357312.h"
#include "mscorlib_System_Reflection_CallingConventions732533990.h"
#include "mscorlib_System_Reflection_BindingFlags_1175949782.h"
#include "mscorlib_System_RuntimeMethodHandle_762307834.h"
#include "mscorlib_System_Reflection_Emit_MethodToken605038341.h"

// System.Void System.Reflection.Emit.ConstructorBuilder::.ctor(System.Reflection.Emit.TypeBuilder,System.Reflection.MethodAttributes,System.Reflection.CallingConventions,System.Type[],System.Type[][],System.Type[][])
extern "C"  void ConstructorBuilder__ctor_m_518627685_0 (ConstructorBuilder_t1955451956_0 * __this, TypeBuilder_t_1794569106_0 * ___tb, int32_t ___attributes, int32_t ___callingConvention, TypeU5BU5D_t_722972841_0* ___parameterTypes, TypeU5BU5DU5BU5D_t1007804665_0* ___paramModReq, TypeU5BU5DU5BU5D_t1007804665_0* ___paramModOpt, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.CallingConventions System.Reflection.Emit.ConstructorBuilder::get_CallingConvention()
extern "C"  int32_t ConstructorBuilder_get_CallingConvention_m1759375919_0 (ConstructorBuilder_t1955451956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.Emit.TypeBuilder System.Reflection.Emit.ConstructorBuilder::get_TypeBuilder()
extern "C"  TypeBuilder_t_1794569106_0 * ConstructorBuilder_get_TypeBuilder_m1751255827_0 (ConstructorBuilder_t1955451956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.ParameterInfo[] System.Reflection.Emit.ConstructorBuilder::GetParameters()
extern "C"  ParameterInfoU5BU5D_t_1161824911_0* ConstructorBuilder_GetParameters_m888861432_0 (ConstructorBuilder_t1955451956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.ParameterInfo[] System.Reflection.Emit.ConstructorBuilder::GetParametersInternal()
extern "C"  ParameterInfoU5BU5D_t_1161824911_0* ConstructorBuilder_GetParametersInternal_m465564565_0 (ConstructorBuilder_t1955451956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Reflection.Emit.ConstructorBuilder::GetParameterCount()
extern "C"  int32_t ConstructorBuilder_GetParameterCount_m_462413902_0 (ConstructorBuilder_t1955451956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Reflection.Emit.ConstructorBuilder::Invoke(System.Object,System.Reflection.BindingFlags,System.Reflection.Binder,System.Object[],System.Globalization.CultureInfo)
extern "C"  Object_t * ConstructorBuilder_Invoke_m_1164876119_0 (ConstructorBuilder_t1955451956_0 * __this, Object_t * ___obj, int32_t ___invokeAttr, Binder_t1890870994_0 * ___binder, ObjectU5BU5D_t1774424924_0* ___parameters, CultureInfo_t_1039475404_0 * ___culture, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Reflection.Emit.ConstructorBuilder::Invoke(System.Reflection.BindingFlags,System.Reflection.Binder,System.Object[],System.Globalization.CultureInfo)
extern "C"  Object_t * ConstructorBuilder_Invoke_m_455303561_0 (ConstructorBuilder_t1955451956_0 * __this, int32_t ___invokeAttr, Binder_t1890870994_0 * ___binder, ObjectU5BU5D_t1774424924_0* ___parameters, CultureInfo_t_1039475404_0 * ___culture, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.RuntimeMethodHandle System.Reflection.Emit.ConstructorBuilder::get_MethodHandle()
extern "C"  RuntimeMethodHandle_t_762307834_0  ConstructorBuilder_get_MethodHandle_m_483210095_0 (ConstructorBuilder_t1955451956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodAttributes System.Reflection.Emit.ConstructorBuilder::get_Attributes()
extern "C"  int32_t ConstructorBuilder_get_Attributes_m1523127289_0 (ConstructorBuilder_t1955451956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Reflection.Emit.ConstructorBuilder::get_ReflectedType()
extern "C"  Type_t * ConstructorBuilder_get_ReflectedType_m1081966177_0 (ConstructorBuilder_t1955451956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Reflection.Emit.ConstructorBuilder::get_DeclaringType()
extern "C"  Type_t * ConstructorBuilder_get_DeclaringType_m1851519404_0 (ConstructorBuilder_t1955451956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.Emit.ConstructorBuilder::get_Name()
extern "C"  String_t* ConstructorBuilder_get_Name_m693047033_0 (ConstructorBuilder_t1955451956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.ConstructorBuilder::IsDefined(System.Type,System.Boolean)
extern "C"  bool ConstructorBuilder_IsDefined_m503974687_0 (ConstructorBuilder_t1955451956_0 * __this, Type_t * ___attributeType, bool ___inherit, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.Reflection.Emit.ConstructorBuilder::GetCustomAttributes(System.Boolean)
extern "C"  ObjectU5BU5D_t1774424924_0* ConstructorBuilder_GetCustomAttributes_m1576913186_0 (ConstructorBuilder_t1955451956_0 * __this, bool ___inherit, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.Reflection.Emit.ConstructorBuilder::GetCustomAttributes(System.Type,System.Boolean)
extern "C"  ObjectU5BU5D_t1774424924_0* ConstructorBuilder_GetCustomAttributes_m_1701233137_0 (ConstructorBuilder_t1955451956_0 * __this, Type_t * ___attributeType, bool ___inherit, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.Emit.ILGenerator System.Reflection.Emit.ConstructorBuilder::GetILGenerator()
extern "C"  ILGenerator_t2081778301_0 * ConstructorBuilder_GetILGenerator_m1097527344_0 (ConstructorBuilder_t1955451956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.Emit.ILGenerator System.Reflection.Emit.ConstructorBuilder::GetILGenerator(System.Int32)
extern "C"  ILGenerator_t2081778301_0 * ConstructorBuilder_GetILGenerator_m396483969_0 (ConstructorBuilder_t1955451956_0 * __this, int32_t ___streamSize, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.Emit.MethodToken System.Reflection.Emit.ConstructorBuilder::GetToken()
extern "C"  MethodToken_t605038341_0  ConstructorBuilder_GetToken_m2130394273_0 (ConstructorBuilder_t1955451956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.Module System.Reflection.Emit.ConstructorBuilder::get_Module()
extern "C"  Module_t_2083915884_0 * ConstructorBuilder_get_Module_m779973538_0 (ConstructorBuilder_t1955451956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.Emit.ConstructorBuilder::ToString()
extern "C"  String_t* ConstructorBuilder_ToString_m54772113_0 (ConstructorBuilder_t1955451956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Reflection.Emit.ConstructorBuilder::fixup()
extern "C"  void ConstructorBuilder_fixup_m_303138102_0 (ConstructorBuilder_t1955451956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Reflection.Emit.ConstructorBuilder::get_next_table_index(System.Object,System.Int32,System.Boolean)
extern "C"  int32_t ConstructorBuilder_get_next_table_index_m_234516080_0 (ConstructorBuilder_t1955451956_0 * __this, Object_t * ___obj, int32_t ___table, bool ___inc, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.ConstructorBuilder::get_IsCompilerContext()
extern "C"  bool ConstructorBuilder_get_IsCompilerContext_m884160345_0 (ConstructorBuilder_t1955451956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Exception System.Reflection.Emit.ConstructorBuilder::not_supported()
extern "C"  Exception_t2143823668_0 * ConstructorBuilder_not_supported_m993826647_0 (ConstructorBuilder_t1955451956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Exception System.Reflection.Emit.ConstructorBuilder::not_created()
extern "C"  Exception_t2143823668_0 * ConstructorBuilder_not_created_m1839318289_0 (ConstructorBuilder_t1955451956_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
