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

// System.Text.RegularExpressions.Interpreter/RepeatContext
struct RepeatContext_t_1915870612_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Text.RegularExpressions.Interpreter/RepeatContext::.ctor(System.Text.RegularExpressions.Interpreter/RepeatContext,System.Int32,System.Int32,System.Boolean,System.Int32)
extern "C"  void RepeatContext__ctor_m788719250_0 (RepeatContext_t_1915870612_0 * __this, RepeatContext_t_1915870612_0 * ___previous, int32_t ___min, int32_t ___max, bool ___lazy, int32_t ___expr_pc, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.RegularExpressions.Interpreter/RepeatContext::get_Count()
extern "C"  int32_t RepeatContext_get_Count_m_197712770_0 (RepeatContext_t_1915870612_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Interpreter/RepeatContext::set_Count(System.Int32)
extern "C"  void RepeatContext_set_Count_m_145576437_0 (RepeatContext_t_1915870612_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.RegularExpressions.Interpreter/RepeatContext::get_Start()
extern "C"  int32_t RepeatContext_get_Start_m1242238737_0 (RepeatContext_t_1915870612_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Interpreter/RepeatContext::set_Start(System.Int32)
extern "C"  void RepeatContext_set_Start_m_506178530_0 (RepeatContext_t_1915870612_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Interpreter/RepeatContext::get_IsMinimum()
extern "C"  bool RepeatContext_get_IsMinimum_m1600048397_0 (RepeatContext_t_1915870612_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Interpreter/RepeatContext::get_IsMaximum()
extern "C"  bool RepeatContext_get_IsMaximum_m827569823_0 (RepeatContext_t_1915870612_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Interpreter/RepeatContext::get_IsLazy()
extern "C"  bool RepeatContext_get_IsLazy_m_1379833673_0 (RepeatContext_t_1915870612_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.RegularExpressions.Interpreter/RepeatContext::get_Expression()
extern "C"  int32_t RepeatContext_get_Expression_m540420139_0 (RepeatContext_t_1915870612_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.RegularExpressions.Interpreter/RepeatContext System.Text.RegularExpressions.Interpreter/RepeatContext::get_Previous()
extern "C"  RepeatContext_t_1915870612_0 * RepeatContext_get_Previous_m_153352825_0 (RepeatContext_t_1915870612_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
