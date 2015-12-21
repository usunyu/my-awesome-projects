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

// System.Security.SecurityContext
struct SecurityContext_t_1563058692_0;
// System.Threading.CompressedStack
struct CompressedStack_t_1011131402_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Security.SecurityContext::.ctor()
extern "C"  void SecurityContext__ctor_m_1404705900_0 (SecurityContext_t_1563058692_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.SecurityContext::.ctor(System.Security.SecurityContext)
extern "C"  void SecurityContext__ctor_m1345715454_0 (SecurityContext_t_1563058692_0 * __this, SecurityContext_t_1563058692_0 * ___sc, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.SecurityContext System.Security.SecurityContext::Capture()
extern "C"  SecurityContext_t_1563058692_0 * SecurityContext_Capture_m_654168661_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Security.SecurityContext::get_FlowSuppressed()
extern "C"  bool SecurityContext_get_FlowSuppressed_m2046518873_0 (SecurityContext_t_1563058692_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Threading.CompressedStack System.Security.SecurityContext::get_CompressedStack()
extern "C"  CompressedStack_t_1011131402_0 * SecurityContext_get_CompressedStack_m649521097_0 (SecurityContext_t_1563058692_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
