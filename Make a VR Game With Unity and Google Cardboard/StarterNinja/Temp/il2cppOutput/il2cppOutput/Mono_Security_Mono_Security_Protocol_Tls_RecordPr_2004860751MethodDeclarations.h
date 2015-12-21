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

// Mono.Security.Protocol.Tls.RecordProtocol
struct RecordProtocol_t_2004860751_0;
// System.IO.Stream
struct Stream_t463444077_0;
// Mono.Security.Protocol.Tls.Context
struct Context_t_1281777657_0;
// Mono.Security.Protocol.Tls.Handshake.HandshakeMessage
struct HandshakeMessage_t1568425967_0;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;
// System.Object
struct Object_t;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// Mono.Security.Protocol.Tls.Alert
struct Alert_t103983540_0;
// Mono.Security.Protocol.Tls.CipherSuite
struct CipherSuite_t_1835594235_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_Handshak_1520136110.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_AlertLev_1550454224.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_AlertDescr843131304.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_ContentTyp_45887061.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_SecurityP_942303750.h"

// System.Void Mono.Security.Protocol.Tls.RecordProtocol::.ctor(System.IO.Stream,Mono.Security.Protocol.Tls.Context)
extern "C"  void RecordProtocol__ctor_m680122215_0 (RecordProtocol_t_2004860751_0 * __this, Stream_t463444077_0 * ___innerStream, Context_t_1281777657_0 * ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.RecordProtocol::.cctor()
extern "C"  void RecordProtocol__cctor_m1295387214_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.Context Mono.Security.Protocol.Tls.RecordProtocol::get_Context()
extern "C"  Context_t_1281777657_0 * RecordProtocol_get_Context_m1960772337_0 (RecordProtocol_t_2004860751_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.RecordProtocol::SendRecord(Mono.Security.Protocol.Tls.Handshake.HandshakeType)
extern "C"  void RecordProtocol_SendRecord_m_1603526038_0 (RecordProtocol_t_2004860751_0 * __this, uint8_t ___type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.RecordProtocol::ProcessChangeCipherSpec()
extern "C"  void RecordProtocol_ProcessChangeCipherSpec_m1060708066_0 (RecordProtocol_t_2004860751_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.Handshake.HandshakeMessage Mono.Security.Protocol.Tls.RecordProtocol::GetMessage(Mono.Security.Protocol.Tls.Handshake.HandshakeType)
extern "C"  HandshakeMessage_t1568425967_0 * RecordProtocol_GetMessage_m_1305434468_0 (RecordProtocol_t_2004860751_0 * __this, uint8_t ___type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.IAsyncResult Mono.Security.Protocol.Tls.RecordProtocol::BeginReceiveRecord(System.IO.Stream,System.AsyncCallback,System.Object)
extern "C"  Object_t * RecordProtocol_BeginReceiveRecord_m_1810502417_0 (RecordProtocol_t_2004860751_0 * __this, Stream_t463444077_0 * ___record, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___state, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.RecordProtocol::InternalReceiveRecordCallback(System.IAsyncResult)
extern "C"  void RecordProtocol_InternalReceiveRecordCallback_m1163093802_0 (RecordProtocol_t_2004860751_0 * __this, Object_t * ___asyncResult, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.RecordProtocol::EndReceiveRecord(System.IAsyncResult)
extern "C"  ByteU5BU5D_t_1238178395_0* RecordProtocol_EndReceiveRecord_m_1450263697_0 (RecordProtocol_t_2004860751_0 * __this, Object_t * ___asyncResult, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.RecordProtocol::ReceiveRecord(System.IO.Stream)
extern "C"  ByteU5BU5D_t_1238178395_0* RecordProtocol_ReceiveRecord_m1131958450_0 (RecordProtocol_t_2004860751_0 * __this, Stream_t463444077_0 * ___record, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.RecordProtocol::ReadRecordBuffer(System.Int32,System.IO.Stream)
extern "C"  ByteU5BU5D_t_1238178395_0* RecordProtocol_ReadRecordBuffer_m1367596554_0 (RecordProtocol_t_2004860751_0 * __this, int32_t ___contentType, Stream_t463444077_0 * ___record, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.RecordProtocol::ReadClientHelloV2(System.IO.Stream)
extern "C"  ByteU5BU5D_t_1238178395_0* RecordProtocol_ReadClientHelloV2_m_170303733_0 (RecordProtocol_t_2004860751_0 * __this, Stream_t463444077_0 * ___record, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.RecordProtocol::ReadStandardRecordBuffer(System.IO.Stream)
extern "C"  ByteU5BU5D_t_1238178395_0* RecordProtocol_ReadStandardRecordBuffer_m1386517462_0 (RecordProtocol_t_2004860751_0 * __this, Stream_t463444077_0 * ___record, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.RecordProtocol::ProcessAlert(Mono.Security.Protocol.Tls.AlertLevel,Mono.Security.Protocol.Tls.AlertDescription)
extern "C"  void RecordProtocol_ProcessAlert_m_279438344_0 (RecordProtocol_t_2004860751_0 * __this, uint8_t ___alertLevel, uint8_t ___alertDesc, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.RecordProtocol::SendAlert(Mono.Security.Protocol.Tls.AlertDescription)
extern "C"  void RecordProtocol_SendAlert_m_1780022405_0 (RecordProtocol_t_2004860751_0 * __this, uint8_t ___description, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.RecordProtocol::SendAlert(Mono.Security.Protocol.Tls.AlertLevel,Mono.Security.Protocol.Tls.AlertDescription)
extern "C"  void RecordProtocol_SendAlert_m1748450521_0 (RecordProtocol_t_2004860751_0 * __this, uint8_t ___level, uint8_t ___description, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.RecordProtocol::SendAlert(Mono.Security.Protocol.Tls.Alert)
extern "C"  void RecordProtocol_SendAlert_m1661652283_0 (RecordProtocol_t_2004860751_0 * __this, Alert_t103983540_0 * ___alert, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.RecordProtocol::SendChangeCipherSpec()
extern "C"  void RecordProtocol_SendChangeCipherSpec_m1492403331_0 (RecordProtocol_t_2004860751_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.IAsyncResult Mono.Security.Protocol.Tls.RecordProtocol::BeginSendRecord(Mono.Security.Protocol.Tls.Handshake.HandshakeType,System.AsyncCallback,System.Object)
extern "C"  Object_t * RecordProtocol_BeginSendRecord_m_220307165_0 (RecordProtocol_t_2004860751_0 * __this, uint8_t ___handshakeType, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___state, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.RecordProtocol::InternalSendRecordCallback(System.IAsyncResult)
extern "C"  void RecordProtocol_InternalSendRecordCallback_m396863619_0 (RecordProtocol_t_2004860751_0 * __this, Object_t * ___ar, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.IAsyncResult Mono.Security.Protocol.Tls.RecordProtocol::BeginSendRecord(Mono.Security.Protocol.Tls.ContentType,System.Byte[],System.AsyncCallback,System.Object)
extern "C"  Object_t * RecordProtocol_BeginSendRecord_m284507289_0 (RecordProtocol_t_2004860751_0 * __this, uint8_t ___contentType, ByteU5BU5D_t_1238178395_0* ___recordData, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___state, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.RecordProtocol::EndSendRecord(System.IAsyncResult)
extern "C"  void RecordProtocol_EndSendRecord_m1779126194_0 (RecordProtocol_t_2004860751_0 * __this, Object_t * ___asyncResult, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.RecordProtocol::SendRecord(Mono.Security.Protocol.Tls.ContentType,System.Byte[])
extern "C"  void RecordProtocol_SendRecord_m1964683252_0 (RecordProtocol_t_2004860751_0 * __this, uint8_t ___contentType, ByteU5BU5D_t_1238178395_0* ___recordData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.RecordProtocol::EncodeRecord(Mono.Security.Protocol.Tls.ContentType,System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* RecordProtocol_EncodeRecord_m_767360360_0 (RecordProtocol_t_2004860751_0 * __this, uint8_t ___contentType, ByteU5BU5D_t_1238178395_0* ___recordData, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.RecordProtocol::EncodeRecord(Mono.Security.Protocol.Tls.ContentType,System.Byte[],System.Int32,System.Int32)
extern "C"  ByteU5BU5D_t_1238178395_0* RecordProtocol_EncodeRecord_m1123568120_0 (RecordProtocol_t_2004860751_0 * __this, uint8_t ___contentType, ByteU5BU5D_t_1238178395_0* ___recordData, int32_t ___offset, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.RecordProtocol::encryptRecordFragment(Mono.Security.Protocol.Tls.ContentType,System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* RecordProtocol_encryptRecordFragment_m_623907389_0 (RecordProtocol_t_2004860751_0 * __this, uint8_t ___contentType, ByteU5BU5D_t_1238178395_0* ___fragment, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.RecordProtocol::decryptRecordFragment(Mono.Security.Protocol.Tls.ContentType,System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* RecordProtocol_decryptRecordFragment_m_1188495125_0 (RecordProtocol_t_2004860751_0 * __this, uint8_t ___contentType, ByteU5BU5D_t_1238178395_0* ___fragment, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.RecordProtocol::Compare(System.Byte[],System.Byte[])
extern "C"  bool RecordProtocol_Compare_m_2114195268_0 (RecordProtocol_t_2004860751_0 * __this, ByteU5BU5D_t_1238178395_0* ___array1, ByteU5BU5D_t_1238178395_0* ___array2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.RecordProtocol::ProcessCipherSpecV2Buffer(Mono.Security.Protocol.Tls.SecurityProtocolType,System.Byte[])
extern "C"  void RecordProtocol_ProcessCipherSpecV2Buffer_m572218255_0 (RecordProtocol_t_2004860751_0 * __this, int32_t ___protocol, ByteU5BU5D_t_1238178395_0* ___buffer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.CipherSuite Mono.Security.Protocol.Tls.RecordProtocol::MapV2CipherCode(System.String,System.Int32)
extern "C"  CipherSuite_t_1835594235_0 * RecordProtocol_MapV2CipherCode_m_1229567758_0 (RecordProtocol_t_2004860751_0 * __this, String_t* ___prefix, int32_t ___code, const MethodInfo* method) IL2CPP_METHOD_ATTR;
