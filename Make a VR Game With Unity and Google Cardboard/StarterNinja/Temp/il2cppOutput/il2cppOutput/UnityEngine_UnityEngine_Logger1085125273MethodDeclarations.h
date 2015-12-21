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

// UnityEngine.Logger
struct Logger_t1085125273_0;
// UnityEngine.ILogHandler
struct ILogHandler_t1337460038_0;
// System.String
struct String_t;
// System.Object
struct Object_t;
// UnityEngine.Object
struct Object_t1159094344_0;
struct Object_t1159094344_0_marshaled;
// System.Object[]
struct ObjectU5BU5D_t1774424924_0;
// System.Exception
struct Exception_t2143823668_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_LogType_721401675.h"

// System.Void UnityEngine.Logger::.ctor(UnityEngine.ILogHandler)
extern "C"  void Logger__ctor_m654679389_0 (Logger_t1085125273_0 * __this, Object_t * ___logHandler, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.ILogHandler UnityEngine.Logger::get_logHandler()
extern "C"  Object_t * Logger_get_logHandler_m_1718567727_0 (Logger_t1085125273_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Logger::set_logHandler(UnityEngine.ILogHandler)
extern "C"  void Logger_set_logHandler_m_1633937712_0 (Logger_t1085125273_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Logger::get_logEnabled()
extern "C"  bool Logger_get_logEnabled_m_491619341_0 (Logger_t1085125273_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Logger::set_logEnabled(System.Boolean)
extern "C"  void Logger_set_logEnabled_m1919624760_0 (Logger_t1085125273_0 * __this, bool ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.LogType UnityEngine.Logger::get_filterLogType()
extern "C"  int32_t Logger_get_filterLogType_m1512373196_0 (Logger_t1085125273_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Logger::set_filterLogType(UnityEngine.LogType)
extern "C"  void Logger_set_filterLogType_m_1050251129_0 (Logger_t1085125273_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Logger::IsLogTypeAllowed(UnityEngine.LogType)
extern "C"  bool Logger_IsLogTypeAllowed_m_932059638_0 (Logger_t1085125273_0 * __this, int32_t ___logType, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String UnityEngine.Logger::GetString(System.Object)
extern "C"  String_t* Logger_GetString_m_1261170955_0 (Object_t * __this /* static, unused */, Object_t * ___message, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Logger::Log(UnityEngine.LogType,System.Object)
extern "C"  void Logger_Log_m_419158662_0 (Logger_t1085125273_0 * __this, int32_t ___logType, Object_t * ___message, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Logger::Log(UnityEngine.LogType,System.Object,UnityEngine.Object)
extern "C"  void Logger_Log_m_1109088490_0 (Logger_t1085125273_0 * __this, int32_t ___logType, Object_t * ___message, Object_t1159094344_0 * ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Logger::LogFormat(UnityEngine.LogType,UnityEngine.Object,System.String,System.Object[])
extern "C"  void Logger_LogFormat_m_244950109_0 (Logger_t1085125273_0 * __this, int32_t ___logType, Object_t1159094344_0 * ___context, String_t* ___format, ObjectU5BU5D_t1774424924_0* ___args, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Logger::LogException(System.Exception,UnityEngine.Object)
extern "C"  void Logger_LogException_m426775790_0 (Logger_t1085125273_0 * __this, Exception_t2143823668_0 * ___exception, Object_t1159094344_0 * ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
