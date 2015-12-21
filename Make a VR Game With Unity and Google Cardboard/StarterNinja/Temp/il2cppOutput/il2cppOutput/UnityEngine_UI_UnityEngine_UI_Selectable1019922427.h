#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Collections.Generic.List`1<UnityEngine.UI.Selectable>
struct List_1_t_464410399_0;
// UnityEngine.UI.AnimationTriggers
struct AnimationTriggers_t_1893216742_0;
// UnityEngine.UI.Graphic
struct Graphic_t141164899_0;
// System.Collections.Generic.List`1<UnityEngine.CanvasGroup>
struct List_1_t678370474_0;

#include "UnityEngine_UI_UnityEngine_EventSystems_UIBehaviou1048696858.h"
#include "UnityEngine_UI_UnityEngine_UI_Navigation243197369.h"
#include "UnityEngine_UI_UnityEngine_UI_Selectable_Transitio_910551031.h"
#include "UnityEngine_UI_UnityEngine_UI_ColorBlock_356800881.h"
#include "UnityEngine_UI_UnityEngine_UI_SpriteState1573477831.h"
#include "UnityEngine_UI_UnityEngine_UI_Selectable_Selectio_1483298023.h"

// UnityEngine.UI.Selectable
struct  Selectable_t1019922427_0  : public UIBehaviour_t1048696858_0
{
	// UnityEngine.UI.Navigation UnityEngine.UI.Selectable::m_Navigation
	Navigation_t243197369_0  ___m_Navigation_3;
	// UnityEngine.UI.Selectable/Transition UnityEngine.UI.Selectable::m_Transition
	int32_t ___m_Transition_4;
	// UnityEngine.UI.ColorBlock UnityEngine.UI.Selectable::m_Colors
	ColorBlock_t_356800881_0  ___m_Colors_5;
	// UnityEngine.UI.SpriteState UnityEngine.UI.Selectable::m_SpriteState
	SpriteState_t1573477831_0  ___m_SpriteState_6;
	// UnityEngine.UI.AnimationTriggers UnityEngine.UI.Selectable::m_AnimationTriggers
	AnimationTriggers_t_1893216742_0 * ___m_AnimationTriggers_7;
	// System.Boolean UnityEngine.UI.Selectable::m_Interactable
	bool ___m_Interactable_8;
	// UnityEngine.UI.Graphic UnityEngine.UI.Selectable::m_TargetGraphic
	Graphic_t141164899_0 * ___m_TargetGraphic_9;
	// System.Boolean UnityEngine.UI.Selectable::m_GroupsAllowInteraction
	bool ___m_GroupsAllowInteraction_10;
	// UnityEngine.UI.Selectable/SelectionState UnityEngine.UI.Selectable::m_CurrentSelectionState
	int32_t ___m_CurrentSelectionState_11;
	// System.Collections.Generic.List`1<UnityEngine.CanvasGroup> UnityEngine.UI.Selectable::m_CanvasGroupCache
	List_1_t678370474_0 * ___m_CanvasGroupCache_12;
	// System.Boolean UnityEngine.UI.Selectable::<isPointerInside>k__BackingField
	bool ___U3CisPointerInsideU3Ek__BackingField_13;
	// System.Boolean UnityEngine.UI.Selectable::<isPointerDown>k__BackingField
	bool ___U3CisPointerDownU3Ek__BackingField_14;
	// System.Boolean UnityEngine.UI.Selectable::<hasSelection>k__BackingField
	bool ___U3ChasSelectionU3Ek__BackingField_15;
};
struct Selectable_t1019922427_0_StaticFields{
	// System.Collections.Generic.List`1<UnityEngine.UI.Selectable> UnityEngine.UI.Selectable::s_List
	List_1_t_464410399_0 * ___s_List_2;
};
