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

// System.Text.RegularExpressions.PatternCompiler
struct PatternCompiler_t_983530916_0;
// System.Text.RegularExpressions.IMachineFactory
struct IMachineFactory_t_629363303_0;
// System.Collections.BitArray
struct BitArray_t588948896_0;
// System.String
struct String_t;
// System.Text.RegularExpressions.LinkRef
struct LinkRef_t_201520826_0;

#include "codegen/il2cpp-codegen.h"
#include "System_System_Text_RegularExpressions_OpCode_885256511.h"
#include "System_System_Text_RegularExpressions_OpFlags_1670469581.h"
#include "System_System_Text_RegularExpressions_Category1199172497.h"
#include "System_System_Text_RegularExpressions_Position1896466364.h"

// System.Void System.Text.RegularExpressions.PatternCompiler::.ctor()
extern "C"  void PatternCompiler__ctor_m640185722_0 (PatternCompiler_t_983530916_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt16 System.Text.RegularExpressions.PatternCompiler::EncodeOp(System.Text.RegularExpressions.OpCode,System.Text.RegularExpressions.OpFlags)
extern "C"  uint16_t PatternCompiler_EncodeOp_m_856712148_0 (Object_t * __this /* static, unused */, uint16_t ___op, uint16_t ___flags, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.RegularExpressions.IMachineFactory System.Text.RegularExpressions.PatternCompiler::GetMachineFactory()
extern "C"  Object_t * PatternCompiler_GetMachineFactory_m1519739313_0 (PatternCompiler_t_983530916_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitFalse()
extern "C"  void PatternCompiler_EmitFalse_m722778152_0 (PatternCompiler_t_983530916_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitTrue()
extern "C"  void PatternCompiler_EmitTrue_m_1638133813_0 (PatternCompiler_t_983530916_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitCount(System.Int32)
extern "C"  void PatternCompiler_EmitCount_m_1111663515_0 (PatternCompiler_t_983530916_0 * __this, int32_t ___count, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitCharacter(System.Char,System.Boolean,System.Boolean,System.Boolean)
extern "C"  void PatternCompiler_EmitCharacter_m_983670258_0 (PatternCompiler_t_983530916_0 * __this, uint16_t ___c, bool ___negate, bool ___ignore, bool ___reverse, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitCategory(System.Text.RegularExpressions.Category,System.Boolean,System.Boolean)
extern "C"  void PatternCompiler_EmitCategory_m_1848102772_0 (PatternCompiler_t_983530916_0 * __this, uint16_t ___cat, bool ___negate, bool ___reverse, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitNotCategory(System.Text.RegularExpressions.Category,System.Boolean,System.Boolean)
extern "C"  void PatternCompiler_EmitNotCategory_m_319985359_0 (PatternCompiler_t_983530916_0 * __this, uint16_t ___cat, bool ___negate, bool ___reverse, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitRange(System.Char,System.Char,System.Boolean,System.Boolean,System.Boolean)
extern "C"  void PatternCompiler_EmitRange_m_1082737557_0 (PatternCompiler_t_983530916_0 * __this, uint16_t ___lo, uint16_t ___hi, bool ___negate, bool ___ignore, bool ___reverse, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitSet(System.Char,System.Collections.BitArray,System.Boolean,System.Boolean,System.Boolean)
extern "C"  void PatternCompiler_EmitSet_m_1398979361_0 (PatternCompiler_t_983530916_0 * __this, uint16_t ___lo, BitArray_t588948896_0 * ___set, bool ___negate, bool ___ignore, bool ___reverse, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitString(System.String,System.Boolean,System.Boolean)
extern "C"  void PatternCompiler_EmitString_m_1981451628_0 (PatternCompiler_t_983530916_0 * __this, String_t* ___str, bool ___ignore, bool ___reverse, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitPosition(System.Text.RegularExpressions.Position)
extern "C"  void PatternCompiler_EmitPosition_m_1105966954_0 (PatternCompiler_t_983530916_0 * __this, uint16_t ___pos, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitOpen(System.Int32)
extern "C"  void PatternCompiler_EmitOpen_m1906123864_0 (PatternCompiler_t_983530916_0 * __this, int32_t ___gid, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitClose(System.Int32)
extern "C"  void PatternCompiler_EmitClose_m_1341481586_0 (PatternCompiler_t_983530916_0 * __this, int32_t ___gid, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitBalanceStart(System.Int32,System.Int32,System.Boolean,System.Text.RegularExpressions.LinkRef)
extern "C"  void PatternCompiler_EmitBalanceStart_m153593536_0 (PatternCompiler_t_983530916_0 * __this, int32_t ___gid, int32_t ___balance, bool ___capture, LinkRef_t_201520826_0 * ___tail, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitBalance()
extern "C"  void PatternCompiler_EmitBalance_m1234756257_0 (PatternCompiler_t_983530916_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitReference(System.Int32,System.Boolean,System.Boolean)
extern "C"  void PatternCompiler_EmitReference_m_2068163007_0 (PatternCompiler_t_983530916_0 * __this, int32_t ___gid, bool ___ignore, bool ___reverse, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitIfDefined(System.Int32,System.Text.RegularExpressions.LinkRef)
extern "C"  void PatternCompiler_EmitIfDefined_m1998800056_0 (PatternCompiler_t_983530916_0 * __this, int32_t ___gid, LinkRef_t_201520826_0 * ___tail, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitSub(System.Text.RegularExpressions.LinkRef)
extern "C"  void PatternCompiler_EmitSub_m1250623225_0 (PatternCompiler_t_983530916_0 * __this, LinkRef_t_201520826_0 * ___tail, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitTest(System.Text.RegularExpressions.LinkRef,System.Text.RegularExpressions.LinkRef)
extern "C"  void PatternCompiler_EmitTest_m_775693289_0 (PatternCompiler_t_983530916_0 * __this, LinkRef_t_201520826_0 * ___yes, LinkRef_t_201520826_0 * ___tail, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitBranch(System.Text.RegularExpressions.LinkRef)
extern "C"  void PatternCompiler_EmitBranch_m_1981027245_0 (PatternCompiler_t_983530916_0 * __this, LinkRef_t_201520826_0 * ___next, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitJump(System.Text.RegularExpressions.LinkRef)
extern "C"  void PatternCompiler_EmitJump_m_135905825_0 (PatternCompiler_t_983530916_0 * __this, LinkRef_t_201520826_0 * ___target, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitRepeat(System.Int32,System.Int32,System.Boolean,System.Text.RegularExpressions.LinkRef)
extern "C"  void PatternCompiler_EmitRepeat_m_381242453_0 (PatternCompiler_t_983530916_0 * __this, int32_t ___min, int32_t ___max, bool ___lazy, LinkRef_t_201520826_0 * ___until, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitUntil(System.Text.RegularExpressions.LinkRef)
extern "C"  void PatternCompiler_EmitUntil_m_1377851113_0 (PatternCompiler_t_983530916_0 * __this, LinkRef_t_201520826_0 * ___repeat, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitFastRepeat(System.Int32,System.Int32,System.Boolean,System.Text.RegularExpressions.LinkRef)
extern "C"  void PatternCompiler_EmitFastRepeat_m1340139951_0 (PatternCompiler_t_983530916_0 * __this, int32_t ___min, int32_t ___max, bool ___lazy, LinkRef_t_201520826_0 * ___tail, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitIn(System.Text.RegularExpressions.LinkRef)
extern "C"  void PatternCompiler_EmitIn_m_2030071082_0 (PatternCompiler_t_983530916_0 * __this, LinkRef_t_201520826_0 * ___tail, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitAnchor(System.Boolean,System.Int32,System.Text.RegularExpressions.LinkRef)
extern "C"  void PatternCompiler_EmitAnchor_m1283354284_0 (PatternCompiler_t_983530916_0 * __this, bool ___reverse, int32_t ___offset, LinkRef_t_201520826_0 * ___tail, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitInfo(System.Int32,System.Int32,System.Int32)
extern "C"  void PatternCompiler_EmitInfo_m_1379940836_0 (PatternCompiler_t_983530916_0 * __this, int32_t ___count, int32_t ___min, int32_t ___max, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.RegularExpressions.LinkRef System.Text.RegularExpressions.PatternCompiler::NewLink()
extern "C"  LinkRef_t_201520826_0 * PatternCompiler_NewLink_m629334431_0 (PatternCompiler_t_983530916_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::ResolveLink(System.Text.RegularExpressions.LinkRef)
extern "C"  void PatternCompiler_ResolveLink_m1754537234_0 (PatternCompiler_t_983530916_0 * __this, LinkRef_t_201520826_0 * ___lref, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitBranchEnd()
extern "C"  void PatternCompiler_EmitBranchEnd_m676018014_0 (PatternCompiler_t_983530916_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitAlternationEnd()
extern "C"  void PatternCompiler_EmitAlternationEnd_m2098295803_0 (PatternCompiler_t_983530916_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.RegularExpressions.OpFlags System.Text.RegularExpressions.PatternCompiler::MakeFlags(System.Boolean,System.Boolean,System.Boolean,System.Boolean)
extern "C"  uint16_t PatternCompiler_MakeFlags_m1692978267_0 (Object_t * __this /* static, unused */, bool ___negate, bool ___ignore, bool ___reverse, bool ___lazy, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::Emit(System.Text.RegularExpressions.OpCode)
extern "C"  void PatternCompiler_Emit_m992741850_0 (PatternCompiler_t_983530916_0 * __this, uint16_t ___op, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::Emit(System.Text.RegularExpressions.OpCode,System.Text.RegularExpressions.OpFlags)
extern "C"  void PatternCompiler_Emit_m1318559571_0 (PatternCompiler_t_983530916_0 * __this, uint16_t ___op, uint16_t ___flags, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::Emit(System.UInt16)
extern "C"  void PatternCompiler_Emit_m2066671991_0 (PatternCompiler_t_983530916_0 * __this, uint16_t ___word, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.RegularExpressions.PatternCompiler::get_CurrentAddress()
extern "C"  int32_t PatternCompiler_get_CurrentAddress_m1919164478_0 (PatternCompiler_t_983530916_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::BeginLink(System.Text.RegularExpressions.LinkRef)
extern "C"  void PatternCompiler_BeginLink_m_223508977_0 (PatternCompiler_t_983530916_0 * __this, LinkRef_t_201520826_0 * ___lref, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.PatternCompiler::EmitLink(System.Text.RegularExpressions.LinkRef)
extern "C"  void PatternCompiler_EmitLink_m116538795_0 (PatternCompiler_t_983530916_0 * __this, LinkRef_t_201520826_0 * ___lref, const MethodInfo* method) IL2CPP_METHOD_ATTR;
