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

// System.Collections.CaseInsensitiveHashCodeProvider
struct CaseInsensitiveHashCodeProvider_t69752889_0;
// System.Globalization.CultureInfo
struct CultureInfo_t_1039475404_0;
// System.Globalization.TextInfo
struct TextInfo_t_2130369341_0;
// System.Object
struct Object_t;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Collections.CaseInsensitiveHashCodeProvider::.ctor()
extern "C"  void CaseInsensitiveHashCodeProvider__ctor_m1687836093_0 (CaseInsensitiveHashCodeProvider_t69752889_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.CaseInsensitiveHashCodeProvider::.ctor(System.Globalization.CultureInfo)
extern "C"  void CaseInsensitiveHashCodeProvider__ctor_m_1819416979_0 (CaseInsensitiveHashCodeProvider_t69752889_0 * __this, CultureInfo_t_1039475404_0 * ___culture, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Collections.CaseInsensitiveHashCodeProvider::.cctor()
extern "C"  void CaseInsensitiveHashCodeProvider__cctor_m301215120_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.CaseInsensitiveHashCodeProvider::AreEqual(System.Globalization.CultureInfo,System.Globalization.CultureInfo)
extern "C"  bool CaseInsensitiveHashCodeProvider_AreEqual_m2045397501_0 (Object_t * __this /* static, unused */, CultureInfo_t_1039475404_0 * ___a, CultureInfo_t_1039475404_0 * ___b, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Collections.CaseInsensitiveHashCodeProvider::AreEqual(System.Globalization.TextInfo,System.Globalization.CultureInfo)
extern "C"  bool CaseInsensitiveHashCodeProvider_AreEqual_m_641749996_0 (Object_t * __this /* static, unused */, TextInfo_t_2130369341_0 * ___info, CultureInfo_t_1039475404_0 * ___culture, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.CaseInsensitiveHashCodeProvider System.Collections.CaseInsensitiveHashCodeProvider::get_DefaultInvariant()
extern "C"  CaseInsensitiveHashCodeProvider_t69752889_0 * CaseInsensitiveHashCodeProvider_get_DefaultInvariant_m1403540293_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Collections.CaseInsensitiveHashCodeProvider::GetHashCode(System.Object)
extern "C"  int32_t CaseInsensitiveHashCodeProvider_GetHashCode_m517823364_0 (CaseInsensitiveHashCodeProvider_t69752889_0 * __this, Object_t * ___obj, const MethodInfo* method) IL2CPP_METHOD_ATTR;
