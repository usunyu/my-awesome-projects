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

// UnityEngine.BitStream
struct BitStream_t164902212_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Quaternion1989680039.h"
#include "UnityEngine_UnityEngine_Vector3_725341337.h"
#include "UnityEngine_UnityEngine_NetworkViewID_1654468315.h"
#include "UnityEngine_UnityEngine_NetworkPlayer_1823588986.h"

// System.Void UnityEngine.BitStream::.ctor()
extern "C"  void BitStream__ctor_m922403980_0 (BitStream_t164902212_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::Serializeb(System.Int32&)
extern "C"  void BitStream_Serializeb_m1472011233_0 (BitStream_t164902212_0 * __this, int32_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::Serializec(System.Char&)
extern "C"  void BitStream_Serializec_m1377214154_0 (BitStream_t164902212_0 * __this, uint16_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::Serializes(System.Int16&)
extern "C"  void BitStream_Serializes_m1382809078_0 (BitStream_t164902212_0 * __this, int16_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::Serializei(System.Int32&)
extern "C"  void BitStream_Serializei_m_2101728006_0 (BitStream_t164902212_0 * __this, int32_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::Serializef(System.Single&,System.Single)
extern "C"  void BitStream_Serializef_m145870244_0 (BitStream_t164902212_0 * __this, float* ___value, float ___maximumDelta, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::Serializeq(UnityEngine.Quaternion&,System.Single)
extern "C"  void BitStream_Serializeq_m_1305596707_0 (BitStream_t164902212_0 * __this, Quaternion_t1989680039_0 * ___value, float ___maximumDelta, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::INTERNAL_CALL_Serializeq(UnityEngine.BitStream,UnityEngine.Quaternion&,System.Single)
extern "C"  void BitStream_INTERNAL_CALL_Serializeq_m999142740_0 (Object_t * __this /* static, unused */, BitStream_t164902212_0 * ___self, Quaternion_t1989680039_0 * ___value, float ___maximumDelta, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::Serializev(UnityEngine.Vector3&,System.Single)
extern "C"  void BitStream_Serializev_m_1474642106_0 (BitStream_t164902212_0 * __this, Vector3_t_725341337_0 * ___value, float ___maximumDelta, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::INTERNAL_CALL_Serializev(UnityEngine.BitStream,UnityEngine.Vector3&,System.Single)
extern "C"  void BitStream_INTERNAL_CALL_Serializev_m2004861039_0 (Object_t * __this /* static, unused */, BitStream_t164902212_0 * ___self, Vector3_t_725341337_0 * ___value, float ___maximumDelta, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::Serializen(UnityEngine.NetworkViewID&)
extern "C"  void BitStream_Serializen_m_639817961_0 (BitStream_t164902212_0 * __this, NetworkViewID_t_1654468315_0 * ___viewID, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::INTERNAL_CALL_Serializen(UnityEngine.BitStream,UnityEngine.NetworkViewID&)
extern "C"  void BitStream_INTERNAL_CALL_Serializen_m_263416000_0 (Object_t * __this /* static, unused */, BitStream_t164902212_0 * ___self, NetworkViewID_t_1654468315_0 * ___viewID, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::Serialize(System.Boolean&)
extern "C"  void BitStream_Serialize_m2001881067_0 (BitStream_t164902212_0 * __this, bool* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::Serialize(System.Char&)
extern "C"  void BitStream_Serialize_m_1566213735_0 (BitStream_t164902212_0 * __this, uint16_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::Serialize(System.Int16&)
extern "C"  void BitStream_Serialize_m_90530025_0 (BitStream_t164902212_0 * __this, int16_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::Serialize(System.Int32&)
extern "C"  void BitStream_Serialize_m_90474287_0 (BitStream_t164902212_0 * __this, int32_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::Serialize(System.Single&)
extern "C"  void BitStream_Serialize_m1473984011_0 (BitStream_t164902212_0 * __this, float* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::Serialize(System.Single&,System.Single)
extern "C"  void BitStream_Serialize_m518836656_0 (BitStream_t164902212_0 * __this, float* ___value, float ___maxDelta, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::Serialize(UnityEngine.Quaternion&)
extern "C"  void BitStream_Serialize_m_162462185_0 (BitStream_t164902212_0 * __this, Quaternion_t1989680039_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::Serialize(UnityEngine.Quaternion&,System.Single)
extern "C"  void BitStream_Serialize_m1228905660_0 (BitStream_t164902212_0 * __this, Quaternion_t1989680039_0 * ___value, float ___maxDelta, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::Serialize(UnityEngine.Vector3&)
extern "C"  void BitStream_Serialize_m981417501_0 (BitStream_t164902212_0 * __this, Vector3_t_725341337_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::Serialize(UnityEngine.Vector3&,System.Single)
extern "C"  void BitStream_Serialize_m_1085255102_0 (BitStream_t164902212_0 * __this, Vector3_t_725341337_0 * ___value, float ___maxDelta, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::Serialize(UnityEngine.NetworkPlayer&)
extern "C"  void BitStream_Serialize_m_47943108_0 (BitStream_t164902212_0 * __this, NetworkPlayer_t_1823588986_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::Serialize(UnityEngine.NetworkViewID&)
extern "C"  void BitStream_Serialize_m_731735525_0 (BitStream_t164902212_0 * __this, NetworkViewID_t_1654468315_0 * ___viewID, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.BitStream::get_isReading()
extern "C"  bool BitStream_get_isReading_m_365097655_0 (BitStream_t164902212_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.BitStream::get_isWriting()
extern "C"  bool BitStream_get_isWriting_m_662576231_0 (BitStream_t164902212_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.BitStream::Serialize(System.String&)
extern "C"  void BitStream_Serialize_m_1531952236_0 (BitStream_t164902212_0 * __this, String_t** ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
