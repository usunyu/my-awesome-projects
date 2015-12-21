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

// System.Runtime.Remoting.ClientIdentity
struct ClientIdentity_t_958138237_0;
// System.String
struct String_t;
// System.Runtime.Remoting.ObjRef
struct ObjRef_t436928758_0;
// System.MarshalByRefObject
struct MarshalByRefObject_t1484498776_0;
// System.Type
struct Type_t;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Runtime.Remoting.ClientIdentity::.ctor(System.String,System.Runtime.Remoting.ObjRef)
extern "C"  void ClientIdentity__ctor_m_699839643_0 (ClientIdentity_t_958138237_0 * __this, String_t* ___objectUri, ObjRef_t436928758_0 * ___objRef, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.MarshalByRefObject System.Runtime.Remoting.ClientIdentity::get_ClientProxy()
extern "C"  MarshalByRefObject_t1484498776_0 * ClientIdentity_get_ClientProxy_m_168281004_0 (ClientIdentity_t_958138237_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.ClientIdentity::set_ClientProxy(System.MarshalByRefObject)
extern "C"  void ClientIdentity_set_ClientProxy_m12327679_0 (ClientIdentity_t_958138237_0 * __this, MarshalByRefObject_t1484498776_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.ObjRef System.Runtime.Remoting.ClientIdentity::CreateObjRef(System.Type)
extern "C"  ObjRef_t436928758_0 * ClientIdentity_CreateObjRef_m_1505156201_0 (ClientIdentity_t_958138237_0 * __this, Type_t * ___requestedType, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Runtime.Remoting.ClientIdentity::get_TargetUri()
extern "C"  String_t* ClientIdentity_get_TargetUri_m_838182144_0 (ClientIdentity_t_958138237_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
