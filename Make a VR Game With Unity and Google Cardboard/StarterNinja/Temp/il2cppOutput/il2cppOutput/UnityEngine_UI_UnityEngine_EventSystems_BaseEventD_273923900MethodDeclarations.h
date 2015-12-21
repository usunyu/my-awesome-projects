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

// UnityEngine.EventSystems.BaseEventData
struct BaseEventData_t_273923900_0;
// UnityEngine.EventSystems.EventSystem
struct EventSystem_t813375706_0;
// UnityEngine.EventSystems.BaseInputModule
struct BaseInputModule_t_1390847434_0;
// UnityEngine.GameObject
struct GameObject_t_184308134_0;

#include "codegen/il2cpp-codegen.h"

// System.Void UnityEngine.EventSystems.BaseEventData::.ctor(UnityEngine.EventSystems.EventSystem)
extern "C"  void BaseEventData__ctor_m_1048614314_0 (BaseEventData_t_273923900_0 * __this, EventSystem_t813375706_0 * ___eventSystem, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.BaseInputModule UnityEngine.EventSystems.BaseEventData::get_currentInputModule()
extern "C"  BaseInputModule_t_1390847434_0 * BaseEventData_get_currentInputModule_m502779959_0 (BaseEventData_t_273923900_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.EventSystems.BaseEventData::get_selectedObject()
extern "C"  GameObject_t_184308134_0 * BaseEventData_get_selectedObject_m2003968484_0 (BaseEventData_t_273923900_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.BaseEventData::set_selectedObject(UnityEngine.GameObject)
extern "C"  void BaseEventData_set_selectedObject_m_382536639_0 (BaseEventData_t_273923900_0 * __this, GameObject_t_184308134_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
