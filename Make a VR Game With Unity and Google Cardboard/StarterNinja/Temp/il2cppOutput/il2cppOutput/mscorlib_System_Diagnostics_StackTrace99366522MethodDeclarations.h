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

// System.Diagnostics.StackTrace
struct StackTrace_t99366522_0;
// System.Exception
struct Exception_t2143823668_0;
// System.Diagnostics.StackFrame[]
struct StackFrameU5BU5D_t1462098308_0;
// System.Diagnostics.StackFrame
struct StackFrame_t86437538_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Diagnostics.StackTrace::.ctor()
extern "C"  void StackTrace__ctor_m1636562966_0 (StackTrace_t99366522_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Diagnostics.StackTrace::.ctor(System.Int32,System.Boolean)
extern "C"  void StackTrace__ctor_m449371190_0 (StackTrace_t99366522_0 * __this, int32_t ___skipFrames, bool ___fNeedFileInfo, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Diagnostics.StackTrace::.ctor(System.Exception,System.Boolean)
extern "C"  void StackTrace__ctor_m109564407_0 (StackTrace_t99366522_0 * __this, Exception_t2143823668_0 * ___e, bool ___fNeedFileInfo, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Diagnostics.StackTrace::.ctor(System.Exception,System.Int32,System.Boolean)
extern "C"  void StackTrace__ctor_m_1802869364_0 (StackTrace_t99366522_0 * __this, Exception_t2143823668_0 * ___e, int32_t ___skipFrames, bool ___fNeedFileInfo, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Diagnostics.StackTrace::.ctor(System.Exception,System.Int32,System.Boolean,System.Boolean)
extern "C"  void StackTrace__ctor_m2042930289_0 (StackTrace_t99366522_0 * __this, Exception_t2143823668_0 * ___e, int32_t ___skipFrames, bool ___fNeedFileInfo, bool ___returnNativeFrames, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Diagnostics.StackTrace::init_frames(System.Int32,System.Boolean)
extern "C"  void StackTrace_init_frames_m198588387_0 (StackTrace_t99366522_0 * __this, int32_t ___skipFrames, bool ___fNeedFileInfo, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Diagnostics.StackFrame[] System.Diagnostics.StackTrace::get_trace(System.Exception,System.Int32,System.Boolean)
extern "C"  StackFrameU5BU5D_t1462098308_0* StackTrace_get_trace_m483954897_0 (Object_t * __this /* static, unused */, Exception_t2143823668_0 * ___e, int32_t ___skipFrames, bool ___fNeedFileInfo, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Diagnostics.StackTrace::get_FrameCount()
extern "C"  int32_t StackTrace_get_FrameCount_m_1573189635_0 (StackTrace_t99366522_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Diagnostics.StackFrame System.Diagnostics.StackTrace::GetFrame(System.Int32)
extern "C"  StackFrame_t86437538_0 * StackTrace_GetFrame_m_1319787895_0 (StackTrace_t99366522_0 * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Diagnostics.StackTrace::ToString()
extern "C"  String_t* StackTrace_ToString_m317965015_0 (StackTrace_t99366522_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
