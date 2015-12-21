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

// UnityEngine.Component
struct Component_t_867674284_0;
// UnityEngine.Transform
struct Transform_t1584899523_0;
// UnityEngine.GameObject
struct GameObject_t_184308134_0;
// System.Type
struct Type_t;
// System.String
struct String_t;
// UnityEngine.Component[]
struct ComponentU5BU5D_t_611328586_0;
// System.Object
struct Object_t;
// System.Collections.Generic.List`1<UnityEngine.Component>
struct List_1_t_503171416_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"
#include "UnityEngine_UnityEngine_SendMessageOptions_53436984.h"

// System.Void UnityEngine.Component::.ctor()
extern "C"  void Component__ctor_m_56363908_0 (Component_t_867674284_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Transform UnityEngine.Component::get_transform()
extern "C"  Transform_t1584899523_0 * Component_get_transform_m_37826853_0 (Component_t_867674284_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UnityEngine.Component::get_gameObject()
extern "C"  GameObject_t_184308134_0 * Component_get_gameObject_m1170635899_0 (Component_t_867674284_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Component UnityEngine.Component::GetComponent(System.Type)
extern "C"  Component_t_867674284_0 * Component_GetComponent_m936021879_0 (Component_t_867674284_0 * __this, Type_t * ___type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Component::GetComponentFastPath(System.Type,System.IntPtr)
extern "C"  void Component_GetComponentFastPath_m1455568887_0 (Component_t_867674284_0 * __this, Type_t * ___type, IntPtr_t ___oneFurtherThanResultValue, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Component UnityEngine.Component::GetComponent(System.String)
extern "C"  Component_t_867674284_0 * Component_GetComponent_m840247168_0 (Component_t_867674284_0 * __this, String_t* ___type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Component UnityEngine.Component::GetComponentInChildren(System.Type)
extern "C"  Component_t_867674284_0 * Component_GetComponentInChildren_m680239315_0 (Component_t_867674284_0 * __this, Type_t * ___t, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Component UnityEngine.Component::GetComponentInChildren(System.Type,System.Boolean)
extern "C"  Component_t_867674284_0 * Component_GetComponentInChildren_m1899663946_0 (Component_t_867674284_0 * __this, Type_t * ___t, bool ___includeInactive, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Component[] UnityEngine.Component::GetComponentsInChildren(System.Type)
extern "C"  ComponentU5BU5D_t_611328586_0* Component_GetComponentsInChildren_m1419556996_0 (Component_t_867674284_0 * __this, Type_t * ___t, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Component[] UnityEngine.Component::GetComponentsInChildren(System.Type,System.Boolean)
extern "C"  ComponentU5BU5D_t_611328586_0* Component_GetComponentsInChildren_m_1848442247_0 (Component_t_867674284_0 * __this, Type_t * ___t, bool ___includeInactive, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Component UnityEngine.Component::GetComponentInParent(System.Type)
extern "C"  Component_t_867674284_0 * Component_GetComponentInParent_m1953645192_0 (Component_t_867674284_0 * __this, Type_t * ___t, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Component[] UnityEngine.Component::GetComponentsInParent(System.Type)
extern "C"  ComponentU5BU5D_t_611328586_0* Component_GetComponentsInParent_m345477753_0 (Component_t_867674284_0 * __this, Type_t * ___t, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Component[] UnityEngine.Component::GetComponentsInParent(System.Type,System.Boolean)
extern "C"  ComponentU5BU5D_t_611328586_0* Component_GetComponentsInParent_m608460772_0 (Component_t_867674284_0 * __this, Type_t * ___t, bool ___includeInactive, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Component[] UnityEngine.Component::GetComponents(System.Type)
extern "C"  ComponentU5BU5D_t_611328586_0* Component_GetComponents_m_1319935896_0 (Component_t_867674284_0 * __this, Type_t * ___type, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Component::GetComponentsForListInternal(System.Type,System.Object)
extern "C"  void Component_GetComponentsForListInternal_m814665735_0 (Component_t_867674284_0 * __this, Type_t * ___searchType, Object_t * ___resultList, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Component::GetComponents(System.Type,System.Collections.Generic.List`1<UnityEngine.Component>)
extern "C"  void Component_GetComponents_m_868155011_0 (Component_t_867674284_0 * __this, Type_t * ___type, List_1_t_503171416_0 * ___results, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.Component::get_tag()
extern "C"  String_t* Component_get_tag_m217485006_0 (Component_t_867674284_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Component::set_tag(System.String)
extern "C"  void Component_set_tag_m_1053978133_0 (Component_t_867674284_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Component::CompareTag(System.String)
extern "C"  bool Component_CompareTag_m305486283_0 (Component_t_867674284_0 * __this, String_t* ___tag, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Component::SendMessageUpwards(System.String,System.Object,UnityEngine.SendMessageOptions)
extern "C"  void Component_SendMessageUpwards_m_1522836635_0 (Component_t_867674284_0 * __this, String_t* ___methodName, Object_t * ___value, int32_t ___options, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Component::SendMessageUpwards(System.String,System.Object)
extern "C"  void Component_SendMessageUpwards_m_1821775349_0 (Component_t_867674284_0 * __this, String_t* ___methodName, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Component::SendMessageUpwards(System.String)
extern "C"  void Component_SendMessageUpwards_m767712765_0 (Component_t_867674284_0 * __this, String_t* ___methodName, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Component::SendMessageUpwards(System.String,UnityEngine.SendMessageOptions)
extern "C"  void Component_SendMessageUpwards_m707848499_0 (Component_t_867674284_0 * __this, String_t* ___methodName, int32_t ___options, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Component::SendMessage(System.String,System.Object,UnityEngine.SendMessageOptions)
extern "C"  void Component_SendMessage_m1163914169_0 (Component_t_867674284_0 * __this, String_t* ___methodName, Object_t * ___value, int32_t ___options, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Component::SendMessage(System.String,System.Object)
extern "C"  void Component_SendMessage_m904598583_0 (Component_t_867674284_0 * __this, String_t* ___methodName, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Component::SendMessage(System.String)
extern "C"  void Component_SendMessage_m_1935833815_0 (Component_t_867674284_0 * __this, String_t* ___methodName, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Component::SendMessage(System.String,UnityEngine.SendMessageOptions)
extern "C"  void Component_SendMessage_m1912331399_0 (Component_t_867674284_0 * __this, String_t* ___methodName, int32_t ___options, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Component::BroadcastMessage(System.String,System.Object,UnityEngine.SendMessageOptions)
extern "C"  void Component_BroadcastMessage_m_332971442_0 (Component_t_867674284_0 * __this, String_t* ___methodName, Object_t * ___parameter, int32_t ___options, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Component::BroadcastMessage(System.String,System.Object)
extern "C"  void Component_BroadcastMessage_m_748061630_0 (Component_t_867674284_0 * __this, String_t* ___methodName, Object_t * ___parameter, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Component::BroadcastMessage(System.String)
extern "C"  void Component_BroadcastMessage_m_1437856652_0 (Component_t_867674284_0 * __this, String_t* ___methodName, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Component::BroadcastMessage(System.String,UnityEngine.SendMessageOptions)
extern "C"  void Component_BroadcastMessage_m1985948636_0 (Component_t_867674284_0 * __this, String_t* ___methodName, int32_t ___options, const MethodInfo* method) IL2CPP_METHOD_ATTR;
