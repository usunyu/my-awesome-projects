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

// System.Text.RegularExpressions.Syntax.PositionAssertion
struct PositionAssertion_t567377665_0;
// System.Text.RegularExpressions.ICompiler
struct ICompiler_t_90276875_0;
// System.Text.RegularExpressions.Syntax.AnchorInfo
struct AnchorInfo_t_26193189_0;

#include "codegen/il2cpp-codegen.h"
#include "System_System_Text_RegularExpressions_Position1896466364.h"

// System.Void System.Text.RegularExpressions.Syntax.PositionAssertion::.ctor(System.Text.RegularExpressions.Position)
extern "C"  void PositionAssertion__ctor_m_1582458131_0 (PositionAssertion_t567377665_0 * __this, uint16_t ___pos, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.PositionAssertion::Compile(System.Text.RegularExpressions.ICompiler,System.Boolean)
extern "C"  void PositionAssertion_Compile_m_1803047304_0 (PositionAssertion_t567377665_0 * __this, Object_t * ___cmp, bool ___reverse, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.PositionAssertion::GetWidth(System.Int32&,System.Int32&)
extern "C"  void PositionAssertion_GetWidth_m_182857013_0 (PositionAssertion_t567377665_0 * __this, int32_t* ___min, int32_t* ___max, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Syntax.PositionAssertion::IsComplex()
extern "C"  bool PositionAssertion_IsComplex_m2141947785_0 (PositionAssertion_t567377665_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.RegularExpressions.Syntax.AnchorInfo System.Text.RegularExpressions.Syntax.PositionAssertion::GetAnchorInfo(System.Boolean)
extern "C"  AnchorInfo_t_26193189_0 * PositionAssertion_GetAnchorInfo_m_383613093_0 (PositionAssertion_t567377665_0 * __this, bool ___revers, const MethodInfo* method) IL2CPP_METHOD_ATTR;
