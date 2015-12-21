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

// System.Net.DefaultCertificatePolicy
struct DefaultCertificatePolicy_t_51627618_0;
// System.Net.ServicePoint
struct ServicePoint_t_1625863919_0;
// System.Security.Cryptography.X509Certificates.X509Certificate
struct X509Certificate_t1524084820_0;
// System.Net.WebRequest
struct WebRequest_t442478417_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Net.DefaultCertificatePolicy::.ctor()
extern "C"  void DefaultCertificatePolicy__ctor_m_46047566_0 (DefaultCertificatePolicy_t_51627618_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Net.DefaultCertificatePolicy::CheckValidationResult(System.Net.ServicePoint,System.Security.Cryptography.X509Certificates.X509Certificate,System.Net.WebRequest,System.Int32)
extern "C"  bool DefaultCertificatePolicy_CheckValidationResult_m_170940833_0 (DefaultCertificatePolicy_t_51627618_0 * __this, ServicePoint_t_1625863919_0 * ___point, X509Certificate_t1524084820_0 * ___certificate, WebRequest_t442478417_0 * ___request, int32_t ___certificateProblem, const MethodInfo* method) IL2CPP_METHOD_ATTR;
