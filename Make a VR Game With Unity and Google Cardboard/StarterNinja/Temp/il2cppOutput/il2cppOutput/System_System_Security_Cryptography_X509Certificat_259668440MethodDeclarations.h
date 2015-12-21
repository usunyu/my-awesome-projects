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

// System.Security.Cryptography.X509Certificates.X509Chain
struct X509Chain_t_259668440_0;
// System.Security.Cryptography.X509Certificates.X509ChainPolicy
struct X509ChainPolicy_t_1654318726_0;
// System.Security.Cryptography.X509Certificates.X509Certificate2
struct X509Certificate2_t1644507188_0;
// System.Security.Cryptography.X509Certificates.X509Store
struct X509Store_t_244520888_0;
// System.Security.Cryptography.X509Certificates.X509Certificate2Collection
struct X509Certificate2Collection_t_1899689486_0;
// System.Security.Cryptography.X509Certificates.X509ChainElement
struct X509ChainElement_t_1009110092_0;
// System.Security.Cryptography.AsymmetricAlgorithm
struct AsymmetricAlgorithm_t1451338986_0;
// System.String
struct String_t;
// Mono.Security.X509.X509Crl
struct X509Crl_t_956935956_0;
// Mono.Security.X509.X509Extension
struct X509Extension_t_556260338_0;
// Mono.Security.X509.X509Crl/X509CrlEntry
struct X509CrlEntry_t_830724962_0;

#include "codegen/il2cpp-codegen.h"
#include "System_System_Security_Cryptography_X509Certifica_1058320787.h"

// System.Void System.Security.Cryptography.X509Certificates.X509Chain::.ctor()
extern "C"  void X509Chain__ctor_m440780008_0 (X509Chain_t_259668440_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Chain::.ctor(System.Boolean)
extern "C"  void X509Chain__ctor_m_1407335329_0 (X509Chain_t_259668440_0 * __this, bool ___useMachineContext, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Chain::.cctor()
extern "C"  void X509Chain__cctor_m297182149_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509ChainPolicy System.Security.Cryptography.X509Certificates.X509Chain::get_ChainPolicy()
extern "C"  X509ChainPolicy_t_1654318726_0 * X509Chain_get_ChainPolicy_m_1153143153_0 (X509Chain_t_259668440_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Security.Cryptography.X509Certificates.X509Chain::Build(System.Security.Cryptography.X509Certificates.X509Certificate2)
extern "C"  bool X509Chain_Build_m417178512_0 (X509Chain_t_259668440_0 * __this, X509Certificate2_t1644507188_0 * ___certificate, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Chain::Reset()
extern "C"  void X509Chain_Reset_m_1912787051_0 (X509Chain_t_259668440_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509Store System.Security.Cryptography.X509Certificates.X509Chain::get_Roots()
extern "C"  X509Store_t_244520888_0 * X509Chain_get_Roots_m_193291841_0 (X509Chain_t_259668440_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509Store System.Security.Cryptography.X509Certificates.X509Chain::get_CertificateAuthorities()
extern "C"  X509Store_t_244520888_0 * X509Chain_get_CertificateAuthorities_m1238271486_0 (X509Chain_t_259668440_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509Certificate2Collection System.Security.Cryptography.X509Certificates.X509Chain::get_CertificateCollection()
extern "C"  X509Certificate2Collection_t_1899689486_0 * X509Chain_get_CertificateCollection_m1393875737_0 (X509Chain_t_259668440_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509ChainStatusFlags System.Security.Cryptography.X509Certificates.X509Chain::BuildChainFrom(System.Security.Cryptography.X509Certificates.X509Certificate2)
extern "C"  int32_t X509Chain_BuildChainFrom_m_1517945773_0 (X509Chain_t_259668440_0 * __this, X509Certificate2_t1644507188_0 * ___certificate, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509Certificate2 System.Security.Cryptography.X509Certificates.X509Chain::SelectBestFromCollection(System.Security.Cryptography.X509Certificates.X509Certificate2,System.Security.Cryptography.X509Certificates.X509Certificate2Collection)
extern "C"  X509Certificate2_t1644507188_0 * X509Chain_SelectBestFromCollection_m_1062882039_0 (X509Chain_t_259668440_0 * __this, X509Certificate2_t1644507188_0 * ___child, X509Certificate2Collection_t_1899689486_0 * ___c, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509Certificate2 System.Security.Cryptography.X509Certificates.X509Chain::FindParent(System.Security.Cryptography.X509Certificates.X509Certificate2)
extern "C"  X509Certificate2_t1644507188_0 * X509Chain_FindParent_m_1482772832_0 (X509Chain_t_259668440_0 * __this, X509Certificate2_t1644507188_0 * ___certificate, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Security.Cryptography.X509Certificates.X509Chain::IsChainComplete(System.Security.Cryptography.X509Certificates.X509Certificate2)
extern "C"  bool X509Chain_IsChainComplete_m_853030542_0 (X509Chain_t_259668440_0 * __this, X509Certificate2_t1644507188_0 * ___certificate, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Security.Cryptography.X509Certificates.X509Chain::IsSelfIssued(System.Security.Cryptography.X509Certificates.X509Certificate2)
extern "C"  bool X509Chain_IsSelfIssued_m397924845_0 (X509Chain_t_259668440_0 * __this, X509Certificate2_t1644507188_0 * ___certificate, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Chain::ValidateChain(System.Security.Cryptography.X509Certificates.X509ChainStatusFlags)
extern "C"  void X509Chain_ValidateChain_m976559422_0 (X509Chain_t_259668440_0 * __this, int32_t ___flag, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Chain::Process(System.Int32)
extern "C"  void X509Chain_Process_m940730694_0 (X509Chain_t_259668440_0 * __this, int32_t ___n, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Chain::PrepareForNextCertificate(System.Int32)
extern "C"  void X509Chain_PrepareForNextCertificate_m_1787915175_0 (X509Chain_t_259668440_0 * __this, int32_t ___n, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Chain::WrapUp()
extern "C"  void X509Chain_WrapUp_m_896113695_0 (X509Chain_t_259668440_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Chain::ProcessCertificateExtensions(System.Security.Cryptography.X509Certificates.X509ChainElement)
extern "C"  void X509Chain_ProcessCertificateExtensions_m1491797822_0 (X509Chain_t_259668440_0 * __this, X509ChainElement_t_1009110092_0 * ___element, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Security.Cryptography.X509Certificates.X509Chain::IsSignedWith(System.Security.Cryptography.X509Certificates.X509Certificate2,System.Security.Cryptography.AsymmetricAlgorithm)
extern "C"  bool X509Chain_IsSignedWith_m1198520936_0 (X509Chain_t_259668440_0 * __this, X509Certificate2_t1644507188_0 * ___signed, AsymmetricAlgorithm_t1451338986_0 * ___pubkey, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509Chain::GetSubjectKeyIdentifier(System.Security.Cryptography.X509Certificates.X509Certificate2)
extern "C"  String_t* X509Chain_GetSubjectKeyIdentifier_m2141872961_0 (X509Chain_t_259668440_0 * __this, X509Certificate2_t1644507188_0 * ___certificate, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509Chain::GetAuthorityKeyIdentifier(System.Security.Cryptography.X509Certificates.X509Certificate2)
extern "C"  String_t* X509Chain_GetAuthorityKeyIdentifier_m_834812150_0 (X509Chain_t_259668440_0 * __this, X509Certificate2_t1644507188_0 * ___certificate, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509Chain::GetAuthorityKeyIdentifier(Mono.Security.X509.X509Crl)
extern "C"  String_t* X509Chain_GetAuthorityKeyIdentifier_m_492051502_0 (X509Chain_t_259668440_0 * __this, X509Crl_t_956935956_0 * ___crl, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Security.Cryptography.X509Certificates.X509Chain::GetAuthorityKeyIdentifier(Mono.Security.X509.X509Extension)
extern "C"  String_t* X509Chain_GetAuthorityKeyIdentifier_m1262096688_0 (X509Chain_t_259668440_0 * __this, X509Extension_t_556260338_0 * ___ext, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Security.Cryptography.X509Certificates.X509Chain::CheckRevocationOnChain(System.Security.Cryptography.X509Certificates.X509ChainStatusFlags)
extern "C"  void X509Chain_CheckRevocationOnChain_m1059846149_0 (X509Chain_t_259668440_0 * __this, int32_t ___flag, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509ChainStatusFlags System.Security.Cryptography.X509Certificates.X509Chain::CheckRevocation(System.Security.Cryptography.X509Certificates.X509Certificate2,System.Int32,System.Boolean)
extern "C"  int32_t X509Chain_CheckRevocation_m_1342605852_0 (X509Chain_t_259668440_0 * __this, X509Certificate2_t1644507188_0 * ___certificate, int32_t ___ca, bool ___online, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.X509Certificates.X509ChainStatusFlags System.Security.Cryptography.X509Certificates.X509Chain::CheckRevocation(System.Security.Cryptography.X509Certificates.X509Certificate2,System.Security.Cryptography.X509Certificates.X509Certificate2,System.Boolean)
extern "C"  int32_t X509Chain_CheckRevocation_m1219092751_0 (X509Chain_t_259668440_0 * __this, X509Certificate2_t1644507188_0 * ___certificate, X509Certificate2_t1644507188_0 * ___ca_cert, bool ___online, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.X509.X509Crl System.Security.Cryptography.X509Certificates.X509Chain::FindCrl(System.Security.Cryptography.X509Certificates.X509Certificate2)
extern "C"  X509Crl_t_956935956_0 * X509Chain_FindCrl_m1761802781_0 (X509Chain_t_259668440_0 * __this, X509Certificate2_t1644507188_0 * ___caCertificate, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Security.Cryptography.X509Certificates.X509Chain::ProcessCrlExtensions(Mono.Security.X509.X509Crl)
extern "C"  bool X509Chain_ProcessCrlExtensions_m_946998922_0 (X509Chain_t_259668440_0 * __this, X509Crl_t_956935956_0 * ___crl, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Security.Cryptography.X509Certificates.X509Chain::ProcessCrlEntryExtensions(Mono.Security.X509.X509Crl/X509CrlEntry)
extern "C"  bool X509Chain_ProcessCrlEntryExtensions_m_82878874_0 (X509Chain_t_259668440_0 * __this, X509CrlEntry_t_830724962_0 * ___entry, const MethodInfo* method) IL2CPP_METHOD_ATTR;
