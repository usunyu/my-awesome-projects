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

#include "mscorlib_System_Reflection_FieldInfo336243360.h"
#include "mscorlib_System_IntPtr_1047952454.h"
#include "mscorlib_System_RuntimeFieldHandle_1681755259.h"
#include "mscorlib_System_Reflection_FieldAttributes887304649.h"

// System.Reflection.MonoField
struct  MonoField_t  : public FieldInfo_t
{
	// System.IntPtr System.Reflection.MonoField::klass
	IntPtr_t ___klass_0;
	// System.RuntimeFieldHandle System.Reflection.MonoField::fhandle
	RuntimeFieldHandle_t_1681755259_0  ___fhandle_1;
	// System.String System.Reflection.MonoField::name
	String_t* ___name_2;
	// System.Type System.Reflection.MonoField::type
	Type_t * ___type_3;
	// System.Reflection.FieldAttributes System.Reflection.MonoField::attrs
	int32_t ___attrs_4;
};
