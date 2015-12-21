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

// Mono.Math.BigInteger
struct BigInteger_t_19408649_0;
// Mono.Math.BigInteger[]
struct BigIntegerU5BU5D_t_1471839591_0;
// System.UInt32[]
struct UInt32U5BU5D_t_1239494474_0;

#include "codegen/il2cpp-codegen.h"
#include "Mono_Security_Mono_Math_BigInteger_Sign_292959243.h"

// Mono.Math.BigInteger Mono.Math.BigInteger/Kernel::AddSameSign(Mono.Math.BigInteger,Mono.Math.BigInteger)
extern "C"  BigInteger_t_19408649_0 * Kernel_AddSameSign_m_343256693_0 (Object_t * __this /* static, unused */, BigInteger_t_19408649_0 * ___bi1, BigInteger_t_19408649_0 * ___bi2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger Mono.Math.BigInteger/Kernel::Subtract(Mono.Math.BigInteger,Mono.Math.BigInteger)
extern "C"  BigInteger_t_19408649_0 * Kernel_Subtract_m593759655_0 (Object_t * __this /* static, unused */, BigInteger_t_19408649_0 * ___big, BigInteger_t_19408649_0 * ___small, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Math.BigInteger/Kernel::MinusEq(Mono.Math.BigInteger,Mono.Math.BigInteger)
extern "C"  void Kernel_MinusEq_m_1706928783_0 (Object_t * __this /* static, unused */, BigInteger_t_19408649_0 * ___big, BigInteger_t_19408649_0 * ___small, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Math.BigInteger/Kernel::PlusEq(Mono.Math.BigInteger,Mono.Math.BigInteger)
extern "C"  void Kernel_PlusEq_m1327972151_0 (Object_t * __this /* static, unused */, BigInteger_t_19408649_0 * ___bi1, BigInteger_t_19408649_0 * ___bi2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger/Sign Mono.Math.BigInteger/Kernel::Compare(Mono.Math.BigInteger,Mono.Math.BigInteger)
extern "C"  int32_t Kernel_Compare_m_780564216_0 (Object_t * __this /* static, unused */, BigInteger_t_19408649_0 * ___bi1, BigInteger_t_19408649_0 * ___bi2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt32 Mono.Math.BigInteger/Kernel::SingleByteDivideInPlace(Mono.Math.BigInteger,System.UInt32)
extern "C"  uint32_t Kernel_SingleByteDivideInPlace_m746013128_0 (Object_t * __this /* static, unused */, BigInteger_t_19408649_0 * ___n, uint32_t ___d, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt32 Mono.Math.BigInteger/Kernel::DwordMod(Mono.Math.BigInteger,System.UInt32)
extern "C"  uint32_t Kernel_DwordMod_m419221597_0 (Object_t * __this /* static, unused */, BigInteger_t_19408649_0 * ___n, uint32_t ___d, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger[] Mono.Math.BigInteger/Kernel::DwordDivMod(Mono.Math.BigInteger,System.UInt32)
extern "C"  BigIntegerU5BU5D_t_1471839591_0* Kernel_DwordDivMod_m_786706289_0 (Object_t * __this /* static, unused */, BigInteger_t_19408649_0 * ___n, uint32_t ___d, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger[] Mono.Math.BigInteger/Kernel::multiByteDivide(Mono.Math.BigInteger,Mono.Math.BigInteger)
extern "C"  BigIntegerU5BU5D_t_1471839591_0* Kernel_multiByteDivide_m1455363991_0 (Object_t * __this /* static, unused */, BigInteger_t_19408649_0 * ___bi1, BigInteger_t_19408649_0 * ___bi2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger Mono.Math.BigInteger/Kernel::LeftShift(Mono.Math.BigInteger,System.Int32)
extern "C"  BigInteger_t_19408649_0 * Kernel_LeftShift_m_654248834_0 (Object_t * __this /* static, unused */, BigInteger_t_19408649_0 * ___bi, int32_t ___n, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger Mono.Math.BigInteger/Kernel::RightShift(Mono.Math.BigInteger,System.Int32)
extern "C"  BigInteger_t_19408649_0 * Kernel_RightShift_m1364066239_0 (Object_t * __this /* static, unused */, BigInteger_t_19408649_0 * ___bi, int32_t ___n, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Math.BigInteger/Kernel::Multiply(System.UInt32[],System.UInt32,System.UInt32,System.UInt32[],System.UInt32,System.UInt32,System.UInt32[],System.UInt32)
extern "C"  void Kernel_Multiply_m1952926483_0 (Object_t * __this /* static, unused */, UInt32U5BU5D_t_1239494474_0* ___x, uint32_t ___xOffset, uint32_t ___xLen, UInt32U5BU5D_t_1239494474_0* ___y, uint32_t ___yOffset, uint32_t ___yLen, UInt32U5BU5D_t_1239494474_0* ___d, uint32_t ___dOffset, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Math.BigInteger/Kernel::MultiplyMod2p32pmod(System.UInt32[],System.Int32,System.Int32,System.UInt32[],System.Int32,System.Int32,System.UInt32[],System.Int32,System.Int32)
extern "C"  void Kernel_MultiplyMod2p32pmod_m2080485974_0 (Object_t * __this /* static, unused */, UInt32U5BU5D_t_1239494474_0* ___x, int32_t ___xOffset, int32_t ___xLen, UInt32U5BU5D_t_1239494474_0* ___y, int32_t ___yOffest, int32_t ___yLen, UInt32U5BU5D_t_1239494474_0* ___d, int32_t ___dOffset, int32_t ___mod, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt32 Mono.Math.BigInteger/Kernel::modInverse(Mono.Math.BigInteger,System.UInt32)
extern "C"  uint32_t Kernel_modInverse_m_1710877929_0 (Object_t * __this /* static, unused */, BigInteger_t_19408649_0 * ___bi, uint32_t ___modulus, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger Mono.Math.BigInteger/Kernel::modInverse(Mono.Math.BigInteger,Mono.Math.BigInteger)
extern "C"  BigInteger_t_19408649_0 * Kernel_modInverse_m_1817383603_0 (Object_t * __this /* static, unused */, BigInteger_t_19408649_0 * ___bi, BigInteger_t_19408649_0 * ___modulus, const MethodInfo* method) IL2CPP_METHOD_ATTR;
