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
#include "UnityEngine_UnityEngine_NetworkPlayer_1823588986.h"

// System.Void UnityEngine.NetworkPlayer::.ctor(System.String,System.Int32)
extern "C"  void NetworkPlayer__ctor_m978047135_0 (NetworkPlayer_t_1823588986_0 * __this, String_t* ___ip, int32_t ___port, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.NetworkPlayer::Internal_GetIPAddress(System.Int32)
extern "C"  String_t* NetworkPlayer_Internal_GetIPAddress_m_1589044619_0 (Object_t * __this /* static, unused */, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.NetworkPlayer::Internal_GetPort(System.Int32)
extern "C"  int32_t NetworkPlayer_Internal_GetPort_m_1648276256_0 (Object_t * __this /* static, unused */, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.NetworkPlayer::Internal_GetExternalIP()
extern "C"  String_t* NetworkPlayer_Internal_GetExternalIP_m_147146499_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.NetworkPlayer::Internal_GetExternalPort()
extern "C"  int32_t NetworkPlayer_Internal_GetExternalPort_m152642746_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.NetworkPlayer::Internal_GetLocalIP()
extern "C"  String_t* NetworkPlayer_Internal_GetLocalIP_m_1152322487_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.NetworkPlayer::Internal_GetLocalPort()
extern "C"  int32_t NetworkPlayer_Internal_GetLocalPort_m_4320288_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.NetworkPlayer::Internal_GetPlayerIndex()
extern "C"  int32_t NetworkPlayer_Internal_GetPlayerIndex_m1155344837_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.NetworkPlayer::Internal_GetGUID(System.Int32)
extern "C"  String_t* NetworkPlayer_Internal_GetGUID_m82698821_0 (Object_t * __this /* static, unused */, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.NetworkPlayer::Internal_GetLocalGUID()
extern "C"  String_t* NetworkPlayer_Internal_GetLocalGUID_m668021995_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.NetworkPlayer::GetHashCode()
extern "C"  int32_t NetworkPlayer_GetHashCode_m_1461969479_0 (NetworkPlayer_t_1823588986_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.NetworkPlayer::Equals(System.Object)
extern "C"  bool NetworkPlayer_Equals_m1380117345_0 (NetworkPlayer_t_1823588986_0 * __this, Object_t * ___other, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.NetworkPlayer::get_ipAddress()
extern "C"  String_t* NetworkPlayer_get_ipAddress_m206939407_0 (NetworkPlayer_t_1823588986_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.NetworkPlayer::get_port()
extern "C"  int32_t NetworkPlayer_get_port_m_34043868_0 (NetworkPlayer_t_1823588986_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.NetworkPlayer::get_guid()
extern "C"  String_t* NetworkPlayer_get_guid_m1193250345_0 (NetworkPlayer_t_1823588986_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.NetworkPlayer::ToString()
extern "C"  String_t* NetworkPlayer_ToString_m_179103645_0 (NetworkPlayer_t_1823588986_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.NetworkPlayer::get_externalIP()
extern "C"  String_t* NetworkPlayer_get_externalIP_m420672594_0 (NetworkPlayer_t_1823588986_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.NetworkPlayer::get_externalPort()
extern "C"  int32_t NetworkPlayer_get_externalPort_m_1902800433_0 (NetworkPlayer_t_1823588986_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.NetworkPlayer UnityEngine.NetworkPlayer::get_unassigned()
extern "C"  NetworkPlayer_t_1823588986_0  NetworkPlayer_get_unassigned_m865556847_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.NetworkPlayer::op_Equality(UnityEngine.NetworkPlayer,UnityEngine.NetworkPlayer)
extern "C"  bool NetworkPlayer_op_Equality_m1190866952_0 (Object_t * __this /* static, unused */, NetworkPlayer_t_1823588986_0  ___lhs, NetworkPlayer_t_1823588986_0  ___rhs, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.NetworkPlayer::op_Inequality(UnityEngine.NetworkPlayer,UnityEngine.NetworkPlayer)
extern "C"  bool NetworkPlayer_op_Inequality_m_373949501_0 (Object_t * __this /* static, unused */, NetworkPlayer_t_1823588986_0  ___lhs, NetworkPlayer_t_1823588986_0  ___rhs, const MethodInfo* method) IL2CPP_METHOD_ATTR;
