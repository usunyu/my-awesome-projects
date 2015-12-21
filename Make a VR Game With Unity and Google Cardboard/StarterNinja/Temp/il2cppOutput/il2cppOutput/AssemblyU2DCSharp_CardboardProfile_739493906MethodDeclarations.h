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

// CardboardProfile
struct CardboardProfile_t_739493906_0;
// System.Single[]
struct SingleU5BU5D_t_2105059803_0;
// System.Double[]
struct DoubleU5BU5D_t_1251569810_0;
// System.Double[,]
struct DoubleU5BU2CU5D_t_1031583305_0;

#include "codegen/il2cpp-codegen.h"
#include "AssemblyU2DCSharp_CardboardProfile_ScreenSizes_1467707.h"
#include "AssemblyU2DCSharp_CardboardProfile_DeviceTypes_1499883774.h"
#include "UnityEngine_UnityEngine_Rect_981940947.h"
#include "AssemblyU2DCSharp_CardboardProfile_Distortion_2110503554.h"

// System.Void CardboardProfile::.ctor()
extern "C"  void CardboardProfile__ctor_m_1602649880_0 (CardboardProfile_t_739493906_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardProfile::.cctor()
extern "C"  void CardboardProfile__cctor_m1375365061_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// CardboardProfile CardboardProfile::Clone()
extern "C"  CardboardProfile_t_739493906_0 * CardboardProfile_Clone_m_476860327_0 (CardboardProfile_t_739493906_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single CardboardProfile::get_VerticalLensOffset()
extern "C"  float CardboardProfile_get_VerticalLensOffset_m_420108488_0 (CardboardProfile_t_739493906_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// CardboardProfile CardboardProfile::GetKnownProfile(CardboardProfile/ScreenSizes,CardboardProfile/DeviceTypes)
extern "C"  CardboardProfile_t_739493906_0 * CardboardProfile_GetKnownProfile_m_1597554479_0 (Object_t * __this /* static, unused */, int32_t ___screenSize, int32_t ___deviceType, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardProfile::GetLeftEyeVisibleTanAngles(System.Single[])
extern "C"  void CardboardProfile_GetLeftEyeVisibleTanAngles_m_403801462_0 (CardboardProfile_t_739493906_0 * __this, SingleU5BU5D_t_2105059803_0* ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardProfile::GetLeftEyeNoLensTanAngles(System.Single[])
extern "C"  void CardboardProfile_GetLeftEyeNoLensTanAngles_m_939046091_0 (CardboardProfile_t_739493906_0 * __this, SingleU5BU5D_t_2105059803_0* ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Rect CardboardProfile::GetLeftEyeVisibleScreenRect(System.Single[])
extern "C"  Rect_t_981940947_0  CardboardProfile_GetLeftEyeVisibleScreenRect_m_190364073_0 (CardboardProfile_t_739493906_0 * __this, SingleU5BU5D_t_2105059803_0* ___undistortedFrustum, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single CardboardProfile::GetMaxRadius(System.Single[])
extern "C"  float CardboardProfile_GetMaxRadius_m1330854785_0 (Object_t * __this /* static, unused */, SingleU5BU5D_t_2105059803_0* ___tanAngleRect, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Double[] CardboardProfile::solveLeastSquares(System.Double[,],System.Double[])
extern "C"  DoubleU5BU5D_t_1251569810_0* CardboardProfile_solveLeastSquares_m597961519_0 (Object_t * __this /* static, unused */, DoubleU5BU2CU5D_t_1031583305_0* ___matA, DoubleU5BU5D_t_1251569810_0* ___vecY, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// CardboardProfile/Distortion CardboardProfile::ApproximateInverse(System.Single,System.Single,System.Single,System.Int32)
extern "C"  Distortion_t_2110503554_0  CardboardProfile_ApproximateInverse_m_1903334444_0 (Object_t * __this /* static, unused */, float ___k1, float ___k2, float ___maxRadius, int32_t ___numSamples, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// CardboardProfile/Distortion CardboardProfile::ApproximateInverse(CardboardProfile/Distortion,System.Single,System.Int32)
extern "C"  Distortion_t_2110503554_0  CardboardProfile_ApproximateInverse_m151061419_0 (Object_t * __this /* static, unused */, Distortion_t_2110503554_0  ___distort, float ___maxRadius, int32_t ___numSamples, const MethodInfo* method) IL2CPP_METHOD_ATTR;
