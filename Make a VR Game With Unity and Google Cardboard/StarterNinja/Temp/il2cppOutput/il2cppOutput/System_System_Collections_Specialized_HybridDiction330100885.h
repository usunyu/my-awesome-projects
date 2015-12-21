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
// System.Collections.Specialized.ListDictionary
struct ListDictionary_t_2060207753_0;

#include "mscorlib_System_Object_887538054.h"

// System.Collections.Specialized.HybridDictionary
struct  HybridDictionary_t330100885_0  : public Object_t
{
	// System.Boolean System.Collections.Specialized.HybridDictionary::caseInsensitive
	bool ___caseInsensitive_0;
	// System.Collections.Hashtable System.Collections.Specialized.HybridDictionary::hashtable
	Hashtable_t_2004451924_0 * ___hashtable_1;
	// System.Collections.Specialized.ListDictionary System.Collections.Specialized.HybridDictionary::list
	ListDictionary_t_2060207753_0 * ___list_2;
};
