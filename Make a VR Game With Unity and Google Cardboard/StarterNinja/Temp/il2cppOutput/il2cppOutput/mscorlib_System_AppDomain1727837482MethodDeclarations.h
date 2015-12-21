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

// System.AppDomain
struct AppDomain_t1727837482_0;
// System.UnhandledExceptionEventHandler
struct UnhandledExceptionEventHandler_t1645375671_0;
// System.String
struct String_t;
// System.Reflection.Assembly
struct Assembly_t_957553394_0;
// System.Security.Policy.Evidence
struct Evidence_t_738265248_0;
// System.Runtime.Remoting.Contexts.Context
struct Context_t_1732618593_0;
// System.Object
struct Object_t;

#include "codegen/il2cpp-codegen.h"

// System.Void System.AppDomain::add_UnhandledException(System.UnhandledExceptionEventHandler)
extern "C"  void AppDomain_add_UnhandledException_m1729490677_0 (AppDomain_t1727837482_0 * __this, UnhandledExceptionEventHandler_t1645375671_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.AppDomain::remove_UnhandledException(System.UnhandledExceptionEventHandler)
extern "C"  void AppDomain_remove_UnhandledException_m1873750054_0 (AppDomain_t1727837482_0 * __this, UnhandledExceptionEventHandler_t1645375671_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.AppDomain::getFriendlyName()
extern "C"  String_t* AppDomain_getFriendlyName_m290133299_0 (AppDomain_t1727837482_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.AppDomain System.AppDomain::getCurDomain()
extern "C"  AppDomain_t1727837482_0 * AppDomain_getCurDomain_m_1780735317_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.AppDomain System.AppDomain::get_CurrentDomain()
extern "C"  AppDomain_t1727837482_0 * AppDomain_get_CurrentDomain_m_846619879_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.Assembly System.AppDomain::LoadAssembly(System.String,System.Security.Policy.Evidence,System.Boolean)
extern "C"  Assembly_t_957553394_0 * AppDomain_LoadAssembly_m_79255240_0 (AppDomain_t1727837482_0 * __this, String_t* ___assemblyRef, Evidence_t_738265248_0 * ___securityEvidence, bool ___refOnly, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.Assembly System.AppDomain::Load(System.String)
extern "C"  Assembly_t_957553394_0 * AppDomain_Load_m_760439933_0 (AppDomain_t1727837482_0 * __this, String_t* ___assemblyString, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.Assembly System.AppDomain::Load(System.String,System.Security.Policy.Evidence,System.Boolean)
extern "C"  Assembly_t_957553394_0 * AppDomain_Load_m_1717097550_0 (AppDomain_t1727837482_0 * __this, String_t* ___assemblyString, Evidence_t_738265248_0 * ___assemblySecurity, bool ___refonly, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Contexts.Context System.AppDomain::InternalSetContext(System.Runtime.Remoting.Contexts.Context)
extern "C"  Context_t_1732618593_0 * AppDomain_InternalSetContext_m_1163165577_0 (Object_t * __this /* static, unused */, Context_t_1732618593_0 * ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Contexts.Context System.AppDomain::InternalGetContext()
extern "C"  Context_t_1732618593_0 * AppDomain_InternalGetContext_m41184350_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Contexts.Context System.AppDomain::InternalGetDefaultContext()
extern "C"  Context_t_1732618593_0 * AppDomain_InternalGetDefaultContext_m_455895935_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.AppDomain::InternalGetProcessGuid(System.String)
extern "C"  String_t* AppDomain_InternalGetProcessGuid_m_1132664568_0 (Object_t * __this /* static, unused */, String_t* ___newguid, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.AppDomain::GetProcessGuid()
extern "C"  String_t* AppDomain_GetProcessGuid_m_596570787_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.AppDomain::ToString()
extern "C"  String_t* AppDomain_ToString_m1440401511_0 (AppDomain_t1727837482_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.Assembly System.AppDomain::DoTypeResolve(System.Object)
extern "C"  Assembly_t_957553394_0 * AppDomain_DoTypeResolve_m_1755662588_0 (AppDomain_t1727837482_0 * __this, Object_t * ___name_or_tb, const MethodInfo* method) IL2CPP_METHOD_ATTR;
