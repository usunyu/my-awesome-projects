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

// System.Resources.ResourceReader/ResourceEnumerator
struct ResourceEnumerator_t1878955756_0;
// System.Resources.ResourceReader
struct ResourceReader_t_1480646667_0;
// System.Object
struct Object_t;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Collections_DictionaryEntry_1842557272.h"

// System.Void System.Resources.ResourceReader/ResourceEnumerator::.ctor(System.Resources.ResourceReader)
extern "C"  void ResourceEnumerator__ctor_m_300772721_0 (ResourceEnumerator_t1878955756_0 * __this, ResourceReader_t_1480646667_0 * ___readerToEnumerate, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.DictionaryEntry System.Resources.ResourceReader/ResourceEnumerator::get_Entry()
extern "C"  DictionaryEntry_t_1842557272_0  ResourceEnumerator_get_Entry_m715318570_0 (ResourceEnumerator_t1878955756_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Resources.ResourceReader/ResourceEnumerator::get_Key()
extern "C"  Object_t * ResourceEnumerator_get_Key_m424542697_0 (ResourceEnumerator_t1878955756_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Resources.ResourceReader/ResourceEnumerator::get_Value()
extern "C"  Object_t * ResourceEnumerator_get_Value_m1012075067_0 (ResourceEnumerator_t1878955756_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Resources.ResourceReader/ResourceEnumerator::get_Current()
extern "C"  Object_t * ResourceEnumerator_get_Current_m_928745981_0 (ResourceEnumerator_t1878955756_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Resources.ResourceReader/ResourceEnumerator::MoveNext()
extern "C"  bool ResourceEnumerator_MoveNext_m_378659840_0 (ResourceEnumerator_t1878955756_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Resources.ResourceReader/ResourceEnumerator::Reset()
extern "C"  void ResourceEnumerator_Reset_m_168076521_0 (ResourceEnumerator_t1878955756_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Resources.ResourceReader/ResourceEnumerator::FillCache()
extern "C"  void ResourceEnumerator_FillCache_m1751484935_0 (ResourceEnumerator_t1878955756_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
