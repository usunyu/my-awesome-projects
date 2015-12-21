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

// UnityEngine.iOS.LocalNotification
struct LocalNotification_t731349036_0;
// System.String
struct String_t;
// System.Collections.IDictionary
struct IDictionary_t_1514320629_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_DateTime_818288618.h"
#include "UnityEngine_UnityEngine_iOS_CalendarUnit1020765164.h"
#include "UnityEngine_UnityEngine_iOS_CalendarIdentifier208800017.h"

// System.Void UnityEngine.iOS.LocalNotification::.ctor()
extern "C"  void LocalNotification__ctor_m_1933610204_0 (LocalNotification_t731349036_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.LocalNotification::.cctor()
extern "C"  void LocalNotification__cctor_m_294470391_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Double UnityEngine.iOS.LocalNotification::GetFireDate()
extern "C"  double LocalNotification_GetFireDate_m_1068307425_0 (LocalNotification_t731349036_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.LocalNotification::SetFireDate(System.Double)
extern "C"  void LocalNotification_SetFireDate_m1553477818_0 (LocalNotification_t731349036_0 * __this, double ___dt, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime UnityEngine.iOS.LocalNotification::get_fireDate()
extern "C"  DateTime_t_818288618_0  LocalNotification_get_fireDate_m_2108998444_0 (LocalNotification_t731349036_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.LocalNotification::set_fireDate(System.DateTime)
extern "C"  void LocalNotification_set_fireDate_m_589950057_0 (LocalNotification_t731349036_0 * __this, DateTime_t_818288618_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.iOS.LocalNotification::get_timeZone()
extern "C"  String_t* LocalNotification_get_timeZone_m_1354682657_0 (LocalNotification_t731349036_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.LocalNotification::set_timeZone(System.String)
extern "C"  void LocalNotification_set_timeZone_m_1624183188_0 (LocalNotification_t731349036_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.iOS.CalendarUnit UnityEngine.iOS.LocalNotification::get_repeatInterval()
extern "C"  int32_t LocalNotification_get_repeatInterval_m_1356424620_0 (LocalNotification_t731349036_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.LocalNotification::set_repeatInterval(UnityEngine.iOS.CalendarUnit)
extern "C"  void LocalNotification_set_repeatInterval_m_2010555165_0 (LocalNotification_t731349036_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.iOS.CalendarIdentifier UnityEngine.iOS.LocalNotification::get_repeatCalendar()
extern "C"  int32_t LocalNotification_get_repeatCalendar_m916891826_0 (LocalNotification_t731349036_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.LocalNotification::set_repeatCalendar(UnityEngine.iOS.CalendarIdentifier)
extern "C"  void LocalNotification_set_repeatCalendar_m599340503_0 (LocalNotification_t731349036_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.iOS.LocalNotification::get_alertBody()
extern "C"  String_t* LocalNotification_get_alertBody_m_1078309062_0 (LocalNotification_t731349036_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.LocalNotification::set_alertBody(System.String)
extern "C"  void LocalNotification_set_alertBody_m_960512193_0 (LocalNotification_t731349036_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.iOS.LocalNotification::get_alertAction()
extern "C"  String_t* LocalNotification_get_alertAction_m_230370034_0 (LocalNotification_t731349036_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.LocalNotification::set_alertAction(System.String)
extern "C"  void LocalNotification_set_alertAction_m860676139_0 (LocalNotification_t731349036_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.iOS.LocalNotification::get_hasAction()
extern "C"  bool LocalNotification_get_hasAction_m_492363057_0 (LocalNotification_t731349036_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.LocalNotification::set_hasAction(System.Boolean)
extern "C"  void LocalNotification_set_hasAction_m_963071700_0 (LocalNotification_t731349036_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.iOS.LocalNotification::get_alertLaunchImage()
extern "C"  String_t* LocalNotification_get_alertLaunchImage_m_609210510_0 (LocalNotification_t731349036_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.LocalNotification::set_alertLaunchImage(System.String)
extern "C"  void LocalNotification_set_alertLaunchImage_m_2005222471_0 (LocalNotification_t731349036_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.iOS.LocalNotification::get_applicationIconBadgeNumber()
extern "C"  int32_t LocalNotification_get_applicationIconBadgeNumber_m598051564_0 (LocalNotification_t731349036_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.LocalNotification::set_applicationIconBadgeNumber(System.Int32)
extern "C"  void LocalNotification_set_applicationIconBadgeNumber_m_188420303_0 (LocalNotification_t731349036_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.iOS.LocalNotification::get_soundName()
extern "C"  String_t* LocalNotification_get_soundName_m2126669654_0 (LocalNotification_t731349036_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.LocalNotification::set_soundName(System.String)
extern "C"  void LocalNotification_set_soundName_m870364323_0 (LocalNotification_t731349036_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.iOS.LocalNotification::get_defaultSoundName()
extern "C"  String_t* LocalNotification_get_defaultSoundName_m_1936473921_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IDictionary UnityEngine.iOS.LocalNotification::get_userInfo()
extern "C"  Object_t * LocalNotification_get_userInfo_m_166495494_0 (LocalNotification_t731349036_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.LocalNotification::set_userInfo(System.Collections.IDictionary)
extern "C"  void LocalNotification_set_userInfo_m_444252337_0 (LocalNotification_t731349036_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.LocalNotification::Destroy()
extern "C"  void LocalNotification_Destroy_m_1139370628_0 (LocalNotification_t731349036_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.LocalNotification::Finalize()
extern "C"  void LocalNotification_Finalize_m22293182_0 (LocalNotification_t731349036_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.iOS.LocalNotification::InitWrapper()
extern "C"  void LocalNotification_InitWrapper_m910277669_0 (LocalNotification_t731349036_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
