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

// UnityEngine.SocialPlatforms.Impl.Leaderboard
struct Leaderboard_t_1959514221_0;
// System.String
struct String_t;
// UnityEngine.SocialPlatforms.IScore
struct IScore_t_1846438995_0;
// UnityEngine.SocialPlatforms.IScore[]
struct IScoreU5BU5D_t_606378033_0;
// System.String[]
struct StringU5BU5D_t_816028754_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_SocialPlatforms_UserScope_64885051.h"
#include "UnityEngine_UnityEngine_SocialPlatforms_Range_605012807.h"
#include "UnityEngine_UnityEngine_SocialPlatforms_TimeScope_367748861.h"

// System.Void UnityEngine.SocialPlatforms.Impl.Leaderboard::.ctor()
extern "C"  void Leaderboard__ctor_m596857571_0 (Leaderboard_t_1959514221_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.SocialPlatforms.Impl.Leaderboard::ToString()
extern "C"  String_t* Leaderboard_ToString_m114482384_0 (Leaderboard_t_1959514221_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.Impl.Leaderboard::SetLocalUserScore(UnityEngine.SocialPlatforms.IScore)
extern "C"  void Leaderboard_SetLocalUserScore_m700491556_0 (Leaderboard_t_1959514221_0 * __this, Object_t * ___score, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.Impl.Leaderboard::SetMaxRange(System.UInt32)
extern "C"  void Leaderboard_SetMaxRange_m_515058562_0 (Leaderboard_t_1959514221_0 * __this, uint32_t ___maxRange, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.Impl.Leaderboard::SetScores(UnityEngine.SocialPlatforms.IScore[])
extern "C"  void Leaderboard_SetScores_m1463319879_0 (Leaderboard_t_1959514221_0 * __this, IScoreU5BU5D_t_606378033_0* ___scores, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.Impl.Leaderboard::SetTitle(System.String)
extern "C"  void Leaderboard_SetTitle_m771163339_0 (Leaderboard_t_1959514221_0 * __this, String_t* ___title, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String[] UnityEngine.SocialPlatforms.Impl.Leaderboard::GetUserFilter()
extern "C"  StringU5BU5D_t_816028754_0* Leaderboard_GetUserFilter_m_1175061575_0 (Leaderboard_t_1959514221_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.SocialPlatforms.Impl.Leaderboard::get_id()
extern "C"  String_t* Leaderboard_get_id_m_1915727960_0 (Leaderboard_t_1959514221_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.Impl.Leaderboard::set_id(System.String)
extern "C"  void Leaderboard_set_id_m2022535593_0 (Leaderboard_t_1959514221_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.SocialPlatforms.UserScope UnityEngine.SocialPlatforms.Impl.Leaderboard::get_userScope()
extern "C"  int32_t Leaderboard_get_userScope_m_747196827_0 (Leaderboard_t_1959514221_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.Impl.Leaderboard::set_userScope(UnityEngine.SocialPlatforms.UserScope)
extern "C"  void Leaderboard_set_userScope_m_380137010_0 (Leaderboard_t_1959514221_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.SocialPlatforms.Range UnityEngine.SocialPlatforms.Impl.Leaderboard::get_range()
extern "C"  Range_t_605012807_0  Leaderboard_get_range_m234965965_0 (Leaderboard_t_1959514221_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.Impl.Leaderboard::set_range(UnityEngine.SocialPlatforms.Range)
extern "C"  void Leaderboard_set_range_m_1464796826_0 (Leaderboard_t_1959514221_0 * __this, Range_t_605012807_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.SocialPlatforms.TimeScope UnityEngine.SocialPlatforms.Impl.Leaderboard::get_timeScope()
extern "C"  int32_t Leaderboard_get_timeScope_m_1938885919_0 (Leaderboard_t_1959514221_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.Impl.Leaderboard::set_timeScope(UnityEngine.SocialPlatforms.TimeScope)
extern "C"  void Leaderboard_set_timeScope_m_625173678_0 (Leaderboard_t_1959514221_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
