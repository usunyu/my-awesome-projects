 /*
 * =====================================================================================
 *
 *       Filename:  xExtensions.cpp
 *
 *    Description:  using glew to get extensions 
 *
 *                -- its a good idea to #define GLEW_STATIC 
                        unless you are dynamically linking to glew
 *                -- including glew will automatically include OpenGL
 *                -- include <stidlib.h> first to avoid errors on windows machines
 *                -- include glfw
 *                -- set glewExperimental = true
 *
 *
 *        Version:  1.0
 *        Created:  06/11/2014 10:52:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Pablo Colapinto (), gmail -> wolftype
 *
 * =====================================================================================
 */

#include <stdlib.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include "GLFW/glfw3.h"
#include <iostream>

 using namespace std;

 int main(int argc, char * argv[]){

	 GLFWwindow * window;
	 if (!glfwInit()) exit(EXIT_FAILURE);
	 window = glfwCreateWindow(1024, 768, "glfw", NULL, NULL);
	 if (!window) {
		 glfwTerminate();
		 exit(EXIT_FAILURE);
	 }
	 glfwMakeContextCurrent(window);


   //2. Now that a context exists, we can initialize glew
   glewExperimental = true;     // This flag helps prevent errors with modern OpenGL
   GLenum glewError = glewInit();
   if (glewError != GLEW_OK){
     printf("glew init error\n%s\n", glewGetErrorString( glewError) );
   }

    if( !GLEW_VERSION_2_1 )
    {
        printf( "OpenGL 2.1 not supported!\n" );
        return false;
    }

   //2. Get OpenGL Version String and GLSL Version string
   const GLubyte * p = glGetString(GL_VERSION); 
   cout << "Graphics Driver: " << p << endl;

   const GLubyte * q = glGetString(GL_SHADING_LANGUAGE_VERSION);
   cout <<  "GLSL Version: " << q << endl;

   //3. Check for specific functionality
   if (GLEW_ARB_vertex_array_object){
     printf("genVertexArrays supported\n");
   }
   if (GLEW_APPLE_vertex_array_object){
     printf("genVertexArrayAPPLE supported\n");
   }

   return 0;
 }    
