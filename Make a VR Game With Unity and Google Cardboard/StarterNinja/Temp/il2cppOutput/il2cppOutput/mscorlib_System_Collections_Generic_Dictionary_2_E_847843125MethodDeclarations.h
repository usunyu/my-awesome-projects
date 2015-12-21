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

// System.Collections.Generic.Dictionary`2<System.Object,System.Boolean>
struct Dictionary_2_t1735729726_0;
// System.Object
struct Object_t;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Collections_Generic_Dictionary_2_E_847843125.h"
#include "mscorlib_System_Collections_DictionaryEntry_1842557272.h"
#include "mscorlib_System_Collections_Generic_KeyValuePair__1968926924.h"

// System.Void System.Collections.Generic.Dictionary`2/Enumerator<System.Object,System.Boolean>::.ctor(System.Collections.Generic.Dictionary`2<TKey,TValue>)
extern "C"  void Enumerator__ctor_m_829413498_0_gshared (Enumerator_t_847843125_0 * __this, Dictionary_2_t1735729726_0 * ___dictionary, const MethodInfo* method);
#define Enumerator__ctor_m_829413498_0(__this, ___dictionary, method) ((  void (*) (Enumerator_t_847843125_0 *, Dictionary_2_t1735729726_0 *, const MethodInfo*))Enumerator__ctor_m_829413498_0_gshared)(__this, ___dictionary, method)
// System.Object System.Collections.Generic.Dictionary`2/Enumerator<System.Object,System.Boolean>::System.Collections.IEnumerator.get_Current()
extern "C"  Object_t * Enumerator_System_Collections_IEnumerator_get_Current_m16779749_0_gshared (Enumerator_t_847843125_0 * __this, const MethodInfo* method);
#define Enumerator_System_Collections_IEnumerator_get_Current_m16779749_0(__this, method) ((  Object_t * (*) (Enumerator_t_847843125_0 *, const MethodInfo*))Enumerator_System_Collections_IEnumerator_get_Current_m16779749_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2/Enumerator<System.Object,System.Boolean>::System.Collections.IEnumerator.Reset()
extern "C"  void Enumerator_System_Collections_IEnumerator_Reset_m_487521937_0_gshared (Enumerator_t_847843125_0 * __this, const MethodInfo* method);
#define Enumerator_System_Collections_IEnumerator_Reset_m_487521937_0(__this, method) ((  void (*) (Enumerator_t_847843125_0 *, const MethodInfo*))Enumerator_System_Collections_IEnumerator_Reset_m_487521937_0_gshared)(__this, method)
// System.Collections.DictionaryEntry System.Collections.Generic.Dictionary`2/Enumerator<System.Object,System.Boolean>::System.Collections.IDictionaryEnumerator.get_Entry()
extern "C"  DictionaryEntry_t_1842557272_0  Enumerator_System_Collections_IDictionaryEnumerator_get_Entry_m_11418586_0_gshared (Enumerator_t_847843125_0 * __this, const MethodInfo* method);
#define Enumerator_System_Collections_IDictionaryEnumerator_get_Entry_m_11418586_0(__this, method) ((  DictionaryEntry_t_1842557272_0  (*) (Enumerator_t_847843125_0 *, const MethodInfo*))Enumerator_System_Collections_IDictionaryEnumerator_get_Entry_m_11418586_0_gshared)(__this, method)
// System.Object System.Collections.Generic.Dictionary`2/Enumerator<System.Object,System.Boolean>::System.Collections.IDictionaryEnumerator.get_Key()
extern "C"  Object_t * Enumerator_System_Collections_IDictionaryEnumerator_get_Key_m2023196417_0_gshared (Enumerator_t_847843125_0 * __this, const MethodInfo* method);
#define Enumerator_System_Collections_IDictionaryEnumerator_get_Key_m2023196417_0(__this, method) ((  Object_t * (*) (Enumerator_t_847843125_0 *, const MethodInfo*))Enumerator_System_Collections_IDictionaryEnumerator_get_Key_m2023196417_0_gshared)(__this, method)
// System.Object System.Collections.Generic.Dictionary`2/Enumerator<System.Object,System.Boolean>::System.Collections.IDictionaryEnumerator.get_Value()
extern "C"  Object_t * Enumerator_System_Collections_IDictionaryEnumerator_get_Value_m_279991981_0_gshared (Enumerator_t_847843125_0 * __this, const MethodInfo* method);
#define Enumerator_System_Collections_IDictionaryEnumerator_get_Value_m_279991981_0(__this, method) ((  Object_t * (*) (Enumerator_t_847843125_0 *, const MethodInfo*))Enumerator_System_Collections_IDictionaryEnumerator_get_Value_m_279991981_0_gshared)(__this, method)
// System.Boolean System.Collections.Generic.Dictionary`2/Enumerator<System.Object,System.Boolean>::MoveNext()
extern "C"  bool Enumerator_MoveNext_m1757195039_0_gshared (Enumerator_t_847843125_0 * __this, const MethodInfo* method);
#define Enumerator_MoveNext_m1757195039_0(__this, method) ((  bool (*) (Enumerator_t_847843125_0 *, const MethodInfo*))Enumerator_MoveNext_m1757195039_0_gshared)(__this, method)
// System.Collections.Generic.KeyValuePair`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator<System.Object,System.Boolean>::get_Current()
extern "C"  KeyValuePair_2_t_1968926924_0  Enumerator_get_Current_m_433949763_0_gshared (Enumerator_t_847843125_0 * __this, const MethodInfo* method);
#define Enumerator_get_Current_m_433949763_0(__this, method) ((  KeyValuePair_2_t_1968926924_0  (*) (Enumerator_t_847843125_0 *, const MethodInfo*))Enumerator_get_Current_m_433949763_0_gshared)(__this, method)
// TKey System.Collections.Generic.Dictionary`2/Enumerator<System.Object,System.Boolean>::get_CurrentKey()
extern "C"  Object_t * Enumerator_get_CurrentKey_m_2094029080_0_gshared (Enumerator_t_847843125_0 * __this, const MethodInfo* method);
#define Enumerator_get_CurrentKey_m_2094029080_0(__this, method) ((  Object_t * (*) (Enumerator_t_847843125_0 *, const MethodInfo*))Enumerator_get_CurrentKey_m_2094029080_0_gshared)(__this, method)
// TValue System.Collections.Generic.Dictionary`2/Enumerator<System.Object,System.Boolean>::get_CurrentValue()
extern "C"  bool Enumerator_get_CurrentValue_m2085087144_0_gshared (Enumerator_t_847843125_0 * __this, const MethodInfo* method);
#define Enumerator_get_CurrentValue_m2085087144_0(__this, method) ((  bool (*) (Enumerator_t_847843125_0 *, const MethodInfo*))Enumerator_get_CurrentValue_m2085087144_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2/Enumerator<System.Object,System.Boolean>::Reset()
extern "C"  void Enumerator_Reset_m963565784_0_gshared (Enumerator_t_847843125_0 * __this, const MethodInfo* method);
#define Enumerator_Reset_m963565784_0(__this, method) ((  void (*) (Enumerator_t_847843125_0 *, const MethodInfo*))Enumerator_Reset_m963565784_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2/Enumerator<System.Object,System.Boolean>::VerifyState()
extern "C"  void Enumerator_VerifyState_m88221409_0_gshared (Enumerator_t_847843125_0 * __this, const MethodInfo* method);
#define Enumerator_VerifyState_m88221409_0(__this, method) ((  void (*) (Enumerator_t_847843125_0 *, const MethodInfo*))Enumerator_VerifyState_m88221409_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2/Enumerator<System.Object,System.Boolean>::VerifyCurrent()
extern "C"  void Enumerator_VerifyCurrent_m1626299913_0_gshared (Enumerator_t_847843125_0 * __this, const MethodInfo* method);
#define Enumerator_VerifyCurrent_m1626299913_0(__this, method) ((  void (*) (Enumerator_t_847843125_0 *, const MethodInfo*))Enumerator_VerifyCurrent_m1626299913_0_gshared)(__this, method)
// System.Void System.Collections.Generic.Dictionary`2/Enumerator<System.Object,System.Boolean>::Dispose()
extern "C"  void Enumerator_Dispose_m797211560_0_gshared (Enumerator_t_847843125_0 * __this, const MethodInfo* method);
#define Enumerator_Dispose_m797211560_0(__this, method) ((  void (*) (Enumerator_t_847843125_0 *, const MethodInfo*))Enumerator_Dispose_m797211560_0_gshared)(__this, method)
