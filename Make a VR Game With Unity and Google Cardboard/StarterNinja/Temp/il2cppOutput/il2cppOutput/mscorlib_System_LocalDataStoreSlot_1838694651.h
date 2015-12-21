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
// System.Boolean[]
struct BooleanU5BU5D_t_1574345617_0;

#include "mscorlib_System_Object_887538054.h"

// System.LocalDataStoreSlot
struct  LocalDataStoreSlot_t_1838694651_0  : public Object_t
{
	// System.Int32 System.LocalDataStoreSlot::slot
	int32_t ___slot_0;
	// System.Boolean System.LocalDataStoreSlot::thread_local
	bool ___thread_local_1;
};
struct LocalDataStoreSlot_t_1838694651_0_StaticFields{
	// System.Object System.LocalDataStoreSlot::lock_obj
	Object_t * ___lock_obj_2;
	// System.Boolean[] System.LocalDataStoreSlot::slot_bitmap_thread
	BooleanU5BU5D_t_1574345617_0* ___slot_bitmap_thread_3;
	// System.Boolean[] System.LocalDataStoreSlot::slot_bitmap_context
	BooleanU5BU5D_t_1574345617_0* ___slot_bitmap_context_4;
};
