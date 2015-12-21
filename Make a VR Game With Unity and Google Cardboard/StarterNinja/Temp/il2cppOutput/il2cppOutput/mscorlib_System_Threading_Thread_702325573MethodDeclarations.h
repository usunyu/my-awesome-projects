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

// System.Threading.Thread
struct Thread_t_702325573_0;
// System.Threading.ThreadStart
struct ThreadStart_t_914869145_0;
// System.Runtime.Remoting.Contexts.Context
struct Context_t_1732618593_0;
// System.MulticastDelegate
struct MulticastDelegate_t_674203774_0;
// System.Globalization.CultureInfo
struct CultureInfo_t_1039475404_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.String
struct String_t;
// System.Threading.ExecutionContext
struct ExecutionContext_t1832451304_0;
// System.Threading.CompressedStack
struct CompressedStack_t_1011131402_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_IntPtr_1047952454.h"
#include "mscorlib_System_Threading_ThreadState_914869098.h"

// System.Void System.Threading.Thread::.ctor(System.Threading.ThreadStart)
extern "C"  void Thread__ctor_m_1122158_0 (Thread_t_702325573_0 * __this, ThreadStart_t_914869145_0 * ___start, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.Thread::.cctor()
extern "C"  void Thread__cctor_m_697910888_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Contexts.Context System.Threading.Thread::get_CurrentContext()
extern "C"  Context_t_1732618593_0 * Thread_get_CurrentContext_m1613403838_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Threading.Thread System.Threading.Thread::CurrentThread_internal()
extern "C"  Thread_t_702325573_0 * Thread_CurrentThread_internal_m_491863820_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Threading.Thread System.Threading.Thread::get_CurrentThread()
extern "C"  Thread_t_702325573_0 * Thread_get_CurrentThread_m1523593825_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.Thread::FreeLocalSlotValues(System.Int32,System.Boolean)
extern "C"  void Thread_FreeLocalSlotValues_m_1105471046_0 (Object_t * __this /* static, unused */, int32_t ___slot, bool ___thread_local, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Threading.Thread::GetDomainID()
extern "C"  int32_t Thread_GetDomainID_m_710571900_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.IntPtr System.Threading.Thread::Thread_internal(System.MulticastDelegate)
extern "C"  IntPtr_t Thread_Thread_internal_m1309677628_0 (Thread_t_702325573_0 * __this, MulticastDelegate_t_674203774_0 * ___start, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.Thread::Thread_init()
extern "C"  void Thread_Thread_init_m_349734600_0 (Thread_t_702325573_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.CultureInfo System.Threading.Thread::GetCachedCurrentCulture()
extern "C"  CultureInfo_t_1039475404_0 * Thread_GetCachedCurrentCulture_m432100475_0 (Thread_t_702325573_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Threading.Thread::GetSerializedCurrentCulture()
extern "C"  ByteU5BU5D_t_1238178395_0* Thread_GetSerializedCurrentCulture_m_1436182580_0 (Thread_t_702325573_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.Thread::SetCachedCurrentCulture(System.Globalization.CultureInfo)
extern "C"  void Thread_SetCachedCurrentCulture_m1882292988_0 (Thread_t_702325573_0 * __this, CultureInfo_t_1039475404_0 * ___culture, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.CultureInfo System.Threading.Thread::GetCachedCurrentUICulture()
extern "C"  CultureInfo_t_1039475404_0 * Thread_GetCachedCurrentUICulture_m_76266137_0 (Thread_t_702325573_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.Threading.Thread::GetSerializedCurrentUICulture()
extern "C"  ByteU5BU5D_t_1238178395_0* Thread_GetSerializedCurrentUICulture_m_199952264_0 (Thread_t_702325573_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.Thread::SetCachedCurrentUICulture(System.Globalization.CultureInfo)
extern "C"  void Thread_SetCachedCurrentUICulture_m1939313576_0 (Thread_t_702325573_0 * __this, CultureInfo_t_1039475404_0 * ___culture, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.CultureInfo System.Threading.Thread::get_CurrentCulture()
extern "C"  CultureInfo_t_1039475404_0 * Thread_get_CurrentCulture_m334626002_0 (Thread_t_702325573_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.CultureInfo System.Threading.Thread::get_CurrentUICulture()
extern "C"  CultureInfo_t_1039475404_0 * Thread_get_CurrentUICulture_m740045822_0 (Thread_t_702325573_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.Thread::set_IsBackground(System.Boolean)
extern "C"  void Thread_set_IsBackground_m1141752027_0 (Thread_t_702325573_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.Thread::SetName_internal(System.String)
extern "C"  void Thread_SetName_internal_m_1039133212_0 (Thread_t_702325573_0 * __this, String_t* ___name, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.Thread::set_Name(System.String)
extern "C"  void Thread_set_Name_m597236523_0 (Thread_t_702325573_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.Thread::Start()
extern "C"  void Thread_Start_m_228539979_0 (Thread_t_702325573_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.Thread::Thread_free_internal(System.IntPtr)
extern "C"  void Thread_Thread_free_internal_m1268585386_0 (Thread_t_702325573_0 * __this, IntPtr_t ___handle, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.Thread::Finalize()
extern "C"  void Thread_Finalize_m_1136967795_0 (Thread_t_702325573_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.Thread::SetState(System.Threading.ThreadState)
extern "C"  void Thread_SetState_m_1712978292_0 (Thread_t_702325573_0 * __this, int32_t ___set, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Threading.Thread::ClrState(System.Threading.ThreadState)
extern "C"  void Thread_ClrState_m634688613_0 (Thread_t_702325573_0 * __this, int32_t ___clr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Threading.Thread::GetNewManagedId()
extern "C"  int32_t Thread_GetNewManagedId_m_314032577_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Threading.Thread::GetNewManagedId_internal()
extern "C"  int32_t Thread_GetNewManagedId_internal_m_373771617_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Threading.ExecutionContext System.Threading.Thread::get_ExecutionContext()
extern "C"  ExecutionContext_t1832451304_0 * Thread_get_ExecutionContext_m1683588744_0 (Thread_t_702325573_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Threading.Thread::get_ManagedThreadId()
extern "C"  int32_t Thread_get_ManagedThreadId_m_379334326_0 (Thread_t_702325573_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Threading.Thread::GetHashCode()
extern "C"  int32_t Thread_GetHashCode_m736270528_0 (Thread_t_702325573_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Threading.CompressedStack System.Threading.Thread::GetCompressedStack()
extern "C"  CompressedStack_t_1011131402_0 * Thread_GetCompressedStack_m_966289753_0 (Thread_t_702325573_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
