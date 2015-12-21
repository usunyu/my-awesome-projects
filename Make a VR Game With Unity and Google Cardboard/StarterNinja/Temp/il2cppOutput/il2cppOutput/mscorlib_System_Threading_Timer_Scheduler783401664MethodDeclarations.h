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

// System.Threading.Timer/Scheduler
struct Scheduler_t783401664_0;
// System.Threading.Timer
struct Timer_t_161177996_0;
// System.Collections.ArrayList
struct ArrayList_t536890563_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Threading.Timer/Scheduler::.ctor()
extern "C"  void Scheduler__ctor_m1239585238_0 (Scheduler_t783401664_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.Timer/Scheduler::.cctor()
extern "C"  void Scheduler__cctor_m_709659497_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Threading.Timer/Scheduler System.Threading.Timer/Scheduler::get_Instance()
extern "C"  Scheduler_t783401664_0 * Scheduler_get_Instance_m_2056962949_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.Timer/Scheduler::Remove(System.Threading.Timer)
extern "C"  void Scheduler_Remove_m1246429346_0 (Scheduler_t783401664_0 * __this, Timer_t_161177996_0 * ___timer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.Timer/Scheduler::Change(System.Threading.Timer,System.Int64)
extern "C"  void Scheduler_Change_m_692228278_0 (Scheduler_t783401664_0 * __this, Timer_t_161177996_0 * ___timer, int64_t ___new_next_run, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.Timer/Scheduler::Add(System.Threading.Timer)
extern "C"  void Scheduler_Add_m1591289733_0 (Scheduler_t783401664_0 * __this, Timer_t_161177996_0 * ___timer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Threading.Timer/Scheduler::InternalRemove(System.Threading.Timer)
extern "C"  int32_t Scheduler_InternalRemove_m1022594523_0 (Scheduler_t783401664_0 * __this, Timer_t_161177996_0 * ___timer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.Timer/Scheduler::SchedulerThread()
extern "C"  void Scheduler_SchedulerThread_m2007715993_0 (Scheduler_t783401664_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.Timer/Scheduler::ShrinkIfNeeded(System.Collections.ArrayList,System.Int32)
extern "C"  void Scheduler_ShrinkIfNeeded_m_157022707_0 (Scheduler_t783401664_0 * __this, ArrayList_t536890563_0 * ___list, int32_t ___initial, const MethodInfo* method) IL2CPP_METHOD_ATTR;
