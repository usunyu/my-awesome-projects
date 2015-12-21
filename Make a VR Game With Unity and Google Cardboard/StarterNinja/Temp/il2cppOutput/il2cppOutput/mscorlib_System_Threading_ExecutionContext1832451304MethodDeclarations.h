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

// System.Threading.ExecutionContext
struct ExecutionContext_t1832451304_0;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;
// System.Security.SecurityContext
struct SecurityContext_t_1563058692_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"

// System.Void System.Threading.ExecutionContext::.ctor()
extern "C"  void ExecutionContext__ctor_m_952672536_0 (ExecutionContext_t1832451304_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.ExecutionContext::.ctor(System.Threading.ExecutionContext)
extern "C"  void ExecutionContext__ctor_m881535614_0 (ExecutionContext_t1832451304_0 * __this, ExecutionContext_t1832451304_0 * ___ec, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.ExecutionContext::.ctor(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void ExecutionContext__ctor_m469890089_0 (ExecutionContext_t1832451304_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Threading.ExecutionContext System.Threading.ExecutionContext::Capture()
extern "C"  ExecutionContext_t1832451304_0 * ExecutionContext_Capture_m1949565907_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.ExecutionContext::GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void ExecutionContext_GetObjectData_m67437190_0 (ExecutionContext_t1832451304_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.SecurityContext System.Threading.ExecutionContext::get_SecurityContext()
extern "C"  SecurityContext_t_1563058692_0 * ExecutionContext_get_SecurityContext_m_1983846561_0 (ExecutionContext_t1832451304_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.ExecutionContext::set_SecurityContext(System.Security.SecurityContext)
extern "C"  void ExecutionContext_set_SecurityContext_m_319980326_0 (ExecutionContext_t1832451304_0 * __this, SecurityContext_t_1563058692_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Threading.ExecutionContext::get_FlowSuppressed()
extern "C"  bool ExecutionContext_get_FlowSuppressed_m927554565_0 (ExecutionContext_t1832451304_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Threading.ExecutionContext::IsFlowSuppressed()
extern "C"  bool ExecutionContext_IsFlowSuppressed_m_1353219642_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
