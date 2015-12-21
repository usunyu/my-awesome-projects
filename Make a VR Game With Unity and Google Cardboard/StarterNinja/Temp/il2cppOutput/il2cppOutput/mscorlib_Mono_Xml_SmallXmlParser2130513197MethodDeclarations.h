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

// Mono.Xml.SmallXmlParser
struct SmallXmlParser_t2130513197_0;
// System.Exception
struct Exception_t2143823668_0;
// System.String
struct String_t;
// System.IO.TextReader
struct TextReader_t1262698173_0;
// Mono.Xml.SmallXmlParser/IContentHandler
struct IContentHandler_t_1086891944_0;
// Mono.Xml.SmallXmlParser/AttrListImpl
struct AttrListImpl_t_1125003599_0;

#include "codegen/il2cpp-codegen.h"

// System.Void Mono.Xml.SmallXmlParser::.ctor()
extern "C"  void SmallXmlParser__ctor_m_1293756285_0 (SmallXmlParser_t2130513197_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Exception Mono.Xml.SmallXmlParser::Error(System.String)
extern "C"  Exception_t2143823668_0 * SmallXmlParser_Error_m26295006_0 (SmallXmlParser_t2130513197_0 * __this, String_t* ___msg, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Exception Mono.Xml.SmallXmlParser::UnexpectedEndError()
extern "C"  Exception_t2143823668_0 * SmallXmlParser_UnexpectedEndError_m_1919100636_0 (SmallXmlParser_t2130513197_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Xml.SmallXmlParser::IsNameChar(System.Char,System.Boolean)
extern "C"  bool SmallXmlParser_IsNameChar_m1063489066_0 (SmallXmlParser_t2130513197_0 * __this, uint16_t ___c, bool ___start, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean Mono.Xml.SmallXmlParser::IsWhitespace(System.Int32)
extern "C"  bool SmallXmlParser_IsWhitespace_m2144732407_0 (SmallXmlParser_t2130513197_0 * __this, int32_t ___c, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Xml.SmallXmlParser::SkipWhitespaces()
extern "C"  void SmallXmlParser_SkipWhitespaces_m_1965174152_0 (SmallXmlParser_t2130513197_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Xml.SmallXmlParser::HandleWhitespaces()
extern "C"  void SmallXmlParser_HandleWhitespaces_m1038007407_0 (SmallXmlParser_t2130513197_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Xml.SmallXmlParser::SkipWhitespaces(System.Boolean)
extern "C"  void SmallXmlParser_SkipWhitespaces_m_494479889_0 (SmallXmlParser_t2130513197_0 * __this, bool ___expected, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Xml.SmallXmlParser::Peek()
extern "C"  int32_t SmallXmlParser_Peek_m1856282464_0 (SmallXmlParser_t2130513197_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Xml.SmallXmlParser::Read()
extern "C"  int32_t SmallXmlParser_Read_m1913414875_0 (SmallXmlParser_t2130513197_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Xml.SmallXmlParser::Expect(System.Int32)
extern "C"  void SmallXmlParser_Expect_m_1781012277_0 (SmallXmlParser_t2130513197_0 * __this, int32_t ___c, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Xml.SmallXmlParser::ReadUntil(System.Char,System.Boolean)
extern "C"  String_t* SmallXmlParser_ReadUntil_m_1313673876_0 (SmallXmlParser_t2130513197_0 * __this, uint16_t ___until, bool ___handleReferences, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String Mono.Xml.SmallXmlParser::ReadName()
extern "C"  String_t* SmallXmlParser_ReadName_m_1573852513_0 (SmallXmlParser_t2130513197_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Xml.SmallXmlParser::Parse(System.IO.TextReader,Mono.Xml.SmallXmlParser/IContentHandler)
extern "C"  void SmallXmlParser_Parse_m1621116747_0 (SmallXmlParser_t2130513197_0 * __this, TextReader_t1262698173_0 * ___input, Object_t * ___handler, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Xml.SmallXmlParser::Cleanup()
extern "C"  void SmallXmlParser_Cleanup_m614519621_0 (SmallXmlParser_t2130513197_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Xml.SmallXmlParser::ReadContent()
extern "C"  void SmallXmlParser_ReadContent_m_2021232924_0 (SmallXmlParser_t2130513197_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Xml.SmallXmlParser::HandleBufferedContent()
extern "C"  void SmallXmlParser_HandleBufferedContent_m1598683251_0 (SmallXmlParser_t2130513197_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Xml.SmallXmlParser::ReadCharacters()
extern "C"  void SmallXmlParser_ReadCharacters_m_1330432767_0 (SmallXmlParser_t2130513197_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Xml.SmallXmlParser::ReadReference()
extern "C"  void SmallXmlParser_ReadReference_m_705312074_0 (SmallXmlParser_t2130513197_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 Mono.Xml.SmallXmlParser::ReadCharacterReference()
extern "C"  int32_t SmallXmlParser_ReadCharacterReference_m_238667747_0 (SmallXmlParser_t2130513197_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Xml.SmallXmlParser::ReadAttribute(Mono.Xml.SmallXmlParser/AttrListImpl)
extern "C"  void SmallXmlParser_ReadAttribute_m1488878490_0 (SmallXmlParser_t2130513197_0 * __this, AttrListImpl_t_1125003599_0 * ___a, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Xml.SmallXmlParser::ReadCDATASection()
extern "C"  void SmallXmlParser_ReadCDATASection_m316037423_0 (SmallXmlParser_t2130513197_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void Mono.Xml.SmallXmlParser::ReadComment()
extern "C"  void SmallXmlParser_ReadComment_m1185826634_0 (SmallXmlParser_t2130513197_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
