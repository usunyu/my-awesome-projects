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

// System.UnitySerializationHolder
struct UnitySerializationHolder_t_531276158_0;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;
// System.Type
struct Type_t;
// System.DBNull
struct DBNull_t_1232829888_0;
// System.Reflection.Module
struct Module_t_2083915884_0;
// System.Object
struct Object_t;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"

// System.Void System.UnitySerializationHolder::.ctor(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void UnitySerializationHolder__ctor_m_981202417_0 (UnitySerializationHolder_t_531276158_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___ctx, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.UnitySerializationHolder::GetTypeData(System.Type,System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void UnitySerializationHolder_GetTypeData_m1915295124_0 (Object_t * __this /* static, unused */, Type_t * ___instance, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___ctx, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.UnitySerializationHolder::GetDBNullData(System.DBNull,System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void UnitySerializationHolder_GetDBNullData_m_1132793174_0 (Object_t * __this /* static, unused */, DBNull_t_1232829888_0 * ___instance, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___ctx, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.UnitySerializationHolder::GetModuleData(System.Reflection.Module,System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void UnitySerializationHolder_GetModuleData_m_1220126881_0 (Object_t * __this /* static, unused */, Module_t_2083915884_0 * ___instance, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___ctx, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.UnitySerializationHolder::GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void UnitySerializationHolder_GetObjectData_m_568470932_0 (UnitySerializationHolder_t_531276158_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.UnitySerializationHolder::GetRealObject(System.Runtime.Serialization.StreamingContext)
extern "C"  Object_t * UnitySerializationHolder_GetRealObject_m_1112249026_0 (UnitySerializationHolder_t_531276158_0 * __this, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
