#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// Cardboard
struct Cardboard_t1550393659_0;
// UnityEngine.Camera
struct Camera_t814710830_0;
// StereoController
struct StereoController_t1679119023_0;
// BaseVRDevice
struct BaseVRDevice_t1612809342_0;
// UnityEngine.RenderTexture
struct RenderTexture_t1203146108_0;
// System.Uri
struct Uri_t18014439_0;
// Cardboard/StereoScreenChangeDelegate
struct StereoScreenChangeDelegate_t509462125_0;
// System.Action
struct Action_t2132293834_0;

#include "UnityEngine_UnityEngine_MonoBehaviour_92453903.h"
#include "AssemblyU2DCSharp_Cardboard_DistortionCorrectionMet122018320.h"
#include "AssemblyU2DCSharp_Cardboard_BackButtonModes2114367171.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"

// Cardboard
struct  Cardboard_t1550393659_0  : public MonoBehaviour_t_92453903_0
{
	// System.Boolean Cardboard::vrModeEnabled
	bool ___vrModeEnabled_5;
	// Cardboard/DistortionCorrectionMethod Cardboard::distortionCorrection
	int32_t ___distortionCorrection_6;
	// System.Boolean Cardboard::enableAlignmentMarker
	bool ___enableAlignmentMarker_7;
	// System.Boolean Cardboard::enableSettingsButton
	bool ___enableSettingsButton_8;
	// Cardboard/BackButtonModes Cardboard::backButtonMode
	int32_t ___backButtonMode_9;
	// System.Boolean Cardboard::tapIsTrigger
	bool ___tapIsTrigger_10;
	// System.Single Cardboard::neckModelScale
	float ___neckModelScale_11;
	// System.Boolean Cardboard::autoDriftCorrection
	bool ___autoDriftCorrection_12;
	// System.Boolean Cardboard::electronicDisplayStabilization
	bool ___electronicDisplayStabilization_13;
	// System.Boolean Cardboard::syncWithCardboardApp
	bool ___syncWithCardboardApp_14;
	// System.Single Cardboard::stereoScreenScale
	float ___stereoScreenScale_16;
	// UnityEngine.Vector2 Cardboard::defaultComfortableViewingRange
	Vector2_t_725341338_0  ___defaultComfortableViewingRange_18;
	// System.Uri Cardboard::DefaultDeviceProfile
	Uri_t18014439_0 * ___DefaultDeviceProfile_19;
	// System.Boolean Cardboard::updated
	bool ___updated_20;
	// Cardboard/StereoScreenChangeDelegate Cardboard::OnStereoScreenChanged
	StereoScreenChangeDelegate_t509462125_0 * ___OnStereoScreenChanged_21;
	// System.Action Cardboard::OnTrigger
	Action_t2132293834_0 * ___OnTrigger_22;
	// System.Action Cardboard::OnTilt
	Action_t2132293834_0 * ___OnTilt_23;
	// System.Action Cardboard::OnProfileChange
	Action_t2132293834_0 * ___OnProfileChange_24;
	// System.Action Cardboard::OnBackButton
	Action_t2132293834_0 * ___OnBackButton_25;
	// System.Boolean Cardboard::<NativeDistortionCorrectionSupported>k__BackingField
	bool ___U3CNativeDistortionCorrectionSupportedU3Ek__BackingField_26;
	// System.Boolean Cardboard::<NativeUILayerSupported>k__BackingField
	bool ___U3CNativeUILayerSupportedU3Ek__BackingField_27;
	// System.Boolean Cardboard::<Triggered>k__BackingField
	bool ___U3CTriggeredU3Ek__BackingField_28;
	// System.Boolean Cardboard::<Tilted>k__BackingField
	bool ___U3CTiltedU3Ek__BackingField_29;
	// System.Boolean Cardboard::<ProfileChanged>k__BackingField
	bool ___U3CProfileChangedU3Ek__BackingField_30;
	// System.Boolean Cardboard::<BackButtonPressed>k__BackingField
	bool ___U3CBackButtonPressedU3Ek__BackingField_31;
};
struct Cardboard_t1550393659_0_StaticFields{
	// Cardboard Cardboard::sdk
	Cardboard_t1550393659_0 * ___sdk_2;
	// UnityEngine.Camera Cardboard::currentMainCamera
	Camera_t814710830_0 * ___currentMainCamera_3;
	// StereoController Cardboard::currentController
	StereoController_t1679119023_0 * ___currentController_4;
	// BaseVRDevice Cardboard::device
	BaseVRDevice_t1612809342_0 * ___device_15;
	// UnityEngine.RenderTexture Cardboard::stereoScreen
	RenderTexture_t1203146108_0 * ___stereoScreen_17;
};
