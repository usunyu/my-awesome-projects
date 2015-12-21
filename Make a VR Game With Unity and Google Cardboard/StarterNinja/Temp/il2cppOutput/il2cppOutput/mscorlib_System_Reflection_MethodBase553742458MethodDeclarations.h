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

// System.Reflection.MethodBase
struct MethodBase_t553742458_0;
// System.Object
struct Object_t;
// System.Object[]
struct ObjectU5BU5D_t1774424924_0;
// System.Type[]
struct TypeU5BU5D_t_722972841_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_RuntimeMethodHandle_762307834.h"
#include "mscorlib_System_IntPtr_1047952454.h"
#include "mscorlib_System_Reflection_CallingConventions732533990.h"

// System.Void System.Reflection.MethodBase::.ctor()
extern "C"  void MethodBase__ctor_m_1425230116_0 (MethodBase_t553742458_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodBase System.Reflection.MethodBase::GetMethodFromHandleNoGenericCheck(System.RuntimeMethodHandle)
extern "C"  MethodBase_t553742458_0 * MethodBase_GetMethodFromHandleNoGenericCheck_m_437034722_0 (Object_t * __this /* static, unused */, RuntimeMethodHandle_t_762307834_0  ___handle, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodBase System.Reflection.MethodBase::GetMethodFromIntPtr(System.IntPtr,System.IntPtr)
extern "C"  MethodBase_t553742458_0 * MethodBase_GetMethodFromIntPtr_m1804781085_0 (Object_t * __this /* static, unused */, IntPtr_t ___handle, IntPtr_t ___declaringType, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodBase System.Reflection.MethodBase::GetMethodFromHandle(System.RuntimeMethodHandle)
extern "C"  MethodBase_t553742458_0 * MethodBase_GetMethodFromHandle_m_746619668_0 (Object_t * __this /* static, unused */, RuntimeMethodHandle_t_762307834_0  ___handle, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.MethodBase System.Reflection.MethodBase::GetMethodFromHandleInternalType(System.IntPtr,System.IntPtr)
extern "C"  MethodBase_t553742458_0 * MethodBase_GetMethodFromHandleInternalType_m1518673981_0 (Object_t * __this /* static, unused */, IntPtr_t ___method_handle, IntPtr_t ___type_handle, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Reflection.MethodBase::GetParameterCount()
extern "C"  int32_t MethodBase_GetParameterCount_m_924953926_0 (MethodBase_t553742458_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Reflection.MethodBase::Invoke(System.Object,System.Object[])
extern "C"  Object_t * MethodBase_Invoke_m_859801141_0 (MethodBase_t553742458_0 * __this, Object_t * ___obj, ObjectU5BU5D_t1774424924_0* ___parameters, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Reflection.CallingConventions System.Reflection.MethodBase::get_CallingConvention()
extern "C"  int32_t MethodBase_get_CallingConvention_m1001031613_0 (MethodBase_t553742458_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.MethodBase::get_IsPublic()
extern "C"  bool MethodBase_get_IsPublic_m_205807642_0 (MethodBase_t553742458_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.MethodBase::get_IsStatic()
extern "C"  bool MethodBase_get_IsStatic_m_181088597_0 (MethodBase_t553742458_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.MethodBase::get_IsVirtual()
extern "C"  bool MethodBase_get_IsVirtual_m2071496208_0 (MethodBase_t553742458_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.MethodBase::get_IsAbstract()
extern "C"  bool MethodBase_get_IsAbstract_m1047696479_0 (MethodBase_t553742458_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Reflection.MethodBase::get_next_table_index(System.Object,System.Int32,System.Boolean)
extern "C"  int32_t MethodBase_get_next_table_index_m1161386136_0 (MethodBase_t553742458_0 * __this, Object_t * ___obj, int32_t ___table, bool ___inc, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Type[] System.Reflection.MethodBase::GetGenericArguments()
extern "C"  TypeU5BU5D_t_722972841_0* MethodBase_GetGenericArguments_m_1158369417_0 (MethodBase_t553742458_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.MethodBase::get_ContainsGenericParameters()
extern "C"  bool MethodBase_get_ContainsGenericParameters_m30026257_0 (MethodBase_t553742458_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.MethodBase::get_IsGenericMethodDefinition()
extern "C"  bool MethodBase_get_IsGenericMethodDefinition_m_714040304_0 (MethodBase_t553742458_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Reflection.MethodBase::get_IsGenericMethod()
extern "C"  bool MethodBase_get_IsGenericMethod_m_1129374115_0 (MethodBase_t553742458_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
