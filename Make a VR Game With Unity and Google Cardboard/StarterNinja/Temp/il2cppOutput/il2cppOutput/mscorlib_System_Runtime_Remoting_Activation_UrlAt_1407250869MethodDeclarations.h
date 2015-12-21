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

// System.Runtime.Remoting.Activation.UrlAttribute
struct UrlAttribute_t_1407250869_0;
// System.String
struct String_t;
// System.Object
struct Object_t;
// System.Runtime.Remoting.Activation.IConstructionCallMessage
struct IConstructionCallMessage_t_1303764243_0;
// System.Runtime.Remoting.Contexts.Context
struct Context_t_1732618593_0;

#include "codegen/il2cpp-codegen.h"

// System.String System.Runtime.Remoting.Activation.UrlAttribute::get_UrlValue()
extern "C"  String_t* UrlAttribute_get_UrlValue_m_1351742073_0 (UrlAttribute_t_1407250869_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Remoting.Activation.UrlAttribute::Equals(System.Object)
extern "C"  bool UrlAttribute_Equals_m_1128383272_0 (UrlAttribute_t_1407250869_0 * __this, Object_t * ___o, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Runtime.Remoting.Activation.UrlAttribute::GetHashCode()
extern "C"  int32_t UrlAttribute_GetHashCode_m1694018096_0 (UrlAttribute_t_1407250869_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Activation.UrlAttribute::GetPropertiesForNewContext(System.Runtime.Remoting.Activation.IConstructionCallMessage)
extern "C"  void UrlAttribute_GetPropertiesForNewContext_m28161747_0 (UrlAttribute_t_1407250869_0 * __this, Object_t * ___ctorMsg, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Remoting.Activation.UrlAttribute::IsContextOK(System.Runtime.Remoting.Contexts.Context,System.Runtime.Remoting.Activation.IConstructionCallMessage)
extern "C"  bool UrlAttribute_IsContextOK_m864962150_0 (UrlAttribute_t_1407250869_0 * __this, Context_t_1732618593_0 * ___ctx, Object_t * ___msg, const MethodInfo* method) IL2CPP_METHOD_ATTR;
