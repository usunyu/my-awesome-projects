#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>


#include "mscorlib_System_Object_887538054.h"
#include "UnityEngine_UnityEngine_Matrix4x41577636070.h"
#include "UnityEngine_UnityEngine_Vector3_725341337.h"
#include "UnityEngine_UnityEngine_Quaternion1989680039.h"

// Pose3D
struct  Pose3D_t_1878999683_0  : public Object_t
{
	// UnityEngine.Vector3 Pose3D::<Position>k__BackingField
	Vector3_t_725341337_0  ___U3CPositionU3Ek__BackingField_1;
	// UnityEngine.Quaternion Pose3D::<Orientation>k__BackingField
	Quaternion_t1989680039_0  ___U3COrientationU3Ek__BackingField_2;
	// UnityEngine.Matrix4x4 Pose3D::<Matrix>k__BackingField
	Matrix4x4_t1577636070_0  ___U3CMatrixU3Ek__BackingField_3;
};
struct Pose3D_t_1878999683_0_StaticFields{
	// UnityEngine.Matrix4x4 Pose3D::flipZ
	Matrix4x4_t1577636070_0  ___flipZ_0;
};
