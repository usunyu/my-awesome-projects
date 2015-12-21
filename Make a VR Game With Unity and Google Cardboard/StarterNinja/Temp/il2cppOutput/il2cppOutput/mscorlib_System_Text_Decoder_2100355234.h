#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Text.DecoderFallback
struct DecoderFallback_t798682208_0;
// System.Text.DecoderFallbackBuffer
struct DecoderFallbackBuffer_t542155968_0;

#include "mscorlib_System_Object_887538054.h"

// System.Text.Decoder
struct  Decoder_t_2100355234_0  : public Object_t
{
	// System.Text.DecoderFallback System.Text.Decoder::fallback
	DecoderFallback_t798682208_0 * ___fallback_0;
	// System.Text.DecoderFallbackBuffer System.Text.Decoder::fallback_buffer
	DecoderFallbackBuffer_t542155968_0 * ___fallback_buffer_1;
};
