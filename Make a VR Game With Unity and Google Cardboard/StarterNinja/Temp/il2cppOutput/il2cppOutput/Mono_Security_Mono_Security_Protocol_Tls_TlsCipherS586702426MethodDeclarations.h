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

// Mono.Security.Protocol.Tls.TlsCipherSuite
struct TlsCipherSuite_t586702426_0;
// System.String
struct String_t;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;

#include "codegen/il2cpp-codegen.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_CipherAl_2011610538.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_HashAlgor_103851469.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_ExchangeAl701975358.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_ContentTyp_45887061.h"

// System.Void Mono.Security.Protocol.Tls.TlsCipherSuite::.ctor(System.Int16,System.String,Mono.Security.Protocol.Tls.CipherAlgorithmType,Mono.Security.Protocol.Tls.HashAlgorithmType,Mono.Security.Protocol.Tls.ExchangeAlgorithmType,System.Boolean,System.Boolean,System.Byte,System.Byte,System.Int16,System.Byte,System.Byte)
extern "C"  void TlsCipherSuite__ctor_m1139271371_0 (TlsCipherSuite_t586702426_0 * __this, int16_t ___code, String_t* ___name, int32_t ___cipherAlgorithmType, int32_t ___hashAlgorithmType, int32_t ___exchangeAlgorithmType, bool ___exportable, bool ___blockMode, uint8_t ___keyMaterialSize, uint8_t ___expandedKeyMaterialSize, int16_t ___effectiveKeyBytes, uint8_t ___ivSize, uint8_t ___blockSize, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.TlsCipherSuite::ComputeServerRecordMAC(Mono.Security.Protocol.Tls.ContentType,System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* TlsCipherSuite_ComputeServerRecordMAC_m_581327810_0 (TlsCipherSuite_t586702426_0 * __this, uint8_t ___contentType, ByteU5BU5D_t_1238178395_0* ___fragment, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.TlsCipherSuite::ComputeClientRecordMAC(Mono.Security.Protocol.Tls.ContentType,System.Byte[])
extern "C"  ByteU5BU5D_t_1238178395_0* TlsCipherSuite_ComputeClientRecordMAC_m13266614_0 (TlsCipherSuite_t586702426_0 * __this, uint8_t ___contentType, ByteU5BU5D_t_1238178395_0* ___fragment, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.TlsCipherSuite::ComputeMasterSecret(System.Byte[])
extern "C"  void TlsCipherSuite_ComputeMasterSecret_m988816908_0 (TlsCipherSuite_t586702426_0 * __this, ByteU5BU5D_t_1238178395_0* ___preMasterSecret, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.TlsCipherSuite::ComputeKeys()
extern "C"  void TlsCipherSuite_ComputeKeys_m_1057864545_0 (TlsCipherSuite_t586702426_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
