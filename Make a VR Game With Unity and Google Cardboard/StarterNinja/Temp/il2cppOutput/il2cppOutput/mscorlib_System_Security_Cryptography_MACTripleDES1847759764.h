#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Security.Cryptography.TripleDES
struct TripleDES_t_474022939_0;
// Mono.Security.Cryptography.MACAlgorithm
struct MACAlgorithm_t_1709319429_0;

#include "mscorlib_System_Security_Cryptography_KeyedHashAlg1340577394.h"

// System.Security.Cryptography.MACTripleDES
struct  MACTripleDES_t1847759764_0  : public KeyedHashAlgorithm_t1340577394_0
{
	// System.Security.Cryptography.TripleDES System.Security.Cryptography.MACTripleDES::tdes
	TripleDES_t_474022939_0 * ___tdes_5;
	// Mono.Security.Cryptography.MACAlgorithm System.Security.Cryptography.MACTripleDES::mac
	MACAlgorithm_t_1709319429_0 * ___mac_6;
	// System.Boolean System.Security.Cryptography.MACTripleDES::m_disposed
	bool ___m_disposed_7;
};
