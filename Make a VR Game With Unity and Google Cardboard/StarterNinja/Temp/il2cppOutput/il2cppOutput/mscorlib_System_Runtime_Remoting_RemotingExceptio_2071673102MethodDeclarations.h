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

// System.Runtime.Remoting.RemotingException
struct RemotingException_t_2071673102_0;
// System.String
struct String_t;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;
// System.Exception
struct Exception_t2143823668_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"

// System.Void System.Runtime.Remoting.RemotingException::.ctor()
extern "C"  void RemotingException__ctor_m_1856724194_0 (RemotingException_t_2071673102_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.RemotingException::.ctor(System.String)
extern "C"  void RemotingException__ctor_m_1125417820_0 (RemotingException_t_2071673102_0 * __this, String_t* ___message, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.RemotingException::.ctor(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
extern "C"  void RemotingException__ctor_m1465301855_0 (RemotingException_t_2071673102_0 * __this, SerializationInfo_t526833679_0 * ___info, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.RemotingException::.ctor(System.String,System.Exception)
extern "C"  void RemotingException__ctor_m2401554_0 (RemotingException_t_2071673102_0 * __this, String_t* ___message, Exception_t2143823668_0 * ___InnerException, const MethodInfo* method) IL2CPP_METHOD_ATTR;
