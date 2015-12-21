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

// System.Object
struct Object_t;
// System.Object[]
struct ObjectU5BU5D_t1774424924_0;
// System.Reflection.ICustomAttributeProvider
struct ICustomAttributeProvider_t_1270520389_0;
// System.Type
struct Type_t;
// System.Attribute
struct Attribute_t675283329_0;
// System.Reflection.CustomAttributeData[]
struct CustomAttributeDataU5BU5D_t446357615_0;
// System.Collections.Generic.IList`1<System.Reflection.CustomAttributeData>
struct IList_1_t_780809060_0;
// System.Reflection.PropertyInfo
struct PropertyInfo_t;
// System.AttributeUsageAttribute
struct AttributeUsageAttribute_t_1438537252_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.MonoCustomAttrs::.cctor()
extern "C"  void MonoCustomAttrs__cctor_m_910939574_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.MonoCustomAttrs::IsUserCattrProvider(System.Object)
extern "C"  bool MonoCustomAttrs_IsUserCattrProvider_m151684613_0 (Object_t * __this /* static, unused */, Object_t * ___obj, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.MonoCustomAttrs::GetCustomAttributesInternal(System.Reflection.ICustomAttributeProvider,System.Type,System.Boolean)
extern "C"  ObjectU5BU5D_t1774424924_0* MonoCustomAttrs_GetCustomAttributesInternal_m349185144_0 (Object_t * __this /* static, unused */, Object_t * ___obj, Type_t * ___attributeType, bool ___pseudoAttrs, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.MonoCustomAttrs::GetPseudoCustomAttributes(System.Reflection.ICustomAttributeProvider,System.Type)
extern "C"  ObjectU5BU5D_t1774424924_0* MonoCustomAttrs_GetPseudoCustomAttributes_m_417213146_0 (Object_t * __this /* static, unused */, Object_t * ___obj, Type_t * ___attributeType, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.MonoCustomAttrs::GetCustomAttributesBase(System.Reflection.ICustomAttributeProvider,System.Type)
extern "C"  ObjectU5BU5D_t1774424924_0* MonoCustomAttrs_GetCustomAttributesBase_m_133162503_0 (Object_t * __this /* static, unused */, Object_t * ___obj, Type_t * ___attributeType, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Attribute System.MonoCustomAttrs::GetCustomAttribute(System.Reflection.ICustomAttributeProvider,System.Type,System.Boolean)
extern "C"  Attribute_t675283329_0 * MonoCustomAttrs_GetCustomAttribute_m1376894045_0 (Object_t * __this /* static, unused */, Object_t * ___obj, Type_t * ___attributeType, bool ___inherit, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.MonoCustomAttrs::GetCustomAttributes(System.Reflection.ICustomAttributeProvider,System.Type,System.Boolean)
extern "C"  ObjectU5BU5D_t1774424924_0* MonoCustomAttrs_GetCustomAttributes_m_1274638603_0 (Object_t * __this /* static, unused */, Object_t * ___obj, Type_t * ___attributeType, bool ___inherit, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.MonoCustomAttrs::GetCustomAttributes(System.Reflection.ICustomAttributeProvider,System.Boolean)
extern "C"  ObjectU5BU5D_t1774424924_0* MonoCustomAttrs_GetCustomAttributes_m_1084177656_0 (Object_t * __this /* static, unused */, Object_t * ___obj, bool ___inherit, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.CustomAttributeData[] System.MonoCustomAttrs::GetCustomAttributesDataInternal(System.Reflection.ICustomAttributeProvider)
extern "C"  CustomAttributeDataU5BU5D_t446357615_0* MonoCustomAttrs_GetCustomAttributesDataInternal_m1332961551_0 (Object_t * __this /* static, unused */, Object_t * ___obj, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.Generic.IList`1<System.Reflection.CustomAttributeData> System.MonoCustomAttrs::GetCustomAttributesData(System.Reflection.ICustomAttributeProvider)
extern "C"  Object_t* MonoCustomAttrs_GetCustomAttributesData_m954311775_0 (Object_t * __this /* static, unused */, Object_t * ___obj, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.MonoCustomAttrs::IsDefined(System.Reflection.ICustomAttributeProvider,System.Type,System.Boolean)
extern "C"  bool MonoCustomAttrs_IsDefined_m1052740451_0 (Object_t * __this /* static, unused */, Object_t * ___obj, Type_t * ___attributeType, bool ___inherit, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.MonoCustomAttrs::IsDefinedInternal(System.Reflection.ICustomAttributeProvider,System.Type)
extern "C"  bool MonoCustomAttrs_IsDefinedInternal_m386120631_0 (Object_t * __this /* static, unused */, Object_t * ___obj, Type_t * ___AttributeType, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.PropertyInfo System.MonoCustomAttrs::GetBasePropertyDefinition(System.Reflection.PropertyInfo)
extern "C"  PropertyInfo_t * MonoCustomAttrs_GetBasePropertyDefinition_m1612293317_0 (Object_t * __this /* static, unused */, PropertyInfo_t * ___property, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.ICustomAttributeProvider System.MonoCustomAttrs::GetBase(System.Reflection.ICustomAttributeProvider)
extern "C"  Object_t * MonoCustomAttrs_GetBase_m1327587805_0 (Object_t * __this /* static, unused */, Object_t * ___obj, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.AttributeUsageAttribute System.MonoCustomAttrs::RetrieveAttributeUsage(System.Type)
extern "C"  AttributeUsageAttribute_t_1438537252_0 * MonoCustomAttrs_RetrieveAttributeUsage_m2136597604_0 (Object_t * __this /* static, unused */, Type_t * ___attributeType, const MethodInfo* method) IL2CPP_METHOD_ATTR;
