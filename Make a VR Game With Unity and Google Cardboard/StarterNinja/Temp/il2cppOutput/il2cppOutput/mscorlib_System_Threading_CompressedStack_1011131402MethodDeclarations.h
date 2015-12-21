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

// System.Threading.CompressedStack
struct CompressedStack_t_1011131402_0;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"

// System.Void System.Threading.CompressedStack::.ctor(System.Int32)
extern "C"  void CompressedStack__ctor_m_1661232463_0 (CompressedStack_t_1011131402_0 * __this, int32_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.CompressedStack::.ctor(System.Threading.CompressedStack)
extern "C"  void CompressedStack__ctor_m1552323470_0 (CompressedStack_t_1011131402_0 * __this, CompressedStack_t_1011131402_0 * ___cs, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Threading.CompressedStack System.Threading.CompressedStack::CreateCopy()
extern "C"  CompressedStack_t_1011131402_0 * CompressedStack_CreateCopy_m_1590304594_0 (CompressedStack_t_1011131402_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Threading.CompressedStack System.Threading.CompressedStack::Capture()
extern "C"  CompressedStack_t_1011131402_0 * CompressedStack_Capture_m_106030357_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.CompressedStack::GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void CompressedStack_GetObjectData_m1776876798_0 (CompressedStack_t_1011131402_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Threading.CompressedStack::IsEmpty()
extern "C"  bool CompressedStack_IsEmpty_m35500159_0 (CompressedStack_t_1011131402_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
