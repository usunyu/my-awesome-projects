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

// CardboardiOSDevice
struct CardboardiOSDevice_t_851660312_0;
// System.Collections.Generic.List`1<System.String>
struct List_1_t_293602512_0;
// System.Uri
struct Uri_t18014439_0;

#include "codegen/il2cpp-codegen.h"
#include "AssemblyU2DCSharp_BaseVRDevice_DisplayMetrics1397079922.h"

// System.Void CardboardiOSDevice::.ctor()
extern "C"  void CardboardiOSDevice__ctor_m_2040346770_0 (CardboardiOSDevice_t_851660312_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// BaseVRDevice/DisplayMetrics CardboardiOSDevice::GetDisplayMetrics()
extern "C"  DisplayMetrics_t1397079922_0  CardboardiOSDevice_GetDisplayMetrics_m_1811421667_0 (CardboardiOSDevice_t_851660312_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean CardboardiOSDevice::SupportsNativeDistortionCorrection(System.Collections.Generic.List`1<System.String>)
extern "C"  bool CardboardiOSDevice_SupportsNativeDistortionCorrection_m210658036_0 (CardboardiOSDevice_t_851660312_0 * __this, List_1_t_293602512_0 * ___diagnostics, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardiOSDevice::SetVRModeEnabled(System.Boolean)
extern "C"  void CardboardiOSDevice_SetVRModeEnabled_m238427693_0 (CardboardiOSDevice_t_851660312_0 * __this, bool ___enabled, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardiOSDevice::SetSettingsButtonEnabled(System.Boolean)
extern "C"  void CardboardiOSDevice_SetSettingsButtonEnabled_m2141597591_0 (CardboardiOSDevice_t_851660312_0 * __this, bool ___enabled, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardiOSDevice::SetAlignmentMarkerEnabled(System.Boolean)
extern "C"  void CardboardiOSDevice_SetAlignmentMarkerEnabled_m_2066718455_0 (CardboardiOSDevice_t_851660312_0 * __this, bool ___enabled, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardiOSDevice::SetVRBackButtonEnabled(System.Boolean)
extern "C"  void CardboardiOSDevice_SetVRBackButtonEnabled_m_2074768681_0 (CardboardiOSDevice_t_851660312_0 * __this, bool ___enabled, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardiOSDevice::SetShowVrBackButtonOnlyInVR(System.Boolean)
extern "C"  void CardboardiOSDevice_SetShowVrBackButtonOnlyInVR_m_308410300_0 (CardboardiOSDevice_t_851660312_0 * __this, bool ___only, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardiOSDevice::SetTapIsTrigger(System.Boolean)
extern "C"  void CardboardiOSDevice_SetTapIsTrigger_m_433155184_0 (CardboardiOSDevice_t_851660312_0 * __this, bool ___enabled, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean CardboardiOSDevice::SetDefaultDeviceProfile(System.Uri)
extern "C"  bool CardboardiOSDevice_SetDefaultDeviceProfile_m_1875290497_0 (CardboardiOSDevice_t_851660312_0 * __this, Uri_t18014439_0 * ___uri, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardiOSDevice::Init()
extern "C"  void CardboardiOSDevice_Init_m_1361207002_0 (CardboardiOSDevice_t_851660312_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardiOSDevice::OnFocus(System.Boolean)
extern "C"  void CardboardiOSDevice_OnFocus_m1424928380_0 (CardboardiOSDevice_t_851660312_0 * __this, bool ___focus, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardiOSDevice::ShowSettingsDialog()
extern "C"  void CardboardiOSDevice_ShowSettingsDialog_m1600148734_0 (CardboardiOSDevice_t_851660312_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean CardboardiOSDevice::isOpenGLAPI()
extern "C"  bool CardboardiOSDevice_isOpenGLAPI_m_738298663_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardiOSDevice::setVRModeEnabled(System.Boolean)
extern "C"  void CardboardiOSDevice_setVRModeEnabled_m339614221_0 (Object_t * __this /* static, unused */, bool ___enabled, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardiOSDevice::setShowVrBackButtonOnlyInVR(System.Boolean)
extern "C"  void CardboardiOSDevice_setShowVrBackButtonOnlyInVR_m_1781800860_0 (Object_t * __this /* static, unused */, bool ___only, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardiOSDevice::setSettingsButtonEnabled(System.Boolean)
extern "C"  void CardboardiOSDevice_setSettingsButtonEnabled_m1667517303_0 (Object_t * __this /* static, unused */, bool ___enabled, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardiOSDevice::setAlignmentMarkerEnabled(System.Boolean)
extern "C"  void CardboardiOSDevice_setAlignmentMarkerEnabled_m416661801_0 (Object_t * __this /* static, unused */, bool ___enabled, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardiOSDevice::setVRBackButtonEnabled(System.Boolean)
extern "C"  void CardboardiOSDevice_setVRBackButtonEnabled_m_1364648265_0 (Object_t * __this /* static, unused */, bool ___enabled, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardiOSDevice::setSyncWithCardboardEnabled(System.Boolean)
extern "C"  void CardboardiOSDevice_setSyncWithCardboardEnabled_m_1920221679_0 (Object_t * __this /* static, unused */, bool ___enabled, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardiOSDevice::setOnboardingDone()
extern "C"  void CardboardiOSDevice_setOnboardingDone_m_153315925_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean CardboardiOSDevice::isOnboardingDone()
extern "C"  bool CardboardiOSDevice_isOnboardingDone_m_206193039_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardiOSDevice::launchSettingsDialog()
extern "C"  void CardboardiOSDevice_launchSettingsDialog_m306938964_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardiOSDevice::launchOnboardingDialog()
extern "C"  void CardboardiOSDevice_launchOnboardingDialog_m126809164_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single CardboardiOSDevice::getScreenDPI()
extern "C"  float CardboardiOSDevice_getScreenDPI_m1205670045_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
