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

// System.Reflection.Binder
struct Binder_t1890870994_0;
// System.Object[]
struct ObjectU5BU5D_t1774424924_0;
// System.Reflection.ParameterInfo[]
struct ParameterInfoU5BU5D_t_1161824911_0;
// System.Globalization.CultureInfo
struct CultureInfo_t_1039475404_0;
// System.Type
struct Type_t;
// System.Reflection.MethodBase
struct MethodBase_t553742458_0;
// System.Reflection.MethodBase[]
struct MethodBaseU5BU5D_t_429439652_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Reflection.Binder::.ctor()
extern "C"  void Binder__ctor_m1880433924_0 (Binder_t1890870994_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Reflection.Binder::.cctor()
extern "C"  void Binder__cctor_m1976780585_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.Binder System.Reflection.Binder::get_DefaultBinder()
extern "C"  Binder_t1890870994_0 * Binder_get_DefaultBinder_m695054407_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Binder::ConvertArgs(System.Reflection.Binder,System.Object[],System.Reflection.ParameterInfo[],System.Globalization.CultureInfo)
extern "C"  bool Binder_ConvertArgs_m_1852526959_0 (Object_t * __this /* static, unused */, Binder_t1890870994_0 * ___binder, ObjectU5BU5D_t1774424924_0* ___args, ParameterInfoU5BU5D_t_1161824911_0* ___pinfo, CultureInfo_t_1039475404_0 * ___culture, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Reflection.Binder::GetDerivedLevel(System.Type)
extern "C"  int32_t Binder_GetDerivedLevel_m1285412278_0 (Object_t * __this /* static, unused */, Type_t * ___type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodBase System.Reflection.Binder::FindMostDerivedMatch(System.Reflection.MethodBase[])
extern "C"  MethodBase_t553742458_0 * Binder_FindMostDerivedMatch_m1519815265_0 (Object_t * __this /* static, unused */, MethodBaseU5BU5D_t_429439652_0* ___match, const MethodInfo* method) IL2CPP_METHOD_ATTR;
