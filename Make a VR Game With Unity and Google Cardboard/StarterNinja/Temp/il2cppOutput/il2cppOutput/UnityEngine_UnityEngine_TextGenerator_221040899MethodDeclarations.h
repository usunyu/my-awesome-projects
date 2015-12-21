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

// UnityEngine.TextGenerator
struct TextGenerator_t_221040899_0;
// System.Collections.Generic.List`1<UnityEngine.UICharInfo>
struct List_1_t568339615_0;
// System.Collections.Generic.List`1<UnityEngine.UILineInfo>
struct List_1_t1504395969_0;
// System.Collections.Generic.List`1<UnityEngine.UIVertex>
struct List_1_t757324127_0;
// System.String
struct String_t;
// System.Collections.Generic.IList`1<UnityEngine.UIVertex>
struct IList_1_t716206734_0;
// System.Collections.Generic.IList`1<UnityEngine.UICharInfo>
struct IList_1_t_290769394_0;
// System.Collections.Generic.IList`1<UnityEngine.UILineInfo>
struct IList_1_t645286960_0;
// UnityEngine.Font
struct Font_t_982288488_0;
// System.Object
struct Object_t;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_TextGenerationSettings_570315663.h"
#include "UnityEngine_UnityEngine_Color_388944582.h"
#include "UnityEngine_UnityEngine_FontStyle_1018710791.h"
#include "UnityEngine_UnityEngine_VerticalWrapMode900334700.h"
#include "UnityEngine_UnityEngine_HorizontalWrapMode_991408934.h"
#include "UnityEngine_UnityEngine_TextAnchor649899723.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"
#include "UnityEngine_UnityEngine_Rect_981940947.h"

// System.Void UnityEngine.TextGenerator::.ctor()
extern "C"  void TextGenerator__ctor_m_300057485_0 (TextGenerator_t_221040899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.TextGenerator::.ctor(System.Int32)
extern "C"  void TextGenerator__ctor_m1563237700_0 (TextGenerator_t_221040899_0 * __this, int32_t ___initialCapacity, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.TextGenerator::System.IDisposable.Dispose()
extern "C"  void TextGenerator_System_IDisposable_Dispose_m_708531956_0 (TextGenerator_t_221040899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.TextGenerator::Finalize()
extern "C"  void TextGenerator_Finalize_m_1083086065_0 (TextGenerator_t_221040899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.TextGenerationSettings UnityEngine.TextGenerator::ValidatedSettings(UnityEngine.TextGenerationSettings)
extern "C"  TextGenerationSettings_t_570315663_0  TextGenerator_ValidatedSettings_m1098807955_0 (TextGenerator_t_221040899_0 * __this, TextGenerationSettings_t_570315663_0  ___settings, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.TextGenerator::Invalidate()
extern "C"  void TextGenerator_Invalidate_m620450028_0 (TextGenerator_t_221040899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.TextGenerator::GetCharacters(System.Collections.Generic.List`1<UnityEngine.UICharInfo>)
extern "C"  void TextGenerator_GetCharacters_m_1811907184_0 (TextGenerator_t_221040899_0 * __this, List_1_t568339615_0 * ___characters, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.TextGenerator::GetLines(System.Collections.Generic.List`1<UnityEngine.UILineInfo>)
extern "C"  void TextGenerator_GetLines_m_1853463995_0 (TextGenerator_t_221040899_0 * __this, List_1_t1504395969_0 * ___lines, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.TextGenerator::GetVertices(System.Collections.Generic.List`1<UnityEngine.UIVertex>)
extern "C"  void TextGenerator_GetVertices_m1097518625_0 (TextGenerator_t_221040899_0 * __this, List_1_t757324127_0 * ___vertices, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.TextGenerator::GetPreferredWidth(System.String,UnityEngine.TextGenerationSettings)
extern "C"  float TextGenerator_GetPreferredWidth_m1618543389_0 (TextGenerator_t_221040899_0 * __this, String_t* ___str, TextGenerationSettings_t_570315663_0  ___settings, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.TextGenerator::GetPreferredHeight(System.String,UnityEngine.TextGenerationSettings)
extern "C"  float TextGenerator_GetPreferredHeight_m1770778044_0 (TextGenerator_t_221040899_0 * __this, String_t* ___str, TextGenerationSettings_t_570315663_0  ___settings, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.TextGenerator::Populate(System.String,UnityEngine.TextGenerationSettings)
extern "C"  bool TextGenerator_Populate_m953583418_0 (TextGenerator_t_221040899_0 * __this, String_t* ___str, TextGenerationSettings_t_570315663_0  ___settings, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.TextGenerator::PopulateAlways(System.String,UnityEngine.TextGenerationSettings)
extern "C"  bool TextGenerator_PopulateAlways_m_156130135_0 (TextGenerator_t_221040899_0 * __this, String_t* ___str, TextGenerationSettings_t_570315663_0  ___settings, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.Generic.IList`1<UnityEngine.UIVertex> UnityEngine.TextGenerator::get_verts()
extern "C"  Object_t* TextGenerator_get_verts_m1179011229_0 (TextGenerator_t_221040899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.Generic.IList`1<UnityEngine.UICharInfo> UnityEngine.TextGenerator::get_characters()
extern "C"  Object_t* TextGenerator_get_characters_m_874296847_0 (TextGenerator_t_221040899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.Generic.IList`1<UnityEngine.UILineInfo> UnityEngine.TextGenerator::get_lines()
extern "C"  Object_t* TextGenerator_get_lines_m_1097425128_0 (TextGenerator_t_221040899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.TextGenerator::Init()
extern "C"  void TextGenerator_Init_m1881520001_0 (TextGenerator_t_221040899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.TextGenerator::Dispose_cpp()
extern "C"  void TextGenerator_Dispose_cpp_m959647828_0 (TextGenerator_t_221040899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.TextGenerator::Populate_Internal(System.String,UnityEngine.Font,UnityEngine.Color,System.Int32,System.Single,System.Single,UnityEngine.FontStyle,System.Boolean,System.Boolean,System.Int32,System.Int32,UnityEngine.VerticalWrapMode,UnityEngine.HorizontalWrapMode,System.Boolean,UnityEngine.TextAnchor,UnityEngine.Vector2,UnityEngine.Vector2,System.Boolean,System.Boolean)
extern "C"  bool TextGenerator_Populate_Internal_m1773862789_0 (TextGenerator_t_221040899_0 * __this, String_t* ___str, Font_t_982288488_0 * ___font, Color_t_388944582_0  ___color, int32_t ___fontSize, float ___scaleFactor, float ___lineSpacing, int32_t ___style, bool ___richText, bool ___resizeTextForBestFit, int32_t ___resizeTextMinSize, int32_t ___resizeTextMaxSize, int32_t ___verticalOverFlow, int32_t ___horizontalOverflow, bool ___updateBounds, int32_t ___anchor, Vector2_t_725341338_0  ___extents, Vector2_t_725341338_0  ___pivot, bool ___generateOutOfBounds, bool ___alignByGeometry, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.TextGenerator::Populate_Internal_cpp(System.String,UnityEngine.Font,UnityEngine.Color,System.Int32,System.Single,System.Single,UnityEngine.FontStyle,System.Boolean,System.Boolean,System.Int32,System.Int32,System.Int32,System.Int32,System.Boolean,UnityEngine.TextAnchor,System.Single,System.Single,System.Single,System.Single,System.Boolean,System.Boolean)
extern "C"  bool TextGenerator_Populate_Internal_cpp_m_1045161893_0 (TextGenerator_t_221040899_0 * __this, String_t* ___str, Font_t_982288488_0 * ___font, Color_t_388944582_0  ___color, int32_t ___fontSize, float ___scaleFactor, float ___lineSpacing, int32_t ___style, bool ___richText, bool ___resizeTextForBestFit, int32_t ___resizeTextMinSize, int32_t ___resizeTextMaxSize, int32_t ___verticalOverFlow, int32_t ___horizontalOverflow, bool ___updateBounds, int32_t ___anchor, float ___extentsX, float ___extentsY, float ___pivotX, float ___pivotY, bool ___generateOutOfBounds, bool ___alignByGeometry, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.TextGenerator::INTERNAL_CALL_Populate_Internal_cpp(UnityEngine.TextGenerator,System.String,UnityEngine.Font,UnityEngine.Color&,System.Int32,System.Single,System.Single,UnityEngine.FontStyle,System.Boolean,System.Boolean,System.Int32,System.Int32,System.Int32,System.Int32,System.Boolean,UnityEngine.TextAnchor,System.Single,System.Single,System.Single,System.Single,System.Boolean,System.Boolean)
extern "C"  bool TextGenerator_INTERNAL_CALL_Populate_Internal_cpp_m_1355594487_0 (Object_t * __this /* static, unused */, TextGenerator_t_221040899_0 * ___self, String_t* ___str, Font_t_982288488_0 * ___font, Color_t_388944582_0 * ___color, int32_t ___fontSize, float ___scaleFactor, float ___lineSpacing, int32_t ___style, bool ___richText, bool ___resizeTextForBestFit, int32_t ___resizeTextMinSize, int32_t ___resizeTextMaxSize, int32_t ___verticalOverFlow, int32_t ___horizontalOverflow, bool ___updateBounds, int32_t ___anchor, float ___extentsX, float ___extentsY, float ___pivotX, float ___pivotY, bool ___generateOutOfBounds, bool ___alignByGeometry, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Rect UnityEngine.TextGenerator::get_rectExtents()
extern "C"  Rect_t_981940947_0  TextGenerator_get_rectExtents_m_2094440767_0 (TextGenerator_t_221040899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.TextGenerator::INTERNAL_get_rectExtents(UnityEngine.Rect&)
extern "C"  void TextGenerator_INTERNAL_get_rectExtents_m_142964964_0 (TextGenerator_t_221040899_0 * __this, Rect_t_981940947_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.TextGenerator::get_vertexCount()
extern "C"  int32_t TextGenerator_get_vertexCount_m818659347_0 (TextGenerator_t_221040899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.TextGenerator::GetVerticesInternal(System.Object)
extern "C"  void TextGenerator_GetVerticesInternal_m2005679319_0 (TextGenerator_t_221040899_0 * __this, Object_t * ___vertices, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.TextGenerator::get_characterCountVisible()
extern "C"  int32_t TextGenerator_get_characterCountVisible_m_1673704588_0 (TextGenerator_t_221040899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.TextGenerator::GetCharactersInternal(System.Object)
extern "C"  void TextGenerator_GetCharactersInternal_m_1105337146_0 (TextGenerator_t_221040899_0 * __this, Object_t * ___characters, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.TextGenerator::get_lineCount()
extern "C"  int32_t TextGenerator_get_lineCount_m_1173922429_0 (TextGenerator_t_221040899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.TextGenerator::GetLinesInternal(System.Object)
extern "C"  void TextGenerator_GetLinesInternal_m702225117_0 (TextGenerator_t_221040899_0 * __this, Object_t * ___lines, const MethodInfo* method) IL2CPP_METHOD_ATTR;
