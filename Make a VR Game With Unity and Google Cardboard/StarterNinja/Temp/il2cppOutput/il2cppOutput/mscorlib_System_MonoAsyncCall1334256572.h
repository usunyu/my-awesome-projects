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

#include "mscorlib_System_Object_887538054.h"
#include "mscorlib_System_IntPtr_1047952454.h"

// System.MonoAsyncCall
struct  MonoAsyncCall_t1334256572_0  : public Object_t
{
	// System.Object System.MonoAsyncCall::msg
	Object_t * ___msg_0;
	// System.IntPtr System.MonoAsyncCall::cb_method
	IntPtr_t ___cb_method_1;
	// System.Object System.MonoAsyncCall::cb_target
	Object_t * ___cb_target_2;
	// System.Object System.MonoAsyncCall::state
	Object_t * ___state_3;
	// System.Object System.MonoAsyncCall::res
	Object_t * ___res_4;
	// System.Object System.MonoAsyncCall::out_args
	Object_t * ___out_args_5;
	// System.Int64 System.MonoAsyncCall::wait_event
	int64_t ___wait_event_6;
};
