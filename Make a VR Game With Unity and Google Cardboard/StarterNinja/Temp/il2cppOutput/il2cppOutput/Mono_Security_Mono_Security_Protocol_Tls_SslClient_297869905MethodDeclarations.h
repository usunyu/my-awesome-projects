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

// Mono.Security.Protocol.Tls.SslClientStream
struct SslClientStream_t_297869905_0;
// System.IO.Stream
struct Stream_t463444077_0;
// System.String
struct String_t;
// System.Security.Cryptography.X509Certificates.X509Certificate
struct X509Certificate_t1524084820_0;
// System.Security.Cryptography.X509Certificates.X509CertificateCollection
struct X509CertificateCollection_t_798278404_0;
// Mono.Security.Protocol.Tls.CertificateValidationCallback
struct CertificateValidationCallback_t_31047123_0;
// Mono.Security.Protocol.Tls.CertificateSelectionCallback
struct CertificateSelectionCallback_t_1508760126_0;
// Mono.Security.Protocol.Tls.PrivateKeySelectionCallback
struct PrivateKeySelectionCallback_t_1430962739_0;
// Mono.Security.Protocol.Tls.CertificateValidationCallback2
struct CertificateValidationCallback2_t_962460763_0;
// System.IAsyncResult
struct IAsyncResult_t_1647744885_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;
// System.Object
struct Object_t;
// Mono.Security.Protocol.Tls.ValidationResult
struct ValidationResult_t1825158814_0;
// Mono.Security.X509.X509CertificateCollection
struct X509CertificateCollection_t15320292_0;
// System.Int32[]
struct Int32U5BU5D_t1872284309_0;
// System.Security.Cryptography.AsymmetricAlgorithm
struct AsymmetricAlgorithm_t1451338986_0;

#include "codegen/il2cpp-codegen.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_SecurityP_942303750.h"

// System.Void Mono.Security.Protocol.Tls.SslClientStream::.ctor(System.IO.Stream,System.String,System.Boolean)
extern "C"  void SslClientStream__ctor_m99328227_0 (SslClientStream_t_297869905_0 * __this, Stream_t463444077_0 * ___stream, String_t* ___targetHost, bool ___ownsStream, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslClientStream::.ctor(System.IO.Stream,System.String,System.Security.Cryptography.X509Certificates.X509Certificate)
extern "C"  void SslClientStream__ctor_m_464598002_0 (SslClientStream_t_297869905_0 * __this, Stream_t463444077_0 * ___stream, String_t* ___targetHost, X509Certificate_t1524084820_0 * ___clientCertificate, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslClientStream::.ctor(System.IO.Stream,System.String,System.Security.Cryptography.X509Certificates.X509CertificateCollection)
extern "C"  void SslClientStream__ctor_m_1224032560_0 (SslClientStream_t_297869905_0 * __this, Stream_t463444077_0 * ___stream, String_t* ___targetHost, X509CertificateCollection_t_798278404_0 * ___clientCertificates, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslClientStream::.ctor(System.IO.Stream,System.String,System.Boolean,Mono.Security.Protocol.Tls.SecurityProtocolType)
extern "C"  void SslClientStream__ctor_m1812308023_0 (SslClientStream_t_297869905_0 * __this, Stream_t463444077_0 * ___stream, String_t* ___targetHost, bool ___ownsStream, int32_t ___securityProtocolType, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslClientStream::.ctor(System.IO.Stream,System.String,System.Boolean,Mono.Security.Protocol.Tls.SecurityProtocolType,System.Security.Cryptography.X509Certificates.X509CertificateCollection)
extern "C"  void SslClientStream__ctor_m_1411483987_0 (SslClientStream_t_297869905_0 * __this, Stream_t463444077_0 * ___stream, String_t* ___targetHost, bool ___ownsStream, int32_t ___securityProtocolType, X509CertificateCollection_t_798278404_0 * ___clientCertificates, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslClientStream::add_ServerCertValidation(Mono.Security.Protocol.Tls.CertificateValidationCallback)
extern "C"  void SslClientStream_add_ServerCertValidation_m_198104468_0 (SslClientStream_t_297869905_0 * __this, CertificateValidationCallback_t_31047123_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslClientStream::remove_ServerCertValidation(Mono.Security.Protocol.Tls.CertificateValidationCallback)
extern "C"  void SslClientStream_remove_ServerCertValidation_m_2023630287_0 (SslClientStream_t_297869905_0 * __this, CertificateValidationCallback_t_31047123_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslClientStream::add_ClientCertSelection(Mono.Security.Protocol.Tls.CertificateSelectionCallback)
extern "C"  void SslClientStream_add_ClientCertSelection_m_696328242_0 (SslClientStream_t_297869905_0 * __this, CertificateSelectionCallback_t_1508760126_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslClientStream::remove_ClientCertSelection(Mono.Security.Protocol.Tls.CertificateSelectionCallback)
extern "C"  void SslClientStream_remove_ClientCertSelection_m_952976173_0 (SslClientStream_t_297869905_0 * __this, CertificateSelectionCallback_t_1508760126_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslClientStream::add_PrivateKeySelection(Mono.Security.Protocol.Tls.PrivateKeySelectionCallback)
extern "C"  void SslClientStream_add_PrivateKeySelection_m_538696120_0 (SslClientStream_t_297869905_0 * __this, PrivateKeySelectionCallback_t_1430962739_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslClientStream::remove_PrivateKeySelection(Mono.Security.Protocol.Tls.PrivateKeySelectionCallback)
extern "C"  void SslClientStream_remove_PrivateKeySelection_m7214243_0 (SslClientStream_t_297869905_0 * __this, PrivateKeySelectionCallback_t_1430962739_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslClientStream::add_ServerCertValidation2(Mono.Security.Protocol.Tls.CertificateValidationCallback2)
extern "C"  void SslClientStream_add_ServerCertValidation2_m_1574291882_0 (SslClientStream_t_297869905_0 * __this, CertificateValidationCallback2_t_962460763_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslClientStream::remove_ServerCertValidation2(Mono.Security.Protocol.Tls.CertificateValidationCallback2)
extern "C"  void SslClientStream_remove_ServerCertValidation2_m737020123_0 (SslClientStream_t_297869905_0 * __this, CertificateValidationCallback2_t_962460763_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.IO.Stream Mono.Security.Protocol.Tls.SslClientStream::get_InputBuffer()
extern "C"  Stream_t463444077_0 * SslClientStream_get_InputBuffer_m_89856456_0 (SslClientStream_t_297869905_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509CertificateCollection Mono.Security.Protocol.Tls.SslClientStream::get_ClientCertificates()
extern "C"  X509CertificateCollection_t_798278404_0 * SslClientStream_get_ClientCertificates_m_213688470_0 (SslClientStream_t_297869905_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509Certificate Mono.Security.Protocol.Tls.SslClientStream::get_SelectedClientCertificate()
extern "C"  X509Certificate_t1524084820_0 * SslClientStream_get_SelectedClientCertificate_m_42079822_0 (SslClientStream_t_297869905_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.CertificateValidationCallback Mono.Security.Protocol.Tls.SslClientStream::get_ServerCertValidationDelegate()
extern "C"  CertificateValidationCallback_t_31047123_0 * SslClientStream_get_ServerCertValidationDelegate_m459420051_0 (SslClientStream_t_297869905_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslClientStream::set_ServerCertValidationDelegate(Mono.Security.Protocol.Tls.CertificateValidationCallback)
extern "C"  void SslClientStream_set_ServerCertValidationDelegate_m772375792_0 (SslClientStream_t_297869905_0 * __this, CertificateValidationCallback_t_31047123_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.CertificateSelectionCallback Mono.Security.Protocol.Tls.SslClientStream::get_ClientCertSelectionDelegate()
extern "C"  CertificateSelectionCallback_t_1508760126_0 * SslClientStream_get_ClientCertSelectionDelegate_m_1032245301_0 (SslClientStream_t_297869905_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslClientStream::set_ClientCertSelectionDelegate(Mono.Security.Protocol.Tls.CertificateSelectionCallback)
extern "C"  void SslClientStream_set_ClientCertSelectionDelegate_m1954811816_0 (SslClientStream_t_297869905_0 * __this, CertificateSelectionCallback_t_1508760126_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.PrivateKeySelectionCallback Mono.Security.Protocol.Tls.SslClientStream::get_PrivateKeyCertSelectionDelegate()
extern "C"  PrivateKeySelectionCallback_t_1430962739_0 * SslClientStream_get_PrivateKeyCertSelectionDelegate_m_989285915_0 (SslClientStream_t_297869905_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslClientStream::set_PrivateKeyCertSelectionDelegate(Mono.Security.Protocol.Tls.PrivateKeySelectionCallback)
extern "C"  void SslClientStream_set_PrivateKeyCertSelectionDelegate_m_478031638_0 (SslClientStream_t_297869905_0 * __this, PrivateKeySelectionCallback_t_1430962739_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslClientStream::Finalize()
extern "C"  void SslClientStream_Finalize_m1289121787_0 (SslClientStream_t_297869905_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslClientStream::Dispose(System.Boolean)
extern "C"  void SslClientStream_Dispose_m_2086829061_0 (SslClientStream_t_297869905_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.IAsyncResult Mono.Security.Protocol.Tls.SslClientStream::OnBeginNegotiateHandshake(System.AsyncCallback,System.Object)
extern "C"  Object_t * SslClientStream_OnBeginNegotiateHandshake_m_736375344_0 (SslClientStream_t_297869905_0 * __this, AsyncCallback_t_266361018_0 * ___callback, Object_t * ___state, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslClientStream::SafeReceiveRecord(System.IO.Stream)
extern "C"  void SslClientStream_SafeReceiveRecord_m_114857597_0 (SslClientStream_t_297869905_0 * __this, Stream_t463444077_0 * ___s, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslClientStream::OnNegotiateHandshakeCallback(System.IAsyncResult)
extern "C"  void SslClientStream_OnNegotiateHandshakeCallback_m_1383057975_0 (SslClientStream_t_297869905_0 * __this, Object_t * ___asyncResult, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509Certificate Mono.Security.Protocol.Tls.SslClientStream::OnLocalCertificateSelection(System.Security.Cryptography.X509Certificates.X509CertificateCollection,System.Security.Cryptography.X509Certificates.X509Certificate,System.String,System.Security.Cryptography.X509Certificates.X509CertificateCollection)
extern "C"  X509Certificate_t1524084820_0 * SslClientStream_OnLocalCertificateSelection_m_556626377_0 (SslClientStream_t_297869905_0 * __this, X509CertificateCollection_t_798278404_0 * ___clientCertificates, X509Certificate_t1524084820_0 * ___serverCertificate, String_t* ___targetHost, X509CertificateCollection_t_798278404_0 * ___serverRequestedCertificates, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.SslClientStream::get_HaveRemoteValidation2Callback()
extern "C"  bool SslClientStream_get_HaveRemoteValidation2Callback_m712645822_0 (SslClientStream_t_297869905_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.ValidationResult Mono.Security.Protocol.Tls.SslClientStream::OnRemoteCertificateValidation2(Mono.Security.X509.X509CertificateCollection)
extern "C"  ValidationResult_t1825158814_0 * SslClientStream_OnRemoteCertificateValidation2_m549297777_0 (SslClientStream_t_297869905_0 * __this, X509CertificateCollection_t15320292_0 * ___collection, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.SslClientStream::OnRemoteCertificateValidation(System.Security.Cryptography.X509Certificates.X509Certificate,System.Int32[])
extern "C"  bool SslClientStream_OnRemoteCertificateValidation_m_1299595075_0 (SslClientStream_t_297869905_0 * __this, X509Certificate_t1524084820_0 * ___certificate, Int32U5BU5D_t1872284309_0* ___errors, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.SslClientStream::RaiseServerCertificateValidation(System.Security.Cryptography.X509Certificates.X509Certificate,System.Int32[])
extern "C"  bool SslClientStream_RaiseServerCertificateValidation_m738622279_0 (SslClientStream_t_297869905_0 * __this, X509Certificate_t1524084820_0 * ___certificate, Int32U5BU5D_t1872284309_0* ___certificateErrors, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.ValidationResult Mono.Security.Protocol.Tls.SslClientStream::RaiseServerCertificateValidation2(Mono.Security.X509.X509CertificateCollection)
extern "C"  ValidationResult_t1825158814_0 * SslClientStream_RaiseServerCertificateValidation2_m1222389749_0 (SslClientStream_t_297869905_0 * __this, X509CertificateCollection_t15320292_0 * ___collection, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509Certificate Mono.Security.Protocol.Tls.SslClientStream::RaiseClientCertificateSelection(System.Security.Cryptography.X509Certificates.X509CertificateCollection,System.Security.Cryptography.X509Certificates.X509Certificate,System.String,System.Security.Cryptography.X509Certificates.X509CertificateCollection)
extern "C"  X509Certificate_t1524084820_0 * SslClientStream_RaiseClientCertificateSelection_m_16755700_0 (SslClientStream_t_297869905_0 * __this, X509CertificateCollection_t_798278404_0 * ___clientCertificates, X509Certificate_t1524084820_0 * ___serverCertificate, String_t* ___targetHost, X509CertificateCollection_t_798278404_0 * ___serverRequestedCertificates, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.AsymmetricAlgorithm Mono.Security.Protocol.Tls.SslClientStream::OnLocalPrivateKeySelection(System.Security.Cryptography.X509Certificates.X509Certificate,System.String)
extern "C"  AsymmetricAlgorithm_t1451338986_0 * SslClientStream_OnLocalPrivateKeySelection_m_1033400412_0 (SslClientStream_t_297869905_0 * __this, X509Certificate_t1524084820_0 * ___certificate, String_t* ___targetHost, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.AsymmetricAlgorithm Mono.Security.Protocol.Tls.SslClientStream::RaisePrivateKeySelection(System.Security.Cryptography.X509Certificates.X509Certificate,System.String)
extern "C"  AsymmetricAlgorithm_t1451338986_0 * SslClientStream_RaisePrivateKeySelection_m_1030827132_0 (SslClientStream_t_297869905_0 * __this, X509Certificate_t1524084820_0 * ___certificate, String_t* ___targetHost, const MethodInfo* method) IL2CPP_METHOD_ATTR;
