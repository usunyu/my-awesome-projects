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

// BaseVRDevice
struct BaseVRDevice_t1612809342_0;
// CardboardProfile
struct CardboardProfile_t_739493906_0;
// System.Collections.Generic.List`1<System.String>
struct List_1_t_293602512_0;
// UnityEngine.RenderTexture
struct RenderTexture_t1203146108_0;
// System.Uri
struct Uri_t18014439_0;
// Pose3D
struct Pose3D_t_1878999683_0;

#include "codegen/il2cpp-codegen.h"
#include "AssemblyU2DCSharp_BaseVRDevice_DisplayMetrics1397079922.h"
#include "AssemblyU2DCSharp_Cardboard_Eye_733578435.h"
#include "UnityEngine_UnityEngine_Matrix4x41577636070.h"
#include "AssemblyU2DCSharp_Cardboard_Distortion338328081.h"
#include "UnityEngine_UnityEngine_Rect_981940947.h"

// System.Void BaseVRDevice::.ctor()
extern "C"  void BaseVRDevice__ctor_m_555706408_0 (BaseVRDevice_t1612809342_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BaseVRDevice::.cctor()
extern "C"  void BaseVRDevice__cctor_m_529125675_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// CardboardProfile BaseVRDevice::get_Profile()
extern "C"  CardboardProfile_t_739493906_0 * BaseVRDevice_get_Profile_m750425516_0 (BaseVRDevice_t1612809342_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BaseVRDevice::set_Profile(CardboardProfile)
extern "C"  void BaseVRDevice_set_Profile_m_2129498545_0 (BaseVRDevice_t1612809342_0 * __this, CardboardProfile_t_739493906_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// BaseVRDevice/DisplayMetrics BaseVRDevice::GetDisplayMetrics()
extern "C"  DisplayMetrics_t1397079922_0  BaseVRDevice_GetDisplayMetrics_m_1435542777_0 (BaseVRDevice_t1612809342_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean BaseVRDevice::SupportsNativeDistortionCorrection(System.Collections.Generic.List`1<System.String>)
extern "C"  bool BaseVRDevice_SupportsNativeDistortionCorrection_m984184266_0 (BaseVRDevice_t1612809342_0 * __this, List_1_t_293602512_0 * ___diagnostics, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean BaseVRDevice::SupportsNativeUILayer(System.Collections.Generic.List`1<System.String>)
extern "C"  bool BaseVRDevice_SupportsNativeUILayer_m1937514360_0 (BaseVRDevice_t1612809342_0 * __this, List_1_t_293602512_0 * ___diagnostics, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean BaseVRDevice::SupportsUnityRenderEvent()
extern "C"  bool BaseVRDevice_SupportsUnityRenderEvent_m_1191955597_0 (BaseVRDevice_t1612809342_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.RenderTexture BaseVRDevice::CreateStereoScreen()
extern "C"  RenderTexture_t1203146108_0 * BaseVRDevice_CreateStereoScreen_m1518340817_0 (BaseVRDevice_t1612809342_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean BaseVRDevice::SetDefaultDeviceProfile(System.Uri)
extern "C"  bool BaseVRDevice_SetDefaultDeviceProfile_m397397225_0 (BaseVRDevice_t1612809342_0 * __this, Uri_t18014439_0 * ___uri, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BaseVRDevice::ShowSettingsDialog()
extern "C"  void BaseVRDevice_ShowSettingsDialog_m866779348_0 (BaseVRDevice_t1612809342_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Pose3D BaseVRDevice::GetHeadPose()
extern "C"  Pose3D_t_1878999683_0 * BaseVRDevice_GetHeadPose_m1841166146_0 (BaseVRDevice_t1612809342_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Pose3D BaseVRDevice::GetEyePose(Cardboard/Eye)
extern "C"  Pose3D_t_1878999683_0 * BaseVRDevice_GetEyePose_m_445556633_0 (BaseVRDevice_t1612809342_0 * __this, int32_t ___eye, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Matrix4x4 BaseVRDevice::GetProjection(Cardboard/Eye,Cardboard/Distortion)
extern "C"  Matrix4x4_t1577636070_0  BaseVRDevice_GetProjection_m_290664682_0 (BaseVRDevice_t1612809342_0 * __this, int32_t ___eye, int32_t ___distortion, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Rect BaseVRDevice::GetViewport(Cardboard/Eye,Cardboard/Distortion)
extern "C"  Rect_t_981940947_0  BaseVRDevice_GetViewport_m_950797978_0 (BaseVRDevice_t1612809342_0 * __this, int32_t ___eye, int32_t ___distortion, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BaseVRDevice::SetTouchCoordinates(System.Int32,System.Int32)
extern "C"  void BaseVRDevice_SetTouchCoordinates_m_688097486_0 (BaseVRDevice_t1612809342_0 * __this, int32_t ___x, int32_t ___y, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BaseVRDevice::OnPause(System.Boolean)
extern "C"  void BaseVRDevice_OnPause_m_724615164_0 (BaseVRDevice_t1612809342_0 * __this, bool ___pause, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BaseVRDevice::OnFocus(System.Boolean)
extern "C"  void BaseVRDevice_OnFocus_m2116184806_0 (BaseVRDevice_t1612809342_0 * __this, bool ___focus, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BaseVRDevice::OnLevelLoaded(System.Int32)
extern "C"  void BaseVRDevice_OnLevelLoaded_m_1634127855_0 (BaseVRDevice_t1612809342_0 * __this, int32_t ___level, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BaseVRDevice::OnApplicationQuit()
extern "C"  void BaseVRDevice_OnApplicationQuit_m55312726_0 (BaseVRDevice_t1612809342_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BaseVRDevice::Destroy()
extern "C"  void BaseVRDevice_Destroy_m176250160_0 (BaseVRDevice_t1612809342_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BaseVRDevice::ComputeEyesFromProfile()
extern "C"  void BaseVRDevice_ComputeEyesFromProfile_m_1166569518_0 (BaseVRDevice_t1612809342_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Matrix4x4 BaseVRDevice::MakeProjection(System.Single,System.Single,System.Single,System.Single,System.Single,System.Single)
extern "C"  Matrix4x4_t1577636070_0  BaseVRDevice_MakeProjection_m_579714752_0 (Object_t * __this /* static, unused */, float ___l, float ___t, float ___r, float ___b, float ___n, float ___f, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// BaseVRDevice BaseVRDevice::GetDevice()
extern "C"  BaseVRDevice_t1612809342_0 * BaseVRDevice_GetDevice_m_746675832_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
