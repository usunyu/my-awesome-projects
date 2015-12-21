#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.String
struct String_t;
// Mono.Security.ASN1
struct ASN1_t1755619932_0;

#include "mscorlib_System_Object_887538054.h"

// Mono.Security.X509.X509Extension
struct  X509Extension_t_7826504_0  : public Object_t
{
	// System.String Mono.Security.X509.X509Extension::extnOid
	String_t* ___extnOid_0;
	// System.Boolean Mono.Security.X509.X509Extension::extnCritical
	bool ___extnCritical_1;
	// Mono.Security.ASN1 Mono.Security.X509.X509Extension::extnValue
	ASN1_t1755619932_0 * ___extnValue_2;
};
