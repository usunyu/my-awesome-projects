#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Security.Cryptography.HashAlgorithm
struct HashAlgorithm_t_1530054766_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;

#include "mscorlib_System_Security_Cryptography_HashAlgorit_1530054766.h"

// Mono.Security.Protocol.Tls.SslHandshakeHash
struct  SslHandshakeHash_t_50906207_0  : public HashAlgorithm_t_1530054766_0
{
	// System.Security.Cryptography.HashAlgorithm Mono.Security.Protocol.Tls.SslHandshakeHash::md5
	HashAlgorithm_t_1530054766_0 * ___md5_4;
	// System.Security.Cryptography.HashAlgorithm Mono.Security.Protocol.Tls.SslHandshakeHash::sha
	HashAlgorithm_t_1530054766_0 * ___sha_5;
	// System.Boolean Mono.Security.Protocol.Tls.SslHandshakeHash::hashing
	bool ___hashing_6;
	// System.Byte[] Mono.Security.Protocol.Tls.SslHandshakeHash::secret
	ByteU5BU5D_t_1238178395_0* ___secret_7;
	// System.Byte[] Mono.Security.Protocol.Tls.SslHandshakeHash::innerPadMD5
	ByteU5BU5D_t_1238178395_0* ___innerPadMD5_8;
	// System.Byte[] Mono.Security.Protocol.Tls.SslHandshakeHash::outerPadMD5
	ByteU5BU5D_t_1238178395_0* ___outerPadMD5_9;
	// System.Byte[] Mono.Security.Protocol.Tls.SslHandshakeHash::innerPadSHA
	ByteU5BU5D_t_1238178395_0* ___innerPadSHA_10;
	// System.Byte[] Mono.Security.Protocol.Tls.SslHandshakeHash::outerPadSHA
	ByteU5BU5D_t_1238178395_0* ___outerPadSHA_11;
};
