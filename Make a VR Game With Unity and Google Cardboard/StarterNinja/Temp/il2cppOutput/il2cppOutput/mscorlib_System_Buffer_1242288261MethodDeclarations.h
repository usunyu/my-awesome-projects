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

// System.Array
struct Array_t;

#include "codegen/il2cpp-codegen.h"

// System.Int32 System.Buffer::ByteLength(System.Array)
extern "C"  int32_t Buffer_ByteLength_m_595765177_0 (Object_t * __this /* static, unused */, Array_t * ___array, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Buffer::BlockCopy(System.Array,System.Int32,System.Array,System.Int32,System.Int32)
extern "C"  void Buffer_BlockCopy_m1580643184_0 (Object_t * __this /* static, unused */, Array_t * ___src, int32_t ___srcOffset, Array_t * ___dst, int32_t ___dstOffset, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Buffer::ByteLengthInternal(System.Array)
extern "C"  int32_t Buffer_ByteLengthInternal_m22076516_0 (Object_t * __this /* static, unused */, Array_t * ___array, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Buffer::BlockCopyInternal(System.Array,System.Int32,System.Array,System.Int32,System.Int32)
extern "C"  bool Buffer_BlockCopyInternal_m1988595087_0 (Object_t * __this /* static, unused */, Array_t * ___src, int32_t ___src_offset, Array_t * ___dest, int32_t ___dest_offset, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
