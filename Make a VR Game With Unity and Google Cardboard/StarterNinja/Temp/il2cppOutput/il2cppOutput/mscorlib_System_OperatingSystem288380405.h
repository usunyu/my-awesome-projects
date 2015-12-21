#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Version
struct Version_t267380989_0;
// System.String
struct String_t;

#include "mscorlib_System_Object_887538054.h"
#include "mscorlib_System_PlatformID1033348745.h"

// System.OperatingSystem
struct  OperatingSystem_t288380405_0  : public Object_t
{
	// System.PlatformID System.OperatingSystem::_platform
	int32_t ____platform_0;
	// System.Version System.OperatingSystem::_version
	Version_t267380989_0 * ____version_1;
	// System.String System.OperatingSystem::_servicePack
	String_t* ____servicePack_2;
};
