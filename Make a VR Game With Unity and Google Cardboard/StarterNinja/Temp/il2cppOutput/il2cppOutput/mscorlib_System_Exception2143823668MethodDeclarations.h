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

// System.Exception
struct Exception_t2143823668_0;
// System.String
struct String_t;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;
// System.Text.StringBuilder
struct StringBuilder_t586045924_0;
// System.Reflection.MethodBase
struct MethodBase_t553742458_0;
// System.Type
struct Type_t;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"

// System.Void System.Exception::.ctor()
extern "C"  void Exception__ctor_m_1071876638_0 (Exception_t2143823668_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Exception::.ctor(System.String)
extern "C"  void Exception__ctor_m_424196000_0 (Exception_t2143823668_0 * __this, String_t* ___message, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Exception::.ctor(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void Exception__ctor_m_692953053_0 (Exception_t2143823668_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Exception::.ctor(System.String,System.Exception)
extern "C"  void Exception__ctor_m1328171222_0 (Exception_t2143823668_0 * __this, String_t* ___message, Exception_t2143823668_0 * ___innerException, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Exception System.Exception::get_InnerException()
extern "C"  Exception_t2143823668_0 * Exception_get_InnerException_m1427945535_0 (Exception_t2143823668_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Exception::set_HResult(System.Int32)
extern "C"  void Exception_set_HResult_m_728396071_0 (Exception_t2143823668_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Exception::get_ClassName()
extern "C"  String_t* Exception_get_ClassName_m_1369185161_0 (Exception_t2143823668_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Exception::get_Message()
extern "C"  String_t* Exception_get_Message_m1013139483_0 (Exception_t2143823668_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Exception::get_Source()
extern "C"  String_t* Exception_get_Source_m_1499675863_0 (Exception_t2143823668_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Exception::get_StackTrace()
extern "C"  String_t* Exception_get_StackTrace_m382134187_0 (Exception_t2143823668_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Exception::GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void Exception_GetObjectData_m1945031808_0 (Exception_t2143823668_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Exception::ToString()
extern "C"  String_t* Exception_ToString_m1076460401_0 (Exception_t2143823668_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Exception::GetFullNameForStackTrace(System.Text.StringBuilder,System.Reflection.MethodBase)
extern "C"  void Exception_GetFullNameForStackTrace_m130874526_0 (Exception_t2143823668_0 * __this, StringBuilder_t586045924_0 * ___sb, MethodBase_t553742458_0 * ___mi, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type System.Exception::GetType()
extern "C"  Type_t * Exception_GetType_m913902486_0 (Exception_t2143823668_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
