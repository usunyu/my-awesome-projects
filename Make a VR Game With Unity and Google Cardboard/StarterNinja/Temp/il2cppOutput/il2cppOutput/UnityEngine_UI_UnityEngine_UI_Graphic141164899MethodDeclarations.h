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

// UnityEngine.UI.Graphic
struct Graphic_t141164899_0;
// UnityEngine.Material
struct Material_t1701708784_0;
// UnityEngine.RectTransform
struct RectTransform_t212748479_0;
// UnityEngine.Canvas
struct Canvas_t814756449_0;
// UnityEngine.CanvasRenderer
struct CanvasRenderer_t310896196_0;
// UnityEngine.Texture
struct Texture_t1814018354_0;
// UnityEngine.Mesh
struct Mesh_t_982089418_0;
// System.Collections.Generic.List`1<UnityEngine.UIVertex>
struct List_1_t757324127_0;
// UnityEngine.UI.VertexHelper
struct VertexHelper_t786786519_0;
// UnityEngine.Camera
struct Camera_t814710830_0;
// UnityEngine.Events.UnityAction
struct UnityAction_t502362143_0;
// UnityEngine.Transform
struct Transform_t1584899523_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Color_388944582.h"
#include "UnityEngine_UI_UnityEngine_UI_CanvasUpdate256425638.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"
#include "UnityEngine_UnityEngine_Rect_981940947.h"

// System.Void UnityEngine.UI.Graphic::.ctor()
extern "C"  void Graphic__ctor_m_228397741_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::.cctor()
extern "C"  void Graphic__cctor_m1027508410_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Material UnityEngine.UI.Graphic::get_defaultGraphicMaterial()
extern "C"  Material_t1701708784_0 * Graphic_get_defaultGraphicMaterial_m456140641_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Color UnityEngine.UI.Graphic::get_color()
extern "C"  Color_t_388944582_0  Graphic_get_color_m2048831972_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::set_color(UnityEngine.Color)
extern "C"  void Graphic_set_color_m1311501487_0 (Graphic_t141164899_0 * __this, Color_t_388944582_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.Graphic::get_raycastTarget()
extern "C"  bool Graphic_get_raycastTarget_m_858317964_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::set_raycastTarget(System.Boolean)
extern "C"  void Graphic_set_raycastTarget_m639541381_0 (Graphic_t141164899_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.Graphic::get_useLegacyMeshGeneration()
extern "C"  bool Graphic_get_useLegacyMeshGeneration_m1330224975_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::set_useLegacyMeshGeneration(System.Boolean)
extern "C"  void Graphic_set_useLegacyMeshGeneration_m693817504_0 (Graphic_t141164899_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::SetAllDirty()
extern "C"  void Graphic_SetAllDirty_m2074784484_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::SetLayoutDirty()
extern "C"  void Graphic_SetLayoutDirty_m_2129688297_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::SetVerticesDirty()
extern "C"  void Graphic_SetVerticesDirty_m_1981789720_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::SetMaterialDirty()
extern "C"  void Graphic_SetMaterialDirty_m282639610_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::OnRectTransformDimensionsChange()
extern "C"  void Graphic_OnRectTransformDimensionsChange_m1660020535_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::OnBeforeTransformParentChanged()
extern "C"  void Graphic_OnBeforeTransformParentChanged_m_1682319091_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::OnTransformParentChanged()
extern "C"  void Graphic_OnTransformParentChanged_m321513902_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.UI.Graphic::get_depth()
extern "C"  int32_t Graphic_get_depth_m1908843203_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.RectTransform UnityEngine.UI.Graphic::get_rectTransform()
extern "C"  RectTransform_t212748479_0 * Graphic_get_rectTransform_m_277595346_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Canvas UnityEngine.UI.Graphic::get_canvas()
extern "C"  Canvas_t814756449_0 * Graphic_get_canvas_m_3583046_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::CacheCanvas()
extern "C"  void Graphic_CacheCanvas_m512847723_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.CanvasRenderer UnityEngine.UI.Graphic::get_canvasRenderer()
extern "C"  CanvasRenderer_t310896196_0 * Graphic_get_canvasRenderer_m184553434_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Material UnityEngine.UI.Graphic::get_defaultMaterial()
extern "C"  Material_t1701708784_0 * Graphic_get_defaultMaterial_m_1200964713_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Material UnityEngine.UI.Graphic::get_material()
extern "C"  Material_t1701708784_0 * Graphic_get_material_m_913873382_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::set_material(UnityEngine.Material)
extern "C"  void Graphic_set_material_m_2092588233_0 (Graphic_t141164899_0 * __this, Material_t1701708784_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Material UnityEngine.UI.Graphic::get_materialForRendering()
extern "C"  Material_t1701708784_0 * Graphic_get_materialForRendering_m1154169789_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Texture UnityEngine.UI.Graphic::get_mainTexture()
extern "C"  Texture_t1814018354_0 * Graphic_get_mainTexture_m_1358267173_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::OnEnable()
extern "C"  void Graphic_OnEnable_m1102673235_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::OnDisable()
extern "C"  void Graphic_OnDisable_m264069178_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::OnCanvasHierarchyChanged()
extern "C"  void Graphic_OnCanvasHierarchyChanged_m514781447_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::Rebuild(UnityEngine.UI.CanvasUpdate)
extern "C"  void Graphic_Rebuild_m444579746_0 (Graphic_t141164899_0 * __this, int32_t ___update, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::LayoutComplete()
extern "C"  void Graphic_LayoutComplete_m1944323924_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::GraphicUpdateComplete()
extern "C"  void Graphic_GraphicUpdateComplete_m_120664549_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::UpdateMaterial()
extern "C"  void Graphic_UpdateMaterial_m1564277409_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::UpdateGeometry()
extern "C"  void Graphic_UpdateGeometry_m2127951660_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::DoMeshGeneration()
extern "C"  void Graphic_DoMeshGeneration_m_1787920927_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::DoLegacyMeshGeneration()
extern "C"  void Graphic_DoLegacyMeshGeneration_m_533369974_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Mesh UnityEngine.UI.Graphic::get_workerMesh()
extern "C"  Mesh_t_982089418_0 * Graphic_get_workerMesh_m1691010424_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::OnFillVBO(System.Collections.Generic.List`1<UnityEngine.UIVertex>)
extern "C"  void Graphic_OnFillVBO_m316398351_0 (Graphic_t141164899_0 * __this, List_1_t757324127_0 * ___vbo, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::OnPopulateMesh(UnityEngine.Mesh)
extern "C"  void Graphic_OnPopulateMesh_m192648803_0 (Graphic_t141164899_0 * __this, Mesh_t_982089418_0 * ___m, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::OnPopulateMesh(UnityEngine.UI.VertexHelper)
extern "C"  void Graphic_OnPopulateMesh_m_1117908746_0 (Graphic_t141164899_0 * __this, VertexHelper_t786786519_0 * ___vh, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::OnDidApplyAnimationProperties()
extern "C"  void Graphic_OnDidApplyAnimationProperties_m_694769670_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::SetNativeSize()
extern "C"  void Graphic_SetNativeSize_m_1478630741_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.Graphic::Raycast(UnityEngine.Vector2,UnityEngine.Camera)
extern "C"  bool Graphic_Raycast_m822891196_0 (Graphic_t141164899_0 * __this, Vector2_t_725341338_0  ___sp, Camera_t814710830_0 * ___eventCamera, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.UI.Graphic::PixelAdjustPoint(UnityEngine.Vector2)
extern "C"  Vector2_t_725341338_0  Graphic_PixelAdjustPoint_m440199187_0 (Graphic_t141164899_0 * __this, Vector2_t_725341338_0  ___point, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Rect UnityEngine.UI.Graphic::GetPixelAdjustedRect()
extern "C"  Rect_t_981940947_0  Graphic_GetPixelAdjustedRect_m517144655_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::CrossFadeColor(UnityEngine.Color,System.Single,System.Boolean,System.Boolean)
extern "C"  void Graphic_CrossFadeColor_m_1100019469_0 (Graphic_t141164899_0 * __this, Color_t_388944582_0  ___targetColor, float ___duration, bool ___ignoreTimeScale, bool ___useAlpha, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::CrossFadeColor(UnityEngine.Color,System.Single,System.Boolean,System.Boolean,System.Boolean)
extern "C"  void Graphic_CrossFadeColor_m1834346026_0 (Graphic_t141164899_0 * __this, Color_t_388944582_0  ___targetColor, float ___duration, bool ___ignoreTimeScale, bool ___useAlpha, bool ___useRGB, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Color UnityEngine.UI.Graphic::CreateColorFromAlpha(System.Single)
extern "C"  Color_t_388944582_0  Graphic_CreateColorFromAlpha_m3334630_0 (Object_t * __this /* static, unused */, float ___alpha, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::CrossFadeAlpha(System.Single,System.Single,System.Boolean)
extern "C"  void Graphic_CrossFadeAlpha_m157692256_0 (Graphic_t141164899_0 * __this, float ___alpha, float ___duration, bool ___ignoreTimeScale, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::RegisterDirtyLayoutCallback(UnityEngine.Events.UnityAction)
extern "C"  void Graphic_RegisterDirtyLayoutCallback_m_105947550_0 (Graphic_t141164899_0 * __this, UnityAction_t502362143_0 * ___action, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::UnregisterDirtyLayoutCallback(UnityEngine.Events.UnityAction)
extern "C"  void Graphic_UnregisterDirtyLayoutCallback_m856391721_0 (Graphic_t141164899_0 * __this, UnityAction_t502362143_0 * ___action, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::RegisterDirtyVerticesCallback(UnityEngine.Events.UnityAction)
extern "C"  void Graphic_RegisterDirtyVerticesCallback_m1901460593_0 (Graphic_t141164899_0 * __this, UnityAction_t502362143_0 * ___action, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::UnregisterDirtyVerticesCallback(UnityEngine.Events.UnityAction)
extern "C"  void Graphic_UnregisterDirtyVerticesCallback_m_1003435912_0 (Graphic_t141164899_0 * __this, UnityAction_t502362143_0 * ___action, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::RegisterDirtyMaterialCallback(UnityEngine.Events.UnityAction)
extern "C"  void Graphic_RegisterDirtyMaterialCallback_m984855455_0 (Graphic_t141164899_0 * __this, UnityAction_t502362143_0 * ___action, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.Graphic::UnregisterDirtyMaterialCallback(UnityEngine.Events.UnityAction)
extern "C"  void Graphic_UnregisterDirtyMaterialCallback_m_1920041050_0 (Graphic_t141164899_0 * __this, UnityAction_t502362143_0 * ___action, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.Graphic::UnityEngine.UI.ICanvasElement.IsDestroyed()
extern "C"  bool Graphic_UnityEngine_UI_ICanvasElement_IsDestroyed_m_2130552094_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Transform UnityEngine.UI.Graphic::UnityEngine.UI.ICanvasElement.get_transform()
extern "C"  Transform_t1584899523_0 * Graphic_UnityEngine_UI_ICanvasElement_get_transform_m1663879910_0 (Graphic_t141164899_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
