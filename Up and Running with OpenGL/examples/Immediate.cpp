/*
 * =====================================================================================
 *
 *       Filename:  Immediate.cpp
 *
 *    Description:  making a triangle in immediate mode
 *
 *        Version:  1.0
 *        Created:  06/11/2014 20:37:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Pablo Colapinto (), gmail -> wolftype
 *
 * =====================================================================================
 */

//Include OpenGL for graphics and Glfw for windowing
#include <stdlib.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include "GLFW/glfw3.h"
#include <iostream>

int width, height;

void draw(){
    //Draw a Triangle!
    glBegin(GL_TRIANGLES);
        glColor3f(1,0,0);
        glVertex3f(-1,0,0);
        glColor3f(0,1,0);
        glVertex3f(0,1,0);
        glColor3f(0,0,1);
        glVertex3f(1,0,0);
    glEnd();
}


int main(){
    printf("hello triangle\n");
    
    if( !glfwInit() ) exit(EXIT_FAILURE);
    
    width = 640; height = 480;
    
    GLFWwindow * window;       //Create Window (use glfwGetPrimaryMonitor() for fullscreen)
    window = glfwCreateWindow(width,height,"glfw",NULL,NULL);
    
    
    if (!window) {                   //Check Validity
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);  //Make Window Current Context
    
  
    /*-----------------------------------------------------------------------------
     *  MAIN LOOP
     *-----------------------------------------------------------------------------*/
    while ( !glfwWindowShouldClose(window) ){
        
        //Set view port size and position every frame of animation
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0,0,width,height);
        glClearColor(.2,.2,.2,1);                  //<-- CLEAR WINDOW CONTENTS
        glClear( GL_COLOR_BUFFER_BIT );
        
        //put drawing code in here
        draw();
        
        glfwSwapBuffers(window);                //<-- SWAP BUFFERS
        glfwPollEvents();                       //<-- LISTEN FOR WINDOW EVENTS
    }
    
    printf("goodbye triangle\n");
    
    return 0;
}

