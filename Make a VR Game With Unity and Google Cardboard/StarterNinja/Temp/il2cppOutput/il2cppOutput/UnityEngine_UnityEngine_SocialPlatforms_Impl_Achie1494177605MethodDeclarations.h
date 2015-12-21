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

// UnityEngine.SocialPlatforms.Impl.Achievement
struct Achievement_t1494177605_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_DateTime_818288618.h"

// System.Void UnityEngine.SocialPlatforms.Impl.Achievement::.ctor(System.String,System.Double,System.Boolean,System.Boolean,System.DateTime)
extern "C"  void Achievement__ctor_m377036415_0 (Achievement_t1494177605_0 * __this, String_t* ___id, double ___percentCompleted, bool ___completed, bool ___hidden, DateTime_t_818288618_0  ___lastReportedDate, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.Impl.Achievement::.ctor(System.String,System.Double)
extern "C"  void Achievement__ctor_m_1334286867_0 (Achievement_t1494177605_0 * __this, String_t* ___id, double ___percent, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.Impl.Achievement::.ctor()
extern "C"  void Achievement__ctor_m_949701775_0 (Achievement_t1494177605_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.SocialPlatforms.Impl.Achievement::ToString()
extern "C"  String_t* Achievement_ToString_m_1320810110_0 (Achievement_t1494177605_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.SocialPlatforms.Impl.Achievement::get_id()
extern "C"  String_t* Achievement_get_id_m1680539866_0 (Achievement_t1494177605_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.Impl.Achievement::set_id(System.String)
extern "C"  void Achievement_set_id_m_1171537481_0 (Achievement_t1494177605_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Double UnityEngine.SocialPlatforms.Impl.Achievement::get_percentCompleted()
extern "C"  double Achievement_get_percentCompleted_m_1802208187_0 (Achievement_t1494177605_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.Impl.Achievement::set_percentCompleted(System.Double)
extern "C"  void Achievement_set_percentCompleted_m1005987436_0 (Achievement_t1494177605_0 * __this, double ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.SocialPlatforms.Impl.Achievement::get_completed()
extern "C"  bool Achievement_get_completed_m_605113941_0 (Achievement_t1494177605_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.SocialPlatforms.Impl.Achievement::get_hidden()
extern "C"  bool Achievement_get_hidden_m_1340412052_0 (Achievement_t1494177605_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime UnityEngine.SocialPlatforms.Impl.Achievement::get_lastReportedDate()
extern "C"  DateTime_t_818288618_0  Achievement_get_lastReportedDate_m445111052_0 (Achievement_t1494177605_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
