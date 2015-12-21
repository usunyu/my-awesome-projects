#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.UI.FontData
struct FontData_t345583998_0;
// System.String
struct String_t;
// UnityEngine.TextGenerator
struct TextGenerator_t_221040899_0;
// UnityEngine.Material
struct Material_t1701708784_0;
// UnityEngine.UIVertex[]
struct UIVertexU5BU5D_t2006642351_0;

#include "UnityEngine_UI_UnityEngine_UI_MaskableGraphic962735421.h"

// UnityEngine.UI.Text
struct  Text_t_204341102_0  : public MaskableGraphic_t962735421_0
{
	// UnityEngine.UI.FontData UnityEngine.UI.Text::m_FontData
	FontData_t345583998_0 * ___m_FontData_28;
	// System.String UnityEngine.UI.Text::m_Text
	String_t* ___m_Text_29;
	// UnityEngine.TextGenerator UnityEngine.UI.Text::m_TextCache
	TextGenerator_t_221040899_0 * ___m_TextCache_30;
	// UnityEngine.TextGenerator UnityEngine.UI.Text::m_TextCacheForLayout
	TextGenerator_t_221040899_0 * ___m_TextCacheForLayout_31;
	// System.Boolean UnityEngine.UI.Text::m_DisableFontTextureRebuiltCallback
	bool ___m_DisableFontTextureRebuiltCallback_33;
	// UnityEngine.UIVertex[] UnityEngine.UI.Text::m_TempVerts
	UIVertexU5BU5D_t2006642351_0* ___m_TempVerts_34;
};
struct Text_t_204341102_0_StaticFields{
	// UnityEngine.Material UnityEngine.UI.Text::s_DefaultText
	Material_t1701708784_0 * ___s_DefaultText_32;
};
