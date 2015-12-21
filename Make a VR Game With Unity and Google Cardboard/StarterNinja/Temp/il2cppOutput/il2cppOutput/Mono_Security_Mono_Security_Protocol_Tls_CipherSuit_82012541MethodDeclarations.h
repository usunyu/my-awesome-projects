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

// Mono.Security.Protocol.Tls.CipherSuiteCollection
struct CipherSuiteCollection_t_82012541_0;
// System.Object
struct Object_t;
// System.Collections.IEnumerator
struct IEnumerator_t1412936761_0;
// Mono.Security.Protocol.Tls.CipherSuite
struct CipherSuite_t_1835594235_0;
// System.String
struct String_t;
// System.Array
struct Array_t;
// Mono.Security.Protocol.Tls.TlsCipherSuite
struct TlsCipherSuite_t586702426_0;
// Mono.Security.Protocol.Tls.SslCipherSuite
struct SslCipherSuite_t_1865139031_0;

#include "codegen/il2cpp-codegen.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_SecurityP_942303750.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_CipherAl_2011610538.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_HashAlgor_103851469.h"
#include "Mono_Security_Mono_Security_Protocol_Tls_ExchangeAl701975358.h"

// System.Void Mono.Security.Protocol.Tls.CipherSuiteCollection::.ctor(Mono.Security.Protocol.Tls.SecurityProtocolType)
extern "C"  void CipherSuiteCollection__ctor_m273269703_0 (CipherSuiteCollection_t_82012541_0 * __this, int32_t ___protocol, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object Mono.Security.Protocol.Tls.CipherSuiteCollection::System.Collections.IList.get_Item(System.Int32)
extern "C"  Object_t * CipherSuiteCollection_System_Collections_IList_get_Item_m_975431800_0 (CipherSuiteCollection_t_82012541_0 * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.CipherSuiteCollection::System.Collections.IList.set_Item(System.Int32,System.Object)
extern "C"  void CipherSuiteCollection_System_Collections_IList_set_Item_m_38978209_0 (CipherSuiteCollection_t_82012541_0 * __this, int32_t ___index, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.CipherSuiteCollection::System.Collections.ICollection.get_IsSynchronized()
extern "C"  bool CipherSuiteCollection_System_Collections_ICollection_get_IsSynchronized_m_596839863_0 (CipherSuiteCollection_t_82012541_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object Mono.Security.Protocol.Tls.CipherSuiteCollection::System.Collections.ICollection.get_SyncRoot()
extern "C"  Object_t * CipherSuiteCollection_System_Collections_ICollection_get_SyncRoot_m914076225_0 (CipherSuiteCollection_t_82012541_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator Mono.Security.Protocol.Tls.CipherSuiteCollection::System.Collections.IEnumerable.GetEnumerator()
extern "C"  Object_t * CipherSuiteCollection_System_Collections_IEnumerable_GetEnumerator_m1907853496_0 (CipherSuiteCollection_t_82012541_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.CipherSuiteCollection::System.Collections.IList.Contains(System.Object)
extern "C"  bool CipherSuiteCollection_System_Collections_IList_Contains_m_799730637_0 (CipherSuiteCollection_t_82012541_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Protocol.Tls.CipherSuiteCollection::System.Collections.IList.IndexOf(System.Object)
extern "C"  int32_t CipherSuiteCollection_System_Collections_IList_IndexOf_m_1497938031_0 (CipherSuiteCollection_t_82012541_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.CipherSuiteCollection::System.Collections.IList.Insert(System.Int32,System.Object)
extern "C"  void CipherSuiteCollection_System_Collections_IList_Insert_m414962568_0 (CipherSuiteCollection_t_82012541_0 * __this, int32_t ___index, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.CipherSuiteCollection::System.Collections.IList.Remove(System.Object)
extern "C"  void CipherSuiteCollection_System_Collections_IList_Remove_m46053536_0 (CipherSuiteCollection_t_82012541_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.CipherSuiteCollection::System.Collections.IList.RemoveAt(System.Int32)
extern "C"  void CipherSuiteCollection_System_Collections_IList_RemoveAt_m_1281951976_0 (CipherSuiteCollection_t_82012541_0 * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Protocol.Tls.CipherSuiteCollection::System.Collections.IList.Add(System.Object)
extern "C"  int32_t CipherSuiteCollection_System_Collections_IList_Add_m_1768254023_0 (CipherSuiteCollection_t_82012541_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.CipherSuite Mono.Security.Protocol.Tls.CipherSuiteCollection::get_Item(System.String)
extern "C"  CipherSuite_t_1835594235_0 * CipherSuiteCollection_get_Item_m95097157_0 (CipherSuiteCollection_t_82012541_0 * __this, String_t* ___name, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.CipherSuite Mono.Security.Protocol.Tls.CipherSuiteCollection::get_Item(System.Int32)
extern "C"  CipherSuite_t_1835594235_0 * CipherSuiteCollection_get_Item_m_1258590546_0 (CipherSuiteCollection_t_82012541_0 * __this, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.CipherSuiteCollection::set_Item(System.Int32,Mono.Security.Protocol.Tls.CipherSuite)
extern "C"  void CipherSuiteCollection_set_Item_m141821933_0 (CipherSuiteCollection_t_82012541_0 * __this, int32_t ___index, CipherSuite_t_1835594235_0 * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.CipherSuite Mono.Security.Protocol.Tls.CipherSuiteCollection::get_Item(System.Int16)
extern "C"  CipherSuite_t_1835594235_0 * CipherSuiteCollection_get_Item_m_1258592344_0 (CipherSuiteCollection_t_82012541_0 * __this, int16_t ___code, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Protocol.Tls.CipherSuiteCollection::get_Count()
extern "C"  int32_t CipherSuiteCollection_get_Count_m2086503695_0 (CipherSuiteCollection_t_82012541_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.CipherSuiteCollection::get_IsFixedSize()
extern "C"  bool CipherSuiteCollection_get_IsFixedSize_m_1420168667_0 (CipherSuiteCollection_t_82012541_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.CipherSuiteCollection::get_IsReadOnly()
extern "C"  bool CipherSuiteCollection_get_IsReadOnly_m_423087052_0 (CipherSuiteCollection_t_82012541_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.CipherSuiteCollection::CopyTo(System.Array,System.Int32)
extern "C"  void CipherSuiteCollection_CopyTo_m_1563469424_0 (CipherSuiteCollection_t_82012541_0 * __this, Array_t * ___array, int32_t ___index, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Security.Protocol.Tls.CipherSuiteCollection::Clear()
extern "C"  void CipherSuiteCollection_Clear_m_2016532834_0 (CipherSuiteCollection_t_82012541_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Protocol.Tls.CipherSuiteCollection::IndexOf(System.String)
extern "C"  int32_t CipherSuiteCollection_IndexOf_m_648822128_0 (CipherSuiteCollection_t_82012541_0 * __this, String_t* ___name, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Security.Protocol.Tls.CipherSuiteCollection::IndexOf(System.Int16)
extern "C"  int32_t CipherSuiteCollection_IndexOf_m102883581_0 (CipherSuiteCollection_t_82012541_0 * __this, int16_t ___code, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.CipherSuite Mono.Security.Protocol.Tls.CipherSuiteCollection::Add(System.Int16,System.String,Mono.Security.Protocol.Tls.CipherAlgorithmType,Mono.Security.Protocol.Tls.HashAlgorithmType,Mono.Security.Protocol.Tls.ExchangeAlgorithmType,System.Boolean,System.Boolean,System.Byte,System.Byte,System.Int16,System.Byte,System.Byte)
extern "C"  CipherSuite_t_1835594235_0 * CipherSuiteCollection_Add_m667539191_0 (CipherSuiteCollection_t_82012541_0 * __this, int16_t ___code, String_t* ___name, int32_t ___cipherType, int32_t ___hashType, int32_t ___exchangeType, bool ___exportable, bool ___blockMode, uint8_t ___keyMaterialSize, uint8_t ___expandedKeyMaterialSize, int16_t ___effectiveKeyBytes, uint8_t ___ivSize, uint8_t ___blockSize, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.TlsCipherSuite Mono.Security.Protocol.Tls.CipherSuiteCollection::add(Mono.Security.Protocol.Tls.TlsCipherSuite)
extern "C"  TlsCipherSuite_t586702426_0 * CipherSuiteCollection_add_m1902600707_0 (CipherSuiteCollection_t_82012541_0 * __this, TlsCipherSuite_t586702426_0 * ___cipherSuite, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Mono.Security.Protocol.Tls.SslCipherSuite Mono.Security.Protocol.Tls.CipherSuiteCollection::add(Mono.Security.Protocol.Tls.SslCipherSuite)
extern "C"  SslCipherSuite_t_1865139031_0 * CipherSuiteCollection_add_m_1943556827_0 (CipherSuiteCollection_t_82012541_0 * __this, SslCipherSuite_t_1865139031_0 * ___cipherSuite, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Security.Protocol.Tls.CipherSuiteCollection::cultureAwareCompare(System.String,System.String)
extern "C"  bool CipherSuiteCollection_cultureAwareCompare_m850129638_0 (CipherSuiteCollection_t_82012541_0 * __this, String_t* ___strA, String_t* ___strB, const MethodInfo* method) IL2CPP_METHOD_ATTR;
