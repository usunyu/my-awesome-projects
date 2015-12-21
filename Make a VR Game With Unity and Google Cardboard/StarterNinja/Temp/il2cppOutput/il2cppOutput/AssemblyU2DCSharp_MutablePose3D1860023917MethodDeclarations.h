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

// MutablePose3D
struct MutablePose3D_t1860023917_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Vector3_725341337.h"
#include "UnityEngine_UnityEngine_Quaternion1989680039.h"
#include "UnityEngine_UnityEngine_Matrix4x41577636070.h"

// System.Void MutablePose3D::.ctor()
extern "C"  void MutablePose3D__ctor_m109975811_0 (MutablePose3D_t1860023917_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void MutablePose3D::Set(UnityEngine.Vector3,UnityEngine.Quaternion)
extern "C"  void MutablePose3D_Set_m735260187_0 (MutablePose3D_t1860023917_0 * __this, Vector3_t_725341337_0  ___position, Quaternion_t1989680039_0  ___orientation, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void MutablePose3D::Set(UnityEngine.Matrix4x4)
extern "C"  void MutablePose3D_Set_m1451198039_0 (MutablePose3D_t1860023917_0 * __this, Matrix4x4_t1577636070_0  ___matrix, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void MutablePose3D::SetRightHanded(UnityEngine.Matrix4x4)
extern "C"  void MutablePose3D_SetRightHanded_m1198386545_0 (MutablePose3D_t1860023917_0 * __this, Matrix4x4_t1577636070_0  ___matrix, const MethodInfo* method) IL2CPP_METHOD_ATTR;
