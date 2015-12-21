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

// CardboardPostRender
struct CardboardPostRender_t1303559665_0;
// UnityEngine.Camera
struct Camera_t814710830_0;
// UnityEngine.Vector3[]
struct Vector3U5BU5D_t_1268319991_0;
// UnityEngine.Vector2[]
struct Vector2U5BU5D_t_1268320952_0;
// UnityEngine.Color[]
struct ColorU5BU5D_t_113585636_0;
// System.Int32[]
struct Int32U5BU5D_t1872284309_0;

#include "codegen/il2cpp-codegen.h"

// System.Void CardboardPostRender::.ctor()
extern "C"  void CardboardPostRender__ctor_m1721374783_0 (CardboardPostRender_t1303559665_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardPostRender::.cctor()
extern "C"  void CardboardPostRender__cctor_m1340914510_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Camera CardboardPostRender::get_camera()
extern "C"  Camera_t814710830_0 * CardboardPostRender_get_camera_m1025661938_0 (CardboardPostRender_t1303559665_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardPostRender::set_camera(UnityEngine.Camera)
extern "C"  void CardboardPostRender_set_camera_m_85689333_0 (CardboardPostRender_t1303559665_0 * __this, Camera_t814710830_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardPostRender::Reset()
extern "C"  void CardboardPostRender_Reset_m_632192276_0 (CardboardPostRender_t1303559665_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardPostRender::Awake()
extern "C"  void CardboardPostRender_Awake_m1958980002_0 (CardboardPostRender_t1303559665_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardPostRender::OnRenderObject()
extern "C"  void CardboardPostRender_OnRenderObject_m515791641_0 (CardboardPostRender_t1303559665_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardPostRender::RebuildDistortionMesh()
extern "C"  void CardboardPostRender_RebuildDistortionMesh_m383685954_0 (CardboardPostRender_t1303559665_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardPostRender::ComputeMeshPoints(System.Int32,System.Int32,System.Boolean,UnityEngine.Vector3[]&,UnityEngine.Vector2[]&)
extern "C"  void CardboardPostRender_ComputeMeshPoints_m_1357775654_0 (Object_t * __this /* static, unused */, int32_t ___width, int32_t ___height, bool ___distortVertices, Vector3U5BU5D_t_1268319991_0** ___vertices, Vector2U5BU5D_t_1268320952_0** ___tex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Color[] CardboardPostRender::ComputeMeshColors(System.Int32,System.Int32,UnityEngine.Vector2[],System.Int32[],System.Boolean)
extern "C"  ColorU5BU5D_t_113585636_0* CardboardPostRender_ComputeMeshColors_m1050881162_0 (Object_t * __this /* static, unused */, int32_t ___width, int32_t ___height, Vector2U5BU5D_t_1268320952_0* ___tex, Int32U5BU5D_t1872284309_0* ___indices, bool ___distortVertices, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32[] CardboardPostRender::ComputeMeshIndices(System.Int32,System.Int32,System.Boolean)
extern "C"  Int32U5BU5D_t1872284309_0* CardboardPostRender_ComputeMeshIndices_m1035625811_0 (Object_t * __this /* static, unused */, int32_t ___width, int32_t ___height, bool ___distortVertices, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardPostRender::DrawUILayer()
extern "C"  void CardboardPostRender_DrawUILayer_m762137462_0 (CardboardPostRender_t1303559665_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardPostRender::ComputeUIMatrix()
extern "C"  void CardboardPostRender_ComputeUIMatrix_m_1796280311_0 (CardboardPostRender_t1303559665_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardPostRender::DrawSettingsButton()
extern "C"  void CardboardPostRender_DrawSettingsButton_m129227646_0 (CardboardPostRender_t1303559665_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardPostRender::DrawAlignmentMarker()
extern "C"  void CardboardPostRender_DrawAlignmentMarker_m_1808117706_0 (CardboardPostRender_t1303559665_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CardboardPostRender::DrawVRBackButton()
extern "C"  void CardboardPostRender_DrawVRBackButton_m1542617854_0 (CardboardPostRender_t1303559665_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
