#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Uri
struct Uri_t18014439_0;
// System.Object
struct Object_t;

#include "mscorlib_System_Object_887538054.h"
#include "mscorlib_System_DateTime_818288618.h"

// System.Net.ServicePoint
struct  ServicePoint_t_1625863919_0  : public Object_t
{
	// System.Uri System.Net.ServicePoint::uri
	Uri_t18014439_0 * ___uri_0;
	// System.Int32 System.Net.ServicePoint::connectionLimit
	int32_t ___connectionLimit_1;
	// System.Int32 System.Net.ServicePoint::maxIdleTime
	int32_t ___maxIdleTime_2;
	// System.Int32 System.Net.ServicePoint::currentConnections
	int32_t ___currentConnections_3;
	// System.DateTime System.Net.ServicePoint::idleSince
	DateTime_t_818288618_0  ___idleSince_4;
	// System.Boolean System.Net.ServicePoint::usesProxy
	bool ___usesProxy_5;
	// System.Boolean System.Net.ServicePoint::sendContinue
	bool ___sendContinue_6;
	// System.Boolean System.Net.ServicePoint::useConnect
	bool ___useConnect_7;
	// System.Object System.Net.ServicePoint::locker
	Object_t * ___locker_8;
	// System.Object System.Net.ServicePoint::hostE
	Object_t * ___hostE_9;
	// System.Boolean System.Net.ServicePoint::useNagle
	bool ___useNagle_10;
};
