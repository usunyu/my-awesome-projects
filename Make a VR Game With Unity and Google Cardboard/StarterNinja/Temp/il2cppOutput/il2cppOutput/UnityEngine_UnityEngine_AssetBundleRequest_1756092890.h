#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.AssetBundle
struct AssetBundle_t1143280681_0;
// System.String
struct String_t;
// System.Type
struct Type_t;

#include "UnityEngine_UnityEngine_AsyncOperation59089492.h"

// UnityEngine.AssetBundleRequest
struct  AssetBundleRequest_t_1756092890_0  : public AsyncOperation_t59089492_0
{
	// UnityEngine.AssetBundle UnityEngine.AssetBundleRequest::m_AssetBundle
	AssetBundle_t1143280681_0 * ___m_AssetBundle_1;
	// System.String UnityEngine.AssetBundleRequest::m_Path
	String_t* ___m_Path_2;
	// System.Type UnityEngine.AssetBundleRequest::m_Type
	Type_t * ___m_Type_3;
};
