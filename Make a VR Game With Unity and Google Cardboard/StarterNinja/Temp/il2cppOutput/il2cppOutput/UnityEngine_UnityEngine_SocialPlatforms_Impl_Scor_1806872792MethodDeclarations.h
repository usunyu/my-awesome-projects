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

// UnityEngine.SocialPlatforms.Impl.Score
struct Score_t_1806872792_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_DateTime_818288618.h"

// System.Void UnityEngine.SocialPlatforms.Impl.Score::.ctor(System.String,System.Int64)
extern "C"  void Score__ctor_m113497156_0 (Score_t_1806872792_0 * __this, String_t* ___leaderboardID, int64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.Impl.Score::.ctor(System.String,System.Int64,System.String,System.DateTime,System.String,System.Int32)
extern "C"  void Score__ctor_m_526929815_0 (Score_t_1806872792_0 * __this, String_t* ___leaderboardID, int64_t ___value, String_t* ___userID, DateTime_t_818288618_0  ___date, String_t* ___formattedValue, int32_t ___rank, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.SocialPlatforms.Impl.Score::ToString()
extern "C"  String_t* Score_ToString_m_914327323_0 (Score_t_1806872792_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.SocialPlatforms.Impl.Score::get_leaderboardID()
extern "C"  String_t* Score_get_leaderboardID_m1097777176_0 (Score_t_1806872792_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.Impl.Score::set_leaderboardID(System.String)
extern "C"  void Score_set_leaderboardID_m_648091909_0 (Score_t_1806872792_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 UnityEngine.SocialPlatforms.Impl.Score::get_value()
extern "C"  int64_t Score_get_value_m_913732461_0 (Score_t_1806872792_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.Impl.Score::set_value(System.Int64)
extern "C"  void Score_set_value_m_2065010670_0 (Score_t_1806872792_0 * __this, int64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
