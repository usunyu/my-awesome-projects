#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.String
struct String_t;
// System.Type
struct Type_t;

#include "mscorlib_System_Reflection_MethodInfo553963095.h"
#include "mscorlib_System_IntPtr_1047952454.h"

// System.Reflection.MonoMethod
struct  MonoMethod_t  : public MethodInfo_t
{
	// System.IntPtr System.Reflection.MonoMethod::mhandle
	IntPtr_t ___mhandle_0;
	// System.String System.Reflection.MonoMethod::name
	String_t* ___name_1;
	// System.Type System.Reflection.MonoMethod::reftype
	Type_t * ___reftype_2;
};
