#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Security.SecurityElement
struct SecurityElement_t117540681_0;
// System.Collections.Stack
struct Stack_t_1068416332_0;

#include "mscorlib_Mono_Xml_SmallXmlParser2130513197.h"

// Mono.Xml.SecurityParser
struct  SecurityParser_t1869590237_0  : public SmallXmlParser_t2130513197_0
{
	// System.Security.SecurityElement Mono.Xml.SecurityParser::root
	SecurityElement_t117540681_0 * ___root_13;
	// System.Security.SecurityElement Mono.Xml.SecurityParser::current
	SecurityElement_t117540681_0 * ___current_14;
	// System.Collections.Stack Mono.Xml.SecurityParser::stack
	Stack_t_1068416332_0 * ___stack_15;
};
