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

// System.Net.HttpRequestCreator
struct HttpRequestCreator_t_1770471941_0;
// System.Net.WebRequest
struct WebRequest_t442478417_0;
// System.Uri
struct Uri_t18014439_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Net.HttpRequestCreator::.ctor()
extern "C"  void HttpRequestCreator__ctor_m_1959378763_0 (HttpRequestCreator_t_1770471941_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Net.WebRequest System.Net.HttpRequestCreator::Create(System.Uri)
extern "C"  WebRequest_t442478417_0 * HttpRequestCreator_Create_m_926311882_0 (HttpRequestCreator_t_1770471941_0 * __this, Uri_t18014439_0 * ___uri, const MethodInfo* method) IL2CPP_METHOD_ATTR;
