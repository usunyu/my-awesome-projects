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

// UnityEngine.UI.CanvasUpdateRegistry
struct CanvasUpdateRegistry_t281103619_0;
// UnityEngine.UI.ICanvasElement
struct ICanvasElement_t_1584762432_0;
// UnityEngine.Transform
struct Transform_t1584899523_0;

#include "codegen/il2cpp-codegen.h"

// System.Void UnityEngine.UI.CanvasUpdateRegistry::.ctor()
extern "C"  void CanvasUpdateRegistry__ctor_m_151480595_0 (CanvasUpdateRegistry_t281103619_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.CanvasUpdateRegistry::.cctor()
extern "C"  void CanvasUpdateRegistry__cctor_m_883027360_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.UI.CanvasUpdateRegistry UnityEngine.UI.CanvasUpdateRegistry::get_instance()
extern "C"  CanvasUpdateRegistry_t281103619_0 * CanvasUpdateRegistry_get_instance_m1077376867_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.CanvasUpdateRegistry::ObjectValidForUpdate(UnityEngine.UI.ICanvasElement)
extern "C"  bool CanvasUpdateRegistry_ObjectValidForUpdate_m_632461002_0 (CanvasUpdateRegistry_t281103619_0 * __this, Object_t * ___element, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.CanvasUpdateRegistry::CleanInvalidItems()
extern "C"  void CanvasUpdateRegistry_CleanInvalidItems_m_626797187_0 (CanvasUpdateRegistry_t281103619_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.CanvasUpdateRegistry::PerformUpdate()
extern "C"  void CanvasUpdateRegistry_PerformUpdate_m_10365163_0 (CanvasUpdateRegistry_t281103619_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.UI.CanvasUpdateRegistry::ParentCount(UnityEngine.Transform)
extern "C"  int32_t CanvasUpdateRegistry_ParentCount_m1557937541_0 (Object_t * __this /* static, unused */, Transform_t1584899523_0 * ___child, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.UI.CanvasUpdateRegistry::SortLayoutList(UnityEngine.UI.ICanvasElement,UnityEngine.UI.ICanvasElement)
extern "C"  int32_t CanvasUpdateRegistry_SortLayoutList_m217615053_0 (Object_t * __this /* static, unused */, Object_t * ___x, Object_t * ___y, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.CanvasUpdateRegistry::RegisterCanvasElementForLayoutRebuild(UnityEngine.UI.ICanvasElement)
extern "C"  void CanvasUpdateRegistry_RegisterCanvasElementForLayoutRebuild_m1282865408_0 (Object_t * __this /* static, unused */, Object_t * ___element, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.CanvasUpdateRegistry::TryRegisterCanvasElementForLayoutRebuild(UnityEngine.UI.ICanvasElement)
extern "C"  bool CanvasUpdateRegistry_TryRegisterCanvasElementForLayoutRebuild_m_817685379_0 (Object_t * __this /* static, unused */, Object_t * ___element, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.CanvasUpdateRegistry::InternalRegisterCanvasElementForLayoutRebuild(UnityEngine.UI.ICanvasElement)
extern "C"  bool CanvasUpdateRegistry_InternalRegisterCanvasElementForLayoutRebuild_m584808143_0 (CanvasUpdateRegistry_t281103619_0 * __this, Object_t * ___element, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.CanvasUpdateRegistry::RegisterCanvasElementForGraphicRebuild(UnityEngine.UI.ICanvasElement)
extern "C"  void CanvasUpdateRegistry_RegisterCanvasElementForGraphicRebuild_m1487849090_0 (Object_t * __this /* static, unused */, Object_t * ___element, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.CanvasUpdateRegistry::TryRegisterCanvasElementForGraphicRebuild(UnityEngine.UI.ICanvasElement)
extern "C"  bool CanvasUpdateRegistry_TryRegisterCanvasElementForGraphicRebuild_m795284133_0 (Object_t * __this /* static, unused */, Object_t * ___element, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.CanvasUpdateRegistry::InternalRegisterCanvasElementForGraphicRebuild(UnityEngine.UI.ICanvasElement)
extern "C"  bool CanvasUpdateRegistry_InternalRegisterCanvasElementForGraphicRebuild_m1322910355_0 (CanvasUpdateRegistry_t281103619_0 * __this, Object_t * ___element, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.CanvasUpdateRegistry::UnRegisterCanvasElementForRebuild(UnityEngine.UI.ICanvasElement)
extern "C"  void CanvasUpdateRegistry_UnRegisterCanvasElementForRebuild_m_2106853585_0 (Object_t * __this /* static, unused */, Object_t * ___element, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.CanvasUpdateRegistry::InternalUnRegisterCanvasElementForLayoutRebuild(UnityEngine.UI.ICanvasElement)
extern "C"  void CanvasUpdateRegistry_InternalUnRegisterCanvasElementForLayoutRebuild_m1911897302_0 (CanvasUpdateRegistry_t281103619_0 * __this, Object_t * ___element, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.CanvasUpdateRegistry::InternalUnRegisterCanvasElementForGraphicRebuild(UnityEngine.UI.ICanvasElement)
extern "C"  void CanvasUpdateRegistry_InternalUnRegisterCanvasElementForGraphicRebuild_m_486998676_0 (CanvasUpdateRegistry_t281103619_0 * __this, Object_t * ___element, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.CanvasUpdateRegistry::IsRebuildingLayout()
extern "C"  bool CanvasUpdateRegistry_IsRebuildingLayout_m1167551012_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.UI.CanvasUpdateRegistry::IsRebuildingGraphics()
extern "C"  bool CanvasUpdateRegistry_IsRebuildingGraphics_m_1315075323_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
