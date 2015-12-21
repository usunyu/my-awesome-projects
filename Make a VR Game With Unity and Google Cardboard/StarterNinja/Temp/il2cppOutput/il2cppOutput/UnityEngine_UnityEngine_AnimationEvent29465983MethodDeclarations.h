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

// UnityEngine.AnimationEvent
struct AnimationEvent_t29465983_0;
// System.String
struct String_t;
// UnityEngine.Object
struct Object_t1159094344_0;
struct Object_t1159094344_0_marshaled;
// UnityEngine.AnimationState
struct AnimationState_t42332022_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_SendMessageOptions_53436984.h"
#include "UnityEngine_UnityEngine_AnimatorStateInfo_306960113.h"
#include "UnityEngine_UnityEngine_AnimatorClipInfo_1796091410.h"

// System.Void UnityEngine.AnimationEvent::.ctor()
extern "C"  void AnimationEvent__ctor_m_401744585_0 (AnimationEvent_t29465983_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.AnimationEvent::get_data()
extern "C"  String_t* AnimationEvent_get_data_m_1476038813_0 (AnimationEvent_t29465983_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.AnimationEvent::set_data(System.String)
extern "C"  void AnimationEvent_set_data_m1709280462_0 (AnimationEvent_t29465983_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.AnimationEvent::get_stringParameter()
extern "C"  String_t* AnimationEvent_get_stringParameter_m774178145_0 (AnimationEvent_t29465983_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.AnimationEvent::set_stringParameter(System.String)
extern "C"  void AnimationEvent_set_stringParameter_m_267803758_0 (AnimationEvent_t29465983_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.AnimationEvent::get_floatParameter()
extern "C"  float AnimationEvent_get_floatParameter_m585550415_0 (AnimationEvent_t29465983_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.AnimationEvent::set_floatParameter(System.Single)
extern "C"  void AnimationEvent_set_floatParameter_m_322547884_0 (AnimationEvent_t29465983_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.AnimationEvent::get_intParameter()
extern "C"  int32_t AnimationEvent_get_intParameter_m1837369744_0 (AnimationEvent_t29465983_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.AnimationEvent::set_intParameter(System.Int32)
extern "C"  void AnimationEvent_set_intParameter_m1983832533_0 (AnimationEvent_t29465983_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Object UnityEngine.AnimationEvent::get_objectReferenceParameter()
extern "C"  Object_t1159094344_0 * AnimationEvent_get_objectReferenceParameter_m1449907980_0 (AnimationEvent_t29465983_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.AnimationEvent::set_objectReferenceParameter(UnityEngine.Object)
extern "C"  void AnimationEvent_set_objectReferenceParameter_m_1342064111_0 (AnimationEvent_t29465983_0 * __this, Object_t1159094344_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.AnimationEvent::get_functionName()
extern "C"  String_t* AnimationEvent_get_functionName_m508701692_0 (AnimationEvent_t29465983_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.AnimationEvent::set_functionName(System.String)
extern "C"  void AnimationEvent_set_functionName_m_946990635_0 (AnimationEvent_t29465983_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.AnimationEvent::get_time()
extern "C"  float AnimationEvent_get_time_m_129257041_0 (AnimationEvent_t29465983_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.AnimationEvent::set_time(System.Single)
extern "C"  void AnimationEvent_set_time_m_1548058124_0 (AnimationEvent_t29465983_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.SendMessageOptions UnityEngine.AnimationEvent::get_messageOptions()
extern "C"  int32_t AnimationEvent_get_messageOptions_m501221094_0 (AnimationEvent_t29465983_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.AnimationEvent::set_messageOptions(UnityEngine.SendMessageOptions)
extern "C"  void AnimationEvent_set_messageOptions_m927737387_0 (AnimationEvent_t29465983_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.AnimationEvent::get_isFiredByLegacy()
extern "C"  bool AnimationEvent_get_isFiredByLegacy_m1265747114_0 (AnimationEvent_t29465983_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.AnimationEvent::get_isFiredByAnimator()
extern "C"  bool AnimationEvent_get_isFiredByAnimator_m877765704_0 (AnimationEvent_t29465983_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.AnimationState UnityEngine.AnimationEvent::get_animationState()
extern "C"  AnimationState_t42332022_0 * AnimationEvent_get_animationState_m_1582214066_0 (AnimationEvent_t29465983_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.AnimatorStateInfo UnityEngine.AnimationEvent::get_animatorStateInfo()
extern "C"  AnimatorStateInfo_t_306960113_0  AnimationEvent_get_animatorStateInfo_m194903218_0 (AnimationEvent_t29465983_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.AnimatorClipInfo UnityEngine.AnimationEvent::get_animatorClipInfo()
extern "C"  AnimatorClipInfo_t_1796091410_0  AnimationEvent_get_animatorClipInfo_m493861262_0 (AnimationEvent_t29465983_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.AnimationEvent::GetHash()
extern "C"  int32_t AnimationEvent_GetHash_m_1708083879_0 (AnimationEvent_t29465983_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
