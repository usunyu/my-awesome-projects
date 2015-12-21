#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>
#include <assert.h>
#include <exception>

// UnityEngine.UI.Text
struct Text_t_204341102_0;
// UnityEngine.TextGenerator
struct TextGenerator_t_221040899_0;
// UnityEngine.Texture
struct Texture_t1814018354_0;
// UnityEngine.Font
struct Font_t_982288488_0;
// System.String
struct String_t;
// UnityEngine.UI.VertexHelper
struct VertexHelper_t786786519_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_TextAnchor649899723.h"
#include "UnityEngine_UnityEngine_HorizontalWrapMode_991408934.h"
#include "UnityEngine_UnityEngine_VerticalWrapMode900334700.h"
#include "UnityEngine_UnityEngine_FontStyle_1018710791.h"
#include "UnityEngine_UnityEngine_TextGenerationSettings_570315663.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"

// System.Void UnityEngine.UI.Text::.ctor()
extern "C"  void Text__ctor_m216739390_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Text::.cctor()
extern "C"  void Text__cctor_m1941857583_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.TextGenerator UnityEngine.UI.Text::get_cachedTextGenerator()
extern "C"  TextGenerator_t_221040899_0 * Text_get_cachedTextGenerator_m337653083_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.TextGenerator UnityEngine.UI.Text::get_cachedTextGeneratorForLayout()
extern "C"  TextGenerator_t_221040899_0 * Text_get_cachedTextGeneratorForLayout_m1260141146_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Texture UnityEngine.UI.Text::get_mainTexture()
extern "C"  Texture_t1814018354_0 * Text_get_mainTexture_m718426116_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Text::FontTextureChanged()
extern "C"  void Text_FontTextureChanged_m740758478_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Font UnityEngine.UI.Text::get_font()
extern "C"  Font_t_982288488_0 * Text_get_font_m_1857214131_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Text::set_font(UnityEngine.Font)
extern "C"  void Text_set_font_m1978976364_0 (Text_t_204341102_0 * __this, Font_t_982288488_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.UI.Text::get_text()
extern "C"  String_t* Text_get_text_m_461928999_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Text::set_text(System.String)
extern "C"  void Text_set_text_m302679026_0 (Text_t_204341102_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.Text::get_supportRichText()
extern "C"  bool Text_get_supportRichText_m226316153_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Text::set_supportRichText(System.Boolean)
extern "C"  void Text_set_supportRichText_m1299469806_0 (Text_t_204341102_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.Text::get_resizeTextForBestFit()
extern "C"  bool Text_get_resizeTextForBestFit_m_543335994_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Text::set_resizeTextForBestFit(System.Boolean)
extern "C"  void Text_set_resizeTextForBestFit_m241625791_0 (Text_t_204341102_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.UI.Text::get_resizeTextMinSize()
extern "C"  int32_t Text_get_resizeTextMinSize_m557265325_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Text::set_resizeTextMinSize(System.Int32)
extern "C"  void Text_set_resizeTextMinSize_m_788950110_0 (Text_t_204341102_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.UI.Text::get_resizeTextMaxSize()
extern "C"  int32_t Text_get_resizeTextMaxSize_m_215213249_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Text::set_resizeTextMaxSize(System.Int32)
extern "C"  void Text_set_resizeTextMaxSize_m_1668107724_0 (Text_t_204341102_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.TextAnchor UnityEngine.UI.Text::get_alignment()
extern "C"  int32_t Text_get_alignment_m_1670484428_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Text::set_alignment(UnityEngine.TextAnchor)
extern "C"  void Text_set_alignment_m_48243479_0 (Text_t_204341102_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.Text::get_alignByGeometry()
extern "C"  bool Text_get_alignByGeometry_m_890559569_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Text::set_alignByGeometry(System.Boolean)
extern "C"  void Text_set_alignByGeometry_m812094372_0 (Text_t_204341102_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.UI.Text::get_fontSize()
extern "C"  int32_t Text_get_fontSize_m_1432321609_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Text::set_fontSize(System.Int32)
extern "C"  void Text_set_fontSize_m2013207524_0 (Text_t_204341102_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.HorizontalWrapMode UnityEngine.UI.Text::get_horizontalOverflow()
extern "C"  int32_t Text_get_horizontalOverflow_m428751238_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Text::set_horizontalOverflow(UnityEngine.HorizontalWrapMode)
extern "C"  void Text_set_horizontalOverflow_m1764021409_0 (Text_t_204341102_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.VerticalWrapMode UnityEngine.UI.Text::get_verticalOverflow()
extern "C"  int32_t Text_get_verticalOverflow_m_80277078_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Text::set_verticalOverflow(UnityEngine.VerticalWrapMode)
extern "C"  void Text_set_verticalOverflow_m1954003489_0 (Text_t_204341102_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.Text::get_lineSpacing()
extern "C"  float Text_get_lineSpacing_m_1326562930_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Text::set_lineSpacing(System.Single)
extern "C"  void Text_set_lineSpacing_m3440093_0 (Text_t_204341102_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.FontStyle UnityEngine.UI.Text::get_fontStyle()
extern "C"  int32_t Text_get_fontStyle_m1258883933_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Text::set_fontStyle(UnityEngine.FontStyle)
extern "C"  void Text_set_fontStyle_m_1412724954_0 (Text_t_204341102_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.Text::get_pixelsPerUnit()
extern "C"  float Text_get_pixelsPerUnit_m_146210829_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Text::OnEnable()
extern "C"  void Text_OnEnable_m_676067192_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Text::OnDisable()
extern "C"  void Text_OnDisable_m957690789_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Text::UpdateGeometry()
extern "C"  void Text_UpdateGeometry_m1493208737_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.TextGenerationSettings UnityEngine.UI.Text::GetGenerationSettings(UnityEngine.Vector2)
extern "C"  TextGenerationSettings_t_570315663_0  Text_GetGenerationSettings_m554596117_0 (Text_t_204341102_0 * __this, Vector2_t_725341338_0  ___extents, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.UI.Text::GetTextAnchorPivot(UnityEngine.TextAnchor)
extern "C"  Vector2_t_725341338_0  Text_GetTextAnchorPivot_m7192668_0 (Object_t * __this /* static, unused */, int32_t ___anchor, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Text::OnPopulateMesh(UnityEngine.UI.VertexHelper)
extern "C"  void Text_OnPopulateMesh_m869628001_0 (Text_t_204341102_0 * __this, VertexHelper_t786786519_0 * ___toFill, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Text::CalculateLayoutInputHorizontal()
extern "C"  void Text_CalculateLayoutInputHorizontal_m_1744223548_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Text::CalculateLayoutInputVertical()
extern "C"  void Text_CalculateLayoutInputVertical_m_281105066_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.Text::get_minWidth()
extern "C"  float Text_get_minWidth_m1415472311_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.Text::get_preferredWidth()
extern "C"  float Text_get_preferredWidth_m_1622549976_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.Text::get_flexibleWidth()
extern "C"  float Text_get_flexibleWidth_m_972808678_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.Text::get_minHeight()
extern "C"  float Text_get_minHeight_m1433783032_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.Text::get_preferredHeight()
extern "C"  float Text_get_preferredHeight_m1744372647_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.UI.Text::get_flexibleHeight()
extern "C"  float Text_get_flexibleHeight_m411516405_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.UI.Text::get_layoutPriority()
extern "C"  int32_t Text_get_layoutPriority_m_252445771_0 (Text_t_204341102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
