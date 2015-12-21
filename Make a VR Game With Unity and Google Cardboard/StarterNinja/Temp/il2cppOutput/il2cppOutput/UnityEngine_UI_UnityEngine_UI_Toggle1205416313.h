#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.UI.Graphic
struct Graphic_t141164899_0;
// UnityEngine.UI.ToggleGroup
struct ToggleGroup_t668326022_0;
// UnityEngine.UI.Toggle/ToggleEvent
struct ToggleEvent_t_1079671824_0;

#include "UnityEngine_UI_UnityEngine_UI_Selectable1019922427.h"
#include "UnityEngine_UI_UnityEngine_UI_Toggle_ToggleTransit_941637185.h"

// UnityEngine.UI.Toggle
struct  Toggle_t1205416313_0  : public Selectable_t1019922427_0
{
	// UnityEngine.UI.Toggle/ToggleTransition UnityEngine.UI.Toggle::toggleTransition
	int32_t ___toggleTransition_16;
	// UnityEngine.UI.Graphic UnityEngine.UI.Toggle::graphic
	Graphic_t141164899_0 * ___graphic_17;
	// UnityEngine.UI.ToggleGroup UnityEngine.UI.Toggle::m_Group
	ToggleGroup_t668326022_0 * ___m_Group_18;
	// UnityEngine.UI.Toggle/ToggleEvent UnityEngine.UI.Toggle::onValueChanged
	ToggleEvent_t_1079671824_0 * ___onValueChanged_19;
	// System.Boolean UnityEngine.UI.Toggle::m_IsOn
	bool ___m_IsOn_20;
};
