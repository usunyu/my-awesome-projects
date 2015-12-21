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

// System.Security.RuntimeSecurityFrame
struct RuntimeSecurityFrame_t_998212216_0;
// System.Array
struct Array_t;
// System.Reflection.Assembly
struct Assembly_t_957553394_0;
// System.AppDomain
struct AppDomain_t1727837482_0;
// System.String
struct String_t;
// System.Collections.ArrayList
struct ArrayList_t536890563_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Security_SecurityFrame689488122.h"

// System.Void System.Security.SecurityFrame::.ctor(System.Security.RuntimeSecurityFrame)
extern "C"  void SecurityFrame__ctor_m1972945906_0 (SecurityFrame_t689488122_0 * __this, RuntimeSecurityFrame_t_998212216_0 * ___frame, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Array System.Security.SecurityFrame::_GetSecurityStack(System.Int32)
extern "C"  Array_t * SecurityFrame__GetSecurityStack_m_113640505_0 (Object_t * __this /* static, unused */, int32_t ___skip, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.SecurityFrame::InitFromRuntimeFrame(System.Security.RuntimeSecurityFrame)
extern "C"  void SecurityFrame_InitFromRuntimeFrame_m_1671221127_0 (SecurityFrame_t689488122_0 * __this, RuntimeSecurityFrame_t_998212216_0 * ___frame, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.Assembly System.Security.SecurityFrame::get_Assembly()
extern "C"  Assembly_t_957553394_0 * SecurityFrame_get_Assembly_m_2138626020_0 (SecurityFrame_t689488122_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.AppDomain System.Security.SecurityFrame::get_Domain()
extern "C"  AppDomain_t1727837482_0 * SecurityFrame_get_Domain_m_1587822890_0 (SecurityFrame_t689488122_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.SecurityFrame::ToString()
extern "C"  String_t* SecurityFrame_ToString_m_1222341289_0 (SecurityFrame_t689488122_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.ArrayList System.Security.SecurityFrame::GetStack(System.Int32)
extern "C"  ArrayList_t536890563_0 * SecurityFrame_GetStack_m_1582492091_0 (Object_t * __this /* static, unused */, int32_t ___skipFrames, const MethodInfo* method) IL2CPP_METHOD_ATTR;
