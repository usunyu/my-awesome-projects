#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Reflection.MonoProperty/GetterAdapter
struct GetterAdapter_t_330280747_0;

#include "mscorlib_System_Reflection_PropertyInfo_1775593653.h"
#include "mscorlib_System_IntPtr_1047952454.h"
#include "mscorlib_System_Reflection_MonoPropertyInfo_303884850.h"
#include "mscorlib_System_Reflection_PInfo1319897878.h"

// System.Reflection.MonoProperty
struct  MonoProperty_t  : public PropertyInfo_t
{
	// System.IntPtr System.Reflection.MonoProperty::klass
	IntPtr_t ___klass_0;
	// System.IntPtr System.Reflection.MonoProperty::prop
	IntPtr_t ___prop_1;
	// System.Reflection.MonoPropertyInfo System.Reflection.MonoProperty::info
	MonoPropertyInfo_t_303884850_0  ___info_2;
	// System.Reflection.PInfo System.Reflection.MonoProperty::cached
	int32_t ___cached_3;
	// System.Reflection.MonoProperty/GetterAdapter System.Reflection.MonoProperty::cached_getter
	GetterAdapter_t_330280747_0 * ___cached_getter_4;
};
