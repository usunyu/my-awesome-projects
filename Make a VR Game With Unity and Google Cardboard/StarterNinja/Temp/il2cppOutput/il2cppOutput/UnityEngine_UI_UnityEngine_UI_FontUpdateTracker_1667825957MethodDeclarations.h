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

// UnityEngine.UI.Text
struct Text_t_204341102_0;
// UnityEngine.Font
struct Font_t_982288488_0;

#include "codegen/il2cpp-codegen.h"

// System.Void UnityEngine.UI.FontUpdateTracker::.cctor()
extern "C"  void FontUpdateTracker__cctor_m1924252658_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.FontUpdateTracker::TrackText(UnityEngine.UI.Text)
extern "C"  void FontUpdateTracker_TrackText_m1576315537_0 (Object_t * __this /* static, unused */, Text_t_204341102_0 * ___t, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.FontUpdateTracker::RebuildForFont(UnityEngine.Font)
extern "C"  void FontUpdateTracker_RebuildForFont_m_244056480_0 (Object_t * __this /* static, unused */, Font_t_982288488_0 * ___f, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.UI.FontUpdateTracker::UntrackText(UnityEngine.UI.Text)
extern "C"  void FontUpdateTracker_UntrackText_m1952028010_0 (Object_t * __this /* static, unused */, Text_t_204341102_0 * ___t, const MethodInfo* method) IL2CPP_METHOD_ATTR;
