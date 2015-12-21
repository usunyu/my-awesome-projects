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

// System.Text.RegularExpressions.BaseMachine/MatchAppendEvaluator
struct MatchAppendEvaluator_t228680604_0;
// System.Object
struct Object_t;
// System.Text.RegularExpressions.Match
struct Match_t939027474_0;
// System.Text.StringBuilder
struct StringBuilder_t586045924_0;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"
#include "mscorlib_System_Text_StringBuilder586045924.h"

// System.Void System.Text.RegularExpressions.BaseMachine/MatchAppendEvaluator::.ctor(System.Object,System.IntPtr)
extern "C"  void MatchAppendEvaluator__ctor_m44201646_0 (MatchAppendEvaluator_t228680604_0 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.BaseMachine/MatchAppendEvaluator::Invoke(System.Text.RegularExpressions.Match,System.Text.StringBuilder)
extern "C"  void MatchAppendEvaluator_Invoke_m_1384157868_0 (MatchAppendEvaluator_t228680604_0 * __this, Match_t939027474_0 * ___match, StringBuilder_t586045924_0 * ___sb, const MethodInfo* method) IL2CPP_METHOD_ATTR;
extern "C" void pinvoke_delegate_wrapper_MatchAppendEvaluator_t228680604_0(Il2CppObject* delegate, Match_t939027474_0 * ___match, StringBuilder_t586045924_0 * ___sb);
// System.IAsyncResult System.Text.RegularExpressions.BaseMachine/MatchAppendEvaluator::BeginInvoke(System.Text.RegularExpressions.Match,System.Text.StringBuilder,System.AsyncCallback,System.Object)
extern "C"  Object_t * MatchAppendEvaluator_BeginInvoke_m1979969071_0 (MatchAppendEvaluator_t228680604_0 * __this, Match_t939027474_0 * ___match, StringBuilder_t586045924_0 * ___sb, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___object, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.BaseMachine/MatchAppendEvaluator::EndInvoke(System.IAsyncResult)
extern "C"  void MatchAppendEvaluator_EndInvoke_m_30904386_0 (MatchAppendEvaluator_t228680604_0 * __this, Object_t * ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
