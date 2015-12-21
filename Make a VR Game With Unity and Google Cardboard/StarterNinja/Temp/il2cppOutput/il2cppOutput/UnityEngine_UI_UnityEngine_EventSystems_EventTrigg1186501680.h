#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.EventSystems.EventTrigger/TriggerEvent
struct TriggerEvent_t585130564_0;

#include "mscorlib_System_Object_887538054.h"
#include "UnityEngine_UI_UnityEngine_EventSystems_EventTrigge735347015.h"

// UnityEngine.EventSystems.EventTrigger/Entry
struct  Entry_t1186501680_0  : public Object_t
{
	// UnityEngine.EventSystems.EventTriggerType UnityEngine.EventSystems.EventTrigger/Entry::eventID
	int32_t ___eventID_0;
	// UnityEngine.EventSystems.EventTrigger/TriggerEvent UnityEngine.EventSystems.EventTrigger/Entry::callback
	TriggerEvent_t585130564_0 * ___callback_1;
};
