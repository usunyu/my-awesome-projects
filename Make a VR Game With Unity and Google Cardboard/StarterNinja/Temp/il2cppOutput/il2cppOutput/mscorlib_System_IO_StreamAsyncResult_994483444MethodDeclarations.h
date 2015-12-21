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

// System.IO.StreamAsyncResult
struct StreamAsyncResult_t_994483444_0;
// System.Object
struct Object_t;
// System.Exception
struct Exception_t2143823668_0;
// System.Threading.WaitHandle
struct WaitHandle_t1045483054_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.IO.StreamAsyncResult::.ctor(System.Object)
extern "C"  void StreamAsyncResult__ctor_m_654661360_0 (StreamAsyncResult_t_994483444_0 * __this, Object_t * ___state, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.StreamAsyncResult::SetComplete(System.Exception)
extern "C"  void StreamAsyncResult_SetComplete_m1144351501_0 (StreamAsyncResult_t_994483444_0 * __this, Exception_t2143823668_0 * ___e, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.StreamAsyncResult::SetComplete(System.Exception,System.Int32)
extern "C"  void StreamAsyncResult_SetComplete_m345427690_0 (StreamAsyncResult_t_994483444_0 * __this, Exception_t2143823668_0 * ___e, int32_t ___nbytes, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.IO.StreamAsyncResult::get_AsyncState()
extern "C"  Object_t * StreamAsyncResult_get_AsyncState_m_765340887_0 (StreamAsyncResult_t_994483444_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Threading.WaitHandle System.IO.StreamAsyncResult::get_AsyncWaitHandle()
extern "C"  WaitHandle_t1045483054_0 * StreamAsyncResult_get_AsyncWaitHandle_m452819475_0 (StreamAsyncResult_t_994483444_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.IO.StreamAsyncResult::get_IsCompleted()
extern "C"  bool StreamAsyncResult_get_IsCompleted_m1862707516_0 (StreamAsyncResult_t_994483444_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Exception System.IO.StreamAsyncResult::get_Exception()
extern "C"  Exception_t2143823668_0 * StreamAsyncResult_get_Exception_m58775747_0 (StreamAsyncResult_t_994483444_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.StreamAsyncResult::get_NBytes()
extern "C"  int32_t StreamAsyncResult_get_NBytes_m_803485174_0 (StreamAsyncResult_t_994483444_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.IO.StreamAsyncResult::get_Done()
extern "C"  bool StreamAsyncResult_get_Done_m_474462967_0 (StreamAsyncResult_t_994483444_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.StreamAsyncResult::set_Done(System.Boolean)
extern "C"  void StreamAsyncResult_set_Done_m603695862_0 (StreamAsyncResult_t_994483444_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
