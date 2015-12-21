#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Security.Cryptography.RSA
struct RSA_t1573116945_0;
// System.Security.Cryptography.RandomNumberGenerator
struct RandomNumberGenerator_t1902086616_0;

#include "mscorlib_System_Security_Cryptography_AsymmetricKe_338607635.h"

// System.Security.Cryptography.RSAPKCS1KeyExchangeFormatter
struct  RSAPKCS1KeyExchangeFormatter_t_876828323_0  : public AsymmetricKeyExchangeFormatter_t_338607635_0
{
	// System.Security.Cryptography.RSA System.Security.Cryptography.RSAPKCS1KeyExchangeFormatter::rsa
	RSA_t1573116945_0 * ___rsa_0;
	// System.Security.Cryptography.RandomNumberGenerator System.Security.Cryptography.RSAPKCS1KeyExchangeFormatter::random
	RandomNumberGenerator_t1902086616_0 * ___random_1;
};
