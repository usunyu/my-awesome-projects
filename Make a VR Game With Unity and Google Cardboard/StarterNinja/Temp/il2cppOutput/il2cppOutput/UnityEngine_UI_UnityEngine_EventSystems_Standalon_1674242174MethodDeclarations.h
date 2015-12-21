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

// UnityEngine.EventSystems.StandaloneInputModule
struct StandaloneInputModule_t_1674242174_0;
// System.String
struct String_t;
// UnityEngine.EventSystems.PointerEventData
struct PointerEventData_t_1258954026_0;
// UnityEngine.EventSystems.PointerInputModule/MouseButtonEventData
struct MouseButtonEventData_t1282251508_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UI_UnityEngine_EventSystems_Standalone2094010912.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"

// System.Void UnityEngine.EventSystems.StandaloneInputModule::.ctor()
extern "C"  void StandaloneInputModule__ctor_m_709705452_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.StandaloneInputModule/InputMode UnityEngine.EventSystems.StandaloneInputModule::get_inputMode()
extern "C"  int32_t StandaloneInputModule_get_inputMode_m_611749823_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.StandaloneInputModule::get_allowActivationOnMobileDevice()
extern "C"  bool StandaloneInputModule_get_allowActivationOnMobileDevice_m898677649_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.StandaloneInputModule::set_allowActivationOnMobileDevice(System.Boolean)
extern "C"  void StandaloneInputModule_set_allowActivationOnMobileDevice_m_1578660894_0 (StandaloneInputModule_t_1674242174_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.StandaloneInputModule::get_forceModuleActive()
extern "C"  bool StandaloneInputModule_get_forceModuleActive_m_31364168_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.StandaloneInputModule::set_forceModuleActive(System.Boolean)
extern "C"  void StandaloneInputModule_set_forceModuleActive_m_1473510711_0 (StandaloneInputModule_t_1674242174_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.EventSystems.StandaloneInputModule::get_inputActionsPerSecond()
extern "C"  float StandaloneInputModule_get_inputActionsPerSecond_m386579003_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.StandaloneInputModule::set_inputActionsPerSecond(System.Single)
extern "C"  void StandaloneInputModule_set_inputActionsPerSecond_m_332294728_0 (StandaloneInputModule_t_1674242174_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.EventSystems.StandaloneInputModule::get_repeatDelay()
extern "C"  float StandaloneInputModule_get_repeatDelay_m756347909_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.StandaloneInputModule::set_repeatDelay(System.Single)
extern "C"  void StandaloneInputModule_set_repeatDelay_m_1011190226_0 (StandaloneInputModule_t_1674242174_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.EventSystems.StandaloneInputModule::get_horizontalAxis()
extern "C"  String_t* StandaloneInputModule_get_horizontalAxis_m_170461791_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.StandaloneInputModule::set_horizontalAxis(System.String)
extern "C"  void StandaloneInputModule_set_horizontalAxis_m1994117648_0 (StandaloneInputModule_t_1674242174_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.EventSystems.StandaloneInputModule::get_verticalAxis()
extern "C"  String_t* StandaloneInputModule_get_verticalAxis_m828001843_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.StandaloneInputModule::set_verticalAxis(System.String)
extern "C"  void StandaloneInputModule_set_verticalAxis_m_1285165442_0 (StandaloneInputModule_t_1674242174_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.EventSystems.StandaloneInputModule::get_submitButton()
extern "C"  String_t* StandaloneInputModule_get_submitButton_m1573295782_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.StandaloneInputModule::set_submitButton(System.String)
extern "C"  void StandaloneInputModule_set_submitButton_m_305121045_0 (StandaloneInputModule_t_1674242174_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.EventSystems.StandaloneInputModule::get_cancelButton()
extern "C"  String_t* StandaloneInputModule_get_cancelButton_m_1245117688_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.StandaloneInputModule::set_cancelButton(System.String)
extern "C"  void StandaloneInputModule_set_cancelButton_m822377417_0 (StandaloneInputModule_t_1674242174_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.StandaloneInputModule::UpdateModule()
extern "C"  void StandaloneInputModule_UpdateModule_m_34219515_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.StandaloneInputModule::IsModuleSupported()
extern "C"  bool StandaloneInputModule_IsModuleSupported_m1519744700_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.StandaloneInputModule::ShouldActivateModule()
extern "C"  bool StandaloneInputModule_ShouldActivateModule_m_1179573040_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.StandaloneInputModule::ActivateModule()
extern "C"  void StandaloneInputModule_ActivateModule_m1130429551_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.StandaloneInputModule::DeactivateModule()
extern "C"  void StandaloneInputModule_DeactivateModule_m1049634608_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.StandaloneInputModule::Process()
extern "C"  void StandaloneInputModule_Process_m_574497631_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.StandaloneInputModule::ProcessTouchEvents()
extern "C"  bool StandaloneInputModule_ProcessTouchEvents_m_727479353_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.StandaloneInputModule::ProcessTouchPress(UnityEngine.EventSystems.PointerEventData,System.Boolean,System.Boolean)
extern "C"  void StandaloneInputModule_ProcessTouchPress_m_1341261895_0 (StandaloneInputModule_t_1674242174_0 * __this, PointerEventData_t_1258954026_0 * ___pointerEvent, bool ___pressed, bool ___released, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.StandaloneInputModule::SendSubmitEventToSelectedObject()
extern "C"  bool StandaloneInputModule_SendSubmitEventToSelectedObject_m_2111223661_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.EventSystems.StandaloneInputModule::GetRawMoveVector()
extern "C"  Vector2_t_725341338_0  StandaloneInputModule_GetRawMoveVector_m_814307247_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.StandaloneInputModule::SendMoveEventToSelectedObject()
extern "C"  bool StandaloneInputModule_SendMoveEventToSelectedObject_m439066490_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.StandaloneInputModule::ProcessMouseEvent()
extern "C"  void StandaloneInputModule_ProcessMouseEvent_m_1367661450_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.StandaloneInputModule::ProcessMouseEvent(System.Int32)
extern "C"  void StandaloneInputModule_ProcessMouseEvent_m1104664775_0 (StandaloneInputModule_t_1674242174_0 * __this, int32_t ___id, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.StandaloneInputModule::SendUpdateEventToSelectedObject()
extern "C"  bool StandaloneInputModule_SendUpdateEventToSelectedObject_m1730287810_0 (StandaloneInputModule_t_1674242174_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.StandaloneInputModule::ProcessMousePress(UnityEngine.EventSystems.PointerInputModule/MouseButtonEventData)
extern "C"  void StandaloneInputModule_ProcessMousePress_m794465737_0 (StandaloneInputModule_t_1674242174_0 * __this, MouseButtonEventData_t1282251508_0 * ___data, const MethodInfo* method) IL2CPP_METHOD_ATTR;
