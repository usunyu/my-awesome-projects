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

// System.Text.RegularExpressions.Syntax.Group
struct Group_t932779431_0;
// System.Text.RegularExpressions.Syntax.Expression
struct Expression_t_524243856_0;
// System.Text.RegularExpressions.ICompiler
struct ICompiler_t_90276875_0;
// System.Text.RegularExpressions.Syntax.AnchorInfo
struct AnchorInfo_t_26193189_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Text.RegularExpressions.Syntax.Group::.ctor()
extern "C"  void Group__ctor_m358391753_0 (Group_t932779431_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.Group::AppendExpression(System.Text.RegularExpressions.Syntax.Expression)
extern "C"  void Group_AppendExpression_m_2118351689_0 (Group_t932779431_0 * __this, Expression_t_524243856_0 * ___e, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.Group::Compile(System.Text.RegularExpressions.ICompiler,System.Boolean)
extern "C"  void Group_Compile_m767805470_0 (Group_t932779431_0 * __this, Object_t * ___cmp, bool ___reverse, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.Group::GetWidth(System.Int32&,System.Int32&)
extern "C"  void Group_GetWidth_m_487016219_0 (Group_t932779431_0 * __this, int32_t* ___min, int32_t* ___max, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.RegularExpressions.Syntax.AnchorInfo System.Text.RegularExpressions.Syntax.Group::GetAnchorInfo(System.Boolean)
extern "C"  AnchorInfo_t_26193189_0 * Group_GetAnchorInfo_m1440957557_0 (Group_t932779431_0 * __this, bool ___reverse, const MethodInfo* method) IL2CPP_METHOD_ATTR;
