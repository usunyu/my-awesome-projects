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

// System.Runtime.Serialization.ObjectRecord
struct ObjectRecord_t468465279_0;
// System.Runtime.Serialization.ObjectManager
struct ObjectManager_t1390185279_0;
// System.Reflection.MemberInfo
struct MemberInfo_t;
// System.Object
struct Object_t;
// System.Int32[]
struct Int32U5BU5D_t1872284309_0;
// System.String
struct String_t;
// System.Runtime.Serialization.BaseFixupRecord
struct BaseFixupRecord_t_157516319_0;
// System.Runtime.Serialization.ISurrogateSelector
struct ISurrogateSelector_t_470051779_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Runtime_Serialization_StreamingCo_1216992900.h"

// System.Void System.Runtime.Serialization.ObjectRecord::.ctor()
extern "C"  void ObjectRecord__ctor_m_1035115983_0 (ObjectRecord_t468465279_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Serialization.ObjectRecord::SetMemberValue(System.Runtime.Serialization.ObjectManager,System.Reflection.MemberInfo,System.Object)
extern "C"  void ObjectRecord_SetMemberValue_m_284660901_0 (ObjectRecord_t468465279_0 * __this, ObjectManager_t1390185279_0 * ___manager, MemberInfo_t * ___member, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Serialization.ObjectRecord::SetArrayValue(System.Runtime.Serialization.ObjectManager,System.Object,System.Int32[])
extern "C"  void ObjectRecord_SetArrayValue_m_1557204487_0 (ObjectRecord_t468465279_0 * __this, ObjectManager_t1390185279_0 * ___manager, Object_t * ___value, Int32U5BU5D_t1872284309_0* ___indices, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Serialization.ObjectRecord::SetMemberValue(System.Runtime.Serialization.ObjectManager,System.String,System.Object)
extern "C"  void ObjectRecord_SetMemberValue_m_1715310793_0 (ObjectRecord_t468465279_0 * __this, ObjectManager_t1390185279_0 * ___manager, String_t* ___memberName, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Serialization.ObjectRecord::get_IsInstanceReady()
extern "C"  bool ObjectRecord_get_IsInstanceReady_m760710444_0 (ObjectRecord_t468465279_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Serialization.ObjectRecord::get_IsUnsolvedObjectReference()
extern "C"  bool ObjectRecord_get_IsUnsolvedObjectReference_m201102828_0 (ObjectRecord_t468465279_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Serialization.ObjectRecord::get_IsRegistered()
extern "C"  bool ObjectRecord_get_IsRegistered_m_424520058_0 (ObjectRecord_t468465279_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Serialization.ObjectRecord::DoFixups(System.Boolean,System.Runtime.Serialization.ObjectManager,System.Boolean)
extern "C"  bool ObjectRecord_DoFixups_m_1738700632_0 (ObjectRecord_t468465279_0 * __this, bool ___asContainer, ObjectManager_t1390185279_0 * ___manager, bool ___strict, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Serialization.ObjectRecord::RemoveFixup(System.Runtime.Serialization.BaseFixupRecord,System.Boolean)
extern "C"  void ObjectRecord_RemoveFixup_m716979711_0 (ObjectRecord_t468465279_0 * __this, BaseFixupRecord_t_157516319_0 * ___fixupToRemove, bool ___asContainer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Serialization.ObjectRecord::UnchainFixup(System.Runtime.Serialization.BaseFixupRecord,System.Runtime.Serialization.BaseFixupRecord,System.Boolean)
extern "C"  void ObjectRecord_UnchainFixup_m_388594990_0 (ObjectRecord_t468465279_0 * __this, BaseFixupRecord_t_157516319_0 * ___fixup, BaseFixupRecord_t_157516319_0 * ___prevFixup, bool ___asContainer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Serialization.ObjectRecord::ChainFixup(System.Runtime.Serialization.BaseFixupRecord,System.Boolean)
extern "C"  void ObjectRecord_ChainFixup_m_1755024424_0 (ObjectRecord_t468465279_0 * __this, BaseFixupRecord_t_157516319_0 * ___fixup, bool ___asContainer, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Serialization.ObjectRecord::LoadData(System.Runtime.Serialization.ObjectManager,System.Runtime.Serialization.ISurrogateSelector,System.Runtime.Serialization.StreamingContext)
extern "C"  bool ObjectRecord_LoadData_m_1140100899_0 (ObjectRecord_t468465279_0 * __this, ObjectManager_t1390185279_0 * ___manager, Object_t * ___selector, StreamingContext_t_1216992900_0  ___context, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Runtime.Serialization.ObjectRecord::get_HasPendingFixups()
extern "C"  bool ObjectRecord_get_HasPendingFixups_m_1986040134_0 (ObjectRecord_t468465279_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
