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

// UnityEngine.EventSystems.AxisEventData
struct AxisEventData_t1026836980_0;
// UnityEngine.EventSystems.EventSystem
struct EventSystem_t813375706_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"
#include "UnityEngine_UI_UnityEngine_EventSystems_MoveDirecti511359455.h"

// System.Void UnityEngine.EventSystems.AxisEventData::.ctor(UnityEngine.EventSystems.EventSystem)
extern "C"  void AxisEventData__ctor_m_883126490_0 (AxisEventData_t1026836980_0 * __this, EventSystem_t813375706_0 * ___eventSystem, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.EventSystems.AxisEventData::get_moveVector()
extern "C"  Vector2_t_725341338_0  AxisEventData_get_moveVector_m_1297873702_0 (AxisEventData_t1026836980_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.AxisEventData::set_moveVector(UnityEngine.Vector2)
extern "C"  void AxisEventData_set_moveVector_m286185191_0 (AxisEventData_t1026836980_0 * __this, Vector2_t_725341338_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventSystems.MoveDirection UnityEngine.EventSystems.AxisEventData::get_moveDir()
extern "C"  int32_t AxisEventData_get_moveDir_m_1555501187_0 (AxisEventData_t1026836980_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.AxisEventData::set_moveDir(UnityEngine.EventSystems.MoveDirection)
extern "C"  void AxisEventData_set_moveDir_m_2081398370_0 (AxisEventData_t1026836980_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
