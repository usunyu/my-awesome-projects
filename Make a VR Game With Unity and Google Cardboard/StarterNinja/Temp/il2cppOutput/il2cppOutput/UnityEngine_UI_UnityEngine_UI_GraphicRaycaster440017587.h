#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.Canvas
struct Canvas_t814756449_0;
// System.Collections.Generic.List`1<UnityEngine.UI.Graphic>
struct List_1_t_1261145411_0;
// System.Comparison`1<UnityEngine.UI.Graphic>
struct Comparison_1_t477911672_0;

#include "UnityEngine_UI_UnityEngine_EventSystems_BaseRaycaste_1151946.h"
#include "UnityEngine_UI_UnityEngine_UI_GraphicRaycaster_Bl_1913877597.h"
#include "UnityEngine_UnityEngine_LayerMask_1132430796.h"

// UnityEngine.UI.GraphicRaycaster
struct  GraphicRaycaster_t440017587_0  : public BaseRaycaster_t_1151946_0
{
	// System.Boolean UnityEngine.UI.GraphicRaycaster::m_IgnoreReversedGraphics
	bool ___m_IgnoreReversedGraphics_3;
	// UnityEngine.UI.GraphicRaycaster/BlockingObjects UnityEngine.UI.GraphicRaycaster::m_BlockingObjects
	int32_t ___m_BlockingObjects_4;
	// UnityEngine.LayerMask UnityEngine.UI.GraphicRaycaster::m_BlockingMask
	LayerMask_t_1132430796_0  ___m_BlockingMask_5;
	// UnityEngine.Canvas UnityEngine.UI.GraphicRaycaster::m_Canvas
	Canvas_t814756449_0 * ___m_Canvas_6;
	// System.Collections.Generic.List`1<UnityEngine.UI.Graphic> UnityEngine.UI.GraphicRaycaster::m_RaycastResults
	List_1_t_1261145411_0 * ___m_RaycastResults_7;
};
struct GraphicRaycaster_t440017587_0_StaticFields{
	// System.Collections.Generic.List`1<UnityEngine.UI.Graphic> UnityEngine.UI.GraphicRaycaster::s_SortedGraphics
	List_1_t_1261145411_0 * ___s_SortedGraphics_8;
	// System.Comparison`1<UnityEngine.UI.Graphic> UnityEngine.UI.GraphicRaycaster::<>f__am$cache6
	Comparison_1_t477911672_0 * ___U3CU3Ef__amU24cache6_9;
};
