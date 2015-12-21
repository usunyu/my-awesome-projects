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

// UnityEngine.EventSystems.PhysicsRaycaster
struct PhysicsRaycaster_t_1937649282_0;
// UnityEngine.Camera
struct Camera_t814710830_0;
// UnityEngine.EventSystems.PointerEventData
struct PointerEventData_t_1258954026_0;
// System.Collections.Generic.List`1<UnityEngine.EventSystems.RaycastResult>
struct List_1_t1613808521_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_LayerMask_1132430796.h"
#include "UnityEngine_UnityEngine_RaycastHit144185587.h"

// System.Void UnityEngine.EventSystems.PhysicsRaycaster::.ctor()
extern "C"  void PhysicsRaycaster__ctor_m_6754542_0 (PhysicsRaycaster_t_1937649282_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Camera UnityEngine.EventSystems.PhysicsRaycaster::get_eventCamera()
extern "C"  Camera_t814710830_0 * PhysicsRaycaster_get_eventCamera_m810838145_0 (PhysicsRaycaster_t_1937649282_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.EventSystems.PhysicsRaycaster::get_depth()
extern "C"  int32_t PhysicsRaycaster_get_depth_m589853138_0 (PhysicsRaycaster_t_1937649282_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.EventSystems.PhysicsRaycaster::get_finalEventMask()
extern "C"  int32_t PhysicsRaycaster_get_finalEventMask_m_2048031293_0 (PhysicsRaycaster_t_1937649282_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.LayerMask UnityEngine.EventSystems.PhysicsRaycaster::get_eventMask()
extern "C"  LayerMask_t_1132430796_0  PhysicsRaycaster_get_eventMask_m610257178_0 (PhysicsRaycaster_t_1937649282_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PhysicsRaycaster::set_eventMask(UnityEngine.LayerMask)
extern "C"  void PhysicsRaycaster_set_eventMask_m_425480589_0 (PhysicsRaycaster_t_1937649282_0 * __this, LayerMask_t_1132430796_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.EventSystems.PhysicsRaycaster::Raycast(UnityEngine.EventSystems.PointerEventData,System.Collections.Generic.List`1<UnityEngine.EventSystems.RaycastResult>)
extern "C"  void PhysicsRaycaster_Raycast_m743134250_0 (PhysicsRaycaster_t_1937649282_0 * __this, PointerEventData_t_1258954026_0 * ___eventData, List_1_t1613808521_0 * ___resultAppendList, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.EventSystems.PhysicsRaycaster::<Raycast>m__1(UnityEngine.RaycastHit,UnityEngine.RaycastHit)
extern "C"  int32_t PhysicsRaycaster_U3CRaycastU3Em__1_m_462106695_0 (Object_t * __this /* static, unused */, RaycastHit_t144185587_0  ___r1, RaycastHit_t144185587_0  ___r2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
