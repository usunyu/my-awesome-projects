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

// System.Text.RegularExpressions.ReplacementEvaluator
struct ReplacementEvaluator_t1435785296_0;
// System.Text.RegularExpressions.Regex
struct Regex_t943751828_0;
// System.String
struct String_t;
// System.Text.RegularExpressions.Match
struct Match_t939027474_0;
// System.Text.StringBuilder
struct StringBuilder_t586045924_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Text.RegularExpressions.ReplacementEvaluator::.ctor(System.Text.RegularExpressions.Regex,System.String)
extern "C"  void ReplacementEvaluator__ctor_m_1520116638_0 (ReplacementEvaluator_t1435785296_0 * __this, Regex_t943751828_0 * ___regex, String_t* ___replacement, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Text.RegularExpressions.ReplacementEvaluator::Evaluate(System.Text.RegularExpressions.Match)
extern "C"  String_t* ReplacementEvaluator_Evaluate_m_89642302_0 (ReplacementEvaluator_t1435785296_0 * __this, Match_t939027474_0 * ___match, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.ReplacementEvaluator::EvaluateAppend(System.Text.RegularExpressions.Match,System.Text.StringBuilder)
extern "C"  void ReplacementEvaluator_EvaluateAppend_m_28560349_0 (ReplacementEvaluator_t1435785296_0 * __this, Match_t939027474_0 * ___match, StringBuilder_t586045924_0 * ___sb, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.ReplacementEvaluator::get_NeedsGroupsOrCaptures()
extern "C"  bool ReplacementEvaluator_get_NeedsGroupsOrCaptures_m1475641324_0 (ReplacementEvaluator_t1435785296_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.ReplacementEvaluator::Ensure(System.Int32)
extern "C"  void ReplacementEvaluator_Ensure_m619661651_0 (ReplacementEvaluator_t1435785296_0 * __this, int32_t ___size, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.ReplacementEvaluator::AddFromReplacement(System.Int32,System.Int32)
extern "C"  void ReplacementEvaluator_AddFromReplacement_m_150910885_0 (ReplacementEvaluator_t1435785296_0 * __this, int32_t ___start, int32_t ___end, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.ReplacementEvaluator::AddInt(System.Int32)
extern "C"  void ReplacementEvaluator_AddInt_m_644515677_0 (ReplacementEvaluator_t1435785296_0 * __this, int32_t ___i, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.ReplacementEvaluator::Compile()
extern "C"  void ReplacementEvaluator_Compile_m763546001_0 (ReplacementEvaluator_t1435785296_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.RegularExpressions.ReplacementEvaluator::CompileTerm(System.Int32&)
extern "C"  int32_t ReplacementEvaluator_CompileTerm_m_1355798930_0 (ReplacementEvaluator_t1435785296_0 * __this, int32_t* ___ptr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
