/*
 * =====================================================================================
 *
 *       Filename:  Model.cpp
 *
 *    Description:  Add matrix uniforms to our shader and use a matrix library to calculate them
 *
 *        Version:  1.0
 *        Created:  06/11/2014 10:55:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Pablo Colapinto (), gmail -> wolftype
 *   Organization:  
 *
 * =====================================================================================
 */

#include "glfw_app.hpp"
#include "gl_shader.hpp"
#include "gl_macros.hpp"

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


using namespace lynda;

/*-----------------------------------------------------------------------------
 *  SHADER CODE
 *-----------------------------------------------------------------------------*/
const char * vert = GLSL(120, 
  
  attribute vec4 position;
  attribute vec4 color;

  varying vec4 dstColor;

  uniform mat4 model;
  uniform mat4 view;                                      //<-- 4x4 Transformation Matrices
  uniform mat4 projection;

  void main(){
    dstColor = color;
    gl_Position = projection * view * model * position;   //<-- Apply transformation 
  }

);

const char * frag = GLSL(120,
  
  varying vec4 dstColor;
   
  void main(){
    gl_FragColor = dstColor;
  }

);


/*-----------------------------------------------------------------------------
 *  CREATE A VERTEX OBJECT
 *-----------------------------------------------------------------------------*/
struct Vertex{
  glm::vec2 position;
  glm::vec4 color;
};


/*-----------------------------------------------------------------------------
 *  OUR APP
 *-----------------------------------------------------------------------------*/
struct MyApp : public App{

  Shader * shader;
  //ID of Vertex Attribute
  GLuint positionID,colorID;
  //A buffer ID
  GLuint bufferID;
  //An array ID
  GLuint arrayID;
  //ID of Uniform
  GLuint modelID, viewID, projectionID;

  //Constructor (initialize application)
  MyApp() : App() { init(); }

  void init(){

    //Specify the 3 VERTICES of A Triangle
    Vertex triangle[] = {
      { glm::vec2(-1,0), glm::vec4(1,0,0,1) },               
      { glm::vec2(0,1),  glm::vec4(0,1,0,1) }, 
      { glm::vec2(1,0),  glm::vec4(0,0,1,1) } 
    };


    //1. CREATE SHADER PROGRAM
    shader = new Shader(vert,frag);
     
    // Get attribute locations
    positionID = glGetAttribLocation(shader->id(), "position");
    colorID = glGetAttribLocation(shader->id(), "color");

    // Get uniform locations
    modelID = glGetUniformLocation(shader->id(), "model");
    viewID = glGetUniformLocation(shader->id(), "view");
    projectionID = glGetUniformLocation(shader->id(), "projection");

    /*-----------------------------------------------------------------------------
     *  CREATE THE VERTEX ARRAY OBJECT
     *-----------------------------------------------------------------------------*/
    GENVERTEXARRAYS(1, &arrayID);
    BINDVERTEXARRAY(arrayID);

    /*-----------------------------------------------------------------------------
     *  CREATE THE VERTEX BUFFER OBJECT
     *-----------------------------------------------------------------------------*/
    // Generate one buffer
    glGenBuffers(1, &bufferID);
    // Bind Array Buffer 
    glBindBuffer( GL_ARRAY_BUFFER, bufferID);
    // Send data over buffer to GPU
    glBufferData( GL_ARRAY_BUFFER, 3 * sizeof(Vertex), triangle, GL_STATIC_DRAW );


    /*-----------------------------------------------------------------------------
     *  ENABLE VERTEX ATTRIBUTES
     *-----------------------------------------------------------------------------*/
    // Enable Position Attribute
    glEnableVertexAttribArray(positionID);
    // Enable Color Attribute
    glEnableVertexAttribArray(colorID);

    // Tell OpenGL how to handle the buffer of data that is already on the GPU
    glVertexAttribPointer(positionID, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0 );
    glVertexAttribPointer(colorID, 4,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)sizeof(glm::vec2) );

    BINDVERTEXARRAY(0);
    glBindBuffer( GL_ARRAY_BUFFER, 0);

  }


  void onDraw(){

    static float time = 0.0;
    time += .01;

    //Bind Shader
    glUseProgram(shader->id());
    //Bind Vertex Array Object
    BINDVERTEXARRAY(arrayID);
                                  
    /*-----------------------------------------------------------------------------
     *  View Transform: Eye Position        Target             Up Direction
     *-----------------------------------------------------------------------------*/
    glm::mat4 view = glm::lookAt( glm::vec3(0,0,2), glm::vec3(0,0,0), glm::vec3(0,1,0) );
    
    /*-----------------------------------------------------------------------------
     *  Projection Transform:  Field of View     Ratio                     Near   Far
     *-----------------------------------------------------------------------------*/
     // glm requires us to use floats!  use .f or else you'll get compiler errors
    glm::mat4 proj = glm::perspective( PI / 3.0f, (float)window().ratio(), 0.1f,-10.0f);
  
    /*-----------------------------------------------------------------------------
     *  Send view and projection matrices to Shader Uniforms
     *-----------------------------------------------------------------------------*/
    glUniformMatrix4fv( viewID, 1, GL_FALSE, glm::value_ptr(view) );
    glUniformMatrix4fv( projectionID, 1, GL_FALSE, glm::value_ptr(proj) );

    for (int i = 0; i < 100; ++i){
      
      /*-----------------------------------------------------------------------------
       *  Create transformation matrices
       *-----------------------------------------------------------------------------*/
       glm::mat4 translate = glm::translate(glm::mat4(), glm::vec3(sin(time),0, (float)i/100));
       glm::mat4 rotate = glm::rotate(glm::mat4(), time * PI * i/100, glm::vec3(0,0,1) );
       glm::mat4 scale = glm::scale(glm::mat4(), glm::vec3(1.0f- (float)i/100) );

      /*-----------------------------------------------------------------------------
       *  Scale, then Rotate, then Translate = translate * rotate * scale 
       *-----------------------------------------------------------------------------*/
       glm::mat4 model = translate * rotate * scale;                        

      glUniformMatrix4fv( modelID, 1, GL_FALSE, glm::value_ptr(model) );
      glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    //Unbind Vertex Array Object and Shader
    BINDVERTEXARRAY(0);
    glUseProgram(0);
  }

};


int main(int argc, const char ** argv){
 
  MyApp app;
  app.start();
       
  return 0;
}



