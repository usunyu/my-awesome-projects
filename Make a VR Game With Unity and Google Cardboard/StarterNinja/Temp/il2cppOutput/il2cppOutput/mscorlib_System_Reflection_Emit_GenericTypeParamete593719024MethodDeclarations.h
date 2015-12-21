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

// System.Reflection.Emit.GenericTypeParameterBuilder
struct GenericTypeParameterBuilder_t593719024_0;
// System.Type
struct Type_t;
// System.Reflection.ConstructorInfo
struct ConstructorInfo_t1048289184_0;
// System.Reflection.Binder
struct Binder_t1890870994_0;
// System.Type[]
struct TypeU5BU5D_t_722972841_0;
// System.Reflection.ParameterModifier[]
struct ParameterModifierU5BU5D_t836130010_0;
// System.Reflection.ConstructorInfo[]
struct ConstructorInfoU5BU5D_t_1911405822_0;
// System.Reflection.EventInfo
struct EventInfo_t;
// System.String
struct String_t;
// System.Reflection.FieldInfo
struct FieldInfo_t;
// System.Reflection.FieldInfo[]
struct FieldInfoU5BU5D_t1007324674_0;
// System.Reflection.MethodInfo[]
struct MethodInfoU5BU5D_t_217407495_0;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// System.Reflection.PropertyInfo
struct PropertyInfo_t;
// System.Object
struct Object_t;
// System.Object[]
struct ObjectU5BU5D_t1774424924_0;
// System.Globalization.CultureInfo
struct CultureInfo_t_1039475404_0;
// System.String[]
struct StringU5BU5D_t_816028754_0;
// System.Reflection.Assembly
struct Assembly_t_957553394_0;
// System.Reflection.Module
struct Module_t_2083915884_0;
// System.Exception
struct Exception_t2143823668_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Reflection_TypeAttributes_156336807.h"
#include "mscorlib_System_Reflection_BindingFlags_1175949782.h"
#include "mscorlib_System_Reflection_CallingConventions732533990.h"
#include "mscorlib_System_RuntimeTypeHandle_1394772513.h"

// System.Boolean System.Reflection.Emit.GenericTypeParameterBuilder::IsSubclassOf(System.Type)
extern "C"  bool GenericTypeParameterBuilder_IsSubclassOf_m952653568_0 (GenericTypeParameterBuilder_t593719024_0 * __this, Type_t * ___c, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.TypeAttributes System.Reflection.Emit.GenericTypeParameterBuilder::GetAttributeFlagsImpl()
extern "C"  int32_t GenericTypeParameterBuilder_GetAttributeFlagsImpl_m1663262351_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.ConstructorInfo System.Reflection.Emit.GenericTypeParameterBuilder::GetConstructorImpl(System.Reflection.BindingFlags,System.Reflection.Binder,System.Reflection.CallingConventions,System.Type[],System.Reflection.ParameterModifier[])
extern "C"  ConstructorInfo_t1048289184_0 * GenericTypeParameterBuilder_GetConstructorImpl_m545561302_0 (GenericTypeParameterBuilder_t593719024_0 * __this, int32_t ___bindingAttr, Binder_t1890870994_0 * ___binder, int32_t ___callConvention, TypeU5BU5D_t_722972841_0* ___types, ParameterModifierU5BU5D_t836130010_0* ___modifiers, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.ConstructorInfo[] System.Reflection.Emit.GenericTypeParameterBuilder::GetConstructors(System.Reflection.BindingFlags)
extern "C"  ConstructorInfoU5BU5D_t_1911405822_0* GenericTypeParameterBuilder_GetConstructors_m_1133437792_0 (GenericTypeParameterBuilder_t593719024_0 * __this, int32_t ___bindingAttr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.EventInfo System.Reflection.Emit.GenericTypeParameterBuilder::GetEvent(System.String,System.Reflection.BindingFlags)
extern "C"  EventInfo_t * GenericTypeParameterBuilder_GetEvent_m_2098894673_0 (GenericTypeParameterBuilder_t593719024_0 * __this, String_t* ___name, int32_t ___bindingAttr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.FieldInfo System.Reflection.Emit.GenericTypeParameterBuilder::GetField(System.String,System.Reflection.BindingFlags)
extern "C"  FieldInfo_t * GenericTypeParameterBuilder_GetField_m2024354991_0 (GenericTypeParameterBuilder_t593719024_0 * __this, String_t* ___name, int32_t ___bindingAttr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.FieldInfo[] System.Reflection.Emit.GenericTypeParameterBuilder::GetFields(System.Reflection.BindingFlags)
extern "C"  FieldInfoU5BU5D_t1007324674_0* GenericTypeParameterBuilder_GetFields_m128303008_0 (GenericTypeParameterBuilder_t593719024_0 * __this, int32_t ___bindingAttr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type[] System.Reflection.Emit.GenericTypeParameterBuilder::GetInterfaces()
extern "C"  TypeU5BU5D_t_722972841_0* GenericTypeParameterBuilder_GetInterfaces_m437688604_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodInfo[] System.Reflection.Emit.GenericTypeParameterBuilder::GetMethods(System.Reflection.BindingFlags)
extern "C"  MethodInfoU5BU5D_t_217407495_0* GenericTypeParameterBuilder_GetMethods_m1386969194_0 (GenericTypeParameterBuilder_t593719024_0 * __this, int32_t ___bindingAttr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodInfo System.Reflection.Emit.GenericTypeParameterBuilder::GetMethodImpl(System.String,System.Reflection.BindingFlags,System.Reflection.Binder,System.Reflection.CallingConventions,System.Type[],System.Reflection.ParameterModifier[])
extern "C"  MethodInfo_t * GenericTypeParameterBuilder_GetMethodImpl_m_808109044_0 (GenericTypeParameterBuilder_t593719024_0 * __this, String_t* ___name, int32_t ___bindingAttr, Binder_t1890870994_0 * ___binder, int32_t ___callConvention, TypeU5BU5D_t_722972841_0* ___types, ParameterModifierU5BU5D_t836130010_0* ___modifiers, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.PropertyInfo System.Reflection.Emit.GenericTypeParameterBuilder::GetPropertyImpl(System.String,System.Reflection.BindingFlags,System.Reflection.Binder,System.Type,System.Type[],System.Reflection.ParameterModifier[])
extern "C"  PropertyInfo_t * GenericTypeParameterBuilder_GetPropertyImpl_m_361730399_0 (GenericTypeParameterBuilder_t593719024_0 * __this, String_t* ___name, int32_t ___bindingAttr, Binder_t1890870994_0 * ___binder, Type_t * ___returnType, TypeU5BU5D_t_722972841_0* ___types, ParameterModifierU5BU5D_t836130010_0* ___modifiers, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.GenericTypeParameterBuilder::HasElementTypeImpl()
extern "C"  bool GenericTypeParameterBuilder_HasElementTypeImpl_m814733436_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.GenericTypeParameterBuilder::IsAssignableFrom(System.Type)
extern "C"  bool GenericTypeParameterBuilder_IsAssignableFrom_m_2003321060_0 (GenericTypeParameterBuilder_t593719024_0 * __this, Type_t * ___c, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.GenericTypeParameterBuilder::IsInstanceOfType(System.Object)
extern "C"  bool GenericTypeParameterBuilder_IsInstanceOfType_m_1461926012_0 (GenericTypeParameterBuilder_t593719024_0 * __this, Object_t * ___o, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.GenericTypeParameterBuilder::IsArrayImpl()
extern "C"  bool GenericTypeParameterBuilder_IsArrayImpl_m_657509551_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.GenericTypeParameterBuilder::IsByRefImpl()
extern "C"  bool GenericTypeParameterBuilder_IsByRefImpl_m1167485812_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.GenericTypeParameterBuilder::IsPointerImpl()
extern "C"  bool GenericTypeParameterBuilder_IsPointerImpl_m763708021_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.GenericTypeParameterBuilder::IsPrimitiveImpl()
extern "C"  bool GenericTypeParameterBuilder_IsPrimitiveImpl_m_1942087713_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.GenericTypeParameterBuilder::IsValueTypeImpl()
extern "C"  bool GenericTypeParameterBuilder_IsValueTypeImpl_m_1459788733_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Reflection.Emit.GenericTypeParameterBuilder::InvokeMember(System.String,System.Reflection.BindingFlags,System.Reflection.Binder,System.Object,System.Object[],System.Reflection.ParameterModifier[],System.Globalization.CultureInfo,System.String[])
extern "C"  Object_t * GenericTypeParameterBuilder_InvokeMember_m2055705555_0 (GenericTypeParameterBuilder_t593719024_0 * __this, String_t* ___name, int32_t ___invokeAttr, Binder_t1890870994_0 * ___binder, Object_t * ___target, ObjectU5BU5D_t1774424924_0* ___args, ParameterModifierU5BU5D_t836130010_0* ___modifiers, CultureInfo_t_1039475404_0 * ___culture, StringU5BU5D_t_816028754_0* ___namedParameters, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Reflection.Emit.GenericTypeParameterBuilder::GetElementType()
extern "C"  Type_t * GenericTypeParameterBuilder_GetElementType_m_426342248_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Reflection.Emit.GenericTypeParameterBuilder::get_UnderlyingSystemType()
extern "C"  Type_t * GenericTypeParameterBuilder_get_UnderlyingSystemType_m2109324167_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.Assembly System.Reflection.Emit.GenericTypeParameterBuilder::get_Assembly()
extern "C"  Assembly_t_957553394_0 * GenericTypeParameterBuilder_get_Assembly_m_371278418_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.Emit.GenericTypeParameterBuilder::get_AssemblyQualifiedName()
extern "C"  String_t* GenericTypeParameterBuilder_get_AssemblyQualifiedName_m1986145049_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Reflection.Emit.GenericTypeParameterBuilder::get_BaseType()
extern "C"  Type_t * GenericTypeParameterBuilder_get_BaseType_m1305573036_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.Emit.GenericTypeParameterBuilder::get_FullName()
extern "C"  String_t* GenericTypeParameterBuilder_get_FullName_m79189380_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.GenericTypeParameterBuilder::IsDefined(System.Type,System.Boolean)
extern "C"  bool GenericTypeParameterBuilder_IsDefined_m1789048485_0 (GenericTypeParameterBuilder_t593719024_0 * __this, Type_t * ___attributeType, bool ___inherit, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.Reflection.Emit.GenericTypeParameterBuilder::GetCustomAttributes(System.Boolean)
extern "C"  ObjectU5BU5D_t1774424924_0* GenericTypeParameterBuilder_GetCustomAttributes_m_1137424602_0 (GenericTypeParameterBuilder_t593719024_0 * __this, bool ___inherit, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.Reflection.Emit.GenericTypeParameterBuilder::GetCustomAttributes(System.Type,System.Boolean)
extern "C"  ObjectU5BU5D_t1774424924_0* GenericTypeParameterBuilder_GetCustomAttributes_m_1894853101_0 (GenericTypeParameterBuilder_t593719024_0 * __this, Type_t * ___attributeType, bool ___inherit, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.Emit.GenericTypeParameterBuilder::get_Name()
extern "C"  String_t* GenericTypeParameterBuilder_get_Name_m1381612181_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.Emit.GenericTypeParameterBuilder::get_Namespace()
extern "C"  String_t* GenericTypeParameterBuilder_get_Namespace_m_1626508429_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.Module System.Reflection.Emit.GenericTypeParameterBuilder::get_Module()
extern "C"  Module_t_2083915884_0 * GenericTypeParameterBuilder_get_Module_m_82644818_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Reflection.Emit.GenericTypeParameterBuilder::get_DeclaringType()
extern "C"  Type_t * GenericTypeParameterBuilder_get_DeclaringType_m_2037386878_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Reflection.Emit.GenericTypeParameterBuilder::get_ReflectedType()
extern "C"  Type_t * GenericTypeParameterBuilder_get_ReflectedType_m1488027191_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.RuntimeTypeHandle System.Reflection.Emit.GenericTypeParameterBuilder::get_TypeHandle()
extern "C"  RuntimeTypeHandle_t_1394772513_0  GenericTypeParameterBuilder_get_TypeHandle_m1599953625_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type[] System.Reflection.Emit.GenericTypeParameterBuilder::GetGenericArguments()
extern "C"  TypeU5BU5D_t_722972841_0* GenericTypeParameterBuilder_GetGenericArguments_m_214370815_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Reflection.Emit.GenericTypeParameterBuilder::GetGenericTypeDefinition()
extern "C"  Type_t * GenericTypeParameterBuilder_GetGenericTypeDefinition_m1742966118_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.GenericTypeParameterBuilder::get_ContainsGenericParameters()
extern "C"  bool GenericTypeParameterBuilder_get_ContainsGenericParameters_m_1776193637_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.GenericTypeParameterBuilder::get_IsGenericParameter()
extern "C"  bool GenericTypeParameterBuilder_get_IsGenericParameter_m633698693_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.GenericTypeParameterBuilder::get_IsGenericType()
extern "C"  bool GenericTypeParameterBuilder_get_IsGenericType_m1264804288_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.GenericTypeParameterBuilder::get_IsGenericTypeDefinition()
extern "C"  bool GenericTypeParameterBuilder_get_IsGenericTypeDefinition_m39731123_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Exception System.Reflection.Emit.GenericTypeParameterBuilder::not_supported()
extern "C"  Exception_t2143823668_0 * GenericTypeParameterBuilder_not_supported_m716718603_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.Emit.GenericTypeParameterBuilder::ToString()
extern "C"  String_t* GenericTypeParameterBuilder_ToString_m743337261_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.GenericTypeParameterBuilder::Equals(System.Object)
extern "C"  bool GenericTypeParameterBuilder_Equals_m1747582869_0 (GenericTypeParameterBuilder_t593719024_0 * __this, Object_t * ___o, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Reflection.Emit.GenericTypeParameterBuilder::GetHashCode()
extern "C"  int32_t GenericTypeParameterBuilder_GetHashCode_m_1223048071_0 (GenericTypeParameterBuilder_t593719024_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Reflection.Emit.GenericTypeParameterBuilder::MakeGenericType(System.Type[])
extern "C"  Type_t * GenericTypeParameterBuilder_MakeGenericType_m_890746902_0 (GenericTypeParameterBuilder_t593719024_0 * __this, TypeU5BU5D_t_722972841_0* ___typeArguments, const MethodInfo* method) IL2CPP_METHOD_ATTR;
