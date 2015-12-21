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

// System.MissingMemberException
struct MissingMemberException_t806483402_0;
// System.String
struct String_t;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"

// System.Void System.MissingMemberException::.ctor()
extern "C"  void MissingMemberException__ctor_m_211782970_0 (MissingMemberException_t806483402_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.MissingMemberException::.ctor(System.String)
extern "C"  void MissingMemberException__ctor_m_732668420_0 (MissingMemberException_t806483402_0 * __this, String_t* ___message, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.MissingMemberException::.ctor(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void MissingMemberException__ctor_m_81608953_0 (MissingMemberException_t806483402_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.MissingMemberException::.ctor(System.String,System.String)
extern "C"  void MissingMemberException__ctor_m_345809608_0 (MissingMemberException_t806483402_0 * __this, String_t* ___className, String_t* ___memberName, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.MissingMemberException::GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void MissingMemberException_GetObjectData_m1444155236_0 (MissingMemberException_t806483402_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.MissingMemberException::get_Message()
extern "C"  String_t* MissingMemberException_get_Message_m388478373_0 (MissingMemberException_t806483402_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
