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

// UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform
struct GameCenterPlatform_t332546685_0;
// UnityEngine.SocialPlatforms.ILocalUser
struct ILocalUser_t_1948065423_0;
// System.Action`1<System.Boolean>
struct Action_1_t_1180387379_0;
// System.String
struct String_t;
// UnityEngine.Texture2D
struct Texture2D_t_485082364_0;
// System.String[]
struct StringU5BU5D_t_816028754_0;
// UnityEngine.SocialPlatforms.GameCenter.GcAchievementData[]
struct GcAchievementDataU5BU5D_t1326650748_0;
// UnityEngine.SocialPlatforms.GameCenter.GcScoreData[]
struct GcScoreDataU5BU5D_t_605295777_0;
// System.Action`1<UnityEngine.SocialPlatforms.IAchievementDescription[]>
struct Action_1_t_2013501088_0;
// System.Action`1<UnityEngine.SocialPlatforms.IAchievement[]>
struct Action_1_t1150423932_0;
// System.Action`1<UnityEngine.SocialPlatforms.IScore[]>
struct Action_1_t2025153657_0;
// UnityEngine.SocialPlatforms.ILeaderboard
struct ILeaderboard_t1630682200_0;
// System.Action`1<UnityEngine.SocialPlatforms.IUserProfile[]>
struct Action_1_t1059329261_0;
// UnityEngine.SocialPlatforms.Impl.UserProfile[]
struct UserProfileU5BU5D_t_2081017386_0;
// UnityEngine.SocialPlatforms.IAchievement
struct IAchievement_t789406730_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_SocialPlatforms_TimeScope_367748861.h"
#include "UnityEngine_UnityEngine_SocialPlatforms_GameCenter_846969558.h"
#include "UnityEngine_UnityEngine_SocialPlatforms_GameCenter1146156361.h"

// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::.ctor()
extern "C"  void GameCenterPlatform__ctor_m573039859_0 (GameCenterPlatform_t332546685_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::.cctor()
extern "C"  void GameCenterPlatform__cctor_m102270234_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::UnityEngine.SocialPlatforms.ISocialPlatform.LoadFriends(UnityEngine.SocialPlatforms.ILocalUser,System.Action`1<System.Boolean>)
extern "C"  void GameCenterPlatform_UnityEngine_SocialPlatforms_ISocialPlatform_LoadFriends_m_1826935177_0 (GameCenterPlatform_t332546685_0 * __this, Object_t * ___user, Action_1_t_1180387379_0 * ___callback, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::UnityEngine.SocialPlatforms.ISocialPlatform.Authenticate(UnityEngine.SocialPlatforms.ILocalUser,System.Action`1<System.Boolean>)
extern "C"  void GameCenterPlatform_UnityEngine_SocialPlatforms_ISocialPlatform_Authenticate_m305325355_0 (GameCenterPlatform_t332546685_0 * __this, Object_t * ___user, Action_1_t_1180387379_0 * ___callback, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::Internal_Authenticate()
extern "C"  void GameCenterPlatform_Internal_Authenticate_m582381960_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::Internal_Authenticated()
extern "C"  bool GameCenterPlatform_Internal_Authenticated_m_1513999336_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::Internal_UserName()
extern "C"  String_t* GameCenterPlatform_Internal_UserName_m1252299660_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::Internal_UserID()
extern "C"  String_t* GameCenterPlatform_Internal_UserID_m385481212_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::Internal_Underage()
extern "C"  bool GameCenterPlatform_Internal_Underage_m_125228352_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Texture2D UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::Internal_UserImage()
extern "C"  Texture2D_t_485082364_0 * GameCenterPlatform_Internal_UserImage_m_1119191166_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::Internal_LoadFriends()
extern "C"  void GameCenterPlatform_Internal_LoadFriends_m1921936862_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::Internal_LoadAchievementDescriptions()
extern "C"  void GameCenterPlatform_Internal_LoadAchievementDescriptions_m1394384079_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::Internal_LoadAchievements()
extern "C"  void GameCenterPlatform_Internal_LoadAchievements_m817891229_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::Internal_ReportProgress(System.String,System.Double)
extern "C"  void GameCenterPlatform_Internal_ReportProgress_m_1783446326_0 (Object_t * __this /* static, unused */, String_t* ___id, double ___progress, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::Internal_ReportScore(System.Int64,System.String)
extern "C"  void GameCenterPlatform_Internal_ReportScore_m408601947_0 (Object_t * __this /* static, unused */, int64_t ___score, String_t* ___category, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::Internal_LoadScores(System.String)
extern "C"  void GameCenterPlatform_Internal_LoadScores_m523283944_0 (Object_t * __this /* static, unused */, String_t* ___category, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::Internal_ShowAchievementsUI()
extern "C"  void GameCenterPlatform_Internal_ShowAchievementsUI_m1934331464_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::Internal_ShowLeaderboardUI()
extern "C"  void GameCenterPlatform_Internal_ShowLeaderboardUI_m_1237262557_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::Internal_LoadUsers(System.String[])
extern "C"  void GameCenterPlatform_Internal_LoadUsers_m_76147217_0 (Object_t * __this /* static, unused */, StringU5BU5D_t_816028754_0* ___userIds, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::Internal_ResetAllAchievements()
extern "C"  void GameCenterPlatform_Internal_ResetAllAchievements_m165059209_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::Internal_ShowDefaultAchievementBanner(System.Boolean)
extern "C"  void GameCenterPlatform_Internal_ShowDefaultAchievementBanner_m_1186590399_0 (Object_t * __this /* static, unused */, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::ResetAllAchievements(System.Action`1<System.Boolean>)
extern "C"  void GameCenterPlatform_ResetAllAchievements_m878609996_0 (Object_t * __this /* static, unused */, Action_1_t_1180387379_0 * ___callback, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::ShowDefaultAchievementCompletionBanner(System.Boolean)
extern "C"  void GameCenterPlatform_ShowDefaultAchievementCompletionBanner_m_1778798597_0 (Object_t * __this /* static, unused */, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::ShowLeaderboardUI(System.String,UnityEngine.SocialPlatforms.TimeScope)
extern "C"  void GameCenterPlatform_ShowLeaderboardUI_m_503100748_0 (Object_t * __this /* static, unused */, String_t* ___leaderboardID, int32_t ___timeScope, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::Internal_ShowSpecificLeaderboardUI(System.String,System.Int32)
extern "C"  void GameCenterPlatform_Internal_ShowSpecificLeaderboardUI_m1768304742_0 (Object_t * __this /* static, unused */, String_t* ___leaderboardID, int32_t ___timeScope, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::ClearAchievementDescriptions(System.Int32)
extern "C"  void GameCenterPlatform_ClearAchievementDescriptions_m_1136208453_0 (Object_t * __this /* static, unused */, int32_t ___size, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::SetAchievementDescription(UnityEngine.SocialPlatforms.GameCenter.GcAchievementDescriptionData,System.Int32)
extern "C"  void GameCenterPlatform_SetAchievementDescription_m_1120471187_0 (Object_t * __this /* static, unused */, GcAchievementDescriptionData_t846969558_0  ___data, int32_t ___number, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::SetAchievementDescriptionImage(UnityEngine.Texture2D,System.Int32)
extern "C"  void GameCenterPlatform_SetAchievementDescriptionImage_m_566292936_0 (Object_t * __this /* static, unused */, Texture2D_t_485082364_0 * ___texture, int32_t ___number, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::TriggerAchievementDescriptionCallback()
extern "C"  void GameCenterPlatform_TriggerAchievementDescriptionCallback_m1497473051_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::AuthenticateCallbackWrapper(System.Int32)
extern "C"  void GameCenterPlatform_AuthenticateCallbackWrapper_m_1398924517_0 (Object_t * __this /* static, unused */, int32_t ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::ClearFriends(System.Int32)
extern "C"  void GameCenterPlatform_ClearFriends_m1761222218_0 (Object_t * __this /* static, unused */, int32_t ___size, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::SetFriends(UnityEngine.SocialPlatforms.GameCenter.GcUserProfileData,System.Int32)
extern "C"  void GameCenterPlatform_SetFriends_m_916723254_0 (Object_t * __this /* static, unused */, GcUserProfileData_t1146156361_0  ___data, int32_t ___number, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::SetFriendImage(UnityEngine.Texture2D,System.Int32)
extern "C"  void GameCenterPlatform_SetFriendImage_m_66672633_0 (Object_t * __this /* static, unused */, Texture2D_t_485082364_0 * ___texture, int32_t ___number, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::TriggerFriendsCallbackWrapper(System.Int32)
extern "C"  void GameCenterPlatform_TriggerFriendsCallbackWrapper_m_449922509_0 (Object_t * __this /* static, unused */, int32_t ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::AchievementCallbackWrapper(UnityEngine.SocialPlatforms.GameCenter.GcAchievementData[])
extern "C"  void GameCenterPlatform_AchievementCallbackWrapper_m2031411110_0 (Object_t * __this /* static, unused */, GcAchievementDataU5BU5D_t1326650748_0* ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::ProgressCallbackWrapper(System.Boolean)
extern "C"  void GameCenterPlatform_ProgressCallbackWrapper_m165794409_0 (Object_t * __this /* static, unused */, bool ___success, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::ScoreCallbackWrapper(System.Boolean)
extern "C"  void GameCenterPlatform_ScoreCallbackWrapper_m_1497654972_0 (Object_t * __this /* static, unused */, bool ___success, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::ScoreLoaderCallbackWrapper(UnityEngine.SocialPlatforms.GameCenter.GcScoreData[])
extern "C"  void GameCenterPlatform_ScoreLoaderCallbackWrapper_m_1706128243_0 (Object_t * __this /* static, unused */, GcScoreDataU5BU5D_t_605295777_0* ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.SocialPlatforms.ILocalUser UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::get_localUser()
extern "C"  Object_t * GameCenterPlatform_get_localUser_m1634439374_0 (GameCenterPlatform_t332546685_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::PopulateLocalUser()
extern "C"  void GameCenterPlatform_PopulateLocalUser_m_1711665379_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::LoadAchievementDescriptions(System.Action`1<UnityEngine.SocialPlatforms.IAchievementDescription[]>)
extern "C"  void GameCenterPlatform_LoadAchievementDescriptions_m232801667_0 (GameCenterPlatform_t332546685_0 * __this, Action_1_t_2013501088_0 * ___callback, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::ReportProgress(System.String,System.Double,System.Action`1<System.Boolean>)
extern "C"  void GameCenterPlatform_ReportProgress_m_184467463_0 (GameCenterPlatform_t332546685_0 * __this, String_t* ___id, double ___progress, Action_1_t_1180387379_0 * ___callback, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::LoadAchievements(System.Action`1<UnityEngine.SocialPlatforms.IAchievement[]>)
extern "C"  void GameCenterPlatform_LoadAchievements_m_1549185047_0 (GameCenterPlatform_t332546685_0 * __this, Action_1_t1150423932_0 * ___callback, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::ReportScore(System.Int64,System.String,System.Action`1<System.Boolean>)
extern "C"  void GameCenterPlatform_ReportScore_m1009544586_0 (GameCenterPlatform_t332546685_0 * __this, int64_t ___score, String_t* ___board, Action_1_t_1180387379_0 * ___callback, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::LoadScores(System.String,System.Action`1<UnityEngine.SocialPlatforms.IScore[]>)
extern "C"  void GameCenterPlatform_LoadScores_m_732352469_0 (GameCenterPlatform_t332546685_0 * __this, String_t* ___category, Action_1_t2025153657_0 * ___callback, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::LoadScores(UnityEngine.SocialPlatforms.ILeaderboard,System.Action`1<System.Boolean>)
extern "C"  void GameCenterPlatform_LoadScores_m_1411573185_0 (GameCenterPlatform_t332546685_0 * __this, Object_t * ___board, Action_1_t_1180387379_0 * ___callback, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::LeaderboardCallbackWrapper(System.Boolean)
extern "C"  void GameCenterPlatform_LeaderboardCallbackWrapper_m_2129813767_0 (Object_t * __this /* static, unused */, bool ___success, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::GetLoading(UnityEngine.SocialPlatforms.ILeaderboard)
extern "C"  bool GameCenterPlatform_GetLoading_m2084830155_0 (GameCenterPlatform_t332546685_0 * __this, Object_t * ___board, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::VerifyAuthentication()
extern "C"  bool GameCenterPlatform_VerifyAuthentication_m_198017316_0 (GameCenterPlatform_t332546685_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::ShowAchievementsUI()
extern "C"  void GameCenterPlatform_ShowAchievementsUI_m_1857627706_0 (GameCenterPlatform_t332546685_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::ShowLeaderboardUI()
extern "C"  void GameCenterPlatform_ShowLeaderboardUI_m302984165_0 (GameCenterPlatform_t332546685_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::ClearUsers(System.Int32)
extern "C"  void GameCenterPlatform_ClearUsers_m_82056643_0 (Object_t * __this /* static, unused */, int32_t ___size, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::SetUser(UnityEngine.SocialPlatforms.GameCenter.GcUserProfileData,System.Int32)
extern "C"  void GameCenterPlatform_SetUser_m847940592_0 (Object_t * __this /* static, unused */, GcUserProfileData_t1146156361_0  ___data, int32_t ___number, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::SetUserImage(UnityEngine.Texture2D,System.Int32)
extern "C"  void GameCenterPlatform_SetUserImage_m_1228377862_0 (Object_t * __this /* static, unused */, Texture2D_t_485082364_0 * ___texture, int32_t ___number, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::TriggerUsersCallbackWrapper()
extern "C"  void GameCenterPlatform_TriggerUsersCallbackWrapper_m_1848495665_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::LoadUsers(System.String[],System.Action`1<UnityEngine.SocialPlatforms.IUserProfile[]>)
extern "C"  void GameCenterPlatform_LoadUsers_m981272890_0 (GameCenterPlatform_t332546685_0 * __this, StringU5BU5D_t_816028754_0* ___userIds, Action_1_t1059329261_0 * ___callback, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::SafeSetUserImage(UnityEngine.SocialPlatforms.Impl.UserProfile[]&,UnityEngine.Texture2D,System.Int32)
extern "C"  void GameCenterPlatform_SafeSetUserImage_m_644868899_0 (Object_t * __this /* static, unused */, UserProfileU5BU5D_t_2081017386_0** ___array, Texture2D_t_485082364_0 * ___texture, int32_t ___number, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::SafeClearArray(UnityEngine.SocialPlatforms.Impl.UserProfile[]&,System.Int32)
extern "C"  void GameCenterPlatform_SafeClearArray_m_1748115407_0 (Object_t * __this /* static, unused */, UserProfileU5BU5D_t_2081017386_0** ___array, int32_t ___size, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.SocialPlatforms.ILeaderboard UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::CreateLeaderboard()
extern "C"  Object_t * GameCenterPlatform_CreateLeaderboard_m_1999917413_0 (GameCenterPlatform_t332546685_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.SocialPlatforms.IAchievement UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::CreateAchievement()
extern "C"  Object_t * GameCenterPlatform_CreateAchievement_m1828880347_0 (GameCenterPlatform_t332546685_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.SocialPlatforms.GameCenter.GameCenterPlatform::TriggerResetAchievementCallback(System.Boolean)
extern "C"  void GameCenterPlatform_TriggerResetAchievementCallback_m1285257317_0 (Object_t * __this /* static, unused */, bool ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
