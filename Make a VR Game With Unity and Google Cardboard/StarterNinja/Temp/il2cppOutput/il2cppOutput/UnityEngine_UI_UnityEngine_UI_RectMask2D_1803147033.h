#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.UI.RectangularVertexClipper
struct RectangularVertexClipper_t_693163632_0;
// UnityEngine.RectTransform
struct RectTransform_t212748479_0;
// System.Collections.Generic.List`1<UnityEngine.UI.IClippable>
struct List_1_t_368838010_0;
// System.Collections.Generic.List`1<UnityEngine.UI.RectMask2D>
struct List_1_t_2080217739_0;

#include "UnityEngine_UI_UnityEngine_EventSystems_UIBehaviou1048696858.h"
#include "UnityEngine_UnityEngine_Rect_981940947.h"

// UnityEngine.UI.RectMask2D
struct  RectMask2D_t_1803147033_0  : public UIBehaviour_t1048696858_0
{
	// UnityEngine.UI.RectangularVertexClipper UnityEngine.UI.RectMask2D::m_VertexClipper
	RectangularVertexClipper_t_693163632_0 * ___m_VertexClipper_2;
	// UnityEngine.RectTransform UnityEngine.UI.RectMask2D::m_RectTransform
	RectTransform_t212748479_0 * ___m_RectTransform_3;
	// System.Collections.Generic.List`1<UnityEngine.UI.IClippable> UnityEngine.UI.RectMask2D::m_ClipTargets
	List_1_t_368838010_0 * ___m_ClipTargets_4;
	// System.Boolean UnityEngine.UI.RectMask2D::m_ShouldRecalculateClipRects
	bool ___m_ShouldRecalculateClipRects_5;
	// System.Collections.Generic.List`1<UnityEngine.UI.RectMask2D> UnityEngine.UI.RectMask2D::m_Clippers
	List_1_t_2080217739_0 * ___m_Clippers_6;
	// UnityEngine.Rect UnityEngine.UI.RectMask2D::m_LastClipRectCanvasSpace
	Rect_t_981940947_0  ___m_LastClipRectCanvasSpace_7;
	// System.Boolean UnityEngine.UI.RectMask2D::m_LastClipRectValid
	bool ___m_LastClipRectValid_8;
};
