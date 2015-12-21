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

// UnityEngine.GameObject
struct GameObject_t_184308134_0;
// System.String
struct String_t;
// UnityEngine.UI.Text
struct Text_t_204341102_0;
// UnityEngine.UI.Selectable
struct Selectable_t1019922427_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"
#include "UnityEngine_UI_UnityEngine_UI_DefaultControls_Resou_57530424.h"

// System.Void UnityEngine.UI.DefaultControls::.cctor()
extern "C"  void DefaultControls__cctor_m1303793449_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.UI.DefaultControls::CreateUIElementRoot(System.String,UnityEngine.Vector2)
extern "C"  GameObject_t_184308134_0 * DefaultControls_CreateUIElementRoot_m335662421_0 (Object_t * __this /* static, unused */, String_t* ___name, Vector2_t_725341338_0  ___size, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.UI.DefaultControls::CreateUIObject(System.String,UnityEngine.GameObject)
extern "C"  GameObject_t_184308134_0 * DefaultControls_CreateUIObject_m1826457530_0 (Object_t * __this /* static, unused */, String_t* ___name, GameObject_t_184308134_0 * ___parent, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.DefaultControls::SetDefaultTextValues(UnityEngine.UI.Text)
extern "C"  void DefaultControls_SetDefaultTextValues_m_1618773260_0 (Object_t * __this /* static, unused */, Text_t_204341102_0 * ___lbl, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.DefaultControls::SetDefaultColorTransitionValues(UnityEngine.UI.Selectable)
extern "C"  void DefaultControls_SetDefaultColorTransitionValues_m_1299909796_0 (Object_t * __this /* static, unused */, Selectable_t1019922427_0 * ___slider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.DefaultControls::SetParentAndAlign(UnityEngine.GameObject,UnityEngine.GameObject)
extern "C"  void DefaultControls_SetParentAndAlign_m867848490_0 (Object_t * __this /* static, unused */, GameObject_t_184308134_0 * ___child, GameObject_t_184308134_0 * ___parent, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.DefaultControls::SetLayerRecursively(UnityEngine.GameObject,System.Int32)
extern "C"  void DefaultControls_SetLayerRecursively_m_1346629875_0 (Object_t * __this /* static, unused */, GameObject_t_184308134_0 * ___go, int32_t ___layer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.UI.DefaultControls::CreatePanel(UnityEngine.UI.DefaultControls/Resources)
extern "C"  GameObject_t_184308134_0 * DefaultControls_CreatePanel_m131101809_0 (Object_t * __this /* static, unused */, Resources_t_57530424_0  ___resources, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.UI.DefaultControls::CreateButton(UnityEngine.UI.DefaultControls/Resources)
extern "C"  GameObject_t_184308134_0 * DefaultControls_CreateButton_m_1385559757_0 (Object_t * __this /* static, unused */, Resources_t_57530424_0  ___resources, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.UI.DefaultControls::CreateText(UnityEngine.UI.DefaultControls/Resources)
extern "C"  GameObject_t_184308134_0 * DefaultControls_CreateText_m414838766_0 (Object_t * __this /* static, unused */, Resources_t_57530424_0  ___resources, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.UI.DefaultControls::CreateImage(UnityEngine.UI.DefaultControls/Resources)
extern "C"  GameObject_t_184308134_0 * DefaultControls_CreateImage_m_369559800_0 (Object_t * __this /* static, unused */, Resources_t_57530424_0  ___resources, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.UI.DefaultControls::CreateRawImage(UnityEngine.UI.DefaultControls/Resources)
extern "C"  GameObject_t_184308134_0 * DefaultControls_CreateRawImage_m383828052_0 (Object_t * __this /* static, unused */, Resources_t_57530424_0  ___resources, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.UI.DefaultControls::CreateSlider(UnityEngine.UI.DefaultControls/Resources)
extern "C"  GameObject_t_184308134_0 * DefaultControls_CreateSlider_m_1204957150_0 (Object_t * __this /* static, unused */, Resources_t_57530424_0  ___resources, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.UI.DefaultControls::CreateScrollbar(UnityEngine.UI.DefaultControls/Resources)
extern "C"  GameObject_t_184308134_0 * DefaultControls_CreateScrollbar_m_1895118061_0 (Object_t * __this /* static, unused */, Resources_t_57530424_0  ___resources, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.UI.DefaultControls::CreateToggle(UnityEngine.UI.DefaultControls/Resources)
extern "C"  GameObject_t_184308134_0 * DefaultControls_CreateToggle_m1602114261_0 (Object_t * __this /* static, unused */, Resources_t_57530424_0  ___resources, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.UI.DefaultControls::CreateInputField(UnityEngine.UI.DefaultControls/Resources)
extern "C"  GameObject_t_184308134_0 * DefaultControls_CreateInputField_m_481067311_0 (Object_t * __this /* static, unused */, Resources_t_57530424_0  ___resources, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.UI.DefaultControls::CreateDropdown(UnityEngine.UI.DefaultControls/Resources)
extern "C"  GameObject_t_184308134_0 * DefaultControls_CreateDropdown_m481152210_0 (Object_t * __this /* static, unused */, Resources_t_57530424_0  ___resources, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.UI.DefaultControls::CreateScrollView(UnityEngine.UI.DefaultControls/Resources)
extern "C"  GameObject_t_184308134_0 * DefaultControls_CreateScrollView_m_1531089901_0 (Object_t * __this /* static, unused */, Resources_t_57530424_0  ___resources, const MethodInfo* method) IL2CPP_METHOD_ATTR;
