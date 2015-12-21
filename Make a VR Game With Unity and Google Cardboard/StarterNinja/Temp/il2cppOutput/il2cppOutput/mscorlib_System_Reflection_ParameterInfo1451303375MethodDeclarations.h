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

// System.Reflection.ParameterInfo
struct ParameterInfo_t1451303375_0;
// System.Reflection.Emit.ParameterBuilder
struct ParameterBuilder_t1628251749_0;
// System.Type
struct Type_t;
// System.Reflection.MemberInfo
struct MemberInfo_t;
// System.String
struct String_t;
// System.Object[]
struct ObjectU5BU5D_t1774424924_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Reflection_ParameterAttributes44648888.h"

// System.Void System.Reflection.ParameterInfo::.ctor()
extern "C"  void ParameterInfo__ctor_m_697959135_0 (ParameterInfo_t1451303375_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Reflection.ParameterInfo::.ctor(System.Reflection.Emit.ParameterBuilder,System.Type,System.Reflection.MemberInfo,System.Int32)
extern "C"  void ParameterInfo__ctor_m703590456_0 (ParameterInfo_t1451303375_0 * __this, ParameterBuilder_t1628251749_0 * ___pb, Type_t * ___type, MemberInfo_t * ___member, int32_t ___position, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Reflection.ParameterInfo::.ctor(System.Reflection.ParameterInfo,System.Reflection.MemberInfo)
extern "C"  void ParameterInfo__ctor_m_558303428_0 (ParameterInfo_t1451303375_0 * __this, ParameterInfo_t1451303375_0 * ___pinfo, MemberInfo_t * ___member, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.ParameterInfo::ToString()
extern "C"  String_t* ParameterInfo_ToString_m608350892_0 (ParameterInfo_t1451303375_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Reflection.ParameterInfo::get_ParameterType()
extern "C"  Type_t * ParameterInfo_get_ParameterType_m962921011_0 (ParameterInfo_t1451303375_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.ParameterAttributes System.Reflection.ParameterInfo::get_Attributes()
extern "C"  int32_t ParameterInfo_get_Attributes_m_627084980_0 (ParameterInfo_t1451303375_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.ParameterInfo::get_IsIn()
extern "C"  bool ParameterInfo_get_IsIn_m462729209_0 (ParameterInfo_t1451303375_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.ParameterInfo::get_IsOptional()
extern "C"  bool ParameterInfo_get_IsOptional_m_1454083788_0 (ParameterInfo_t1451303375_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.ParameterInfo::get_IsOut()
extern "C"  bool ParameterInfo_get_IsOut_m1465526300_0 (ParameterInfo_t1451303375_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.ParameterInfo::get_IsRetval()
extern "C"  bool ParameterInfo_get_IsRetval_m843554164_0 (ParameterInfo_t1451303375_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MemberInfo System.Reflection.ParameterInfo::get_Member()
extern "C"  MemberInfo_t * ParameterInfo_get_Member_m215664551_0 (ParameterInfo_t1451303375_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.ParameterInfo::get_Name()
extern "C"  String_t* ParameterInfo_get_Name_m1246625812_0 (ParameterInfo_t1451303375_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Reflection.ParameterInfo::get_Position()
extern "C"  int32_t ParameterInfo_get_Position_m_2068482599_0 (ParameterInfo_t1451303375_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.Reflection.ParameterInfo::GetCustomAttributes(System.Type,System.Boolean)
extern "C"  ObjectU5BU5D_t1774424924_0* ParameterInfo_GetCustomAttributes_m_707584556_0 (ParameterInfo_t1451303375_0 * __this, Type_t * ___attributeType, bool ___inherit, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.ParameterInfo::IsDefined(System.Type,System.Boolean)
extern "C"  bool ParameterInfo_IsDefined_m1420905444_0 (ParameterInfo_t1451303375_0 * __this, Type_t * ___attributeType, bool ___inherit, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.Reflection.ParameterInfo::GetPseudoCustomAttributes()
extern "C"  ObjectU5BU5D_t1774424924_0* ParameterInfo_GetPseudoCustomAttributes_m760090638_0 (ParameterInfo_t1451303375_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
