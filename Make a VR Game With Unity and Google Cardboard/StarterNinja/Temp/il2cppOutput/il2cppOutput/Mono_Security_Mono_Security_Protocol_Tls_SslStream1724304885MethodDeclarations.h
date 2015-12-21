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

// Mono.Security.Protocol.Tls.SslStreamBase
struct SslStreamBase_t1724304885_0;
// System.IO.Stream
struct Stream_t463444077_0;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.Security.Cryptography.X509Certificates.X509Certificate
struct X509Certificate_t1524084820_0;
// System.Security.Cryptography.X509Certificates.X509CertificateCollection
struct X509CertificateCollection_t_798278404_0;
// System.String
struct String_t;
// System.Int32[]
struct Int32U5BU5D_t1872284309_0;
// Mono.Security.Protocol.Tls.ValidationResult
struct ValidationResult_t1825158814_0;
// Mono.Security.X509.X509CertificateCollection
struct X509CertificateCollection_t15320292_0;
// System.Security.Cryptography.AsymmetricAlgorithm
struct AsymmetricAlgorithm_t1451338986_0;
// Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult
struct InternalAsyncResult_t_104888446_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;
// System.Object
struct Object_t;

#include "codegen/il2cpp-codegen.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_CipherAl_2011610538.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_HashAlgor_103851469.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_ExchangeAl701975358.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_SecurityP_942303750.h"
#include "mscorlib_System_IO_SeekOrigin_1060652501.h"

// System.Void Mono.Security.Protocol.Tls.SslStreamBase::.ctor(System.IO.Stream,System.Boolean)
extern "C"  void SslStreamBase__ctor_m1932094885_0 (SslStreamBase_t1724304885_0 * __this, Stream_t463444077_0 * ___stream, bool ___ownsStream, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase::.cctor()
extern "C"  void SslStreamBase__cctor_m_270180980_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase::AsyncHandshakeCallback(System.IAsyncResult)
extern "C"  void SslStreamBase_AsyncHandshakeCallback_m_1295367072_0 (SslStreamBase_t1724304885_0 * __this, Object_t * ___asyncResult, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.SslStreamBase::get_MightNeedHandshake()
extern "C"  bool SslStreamBase_get_MightNeedHandshake_m_808451932_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase::NegotiateHandshake()
extern "C"  void SslStreamBase_NegotiateHandshake_m_19015620_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509Certificate Mono.Security.Protocol.Tls.SslStreamBase::RaiseLocalCertificateSelection(System.Security.Cryptography.X509Certificates.X509CertificateCollection,System.Security.Cryptography.X509Certificates.X509Certificate,System.String,System.Security.Cryptography.X509Certificates.X509CertificateCollection)
extern "C"  X509Certificate_t1524084820_0 * SslStreamBase_RaiseLocalCertificateSelection_m_1246556624_0 (SslStreamBase_t1724304885_0 * __this, X509CertificateCollection_t_798278404_0 * ___certificates, X509Certificate_t1524084820_0 * ___remoteCertificate, String_t* ___targetHost, X509CertificateCollection_t_798278404_0 * ___requestedCertificates, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.SslStreamBase::RaiseRemoteCertificateValidation(System.Security.Cryptography.X509Certificates.X509Certificate,System.Int32[])
extern "C"  bool SslStreamBase_RaiseRemoteCertificateValidation_m1070332522_0 (SslStreamBase_t1724304885_0 * __this, X509Certificate_t1524084820_0 * ___certificate, Int32U5BU5D_t1872284309_0* ___errors, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.ValidationResult Mono.Security.Protocol.Tls.SslStreamBase::RaiseRemoteCertificateValidation2(Mono.Security.X509.X509CertificateCollection)
extern "C"  ValidationResult_t1825158814_0 * SslStreamBase_RaiseRemoteCertificateValidation2_m_1590680846_0 (SslStreamBase_t1724304885_0 * __this, X509CertificateCollection_t15320292_0 * ___collection, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.AsymmetricAlgorithm Mono.Security.Protocol.Tls.SslStreamBase::RaiseLocalPrivateKeySelection(System.Security.Cryptography.X509Certificates.X509Certificate,System.String)
extern "C"  AsymmetricAlgorithm_t1451338986_0 * SslStreamBase_RaiseLocalPrivateKeySelection_m_1929457609_0 (SslStreamBase_t1724304885_0 * __this, X509Certificate_t1524084820_0 * ___certificate, String_t* ___targetHost, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.SslStreamBase::get_CheckCertRevocationStatus()
extern "C"  bool SslStreamBase_get_CheckCertRevocationStatus_m_1129810172_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase::set_CheckCertRevocationStatus(System.Boolean)
extern "C"  void SslStreamBase_set_CheckCertRevocationStatus_m_1833092715_0 (SslStreamBase_t1724304885_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.CipherAlgorithmType Mono.Security.Protocol.Tls.SslStreamBase::get_CipherAlgorithm()
extern "C"  int32_t SslStreamBase_get_CipherAlgorithm_m_208213733_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Protocol.Tls.SslStreamBase::get_CipherStrength()
extern "C"  int32_t SslStreamBase_get_CipherStrength_m_2089425792_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.HashAlgorithmType Mono.Security.Protocol.Tls.SslStreamBase::get_HashAlgorithm()
extern "C"  int32_t SslStreamBase_get_HashAlgorithm_m_589084971_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Protocol.Tls.SslStreamBase::get_HashStrength()
extern "C"  int32_t SslStreamBase_get_HashStrength_m769179779_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Protocol.Tls.SslStreamBase::get_KeyExchangeStrength()
extern "C"  int32_t SslStreamBase_get_KeyExchangeStrength_m_205386479_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.ExchangeAlgorithmType Mono.Security.Protocol.Tls.SslStreamBase::get_KeyExchangeAlgorithm()
extern "C"  int32_t SslStreamBase_get_KeyExchangeAlgorithm_m_1285655024_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.SecurityProtocolType Mono.Security.Protocol.Tls.SslStreamBase::get_SecurityProtocol()
extern "C"  int32_t SslStreamBase_get_SecurityProtocol_m_1507611105_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509Certificate Mono.Security.Protocol.Tls.SslStreamBase::get_ServerCertificate()
extern "C"  X509Certificate_t1524084820_0 * SslStreamBase_get_ServerCertificate_m2089787471_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.X509.X509CertificateCollection Mono.Security.Protocol.Tls.SslStreamBase::get_ServerCertificates()
extern "C"  X509CertificateCollection_t15320292_0 * SslStreamBase_get_ServerCertificates_m925494264_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.SslStreamBase::BeginNegotiateHandshake(Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult)
extern "C"  bool SslStreamBase_BeginNegotiateHandshake_m_1296205553_0 (SslStreamBase_t1724304885_0 * __this, InternalAsyncResult_t_104888446_0 * ___asyncResult, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase::EndNegotiateHandshake(Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult)
extern "C"  void SslStreamBase_EndNegotiateHandshake_m_1892543281_0 (SslStreamBase_t1724304885_0 * __this, InternalAsyncResult_t_104888446_0 * ___asyncResult, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.IAsyncResult Mono.Security.Protocol.Tls.SslStreamBase::BeginRead(System.Byte[],System.Int32,System.Int32,System.AsyncCallback,System.Object)
extern "C"  Object_t * SslStreamBase_BeginRead_m1224799779_0 (SslStreamBase_t1724304885_0 * __this, ByteU5BU5D_t_1238178395_0* ___buffer, int32_t ___offset, int32_t ___count, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___state, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase::InternalBeginRead(Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult)
extern "C"  void SslStreamBase_InternalBeginRead_m_1629601891_0 (SslStreamBase_t1724304885_0 * __this, InternalAsyncResult_t_104888446_0 * ___asyncResult, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase::InternalReadCallback(System.IAsyncResult)
extern "C"  void SslStreamBase_InternalReadCallback_m_259722808_0 (SslStreamBase_t1724304885_0 * __this, Object_t * ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase::InternalBeginWrite(Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult)
extern "C"  void SslStreamBase_InternalBeginWrite_m_1035710830_0 (SslStreamBase_t1724304885_0 * __this, InternalAsyncResult_t_104888446_0 * ___asyncResult, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase::InternalWriteCallback(System.IAsyncResult)
extern "C"  void SslStreamBase_InternalWriteCallback_m1764266237_0 (SslStreamBase_t1724304885_0 * __this, Object_t * ___ar, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.IAsyncResult Mono.Security.Protocol.Tls.SslStreamBase::BeginWrite(System.Byte[],System.Int32,System.Int32,System.AsyncCallback,System.Object)
extern "C"  Object_t * SslStreamBase_BeginWrite_m1786584070_0 (SslStreamBase_t1724304885_0 * __this, ByteU5BU5D_t_1238178395_0* ___buffer, int32_t ___offset, int32_t ___count, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___state, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Protocol.Tls.SslStreamBase::EndRead(System.IAsyncResult)
extern "C"  int32_t SslStreamBase_EndRead_m29185563_0 (SslStreamBase_t1724304885_0 * __this, Object_t * ___asyncResult, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase::EndWrite(System.IAsyncResult)
extern "C"  void SslStreamBase_EndWrite_m_1478612516_0 (SslStreamBase_t1724304885_0 * __this, Object_t * ___asyncResult, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase::Close()
extern "C"  void SslStreamBase_Close_m_637609129_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase::Flush()
extern "C"  void SslStreamBase_Flush_m2030445923_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Protocol.Tls.SslStreamBase::Read(System.Byte[])
extern "C"  int32_t SslStreamBase_Read_m558115208_0 (SslStreamBase_t1724304885_0 * __this, ByteU5BU5D_t_1238178395_0* ___buffer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Protocol.Tls.SslStreamBase::Read(System.Byte[],System.Int32,System.Int32)
extern "C"  int32_t SslStreamBase_Read_m_1489656600_0 (SslStreamBase_t1724304885_0 * __this, ByteU5BU5D_t_1238178395_0* ___buffer, int32_t ___offset, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 Mono.Security.Protocol.Tls.SslStreamBase::Seek(System.Int64,System.IO.SeekOrigin)
extern "C"  int64_t SslStreamBase_Seek_m_1228631607_0 (SslStreamBase_t1724304885_0 * __this, int64_t ___offset, int32_t ___origin, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase::SetLength(System.Int64)
extern "C"  void SslStreamBase_SetLength_m1474200217_0 (SslStreamBase_t1724304885_0 * __this, int64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase::Write(System.Byte[])
extern "C"  void SslStreamBase_Write_m1278747915_0 (SslStreamBase_t1724304885_0 * __this, ByteU5BU5D_t_1238178395_0* ___buffer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase::Write(System.Byte[],System.Int32,System.Int32)
extern "C"  void SslStreamBase_Write_m139555499_0 (SslStreamBase_t1724304885_0 * __this, ByteU5BU5D_t_1238178395_0* ___buffer, int32_t ___offset, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.SslStreamBase::get_CanRead()
extern "C"  bool SslStreamBase_get_CanRead_m780009774_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.SslStreamBase::get_CanSeek()
extern "C"  bool SslStreamBase_get_CanSeek_m808764816_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.SslStreamBase::get_CanWrite()
extern "C"  bool SslStreamBase_get_CanWrite_m_1066847255_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 Mono.Security.Protocol.Tls.SslStreamBase::get_Length()
extern "C"  int64_t SslStreamBase_get_Length_m_618181317_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 Mono.Security.Protocol.Tls.SslStreamBase::get_Position()
extern "C"  int64_t SslStreamBase_get_Position_m_1145257538_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase::set_Position(System.Int64)
extern "C"  void SslStreamBase_set_Position_m718728987_0 (SslStreamBase_t1724304885_0 * __this, int64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase::Finalize()
extern "C"  void SslStreamBase_Finalize_m1889580673_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase::Dispose(System.Boolean)
extern "C"  void SslStreamBase_Dispose_m927762229_0 (SslStreamBase_t1724304885_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase::resetBuffer()
extern "C"  void SslStreamBase_resetBuffer_m54784942_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase::checkDisposed()
extern "C"  void SslStreamBase_checkDisposed_m_1421711988_0 (SslStreamBase_t1724304885_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
