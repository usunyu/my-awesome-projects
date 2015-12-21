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

// System.Diagnostics.StackFrame
struct StackFrame_t86437538_0;
// System.Reflection.MethodBase
struct MethodBase_t553742458_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Diagnostics.StackFrame::.ctor()
extern "C"  void StackFrame__ctor_m_665195282_0 (StackFrame_t86437538_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Diagnostics.StackFrame::.ctor(System.Int32,System.Boolean)
extern "C"  void StackFrame__ctor_m926982238_0 (StackFrame_t86437538_0 * __this, int32_t ___skipFrames, bool ___fNeedFileInfo, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Diagnostics.StackFrame::get_frame_info(System.Int32,System.Boolean,System.Reflection.MethodBase&,System.Int32&,System.Int32&,System.String&,System.Int32&,System.Int32&)
extern "C"  bool StackFrame_get_frame_info_m_2062583899_0 (Object_t * __this /* static, unused */, int32_t ___skip, bool ___needFileInfo, MethodBase_t553742458_0 ** ___method, int32_t* ___iloffset, int32_t* ___native_offset, String_t** ___file, int32_t* ___line, int32_t* ___column, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Diagnostics.StackFrame::GetFileLineNumber()
extern "C"  int32_t StackFrame_GetFileLineNumber_m_460170537_0 (StackFrame_t86437538_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Diagnostics.StackFrame::GetFileName()
extern "C"  String_t* StackFrame_GetFileName_m_654925428_0 (StackFrame_t86437538_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Diagnostics.StackFrame::GetSecureFileName()
extern "C"  String_t* StackFrame_GetSecureFileName_m_1864727197_0 (StackFrame_t86437538_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Diagnostics.StackFrame::GetILOffset()
extern "C"  int32_t StackFrame_GetILOffset_m_1409809964_0 (StackFrame_t86437538_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodBase System.Diagnostics.StackFrame::GetMethod()
extern "C"  MethodBase_t553742458_0 * StackFrame_GetMethod_m1989802200_0 (StackFrame_t86437538_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Diagnostics.StackFrame::GetNativeOffset()
extern "C"  int32_t StackFrame_GetNativeOffset_m_1541326232_0 (StackFrame_t86437538_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Diagnostics.StackFrame::GetInternalMethodName()
extern "C"  String_t* StackFrame_GetInternalMethodName_m623093646_0 (StackFrame_t86437538_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Diagnostics.StackFrame::ToString()
extern "C"  String_t* StackFrame_ToString_m2085846783_0 (StackFrame_t86437538_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
