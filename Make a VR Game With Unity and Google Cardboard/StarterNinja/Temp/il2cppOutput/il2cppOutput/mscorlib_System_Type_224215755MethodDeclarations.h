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

// System.Type
struct Type_t;
// System.Reflection.MemberInfo
struct MemberInfo_t;
// System.Object
struct Object_t;
// System.String
struct String_t;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// System.Reflection.Binder
struct Binder_t1890870994_0;
// System.Type[]
struct TypeU5BU5D_t_722972841_0;
// System.Reflection.ParameterModifier[]
struct ParameterModifierU5BU5D_t836130010_0;
// System.Reflection.PropertyInfo
struct PropertyInfo_t;
// System.Reflection.ConstructorInfo
struct ConstructorInfo_t1048289184_0;
// System.Object[]
struct ObjectU5BU5D_t1774424924_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Reflection_TypeAttributes_156336807.h"
#include "mscorlib_System_Reflection_MemberTypes_1980459561.h"
#include "mscorlib_System_RuntimeTypeHandle_1394772513.h"
#include "mscorlib_System_IntPtr_1047952454.h"
#include "mscorlib_System_TypeCode1007107266.h"
#include "mscorlib_System_Reflection_BindingFlags_1175949782.h"
#include "mscorlib_System_Reflection_CallingConventions732533990.h"

// System.Void System.Type::.ctor()
extern "C"  void Type__ctor_m_312451845_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Type::.cctor()
extern "C"  void Type__cctor_m_1578168814_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::FilterName_impl(System.Reflection.MemberInfo,System.Object)
extern "C"  bool Type_FilterName_impl_m1368291769_0 (Object_t * __this /* static, unused */, MemberInfo_t * ___m, Object_t * ___filterCriteria, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::FilterNameIgnoreCase_impl(System.Reflection.MemberInfo,System.Object)
extern "C"  bool Type_FilterNameIgnoreCase_impl_m_535823113_0 (Object_t * __this /* static, unused */, MemberInfo_t * ___m, Object_t * ___filterCriteria, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::FilterAttribute_impl(System.Reflection.MemberInfo,System.Object)
extern "C"  bool Type_FilterAttribute_impl_m1809700868_0 (Object_t * __this /* static, unused */, MemberInfo_t * ___m, Object_t * ___filterCriteria, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.TypeAttributes System.Type::get_Attributes()
extern "C"  int32_t Type_get_Attributes_m1828944147_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Type::get_DeclaringType()
extern "C"  Type_t * Type_get_DeclaringType_m_211058293_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::get_HasElementType()
extern "C"  bool Type_get_HasElementType_m_37765044_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::get_IsAbstract()
extern "C"  bool Type_get_IsAbstract_m_2133242404_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::get_IsArray()
extern "C"  bool Type_get_IsArray_m837983873_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::get_IsByRef()
extern "C"  bool Type_get_IsByRef_m1896439844_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::get_IsClass()
extern "C"  bool Type_get_IsClass_m_1868920352_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::get_IsContextful()
extern "C"  bool Type_get_IsContextful_m535795176_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::get_IsEnum()
extern "C"  bool Type_get_IsEnum_m_416236677_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::get_IsExplicitLayout()
extern "C"  bool Type_get_IsExplicitLayout_m911179384_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::get_IsInterface()
extern "C"  bool Type_get_IsInterface_m996103649_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::get_IsMarshalByRef()
extern "C"  bool Type_get_IsMarshalByRef_m345073144_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::get_IsPointer()
extern "C"  bool Type_get_IsPointer_m839992229_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::get_IsPrimitive()
extern "C"  bool Type_get_IsPrimitive_m992199183_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::get_IsSealed()
extern "C"  bool Type_get_IsSealed_m_1911177002_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::get_IsSerializable()
extern "C"  bool Type_get_IsSerializable_m746172153_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::get_IsValueType()
extern "C"  bool Type_get_IsValueType_m1914757235_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MemberTypes System.Type::get_MemberType()
extern "C"  int32_t Type_get_MemberType_m_962546322_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Type::get_ReflectedType()
extern "C"  Type_t * Type_get_ReflectedType_m_980611520_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.RuntimeTypeHandle System.Type::get_TypeHandle()
extern "C"  RuntimeTypeHandle_t_1394772513_0  Type_get_TypeHandle_m_1898761980_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::Equals(System.Object)
extern "C"  bool Type_Equals_m_369106386_0 (Type_t * __this, Object_t * ___o, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::Equals(System.Type)
extern "C"  bool Type_Equals_m_1174962541_0 (Type_t * __this, Type_t * ___o, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::EqualsInternal(System.Type)
extern "C"  bool Type_EqualsInternal_m1929885654_0 (Type_t * __this, Type_t * ___type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Type::internal_from_handle(System.IntPtr)
extern "C"  Type_t * Type_internal_from_handle_m1276658186_0 (Object_t * __this /* static, unused */, IntPtr_t ___handle, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Type::internal_from_name(System.String,System.Boolean,System.Boolean)
extern "C"  Type_t * Type_internal_from_name_m_893924011_0 (Object_t * __this /* static, unused */, String_t* ___name, bool ___throwOnError, bool ___ignoreCase, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Type::GetType(System.String)
extern "C"  Type_t * Type_GetType_m_1417377665_0 (Object_t * __this /* static, unused */, String_t* ___typeName, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Type::GetType(System.String,System.Boolean)
extern "C"  Type_t * Type_GetType_m_864559842_0 (Object_t * __this /* static, unused */, String_t* ___typeName, bool ___throwOnError, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.TypeCode System.Type::GetTypeCodeInternal(System.Type)
extern "C"  int32_t Type_GetTypeCodeInternal_m_862153639_0 (Object_t * __this /* static, unused */, Type_t * ___type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.TypeCode System.Type::GetTypeCode(System.Type)
extern "C"  int32_t Type_GetTypeCode_m_1324970474_0 (Object_t * __this /* static, unused */, Type_t * ___type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Type::GetTypeFromHandle(System.RuntimeTypeHandle)
extern "C"  Type_t * Type_GetTypeFromHandle_m_488061862_0 (Object_t * __this /* static, unused */, RuntimeTypeHandle_t_1394772513_0  ___handle, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.RuntimeTypeHandle System.Type::GetTypeHandle(System.Object)
extern "C"  RuntimeTypeHandle_t_1394772513_0  Type_GetTypeHandle_m1914576243_0 (Object_t * __this /* static, unused */, Object_t * ___o, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::type_is_subtype_of(System.Type,System.Type,System.Boolean)
extern "C"  bool Type_type_is_subtype_of_m_933291964_0 (Object_t * __this /* static, unused */, Type_t * ___a, Type_t * ___b, bool ___check_interfaces, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::type_is_assignable_from(System.Type,System.Type)
extern "C"  bool Type_type_is_assignable_from_m_1248138335_0 (Object_t * __this /* static, unused */, Type_t * ___a, Type_t * ___b, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::IsSubclassOf(System.Type)
extern "C"  bool Type_IsSubclassOf_m1095320857_0 (Type_t * __this, Type_t * ___c, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::IsAssignableFrom(System.Type)
extern "C"  bool Type_IsAssignableFrom_m1817311413_0 (Type_t * __this, Type_t * ___c, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::IsInstanceOfType(System.Object)
extern "C"  bool Type_IsInstanceOfType_m_2031157539_0 (Type_t * __this, Object_t * ___o, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Type::GetHashCode()
extern "C"  int32_t Type_GetHashCode_m_823473530_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodInfo System.Type::GetMethod(System.String)
extern "C"  MethodInfo_t * Type_GetMethod_m_1410165350_0 (Type_t * __this, String_t* ___name, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodInfo System.Type::GetMethod(System.String,System.Reflection.BindingFlags)
extern "C"  MethodInfo_t * Type_GetMethod_m534507110_0 (Type_t * __this, String_t* ___name, int32_t ___bindingAttr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodInfo System.Type::GetMethod(System.String,System.Reflection.BindingFlags,System.Reflection.Binder,System.Type[],System.Reflection.ParameterModifier[])
extern "C"  MethodInfo_t * Type_GetMethod_m527054833_0 (Type_t * __this, String_t* ___name, int32_t ___bindingAttr, Binder_t1890870994_0 * ___binder, TypeU5BU5D_t_722972841_0* ___types, ParameterModifierU5BU5D_t836130010_0* ___modifiers, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodInfo System.Type::GetMethod(System.String,System.Reflection.BindingFlags,System.Reflection.Binder,System.Reflection.CallingConventions,System.Type[],System.Reflection.ParameterModifier[])
extern "C"  MethodInfo_t * Type_GetMethod_m_2123874031_0 (Type_t * __this, String_t* ___name, int32_t ___bindingAttr, Binder_t1890870994_0 * ___binder, int32_t ___callConvention, TypeU5BU5D_t_722972841_0* ___types, ParameterModifierU5BU5D_t836130010_0* ___modifiers, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.PropertyInfo System.Type::GetProperty(System.String,System.Reflection.BindingFlags)
extern "C"  PropertyInfo_t * Type_GetProperty_m_839371930_0 (Type_t * __this, String_t* ___name, int32_t ___bindingAttr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.PropertyInfo System.Type::GetProperty(System.String,System.Type)
extern "C"  PropertyInfo_t * Type_GetProperty_m786720973_0 (Type_t * __this, String_t* ___name, Type_t * ___returnType, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.PropertyInfo System.Type::GetProperty(System.String,System.Type,System.Type[])
extern "C"  PropertyInfo_t * Type_GetProperty_m_1249127522_0 (Type_t * __this, String_t* ___name, Type_t * ___returnType, TypeU5BU5D_t_722972841_0* ___types, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.PropertyInfo System.Type::GetProperty(System.String,System.Reflection.BindingFlags,System.Reflection.Binder,System.Type,System.Type[],System.Reflection.ParameterModifier[])
extern "C"  PropertyInfo_t * Type_GetProperty_m_384629852_0 (Type_t * __this, String_t* ___name, int32_t ___bindingAttr, Binder_t1890870994_0 * ___binder, Type_t * ___returnType, TypeU5BU5D_t_722972841_0* ___types, ParameterModifierU5BU5D_t836130010_0* ___modifiers, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::IsArrayImpl(System.Type)
extern "C"  bool Type_IsArrayImpl_m813148751_0 (Object_t * __this /* static, unused */, Type_t * ___type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::IsValueTypeImpl()
extern "C"  bool Type_IsValueTypeImpl_m_103384228_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::IsContextfulImpl()
extern "C"  bool Type_IsContextfulImpl_m509765663_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::IsMarshalByRefImpl()
extern "C"  bool Type_IsMarshalByRefImpl_m_192565649_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.ConstructorInfo System.Type::GetConstructor(System.Type[])
extern "C"  ConstructorInfo_t1048289184_0 * Type_GetConstructor_m_1708528615_0 (Type_t * __this, TypeU5BU5D_t_722972841_0* ___types, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.ConstructorInfo System.Type::GetConstructor(System.Reflection.BindingFlags,System.Reflection.Binder,System.Type[],System.Reflection.ParameterModifier[])
extern "C"  ConstructorInfo_t1048289184_0 * Type_GetConstructor_m443034079_0 (Type_t * __this, int32_t ___bindingAttr, Binder_t1890870994_0 * ___binder, TypeU5BU5D_t_722972841_0* ___types, ParameterModifierU5BU5D_t836130010_0* ___modifiers, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.ConstructorInfo System.Type::GetConstructor(System.Reflection.BindingFlags,System.Reflection.Binder,System.Reflection.CallingConventions,System.Type[],System.Reflection.ParameterModifier[])
extern "C"  ConstructorInfo_t1048289184_0 * Type_GetConstructor_m_792032285_0 (Type_t * __this, int32_t ___bindingAttr, Binder_t1890870994_0 * ___binder, int32_t ___callConvention, TypeU5BU5D_t_722972841_0* ___types, ParameterModifierU5BU5D_t836130010_0* ___modifiers, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Type::ToString()
extern "C"  String_t* Type_ToString_m_1910518510_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::get_IsSystemType()
extern "C"  bool Type_get_IsSystemType_m_1242440765_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type[] System.Type::GetGenericArguments()
extern "C"  TypeU5BU5D_t_722972841_0* Type_GetGenericArguments_m202281670_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::get_ContainsGenericParameters()
extern "C"  bool Type_get_ContainsGenericParameters_m1949542132_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::get_IsGenericTypeDefinition()
extern "C"  bool Type_get_IsGenericTypeDefinition_m_434603700_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Type::GetGenericTypeDefinition_impl()
extern "C"  Type_t * Type_GetGenericTypeDefinition_impl_m987436420_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Type::GetGenericTypeDefinition()
extern "C"  Type_t * Type_GetGenericTypeDefinition_m785420605_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::get_IsGenericType()
extern "C"  bool Type_get_IsGenericType_m_900524391_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Type::MakeGenericType(System.Type,System.Type[])
extern "C"  Type_t * Type_MakeGenericType_m_1828029900_0 (Object_t * __this /* static, unused */, Type_t * ___gt, TypeU5BU5D_t_722972841_0* ___types, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Type::MakeGenericType(System.Type[])
extern "C"  Type_t * Type_MakeGenericType_m_1989048255_0 (Type_t * __this, TypeU5BU5D_t_722972841_0* ___typeArguments, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::get_IsGenericParameter()
extern "C"  bool Type_get_IsGenericParameter_m1053942860_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Type::get_IsNested()
extern "C"  bool Type_get_IsNested_m_1512581199_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.Type::GetPseudoCustomAttributes()
extern "C"  ObjectU5BU5D_t1774424924_0* Type_GetPseudoCustomAttributes_m_950491544_0 (Type_t * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
