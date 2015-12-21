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

// Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult
struct InternalAsyncResult_t_104888446_0;
// System.AsyncCallback
struct AsyncCallback_t_266361018_0;
// System.Object
struct Object_t;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Exception
struct Exception_t2143823668_0;
// System.Threading.WaitHandle
struct WaitHandle_t1045483054_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult::.ctor(System.AsyncCallback,System.Object,System.Byte[],System.Int32,System.Int32,System.Boolean,System.Boolean)
extern "C"  void InternalAsyncResult__ctor_m358982211_0 (InternalAsyncResult_t_104888446_0 * __this, AsyncCallback_t_266361018_0 * ___userCallback, Object_t * ___userState, ByteU5BU5D_t_1238178395_0* ___buffer, int32_t ___offset, int32_t ___count, bool ___fromWrite, bool ___proceedAfterHandshake, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult::get_ProceedAfterHandshake()
extern "C"  bool InternalAsyncResult_get_ProceedAfterHandshake_m_1400533628_0 (InternalAsyncResult_t_104888446_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult::get_FromWrite()
extern "C"  bool InternalAsyncResult_get_FromWrite_m619101712_0 (InternalAsyncResult_t_104888446_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult::get_Buffer()
extern "C"  ByteU5BU5D_t_1238178395_0* InternalAsyncResult_get_Buffer_m_1536335773_0 (InternalAsyncResult_t_104888446_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult::get_Offset()
extern "C"  int32_t InternalAsyncResult_get_Offset_m_509669068_0 (InternalAsyncResult_t_104888446_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult::get_Count()
extern "C"  int32_t InternalAsyncResult_get_Count_m_1805172240_0 (InternalAsyncResult_t_104888446_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult::get_BytesRead()
extern "C"  int32_t InternalAsyncResult_get_BytesRead_m2065687810_0 (InternalAsyncResult_t_104888446_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult::get_AsyncState()
extern "C"  Object_t * InternalAsyncResult_get_AsyncState_m478600163_0 (InternalAsyncResult_t_104888446_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Exception Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult::get_AsyncException()
extern "C"  Exception_t2143823668_0 * InternalAsyncResult_get_AsyncException_m789203443_0 (InternalAsyncResult_t_104888446_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult::get_CompletedWithError()
extern "C"  bool InternalAsyncResult_get_CompletedWithError_m_2026021026_0 (InternalAsyncResult_t_104888446_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Threading.WaitHandle Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult::get_AsyncWaitHandle()
extern "C"  WaitHandle_t1045483054_0 * InternalAsyncResult_get_AsyncWaitHandle_m_1436941055_0 (InternalAsyncResult_t_104888446_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult::get_IsCompleted()
extern "C"  bool InternalAsyncResult_get_IsCompleted_m517442172_0 (InternalAsyncResult_t_104888446_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult::SetComplete(System.Exception,System.Int32)
extern "C"  void InternalAsyncResult_SetComplete_m849188890_0 (InternalAsyncResult_t_104888446_0 * __this, Exception_t2143823668_0 * ___ex, int32_t ___bytesRead, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult::SetComplete(System.Exception)
extern "C"  void InternalAsyncResult_SetComplete_m1458533341_0 (InternalAsyncResult_t_104888446_0 * __this, Exception_t2143823668_0 * ___ex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult::SetComplete(System.Int32)
extern "C"  void InternalAsyncResult_SetComplete_m_1806289154_0 (InternalAsyncResult_t_104888446_0 * __this, int32_t ___bytesRead, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.SslStreamBase/InternalAsyncResult::SetComplete()
extern "C"  void InternalAsyncResult_SetComplete_m1352916269_0 (InternalAsyncResult_t_104888446_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
