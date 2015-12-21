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
// System.Collections.Generic.Dictionary`2<System.String,System.Boolean>
struct Dictionary_2_t831850618_0;
// System.Boolean[]
struct BooleanU5BU5D_t_1574345617_0;

#include "System_System_Collections_Specialized_NameValueCo_1489674975.h"

// System.Net.WebHeaderCollection
struct  WebHeaderCollection_t_1532305783_0  : public NameValueCollection_t_1489674975_0
{
	// System.Boolean System.Net.WebHeaderCollection::internallyCreated
	bool ___internallyCreated_15;
};
struct WebHeaderCollection_t_1532305783_0_StaticFields{
	// System.Collections.Hashtable System.Net.WebHeaderCollection::restricted
	Hashtable_t_2004451924_0 * ___restricted_12;
	// System.Collections.Hashtable System.Net.WebHeaderCollection::multiValue
	Hashtable_t_2004451924_0 * ___multiValue_13;
	// System.Collections.Generic.Dictionary`2<System.String,System.Boolean> System.Net.WebHeaderCollection::restricted_response
	Dictionary_2_t831850618_0 * ___restricted_response_14;
	// System.Boolean[] System.Net.WebHeaderCollection::allowed_chars
	BooleanU5BU5D_t_1574345617_0* ___allowed_chars_16;
};
