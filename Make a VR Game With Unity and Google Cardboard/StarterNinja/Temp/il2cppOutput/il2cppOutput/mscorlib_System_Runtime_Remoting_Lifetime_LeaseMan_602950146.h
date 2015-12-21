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
// System.Threading.Timer
struct Timer_t_161177996_0;

#include "mscorlib_System_Object_887538054.h"

// System.Runtime.Remoting.Lifetime.LeaseManager
struct  LeaseManager_t_602950146_0  : public Object_t
{
	// System.Collections.ArrayList System.Runtime.Remoting.Lifetime.LeaseManager::_objects
	ArrayList_t536890563_0 * ____objects_0;
	// System.Threading.Timer System.Runtime.Remoting.Lifetime.LeaseManager::_timer
	Timer_t_161177996_0 * ____timer_1;
};
