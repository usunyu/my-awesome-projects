#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Reflection.Emit.ModuleBuilder[]
struct ModuleBuilderU5BU5D_t_364593634_0;
// System.Reflection.Module[]
struct ModuleU5BU5D_t_1188401674_0;
// System.Type
struct Type_t;
// Mono.Security.StrongName
struct StrongName_t_1999711831_0;

#include "mscorlib_System_Reflection_Assembly_957553394.h"

// System.Reflection.Emit.AssemblyBuilder
struct  AssemblyBuilder_t1700742594_0  : public Assembly_t_957553394_0
{
	// System.Reflection.Emit.ModuleBuilder[] System.Reflection.Emit.AssemblyBuilder::modules
	ModuleBuilderU5BU5D_t_364593634_0* ___modules_10;
	// System.Reflection.Module[] System.Reflection.Emit.AssemblyBuilder::loaded_modules
	ModuleU5BU5D_t_1188401674_0* ___loaded_modules_11;
	// System.Type System.Reflection.Emit.AssemblyBuilder::corlib_object_type
	Type_t * ___corlib_object_type_12;
	// System.Type System.Reflection.Emit.AssemblyBuilder::corlib_value_type
	Type_t * ___corlib_value_type_13;
	// System.Type System.Reflection.Emit.AssemblyBuilder::corlib_enum_type
	Type_t * ___corlib_enum_type_14;
	// Mono.Security.StrongName System.Reflection.Emit.AssemblyBuilder::sn
	StrongName_t_1999711831_0 * ___sn_15;
	// System.Boolean System.Reflection.Emit.AssemblyBuilder::is_compiler_context
	bool ___is_compiler_context_16;
};
