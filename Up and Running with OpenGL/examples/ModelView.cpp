/*
 * =====================================================================================
 *
 *       Filename:  xView.cpp
 *
 *    Description:  moving a virtual camera through a scene
 *
 *        Version:  1.0
 *        Created:  06/13/2014 17:49:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Pablo Colapinto (), gmail -> wolftype
 *   Organization:  
 *
 * =====================================================================================
 */


#include "glfw_app.hpp"
#include "gl_macros.hpp"
#include "gl_shader.hpp"

// INCLUDE MATRIX CODE
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
  uniform mat4 view;                 //<-- 4x4 Transformation Matrices
  uniform mat4 projection;

  void main(){
    dstColor = color;
    gl_Position = projection * view * model * position;   //<-- Apply transformation 
  }

);

const char * frag =  GLSL(120,  
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


    /*-----------------------------------------------------------------------------
     *  CREATE THE SHADER
     *-----------------------------------------------------------------------------*/

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
    glBufferData( GL_ARRAY_BUFFER, 3 * sizeof(Vertex), &(triangle[0]), GL_STATIC_DRAW );


    /*-----------------------------------------------------------------------------
     *  ENABLE VERTEX ATTRIBUTES
     *-----------------------------------------------------------------------------*/
    // Enable Position Attribute
    glEnableVertexAttribArray(positionID);
    // Enable Color Attribute
    glEnableVertexAttribArray(colorID);

    // Tell OpenGL how to handle the buffer of data that is already on the GPU
    glVertexAttribPointer( positionID, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0 );  
    glVertexAttribPointer( colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) sizeof(glm::vec2) );  

    //now we can unbind vertex array object and vertex buffer object
    BINDVERTEXARRAY(0);
    glBindBuffer( GL_ARRAY_BUFFER, 0);


  }


  void onDraw(){

    static float time = 0.0;
    time += .01;

    //Bind Shader and Vertex Array Object
    glUseProgram(shader->id());
    BINDVERTEXARRAY(arrayID);

    /*-----------------------------------------------------------------------------
     *  Set up view and projection matrices
     *-----------------------------------------------------------------------------*/
//    glm::vec3 eyepos = glm::vec3(cos(time) * 1.0, 0, sin(time)*5.0);
//    glm::vec3 eyepos = glm::vec3(sin(time)*5.0, 0, 1);
    glm::vec3 eyepos = glm::vec3(0, 0, 2);
      
    glm::mat4 view = glm::lookAt( eyepos,                           //eye
                                  glm::vec3(0,0,0),                 //target
                                  glm::vec3(0,1,0) );               //up
//      cout << time;
    glm::mat4 proj = glm::perspective( 0.0f, (float)window().ratio(), 0.1f, -10.0f);

    glUniformMatrix4fv( viewID, 1, GL_FALSE, glm::value_ptr(view) );
    glUniformMatrix4fv( projectionID, 1, GL_FALSE, glm::value_ptr(proj) );
    
    /*-----------------------------------------------------------------------------
     *  Render a whole bunch of spinning triangles
     *-----------------------------------------------------------------------------*/
     int len = 10; int total = len*len*len;
    for (int i = 0; i < len; ++i){
        for (int j = 0; j < len; ++j){
            for (int k = 0; k < len; ++k){
              int idx = i * len * len + j * len + k;

              glm::vec3 trs(-len/2.0 + i,-len/2.0+j,-len/2.0+k); 
              glm::vec3 axis(0,0,1);
              float rad = time * PI;
              glm::vec3 vscale( 1.0 - (float)idx/total );

              glm::mat4 translation =  glm::translate( glm::mat4(), trs );
              glm::mat4 rotation =  glm::rotate( glm::mat4(), rad, axis );
              glm::mat4 scale =  glm::scale( glm::mat4(), vscale );

              //ORDER MATTERS!
              glm::mat4 model = glm::mat4();
              
              glUniformMatrix4fv( modelID, 1, GL_FALSE, glm::value_ptr(model) );
              glDrawArrays(GL_TRIANGLES, 0, 3);
          }
        }
    }

    //Unbind 
    BINDVERTEXARRAY(0);
    glUseProgram(0);

  }


};


int main(int argc, const char ** argv){
 
  MyApp app;
  app.start();
       
  return 0;
}




