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

// System.Reflection.AssemblyName
struct AssemblyName_t215784633_0;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;
// System.String
struct String_t;
// System.Version
struct Version_t267380989_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Object
struct Object_t;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"
#include "mscorlib_System_Reflection_AssemblyNameFlags274885966.h"

// System.Void System.Reflection.AssemblyName::.ctor()
extern "C"  void AssemblyName__ctor_m2021574845_0 (AssemblyName_t215784633_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Reflection.AssemblyName::.ctor(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void AssemblyName__ctor_m1431164030_0 (AssemblyName_t215784633_0 * __this, SerializationInfo_t526833679_0 * ___si, StreamingContext_t_1216992900_0  ___sc, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.AssemblyName::get_Name()
extern "C"  String_t* AssemblyName_get_Name_m1123490526_0 (AssemblyName_t215784633_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.AssemblyNameFlags System.Reflection.AssemblyName::get_Flags()
extern "C"  int32_t AssemblyName_get_Flags_m841716984_0 (AssemblyName_t215784633_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.AssemblyName::get_FullName()
extern "C"  String_t* AssemblyName_get_FullName_m_1414895283_0 (AssemblyName_t215784633_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Version System.Reflection.AssemblyName::get_Version()
extern "C"  Version_t267380989_0 * AssemblyName_get_Version_m700434552_0 (AssemblyName_t215784633_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Reflection.AssemblyName::set_Version(System.Version)
extern "C"  void AssemblyName_set_Version_m1560254941_0 (AssemblyName_t215784633_0 * __this, Version_t267380989_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Reflection.AssemblyName::ToString()
extern "C"  String_t* AssemblyName_ToString_m485215606_0 (AssemblyName_t215784633_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.AssemblyName::get_IsPublicKeyValid()
extern "C"  bool AssemblyName_get_IsPublicKeyValid_m65110050_0 (AssemblyName_t215784633_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Reflection.AssemblyName::InternalGetPublicKeyToken()
extern "C"  ByteU5BU5D_t_1238178395_0* AssemblyName_InternalGetPublicKeyToken_m1116912397_0 (AssemblyName_t215784633_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Reflection.AssemblyName::ComputePublicKeyToken()
extern "C"  ByteU5BU5D_t_1238178395_0* AssemblyName_ComputePublicKeyToken_m1248936939_0 (AssemblyName_t215784633_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Reflection.AssemblyName::SetPublicKey(System.Byte[])
extern "C"  void AssemblyName_SetPublicKey_m_1411681074_0 (AssemblyName_t215784633_0 * __this, ByteU5BU5D_t_1238178395_0* ___publicKey, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Reflection.AssemblyName::SetPublicKeyToken(System.Byte[])
extern "C"  void AssemblyName_SetPublicKeyToken_m_744305463_0 (AssemblyName_t215784633_0 * __this, ByteU5BU5D_t_1238178395_0* ___publicKeyToken, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Reflection.AssemblyName::GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void AssemblyName_GetObjectData_m_567689765_0 (AssemblyName_t215784633_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Reflection.AssemblyName::Clone()
extern "C"  Object_t * AssemblyName_Clone_m1423794147_0 (AssemblyName_t215784633_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Reflection.AssemblyName::OnDeserialization(System.Object)
extern "C"  void AssemblyName_OnDeserialization_m866678633_0 (AssemblyName_t215784633_0 * __this, Object_t * ___sender, const MethodInfo* method) IL2CPP_METHOD_ATTR;
