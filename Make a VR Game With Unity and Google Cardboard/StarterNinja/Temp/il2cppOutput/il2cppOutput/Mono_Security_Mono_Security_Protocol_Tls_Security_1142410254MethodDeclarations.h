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

// Mono.Security.Protocol.Tls.SecurityParameters
struct SecurityParameters_t_1142410254_0;
// Mono.Security.Protocol.Tls.CipherSuite
struct CipherSuite_t_1835594235_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.Protocol.Tls.SecurityParameters::.ctor()
extern "C"  void SecurityParameters__ctor_m711073950_0 (SecurityParameters_t_1142410254_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.CipherSuite Mono.Security.Protocol.Tls.SecurityParameters::get_Cipher()
extern "C"  CipherSuite_t_1835594235_0 * SecurityParameters_get_Cipher_m2063042602_0 (SecurityParameters_t_1142410254_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SecurityParameters::set_Cipher(Mono.Security.Protocol.Tls.CipherSuite)
extern "C"  void SecurityParameters_set_Cipher_m1888356967_0 (SecurityParameters_t_1142410254_0 * __this, CipherSuite_t_1835594235_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.SecurityParameters::get_ClientWriteMAC()
extern "C"  ByteU5BU5D_t_1238178395_0* SecurityParameters_get_ClientWriteMAC_m509205152_0 (SecurityParameters_t_1142410254_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SecurityParameters::set_ClientWriteMAC(System.Byte[])
extern "C"  void SecurityParameters_set_ClientWriteMAC_m_1904564469_0 (SecurityParameters_t_1142410254_0 * __this, ByteU5BU5D_t_1238178395_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.SecurityParameters::get_ServerWriteMAC()
extern "C"  ByteU5BU5D_t_1238178395_0* SecurityParameters_get_ServerWriteMAC_m451878936_0 (SecurityParameters_t_1142410254_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SecurityParameters::set_ServerWriteMAC(System.Byte[])
extern "C"  void SecurityParameters_set_ServerWriteMAC_m324273299_0 (SecurityParameters_t_1142410254_0 * __this, ByteU5BU5D_t_1238178395_0* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SecurityParameters::Clear()
extern "C"  void SecurityParameters_Clear_m_1882792759_0 (SecurityParameters_t_1142410254_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
