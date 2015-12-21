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

// Cardboard
struct Cardboard_t1550393659_0;
// Cardboard/StereoScreenChangeDelegate
struct StereoScreenChangeDelegate_t509462125_0;
// System.Action
struct Action_t2132293834_0;
// StereoController
struct StereoController_t1679119023_0;
// UnityEngine.RenderTexture
struct RenderTexture_t1203146108_0;
// CardboardProfile
struct CardboardProfile_t_739493906_0;
// Pose3D
struct Pose3D_t_1878999683_0;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;

#include "codegen/il2cpp-codegen.h"
#include "AssemblyU2DCSharp_Cardboard_DistortionCorrectionMet122018320.h"
#include "AssemblyU2DCSharp_Cardboard_BackButtonModes2114367171.h"
#include "AssemblyU2DCSharp_Cardboard_Eye_733578435.h"
#include "UnityEngine_UnityEngine_Matrix4x41577636070.h"
#include "AssemblyU2DCSharp_Cardboard_Distortion338328081.h"
#include "UnityEngine_UnityEngine_Rect_981940947.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"
#include "UnityEngine_UnityEngine_Quaternion1989680039.h"
#include "UnityEngine_UnityEngine_Vector3_725341337.h"

// System.Void Cardboard::.ctor()
extern "C"  void Cardboard__ctor_m_1830869899_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::.cctor()
extern "C"  void Cardboard__cctor_m_1404488232_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::add_OnStereoScreenChanged(Cardboard/StereoScreenChangeDelegate)
extern "C"  void Cardboard_add_OnStereoScreenChanged_m_1876853612_0 (Cardboard_t1550393659_0 * __this, StereoScreenChangeDelegate_t509462125_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::remove_OnStereoScreenChanged(Cardboard/StereoScreenChangeDelegate)
extern "C"  void Cardboard_remove_OnStereoScreenChanged_m_1909875885_0 (Cardboard_t1550393659_0 * __this, StereoScreenChangeDelegate_t509462125_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::add_OnTrigger(System.Action)
extern "C"  void Cardboard_add_OnTrigger_m_1176960337_0 (Cardboard_t1550393659_0 * __this, Action_t2132293834_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::remove_OnTrigger(System.Action)
extern "C"  void Cardboard_remove_OnTrigger_m1014970448_0 (Cardboard_t1550393659_0 * __this, Action_t2132293834_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::add_OnTilt(System.Action)
extern "C"  void Cardboard_add_OnTilt_m_1299248044_0 (Cardboard_t1550393659_0 * __this, Action_t2132293834_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::remove_OnTilt(System.Action)
extern "C"  void Cardboard_remove_OnTilt_m_545742253_0 (Cardboard_t1550393659_0 * __this, Action_t2132293834_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::add_OnProfileChange(System.Action)
extern "C"  void Cardboard_add_OnProfileChange_m_68367538_0 (Cardboard_t1550393659_0 * __this, Action_t2132293834_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::remove_OnProfileChange(System.Action)
extern "C"  void Cardboard_remove_OnProfileChange_m1495434287_0 (Cardboard_t1550393659_0 * __this, Action_t2132293834_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::add_OnBackButton(System.Action)
extern "C"  void Cardboard_add_OnBackButton_m_576697128_0 (Cardboard_t1550393659_0 * __this, Action_t2132293834_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::remove_OnBackButton(System.Action)
extern "C"  void Cardboard_remove_OnBackButton_m_1449449577_0 (Cardboard_t1550393659_0 * __this, Action_t2132293834_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Cardboard Cardboard::get_SDK()
extern "C"  Cardboard_t1550393659_0 * Cardboard_get_SDK_m_1943599231_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// StereoController Cardboard::get_Controller()
extern "C"  StereoController_t1679119023_0 * Cardboard_get_Controller_m_1704431221_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Cardboard::get_VRModeEnabled()
extern "C"  bool Cardboard_get_VRModeEnabled_m_1159893312_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::set_VRModeEnabled(System.Boolean)
extern "C"  void Cardboard_set_VRModeEnabled_m_724929649_0 (Cardboard_t1550393659_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Cardboard/DistortionCorrectionMethod Cardboard::get_DistortionCorrection()
extern "C"  int32_t Cardboard_get_DistortionCorrection_m_39228629_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::set_DistortionCorrection(Cardboard/DistortionCorrectionMethod)
extern "C"  void Cardboard_set_DistortionCorrection_m1636220850_0 (Cardboard_t1550393659_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Cardboard::get_EnableAlignmentMarker()
extern "C"  bool Cardboard_get_EnableAlignmentMarker_m_925399080_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::set_EnableAlignmentMarker(System.Boolean)
extern "C"  void Cardboard_set_EnableAlignmentMarker_m_2127697241_0 (Cardboard_t1550393659_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Cardboard::get_EnableSettingsButton()
extern "C"  bool Cardboard_get_EnableSettingsButton_m_257939556_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::set_EnableSettingsButton(System.Boolean)
extern "C"  void Cardboard_set_EnableSettingsButton_m_1294808645_0 (Cardboard_t1550393659_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Cardboard/BackButtonModes Cardboard::get_BackButtonMode()
extern "C"  int32_t Cardboard_get_BackButtonMode_m_990780609_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::set_BackButtonMode(Cardboard/BackButtonModes)
extern "C"  void Cardboard_set_BackButtonMode_m_694484340_0 (Cardboard_t1550393659_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Cardboard::get_TapIsTrigger()
extern "C"  bool Cardboard_get_TapIsTrigger_m_895466225_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::set_TapIsTrigger(System.Boolean)
extern "C"  void Cardboard_set_TapIsTrigger_m921242094_0 (Cardboard_t1550393659_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single Cardboard::get_NeckModelScale()
extern "C"  float Cardboard_get_NeckModelScale_m1927189132_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::set_NeckModelScale(System.Single)
extern "C"  void Cardboard_set_NeckModelScale_m200320991_0 (Cardboard_t1550393659_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Cardboard::get_AutoDriftCorrection()
extern "C"  bool Cardboard_get_AutoDriftCorrection_m1979577814_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::set_AutoDriftCorrection(System.Boolean)
extern "C"  void Cardboard_set_AutoDriftCorrection_m249494053_0 (Cardboard_t1550393659_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Cardboard::get_ElectronicDisplayStabilization()
extern "C"  bool Cardboard_get_ElectronicDisplayStabilization_m_934532387_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::set_ElectronicDisplayStabilization(System.Boolean)
extern "C"  void Cardboard_set_ElectronicDisplayStabilization_m1910805820_0 (Cardboard_t1550393659_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Cardboard::get_SyncWithCardboardApp()
extern "C"  bool Cardboard_get_SyncWithCardboardApp_m_242433520_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::set_SyncWithCardboardApp(System.Boolean)
extern "C"  void Cardboard_set_SyncWithCardboardApp_m1544948015_0 (Cardboard_t1550393659_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Cardboard::get_NativeDistortionCorrectionSupported()
extern "C"  bool Cardboard_get_NativeDistortionCorrectionSupported_m_1902114086_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::set_NativeDistortionCorrectionSupported(System.Boolean)
extern "C"  void Cardboard_set_NativeDistortionCorrectionSupported_m_1083160535_0 (Cardboard_t1550393659_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Cardboard::get_NativeUILayerSupported()
extern "C"  bool Cardboard_get_NativeUILayerSupported_m600581484_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::set_NativeUILayerSupported(System.Boolean)
extern "C"  void Cardboard_set_NativeUILayerSupported_m_1126067829_0 (Cardboard_t1550393659_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single Cardboard::get_StereoScreenScale()
extern "C"  float Cardboard_get_StereoScreenScale_m1166541980_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::set_StereoScreenScale(System.Single)
extern "C"  void Cardboard_set_StereoScreenScale_m_56058545_0 (Cardboard_t1550393659_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.RenderTexture Cardboard::get_StereoScreen()
extern "C"  RenderTexture_t1203146108_0 * Cardboard_get_StereoScreen_m_62453353_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::set_StereoScreen(UnityEngine.RenderTexture)
extern "C"  void Cardboard_set_StereoScreen_m_1052900108_0 (Cardboard_t1550393659_0 * __this, RenderTexture_t1203146108_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// CardboardProfile Cardboard::get_Profile()
extern "C"  CardboardProfile_t_739493906_0 * Cardboard_get_Profile_m1072312029_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Pose3D Cardboard::get_HeadPose()
extern "C"  Pose3D_t_1878999683_0 * Cardboard_get_HeadPose_m2115147790_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Pose3D Cardboard::EyePose(Cardboard/Eye)
extern "C"  Pose3D_t_1878999683_0 * Cardboard_EyePose_m_1235584598_0 (Cardboard_t1550393659_0 * __this, int32_t ___eye, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Matrix4x4 Cardboard::Projection(Cardboard/Eye,Cardboard/Distortion)
extern "C"  Matrix4x4_t1577636070_0  Cardboard_Projection_m1655400281_0 (Cardboard_t1550393659_0 * __this, int32_t ___eye, int32_t ___distortion, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Rect Cardboard::Viewport(Cardboard/Eye,Cardboard/Distortion)
extern "C"  Rect_t_981940947_0  Cardboard_Viewport_m2018841897_0 (Cardboard_t1550393659_0 * __this, int32_t ___eye, int32_t ___distortion, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 Cardboard::get_ComfortableViewingRange()
extern "C"  Vector2_t_725341338_0  Cardboard_get_ComfortableViewingRange_m1310226859_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::InitDevice()
extern "C"  void Cardboard_InitDevice_m_1407310411_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::Awake()
extern "C"  void Cardboard_Awake_m_1593264680_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::AddCardboardCamera()
extern "C"  void Cardboard_AddCardboardCamera_m1554420969_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Cardboard::get_Triggered()
extern "C"  bool Cardboard_get_Triggered_m_19549067_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::set_Triggered(System.Boolean)
extern "C"  void Cardboard_set_Triggered_m552436868_0 (Cardboard_t1550393659_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Cardboard::get_Tilted()
extern "C"  bool Cardboard_get_Tilted_m1858204256_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::set_Tilted(System.Boolean)
extern "C"  void Cardboard_set_Tilted_m1672475519_0 (Cardboard_t1550393659_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Cardboard::get_ProfileChanged()
extern "C"  bool Cardboard_get_ProfileChanged_m_1344414641_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::set_ProfileChanged(System.Boolean)
extern "C"  void Cardboard_set_ProfileChanged_m_2057427154_0 (Cardboard_t1550393659_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Cardboard::get_BackButtonPressed()
extern "C"  bool Cardboard_get_BackButtonPressed_m2140205447_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::set_BackButtonPressed(System.Boolean)
extern "C"  void Cardboard_set_BackButtonPressed_m1139974678_0 (Cardboard_t1550393659_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::UpdateState()
extern "C"  void Cardboard_UpdateState_m_1353788581_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::DispatchEvents()
extern "C"  void Cardboard_DispatchEvents_m365236770_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator Cardboard::EndOfFrame()
extern "C"  Object_t * Cardboard_EndOfFrame_m95778_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::PostRender()
extern "C"  void Cardboard_PostRender_m_1574888315_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::Recenter()
extern "C"  void Cardboard_Recenter_m649500023_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::SetTouchCoordinates(System.Int32,System.Int32)
extern "C"  void Cardboard_SetTouchCoordinates_m_1907022859_0 (Cardboard_t1550393659_0 * __this, int32_t ___x, int32_t ___y, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::ShowSettingsDialog()
extern "C"  void Cardboard_ShowSettingsDialog_m1001626455_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::OnEnable()
extern "C"  void Cardboard_OnEnable_m416109297_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::OnDisable()
extern "C"  void Cardboard_OnDisable_m455423580_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::OnApplicationPause(System.Boolean)
extern "C"  void Cardboard_OnApplicationPause_m153985387_0 (Cardboard_t1550393659_0 * __this, bool ___pause, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::OnApplicationFocus(System.Boolean)
extern "C"  void Cardboard_OnApplicationFocus_m_1300181939_0 (Cardboard_t1550393659_0 * __this, bool ___focus, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::OnLevelWasLoaded(System.Int32)
extern "C"  void Cardboard_OnLevelWasLoaded_m_193355479_0 (Cardboard_t1550393659_0 * __this, int32_t ___level, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::OnApplicationQuit()
extern "C"  void Cardboard_OnApplicationQuit_m_1741452685_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::OnDestroy()
extern "C"  void Cardboard_OnDestroy_m_1662011666_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Cardboard::get_nativeDistortionCorrection()
extern "C"  bool Cardboard_get_nativeDistortionCorrection_m1162040246_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Cardboard::set_nativeDistortionCorrection(System.Boolean)
extern "C"  void Cardboard_set_nativeDistortionCorrection_m_1177361835_0 (Cardboard_t1550393659_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Cardboard::get_InCardboard()
extern "C"  bool Cardboard_get_InCardboard_m668727439_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Cardboard::get_CardboardTriggered()
extern "C"  bool Cardboard_get_CardboardTriggered_m637180837_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Matrix4x4 Cardboard::get_HeadView()
extern "C"  Matrix4x4_t1577636070_0  Cardboard_get_HeadView_m_2058250526_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Quaternion Cardboard::get_HeadRotation()
extern "C"  Quaternion_t1989680039_0  Cardboard_get_HeadRotation_m_1021720274_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector3 Cardboard::get_HeadPosition()
extern "C"  Vector3_t_725341337_0  Cardboard_get_HeadPosition_m723100391_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Matrix4x4 Cardboard::EyeView(Cardboard/Eye)
extern "C"  Matrix4x4_t1577636070_0  Cardboard_EyeView_m930332374_0 (Cardboard_t1550393659_0 * __this, int32_t ___eye, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector3 Cardboard::EyeOffset(Cardboard/Eye)
extern "C"  Vector3_t_725341337_0  Cardboard_EyeOffset_m_147178903_0 (Cardboard_t1550393659_0 * __this, int32_t ___eye, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Matrix4x4 Cardboard::UndistortedProjection(Cardboard/Eye)
extern "C"  Matrix4x4_t1577636070_0  Cardboard_UndistortedProjection_m_1955512148_0 (Cardboard_t1550393659_0 * __this, int32_t ___eye, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Rect Cardboard::EyeRect(Cardboard/Eye)
extern "C"  Rect_t_981940947_0  Cardboard_EyeRect_m_612202320_0 (Cardboard_t1550393659_0 * __this, int32_t ___eye, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single Cardboard::get_MinimumComfortDistance()
extern "C"  float Cardboard_get_MinimumComfortDistance_m443091295_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single Cardboard::get_MaximumComfortDistance()
extern "C"  float Cardboard_get_MaximumComfortDistance_m169183629_0 (Cardboard_t1550393659_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
