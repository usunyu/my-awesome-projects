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

// Mono.Math.BigInteger/ModulusRing
struct ModulusRing_t_999909617_0;
// Mono.Math.BigInteger
struct BigInteger_t_19408649_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Math.BigInteger/ModulusRing::.ctor(Mono.Math.BigInteger)
extern "C"  void ModulusRing__ctor_m2037212078_0 (ModulusRing_t_999909617_0 * __this, BigInteger_t_19408649_0 * ___modulus, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Math.BigInteger/ModulusRing::BarrettReduction(Mono.Math.BigInteger)
extern "C"  void ModulusRing_BarrettReduction_m1160185617_0 (ModulusRing_t_999909617_0 * __this, BigInteger_t_19408649_0 * ___x, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger Mono.Math.BigInteger/ModulusRing::Multiply(Mono.Math.BigInteger,Mono.Math.BigInteger)
extern "C"  BigInteger_t_19408649_0 * ModulusRing_Multiply_m1902123335_0 (ModulusRing_t_999909617_0 * __this, BigInteger_t_19408649_0 * ___a, BigInteger_t_19408649_0 * ___b, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger Mono.Math.BigInteger/ModulusRing::Difference(Mono.Math.BigInteger,Mono.Math.BigInteger)
extern "C"  BigInteger_t_19408649_0 * ModulusRing_Difference_m_1711009010_0 (ModulusRing_t_999909617_0 * __this, BigInteger_t_19408649_0 * ___a, BigInteger_t_19408649_0 * ___b, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger Mono.Math.BigInteger/ModulusRing::Pow(Mono.Math.BigInteger,Mono.Math.BigInteger)
extern "C"  BigInteger_t_19408649_0 * ModulusRing_Pow_m668600583_0 (ModulusRing_t_999909617_0 * __this, BigInteger_t_19408649_0 * ___a, BigInteger_t_19408649_0 * ___k, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger Mono.Math.BigInteger/ModulusRing::Pow(System.UInt32,Mono.Math.BigInteger)
extern "C"  BigInteger_t_19408649_0 * ModulusRing_Pow_m_920412526_0 (ModulusRing_t_999909617_0 * __this, uint32_t ___b, BigInteger_t_19408649_0 * ___exp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
