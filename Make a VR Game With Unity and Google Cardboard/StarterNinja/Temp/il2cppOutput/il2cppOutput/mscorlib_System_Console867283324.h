#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.IO.TextWriter
struct TextWriter_t1418103405_0;
// System.IO.TextReader
struct TextReader_t1262698173_0;
// System.Text.Encoding
struct Encoding_t453909881_0;

#include "mscorlib_System_Object_887538054.h"

// System.Console
struct  Console_t867283324_0  : public Object_t
{
};
struct Console_t867283324_0_StaticFields{
	// System.IO.TextWriter System.Console::stdout
	TextWriter_t1418103405_0 * ___stdout_0;
	// System.IO.TextWriter System.Console::stderr
	TextWriter_t1418103405_0 * ___stderr_1;
	// System.IO.TextReader System.Console::stdin
	TextReader_t1262698173_0 * ___stdin_2;
	// System.Text.Encoding System.Console::inputEncoding
	Encoding_t453909881_0 * ___inputEncoding_3;
	// System.Text.Encoding System.Console::outputEncoding
	Encoding_t453909881_0 * ___outputEncoding_4;
};
