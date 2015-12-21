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

// System.Text.RegularExpressions.Syntax.CaptureAssertion
struct CaptureAssertion_t_422603212_0;
// System.Text.RegularExpressions.Syntax.Literal
struct Literal_t_1358096937_0;
// System.Text.RegularExpressions.Syntax.CapturingGroup
struct CapturingGroup_t_1855167596_0;
// System.Text.RegularExpressions.ICompiler
struct ICompiler_t_90276875_0;
// System.Text.RegularExpressions.Syntax.ExpressionAssertion
struct ExpressionAssertion_t_181630862_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Text.RegularExpressions.Syntax.CaptureAssertion::.ctor(System.Text.RegularExpressions.Syntax.Literal)
extern "C"  void CaptureAssertion__ctor_m_162181729_0 (CaptureAssertion_t_422603212_0 * __this, Literal_t_1358096937_0 * ___l, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.CaptureAssertion::set_CapturingGroup(System.Text.RegularExpressions.Syntax.CapturingGroup)
extern "C"  void CaptureAssertion_set_CapturingGroup_m1020834945_0 (CaptureAssertion_t_422603212_0 * __this, CapturingGroup_t_1855167596_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.CaptureAssertion::Compile(System.Text.RegularExpressions.ICompiler,System.Boolean)
extern "C"  void CaptureAssertion_Compile_m922447973_0 (CaptureAssertion_t_422603212_0 * __this, Object_t * ___cmp, bool ___reverse, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Syntax.CaptureAssertion::IsComplex()
extern "C"  bool CaptureAssertion_IsComplex_m987845008_0 (CaptureAssertion_t_422603212_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.RegularExpressions.Syntax.ExpressionAssertion System.Text.RegularExpressions.Syntax.CaptureAssertion::get_Alternate()
extern "C"  ExpressionAssertion_t_181630862_0 * CaptureAssertion_get_Alternate_m_46395318_0 (CaptureAssertion_t_422603212_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
