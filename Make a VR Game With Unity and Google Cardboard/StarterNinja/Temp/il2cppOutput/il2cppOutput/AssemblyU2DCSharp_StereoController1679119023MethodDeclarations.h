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

// StereoController
struct StereoController_t1679119023_0;
// CardboardEye[]
struct CardboardEyeU5BU5D_t_1244247848_0;
// CardboardHead
struct CardboardHead_t_732803653_0;
// UnityEngine.Camera
struct Camera_t814710830_0;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;
// CardboardEye
struct CardboardEye_t_300735754_0;

#include "codegen/il2cpp-codegen.h"
#include "AssemblyU2DCSharp_Cardboard_Eye_733578435.h"
#include "UnityEngine_UnityEngine_Vector3_725341337.h"

// System.Void StereoController::.ctor()
extern "C"  void StereoController__ctor_m_817107129_0 (StereoController_t1679119023_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// CardboardEye[] StereoController::get_Eyes()
extern "C"  CardboardEyeU5BU5D_t_1244247848_0* StereoController_get_Eyes_m688534376_0 (StereoController_t1679119023_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// CardboardHead StereoController::get_Head()
extern "C"  CardboardHead_t_732803653_0 * StereoController_get_Head_m1004242787_0 (StereoController_t1679119023_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void StereoController::InvalidateEyes()
extern "C"  void StereoController_InvalidateEyes_m1839724314_0 (StereoController_t1679119023_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void StereoController::UpdateStereoValues()
extern "C"  void StereoController_UpdateStereoValues_m1590209024_0 (StereoController_t1679119023_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Camera StereoController::get_camera()
extern "C"  Camera_t814710830_0 * StereoController_get_camera_m636409804_0 (StereoController_t1679119023_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void StereoController::set_camera(UnityEngine.Camera)
extern "C"  void StereoController_set_camera_m_1977795581_0 (StereoController_t1679119023_0 * __this, Camera_t814710830_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void StereoController::Awake()
extern "C"  void StereoController_Awake_m_579501910_0 (StereoController_t1679119023_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void StereoController::AddStereoRig()
extern "C"  void StereoController_AddStereoRig_m_376244812_0 (StereoController_t1679119023_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void StereoController::CreateEye(Cardboard/Eye)
extern "C"  void StereoController_CreateEye_m1821140992_0 (StereoController_t1679119023_0 * __this, int32_t ___eye, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector3 StereoController::ComputeStereoEyePosition(Cardboard/Eye,System.Single,System.Single)
extern "C"  Vector3_t_725341337_0  StereoController_ComputeStereoEyePosition_m_2092728318_0 (StereoController_t1679119023_0 * __this, int32_t ___eye, float ___proj11, float ___zScale, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void StereoController::OnEnable()
extern "C"  void StereoController_OnEnable_m_787235105_0 (StereoController_t1679119023_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void StereoController::OnDisable()
extern "C"  void StereoController_OnDisable_m1806452782_0 (StereoController_t1679119023_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void StereoController::OnPreCull()
extern "C"  void StereoController_OnPreCull_m_284211013_0 (StereoController_t1679119023_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator StereoController::EndOfFrame()
extern "C"  Object_t * StereoController_EndOfFrame_m473628192_0 (StereoController_t1679119023_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean StereoController::<get_Eyes>m__0(CardboardEye)
extern "C"  bool StereoController_U3Cget_EyesU3Em__0_m_1790997680_0 (StereoController_t1679119023_0 * __this, CardboardEye_t_300735754_0 * ___eye, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// CardboardHead StereoController::<get_Head>m__1(CardboardEye)
extern "C"  CardboardHead_t_732803653_0 * StereoController_U3Cget_HeadU3Em__1_m408087484_0 (Object_t * __this /* static, unused */, CardboardEye_t_300735754_0 * ___eye, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean StereoController::<AddStereoRig>m__2(CardboardEye)
extern "C"  bool StereoController_U3CAddStereoRigU3Em__2_m_1077057626_0 (StereoController_t1679119023_0 * __this, CardboardEye_t_300735754_0 * ___eye, const MethodInfo* method) IL2CPP_METHOD_ATTR;
