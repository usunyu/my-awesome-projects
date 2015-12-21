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

// System.Runtime.Remoting.Contexts.ContextAttribute
struct ContextAttribute_t1985836733_0;
// System.String
struct String_t;
// System.Object
struct Object_t;
// System.Runtime.Remoting.Contexts.Context
struct Context_t_1732618593_0;
// System.Runtime.Remoting.Activation.IConstructionCallMessage
struct IConstructionCallMessage_t_1303764243_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Runtime.Remoting.Contexts.ContextAttribute::.ctor(System.String)
extern "C"  void ContextAttribute__ctor_m2021650223_0 (ContextAttribute_t1985836733_0 * __this, String_t* ___name, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Runtime.Remoting.Contexts.ContextAttribute::get_Name()
extern "C"  String_t* ContextAttribute_get_Name_m_1681023998_0 (ContextAttribute_t1985836733_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Remoting.Contexts.ContextAttribute::Equals(System.Object)
extern "C"  bool ContextAttribute_Equals_m1391598694_0 (ContextAttribute_t1985836733_0 * __this, Object_t * ___o, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Contexts.ContextAttribute::Freeze(System.Runtime.Remoting.Contexts.Context)
extern "C"  void ContextAttribute_Freeze_m533228205_0 (ContextAttribute_t1985836733_0 * __this, Context_t_1732618593_0 * ___newContext, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Runtime.Remoting.Contexts.ContextAttribute::GetHashCode()
extern "C"  int32_t ContextAttribute_GetHashCode_m1120368958_0 (ContextAttribute_t1985836733_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Contexts.ContextAttribute::GetPropertiesForNewContext(System.Runtime.Remoting.Activation.IConstructionCallMessage)
extern "C"  void ContextAttribute_GetPropertiesForNewContext_m_1579961503_0 (ContextAttribute_t1985836733_0 * __this, Object_t * ___ctorMsg, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Remoting.Contexts.ContextAttribute::IsContextOK(System.Runtime.Remoting.Contexts.Context,System.Runtime.Remoting.Activation.IConstructionCallMessage)
extern "C"  bool ContextAttribute_IsContextOK_m_505219852_0 (ContextAttribute_t1985836733_0 * __this, Context_t_1732618593_0 * ___ctx, Object_t * ___ctorMsg, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Remoting.Contexts.ContextAttribute::IsNewContextOK(System.Runtime.Remoting.Contexts.Context)
extern "C"  bool ContextAttribute_IsNewContextOK_m1034674857_0 (ContextAttribute_t1985836733_0 * __this, Context_t_1732618593_0 * ___newCtx, const MethodInfo* method) IL2CPP_METHOD_ATTR;
