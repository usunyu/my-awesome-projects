#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Collections.Hashtable
struct Hashtable_t_2004451924_0;
// System.Text.RegularExpressions.MRUList
struct MRUList_t3523387_0;

#include "mscorlib_System_Object_887538054.h"

// System.Text.RegularExpressions.FactoryCache
struct  FactoryCache_t1335972267_0  : public Object_t
{
	// System.Int32 System.Text.RegularExpressions.FactoryCache::capacity
	int32_t ___capacity_0;
	// System.Collections.Hashtable System.Text.RegularExpressions.FactoryCache::factories
	Hashtable_t_2004451924_0 * ___factories_1;
	// System.Text.RegularExpressions.MRUList System.Text.RegularExpressions.FactoryCache::mru_list
	MRUList_t3523387_0 * ___mru_list_2;
};
