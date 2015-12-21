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

// Mono.Security.Protocol.Tls.ClientRecordProtocol
struct ClientRecordProtocol_t611279708_0;
// System.IO.Stream
struct Stream_t463444077_0;
// Mono.Security.Protocol.Tls.ClientContext
struct ClientContext_t517167036_0;
// Mono.Security.Protocol.Tls.Handshake.HandshakeMessage
struct HandshakeMessage_t1568425967_0;
// Mono.Security.Protocol.Tls.TlsStream
struct TlsStream_t_1516681037_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;

#include "codegen/il2cpp-codegen.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_Handshak_1520136110.h"

// System.Void Mono.Security.Protocol.Tls.ClientRecordProtocol::.ctor(System.IO.Stream,Mono.Security.Protocol.Tls.ClientContext)
extern "C"  void ClientRecordProtocol__ctor_m_1259472835_0 (ClientRecordProtocol_t611279708_0 * __this, Stream_t463444077_0 * ___innerStream, ClientContext_t517167036_0 * ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.Handshake.HandshakeMessage Mono.Security.Protocol.Tls.ClientRecordProtocol::GetMessage(Mono.Security.Protocol.Tls.Handshake.HandshakeType)
extern "C"  HandshakeMessage_t1568425967_0 * ClientRecordProtocol_GetMessage_m_1776718969_0 (ClientRecordProtocol_t611279708_0 * __this, uint8_t ___type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.ClientRecordProtocol::ProcessHandshakeMessage(Mono.Security.Protocol.Tls.TlsStream)
extern "C"  void ClientRecordProtocol_ProcessHandshakeMessage_m_1188829700_0 (ClientRecordProtocol_t611279708_0 * __this, TlsStream_t_1516681037_0 * ___handMsg, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.Handshake.HandshakeMessage Mono.Security.Protocol.Tls.ClientRecordProtocol::createClientHandshakeMessage(Mono.Security.Protocol.Tls.Handshake.HandshakeType)
extern "C"  HandshakeMessage_t1568425967_0 * ClientRecordProtocol_createClientHandshakeMessage_m_861176211_0 (ClientRecordProtocol_t611279708_0 * __this, uint8_t ___type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.Handshake.HandshakeMessage Mono.Security.Protocol.Tls.ClientRecordProtocol::createServerHandshakeMessage(Mono.Security.Protocol.Tls.Handshake.HandshakeType,System.Byte[])
extern "C"  HandshakeMessage_t1568425967_0 * ClientRecordProtocol_createServerHandshakeMessage_m_1906224600_0 (ClientRecordProtocol_t611279708_0 * __this, uint8_t ___type, ByteU5BU5D_t_1238178395_0* ___buffer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
