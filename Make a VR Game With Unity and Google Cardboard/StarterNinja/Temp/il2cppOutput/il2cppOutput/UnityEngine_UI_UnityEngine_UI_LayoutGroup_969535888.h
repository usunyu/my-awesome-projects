#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.RectOffset
struct RectOffset_t_802832352_0;
// UnityEngine.RectTransform
struct RectTransform_t212748479_0;
// System.Collections.Generic.List`1<UnityEngine.RectTransform>
struct List_1_t67163689_0;

#include "UnityEngine_UI_UnityEngine_EventSystems_UIBehaviou1048696858.h"
#include "UnityEngine_UnityEngine_TextAnchor649899723.h"
#include "UnityEngine_UnityEngine_DrivenRectTransformTracke_1079305987.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"

// UnityEngine.UI.LayoutGroup
struct  LayoutGroup_t_969535888_0  : public UIBehaviour_t1048696858_0
{
	// UnityEngine.RectOffset UnityEngine.UI.LayoutGroup::m_Padding
	RectOffset_t_802832352_0 * ___m_Padding_2;
	// UnityEngine.TextAnchor UnityEngine.UI.LayoutGroup::m_ChildAlignment
	int32_t ___m_ChildAlignment_3;
	// UnityEngine.RectTransform UnityEngine.UI.LayoutGroup::m_Rect
	RectTransform_t212748479_0 * ___m_Rect_4;
	// UnityEngine.DrivenRectTransformTracker UnityEngine.UI.LayoutGroup::m_Tracker
	DrivenRectTransformTracker_t_1079305987_0  ___m_Tracker_5;
	// UnityEngine.Vector2 UnityEngine.UI.LayoutGroup::m_TotalMinSize
	Vector2_t_725341338_0  ___m_TotalMinSize_6;
	// UnityEngine.Vector2 UnityEngine.UI.LayoutGroup::m_TotalPreferredSize
	Vector2_t_725341338_0  ___m_TotalPreferredSize_7;
	// UnityEngine.Vector2 UnityEngine.UI.LayoutGroup::m_TotalFlexibleSize
	Vector2_t_725341338_0  ___m_TotalFlexibleSize_8;
	// System.Collections.Generic.List`1<UnityEngine.RectTransform> UnityEngine.UI.LayoutGroup::m_RectChildren
	List_1_t67163689_0 * ___m_RectChildren_9;
};
