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

// UnityEngine.EventSystems.EventSystem
struct EventSystem_t813375706_0;
// UnityEngine.EventSystems.BaseInputModule
struct BaseInputModule_t_1390847434_0;
// UnityEngine.GameObject
struct GameObject_t_184308134_0;
// UnityEngine.EventSystems.BaseEventData
struct BaseEventData_t_273923900_0;
// UnityEngine.EventSystems.PointerEventData
struct PointerEventData_t_1258954026_0;
// System.Collections.Generic.List`1<UnityEngine.EventSystems.RaycastResult>
struct List_1_t1613808521_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UI_UnityEngine_EventSystems_RaycastRes1433838359.h"

// System.Void UnityEngine.EventSystems.EventSystem::.ctor()
extern "C"  void EventSystem__ctor_m1614698108_0 (EventSystem_t813375706_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventSystem::.cctor()
extern "C"  void EventSystem__cctor_m_1966062415_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.EventSystem UnityEngine.EventSystems.EventSystem::get_current()
extern "C"  EventSystem_t813375706_0 * EventSystem_get_current_m_811429425_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventSystem::set_current(UnityEngine.EventSystems.EventSystem)
extern "C"  void EventSystem_set_current_m_1224118310_0 (Object_t * __this /* static, unused */, EventSystem_t813375706_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.EventSystem::get_sendNavigationEvents()
extern "C"  bool EventSystem_get_sendNavigationEvents_m_1536308812_0 (EventSystem_t813375706_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventSystem::set_sendNavigationEvents(System.Boolean)
extern "C"  void EventSystem_set_sendNavigationEvents_m332228817_0 (EventSystem_t813375706_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.EventSystems.EventSystem::get_pixelDragThreshold()
extern "C"  int32_t EventSystem_get_pixelDragThreshold_m_1025719286_0 (EventSystem_t813375706_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventSystem::set_pixelDragThreshold(System.Int32)
extern "C"  void EventSystem_set_pixelDragThreshold_m_1200122905_0 (EventSystem_t813375706_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.BaseInputModule UnityEngine.EventSystems.EventSystem::get_currentInputModule()
extern "C"  BaseInputModule_t_1390847434_0 * EventSystem_get_currentInputModule_m1694913485_0 (EventSystem_t813375706_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.EventSystems.EventSystem::get_firstSelectedGameObject()
extern "C"  GameObject_t_184308134_0 * EventSystem_get_firstSelectedGameObject_m540473918_0 (EventSystem_t813375706_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventSystem::set_firstSelectedGameObject(UnityEngine.GameObject)
extern "C"  void EventSystem_set_firstSelectedGameObject_m1040716465_0 (EventSystem_t813375706_0 * __this, GameObject_t_184308134_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.EventSystems.EventSystem::get_currentSelectedGameObject()
extern "C"  GameObject_t_184308134_0 * EventSystem_get_currentSelectedGameObject_m_58883513_0 (EventSystem_t813375706_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.EventSystems.EventSystem::get_lastSelectedGameObject()
extern "C"  GameObject_t_184308134_0 * EventSystem_get_lastSelectedGameObject_m_1943441982_0 (EventSystem_t813375706_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventSystem::UpdateModules()
extern "C"  void EventSystem_UpdateModules_m_1598411368_0 (EventSystem_t813375706_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.EventSystem::get_alreadySelecting()
extern "C"  bool EventSystem_get_alreadySelecting_m_1220008339_0 (EventSystem_t813375706_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventSystem::SetSelectedGameObject(UnityEngine.GameObject,UnityEngine.EventSystems.BaseEventData)
extern "C"  void EventSystem_SetSelectedGameObject_m2116591616_0 (EventSystem_t813375706_0 * __this, GameObject_t_184308134_0 * ___selected, BaseEventData_t_273923900_0 * ___pointer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.BaseEventData UnityEngine.EventSystems.EventSystem::get_baseEventDataCache()
extern "C"  BaseEventData_t_273923900_0 * EventSystem_get_baseEventDataCache_m1763003665_0 (EventSystem_t813375706_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventSystem::SetSelectedGameObject(UnityEngine.GameObject)
extern "C"  void EventSystem_SetSelectedGameObject_m1869236832_0 (EventSystem_t813375706_0 * __this, GameObject_t_184308134_0 * ___selected, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.EventSystems.EventSystem::RaycastComparer(UnityEngine.EventSystems.RaycastResult,UnityEngine.EventSystems.RaycastResult)
extern "C"  int32_t EventSystem_RaycastComparer_m_1116306306_0 (Object_t * __this /* static, unused */, RaycastResult_t1433838359_0  ___lhs, RaycastResult_t1433838359_0  ___rhs, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventSystem::RaycastAll(UnityEngine.EventSystems.PointerEventData,System.Collections.Generic.List`1<UnityEngine.EventSystems.RaycastResult>)
extern "C"  void EventSystem_RaycastAll_m538533603_0 (EventSystem_t813375706_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, List_1_t1613808521_0 * ___raycastResults, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.EventSystem::IsPointerOverGameObject()
extern "C"  bool EventSystem_IsPointerOverGameObject_m_18508892_0 (EventSystem_t813375706_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.EventSystems.EventSystem::IsPointerOverGameObject(System.Int32)
extern "C"  bool EventSystem_IsPointerOverGameObject_m_291573003_0 (EventSystem_t813375706_0 * __this, int32_t ___pointerId, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventSystem::OnEnable()
extern "C"  void EventSystem_OnEnable_m1909198730_0 (EventSystem_t813375706_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventSystem::OnDisable()
extern "C"  void EventSystem_OnDisable_m_503444253_0 (EventSystem_t813375706_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventSystem::TickModules()
extern "C"  void EventSystem_TickModules_m_220637820_0 (EventSystem_t813375706_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventSystem::Update()
extern "C"  void EventSystem_Update_m242895889_0 (EventSystem_t813375706_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.EventSystem::ChangeEventModule(UnityEngine.EventSystems.BaseInputModule)
extern "C"  void EventSystem_ChangeEventModule_m1717769816_0 (EventSystem_t813375706_0 * __this, BaseInputModule_t_1390847434_0 * ___module, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.EventSystems.EventSystem::ToString()
extern "C"  String_t* EventSystem_ToString_m_450419049_0 (EventSystem_t813375706_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
