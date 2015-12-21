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
// System.Type
struct Type_t;

#include "mscorlib_System_Object_887538054.h"

// System.Resources.ResourceManager
struct  ResourceManager_t1099443899_0  : public Object_t
{
	// System.Type System.Resources.ResourceManager::resourceSetType
	Type_t * ___resourceSetType_4;
};
struct ResourceManager_t1099443899_0_StaticFields{
	// System.Collections.Hashtable System.Resources.ResourceManager::ResourceCache
	Hashtable_t_2004451924_0 * ___ResourceCache_0;
	// System.Collections.Hashtable System.Resources.ResourceManager::NonExistent
	Hashtable_t_2004451924_0 * ___NonExistent_1;
	// System.Int32 System.Resources.ResourceManager::HeaderVersionNumber
	int32_t ___HeaderVersionNumber_2;
	// System.Int32 System.Resources.ResourceManager::MagicNumber
	int32_t ___MagicNumber_3;
};
