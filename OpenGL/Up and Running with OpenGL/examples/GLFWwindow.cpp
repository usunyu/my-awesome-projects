/*
 * =====================================================================================
 *
 *       Filename:  xGLFWwindow.cpp
 *
 *    Description:  making a window with GLFW
 *
 *        Version:  1.0
 *        Created:  06/11/2014 20:37:37
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


int main(){

    if( !glfwInit() ) exit(EXIT_FAILURE);

    int w = 1024; int h = 768;

    GLFWwindow * window;             //Create Window (use glfwGetPrimaryMonitor() for fullscreen)
    window = glfwCreateWindow(w,h,"glfw",NULL,NULL);

    if (!window) {                   //Check Validity
      glfwTerminate();
      exit(EXIT_FAILURE);
    }        
    glfwMakeContextCurrent(window);  //Make Window Current Context


    printf("hello window\n");
  
    /*-----------------------------------------------------------------------------
     *  MAIN LOOP
     *-----------------------------------------------------------------------------*/
    while ( !glfwWindowShouldClose(window) ){
        glViewport(0,0,w,h);             //Set Viewport in pixels
        glClearColor(1,0,0,1);           //CLEAR WINDOW CONTENTS
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //put drawing code in here

        glfwSwapBuffers(window);                //<-- SWAP BUFFERS
        glfwPollEvents();                       //<-- LISTEN FOR WINDOW EVENTS
    }
  
    //Destroy window and terminate glfw
    glfwDestroyWindow(window);
    glfwTerminate();
    printf("goodbye window\n");

  return 0;
}
