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

// System.Reflection.Emit.AssemblyBuilder
struct AssemblyBuilder_t1700742594_0;
// System.String
struct String_t;
// System.Reflection.Module[]
struct ModuleU5BU5D_t_1188401674_0;
// System.Type[]
struct TypeU5BU5D_t_722972841_0;
// System.Exception
struct Exception_t2143823668_0;
// System.Reflection.AssemblyName
struct AssemblyName_t215784633_0;

#include "codegen/il2cpp-codegen.h"

// System.String System.Reflection.Emit.AssemblyBuilder::get_Location()
extern "C"  String_t* AssemblyBuilder_get_Location_m2002209681_0 (AssemblyBuilder_t1700742594_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.Module[] System.Reflection.Emit.AssemblyBuilder::GetModulesInternal()
extern "C"  ModuleU5BU5D_t_1188401674_0* AssemblyBuilder_GetModulesInternal_m_1576185257_0 (AssemblyBuilder_t1700742594_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type[] System.Reflection.Emit.AssemblyBuilder::GetTypes(System.Boolean)
extern "C"  TypeU5BU5D_t_722972841_0* AssemblyBuilder_GetTypes_m_833851422_0 (AssemblyBuilder_t1700742594_0 * __this, bool ___exportedOnly, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.Emit.AssemblyBuilder::get_IsCompilerContext()
extern "C"  bool AssemblyBuilder_get_IsCompilerContext_m332025933_0 (AssemblyBuilder_t1700742594_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Exception System.Reflection.Emit.AssemblyBuilder::not_supported()
extern "C"  Exception_t2143823668_0 * AssemblyBuilder_not_supported_m186391929_0 (AssemblyBuilder_t1700742594_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.AssemblyName System.Reflection.Emit.AssemblyBuilder::UnprotectedGetName()
extern "C"  AssemblyName_t215784633_0 * AssemblyBuilder_UnprotectedGetName_m_906434094_0 (AssemblyBuilder_t1700742594_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
