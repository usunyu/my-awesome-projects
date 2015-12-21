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

// UnityEngine.EventSystems.BaseInputModule
struct BaseInputModule_t_1390847434_0;
// UnityEngine.EventSystems.EventSystem
struct EventSystem_t813375706_0;
// System.Collections.Generic.List`1<UnityEngine.EventSystems.RaycastResult>
struct List_1_t1613808521_0;
// UnityEngine.GameObject
struct GameObject_t_184308134_0;
// UnityEngine.EventSystems.PointerEventData
struct PointerEventData_t_1258954026_0;
// UnityEngine.EventSystems.AxisEventData
struct AxisEventData_t1026836980_0;
// UnityEngine.EventSystems.BaseEventData
struct BaseEventData_t_273923900_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UI_UnityEngine_EventSystems_RaycastRes1433838359.h"
#include "UnityEngine_UI_UnityEngine_EventSystems_MoveDirecti511359455.h"

// System.Void UnityEngine.EventSystems.BaseInputModule::.ctor()
extern "C"  void BaseInputModule__ctor_m_1374166240_0 (BaseInputModule_t_1390847434_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.EventSystem UnityEngine.EventSystems.BaseInputModule::get_eventSystem()
extern "C"  EventSystem_t813375706_0 * BaseInputModule_get_eventSystem_m_345841565_0 (BaseInputModule_t_1390847434_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.BaseInputModule::OnEnable()
extern "C"  void BaseInputModule_OnEnable_m_381579162_0 (BaseInputModule_t_1390847434_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.BaseInputModule::OnDisable()
extern "C"  void BaseInputModule_OnDisable_m1496885127_0 (BaseInputModule_t_1390847434_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.RaycastResult UnityEngine.EventSystems.BaseInputModule::FindFirstRaycast(System.Collections.Generic.List`1<UnityEngine.EventSystems.RaycastResult>)
extern "C"  RaycastResult_t1433838359_0  BaseInputModule_FindFirstRaycast_m_519852713_0 (Object_t * __this /* static, unused */, List_1_t1613808521_0 * ___candidates, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.MoveDirection UnityEngine.EventSystems.BaseInputModule::DetermineMoveDirection(System.Single,System.Single)
extern "C"  int32_t BaseInputModule_DetermineMoveDirection_m1298463611_0 (Object_t * __this /* static, unused */, float ___x, float ___y, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.MoveDirection UnityEngine.EventSystems.BaseInputModule::DetermineMoveDirection(System.Single,System.Single,System.Single)
extern "C"  int32_t BaseInputModule_DetermineMoveDirection_m1501057824_0 (Object_t * __this /* static, unused */, float ___x, float ___y, float ___deadZone, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.EventSystems.BaseInputModule::FindCommonRoot(UnityEngine.GameObject,UnityEngine.GameObject)
extern "C"  GameObject_t_184308134_0 * BaseInputModule_FindCommonRoot_m1904275501_0 (Object_t * __this /* static, unused */, GameObject_t_184308134_0 * ___g1, GameObject_t_184308134_0 * ___g2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.BaseInputModule::HandlePointerExitAndEnter(UnityEngine.EventSystems.PointerEventData,UnityEngine.GameObject)
extern "C"  void BaseInputModule_HandlePointerExitAndEnter_m779127058_0 (BaseInputModule_t_1390847434_0 * __this, PointerEventData_t_1258954026_0 * ___currentPointerData, GameObject_t_184308134_0 * ___newEnterTarget, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.AxisEventData UnityEngine.EventSystems.BaseInputModule::GetAxisEventData(System.Single,System.Single,System.Single)
extern "C"  AxisEventData_t1026836980_0 * BaseInputModule_GetAxisEventData_m_505927805_0 (BaseInputModule_t_1390847434_0 * __this, float ___x, float ___y, float ___moveDeadZone, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.BaseEventData UnityEngine.EventSystems.BaseInputModule::GetBaseEventData()
extern "C"  BaseEventData_t_273923900_0 * BaseInputModule_GetBaseEventData_m1707430642_0 (BaseInputModule_t_1390847434_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.BaseInputModule::IsPointerOverGameObject(System.Int32)
extern "C"  bool BaseInputModule_IsPointerOverGameObject_m674758553_0 (BaseInputModule_t_1390847434_0 * __this, int32_t ___pointerId, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.BaseInputModule::ShouldActivateModule()
extern "C"  bool BaseInputModule_ShouldActivateModule_m222600132_0 (BaseInputModule_t_1390847434_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.BaseInputModule::DeactivateModule()
extern "C"  void BaseInputModule_DeactivateModule_m_1722448476_0 (BaseInputModule_t_1390847434_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.BaseInputModule::ActivateModule()
extern "C"  void BaseInputModule_ActivateModule_m1091790819_0 (BaseInputModule_t_1390847434_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.BaseInputModule::UpdateModule()
extern "C"  void BaseInputModule_UpdateModule_m_1602973063_0 (BaseInputModule_t_1390847434_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.BaseInputModule::IsModuleSupported()
extern "C"  bool BaseInputModule_IsModuleSupported_m_49642424_0 (BaseInputModule_t_1390847434_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
