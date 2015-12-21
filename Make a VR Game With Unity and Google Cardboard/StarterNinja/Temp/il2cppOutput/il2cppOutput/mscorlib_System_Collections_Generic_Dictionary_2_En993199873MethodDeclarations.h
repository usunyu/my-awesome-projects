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

// System.Collections.Generic.Dictionary`2<System.Int32,System.Object>
struct Dictionary_2_t_1176176332_0;
// System.Object
struct Object_t;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Collections_Generic_Dictionary_2_En993199873.h"
#include "mscorlib_System_Collections_DictionaryEntry_1842557272.h"
#include "mscorlib_System_Collections_Generic_KeyValuePair_2_791204950.h"

// System.Void System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>::.ctor(System.Collections.Generic.Dictionary`2<TKey,TValue>)
extern "C"  void Enumerator__ctor_m_1917852208_0_gshared (Enumerator_t993199873_0 * __this, Dictionary_2_t_1176176332_0 * ___dictionary, const MethodInfo* method);
#define Enumerator__ctor_m_1917852208_0(__this, ___dictionary, method) ((  void (*) (Enumerator_t993199873_0 *, Dictionary_2_t_1176176332_0 *, const MethodInfo*))Enumerator__ctor_m_1917852208_0_gshared)(__this, ___dictionary, method)
// System.Object System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>::System.Collections.IEnumerator.get_Current()
extern "C"  Object_t * Enumerator_System_Collections_IEnumerator_get_Current_m1037642267_0_gshared (Enumerator_t993199873_0 * __this, const MethodInfo* method);
#define Enumerator_System_Collections_IEnumerator_get_Current_m1037642267_0(__this, method) ((  Object_t * (*) (Enumerator_t993199873_0 *, const MethodInfo*))Enumerator_System_Collections_IEnumerator_get_Current_m1037642267_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>::System.Collections.IEnumerator.Reset()
extern "C"  void Enumerator_System_Collections_IEnumerator_Reset_m_1485592347_0_gshared (Enumerator_t993199873_0 * __this, const MethodInfo* method);
#define Enumerator_System_Collections_IEnumerator_Reset_m_1485592347_0(__this, method) ((  void (*) (Enumerator_t993199873_0 *, const MethodInfo*))Enumerator_System_Collections_IEnumerator_Reset_m_1485592347_0_gshared)(__this, method)
// System.Collections.DictionaryEntry System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>::System.Collections.IDictionaryEnumerator.get_Entry()
extern "C"  DictionaryEntry_t_1842557272_0  Enumerator_System_Collections_IDictionaryEnumerator_get_Entry_m_1860752676_0_gshared (Enumerator_t993199873_0 * __this, const MethodInfo* method);
#define Enumerator_System_Collections_IDictionaryEnumerator_get_Entry_m_1860752676_0(__this, method) ((  DictionaryEntry_t_1842557272_0  (*) (Enumerator_t993199873_0 *, const MethodInfo*))Enumerator_System_Collections_IDictionaryEnumerator_get_Entry_m_1860752676_0_gshared)(__this, method)
// System.Object System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>::System.Collections.IDictionaryEnumerator.get_Key()
extern "C"  Object_t * Enumerator_System_Collections_IDictionaryEnumerator_get_Key_m_559339849_0_gshared (Enumerator_t993199873_0 * __this, const MethodInfo* method);
#define Enumerator_System_Collections_IDictionaryEnumerator_get_Key_m_559339849_0(__this, method) ((  Object_t * (*) (Enumerator_t993199873_0 *, const MethodInfo*))Enumerator_System_Collections_IDictionaryEnumerator_get_Key_m_559339849_0_gshared)(__this, method)
// System.Object System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>::System.Collections.IDictionaryEnumerator.get_Value()
extern "C"  Object_t * Enumerator_System_Collections_IDictionaryEnumerator_get_Value_m393753481_0_gshared (Enumerator_t993199873_0 * __this, const MethodInfo* method);
#define Enumerator_System_Collections_IDictionaryEnumerator_get_Value_m393753481_0(__this, method) ((  Object_t * (*) (Enumerator_t993199873_0 *, const MethodInfo*))Enumerator_System_Collections_IDictionaryEnumerator_get_Value_m393753481_0_gshared)(__this, method)
// System.Boolean System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>::MoveNext()
extern "C"  bool Enumerator_MoveNext_m1213995029_0_gshared (Enumerator_t993199873_0 * __this, const MethodInfo* method);
#define Enumerator_MoveNext_m1213995029_0(__this, method) ((  bool (*) (Enumerator_t993199873_0 *, const MethodInfo*))Enumerator_MoveNext_m1213995029_0_gshared)(__this, method)
// System.Collections.Generic.KeyValuePair`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>::get_Current()
extern "C"  KeyValuePair_2_t_791204950_0  Enumerator_get_Current_m1399860359_0_gshared (Enumerator_t993199873_0 * __this, const MethodInfo* method);
#define Enumerator_get_Current_m1399860359_0(__this, method) ((  KeyValuePair_2_t_791204950_0  (*) (Enumerator_t993199873_0 *, const MethodInfo*))Enumerator_get_Current_m1399860359_0_gshared)(__this, method)
// TKey System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>::get_CurrentKey()
extern "C"  int32_t Enumerator_get_CurrentKey_m1767398110_0_gshared (Enumerator_t993199873_0 * __this, const MethodInfo* method);
#define Enumerator_get_CurrentKey_m1767398110_0(__this, method) ((  int32_t (*) (Enumerator_t993199873_0 *, const MethodInfo*))Enumerator_get_CurrentKey_m1767398110_0_gshared)(__this, method)
// TValue System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>::get_CurrentValue()
extern "C"  Object_t * Enumerator_get_CurrentValue_m_910120546_0_gshared (Enumerator_t993199873_0 * __this, const MethodInfo* method);
#define Enumerator_get_CurrentValue_m_910120546_0(__this, method) ((  Object_t * (*) (Enumerator_t993199873_0 *, const MethodInfo*))Enumerator_get_CurrentValue_m_910120546_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>::Reset()
extern "C"  void Enumerator_Reset_m1080084514_0_gshared (Enumerator_t993199873_0 * __this, const MethodInfo* method);
#define Enumerator_Reset_m1080084514_0(__this, method) ((  void (*) (Enumerator_t993199873_0 *, const MethodInfo*))Enumerator_Reset_m1080084514_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>::VerifyState()
extern "C"  void Enumerator_VerifyState_m_1890453845_0_gshared (Enumerator_t993199873_0 * __this, const MethodInfo* method);
#define Enumerator_VerifyState_m_1890453845_0(__this, method) ((  void (*) (Enumerator_t993199873_0 *, const MethodInfo*))Enumerator_VerifyState_m_1890453845_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>::VerifyCurrent()
extern "C"  void Enumerator_VerifyCurrent_m_1505074349_0_gshared (Enumerator_t993199873_0 * __this, const MethodInfo* method);
#define Enumerator_VerifyCurrent_m_1505074349_0(__this, method) ((  void (*) (Enumerator_t993199873_0 *, const MethodInfo*))Enumerator_VerifyCurrent_m_1505074349_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>::Dispose()
extern "C"  void Enumerator_Dispose_m1102561394_0_gshared (Enumerator_t993199873_0 * __this, const MethodInfo* method);
#define Enumerator_Dispose_m1102561394_0(__this, method) ((  void (*) (Enumerator_t993199873_0 *, const MethodInfo*))Enumerator_Dispose_m1102561394_0_gshared)(__this, method)
