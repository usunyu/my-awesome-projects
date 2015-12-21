#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>


#include "mscorlib_System_Object_887538054.h"

struct Il2CppArrayBounds;
// System.Array
struct  Array_t  : public Object_t
{
	Il2CppArrayBounds* bounds;
	il2cpp_array_size_t max_length;
};
