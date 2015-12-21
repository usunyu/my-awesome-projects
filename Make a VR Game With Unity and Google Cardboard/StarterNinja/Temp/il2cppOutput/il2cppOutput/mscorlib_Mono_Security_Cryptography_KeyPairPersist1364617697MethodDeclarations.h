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

// Mono.Security.Cryptography.KeyPairPersistence
struct KeyPairPersistence_t1364617697_0;
// System.Security.Cryptography.CspParameters
struct CspParameters_t_1753320293_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Security.Cryptography.KeyPairPersistence::.ctor(System.Security.Cryptography.CspParameters)
extern "C"  void KeyPairPersistence__ctor_m_220047304_0 (KeyPairPersistence_t1364617697_0 * __this, CspParameters_t_1753320293_0 * ___parameters, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.KeyPairPersistence::.ctor(System.Security.Cryptography.CspParameters,System.String)
extern "C"  void KeyPairPersistence__ctor_m1684061812_0 (KeyPairPersistence_t1364617697_0 * __this, CspParameters_t_1753320293_0 * ___parameters, String_t* ___keyPair, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.KeyPairPersistence::.cctor()
extern "C"  void KeyPairPersistence__cctor_m487272190_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.Cryptography.KeyPairPersistence::get_Filename()
extern "C"  String_t* KeyPairPersistence_get_Filename_m_2139853662_0 (KeyPairPersistence_t1364617697_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.Cryptography.KeyPairPersistence::get_KeyValue()
extern "C"  String_t* KeyPairPersistence_get_KeyValue_m204692013_0 (KeyPairPersistence_t1364617697_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.KeyPairPersistence::set_KeyValue(System.String)
extern "C"  void KeyPairPersistence_set_KeyValue_m_1504011554_0 (KeyPairPersistence_t1364617697_0 * __this, String_t* ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Cryptography.KeyPairPersistence::Load()
extern "C"  bool KeyPairPersistence_Load_m625005177_0 (KeyPairPersistence_t1364617697_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.KeyPairPersistence::Save()
extern "C"  void KeyPairPersistence_Save_m870778642_0 (KeyPairPersistence_t1364617697_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.KeyPairPersistence::Remove()
extern "C"  void KeyPairPersistence_Remove_m860812121_0 (KeyPairPersistence_t1364617697_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.Cryptography.KeyPairPersistence::get_UserPath()
extern "C"  String_t* KeyPairPersistence_get_UserPath_m1086915307_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.Cryptography.KeyPairPersistence::get_MachinePath()
extern "C"  String_t* KeyPairPersistence_get_MachinePath_m_291495565_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Cryptography.KeyPairPersistence::_CanSecure(System.String)
extern "C"  bool KeyPairPersistence__CanSecure_m255016359_0 (Object_t * __this /* static, unused */, String_t* ___root, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Cryptography.KeyPairPersistence::_ProtectUser(System.String)
extern "C"  bool KeyPairPersistence__ProtectUser_m_623488460_0 (Object_t * __this /* static, unused */, String_t* ___path, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Cryptography.KeyPairPersistence::_ProtectMachine(System.String)
extern "C"  bool KeyPairPersistence__ProtectMachine_m1278598652_0 (Object_t * __this /* static, unused */, String_t* ___path, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Cryptography.KeyPairPersistence::_IsUserProtected(System.String)
extern "C"  bool KeyPairPersistence__IsUserProtected_m_1916660235_0 (Object_t * __this /* static, unused */, String_t* ___path, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Cryptography.KeyPairPersistence::_IsMachineProtected(System.String)
extern "C"  bool KeyPairPersistence__IsMachineProtected_m_28273309_0 (Object_t * __this /* static, unused */, String_t* ___path, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Cryptography.KeyPairPersistence::CanSecure(System.String)
extern "C"  bool KeyPairPersistence_CanSecure_m_82983188_0 (Object_t * __this /* static, unused */, String_t* ___path, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Cryptography.KeyPairPersistence::ProtectUser(System.String)
extern "C"  bool KeyPairPersistence_ProtectUser_m976461369_0 (Object_t * __this /* static, unused */, String_t* ___path, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Cryptography.KeyPairPersistence::ProtectMachine(System.String)
extern "C"  bool KeyPairPersistence_ProtectMachine_m_163096617_0 (Object_t * __this /* static, unused */, String_t* ___path, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Cryptography.KeyPairPersistence::IsUserProtected(System.String)
extern "C"  bool KeyPairPersistence_IsUserProtected_m635426682_0 (Object_t * __this /* static, unused */, String_t* ___path, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Cryptography.KeyPairPersistence::IsMachineProtected(System.String)
extern "C"  bool KeyPairPersistence_IsMachineProtected_m_318002754_0 (Object_t * __this /* static, unused */, String_t* ___path, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Cryptography.KeyPairPersistence::get_CanChange()
extern "C"  bool KeyPairPersistence_get_CanChange_m_540010650_0 (KeyPairPersistence_t1364617697_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Cryptography.KeyPairPersistence::get_UseDefaultKeyContainer()
extern "C"  bool KeyPairPersistence_get_UseDefaultKeyContainer_m1048698904_0 (KeyPairPersistence_t1364617697_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Cryptography.KeyPairPersistence::get_UseMachineKeyStore()
extern "C"  bool KeyPairPersistence_get_UseMachineKeyStore_m_1394807298_0 (KeyPairPersistence_t1364617697_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.Cryptography.KeyPairPersistence::get_ContainerName()
extern "C"  String_t* KeyPairPersistence_get_ContainerName_m_870536813_0 (KeyPairPersistence_t1364617697_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Security.Cryptography.CspParameters Mono.Security.Cryptography.KeyPairPersistence::Copy(System.Security.Cryptography.CspParameters)
extern "C"  CspParameters_t_1753320293_0 * KeyPairPersistence_Copy_m_1677992961_0 (KeyPairPersistence_t1364617697_0 * __this, CspParameters_t_1753320293_0 * ___p, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Cryptography.KeyPairPersistence::FromXml(System.String)
extern "C"  void KeyPairPersistence_FromXml_m1868637128_0 (KeyPairPersistence_t1364617697_0 * __this, String_t* ___xml, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Security.Cryptography.KeyPairPersistence::ToXml()
extern "C"  String_t* KeyPairPersistence_ToXml_m_1484512276_0 (KeyPairPersistence_t1364617697_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
