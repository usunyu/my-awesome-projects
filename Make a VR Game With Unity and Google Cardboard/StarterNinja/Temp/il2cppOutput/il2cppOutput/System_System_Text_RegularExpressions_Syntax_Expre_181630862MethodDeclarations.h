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

// System.Text.RegularExpressions.Syntax.ExpressionAssertion
struct ExpressionAssertion_t_181630862_0;
// System.Text.RegularExpressions.Syntax.Expression
struct Expression_t_524243856_0;
// System.Text.RegularExpressions.ICompiler
struct ICompiler_t_90276875_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Text.RegularExpressions.Syntax.ExpressionAssertion::.ctor()
extern "C"  void ExpressionAssertion__ctor_m_1518025058_0 (ExpressionAssertion_t_181630862_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.ExpressionAssertion::set_Reverse(System.Boolean)
extern "C"  void ExpressionAssertion_set_Reverse_m_695707144_0 (ExpressionAssertion_t_181630862_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.ExpressionAssertion::set_Negate(System.Boolean)
extern "C"  void ExpressionAssertion_set_Negate_m1902108060_0 (ExpressionAssertion_t_181630862_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.RegularExpressions.Syntax.Expression System.Text.RegularExpressions.Syntax.ExpressionAssertion::get_TestExpression()
extern "C"  Expression_t_524243856_0 * ExpressionAssertion_get_TestExpression_m1374960432_0 (ExpressionAssertion_t_181630862_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.ExpressionAssertion::set_TestExpression(System.Text.RegularExpressions.Syntax.Expression)
extern "C"  void ExpressionAssertion_set_TestExpression_m828897591_0 (ExpressionAssertion_t_181630862_0 * __this, Expression_t_524243856_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.ExpressionAssertion::Compile(System.Text.RegularExpressions.ICompiler,System.Boolean)
extern "C"  void ExpressionAssertion_Compile_m_1387356439_0 (ExpressionAssertion_t_181630862_0 * __this, Object_t * ___cmp, bool ___reverse, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Syntax.ExpressionAssertion::IsComplex()
extern "C"  bool ExpressionAssertion_IsComplex_m_21069576_0 (ExpressionAssertion_t_181630862_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
