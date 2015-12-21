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

// CardboardEye
struct CardboardEye_t_300735754_0;
// StereoController
struct StereoController_t1679119023_0;
// CardboardHead
struct CardboardHead_t_732803653_0;
// UnityEngine.Camera
struct Camera_t814710830_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Matrix4x41577636070.h"
#include "UnityEngine_UnityEngine_Rect_981940947.h"

// System.Void CardboardEye::.ctor()
extern "C"  void CardboardEye__ctor_m1179500640_0 (CardboardEye_t_300735754_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// StereoController CardboardEye::get_Controller()
extern "C"  StereoController_t1679119023_0 * CardboardEye_get_Controller_m_1598897486_0 (CardboardEye_t_300735754_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// CardboardHead CardboardEye::get_Head()
extern "C"  CardboardHead_t_732803653_0 * CardboardEye_get_Head_m1430956586_0 (CardboardEye_t_300735754_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Camera CardboardEye::get_camera()
extern "C"  Camera_t814710830_0 * CardboardEye_get_camera_m_1587837229_0 (CardboardEye_t_300735754_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardEye::set_camera(UnityEngine.Camera)
extern "C"  void CardboardEye_set_camera_m_1547223350_0 (CardboardEye_t_300735754_0 * __this, Camera_t814710830_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardEye::Awake()
extern "C"  void CardboardEye_Awake_m1417105859_0 (CardboardEye_t_300735754_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardEye::Start()
extern "C"  void CardboardEye_Start_m126638432_0 (CardboardEye_t_300735754_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardEye::FixProjection(UnityEngine.Matrix4x4&)
extern "C"  void CardboardEye_FixProjection_m_31744812_0 (CardboardEye_t_300735754_0 * __this, Matrix4x4_t1577636070_0 * ___proj, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Rect CardboardEye::FixViewport(UnityEngine.Rect)
extern "C"  Rect_t_981940947_0  CardboardEye_FixViewport_m_1559529508_0 (CardboardEye_t_300735754_0 * __this, Rect_t_981940947_0  ___rect, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardEye::UpdateStereoValues()
extern "C"  void CardboardEye_UpdateStereoValues_m833300871_0 (CardboardEye_t_300735754_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardEye::SetupStereo()
extern "C"  void CardboardEye_SetupStereo_m_638820525_0 (CardboardEye_t_300735754_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardEye::OnPreCull()
extern "C"  void CardboardEye_OnPreCull_m_2145327788_0 (CardboardEye_t_300735754_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardEye::CopyCameraAndMakeSideBySide(StereoController,System.Single,System.Single)
extern "C"  void CardboardEye_CopyCameraAndMakeSideBySide_m669497188_0 (CardboardEye_t_300735754_0 * __this, StereoController_t1679119023_0 * ___controller, float ___parx, float ___pary, const MethodInfo* method) IL2CPP_METHOD_ATTR;
