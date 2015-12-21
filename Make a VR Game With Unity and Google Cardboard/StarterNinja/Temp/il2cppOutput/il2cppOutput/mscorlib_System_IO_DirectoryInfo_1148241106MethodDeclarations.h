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

// System.IO.DirectoryInfo
struct DirectoryInfo_t_1148241106_0;
// System.String
struct String_t;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"

// System.Void System.IO.DirectoryInfo::.ctor(System.String)
extern "C"  void DirectoryInfo__ctor_m_265733472_0 (DirectoryInfo_t_1148241106_0 * __this, String_t* ___path, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.DirectoryInfo::.ctor(System.String,System.Boolean)
extern "C"  void DirectoryInfo__ctor_m_1419344675_0 (DirectoryInfo_t_1148241106_0 * __this, String_t* ___path, bool ___simpleOriginalPath, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.DirectoryInfo::.ctor(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void DirectoryInfo__ctor_m944219619_0 (DirectoryInfo_t_1148241106_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.DirectoryInfo::Initialize()
extern "C"  void DirectoryInfo_Initialize_m287338546_0 (DirectoryInfo_t_1148241106_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.IO.DirectoryInfo::get_Exists()
extern "C"  bool DirectoryInfo_get_Exists_m1761829637_0 (DirectoryInfo_t_1148241106_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.IO.DirectoryInfo System.IO.DirectoryInfo::get_Parent()
extern "C"  DirectoryInfo_t_1148241106_0 * DirectoryInfo_get_Parent_m1129672180_0 (DirectoryInfo_t_1148241106_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.DirectoryInfo::Create()
extern "C"  void DirectoryInfo_Create_m153588510_0 (DirectoryInfo_t_1148241106_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.IO.DirectoryInfo::ToString()
extern "C"  String_t* DirectoryInfo_ToString_m_1633466997_0 (DirectoryInfo_t_1148241106_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
