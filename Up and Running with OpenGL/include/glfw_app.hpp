/*
 * =====================================================================================
 *
 *       Filename:  glfw_app.hpp
 *
 *    Description:  glfw windowed application
 *
 *        Version:  1.0
 *        Created:  06/11/2014 20:32:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Pablo Colapinto (), gmail -> wolftype
 *
 * =====================================================================================
 */

#ifndef  glfw_app_INC
#define  glfw_app_INC

#include "glfw_window.hpp" //<-- Our GLFW Window


namespace lynda {

struct App{

    Window mWindow;
    Window& window() { return mWindow; }

    App(int w = 640, int h=480)  {

      /*-----------------------------------------------------------------------------
       *  Initialize GLFW
       *-----------------------------------------------------------------------------*/
      if( !glfwInit() ) exit(EXIT_FAILURE);
      printf("glfw initialized \n"); 
      
      mWindow.create(this,w,h);       //<-- Create the window, passing this application to it
      printf("glfw window created \n"); 

      /*-----------------------------------------------------------------------------
       *  Initialize GLEW
       *-----------------------------------------------------------------------------*/
	    glewExperimental = true;
      GLenum glewError = glewInit();
      if (glewError != GLEW_OK){
       printf("glew init error\n%s\n", glewGetErrorString( glewError) );
     }

      if (GLEW_APPLE_vertex_array_object){
        printf("genVertexArrayAPPLE supported\n");
      } else if (GLEW_ARB_vertex_array_object){
        printf("genVertexArrays supported\n");
      }
     
      /*-----------------------------------------------------------------------------
       *  Some Good Defaults to Start with: enable Alpha Blending and Depth Testing
       *-----------------------------------------------------------------------------*/
      glEnable(GL_DEPTH_TEST);
      glDepthFunc(GL_LESS);
        
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

      glLineWidth(3);               //<-- Thicken lines so we can see 'em clearly

    }


    /*-----------------------------------------------------------------------------
     *  Start the Draw Loop
     *-----------------------------------------------------------------------------*/
    void start(){
      printf("starting app\n");
      while ( !mWindow.shouldClose() ){

        mWindow.setViewport();
 
        glClearColor(.2,.2,.2,1);
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        onDraw();
        
        mWindow.swapBuffers();      //<-- SWAP BUFFERS
        glfwPollEvents();           //<-- LISTEN FOR WINDOW EVENTS
       
      }

    }

    
    /*-----------------------------------------------------------------------------
     *  Properly terminate glfw when app closes
     *-----------------------------------------------------------------------------*/
    ~App(){
      glfwTerminate();
    }

    virtual void onDraw() {}

    virtual void onMouseMove(int x, int y){}

    virtual void onMouseDown(int button, int action){}

    virtual void onKeyDown(int key, int action){}
};

} //lynda::


#endif   /* ----- #ifndef glut_app_INC  ----- */
