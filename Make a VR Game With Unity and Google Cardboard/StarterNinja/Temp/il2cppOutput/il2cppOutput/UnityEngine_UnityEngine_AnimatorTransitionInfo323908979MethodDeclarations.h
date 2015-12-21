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

// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_AnimatorTransitionInfo323908979.h"

// System.Boolean UnityEngine.AnimatorTransitionInfo::IsName(System.String)
extern "C"  bool AnimatorTransitionInfo_IsName_m1283663078_0 (AnimatorTransitionInfo_t323908979_0 * __this, String_t* ___name, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.AnimatorTransitionInfo::IsUserName(System.String)
extern "C"  bool AnimatorTransitionInfo_IsUserName_m_1562769637_0 (AnimatorTransitionInfo_t323908979_0 * __this, String_t* ___name, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.AnimatorTransitionInfo::get_fullPathHash()
extern "C"  int32_t AnimatorTransitionInfo_get_fullPathHash_m_959500660_0 (AnimatorTransitionInfo_t323908979_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.AnimatorTransitionInfo::get_nameHash()
extern "C"  int32_t AnimatorTransitionInfo_get_nameHash_m2102867203_0 (AnimatorTransitionInfo_t323908979_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.AnimatorTransitionInfo::get_userNameHash()
extern "C"  int32_t AnimatorTransitionInfo_get_userNameHash_m249220782_0 (AnimatorTransitionInfo_t323908979_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.AnimatorTransitionInfo::get_normalizedTime()
extern "C"  float AnimatorTransitionInfo_get_normalizedTime_m_1036282310_0 (AnimatorTransitionInfo_t323908979_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.AnimatorTransitionInfo::get_anyState()
extern "C"  bool AnimatorTransitionInfo_get_anyState_m_873410891_0 (AnimatorTransitionInfo_t323908979_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.AnimatorTransitionInfo::get_entry()
extern "C"  bool AnimatorTransitionInfo_get_entry_m2038132324_0 (AnimatorTransitionInfo_t323908979_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.AnimatorTransitionInfo::get_exit()
extern "C"  bool AnimatorTransitionInfo_get_exit_m_1726462194_0 (AnimatorTransitionInfo_t323908979_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
extern "C" void AnimatorTransitionInfo_t323908979_0_marshal(const AnimatorTransitionInfo_t323908979_0& unmarshaled, AnimatorTransitionInfo_t323908979_0_marshaled& marshaled);
extern "C" void AnimatorTransitionInfo_t323908979_0_marshal_back(const AnimatorTransitionInfo_t323908979_0_marshaled& marshaled, AnimatorTransitionInfo_t323908979_0& unmarshaled);
extern "C" void AnimatorTransitionInfo_t323908979_0_marshal_cleanup(AnimatorTransitionInfo_t323908979_0_marshaled& marshaled);
