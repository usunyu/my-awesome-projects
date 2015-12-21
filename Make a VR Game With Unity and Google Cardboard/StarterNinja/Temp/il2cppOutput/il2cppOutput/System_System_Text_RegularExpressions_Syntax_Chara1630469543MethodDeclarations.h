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

// System.Text.RegularExpressions.Syntax.CharacterClass
struct CharacterClass_t1630469543_0;
// System.Text.RegularExpressions.ICompiler
struct ICompiler_t_90276875_0;

#include "codegen/il2cpp-codegen.h"
#include "System_System_Text_RegularExpressions_Category1199172497.h"
#include "System_System_Text_RegularExpressions_Interval1719079768.h"

// System.Void System.Text.RegularExpressions.Syntax.CharacterClass::.ctor(System.Boolean,System.Boolean)
extern "C"  void CharacterClass__ctor_m318669623_0 (CharacterClass_t1630469543_0 * __this, bool ___negate, bool ___ignore, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.CharacterClass::.ctor(System.Text.RegularExpressions.Category,System.Boolean)
extern "C"  void CharacterClass__ctor_m_621967643_0 (CharacterClass_t1630469543_0 * __this, uint16_t ___cat, bool ___negate, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.CharacterClass::.cctor()
extern "C"  void CharacterClass__cctor_m2076983614_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.CharacterClass::AddCategory(System.Text.RegularExpressions.Category,System.Boolean)
extern "C"  void CharacterClass_AddCategory_m385157186_0 (CharacterClass_t1630469543_0 * __this, uint16_t ___cat, bool ___negate, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.CharacterClass::AddCharacter(System.Char)
extern "C"  void CharacterClass_AddCharacter_m509912608_0 (CharacterClass_t1630469543_0 * __this, uint16_t ___c, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.CharacterClass::AddRange(System.Char,System.Char)
extern "C"  void CharacterClass_AddRange_m_110279773_0 (CharacterClass_t1630469543_0 * __this, uint16_t ___lo, uint16_t ___hi, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.CharacterClass::Compile(System.Text.RegularExpressions.ICompiler,System.Boolean)
extern "C"  void CharacterClass_Compile_m_1113919912_0 (CharacterClass_t1630469543_0 * __this, Object_t * ___cmp, bool ___reverse, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.CharacterClass::GetWidth(System.Int32&,System.Int32&)
extern "C"  void CharacterClass_GetWidth_m2016149227_0 (CharacterClass_t1630469543_0 * __this, int32_t* ___min, int32_t* ___max, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Syntax.CharacterClass::IsComplex()
extern "C"  bool CharacterClass_IsComplex_m_1052280771_0 (CharacterClass_t1630469543_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Double System.Text.RegularExpressions.Syntax.CharacterClass::GetIntervalCost(System.Text.RegularExpressions.Interval)
extern "C"  double CharacterClass_GetIntervalCost_m_724422514_0 (Object_t * __this /* static, unused */, Interval_t1719079768_0  ___i, const MethodInfo* method) IL2CPP_METHOD_ATTR;
