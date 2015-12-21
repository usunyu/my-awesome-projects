#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Type
struct Type_t;
// System.Array
struct Array_t;
// System.String[]
struct StringU5BU5D_t_816028754_0;
// System.Collections.Hashtable
struct Hashtable_t_2004451924_0;
// System.Object
struct Object_t;
// System.MonoEnumInfo/SByteComparer
struct SByteComparer_t_29484282_0;
// System.MonoEnumInfo/ShortComparer
struct ShortComparer_t421349991_0;
// System.MonoEnumInfo/IntComparer
struct IntComparer_t_1209857446_0;
// System.MonoEnumInfo/LongComparer
struct LongComparer_t_1692080789_0;

#include "mscorlib_System_ValueType_103494864.h"

// System.MonoEnumInfo
struct  MonoEnumInfo_t_864545715_0 
{
	// System.Type System.MonoEnumInfo::utype
	Type_t * ___utype_0;
	// System.Array System.MonoEnumInfo::values
	Array_t * ___values_1;
	// System.String[] System.MonoEnumInfo::names
	StringU5BU5D_t_816028754_0* ___names_2;
	// System.Collections.Hashtable System.MonoEnumInfo::name_hash
	Hashtable_t_2004451924_0 * ___name_hash_3;
};
struct MonoEnumInfo_t_864545715_0_StaticFields{
	// System.Collections.Hashtable System.MonoEnumInfo::global_cache
	Hashtable_t_2004451924_0 * ___global_cache_5;
	// System.Object System.MonoEnumInfo::global_cache_monitor
	Object_t * ___global_cache_monitor_6;
	// System.MonoEnumInfo/SByteComparer System.MonoEnumInfo::sbyte_comparer
	SByteComparer_t_29484282_0 * ___sbyte_comparer_7;
	// System.MonoEnumInfo/ShortComparer System.MonoEnumInfo::short_comparer
	ShortComparer_t421349991_0 * ___short_comparer_8;
	// System.MonoEnumInfo/IntComparer System.MonoEnumInfo::int_comparer
	IntComparer_t_1209857446_0 * ___int_comparer_9;
	// System.MonoEnumInfo/LongComparer System.MonoEnumInfo::long_comparer
	LongComparer_t_1692080789_0 * ___long_comparer_10;
};
struct MonoEnumInfo_t_864545715_0_ThreadStaticFields{
	// System.Collections.Hashtable System.MonoEnumInfo::cache
	Hashtable_t_2004451924_0 * ___cache_4;
};
