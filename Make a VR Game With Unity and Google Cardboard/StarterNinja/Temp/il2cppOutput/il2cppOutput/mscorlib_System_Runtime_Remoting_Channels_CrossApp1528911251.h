#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Object
struct Object_t;
// System.String
struct String_t;

#include "mscorlib_System_Object_887538054.h"

// System.Runtime.Remoting.Channels.CrossAppDomainData
struct  CrossAppDomainData_t1528911251_0  : public Object_t
{
	// System.Object System.Runtime.Remoting.Channels.CrossAppDomainData::_ContextID
	Object_t * ____ContextID_0;
	// System.Int32 System.Runtime.Remoting.Channels.CrossAppDomainData::_DomainID
	int32_t ____DomainID_1;
	// System.String System.Runtime.Remoting.Channels.CrossAppDomainData::_processGuid
	String_t* ____processGuid_2;
};
