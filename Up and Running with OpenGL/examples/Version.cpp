/*
 * =====================================================================================
 *
 *       Filename:  xVersion.cpp
 *
 *    Description: initialize a context and print out OpenGL version
 *
 *        Version:  1.0
 *        Created:  06/10/2014 12:39:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Pablo Colapinto (), gmail -> wolftype
 *   Organization:  
 *
 * =====================================================================================
 */

//Include OpenGL for graphics and Glfw for windowing
#include <stdlib.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include "GLFW/glfw3.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

    GLFWwindow * window;
    if (!glfwInit()) exit(EXIT_FAILURE);
    window = glfwCreateWindow(1024,768,"glfw",NULL,NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
  glfwMakeContextCurrent(window);
    
  //Get Version String
  const GLubyte * p = glGetString(GL_VERSION);
  cout << "OpenGL Version: " << p << endl;
  return 0;
}



