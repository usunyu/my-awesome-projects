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

// System.Text.RegularExpressions.Syntax.Parser
struct Parser_t_906558985_0;
// System.String
struct String_t;
// System.Text.RegularExpressions.Syntax.RegularExpression
struct RegularExpression_t_1358143876_0;
// System.Collections.Hashtable
struct Hashtable_t_2004451924_0;
// System.Text.RegularExpressions.Syntax.Group
struct Group_t932779431_0;
// System.Text.RegularExpressions.Syntax.Assertion
struct Assertion_t_1692638678_0;
// System.Text.RegularExpressions.Syntax.Expression
struct Expression_t_524243856_0;
// System.Text.RegularExpressions.Syntax.ExpressionAssertion
struct ExpressionAssertion_t_181630862_0;
// System.Collections.ArrayList
struct ArrayList_t536890563_0;
// System.ArgumentException
struct ArgumentException_t1159624695_0;

#include "codegen/il2cpp-codegen.h"
#include "System_System_Text_RegularExpressions_RegexOptions2138459498.h"
#include "System_System_Text_RegularExpressions_Category1199172497.h"

// System.Void System.Text.RegularExpressions.Syntax.Parser::.ctor()
extern "C"  void Parser__ctor_m1404972287_0 (Parser_t_906558985_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.RegularExpressions.Syntax.Parser::ParseDecimal(System.String,System.Int32&)
extern "C"  int32_t Parser_ParseDecimal_m_1176119484_0 (Object_t * __this /* static, unused */, String_t* ___str, int32_t* ___ptr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.RegularExpressions.Syntax.Parser::ParseOctal(System.String,System.Int32&)
extern "C"  int32_t Parser_ParseOctal_m1398273866_0 (Object_t * __this /* static, unused */, String_t* ___str, int32_t* ___ptr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.RegularExpressions.Syntax.Parser::ParseHex(System.String,System.Int32&,System.Int32)
extern "C"  int32_t Parser_ParseHex_m370479069_0 (Object_t * __this /* static, unused */, String_t* ___str, int32_t* ___ptr, int32_t ___digits, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.RegularExpressions.Syntax.Parser::ParseNumber(System.String,System.Int32&,System.Int32,System.Int32,System.Int32)
extern "C"  int32_t Parser_ParseNumber_m633788361_0 (Object_t * __this /* static, unused */, String_t* ___str, int32_t* ___ptr, int32_t ___b, int32_t ___min, int32_t ___max, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Text.RegularExpressions.Syntax.Parser::ParseName(System.String,System.Int32&)
extern "C"  String_t* Parser_ParseName_m_1142294817_0 (Object_t * __this /* static, unused */, String_t* ___str, int32_t* ___ptr, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.RegularExpressions.Syntax.RegularExpression System.Text.RegularExpressions.Syntax.Parser::ParseRegularExpression(System.String,System.Text.RegularExpressions.RegexOptions)
extern "C"  RegularExpression_t_1358143876_0 * Parser_ParseRegularExpression_m_693049849_0 (Parser_t_906558985_0 * __this, String_t* ___pattern, int32_t ___options, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.RegularExpressions.Syntax.Parser::GetMapping(System.Collections.Hashtable)
extern "C"  int32_t Parser_GetMapping_m_2052864155_0 (Parser_t_906558985_0 * __this, Hashtable_t_2004451924_0 * ___mapping, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.Parser::ParseGroup(System.Text.RegularExpressions.Syntax.Group,System.Text.RegularExpressions.RegexOptions,System.Text.RegularExpressions.Syntax.Assertion)
extern "C"  void Parser_ParseGroup_m_1758247248_0 (Parser_t_906558985_0 * __this, Group_t932779431_0 * ___group, int32_t ___options, Assertion_t_1692638678_0 * ___assertion, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.RegularExpressions.Syntax.Expression System.Text.RegularExpressions.Syntax.Parser::ParseGroupingConstruct(System.Text.RegularExpressions.RegexOptions&)
extern "C"  Expression_t_524243856_0 * Parser_ParseGroupingConstruct_m845745261_0 (Parser_t_906558985_0 * __this, int32_t* ___options, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Syntax.Parser::ParseAssertionType(System.Text.RegularExpressions.Syntax.ExpressionAssertion)
extern "C"  bool Parser_ParseAssertionType_m_585720030_0 (Parser_t_906558985_0 * __this, ExpressionAssertion_t_181630862_0 * ___assertion, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.Parser::ParseOptions(System.Text.RegularExpressions.RegexOptions&,System.Boolean)
extern "C"  void Parser_ParseOptions_m1196738735_0 (Parser_t_906558985_0 * __this, int32_t* ___options, bool ___negate, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.RegularExpressions.Syntax.Expression System.Text.RegularExpressions.Syntax.Parser::ParseCharacterClass(System.Text.RegularExpressions.RegexOptions)
extern "C"  Expression_t_524243856_0 * Parser_ParseCharacterClass_m_241371304_0 (Parser_t_906558985_0 * __this, int32_t ___options, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Syntax.Parser::ParseRepetitionBounds(System.Int32&,System.Int32&,System.Text.RegularExpressions.RegexOptions)
extern "C"  bool Parser_ParseRepetitionBounds_m_2114055912_0 (Parser_t_906558985_0 * __this, int32_t* ___min, int32_t* ___max, int32_t ___options, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.RegularExpressions.Category System.Text.RegularExpressions.Syntax.Parser::ParseUnicodeCategory()
extern "C"  uint16_t Parser_ParseUnicodeCategory_m1866187541_0 (Parser_t_906558985_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Text.RegularExpressions.Syntax.Expression System.Text.RegularExpressions.Syntax.Parser::ParseSpecial(System.Text.RegularExpressions.RegexOptions)
extern "C"  Expression_t_524243856_0 * Parser_ParseSpecial_m1376060474_0 (Parser_t_906558985_0 * __this, int32_t ___options, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.RegularExpressions.Syntax.Parser::ParseEscape()
extern "C"  int32_t Parser_ParseEscape_m675256065_0 (Parser_t_906558985_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Text.RegularExpressions.Syntax.Parser::ParseName()
extern "C"  String_t* Parser_ParseName_m417255288_0 (Parser_t_906558985_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Syntax.Parser::IsNameChar(System.Char)
extern "C"  bool Parser_IsNameChar_m1287282583_0 (Object_t * __this /* static, unused */, uint16_t ___c, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.RegularExpressions.Syntax.Parser::ParseNumber(System.Int32,System.Int32,System.Int32)
extern "C"  int32_t Parser_ParseNumber_m_1819223942_0 (Parser_t_906558985_0 * __this, int32_t ___b, int32_t ___min, int32_t ___max, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Text.RegularExpressions.Syntax.Parser::ParseDigit(System.Char,System.Int32,System.Int32)
extern "C"  int32_t Parser_ParseDigit_m_1189529074_0 (Object_t * __this /* static, unused */, uint16_t ___c, int32_t ___b, int32_t ___n, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.Parser::ConsumeWhitespace(System.Boolean)
extern "C"  void Parser_ConsumeWhitespace_m_494233491_0 (Parser_t_906558985_0 * __this, bool ___ignore, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.Parser::ResolveReferences()
extern "C"  void Parser_ResolveReferences_m1842037937_0 (Parser_t_906558985_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Text.RegularExpressions.Syntax.Parser::HandleExplicitNumericGroups(System.Collections.ArrayList)
extern "C"  void Parser_HandleExplicitNumericGroups_m_1361907325_0 (Parser_t_906558985_0 * __this, ArrayList_t536890563_0 * ___explicit_numeric_groups, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Syntax.Parser::IsIgnoreCase(System.Text.RegularExpressions.RegexOptions)
extern "C"  bool Parser_IsIgnoreCase_m_1217298873_0 (Object_t * __this /* static, unused */, int32_t ___options, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Syntax.Parser::IsMultiline(System.Text.RegularExpressions.RegexOptions)
extern "C"  bool Parser_IsMultiline_m1332832164_0 (Object_t * __this /* static, unused */, int32_t ___options, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Syntax.Parser::IsExplicitCapture(System.Text.RegularExpressions.RegexOptions)
extern "C"  bool Parser_IsExplicitCapture_m_2142885121_0 (Object_t * __this /* static, unused */, int32_t ___options, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Syntax.Parser::IsSingleline(System.Text.RegularExpressions.RegexOptions)
extern "C"  bool Parser_IsSingleline_m_186104723_0 (Object_t * __this /* static, unused */, int32_t ___options, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Syntax.Parser::IsIgnorePatternWhitespace(System.Text.RegularExpressions.RegexOptions)
extern "C"  bool Parser_IsIgnorePatternWhitespace_m_255251050_0 (Object_t * __this /* static, unused */, int32_t ___options, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Text.RegularExpressions.Syntax.Parser::IsECMAScript(System.Text.RegularExpressions.RegexOptions)
extern "C"  bool Parser_IsECMAScript_m432342092_0 (Object_t * __this /* static, unused */, int32_t ___options, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.ArgumentException System.Text.RegularExpressions.Syntax.Parser::NewParseException(System.String)
extern "C"  ArgumentException_t1159624695_0 * Parser_NewParseException_m_819111275_0 (Parser_t_906558985_0 * __this, String_t* ___msg, const MethodInfo* method) IL2CPP_METHOD_ATTR;
