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

// UnityEngine.GUIStyle
struct GUIStyle_t822037503_0;
// UnityEngine.GUIStyleState
struct GUIStyleState_t1237528530_0;
// UnityEngine.RectOffset
struct RectOffset_t_802832352_0;
// UnityEngine.Font
struct Font_t_982288488_0;
// UnityEngine.GUIContent
struct GUIContent_t_1764161721_0;
// System.String
struct String_t;
// UnityEngine.Texture
struct Texture_t1814018354_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"
#include "mscorlib_System_IntPtr_1047952454.h"
#include "UnityEngine_UnityEngine_Rect_981940947.h"
#include "UnityEngine_UnityEngine_ImagePosition1331188347.h"
#include "UnityEngine_UnityEngine_TextAnchor649899723.h"
#include "UnityEngine_UnityEngine_TextClipping_621790376.h"
#include "UnityEngine_UnityEngine_FontStyle_1018710791.h"
#include "UnityEngine_UnityEngine_Internal_DrawArguments_905945767.h"
#include "UnityEngine_UnityEngine_Color_388944582.h"
#include "UnityEngine_UnityEngine_Internal_DrawWithTextSelect912538618.h"

// System.Void UnityEngine.GUIStyle::.ctor()
extern "C"  void GUIStyle__ctor_m478034167_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::.ctor(UnityEngine.GUIStyle)
extern "C"  void GUIStyle__ctor_m584655914_0 (GUIStyle_t822037503_0 * __this, GUIStyle_t822037503_0 * ___other, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::.cctor()
extern "C"  void GUIStyle__cctor_m1452061078_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::Finalize()
extern "C"  void GUIStyle_Finalize_m_893177845_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::InternalOnAfterDeserialize()
extern "C"  void GUIStyle_InternalOnAfterDeserialize_m1012732492_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GUIStyleState UnityEngine.GUIStyle::get_normal()
extern "C"  GUIStyleState_t1237528530_0 * GUIStyle_get_normal_m42729964_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_normal(UnityEngine.GUIStyleState)
extern "C"  void GUIStyle_set_normal_m_704698883_0 (GUIStyle_t822037503_0 * __this, GUIStyleState_t1237528530_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GUIStyleState UnityEngine.GUIStyle::get_hover()
extern "C"  GUIStyleState_t1237528530_0 * GUIStyle_get_hover_m_609564423_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_hover(UnityEngine.GUIStyleState)
extern "C"  void GUIStyle_set_hover_m660294266_0 (GUIStyle_t822037503_0 * __this, GUIStyleState_t1237528530_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GUIStyleState UnityEngine.GUIStyle::get_active()
extern "C"  GUIStyleState_t1237528530_0 * GUIStyle_get_active_m1150072907_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_active(UnityEngine.GUIStyleState)
extern "C"  void GUIStyle_set_active_m79497342_0 (GUIStyle_t822037503_0 * __this, GUIStyleState_t1237528530_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GUIStyleState UnityEngine.GUIStyle::get_onNormal()
extern "C"  GUIStyleState_t1237528530_0 * GUIStyle_get_onNormal_m_622476309_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_onNormal(UnityEngine.GUIStyleState)
extern "C"  void GUIStyle_set_onNormal_m_434567650_0 (GUIStyle_t822037503_0 * __this, GUIStyleState_t1237528530_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GUIStyleState UnityEngine.GUIStyle::get_onHover()
extern "C"  GUIStyleState_t1237528530_0 * GUIStyle_get_onHover_m_769570022_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_onHover(UnityEngine.GUIStyleState)
extern "C"  void GUIStyle_set_onHover_m946102841_0 (GUIStyle_t822037503_0 * __this, GUIStyleState_t1237528530_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GUIStyleState UnityEngine.GUIStyle::get_onActive()
extern "C"  GUIStyleState_t1237528530_0 * GUIStyle_get_onActive_m484866634_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_onActive(UnityEngine.GUIStyleState)
extern "C"  void GUIStyle_set_onActive_m349628575_0 (GUIStyle_t822037503_0 * __this, GUIStyleState_t1237528530_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GUIStyleState UnityEngine.GUIStyle::get_focused()
extern "C"  GUIStyleState_t1237528530_0 * GUIStyle_get_focused_m_1577752204_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_focused(UnityEngine.GUIStyleState)
extern "C"  void GUIStyle_set_focused_m1026899231_0 (GUIStyle_t822037503_0 * __this, GUIStyleState_t1237528530_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GUIStyleState UnityEngine.GUIStyle::get_onFocused()
extern "C"  GUIStyleState_t1237528530_0 * GUIStyle_get_onFocused_m_724310187_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_onFocused(UnityEngine.GUIStyleState)
extern "C"  void GUIStyle_set_onFocused_m811032862_0 (GUIStyle_t822037503_0 * __this, GUIStyleState_t1237528530_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.RectOffset UnityEngine.GUIStyle::get_border()
extern "C"  RectOffset_t_802832352_0 * GUIStyle_get_border_m1826068707_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_border(UnityEngine.RectOffset)
extern "C"  void GUIStyle_set_border_m_1040610648_0 (GUIStyle_t822037503_0 * __this, RectOffset_t_802832352_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.RectOffset UnityEngine.GUIStyle::get_margin()
extern "C"  RectOffset_t_802832352_0 * GUIStyle_get_margin_m_15117851_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_margin(UnityEngine.RectOffset)
extern "C"  void GUIStyle_set_margin_m698201642_0 (GUIStyle_t822037503_0 * __this, RectOffset_t_802832352_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.RectOffset UnityEngine.GUIStyle::get_padding()
extern "C"  RectOffset_t_802832352_0 * GUIStyle_get_padding_m_1222026020_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_padding(UnityEngine.RectOffset)
extern "C"  void GUIStyle_set_padding_m458170651_0 (GUIStyle_t822037503_0 * __this, RectOffset_t_802832352_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.RectOffset UnityEngine.GUIStyle::get_overflow()
extern "C"  RectOffset_t_802832352_0 * GUIStyle_get_overflow_m_1432853063_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_overflow(UnityEngine.RectOffset)
extern "C"  void GUIStyle_set_overflow_m_1265640898_0 (GUIStyle_t822037503_0 * __this, RectOffset_t_802832352_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.GUIStyle::get_clipOffset()
extern "C"  Vector2_t_725341338_0  GUIStyle_get_clipOffset_m_1160279564_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_clipOffset(UnityEngine.Vector2)
extern "C"  void GUIStyle_set_clipOffset_m_1514329011_0 (GUIStyle_t822037503_0 * __this, Vector2_t_725341338_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Font UnityEngine.GUIStyle::get_font()
extern "C"  Font_t_982288488_0 * GUIStyle_get_font_m1061814606_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_font(UnityEngine.Font)
extern "C"  void GUIStyle_set_font_m_707434221_0 (GUIStyle_t822037503_0 * __this, Font_t_982288488_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.GUIStyle::get_lineHeight()
extern "C"  float GUIStyle_get_lineHeight_m_317711843_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::Internal_Draw(System.IntPtr,UnityEngine.Rect,UnityEngine.GUIContent,System.Boolean,System.Boolean,System.Boolean,System.Boolean)
extern "C"  void GUIStyle_Internal_Draw_m_623348033_0 (Object_t * __this /* static, unused */, IntPtr_t ___target, Rect_t_981940947_0  ___position, GUIContent_t_1764161721_0 * ___content, bool ___isHover, bool ___isActive, bool ___on, bool ___hasKeyboardFocus, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::Draw(UnityEngine.Rect,System.Boolean,System.Boolean,System.Boolean,System.Boolean)
extern "C"  void GUIStyle_Draw_m_1441408714_0 (GUIStyle_t822037503_0 * __this, Rect_t_981940947_0  ___position, bool ___isHover, bool ___isActive, bool ___on, bool ___hasKeyboardFocus, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::Draw(UnityEngine.Rect,System.String,System.Boolean,System.Boolean,System.Boolean,System.Boolean)
extern "C"  void GUIStyle_Draw_m645175538_0 (GUIStyle_t822037503_0 * __this, Rect_t_981940947_0  ___position, String_t* ___text, bool ___isHover, bool ___isActive, bool ___on, bool ___hasKeyboardFocus, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::Draw(UnityEngine.Rect,UnityEngine.Texture,System.Boolean,System.Boolean,System.Boolean,System.Boolean)
extern "C"  void GUIStyle_Draw_m1301423966_0 (GUIStyle_t822037503_0 * __this, Rect_t_981940947_0  ___position, Texture_t1814018354_0 * ___image, bool ___isHover, bool ___isActive, bool ___on, bool ___hasKeyboardFocus, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::Draw(UnityEngine.Rect,UnityEngine.GUIContent,System.Boolean,System.Boolean,System.Boolean,System.Boolean)
extern "C"  void GUIStyle_Draw_m860139579_0 (GUIStyle_t822037503_0 * __this, Rect_t_981940947_0  ___position, GUIContent_t_1764161721_0 * ___content, bool ___isHover, bool ___isActive, bool ___on, bool ___hasKeyboardFocus, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::Draw(UnityEngine.Rect,UnityEngine.GUIContent,System.Int32)
extern "C"  void GUIStyle_Draw_m_1300390212_0 (GUIStyle_t822037503_0 * __this, Rect_t_981940947_0  ___position, GUIContent_t_1764161721_0 * ___content, int32_t ___controlID, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::Draw(UnityEngine.Rect,UnityEngine.GUIContent,System.Int32,System.Boolean)
extern "C"  void GUIStyle_Draw_m489809217_0 (GUIStyle_t822037503_0 * __this, Rect_t_981940947_0  ___position, GUIContent_t_1764161721_0 * ___content, int32_t ___controlID, bool ___on, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::DrawCursor(UnityEngine.Rect,UnityEngine.GUIContent,System.Int32,System.Int32)
extern "C"  void GUIStyle_DrawCursor_m_125302683_0 (GUIStyle_t822037503_0 * __this, Rect_t_981940947_0  ___position, GUIContent_t_1764161721_0 * ___content, int32_t ___controlID, int32_t ___Character, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::DrawWithTextSelection(UnityEngine.Rect,UnityEngine.GUIContent,System.Int32,System.Int32,System.Int32,System.Boolean)
extern "C"  void GUIStyle_DrawWithTextSelection_m469195656_0 (GUIStyle_t822037503_0 * __this, Rect_t_981940947_0  ___position, GUIContent_t_1764161721_0 * ___content, int32_t ___controlID, int32_t ___firstSelectedCharacter, int32_t ___lastSelectedCharacter, bool ___drawSelectionAsComposition, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::DrawWithTextSelection(UnityEngine.Rect,UnityEngine.GUIContent,System.Int32,System.Int32,System.Int32)
extern "C"  void GUIStyle_DrawWithTextSelection_m984171349_0 (GUIStyle_t822037503_0 * __this, Rect_t_981940947_0  ___position, GUIContent_t_1764161721_0 * ___content, int32_t ___controlID, int32_t ___firstSelectedCharacter, int32_t ___lastSelectedCharacter, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GUIStyle UnityEngine.GUIStyle::get_none()
extern "C"  GUIStyle_t822037503_0 * GUIStyle_get_none_m_1527307664_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.GUIStyle::GetCursorPixelPosition(UnityEngine.Rect,UnityEngine.GUIContent,System.Int32)
extern "C"  Vector2_t_725341338_0  GUIStyle_GetCursorPixelPosition_m296157110_0 (GUIStyle_t822037503_0 * __this, Rect_t_981940947_0  ___position, GUIContent_t_1764161721_0 * ___content, int32_t ___cursorStringIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.GUIStyle::GetCursorStringIndex(UnityEngine.Rect,UnityEngine.GUIContent,UnityEngine.Vector2)
extern "C"  int32_t GUIStyle_GetCursorStringIndex_m_1071607554_0 (GUIStyle_t822037503_0 * __this, Rect_t_981940947_0  ___position, GUIContent_t_1764161721_0 * ___content, Vector2_t_725341338_0  ___cursorPixelPosition, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.GUIStyle::GetNumCharactersThatFitWithinWidth(System.String,System.Single)
extern "C"  int32_t GUIStyle_GetNumCharactersThatFitWithinWidth_m_1008936977_0 (GUIStyle_t822037503_0 * __this, String_t* ___text, float ___width, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.GUIStyle::CalcSize(UnityEngine.GUIContent)
extern "C"  Vector2_t_725341338_0  GUIStyle_CalcSize_m_1995158039_0 (GUIStyle_t822037503_0 * __this, GUIContent_t_1764161721_0 * ___content, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.GUIStyle::CalcSizeWithConstraints(UnityEngine.GUIContent,UnityEngine.Vector2)
extern "C"  Vector2_t_725341338_0  GUIStyle_CalcSizeWithConstraints_m_635549005_0 (GUIStyle_t822037503_0 * __this, GUIContent_t_1764161721_0 * ___content, Vector2_t_725341338_0  ___constraints, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.GUIStyle::CalcScreenSize(UnityEngine.Vector2)
extern "C"  Vector2_t_725341338_0  GUIStyle_CalcScreenSize_m1487928496_0 (GUIStyle_t822037503_0 * __this, Vector2_t_725341338_0  ___contentSize, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.GUIStyle::CalcHeight(UnityEngine.GUIContent,System.Single)
extern "C"  float GUIStyle_CalcHeight_m_729543003_0 (GUIStyle_t822037503_0 * __this, GUIContent_t_1764161721_0 * ___content, float ___width, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.GUIStyle::get_isHeightDependantOnWidth()
extern "C"  bool GUIStyle_get_isHeightDependantOnWidth_m1959928889_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::CalcMinMaxWidth(UnityEngine.GUIContent,System.Single&,System.Single&)
extern "C"  void GUIStyle_CalcMinMaxWidth_m421008639_0 (GUIStyle_t822037503_0 * __this, GUIContent_t_1764161721_0 * ___content, float* ___minWidth, float* ___maxWidth, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.GUIStyle::ToString()
extern "C"  String_t* GUIStyle_ToString_m_1803188420_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::Init()
extern "C"  void GUIStyle_Init_m_1002874243_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::InitCopy(UnityEngine.GUIStyle)
extern "C"  void GUIStyle_InitCopy_m_1231536507_0 (GUIStyle_t822037503_0 * __this, GUIStyle_t822037503_0 * ___other, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::Cleanup()
extern "C"  void GUIStyle_Cleanup_m_1796872519_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.GUIStyle::get_name()
extern "C"  String_t* GUIStyle_get_name_m_248780668_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_name(System.String)
extern "C"  void GUIStyle_set_name_m_169042035_0 (GUIStyle_t822037503_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.IntPtr UnityEngine.GUIStyle::GetStyleStatePtr(System.Int32)
extern "C"  IntPtr_t GUIStyle_GetStyleStatePtr_m_1744094677_0 (GUIStyle_t822037503_0 * __this, int32_t ___idx, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::AssignStyleState(System.Int32,System.IntPtr)
extern "C"  void GUIStyle_AssignStyleState_m_264771205_0 (GUIStyle_t822037503_0 * __this, int32_t ___idx, IntPtr_t ___srcStyleState, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.IntPtr UnityEngine.GUIStyle::GetRectOffsetPtr(System.Int32)
extern "C"  IntPtr_t GUIStyle_GetRectOffsetPtr_m1931607252_0 (GUIStyle_t822037503_0 * __this, int32_t ___idx, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::AssignRectOffset(System.Int32,System.IntPtr)
extern "C"  void GUIStyle_AssignRectOffset_m519705394_0 (GUIStyle_t822037503_0 * __this, int32_t ___idx, IntPtr_t ___srcRectOffset, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.ImagePosition UnityEngine.GUIStyle::get_imagePosition()
extern "C"  int32_t GUIStyle_get_imagePosition_m_418814774_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_imagePosition(UnityEngine.ImagePosition)
extern "C"  void GUIStyle_set_imagePosition_m1689669769_0 (GUIStyle_t822037503_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.TextAnchor UnityEngine.GUIStyle::get_alignment()
extern "C"  int32_t GUIStyle_get_alignment_m1533628953_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_alignment(UnityEngine.TextAnchor)
extern "C"  void GUIStyle_set_alignment_m_42066462_0 (GUIStyle_t822037503_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.GUIStyle::get_wordWrap()
extern "C"  bool GUIStyle_get_wordWrap_m_464184528_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_wordWrap(System.Boolean)
extern "C"  void GUIStyle_set_wordWrap_m_494394443_0 (GUIStyle_t822037503_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.TextClipping UnityEngine.GUIStyle::get_clipping()
extern "C"  int32_t GUIStyle_get_clipping_m2044798529_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_clipping(UnityEngine.TextClipping)
extern "C"  void GUIStyle_set_clipping_m771351942_0 (GUIStyle_t822037503_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.GUIStyle::get_contentOffset()
extern "C"  Vector2_t_725341338_0  GUIStyle_get_contentOffset_m2092220605_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_contentOffset(UnityEngine.Vector2)
extern "C"  void GUIStyle_set_contentOffset_m_909103242_0 (GUIStyle_t822037503_0 * __this, Vector2_t_725341338_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::INTERNAL_get_contentOffset(UnityEngine.Vector2&)
extern "C"  void GUIStyle_INTERNAL_get_contentOffset_m2078390432_0 (GUIStyle_t822037503_0 * __this, Vector2_t_725341338_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::INTERNAL_set_contentOffset(UnityEngine.Vector2&)
extern "C"  void GUIStyle_INTERNAL_set_contentOffset_m_403877972_0 (GUIStyle_t822037503_0 * __this, Vector2_t_725341338_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.GUIStyle::get_Internal_clipOffset()
extern "C"  Vector2_t_725341338_0  GUIStyle_get_Internal_clipOffset_m_171803978_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_Internal_clipOffset(UnityEngine.Vector2)
extern "C"  void GUIStyle_set_Internal_clipOffset_m411599389_0 (GUIStyle_t822037503_0 * __this, Vector2_t_725341338_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::INTERNAL_get_Internal_clipOffset(UnityEngine.Vector2&)
extern "C"  void GUIStyle_INTERNAL_get_Internal_clipOffset_m_877597863_0 (GUIStyle_t822037503_0 * __this, Vector2_t_725341338_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::INTERNAL_set_Internal_clipOffset(UnityEngine.Vector2&)
extern "C"  void GUIStyle_INTERNAL_set_Internal_clipOffset_m188352869_0 (GUIStyle_t822037503_0 * __this, Vector2_t_725341338_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.GUIStyle::get_fixedWidth()
extern "C"  float GUIStyle_get_fixedWidth_m_1045868332_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_fixedWidth(System.Single)
extern "C"  void GUIStyle_set_fixedWidth_m_1808732689_0 (GUIStyle_t822037503_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.GUIStyle::get_fixedHeight()
extern "C"  float GUIStyle_get_fixedHeight_m_1853332869_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_fixedHeight(System.Single)
extern "C"  void GUIStyle_set_fixedHeight_m_2085089928_0 (GUIStyle_t822037503_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.GUIStyle::get_stretchWidth()
extern "C"  bool GUIStyle_get_stretchWidth_m38609341_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_stretchWidth(System.Boolean)
extern "C"  void GUIStyle_set_stretchWidth_m829487234_0 (GUIStyle_t822037503_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.GUIStyle::get_stretchHeight()
extern "C"  bool GUIStyle_get_stretchHeight_m1700703922_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_stretchHeight(System.Boolean)
extern "C"  void GUIStyle_set_stretchHeight_m703419995_0 (GUIStyle_t822037503_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.GUIStyle::Internal_GetLineHeight(System.IntPtr)
extern "C"  float GUIStyle_Internal_GetLineHeight_m_70161268_0 (Object_t * __this /* static, unused */, IntPtr_t ___target, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::SetFontInternal(UnityEngine.Font)
extern "C"  void GUIStyle_SetFontInternal_m_1435708931_0 (GUIStyle_t822037503_0 * __this, Font_t_982288488_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Font UnityEngine.GUIStyle::GetFontInternalDuringLoadingThread()
extern "C"  Font_t_982288488_0 * GUIStyle_GetFontInternalDuringLoadingThread_m1458608761_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Font UnityEngine.GUIStyle::GetFontInternal()
extern "C"  Font_t_982288488_0 * GUIStyle_GetFontInternal_m_1366162770_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.GUIStyle::get_fontSize()
extern "C"  int32_t GUIStyle_get_fontSize_m_1356690618_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_fontSize(System.Int32)
extern "C"  void GUIStyle_set_fontSize_m_673203061_0 (GUIStyle_t822037503_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.FontStyle UnityEngine.GUIStyle::get_fontStyle()
extern "C"  int32_t GUIStyle_get_fontStyle_m_980948282_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_fontStyle(UnityEngine.FontStyle)
extern "C"  void GUIStyle_set_fontStyle_m_996883699_0 (GUIStyle_t822037503_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.GUIStyle::get_richText()
extern "C"  bool GUIStyle_get_richText_m1558667173_0 (GUIStyle_t822037503_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::set_richText(System.Boolean)
extern "C"  void GUIStyle_set_richText_m1293612906_0 (GUIStyle_t822037503_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::Internal_Draw(UnityEngine.GUIContent,UnityEngine.Internal_DrawArguments&)
extern "C"  void GUIStyle_Internal_Draw_m_929188109_0 (Object_t * __this /* static, unused */, GUIContent_t_1764161721_0 * ___content, Internal_DrawArguments_t_905945767_0 * ___arguments, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::Internal_Draw2(System.IntPtr,UnityEngine.Rect,UnityEngine.GUIContent,System.Int32,System.Boolean)
extern "C"  void GUIStyle_Internal_Draw2_m_1588592889_0 (Object_t * __this /* static, unused */, IntPtr_t ___style, Rect_t_981940947_0  ___position, GUIContent_t_1764161721_0 * ___content, int32_t ___controlID, bool ___on, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::INTERNAL_CALL_Internal_Draw2(System.IntPtr,UnityEngine.Rect&,UnityEngine.GUIContent,System.Int32,System.Boolean)
extern "C"  void GUIStyle_INTERNAL_CALL_Internal_Draw2_m1512749466_0 (Object_t * __this /* static, unused */, IntPtr_t ___style, Rect_t_981940947_0 * ___position, GUIContent_t_1764161721_0 * ___content, int32_t ___controlID, bool ___on, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::Internal_DrawPrefixLabel(System.IntPtr,UnityEngine.Rect,UnityEngine.GUIContent,System.Int32,System.Boolean)
extern "C"  void GUIStyle_Internal_DrawPrefixLabel_m1343381847_0 (Object_t * __this /* static, unused */, IntPtr_t ___style, Rect_t_981940947_0  ___position, GUIContent_t_1764161721_0 * ___content, int32_t ___controlID, bool ___on, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::INTERNAL_CALL_Internal_DrawPrefixLabel(System.IntPtr,UnityEngine.Rect&,UnityEngine.GUIContent,System.Int32,System.Boolean)
extern "C"  void GUIStyle_INTERNAL_CALL_Internal_DrawPrefixLabel_m_640045430_0 (Object_t * __this /* static, unused */, IntPtr_t ___style, Rect_t_981940947_0 * ___position, GUIContent_t_1764161721_0 * ___content, int32_t ___controlID, bool ___on, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.GUIStyle::Internal_GetCursorFlashOffset()
extern "C"  float GUIStyle_Internal_GetCursorFlashOffset_m_1188525214_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::Internal_DrawCursor(System.IntPtr,UnityEngine.Rect,UnityEngine.GUIContent,System.Int32,UnityEngine.Color)
extern "C"  void GUIStyle_Internal_DrawCursor_m496261262_0 (Object_t * __this /* static, unused */, IntPtr_t ___target, Rect_t_981940947_0  ___position, GUIContent_t_1764161721_0 * ___content, int32_t ___pos, Color_t_388944582_0  ___cursorColor, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::INTERNAL_CALL_Internal_DrawCursor(System.IntPtr,UnityEngine.Rect&,UnityEngine.GUIContent,System.Int32,UnityEngine.Color&)
extern "C"  void GUIStyle_INTERNAL_CALL_Internal_DrawCursor_m330118499_0 (Object_t * __this /* static, unused */, IntPtr_t ___target, Rect_t_981940947_0 * ___position, GUIContent_t_1764161721_0 * ___content, int32_t ___pos, Color_t_388944582_0 * ___cursorColor, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::Internal_DrawWithTextSelection(UnityEngine.GUIContent,UnityEngine.Internal_DrawWithTextSelectionArguments&)
extern "C"  void GUIStyle_Internal_DrawWithTextSelection_m538670273_0 (Object_t * __this /* static, unused */, GUIContent_t_1764161721_0 * ___content, Internal_DrawWithTextSelectionArguments_t912538618_0 * ___arguments, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::SetDefaultFont(UnityEngine.Font)
extern "C"  void GUIStyle_SetDefaultFont_m1041826325_0 (Object_t * __this /* static, unused */, Font_t_982288488_0 * ___font, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::Internal_GetCursorPixelPosition(System.IntPtr,UnityEngine.Rect,UnityEngine.GUIContent,System.Int32,UnityEngine.Vector2&)
extern "C"  void GUIStyle_Internal_GetCursorPixelPosition_m336331745_0 (Object_t * __this /* static, unused */, IntPtr_t ___target, Rect_t_981940947_0  ___position, GUIContent_t_1764161721_0 * ___content, int32_t ___cursorStringIndex, Vector2_t_725341338_0 * ___ret, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::INTERNAL_CALL_Internal_GetCursorPixelPosition(System.IntPtr,UnityEngine.Rect&,UnityEngine.GUIContent,System.Int32,UnityEngine.Vector2&)
extern "C"  void GUIStyle_INTERNAL_CALL_Internal_GetCursorPixelPosition_m_1692399496_0 (Object_t * __this /* static, unused */, IntPtr_t ___target, Rect_t_981940947_0 * ___position, GUIContent_t_1764161721_0 * ___content, int32_t ___cursorStringIndex, Vector2_t_725341338_0 * ___ret, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.GUIStyle::Internal_GetCursorStringIndex(System.IntPtr,UnityEngine.Rect,UnityEngine.GUIContent,UnityEngine.Vector2)
extern "C"  int32_t GUIStyle_Internal_GetCursorStringIndex_m1275963970_0 (Object_t * __this /* static, unused */, IntPtr_t ___target, Rect_t_981940947_0  ___position, GUIContent_t_1764161721_0 * ___content, Vector2_t_725341338_0  ___cursorPixelPosition, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.GUIStyle::INTERNAL_CALL_Internal_GetCursorStringIndex(System.IntPtr,UnityEngine.Rect&,UnityEngine.GUIContent,UnityEngine.Vector2&)
extern "C"  int32_t GUIStyle_INTERNAL_CALL_Internal_GetCursorStringIndex_m_837787409_0 (Object_t * __this /* static, unused */, IntPtr_t ___target, Rect_t_981940947_0 * ___position, GUIContent_t_1764161721_0 * ___content, Vector2_t_725341338_0 * ___cursorPixelPosition, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.GUIStyle::Internal_GetNumCharactersThatFitWithinWidth(System.IntPtr,System.String,System.Single)
extern "C"  int32_t GUIStyle_Internal_GetNumCharactersThatFitWithinWidth_m470425907_0 (Object_t * __this /* static, unused */, IntPtr_t ___target, String_t* ___text, float ___width, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::Internal_CalcSize(System.IntPtr,UnityEngine.GUIContent,UnityEngine.Vector2&)
extern "C"  void GUIStyle_Internal_CalcSize_m1389308622_0 (Object_t * __this /* static, unused */, IntPtr_t ___target, GUIContent_t_1764161721_0 * ___content, Vector2_t_725341338_0 * ___ret, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::Internal_CalcSizeWithConstraints(System.IntPtr,UnityEngine.GUIContent,UnityEngine.Vector2,UnityEngine.Vector2&)
extern "C"  void GUIStyle_Internal_CalcSizeWithConstraints_m484790978_0 (Object_t * __this /* static, unused */, IntPtr_t ___target, GUIContent_t_1764161721_0 * ___content, Vector2_t_725341338_0  ___maxSize, Vector2_t_725341338_0 * ___ret, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::INTERNAL_CALL_Internal_CalcSizeWithConstraints(System.IntPtr,UnityEngine.GUIContent,UnityEngine.Vector2&,UnityEngine.Vector2&)
extern "C"  void GUIStyle_INTERNAL_CALL_Internal_CalcSizeWithConstraints_m2048982689_0 (Object_t * __this /* static, unused */, IntPtr_t ___target, GUIContent_t_1764161721_0 * ___content, Vector2_t_725341338_0 * ___maxSize, Vector2_t_725341338_0 * ___ret, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.GUIStyle::Internal_CalcHeight(System.IntPtr,UnityEngine.GUIContent,System.Single)
extern "C"  float GUIStyle_Internal_CalcHeight_m_846664311_0 (Object_t * __this /* static, unused */, IntPtr_t ___target, GUIContent_t_1764161721_0 * ___content, float ___width, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.GUIStyle::Internal_CalcMinMaxWidth(System.IntPtr,UnityEngine.GUIContent,System.Single&,System.Single&)
extern "C"  void GUIStyle_Internal_CalcMinMaxWidth_m1670371175_0 (Object_t * __this /* static, unused */, IntPtr_t ___target, GUIContent_t_1764161721_0 * ___content, float* ___minWidth, float* ___maxWidth, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GUIStyle UnityEngine.GUIStyle::op_Implicit(System.String)
extern "C"  GUIStyle_t822037503_0 * GUIStyle_op_Implicit_m169215436_0 (Object_t * __this /* static, unused */, String_t* ___str, const MethodInfo* method) IL2CPP_METHOD_ATTR;
