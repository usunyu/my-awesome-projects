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

// UnityEngine.EventSystems.TouchInputModule
struct TouchInputModule_t2081937734_0;
// UnityEngine.EventSystems.PointerEventData
struct PointerEventData_t_1258954026_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"

// System.Void UnityEngine.EventSystems.TouchInputModule::.ctor()
extern "C"  void TouchInputModule__ctor_m339421258_0 (TouchInputModule_t2081937734_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.TouchInputModule::get_allowActivationOnStandalone()
extern "C"  bool TouchInputModule_get_allowActivationOnStandalone_m_1319413104_0 (TouchInputModule_t2081937734_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.TouchInputModule::set_allowActivationOnStandalone(System.Boolean)
extern "C"  void TouchInputModule_set_allowActivationOnStandalone_m_1450635707_0 (TouchInputModule_t2081937734_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.TouchInputModule::get_forceModuleActive()
extern "C"  bool TouchInputModule_get_forceModuleActive_m_583250998_0 (TouchInputModule_t2081937734_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.TouchInputModule::set_forceModuleActive(System.Boolean)
extern "C"  void TouchInputModule_set_forceModuleActive_m_631216257_0 (TouchInputModule_t2081937734_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.TouchInputModule::UpdateModule()
extern "C"  void TouchInputModule_UpdateModule_m1492847119_0 (TouchInputModule_t2081937734_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.TouchInputModule::IsModuleSupported()
extern "C"  bool TouchInputModule_IsModuleSupported_m_1036570674_0 (TouchInputModule_t2081937734_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.TouchInputModule::ShouldActivateModule()
extern "C"  bool TouchInputModule_ShouldActivateModule_m1989212798_0 (TouchInputModule_t2081937734_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.TouchInputModule::UseFakeInput()
extern "C"  bool TouchInputModule_UseFakeInput_m1788394586_0 (TouchInputModule_t2081937734_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.TouchInputModule::Process()
extern "C"  void TouchInputModule_Process_m_1681043881_0 (TouchInputModule_t2081937734_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.TouchInputModule::FakeTouches()
extern "C"  void TouchInputModule_FakeTouches_m1483201856_0 (TouchInputModule_t2081937734_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.TouchInputModule::ProcessTouchEvents()
extern "C"  void TouchInputModule_ProcessTouchEvents_m_1642763005_0 (TouchInputModule_t2081937734_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.TouchInputModule::ProcessTouchPress(UnityEngine.EventSystems.PointerEventData,System.Boolean,System.Boolean)
extern "C"  void TouchInputModule_ProcessTouchPress_m_1017374525_0 (TouchInputModule_t2081937734_0 * __this, PointerEventData_t_1258954026_0 * ___pointerEvent, bool ___pressed, bool ___released, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.TouchInputModule::DeactivateModule()
extern "C"  void TouchInputModule_DeactivateModule_m873087546_0 (TouchInputModule_t2081937734_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.EventSystems.TouchInputModule::ToString()
extern "C"  String_t* TouchInputModule_ToString_m_1951352541_0 (TouchInputModule_t2081937734_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
