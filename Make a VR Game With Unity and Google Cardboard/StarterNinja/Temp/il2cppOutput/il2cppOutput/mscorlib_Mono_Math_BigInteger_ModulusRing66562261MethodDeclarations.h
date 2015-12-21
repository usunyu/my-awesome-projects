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
struct ModulusRing_t66562261_0;
// Mono.Math.BigInteger
struct BigInteger_t340845501_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Math.BigInteger/ModulusRing::.ctor(Mono.Math.BigInteger)
extern "C"  void ModulusRing__ctor_m_1580562264_0 (ModulusRing_t66562261_0 * __this, BigInteger_t340845501_0 * ___modulus, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Math.BigInteger/ModulusRing::BarrettReduction(Mono.Math.BigInteger)
extern "C"  void ModulusRing_BarrettReduction_m_1352212009_0 (ModulusRing_t66562261_0 * __this, BigInteger_t340845501_0 * ___x, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger Mono.Math.BigInteger/ModulusRing::Multiply(Mono.Math.BigInteger,Mono.Math.BigInteger)
extern "C"  BigInteger_t340845501_0 * ModulusRing_Multiply_m_1321403507_0 (ModulusRing_t66562261_0 * __this, BigInteger_t340845501_0 * ___a, BigInteger_t340845501_0 * ___b, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger Mono.Math.BigInteger/ModulusRing::Difference(Mono.Math.BigInteger,Mono.Math.BigInteger)
extern "C"  BigInteger_t340845501_0 * ModulusRing_Difference_m1446083540_0 (ModulusRing_t66562261_0 * __this, BigInteger_t340845501_0 * ___a, BigInteger_t340845501_0 * ___b, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger Mono.Math.BigInteger/ModulusRing::Pow(Mono.Math.BigInteger,Mono.Math.BigInteger)
extern "C"  BigInteger_t340845501_0 * ModulusRing_Pow_m_421637375_0 (ModulusRing_t66562261_0 * __this, BigInteger_t340845501_0 * ___a, BigInteger_t340845501_0 * ___k, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger Mono.Math.BigInteger/ModulusRing::Pow(System.UInt32,Mono.Math.BigInteger)
extern "C"  BigInteger_t340845501_0 * ModulusRing_Pow_m_1715652136_0 (ModulusRing_t66562261_0 * __this, uint32_t ___b, BigInteger_t340845501_0 * ___exp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
