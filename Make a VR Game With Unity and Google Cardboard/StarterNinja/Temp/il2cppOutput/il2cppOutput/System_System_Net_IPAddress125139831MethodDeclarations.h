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

// System.Net.IPAddress
struct IPAddress_t125139831_0;
// System.UInt16[]
struct UInt16U5BU5D_t_1239550212_0;
// System.String
struct String_t;
// System.Object
struct Object_t;

#include "codegen/il2cpp-codegen.h"
#include "System_System_Net_Sockets_AddressFamily1922836948.h"

// System.Void System.Net.IPAddress::.ctor(System.Int64)
extern "C"  void IPAddress__ctor_m927672017_0 (IPAddress_t125139831_0 * __this, int64_t ___addr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Net.IPAddress::.ctor(System.UInt16[],System.Int64)
extern "C"  void IPAddress__ctor_m_357443195_0 (IPAddress_t125139831_0 * __this, UInt16U5BU5D_t_1239550212_0* ___address, int64_t ___scopeId, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Net.IPAddress::.cctor()
extern "C"  void IPAddress__cctor_m_938856690_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int16 System.Net.IPAddress::SwapShort(System.Int16)
extern "C"  int16_t IPAddress_SwapShort_m2091369575_0 (Object_t * __this /* static, unused */, int16_t ___number, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int16 System.Net.IPAddress::HostToNetworkOrder(System.Int16)
extern "C"  int16_t IPAddress_HostToNetworkOrder_m_780373827_0 (Object_t * __this /* static, unused */, int16_t ___host, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int16 System.Net.IPAddress::NetworkToHostOrder(System.Int16)
extern "C"  int16_t IPAddress_NetworkToHostOrder_m_726577449_0 (Object_t * __this /* static, unused */, int16_t ___network, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Net.IPAddress System.Net.IPAddress::Parse(System.String)
extern "C"  IPAddress_t125139831_0 * IPAddress_Parse_m1640477876_0 (Object_t * __this /* static, unused */, String_t* ___ipString, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Net.IPAddress::TryParse(System.String,System.Net.IPAddress&)
extern "C"  bool IPAddress_TryParse_m1385842418_0 (Object_t * __this /* static, unused */, String_t* ___ipString, IPAddress_t125139831_0 ** ___address, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Net.IPAddress System.Net.IPAddress::ParseIPV4(System.String)
extern "C"  IPAddress_t125139831_0 * IPAddress_ParseIPV4_m120660623_0 (Object_t * __this /* static, unused */, String_t* ___ip, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Net.IPAddress System.Net.IPAddress::ParseIPV6(System.String)
extern "C"  IPAddress_t125139831_0 * IPAddress_ParseIPV6_m_900407731_0 (Object_t * __this /* static, unused */, String_t* ___ip, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.Net.IPAddress::get_InternalIPv4Address()
extern "C"  int64_t IPAddress_get_InternalIPv4Address_m2101711253_0 (IPAddress_t125139831_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.Net.IPAddress::get_ScopeId()
extern "C"  int64_t IPAddress_get_ScopeId_m_2070952846_0 (IPAddress_t125139831_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Net.Sockets.AddressFamily System.Net.IPAddress::get_AddressFamily()
extern "C"  int32_t IPAddress_get_AddressFamily_m_1930645049_0 (IPAddress_t125139831_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Net.IPAddress::IsLoopback(System.Net.IPAddress)
extern "C"  bool IPAddress_IsLoopback_m_845915533_0 (Object_t * __this /* static, unused */, IPAddress_t125139831_0 * ___addr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Net.IPAddress::ToString()
extern "C"  String_t* IPAddress_ToString_m_1346995020_0 (IPAddress_t125139831_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Net.IPAddress::ToString(System.Int64)
extern "C"  String_t* IPAddress_ToString_m277532550_0 (Object_t * __this /* static, unused */, int64_t ___addr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Net.IPAddress::Equals(System.Object)
extern "C"  bool IPAddress_Equals_m1176433114_0 (IPAddress_t125139831_0 * __this, Object_t * ___other, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Net.IPAddress::GetHashCode()
extern "C"  int32_t IPAddress_GetHashCode_m1369616318_0 (IPAddress_t125139831_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Net.IPAddress::Hash(System.Int32,System.Int32,System.Int32,System.Int32)
extern "C"  int32_t IPAddress_Hash_m_556821117_0 (Object_t * __this /* static, unused */, int32_t ___i, int32_t ___j, int32_t ___k, int32_t ___l, const MethodInfo* method) IL2CPP_METHOD_ATTR;
