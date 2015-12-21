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

// System.Text.RegularExpressions.BaseMachine
struct BaseMachine_t598973635_0;
// System.String
struct String_t;
// System.Text.RegularExpressions.Regex
struct Regex_t943751828_0;
// System.Text.RegularExpressions.Match
struct Match_t939027474_0;
// System.Text.RegularExpressions.BaseMachine/MatchAppendEvaluator
struct MatchAppendEvaluator_t228680604_0;
// System.Text.RegularExpressions.MatchEvaluator
struct MatchEvaluator_t172888125_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Text.RegularExpressions.BaseMachine::.ctor()
extern "C"  void BaseMachine__ctor_m17432691_0 (BaseMachine_t598973635_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Text.RegularExpressions.BaseMachine::Replace(System.Text.RegularExpressions.Regex,System.String,System.String,System.Int32,System.Int32)
extern "C"  String_t* BaseMachine_Replace_m_958410496_0 (BaseMachine_t598973635_0 * __this, Regex_t943751828_0 * ___regex, String_t* ___input, String_t* ___replacement, int32_t ___count, int32_t ___startat, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.RegularExpressions.Match System.Text.RegularExpressions.BaseMachine::Scan(System.Text.RegularExpressions.Regex,System.String,System.Int32,System.Int32)
extern "C"  Match_t939027474_0 * BaseMachine_Scan_m223381495_0 (BaseMachine_t598973635_0 * __this, Regex_t943751828_0 * ___regex, String_t* ___text, int32_t ___start, int32_t ___end, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Text.RegularExpressions.BaseMachine::LTRReplace(System.Text.RegularExpressions.Regex,System.String,System.Text.RegularExpressions.BaseMachine/MatchAppendEvaluator,System.Int32,System.Int32,System.Boolean)
extern "C"  String_t* BaseMachine_LTRReplace_m_1061567577_0 (BaseMachine_t598973635_0 * __this, Regex_t943751828_0 * ___regex, String_t* ___input, MatchAppendEvaluator_t228680604_0 * ___evaluator, int32_t ___count, int32_t ___startat, bool ___needs_groups_or_captures, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Text.RegularExpressions.BaseMachine::RTLReplace(System.Text.RegularExpressions.Regex,System.String,System.Text.RegularExpressions.MatchEvaluator,System.Int32,System.Int32)
extern "C"  String_t* BaseMachine_RTLReplace_m1984309653_0 (BaseMachine_t598973635_0 * __this, Regex_t943751828_0 * ___regex, String_t* ___input, MatchEvaluator_t172888125_0 * ___evaluator, int32_t ___count, int32_t ___startat, const MethodInfo* method) IL2CPP_METHOD_ATTR;
