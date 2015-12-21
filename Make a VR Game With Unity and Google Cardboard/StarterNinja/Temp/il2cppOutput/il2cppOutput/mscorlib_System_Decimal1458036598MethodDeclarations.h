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

// System.Object
struct Object_t;
// System.Type
struct Type_t;
// System.IFormatProvider
struct IFormatProvider_t_1172917514_0;
// System.Int32[]
struct Int32U5BU5D_t1872284309_0;
// System.String
struct String_t;
// System.Globalization.NumberFormatInfo
struct NumberFormatInfo_t746228406_0;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Decimal1458036598.h"
#include "mscorlib_System_DateTime_818288618.h"
#include "mscorlib_System_Globalization_NumberStyles_1056602413.h"

// System.Void System.Decimal::.ctor(System.Int32,System.Int32,System.Int32,System.Boolean,System.Byte)
extern "C"  void Decimal__ctor_m_1781595023_0 (Decimal_t1458036598_0 * __this, int32_t ___lo, int32_t ___mid, int32_t ___hi, bool ___isNegative, uint8_t ___scale, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Decimal::.ctor(System.Int32)
extern "C"  void Decimal__ctor_m_1070459407_0 (Decimal_t1458036598_0 * __this, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Decimal::.ctor(System.UInt32)
extern "C"  void Decimal__ctor_m_2122242982_0 (Decimal_t1458036598_0 * __this, uint32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Decimal::.ctor(System.Int64)
extern "C"  void Decimal__ctor_m_1070456462_0 (Decimal_t1458036598_0 * __this, int64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Decimal::.ctor(System.UInt64)
extern "C"  void Decimal__ctor_m_2122240037_0 (Decimal_t1458036598_0 * __this, uint64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Decimal::.ctor(System.Single)
extern "C"  void Decimal__ctor_m1313518859_0 (Decimal_t1458036598_0 * __this, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Decimal::.ctor(System.Double)
extern "C"  void Decimal__ctor_m1063956130_0 (Decimal_t1458036598_0 * __this, double ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Decimal::.cctor()
extern "C"  void Decimal__cctor_m_1600811251_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Decimal::System.IConvertible.ToType(System.Type,System.IFormatProvider)
extern "C"  Object_t * Decimal_System_IConvertible_ToType_m_1120036260_0 (Decimal_t1458036598_0 * __this, Type_t * ___targetType, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Decimal::System.IConvertible.ToBoolean(System.IFormatProvider)
extern "C"  bool Decimal_System_IConvertible_ToBoolean_m632609316_0 (Decimal_t1458036598_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte System.Decimal::System.IConvertible.ToByte(System.IFormatProvider)
extern "C"  uint8_t Decimal_System_IConvertible_ToByte_m852949524_0 (Decimal_t1458036598_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Char System.Decimal::System.IConvertible.ToChar(System.IFormatProvider)
extern "C"  uint16_t Decimal_System_IConvertible_ToChar_m224793940_0 (Decimal_t1458036598_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.DateTime System.Decimal::System.IConvertible.ToDateTime(System.IFormatProvider)
extern "C"  DateTime_t_818288618_0  Decimal_System_IConvertible_ToDateTime_m126860468_0 (Decimal_t1458036598_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::System.IConvertible.ToDecimal(System.IFormatProvider)
extern "C"  Decimal_t1458036598_0  Decimal_System_IConvertible_ToDecimal_m1811804854_0 (Decimal_t1458036598_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Double System.Decimal::System.IConvertible.ToDouble(System.IFormatProvider)
extern "C"  double Decimal_System_IConvertible_ToDouble_m_1803721676_0 (Decimal_t1458036598_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int16 System.Decimal::System.IConvertible.ToInt16(System.IFormatProvider)
extern "C"  int16_t Decimal_System_IConvertible_ToInt16_m_1610868484_0 (Decimal_t1458036598_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Decimal::System.IConvertible.ToInt32(System.IFormatProvider)
extern "C"  int32_t Decimal_System_IConvertible_ToInt32_m1063784048_0 (Decimal_t1458036598_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.Decimal::System.IConvertible.ToInt64(System.IFormatProvider)
extern "C"  int64_t Decimal_System_IConvertible_ToInt64_m_627514706_0 (Decimal_t1458036598_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.SByte System.Decimal::System.IConvertible.ToSByte(System.IFormatProvider)
extern "C"  int8_t Decimal_System_IConvertible_ToSByte_m_1162933238_0 (Decimal_t1458036598_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single System.Decimal::System.IConvertible.ToSingle(System.IFormatProvider)
extern "C"  float Decimal_System_IConvertible_ToSingle_m_1303701100_0 (Decimal_t1458036598_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt16 System.Decimal::System.IConvertible.ToUInt16(System.IFormatProvider)
extern "C"  uint16_t Decimal_System_IConvertible_ToUInt16_m_1416248588_0 (Decimal_t1458036598_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt32 System.Decimal::System.IConvertible.ToUInt32(System.IFormatProvider)
extern "C"  uint32_t Decimal_System_IConvertible_ToUInt32_m_2124605132_0 (Decimal_t1458036598_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt64 System.Decimal::System.IConvertible.ToUInt64(System.IFormatProvider)
extern "C"  uint64_t Decimal_System_IConvertible_ToUInt64_m_1433565292_0 (Decimal_t1458036598_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32[] System.Decimal::GetBits(System.Decimal)
extern "C"  Int32U5BU5D_t1872284309_0* Decimal_GetBits_m_1159226386_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___d, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::Add(System.Decimal,System.Decimal)
extern "C"  Decimal_t1458036598_0  Decimal_Add_m228744192_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___d1, Decimal_t1458036598_0  ___d2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::Subtract(System.Decimal,System.Decimal)
extern "C"  Decimal_t1458036598_0  Decimal_Subtract_m_256321291_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___d1, Decimal_t1458036598_0  ___d2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Decimal::GetHashCode()
extern "C"  int32_t Decimal_GetHashCode_m_569317709_0 (Decimal_t1458036598_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt64 System.Decimal::u64(System.Decimal)
extern "C"  uint64_t Decimal_u64_m_1502701277_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.Decimal::s64(System.Decimal)
extern "C"  int64_t Decimal_s64_m_1885038656_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Decimal::Equals(System.Decimal,System.Decimal)
extern "C"  bool Decimal_Equals_m1154754945_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___d1, Decimal_t1458036598_0  ___d2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Decimal::Equals(System.Object)
extern "C"  bool Decimal_Equals_m_880792369_0 (Decimal_t1458036598_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Decimal::IsZero()
extern "C"  bool Decimal_IsZero_m379800408_0 (Decimal_t1458036598_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::Floor(System.Decimal)
extern "C"  Decimal_t1458036598_0  Decimal_Floor_m_1708094625_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___d, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::Multiply(System.Decimal,System.Decimal)
extern "C"  Decimal_t1458036598_0  Decimal_Multiply_m201714661_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___d1, Decimal_t1458036598_0  ___d2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::Divide(System.Decimal,System.Decimal)
extern "C"  Decimal_t1458036598_0  Decimal_Divide_m555230192_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___d1, Decimal_t1458036598_0  ___d2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Decimal::Compare(System.Decimal,System.Decimal)
extern "C"  int32_t Decimal_Compare_m_1968560097_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___d1, Decimal_t1458036598_0  ___d2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Decimal::CompareTo(System.Object)
extern "C"  int32_t Decimal_CompareTo_m_1743532814_0 (Decimal_t1458036598_0 * __this, Object_t * ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Decimal::CompareTo(System.Decimal)
extern "C"  int32_t Decimal_CompareTo_m_2034871344_0 (Decimal_t1458036598_0 * __this, Decimal_t1458036598_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Decimal::Equals(System.Decimal)
extern "C"  bool Decimal_Equals_m_1059721325_0 (Decimal_t1458036598_0 * __this, Decimal_t1458036598_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::Parse(System.String,System.IFormatProvider)
extern "C"  Decimal_t1458036598_0  Decimal_Parse_m_508716470_0 (Object_t * __this /* static, unused */, String_t* ___s, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Decimal::ThrowAtPos(System.Int32)
extern "C"  void Decimal_ThrowAtPos_m_1796780976_0 (Object_t * __this /* static, unused */, int32_t ___pos, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Decimal::ThrowInvalidExp()
extern "C"  void Decimal_ThrowInvalidExp_m_1412057430_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Decimal::stripStyles(System.String,System.Globalization.NumberStyles,System.Globalization.NumberFormatInfo,System.Int32&,System.Boolean&,System.Boolean&,System.Int32&,System.Boolean)
extern "C"  String_t* Decimal_stripStyles_m1011490529_0 (Object_t * __this /* static, unused */, String_t* ___s, int32_t ___style, NumberFormatInfo_t746228406_0 * ___nfi, int32_t* ___decPos, bool* ___isNegative, bool* ___expFlag, int32_t* ___exp, bool ___throwex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::Parse(System.String,System.Globalization.NumberStyles,System.IFormatProvider)
extern "C"  Decimal_t1458036598_0  Decimal_Parse_m2075137301_0 (Object_t * __this /* static, unused */, String_t* ___s, int32_t ___style, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Decimal::PerformParse(System.String,System.Globalization.NumberStyles,System.IFormatProvider,System.Decimal&,System.Boolean)
extern "C"  bool Decimal_PerformParse_m_2043233776_0 (Object_t * __this /* static, unused */, String_t* ___s, int32_t ___style, Object_t * ___provider, Decimal_t1458036598_0 * ___res, bool ___throwex, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Decimal::ToString(System.String,System.IFormatProvider)
extern "C"  String_t* Decimal_ToString_m_752493851_0 (Decimal_t1458036598_0 * __this, String_t* ___format, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Decimal::ToString()
extern "C"  String_t* Decimal_ToString_m143310003_0 (Decimal_t1458036598_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Decimal::ToString(System.IFormatProvider)
extern "C"  String_t* Decimal_ToString_m1778338145_0 (Decimal_t1458036598_0 * __this, Object_t * ___provider, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Decimal::decimal2UInt64(System.Decimal&,System.UInt64&)
extern "C"  int32_t Decimal_decimal2UInt64_m_330303086_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0 * ___val, uint64_t* ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Decimal::decimal2Int64(System.Decimal&,System.Int64&)
extern "C"  int32_t Decimal_decimal2Int64_m_261750748_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0 * ___val, int64_t* ___result, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Decimal::decimalIncr(System.Decimal&,System.Decimal&)
extern "C"  int32_t Decimal_decimalIncr_m877616783_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0 * ___d1, Decimal_t1458036598_0 * ___d2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Decimal::string2decimal(System.Decimal&,System.String,System.UInt32,System.Int32)
extern "C"  int32_t Decimal_string2decimal_m_676736039_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0 * ___val, String_t* ___sDigits, uint32_t ___decPos, int32_t ___sign, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Decimal::decimalSetExponent(System.Decimal&,System.Int32)
extern "C"  int32_t Decimal_decimalSetExponent_m618812921_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0 * ___val, int32_t ___exp, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Double System.Decimal::decimal2double(System.Decimal&)
extern "C"  double Decimal_decimal2double_m128837253_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0 * ___val, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Decimal::decimalFloorAndTrunc(System.Decimal&,System.Int32)
extern "C"  void Decimal_decimalFloorAndTrunc_m1954139757_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0 * ___val, int32_t ___floorFlag, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Decimal::decimalMult(System.Decimal&,System.Decimal&)
extern "C"  int32_t Decimal_decimalMult_m_930644685_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0 * ___pd1, Decimal_t1458036598_0 * ___pd2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Decimal::decimalDiv(System.Decimal&,System.Decimal&,System.Decimal&)
extern "C"  int32_t Decimal_decimalDiv_m_439567378_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0 * ___pc, Decimal_t1458036598_0 * ___pa, Decimal_t1458036598_0 * ___pb, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Decimal::decimalCompare(System.Decimal&,System.Decimal&)
extern "C"  int32_t Decimal_decimalCompare_m57377858_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0 * ___d1, Decimal_t1458036598_0 * ___d2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::op_Increment(System.Decimal)
extern "C"  Decimal_t1458036598_0  Decimal_op_Increment_m1999568348_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___d, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::op_Subtraction(System.Decimal,System.Decimal)
extern "C"  Decimal_t1458036598_0  Decimal_op_Subtraction_m1143274995_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___d1, Decimal_t1458036598_0  ___d2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::op_Multiply(System.Decimal,System.Decimal)
extern "C"  Decimal_t1458036598_0  Decimal_op_Multiply_m_830367361_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___d1, Decimal_t1458036598_0  ___d2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::op_Division(System.Decimal,System.Decimal)
extern "C"  Decimal_t1458036598_0  Decimal_op_Division_m_344064554_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___d1, Decimal_t1458036598_0  ___d2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Byte System.Decimal::op_Explicit(System.Decimal)
extern "C"  uint8_t Decimal_op_Explicit_m444543858_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.SByte System.Decimal::op_Explicit(System.Decimal)
extern "C"  int8_t Decimal_op_Explicit_m_1225747857_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int16 System.Decimal::op_Explicit(System.Decimal)
extern "C"  int16_t Decimal_op_Explicit_m1899223848_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt16 System.Decimal::op_Explicit(System.Decimal)
extern "C"  uint16_t Decimal_op_Explicit_m1178707977_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Decimal::op_Explicit(System.Decimal)
extern "C"  int32_t Decimal_op_Explicit_m2040523874_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt32 System.Decimal::op_Explicit(System.Decimal)
extern "C"  uint32_t Decimal_op_Explicit_m1320008003_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int64 System.Decimal::op_Explicit(System.Decimal)
extern "C"  int64_t Decimal_op_Explicit_m_616031679_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt64 System.Decimal::op_Explicit(System.Decimal)
extern "C"  uint64_t Decimal_op_Explicit_m_1336547550_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::op_Implicit(System.Byte)
extern "C"  Decimal_t1458036598_0  Decimal_op_Implicit_m394719939_0 (Object_t * __this /* static, unused */, uint8_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::op_Implicit(System.SByte)
extern "C"  Decimal_t1458036598_0  Decimal_op_Implicit_m_212516596_0 (Object_t * __this /* static, unused */, int8_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::op_Implicit(System.Int16)
extern "C"  Decimal_t1458036598_0  Decimal_op_Implicit_m_458387981_0 (Object_t * __this /* static, unused */, int16_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::op_Implicit(System.UInt16)
extern "C"  Decimal_t1458036598_0  Decimal_op_Implicit_m_327844020_0 (Object_t * __this /* static, unused */, uint16_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::op_Implicit(System.Int32)
extern "C"  Decimal_t1458036598_0  Decimal_op_Implicit_m_458386183_0 (Object_t * __this /* static, unused */, int32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::op_Implicit(System.UInt32)
extern "C"  Decimal_t1458036598_0  Decimal_op_Implicit_m_327842222_0 (Object_t * __this /* static, unused */, uint32_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::op_Implicit(System.Int64)
extern "C"  Decimal_t1458036598_0  Decimal_op_Implicit_m_458383238_0 (Object_t * __this /* static, unused */, int64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::op_Implicit(System.UInt64)
extern "C"  Decimal_t1458036598_0  Decimal_op_Implicit_m_327839277_0 (Object_t * __this /* static, unused */, uint64_t ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::op_Explicit(System.Single)
extern "C"  Decimal_t1458036598_0  Decimal_op_Explicit_m1480046292_0 (Object_t * __this /* static, unused */, float ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Decimal System.Decimal::op_Explicit(System.Double)
extern "C"  Decimal_t1458036598_0  Decimal_op_Explicit_m1230483563_0 (Object_t * __this /* static, unused */, double ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single System.Decimal::op_Explicit(System.Decimal)
extern "C"  float Decimal_op_Explicit_m2130641906_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Double System.Decimal::op_Explicit(System.Decimal)
extern "C"  double Decimal_op_Explicit_m_1670409733_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___value, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Decimal::op_Inequality(System.Decimal,System.Decimal)
extern "C"  bool Decimal_op_Inequality_m_25648595_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___d1, Decimal_t1458036598_0  ___d2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Decimal::op_Equality(System.Decimal,System.Decimal)
extern "C"  bool Decimal_op_Equality_m_281484110_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___d1, Decimal_t1458036598_0  ___d2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Decimal::op_GreaterThan(System.Decimal,System.Decimal)
extern "C"  bool Decimal_op_GreaterThan_m_2060536989_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___d1, Decimal_t1458036598_0  ___d2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Decimal::op_LessThan(System.Decimal,System.Decimal)
extern "C"  bool Decimal_op_LessThan_m_788844846_0 (Object_t * __this /* static, unused */, Decimal_t1458036598_0  ___d1, Decimal_t1458036598_0  ___d2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
