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

// System.Runtime.Serialization.FixupRecord
struct FixupRecord_t_982054414_0;
// System.Runtime.Serialization.ObjectRecord
struct ObjectRecord_t468465279_0;
// System.Reflection.MemberInfo
struct MemberInfo_t;
// System.Runtime.Serialization.ObjectManager
struct ObjectManager_t1390185279_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Runtime.Serialization.FixupRecord::.ctor(System.Runtime.Serialization.ObjectRecord,System.Reflection.MemberInfo,System.Runtime.Serialization.ObjectRecord)
extern "C"  void FixupRecord__ctor_m118269336_0 (FixupRecord_t_982054414_0 * __this, ObjectRecord_t468465279_0 * ___objectToBeFixed, MemberInfo_t * ___member, ObjectRecord_t468465279_0 * ___objectRequired, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Serialization.FixupRecord::FixupImpl(System.Runtime.Serialization.ObjectManager)
extern "C"  void FixupRecord_FixupImpl_m200950775_0 (FixupRecord_t_982054414_0 * __this, ObjectManager_t1390185279_0 * ___manager, const MethodInfo* method) IL2CPP_METHOD_ATTR;
