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

// System.DelegateSerializationHolder/DelegateEntry
struct DelegateEntry_t824638618_0;
// System.Delegate
struct Delegate_t_1791715840_0;
// System.String
struct String_t;
// System.Runtime.Serialization.SerializationInfo
struct SerializationInfo_t526833679_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.DelegateSerializationHolder/DelegateEntry::.ctor(System.Delegate,System.String)
extern "C"  void DelegateEntry__ctor_m2030858126_0 (DelegateEntry_t824638618_0 * __this, Delegate_t_1791715840_0 * ___del, String_t* ___targetLabel, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Delegate System.DelegateSerializationHolder/DelegateEntry::DeserializeDelegate(System.Runtime.Serialization.SerializationInfo)
extern "C"  Delegate_t_1791715840_0 * DelegateEntry_DeserializeDelegate_m151701220_0 (DelegateEntry_t824638618_0 * __this, SerializationInfo_t526833679_0 * ___info, const MethodInfo* method) IL2CPP_METHOD_ATTR;
