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

// System.OperatingSystem
struct OperatingSystem_t288380405_0;
// System.Version
struct Version_t267380989_0;
// System.Object
struct Object_t;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_PlatformID1033348745.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"

// System.Void System.OperatingSystem::.ctor(System.PlatformID,System.Version)
extern "C"  void OperatingSystem__ctor_m1430692681_0 (OperatingSystem_t288380405_0 * __this, int32_t ___platform, Version_t267380989_0 * ___version, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.PlatformID System.OperatingSystem::get_Platform()
extern "C"  int32_t OperatingSystem_get_Platform_m949444901_0 (OperatingSystem_t288380405_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.OperatingSystem::Clone()
extern "C"  Object_t * OperatingSystem_Clone_m984082471_0 (OperatingSystem_t288380405_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.OperatingSystem::GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void OperatingSystem_GetObjectData_m746174751_0 (OperatingSystem_t288380405_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.OperatingSystem::ToString()
extern "C"  String_t* OperatingSystem_ToString_m_624624462_0 (OperatingSystem_t288380405_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
