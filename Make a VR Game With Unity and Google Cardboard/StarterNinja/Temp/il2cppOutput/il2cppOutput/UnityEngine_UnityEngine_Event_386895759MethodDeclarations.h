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

// UnityEngine.Event
struct Event_t_386895759_0;
struct Event_t_386895759_0_marshaled;
// System.Object
struct Object_t;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"
#include "UnityEngine_UnityEngine_EventType563663691.h"
#include "UnityEngine_UnityEngine_EventModifiers555415307.h"
#include "UnityEngine_UnityEngine_KeyCode_1879089917.h"
#include "mscorlib_System_IntPtr_1047952454.h"

// System.Void UnityEngine.Event::.ctor()
extern "C"  void Event__ctor_m1609448063_0 (Event_t_386895759_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Event::.ctor(System.Int32)
extern "C"  void Event__ctor_m66398544_0 (Event_t_386895759_0 * __this, int32_t ___displayIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Event::Finalize()
extern "C"  void Event_Finalize_m_1845141117_0 (Event_t_386895759_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 UnityEngine.Event::get_mousePosition()
extern "C"  Vector2_t_725341338_0  Event_get_mousePosition_m_684541347_0 (Event_t_386895759_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Event UnityEngine.Event::get_current()
extern "C"  Event_t_386895759_0 * Event_get_current_m238587645_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Event::Internal_MakeMasterEventCurrent(System.Int32)
extern "C"  void Event_Internal_MakeMasterEventCurrent_m213199903_0 (Object_t * __this /* static, unused */, int32_t ___displayIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Event::get_isKey()
extern "C"  bool Event_get_isKey_m645126607_0 (Event_t_386895759_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Event::get_isMouse()
extern "C"  bool Event_get_isMouse_m_743690539_0 (Event_t_386895759_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.Event::GetHashCode()
extern "C"  int32_t Event_GetHashCode_m_1953319826_0 (Event_t_386895759_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Event::Equals(System.Object)
extern "C"  bool Event_Equals_m_1920351466_0 (Event_t_386895759_0 * __this, Object_t * ___obj, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.Event::ToString()
extern "C"  String_t* Event_ToString_m_633449778_0 (Event_t_386895759_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Event::Init(System.Int32)
extern "C"  void Event_Init_m_769690170_0 (Event_t_386895759_0 * __this, int32_t ___displayIndex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Event::Cleanup()
extern "C"  void Event_Cleanup_m_1134844351_0 (Event_t_386895759_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventType UnityEngine.Event::get_rawType()
extern "C"  int32_t Event_get_rawType_m696564524_0 (Event_t_386895759_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventType UnityEngine.Event::get_type()
extern "C"  int32_t Event_get_type_m_2085028046_0 (Event_t_386895759_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Event::Internal_GetMousePosition(UnityEngine.Vector2&)
extern "C"  void Event_Internal_GetMousePosition_m2054214537_0 (Event_t_386895759_0 * __this, Vector2_t_725341338_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.EventModifiers UnityEngine.Event::get_modifiers()
extern "C"  int32_t Event_get_modifiers_m_273976410_0 (Event_t_386895759_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Char UnityEngine.Event::get_character()
extern "C"  uint16_t Event_get_character_m_631794629_0 (Event_t_386895759_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.Event::get_commandName()
extern "C"  String_t* Event_get_commandName_m1197792621_0 (Event_t_386895759_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.KeyCode UnityEngine.Event::get_keyCode()
extern "C"  int32_t Event_get_keyCode_m1820698462_0 (Event_t_386895759_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Event::Internal_SetNativeEvent(System.IntPtr)
extern "C"  void Event_Internal_SetNativeEvent_m930902932_0 (Object_t * __this /* static, unused */, IntPtr_t ___ptr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Event::set_displayIndex(System.Int32)
extern "C"  void Event_set_displayIndex_m_164876861_0 (Event_t_386895759_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Event::PopEvent(UnityEngine.Event)
extern "C"  bool Event_PopEvent_m_1504892281_0 (Object_t * __this /* static, unused */, Event_t_386895759_0 * ___outEvent, const MethodInfo* method) IL2CPP_METHOD_ATTR;
extern "C" void Event_t_386895759_0_marshal(const Event_t_386895759_0& unmarshaled, Event_t_386895759_0_marshaled& marshaled);
extern "C" void Event_t_386895759_0_marshal_back(const Event_t_386895759_0_marshaled& marshaled, Event_t_386895759_0& unmarshaled);
extern "C" void Event_t_386895759_0_marshal_cleanup(Event_t_386895759_0_marshaled& marshaled);
