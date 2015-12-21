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

// Mono.Security.Protocol.Tls.Context
struct Context_t_1281777657_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// Mono.Security.Protocol.Tls.TlsServerSettings
struct TlsServerSettings_t_519671111_0;
// Mono.Security.Protocol.Tls.TlsClientSettings
struct TlsClientSettings_t_546427071_0;
// Mono.Security.Protocol.Tls.CipherSuiteCollection
struct CipherSuiteCollection_t_82012541_0;
// Mono.Security.Protocol.Tls.TlsStream
struct TlsStream_t_1516681037_0;
// Mono.Security.Protocol.Tls.RecordProtocol
struct RecordProtocol_t_2004860751_0;
// Mono.Security.Protocol.Tls.SecurityParameters
struct SecurityParameters_t_1142410254_0;

#include "codegen/il2cpp-codegen.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_SecurityP_942303750.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_SecurityC_740766536.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_Handshak_1520136110.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_Handshak_1866662526.h"

// System.Void Mono.Security.Protocol.Tls.Context::.ctor(Mono.Security.Protocol.Tls.SecurityProtocolType)
extern "C"  void Context__ctor_m_1602405365_0 (Context_t_1281777657_0 * __this, int32_t ___securityProtocolType, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.Context::get_AbbreviatedHandshake()
extern "C"  bool Context_get_AbbreviatedHandshake_m_673710230_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_AbbreviatedHandshake(System.Boolean)
extern "C"  void Context_set_AbbreviatedHandshake_m66679943_0 (Context_t_1281777657_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.Context::get_ProtocolNegotiated()
extern "C"  bool Context_get_ProtocolNegotiated_m2137079082_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_ProtocolNegotiated(System.Boolean)
extern "C"  void Context_set_ProtocolNegotiated_m_1315064889_0 (Context_t_1281777657_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.SecurityProtocolType Mono.Security.Protocol.Tls.Context::get_SecurityProtocol()
extern "C"  int32_t Context_get_SecurityProtocol_m_1837301711_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_SecurityProtocol(Mono.Security.Protocol.Tls.SecurityProtocolType)
extern "C"  void Context_set_SecurityProtocol_m848973232_0 (Context_t_1281777657_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.SecurityProtocolType Mono.Security.Protocol.Tls.Context::get_SecurityProtocolFlags()
extern "C"  int32_t Context_get_SecurityProtocolFlags_m1914144888_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int16 Mono.Security.Protocol.Tls.Context::get_Protocol()
extern "C"  int16_t Context_get_Protocol_m775713592_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.Context::get_SessionId()
extern "C"  ByteU5BU5D_t_1238178395_0* Context_get_SessionId_m1237865483_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_SessionId(System.Byte[])
extern "C"  void Context_set_SessionId_m_1202845720_0 (Context_t_1281777657_0 * __this, ByteU5BU5D_t_1238178395_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.SecurityCompressionType Mono.Security.Protocol.Tls.Context::get_CompressionMethod()
extern "C"  int32_t Context_get_CompressionMethod_m487253678_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_CompressionMethod(Mono.Security.Protocol.Tls.SecurityCompressionType)
extern "C"  void Context_set_CompressionMethod_m_832917955_0 (Context_t_1281777657_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.TlsServerSettings Mono.Security.Protocol.Tls.Context::get_ServerSettings()
extern "C"  TlsServerSettings_t_519671111_0 * Context_get_ServerSettings_m_284354208_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.TlsClientSettings Mono.Security.Protocol.Tls.Context::get_ClientSettings()
extern "C"  TlsClientSettings_t_546427071_0 * Context_get_ClientSettings_m_52436896_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.Handshake.HandshakeType Mono.Security.Protocol.Tls.Context::get_LastHandshakeMsg()
extern "C"  uint8_t Context_get_LastHandshakeMsg_m1576961185_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_LastHandshakeMsg(Mono.Security.Protocol.Tls.Handshake.HandshakeType)
extern "C"  void Context_set_LastHandshakeMsg_m1436694014_0 (Context_t_1281777657_0 * __this, uint8_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.HandshakeState Mono.Security.Protocol.Tls.Context::get_HandshakeState()
extern "C"  int32_t Context_get_HandshakeState_m972066827_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_HandshakeState(Mono.Security.Protocol.Tls.HandshakeState)
extern "C"  void Context_set_HandshakeState_m_866868858_0 (Context_t_1281777657_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.Context::get_ReceivedConnectionEnd()
extern "C"  bool Context_get_ReceivedConnectionEnd_m731026834_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_ReceivedConnectionEnd(System.Boolean)
extern "C"  void Context_set_ReceivedConnectionEnd_m1502103331_0 (Context_t_1281777657_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.Context::get_SentConnectionEnd()
extern "C"  bool Context_get_SentConnectionEnd_m1343643003_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_SentConnectionEnd(System.Boolean)
extern "C"  void Context_set_SentConnectionEnd_m_1306697652_0 (Context_t_1281777657_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.CipherSuiteCollection Mono.Security.Protocol.Tls.Context::get_SupportedCiphers()
extern "C"  CipherSuiteCollection_t_82012541_0 * Context_get_SupportedCiphers_m_2043215158_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_SupportedCiphers(Mono.Security.Protocol.Tls.CipherSuiteCollection)
extern "C"  void Context_set_SupportedCiphers_m_1636467033_0 (Context_t_1281777657_0 * __this, CipherSuiteCollection_t_82012541_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.TlsStream Mono.Security.Protocol.Tls.Context::get_HandshakeMessages()
extern "C"  TlsStream_t_1516681037_0 * Context_get_HandshakeMessages_m1457854885_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt64 Mono.Security.Protocol.Tls.Context::get_WriteSequenceNumber()
extern "C"  uint64_t Context_get_WriteSequenceNumber_m_1869244111_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_WriteSequenceNumber(System.UInt64)
extern "C"  void Context_set_WriteSequenceNumber_m970670722_0 (Context_t_1281777657_0 * __this, uint64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt64 Mono.Security.Protocol.Tls.Context::get_ReadSequenceNumber()
extern "C"  uint64_t Context_get_ReadSequenceNumber_m1306012538_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_ReadSequenceNumber(System.UInt64)
extern "C"  void Context_set_ReadSequenceNumber_m_1187066711_0 (Context_t_1281777657_0 * __this, uint64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.Context::get_ClientRandom()
extern "C"  ByteU5BU5D_t_1238178395_0* Context_get_ClientRandom_m1978397270_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_ClientRandom(System.Byte[])
extern "C"  void Context_set_ClientRandom_m628701865_0 (Context_t_1281777657_0 * __this, ByteU5BU5D_t_1238178395_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.Context::get_ServerRandom()
extern "C"  ByteU5BU5D_t_1238178395_0* Context_get_ServerRandom_m2005153230_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_ServerRandom(System.Byte[])
extern "C"  void Context_set_ServerRandom_m1721522737_0 (Context_t_1281777657_0 * __this, ByteU5BU5D_t_1238178395_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.Context::get_RandomCS()
extern "C"  ByteU5BU5D_t_1238178395_0* Context_get_RandomCS_m1402706075_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_RandomCS(System.Byte[])
extern "C"  void Context_set_RandomCS_m_1908549756_0 (Context_t_1281777657_0 * __this, ByteU5BU5D_t_1238178395_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.Context::get_RandomSC()
extern "C"  ByteU5BU5D_t_1238178395_0* Context_get_RandomSC_m1403167355_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_RandomSC(System.Byte[])
extern "C"  void Context_set_RandomSC_m2143148452_0 (Context_t_1281777657_0 * __this, ByteU5BU5D_t_1238178395_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.Context::get_MasterSecret()
extern "C"  ByteU5BU5D_t_1238178395_0* Context_get_MasterSecret_m2040743066_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_MasterSecret(System.Byte[])
extern "C"  void Context_set_MasterSecret_m748730085_0 (Context_t_1281777657_0 * __this, ByteU5BU5D_t_1238178395_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.Context::get_ClientWriteKey()
extern "C"  ByteU5BU5D_t_1238178395_0* Context_get_ClientWriteKey_m2094953427_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_ClientWriteKey(System.Byte[])
extern "C"  void Context_set_ClientWriteKey_m409290444_0 (Context_t_1281777657_0 * __this, ByteU5BU5D_t_1238178395_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.Context::get_ServerWriteKey()
extern "C"  ByteU5BU5D_t_1238178395_0* Context_get_ServerWriteKey_m2037627211_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_ServerWriteKey(System.Byte[])
extern "C"  void Context_set_ServerWriteKey_m_1656839084_0 (Context_t_1281777657_0 * __this, ByteU5BU5D_t_1238178395_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.Context::get_ClientWriteIV()
extern "C"  ByteU5BU5D_t_1238178395_0* Context_get_ClientWriteIV_m621691963_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_ClientWriteIV(System.Byte[])
extern "C"  void Context_set_ClientWriteIV_m_361910088_0 (Context_t_1281777657_0 * __this, ByteU5BU5D_t_1238178395_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.Context::get_ServerWriteIV()
extern "C"  ByteU5BU5D_t_1238178395_0* Context_get_ServerWriteIV_m1451126723_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_ServerWriteIV(System.Byte[])
extern "C"  void Context_set_ServerWriteIV_m_844201424_0 (Context_t_1281777657_0 * __this, ByteU5BU5D_t_1238178395_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.RecordProtocol Mono.Security.Protocol.Tls.Context::get_RecordProtocol()
extern "C"  RecordProtocol_t_2004860751_0 * Context_get_RecordProtocol_m_1071571157_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::set_RecordProtocol(Mono.Security.Protocol.Tls.RecordProtocol)
extern "C"  void Context_set_RecordProtocol_m1649539496_0 (Context_t_1281777657_0 * __this, RecordProtocol_t_2004860751_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Protocol.Tls.Context::GetUnixTime()
extern "C"  int32_t Context_GetUnixTime_m545141264_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.Context::GetSecureRandomBytes(System.Int32)
extern "C"  ByteU5BU5D_t_1238178395_0* Context_GetSecureRandomBytes_m_1069491541_0 (Context_t_1281777657_0 * __this, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::Clear()
extern "C"  void Context_Clear_m2073665242_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::ClearKeyInfo()
extern "C"  void Context_ClearKeyInfo_m_2021888683_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.SecurityProtocolType Mono.Security.Protocol.Tls.Context::DecodeProtocolCode(System.Int16)
extern "C"  int32_t Context_DecodeProtocolCode_m1937919790_0 (Context_t_1281777657_0 * __this, int16_t ___code, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::ChangeProtocol(System.Int16)
extern "C"  void Context_ChangeProtocol_m460386024_0 (Context_t_1281777657_0 * __this, int16_t ___protocol, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.SecurityParameters Mono.Security.Protocol.Tls.Context::get_Current()
extern "C"  SecurityParameters_t_1142410254_0 * Context_get_Current_m_2047309318_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.SecurityParameters Mono.Security.Protocol.Tls.Context::get_Negotiating()
extern "C"  SecurityParameters_t_1142410254_0 * Context_get_Negotiating_m622190524_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.SecurityParameters Mono.Security.Protocol.Tls.Context::get_Read()
extern "C"  SecurityParameters_t_1142410254_0 * Context_get_Read_m_600021161_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.SecurityParameters Mono.Security.Protocol.Tls.Context::get_Write()
extern "C"  SecurityParameters_t_1142410254_0 * Context_get_Write_m_898133280_0 (Context_t_1281777657_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::StartSwitchingSecurityParameters(System.Boolean)
extern "C"  void Context_StartSwitchingSecurityParameters_m271202242_0 (Context_t_1281777657_0 * __this, bool ___client, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.Context::EndSwitchingSecurityParameters(System.Boolean)
extern "C"  void Context_EndSwitchingSecurityParameters_m284941993_0 (Context_t_1281777657_0 * __this, bool ___client, const MethodInfo* method) IL2CPP_METHOD_ATTR;
