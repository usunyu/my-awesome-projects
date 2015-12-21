#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Collections.Generic.Dictionary`2<System.Int32,UnityEngine.GUILayoutUtility/LayoutCache>
struct Dictionary_2_t1352990289_0;
// UnityEngine.GUILayoutUtility/LayoutCache
struct LayoutCache_t_428403207_0;
// UnityEngine.GUIStyle
struct GUIStyle_t822037503_0;

#include "mscorlib_System_Object_887538054.h"
#include "UnityEngine_UnityEngine_Rect_981940947.h"

// UnityEngine.GUILayoutUtility
struct  GUILayoutUtility_t_160158928_0  : public Object_t
{
};
struct GUILayoutUtility_t_160158928_0_StaticFields{
	// System.Collections.Generic.Dictionary`2<System.Int32,UnityEngine.GUILayoutUtility/LayoutCache> UnityEngine.GUILayoutUtility::s_StoredLayouts
	Dictionary_2_t1352990289_0 * ___s_StoredLayouts_0;
	// System.Collections.Generic.Dictionary`2<System.Int32,UnityEngine.GUILayoutUtility/LayoutCache> UnityEngine.GUILayoutUtility::s_StoredWindows
	Dictionary_2_t1352990289_0 * ___s_StoredWindows_1;
	// UnityEngine.GUILayoutUtility/LayoutCache UnityEngine.GUILayoutUtility::current
	LayoutCache_t_428403207_0 * ___current_2;
	// UnityEngine.Rect UnityEngine.GUILayoutUtility::kDummyRect
	Rect_t_981940947_0  ___kDummyRect_3;
	// UnityEngine.GUIStyle UnityEngine.GUILayoutUtility::s_SpaceStyle
	GUIStyle_t822037503_0 * ___s_SpaceStyle_4;
};
