#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Collections.ArrayList
struct ArrayList_t536890563_0;
// System.Object
struct Object_t;

#include "mscorlib_System_Object_887538054.h"

// System.Collections.ArrayList/SimpleEnumerator
struct  SimpleEnumerator_t2023319298_0  : public Object_t
{
	// System.Collections.ArrayList System.Collections.ArrayList/SimpleEnumerator::list
	ArrayList_t536890563_0 * ___list_0;
	// System.Int32 System.Collections.ArrayList/SimpleEnumerator::index
	int32_t ___index_1;
	// System.Int32 System.Collections.ArrayList/SimpleEnumerator::version
	int32_t ___version_2;
	// System.Object System.Collections.ArrayList/SimpleEnumerator::currentElement
	Object_t * ___currentElement_3;
};
struct SimpleEnumerator_t2023319298_0_StaticFields{
	// System.Object System.Collections.ArrayList/SimpleEnumerator::endFlag
	Object_t * ___endFlag_4;
};
