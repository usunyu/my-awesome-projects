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

// System.Text.RegularExpressions.Syntax.Alternation
struct Alternation_t555960325_0;
// System.Text.RegularExpressions.Syntax.ExpressionCollection
struct ExpressionCollection_t_873501906_0;
// System.Text.RegularExpressions.Syntax.Expression
struct Expression_t_524243856_0;
// System.Text.RegularExpressions.ICompiler
struct ICompiler_t_90276875_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Text.RegularExpressions.Syntax.Alternation::.ctor()
extern "C"  void Alternation__ctor_m1090419051_0 (Alternation_t555960325_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.RegularExpressions.Syntax.ExpressionCollection System.Text.RegularExpressions.Syntax.Alternation::get_Alternatives()
extern "C"  ExpressionCollection_t_873501906_0 * Alternation_get_Alternatives_m1740410205_0 (Alternation_t555960325_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.Alternation::AddAlternative(System.Text.RegularExpressions.Syntax.Expression)
extern "C"  void Alternation_AddAlternative_m_598999985_0 (Alternation_t555960325_0 * __this, Expression_t_524243856_0 * ___e, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.Alternation::Compile(System.Text.RegularExpressions.ICompiler,System.Boolean)
extern "C"  void Alternation_Compile_m333754556_0 (Alternation_t555960325_0 * __this, Object_t * ___cmp, bool ___reverse, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.Alternation::GetWidth(System.Int32&,System.Int32&)
extern "C"  void Alternation_GetWidth_m1273465607_0 (Alternation_t555960325_0 * __this, int32_t* ___min, int32_t* ___max, const MethodInfo* method) IL2CPP_METHOD_ATTR;
