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


#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Plane_377038797.h"
#include "UnityEngine_UnityEngine_Vector3_725341337.h"
#include "UnityEngine_UnityEngine_Ray1215250369.h"

// System.Void UnityEngine.Plane::.ctor(UnityEngine.Vector3,UnityEngine.Vector3)
extern "C"  void Plane__ctor_m_2093920433_0 (Plane_t_377038797_0 * __this, Vector3_t_725341337_0  ___inNormal, Vector3_t_725341337_0  ___inPoint, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector3 UnityEngine.Plane::get_normal()
extern "C"  Vector3_t_725341337_0  Plane_get_normal_m_760838083_0 (Plane_t_377038797_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.Plane::get_distance()
extern "C"  float Plane_get_distance_m_1682483143_0 (Plane_t_377038797_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Plane::Raycast(UnityEngine.Ray,System.Single&)
extern "C"  bool Plane_Raycast_m_1465198190_0 (Plane_t_377038797_0 * __this, Ray_t1215250369_0  ___ray, float* ___enter, const MethodInfo* method) IL2CPP_METHOD_ATTR;
