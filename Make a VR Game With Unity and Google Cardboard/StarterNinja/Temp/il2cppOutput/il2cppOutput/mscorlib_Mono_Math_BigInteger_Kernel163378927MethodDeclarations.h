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
struct BigInteger_t340845501_0;
// Mono.Math.BigInteger[]
struct BigIntegerU5BU5D_t1135014879_0;
// System.UInt32[]
struct UInt32U5BU5D_t_1239494474_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_Mono_Math_BigInteger_Sign_1090089745.h"

// Mono.Math.BigInteger Mono.Math.BigInteger/Kernel::AddSameSign(Mono.Math.BigInteger,Mono.Math.BigInteger)
extern "C"  BigInteger_t340845501_0 * Kernel_AddSameSign_m_1079571119_0 (Object_t * __this /* static, unused */, BigInteger_t340845501_0 * ___bi1, BigInteger_t340845501_0 * ___bi2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger Mono.Math.BigInteger/Kernel::Subtract(Mono.Math.BigInteger,Mono.Math.BigInteger)
extern "C"  BigInteger_t340845501_0 * Kernel_Subtract_m_496478303_0 (Object_t * __this /* static, unused */, BigInteger_t340845501_0 * ___big, BigInteger_t340845501_0 * ___small, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Math.BigInteger/Kernel::MinusEq(Mono.Math.BigInteger,Mono.Math.BigInteger)
extern "C"  void Kernel_MinusEq_m327282667_0 (Object_t * __this /* static, unused */, BigInteger_t340845501_0 * ___big, BigInteger_t340845501_0 * ___small, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Math.BigInteger/Kernel::PlusEq(Mono.Math.BigInteger,Mono.Math.BigInteger)
extern "C"  void Kernel_PlusEq_m_961712771_0 (Object_t * __this /* static, unused */, BigInteger_t340845501_0 * ___bi1, BigInteger_t340845501_0 * ___bi2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger/Sign Mono.Math.BigInteger/Kernel::Compare(Mono.Math.BigInteger,Mono.Math.BigInteger)
extern "C"  int32_t Kernel_Compare_m_2131474942_0 (Object_t * __this /* static, unused */, BigInteger_t340845501_0 * ___bi1, BigInteger_t340845501_0 * ___bi2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt32 Mono.Math.BigInteger/Kernel::SingleByteDivideInPlace(Mono.Math.BigInteger,System.UInt32)
extern "C"  uint32_t Kernel_SingleByteDivideInPlace_m1308374798_0 (Object_t * __this /* static, unused */, BigInteger_t340845501_0 * ___n, uint32_t ___d, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt32 Mono.Math.BigInteger/Kernel::DwordMod(Mono.Math.BigInteger,System.UInt32)
extern "C"  uint32_t Kernel_DwordMod_m1976612823_0 (Object_t * __this /* static, unused */, BigInteger_t340845501_0 * ___n, uint32_t ___d, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger[] Mono.Math.BigInteger/Kernel::DwordDivMod(Mono.Math.BigInteger,System.UInt32)
extern "C"  BigIntegerU5BU5D_t1135014879_0* Kernel_DwordDivMod_m1857966345_0 (Object_t * __this /* static, unused */, BigInteger_t340845501_0 * ___n, uint32_t ___d, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger[] Mono.Math.BigInteger/Kernel::multiByteDivide(Mono.Math.BigInteger,Mono.Math.BigInteger)
extern "C"  BigIntegerU5BU5D_t1135014879_0* Kernel_multiByteDivide_m_1120573731_0 (Object_t * __this /* static, unused */, BigInteger_t340845501_0 * ___bi1, BigInteger_t340845501_0 * ___bi2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger Mono.Math.BigInteger/Kernel::LeftShift(Mono.Math.BigInteger,System.Int32)
extern "C"  BigInteger_t340845501_0 * Kernel_LeftShift_m_1449488444_0 (Object_t * __this /* static, unused */, BigInteger_t340845501_0 * ___bi, int32_t ___n, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger Mono.Math.BigInteger/Kernel::RightShift(Mono.Math.BigInteger,System.Int32)
extern "C"  BigInteger_t340845501_0 * Kernel_RightShift_m_1813525191_0 (Object_t * __this /* static, unused */, BigInteger_t340845501_0 * ___bi, int32_t ___n, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger Mono.Math.BigInteger/Kernel::MultiplyByDword(Mono.Math.BigInteger,System.UInt32)
extern "C"  BigInteger_t340845501_0 * Kernel_MultiplyByDword_m254641343_0 (Object_t * __this /* static, unused */, BigInteger_t340845501_0 * ___n, uint32_t ___f, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Math.BigInteger/Kernel::Multiply(System.UInt32[],System.UInt32,System.UInt32,System.UInt32[],System.UInt32,System.UInt32,System.UInt32[],System.UInt32)
extern "C"  void Kernel_Multiply_m1732433625_0 (Object_t * __this /* static, unused */, UInt32U5BU5D_t_1239494474_0* ___x, uint32_t ___xOffset, uint32_t ___xLen, UInt32U5BU5D_t_1239494474_0* ___y, uint32_t ___yOffset, uint32_t ___yLen, UInt32U5BU5D_t_1239494474_0* ___d, uint32_t ___dOffset, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Math.BigInteger/Kernel::MultiplyMod2p32pmod(System.UInt32[],System.Int32,System.Int32,System.UInt32[],System.Int32,System.Int32,System.UInt32[],System.Int32,System.Int32)
extern "C"  void Kernel_MultiplyMod2p32pmod_m_1277684528_0 (Object_t * __this /* static, unused */, UInt32U5BU5D_t_1239494474_0* ___x, int32_t ___xOffset, int32_t ___xLen, UInt32U5BU5D_t_1239494474_0* ___y, int32_t ___yOffest, int32_t ___yLen, UInt32U5BU5D_t_1239494474_0* ___d, int32_t ___dOffset, int32_t ___mod, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt32 Mono.Math.BigInteger/Kernel::modInverse(Mono.Math.BigInteger,System.UInt32)
extern "C"  uint32_t Kernel_modInverse_m293471249_0 (Object_t * __this /* static, unused */, BigInteger_t340845501_0 * ___bi, uint32_t ___modulus, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Math.BigInteger Mono.Math.BigInteger/Kernel::modInverse(Mono.Math.BigInteger,Mono.Math.BigInteger)
extern "C"  BigInteger_t340845501_0 * Kernel_modInverse_m_1564041017_0 (Object_t * __this /* static, unused */, BigInteger_t340845501_0 * ___bi, BigInteger_t340845501_0 * ___modulus, const MethodInfo* method) IL2CPP_METHOD_ATTR;
