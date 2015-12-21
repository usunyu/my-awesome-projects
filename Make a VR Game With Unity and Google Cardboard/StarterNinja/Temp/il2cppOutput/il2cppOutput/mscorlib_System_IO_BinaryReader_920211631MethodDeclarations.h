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

// System.IO.BinaryReader
struct BinaryReader_t_920211631_0;
// System.IO.Stream
struct Stream_t463444077_0;
// System.Text.Encoding
struct Encoding_t453909881_0;
// System.Byte[]
struct ByteU5BU5D_t_1238178395_0;
// System.Char[]
struct CharU5BU5D_t_1225802637_0;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Decimal1458036598.h"

// System.Void System.IO.BinaryReader::.ctor(System.IO.Stream)
extern "C"  void BinaryReader__ctor_m449904828_0 (BinaryReader_t_920211631_0 * __this, Stream_t463444077_0 * ___input, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.BinaryReader::.ctor(System.IO.Stream,System.Text.Encoding)
extern "C"  void BinaryReader__ctor_m_372909099_0 (BinaryReader_t_920211631_0 * __this, Stream_t463444077_0 * ___input, Encoding_t453909881_0 * ___encoding, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.BinaryReader::System.IDisposable.Dispose()
extern "C"  void BinaryReader_System_IDisposable_Dispose_m_1545558886_0 (BinaryReader_t_920211631_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.IO.Stream System.IO.BinaryReader::get_BaseStream()
extern "C"  Stream_t463444077_0 * BinaryReader_get_BaseStream_m_1392565349_0 (BinaryReader_t_920211631_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.BinaryReader::Close()
extern "C"  void BinaryReader_Close_m52775227_0 (BinaryReader_t_920211631_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.BinaryReader::Dispose(System.Boolean)
extern "C"  void BinaryReader_Dispose_m2135076121_0 (BinaryReader_t_920211631_0 * __this, bool ___disposing, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.BinaryReader::FillBuffer(System.Int32)
extern "C"  void BinaryReader_FillBuffer_m_565676237_0 (BinaryReader_t_920211631_0 * __this, int32_t ___numBytes, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.BinaryReader::Read()
extern "C"  int32_t BinaryReader_Read_m_1798488143_0 (BinaryReader_t_920211631_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.BinaryReader::Read(System.Byte[],System.Int32,System.Int32)
extern "C"  int32_t BinaryReader_Read_m_1014061288_0 (BinaryReader_t_920211631_0 * __this, ByteU5BU5D_t_1238178395_0* ___buffer, int32_t ___index, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.BinaryReader::Read(System.Char[],System.Int32,System.Int32)
extern "C"  int32_t BinaryReader_Read_m_1313865846_0 (BinaryReader_t_920211631_0 * __this, CharU5BU5D_t_1225802637_0* ___buffer, int32_t ___index, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.BinaryReader::ReadCharBytes(System.Char[],System.Int32,System.Int32,System.Int32&)
extern "C"  int32_t BinaryReader_ReadCharBytes_m1651708170_0 (BinaryReader_t_920211631_0 * __this, CharU5BU5D_t_1225802637_0* ___buffer, int32_t ___index, int32_t ___count, int32_t* ___bytes_read, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.BinaryReader::Read7BitEncodedInt()
extern "C"  int32_t BinaryReader_Read7BitEncodedInt_m1880666088_0 (BinaryReader_t_920211631_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.IO.BinaryReader::ReadBoolean()
extern "C"  bool BinaryReader_ReadBoolean_m1888598835_0 (BinaryReader_t_920211631_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte System.IO.BinaryReader::ReadByte()
extern "C"  uint8_t BinaryReader_ReadByte_m_1189013047_0 (BinaryReader_t_920211631_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte[] System.IO.BinaryReader::ReadBytes(System.Int32)
extern "C"  ByteU5BU5D_t_1238178395_0* BinaryReader_ReadBytes_m_1045514529_0 (BinaryReader_t_920211631_0 * __this, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Char System.IO.BinaryReader::ReadChar()
extern "C"  uint16_t BinaryReader_ReadChar_m2116266889_0 (BinaryReader_t_920211631_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.IO.BinaryReader::ReadDecimal()
extern "C"  Decimal_t1458036598_0  BinaryReader_ReadDecimal_m_1600504699_0 (BinaryReader_t_920211631_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Double System.IO.BinaryReader::ReadDouble()
extern "C"  double BinaryReader_ReadDouble_m_1820905495_0 (BinaryReader_t_920211631_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int16 System.IO.BinaryReader::ReadInt16()
extern "C"  int16_t BinaryReader_ReadInt16_m_326386101_0 (BinaryReader_t_920211631_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.IO.BinaryReader::ReadInt32()
extern "C"  int32_t BinaryReader_ReadInt32_m1620214591_0 (BinaryReader_t_920211631_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.IO.BinaryReader::ReadInt64()
extern "C"  int64_t BinaryReader_ReadInt64_m_1411685187_0 (BinaryReader_t_920211631_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.SByte System.IO.BinaryReader::ReadSByte()
extern "C"  int8_t BinaryReader_ReadSByte_m963271833_0 (BinaryReader_t_920211631_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.IO.BinaryReader::ReadString()
extern "C"  String_t* BinaryReader_ReadString_m1372899305_0 (BinaryReader_t_920211631_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single System.IO.BinaryReader::ReadSingle()
extern "C"  float BinaryReader_ReadSingle_m2118302857_0 (BinaryReader_t_920211631_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt16 System.IO.BinaryReader::ReadUInt16()
extern "C"  uint16_t BinaryReader_ReadUInt16_m_891874007_0 (BinaryReader_t_920211631_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt32 System.IO.BinaryReader::ReadUInt32()
extern "C"  uint32_t BinaryReader_ReadUInt32_m_678466839_0 (BinaryReader_t_920211631_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt64 System.IO.BinaryReader::ReadUInt64()
extern "C"  uint64_t BinaryReader_ReadUInt64_m_180818295_0 (BinaryReader_t_920211631_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.IO.BinaryReader::CheckBuffer(System.Int32)
extern "C"  void BinaryReader_CheckBuffer_m244572668_0 (BinaryReader_t_920211631_0 * __this, int32_t ___length, const MethodInfo* method) IL2CPP_METHOD_ATTR;
