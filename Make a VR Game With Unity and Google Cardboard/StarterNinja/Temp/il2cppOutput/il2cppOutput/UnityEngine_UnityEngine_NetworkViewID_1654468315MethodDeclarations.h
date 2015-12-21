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
// System.Object
struct Object_t;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_NetworkViewID_1654468315.h"
#include "UnityEngine_UnityEngine_NetworkPlayer_1823588986.h"

// UnityEngine.NetworkViewID UnityEngine.NetworkViewID::get_unassigned()
extern "C"  NetworkViewID_t_1654468315_0  NetworkViewID_get_unassigned_m_1992506259_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.NetworkViewID::INTERNAL_get_unassigned(UnityEngine.NetworkViewID&)
extern "C"  void NetworkViewID_INTERNAL_get_unassigned_m_341582196_0 (Object_t * __this /* static, unused */, NetworkViewID_t_1654468315_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.NetworkViewID::Internal_IsMine(UnityEngine.NetworkViewID)
extern "C"  bool NetworkViewID_Internal_IsMine_m619939661_0 (Object_t * __this /* static, unused */, NetworkViewID_t_1654468315_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.NetworkViewID::INTERNAL_CALL_Internal_IsMine(UnityEngine.NetworkViewID&)
extern "C"  bool NetworkViewID_INTERNAL_CALL_Internal_IsMine_m2052798080_0 (Object_t * __this /* static, unused */, NetworkViewID_t_1654468315_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.NetworkViewID::Internal_GetOwner(UnityEngine.NetworkViewID,UnityEngine.NetworkPlayer&)
extern "C"  void NetworkViewID_Internal_GetOwner_m874421061_0 (Object_t * __this /* static, unused */, NetworkViewID_t_1654468315_0  ___value, NetworkPlayer_t_1823588986_0 * ___player, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.NetworkViewID::INTERNAL_CALL_Internal_GetOwner(UnityEngine.NetworkViewID&,UnityEngine.NetworkPlayer&)
extern "C"  void NetworkViewID_INTERNAL_CALL_Internal_GetOwner_m_1889216706_0 (Object_t * __this /* static, unused */, NetworkViewID_t_1654468315_0 * ___value, NetworkPlayer_t_1823588986_0 * ___player, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.NetworkViewID::Internal_GetString(UnityEngine.NetworkViewID)
extern "C"  String_t* NetworkViewID_Internal_GetString_m679444096_0 (Object_t * __this /* static, unused */, NetworkViewID_t_1654468315_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.NetworkViewID::INTERNAL_CALL_Internal_GetString(UnityEngine.NetworkViewID&)
extern "C"  String_t* NetworkViewID_INTERNAL_CALL_Internal_GetString_m1523080203_0 (Object_t * __this /* static, unused */, NetworkViewID_t_1654468315_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.NetworkViewID::Internal_Compare(UnityEngine.NetworkViewID,UnityEngine.NetworkViewID)
extern "C"  bool NetworkViewID_Internal_Compare_m_1753746438_0 (Object_t * __this /* static, unused */, NetworkViewID_t_1654468315_0  ___lhs, NetworkViewID_t_1654468315_0  ___rhs, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.NetworkViewID::INTERNAL_CALL_Internal_Compare(UnityEngine.NetworkViewID&,UnityEngine.NetworkViewID&)
extern "C"  bool NetworkViewID_INTERNAL_CALL_Internal_Compare_m1319175441_0 (Object_t * __this /* static, unused */, NetworkViewID_t_1654468315_0 * ___lhs, NetworkViewID_t_1654468315_0 * ___rhs, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.NetworkViewID::GetHashCode()
extern "C"  int32_t NetworkViewID_GetHashCode_m_1874331590_0 (NetworkViewID_t_1654468315_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.NetworkViewID::Equals(System.Object)
extern "C"  bool NetworkViewID_Equals_m_1682918174_0 (NetworkViewID_t_1654468315_0 * __this, Object_t * ___other, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.NetworkViewID::get_isMine()
extern "C"  bool NetworkViewID_get_isMine_m_1540559623_0 (NetworkViewID_t_1654468315_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.NetworkPlayer UnityEngine.NetworkViewID::get_owner()
extern "C"  NetworkPlayer_t_1823588986_0  NetworkViewID_get_owner_m576069262_0 (NetworkViewID_t_1654468315_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.NetworkViewID::ToString()
extern "C"  String_t* NetworkViewID_ToString_m_511429246_0 (NetworkViewID_t_1654468315_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.NetworkViewID::op_Equality(UnityEngine.NetworkViewID,UnityEngine.NetworkViewID)
extern "C"  bool NetworkViewID_op_Equality_m776200489_0 (Object_t * __this /* static, unused */, NetworkViewID_t_1654468315_0  ___lhs, NetworkViewID_t_1654468315_0  ___rhs, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.NetworkViewID::op_Inequality(UnityEngine.NetworkViewID,UnityEngine.NetworkViewID)
extern "C"  bool NetworkViewID_op_Inequality_m_70110940_0 (Object_t * __this /* static, unused */, NetworkViewID_t_1654468315_0  ___lhs, NetworkViewID_t_1654468315_0  ___rhs, const MethodInfo* method) IL2CPP_METHOD_ATTR;
