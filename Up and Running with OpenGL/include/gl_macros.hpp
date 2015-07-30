/*
 * =====================================================================================
 *
 *       Filename:  gl_macros.h
 *
 *    Description:  some useful #defines like PI and STRINGIFY and GLSL 
 *
 *        Version:  1.0
 *        Created:  06/18/2014 17:42:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Pablo Colapinto (), gmail -> wolftype
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef  gl_macros_INC
#define  gl_macros_INC

#include <math.h>

namespace lynda{

#ifndef PI
#define PI (float)3.14159265359
#endif

#ifndef STRINGIFY 
#define STRINGIFY(A) #A
#endif

//SAME AS STRINGIFY, but with a version preprocessor command
#ifndef GLSL
#define GLSL(version, A) "#version " #version "\n" #A
#endif  

#ifndef RAND
#define RAND (1.0 * rand() / (RAND_MAX))
#endif

#ifndef GENVERTEXARRAYS
#define GENVERTEXARRAYS(n,id) if(GLEW_APPLE_vertex_array_object)glGenVertexArraysAPPLE(1,id);\
	else if (GLEW_ARB_vertex_array_object) glGenVertexArrays(n,id)
#endif

#ifndef BINDVERTEXARRAY
#define BINDVERTEXARRAY(id) if(GLEW_APPLE_vertex_array_object)glBindVertexArrayAPPLE(id);\
	else if (GLEW_ARB_vertex_array_object) glBindVertexArray(id)
#endif

}

#endif   /* ----- #ifndef gl_macros_INC  ----- */
