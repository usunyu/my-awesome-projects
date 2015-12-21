#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Resources.IResourceReader
struct IResourceReader_t_2076836298_0;
// System.Collections.Hashtable
struct Hashtable_t_2004451924_0;

#include "mscorlib_System_Object_887538054.h"

// System.Resources.ResourceSet
struct  ResourceSet_t290886256_0  : public Object_t
{
	// System.Resources.IResourceReader System.Resources.ResourceSet::Reader
	Object_t * ___Reader_0;
	// System.Collections.Hashtable System.Resources.ResourceSet::Table
	Hashtable_t_2004451924_0 * ___Table_1;
	// System.Boolean System.Resources.ResourceSet::resources_read
	bool ___resources_read_2;
	// System.Boolean System.Resources.ResourceSet::disposed
	bool ___disposed_3;
};
