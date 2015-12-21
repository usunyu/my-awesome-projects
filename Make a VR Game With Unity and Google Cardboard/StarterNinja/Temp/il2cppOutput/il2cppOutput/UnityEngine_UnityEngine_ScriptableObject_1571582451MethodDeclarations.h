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

// UnityEngine.ScriptableObject
struct ScriptableObject_t_1571582451_0;
struct ScriptableObject_t_1571582451_0_marshaled;
// System.String
struct String_t;
// System.Type
struct Type_t;

#include "codegen/il2cpp-codegen.h"

// System.Void UnityEngine.ScriptableObject::.ctor()
extern "C"  void ScriptableObject__ctor_m1827087273_0 (ScriptableObject_t_1571582451_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.ScriptableObject::Internal_CreateScriptableObject(UnityEngine.ScriptableObject)
extern "C"  void ScriptableObject_Internal_CreateScriptableObject_m_1960606226_0 (Object_t * __this /* static, unused */, ScriptableObject_t_1571582451_0 * ___self, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.ScriptableObject UnityEngine.ScriptableObject::CreateInstance(System.String)
extern "C"  ScriptableObject_t_1571582451_0 * ScriptableObject_CreateInstance_m750914562_0 (Object_t * __this /* static, unused */, String_t* ___className, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.ScriptableObject UnityEngine.ScriptableObject::CreateInstance(System.Type)
extern "C"  ScriptableObject_t_1571582451_0 * ScriptableObject_CreateInstance_m_1039487879_0 (Object_t * __this /* static, unused */, Type_t * ___type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.ScriptableObject UnityEngine.ScriptableObject::CreateInstanceFromType(System.Type)
extern "C"  ScriptableObject_t_1571582451_0 * ScriptableObject_CreateInstanceFromType_m_499614763_0 (Object_t * __this /* static, unused */, Type_t * ___type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
extern "C" void ScriptableObject_t_1571582451_0_marshal(const ScriptableObject_t_1571582451_0& unmarshaled, ScriptableObject_t_1571582451_0_marshaled& marshaled);
extern "C" void ScriptableObject_t_1571582451_0_marshal_back(const ScriptableObject_t_1571582451_0_marshaled& marshaled, ScriptableObject_t_1571582451_0& unmarshaled);
extern "C" void ScriptableObject_t_1571582451_0_marshal_cleanup(ScriptableObject_t_1571582451_0_marshaled& marshaled);
