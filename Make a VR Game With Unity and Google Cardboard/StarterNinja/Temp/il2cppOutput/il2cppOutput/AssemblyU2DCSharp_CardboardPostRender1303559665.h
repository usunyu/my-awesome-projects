#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.Mesh
struct Mesh_t_982089418_0;
// UnityEngine.Material
struct Material_t1701708784_0;
// System.Single[]
struct SingleU5BU5D_t_2105059803_0;
// UnityEngine.Camera
struct Camera_t814710830_0;

#include "UnityEngine_UnityEngine_MonoBehaviour_92453903.h"
#include "UnityEngine_UnityEngine_Matrix4x41577636070.h"

// CardboardPostRender
struct  CardboardPostRender_t1303559665_0  : public MonoBehaviour_t_92453903_0
{
	// UnityEngine.Mesh CardboardPostRender::distortionMesh
	Mesh_t_982089418_0 * ___distortionMesh_14;
	// UnityEngine.Material CardboardPostRender::meshMaterial
	Material_t1701708784_0 * ___meshMaterial_15;
	// UnityEngine.Material CardboardPostRender::uiMaterial
	Material_t1701708784_0 * ___uiMaterial_16;
	// System.Single CardboardPostRender::centerWidthPx
	float ___centerWidthPx_17;
	// System.Single CardboardPostRender::buttonWidthPx
	float ___buttonWidthPx_18;
	// System.Single CardboardPostRender::xScale
	float ___xScale_19;
	// System.Single CardboardPostRender::yScale
	float ___yScale_20;
	// UnityEngine.Matrix4x4 CardboardPostRender::xfm
	Matrix4x4_t1577636070_0  ___xfm_21;
	// UnityEngine.Camera CardboardPostRender::<camera>k__BackingField
	Camera_t814710830_0 * ___U3CcameraU3Ek__BackingField_23;
};
struct CardboardPostRender_t1303559665_0_StaticFields{
	// System.Single[] CardboardPostRender::Angles
	SingleU5BU5D_t_2105059803_0* ___Angles_22;
};
