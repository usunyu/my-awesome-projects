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

// System.Reflection.Emit.EnumBuilder
struct EnumBuilder_t_2133178169_0;
// System.Reflection.Assembly
struct Assembly_t_957553394_0;
// System.String
struct String_t;
// System.Type
struct Type_t;
// System.Reflection.Module
struct Module_t_2083915884_0;
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
// System.Object[]
struct ObjectU5BU5D_t1774424924_0;
// System.Reflection.EventInfo
struct EventInfo_t;
// System.Reflection.FieldInfo
struct FieldInfo_t;
// System.Reflection.FieldInfo[]
struct FieldInfoU5BU5D_t1007324674_0;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// System.Reflection.MethodInfo[]
struct MethodInfoU5BU5D_t_217407495_0;
// System.Reflection.PropertyInfo
struct PropertyInfo_t;
// System.Object
struct Object_t;
// System.Globalization.CultureInfo
struct CultureInfo_t_1039475404_0;
// System.String[]
struct StringU5BU5D_t_816028754_0;
// System.Exception
struct Exception_t2143823668_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_RuntimeTypeHandle_1394772513.h"
#include "mscorlib_System_Reflection_TypeAttributes_156336807.h"
#include "mscorlib_System_Reflection_BindingFlags_1175949782.h"
#include "mscorlib_System_Reflection_CallingConventions732533990.h"

// System.Reflection.Assembly System.Reflection.Emit.EnumBuilder::get_Assembly()
extern "C"  Assembly_t_957553394_0 * EnumBuilder_get_Assembly_m953263493_0 (EnumBuilder_t_2133178169_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.Emit.EnumBuilder::get_AssemblyQualifiedName()
extern "C"  String_t* EnumBuilder_get_AssemblyQualifiedName_m_221563742_0 (EnumBuilder_t_2133178169_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Reflection.Emit.EnumBuilder::get_BaseType()
extern "C"  Type_t * EnumBuilder_get_BaseType_m1867673731_0 (EnumBuilder_t_2133178169_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Reflection.Emit.EnumBuilder::get_DeclaringType()
extern "C"  Type_t * EnumBuilder_get_DeclaringType_m_1432058357_0 (EnumBuilder_t_2133178169_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.Emit.EnumBuilder::get_FullName()
extern "C"  String_t* EnumBuilder_get_FullName_m1393656155_0 (EnumBuilder_t_2133178169_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.Module System.Reflection.Emit.EnumBuilder::get_Module()
extern "C"  Module_t_2083915884_0 * EnumBuilder_get_Module_m1719899717_0 (EnumBuilder_t_2133178169_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.Emit.EnumBuilder::get_Name()
extern "C"  String_t* EnumBuilder_get_Name_m1759013356_0 (EnumBuilder_t_2133178169_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.Emit.EnumBuilder::get_Namespace()
extern "C"  String_t* EnumBuilder_get_Namespace_m467255932_0 (EnumBuilder_t_2133178169_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Reflection.Emit.EnumBuilder::get_ReflectedType()
extern "C"  Type_t * EnumBuilder_get_ReflectedType_m2093355712_0 (EnumBuilder_t_2133178169_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.RuntimeTypeHandle System.Reflection.Emit.EnumBuilder::get_TypeHandle()
extern "C"  RuntimeTypeHandle_t_1394772513_0  EnumBuilder_get_TypeHandle_m_10934544_0 (EnumBuilder_t_2133178169_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Reflection.Emit.EnumBuilder::get_UnderlyingSystemType()
extern "C"  Type_t * EnumBuilder_get_UnderlyingSystemType_m546810590_0 (EnumBuilder_t_2133178169_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.TypeAttributes System.Reflection.Emit.EnumBuilder::GetAttributeFlagsImpl()
extern "C"  int32_t EnumBuilder_GetAttributeFlagsImpl_m1968787096_0 (EnumBuilder_t_2133178169_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.ConstructorInfo System.Reflection.Emit.EnumBuilder::GetConstructorImpl(System.Reflection.BindingFlags,System.Reflection.Binder,System.Reflection.CallingConventions,System.Type[],System.Reflection.ParameterModifier[])
extern "C"  ConstructorInfo_t1048289184_0 * EnumBuilder_GetConstructorImpl_m_1679514771_0 (EnumBuilder_t_2133178169_0 * __this, int32_t ___bindingAttr, Binder_t1890870994_0 * ___binder, int32_t ___callConvention, TypeU5BU5D_t_722972841_0* ___types, ParameterModifierU5BU5D_t836130010_0* ___modifiers, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.ConstructorInfo[] System.Reflection.Emit.EnumBuilder::GetConstructors(System.Reflection.BindingFlags)
extern "C"  ConstructorInfoU5BU5D_t_1911405822_0* EnumBuilder_GetConstructors_m_1252838487_0 (EnumBuilder_t_2133178169_0 * __this, int32_t ___bindingAttr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.Reflection.Emit.EnumBuilder::GetCustomAttributes(System.Boolean)
extern "C"  ObjectU5BU5D_t1774424924_0* EnumBuilder_GetCustomAttributes_m513136559_0 (EnumBuilder_t_2133178169_0 * __this, bool ___inherit, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.Reflection.Emit.EnumBuilder::GetCustomAttributes(System.Type,System.Boolean)
extern "C"  ObjectU5BU5D_t1774424924_0* EnumBuilder_GetCustomAttributes_m_1078533860_0 (EnumBuilder_t_2133178169_0 * __this, Type_t * ___attributeType, bool ___inherit, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Reflection.Emit.EnumBuilder::GetElementType()
extern "C"  Type_t * EnumBuilder_GetElementType_m_1413453649_0 (EnumBuilder_t_2133178169_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.EventInfo System.Reflection.Emit.EnumBuilder::GetEvent(System.String,System.Reflection.BindingFlags)
extern "C"  EventInfo_t * EnumBuilder_GetEvent_m1271024006_0 (EnumBuilder_t_2133178169_0 * __this, String_t* ___name, int32_t ___bindingAttr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.FieldInfo System.Reflection.Emit.EnumBuilder::GetField(System.String,System.Reflection.BindingFlags)
extern "C"  FieldInfo_t * EnumBuilder_GetField_m1074091398_0 (EnumBuilder_t_2133178169_0 * __this, String_t* ___name, int32_t ___bindingAttr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.FieldInfo[] System.Reflection.Emit.EnumBuilder::GetFields(System.Reflection.BindingFlags)
extern "C"  FieldInfoU5BU5D_t1007324674_0* EnumBuilder_GetFields_m1392120169_0 (EnumBuilder_t_2133178169_0 * __this, int32_t ___bindingAttr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type[] System.Reflection.Emit.EnumBuilder::GetInterfaces()
extern "C"  TypeU5BU5D_t_722972841_0* EnumBuilder_GetInterfaces_m_49324507_0 (EnumBuilder_t_2133178169_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodInfo System.Reflection.Emit.EnumBuilder::GetMethodImpl(System.String,System.Reflection.BindingFlags,System.Reflection.Binder,System.Reflection.CallingConventions,System.Type[],System.Reflection.ParameterModifier[])
extern "C"  MethodInfo_t * EnumBuilder_GetMethodImpl_m133610325_0 (EnumBuilder_t_2133178169_0 * __this, String_t* ___name, int32_t ___bindingAttr, Binder_t1890870994_0 * ___binder, int32_t ___callConvention, TypeU5BU5D_t_722972841_0* ___types, ParameterModifierU5BU5D_t836130010_0* ___modifiers, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodInfo[] System.Reflection.Emit.EnumBuilder::GetMethods(System.Reflection.BindingFlags)
extern "C"  MethodInfoU5BU5D_t_217407495_0* EnumBuilder_GetMethods_m_2046897727_0 (EnumBuilder_t_2133178169_0 * __this, int32_t ___bindingAttr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.PropertyInfo System.Reflection.Emit.EnumBuilder::GetPropertyImpl(System.String,System.Reflection.BindingFlags,System.Reflection.Binder,System.Type,System.Type[],System.Reflection.ParameterModifier[])
extern "C"  PropertyInfo_t * EnumBuilder_GetPropertyImpl_m457098616_0 (EnumBuilder_t_2133178169_0 * __this, String_t* ___name, int32_t ___bindingAttr, Binder_t1890870994_0 * ___binder, Type_t * ___returnType, TypeU5BU5D_t_722972841_0* ___types, ParameterModifierU5BU5D_t836130010_0* ___modifiers, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.EnumBuilder::HasElementTypeImpl()
extern "C"  bool EnumBuilder_HasElementTypeImpl_m_417684205_0 (EnumBuilder_t_2133178169_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Reflection.Emit.EnumBuilder::InvokeMember(System.String,System.Reflection.BindingFlags,System.Reflection.Binder,System.Object,System.Object[],System.Reflection.ParameterModifier[],System.Globalization.CultureInfo,System.String[])
extern "C"  Object_t * EnumBuilder_InvokeMember_m_293017366_0 (EnumBuilder_t_2133178169_0 * __this, String_t* ___name, int32_t ___invokeAttr, Binder_t1890870994_0 * ___binder, Object_t * ___target, ObjectU5BU5D_t1774424924_0* ___args, ParameterModifierU5BU5D_t836130010_0* ___modifiers, CultureInfo_t_1039475404_0 * ___culture, StringU5BU5D_t_816028754_0* ___namedParameters, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.EnumBuilder::IsArrayImpl()
extern "C"  bool EnumBuilder_IsArrayImpl_m_592883046_0 (EnumBuilder_t_2133178169_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.EnumBuilder::IsByRefImpl()
extern "C"  bool EnumBuilder_IsByRefImpl_m1232112317_0 (EnumBuilder_t_2133178169_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.EnumBuilder::IsPointerImpl()
extern "C"  bool EnumBuilder_IsPointerImpl_m_1554730114_0 (EnumBuilder_t_2133178169_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.EnumBuilder::IsPrimitiveImpl()
extern "C"  bool EnumBuilder_IsPrimitiveImpl_m_873108824_0 (EnumBuilder_t_2133178169_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.EnumBuilder::IsValueTypeImpl()
extern "C"  bool EnumBuilder_IsValueTypeImpl_m_390809844_0 (EnumBuilder_t_2133178169_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.EnumBuilder::IsDefined(System.Type,System.Boolean)
extern "C"  bool EnumBuilder_IsDefined_m_1953117458_0 (EnumBuilder_t_2133178169_0 * __this, Type_t * ___attributeType, bool ___inherit, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Exception System.Reflection.Emit.EnumBuilder::CreateNotSupportedException()
extern "C"  Exception_t2143823668_0 * EnumBuilder_CreateNotSupportedException_m856223562_0 (EnumBuilder_t_2133178169_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
