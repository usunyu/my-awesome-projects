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

// System.Globalization.DaylightTime
struct DaylightTime_t_1917202897_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_DateTime_818288618.h"
#include "mscorlib_System_TimeSpan_393459662.h"

// System.Void System.Globalization.DaylightTime::.ctor(System.DateTime,System.DateTime,System.TimeSpan)
extern "C"  void DaylightTime__ctor_m_1238635553_0 (DaylightTime_t_1917202897_0 * __this, DateTime_t_818288618_0  ___start, DateTime_t_818288618_0  ___end, TimeSpan_t_393459662_0  ___delta, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.Globalization.DaylightTime::get_Start()
extern "C"  DateTime_t_818288618_0  DaylightTime_get_Start_m_376894415_0 (DaylightTime_t_1917202897_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.Globalization.DaylightTime::get_End()
extern "C"  DateTime_t_818288618_0  DaylightTime_get_End_m1152979434_0 (DaylightTime_t_1917202897_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.TimeSpan System.Globalization.DaylightTime::get_Delta()
extern "C"  TimeSpan_t_393459662_0  DaylightTime_get_Delta_m_1504060821_0 (DaylightTime_t_1917202897_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
