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

// Pose3D
struct Pose3D_t_1878999683_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Vector3_725341337.h"
#include "UnityEngine_UnityEngine_Quaternion1989680039.h"
#include "UnityEngine_UnityEngine_Matrix4x41577636070.h"

// System.Void Pose3D::.ctor()
extern "C"  void Pose3D__ctor_m184997881_0 (Pose3D_t_1878999683_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Pose3D::.ctor(UnityEngine.Vector3,UnityEngine.Quaternion)
extern "C"  void Pose3D__ctor_m_2072330095_0 (Pose3D_t_1878999683_0 * __this, Vector3_t_725341337_0  ___position, Quaternion_t1989680039_0  ___orientation, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Pose3D::.ctor(UnityEngine.Matrix4x4)
extern "C"  void Pose3D__ctor_m_1083402719_0 (Pose3D_t_1878999683_0 * __this, Matrix4x4_t1577636070_0  ___matrix, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Pose3D::.cctor()
extern "C"  void Pose3D__cctor_m957870804_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector3 Pose3D::get_Position()
extern "C"  Vector3_t_725341337_0  Pose3D_get_Position_m_1286939241_0 (Pose3D_t_1878999683_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Pose3D::set_Position(UnityEngine.Vector3)
extern "C"  void Pose3D_set_Position_m868383016_0 (Pose3D_t_1878999683_0 * __this, Vector3_t_725341337_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Quaternion Pose3D::get_Orientation()
extern "C"  Quaternion_t1989680039_0  Pose3D_get_Orientation_m114671670_0 (Pose3D_t_1878999683_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Pose3D::set_Orientation(UnityEngine.Quaternion)
extern "C"  void Pose3D_set_Orientation_m1189478037_0 (Pose3D_t_1878999683_0 * __this, Quaternion_t1989680039_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Matrix4x4 Pose3D::get_Matrix()
extern "C"  Matrix4x4_t1577636070_0  Pose3D_get_Matrix_m490356496_0 (Pose3D_t_1878999683_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Pose3D::set_Matrix(UnityEngine.Matrix4x4)
extern "C"  void Pose3D_set_Matrix_m_1756607823_0 (Pose3D_t_1878999683_0 * __this, Matrix4x4_t1577636070_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Matrix4x4 Pose3D::get_RightHandedMatrix()
extern "C"  Matrix4x4_t1577636070_0  Pose3D_get_RightHandedMatrix_m_365662754_0 (Pose3D_t_1878999683_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Pose3D::Set(UnityEngine.Vector3,UnityEngine.Quaternion)
extern "C"  void Pose3D_Set_m1511997201_0 (Pose3D_t_1878999683_0 * __this, Vector3_t_725341337_0  ___position, Quaternion_t1989680039_0  ___orientation, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Pose3D::Set(UnityEngine.Matrix4x4)
extern "C"  void Pose3D_Set_m27658145_0 (Pose3D_t_1878999683_0 * __this, Matrix4x4_t1577636070_0  ___matrix, const MethodInfo* method) IL2CPP_METHOD_ATTR;
