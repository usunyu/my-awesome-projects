/*
 * =====================================================================================
 *
 *       Filename:  Lighting.cpp
 *
 *    Description:  render a cube with simple lighting
 *
 *        Version:  1.0
 *        Created:  06/12/2014 17:49:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Pablo Colapinto (), gmail -> wolftype
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

#include <vector>


using namespace lynda;
using namespace std;


/*-----------------------------------------------------------------------------
 *  SHADER CODE
 *-----------------------------------------------------------------------------*/

const char * vert = GLSL(120,

  attribute vec4 position;
  attribute vec3 normal;
  attribute vec4 color;            

  uniform mat4 projection;
  uniform mat4 view;
  uniform mat4 model;
  uniform mat3 normalMatrix; //<-- This will be used to calculate our normals in eye space
  
  varying vec4 destColor;            

  //the simplest Function to calculate lighting
  vec4 doColor(){
    vec3 norm  = normalize( normalMatrix * normalize(normal) );
    vec3 light = normalize( vec3(1.0, 1.0, 1.0) );
    float df = max(dot(norm,light),0.0 );

    return vec4( (color * df).xyz, 1.0);
  }

  void main(void){
    destColor = doColor();
    gl_Position = projection * view * model * position;
  }

);



const char * frag = GLSL(120,

  varying vec4 destColor;          

  void main(void){
    gl_FragColor = destColor;  
  }

);

using glm::vec3;
using glm::vec4;

/*-----------------------------------------------------------------------------
 *  CREATE A VERTEX STRUCT
 *-----------------------------------------------------------------------------*/
struct Vertex{
  vec3 position;
  vec3 normal;            //<-- Assign a normal to the vertex
  vec4 color;

  static size_t offsetNormal() { return sizeof(vec3); }
  static size_t offsetColor() { return sizeof(vec3) * 2; }
};


/*-----------------------------------------------------------------------------
 *  OUR APP
 *-----------------------------------------------------------------------------*/
struct MyApp : public App{

  //ID of Vertex Attribute
  GLuint positionID, normalID, colorID;                   //<-- Add a normalID

  //A buffer ID
  GLuint bufferID, elementID;
  //An array ID
  GLuint arrayID;
  
  //ID of Uniforms
  GLuint modelID, viewID, projectionID, normalMatrixID;   //<-- Add a normalMatrixID

  Shader * shader;

  //Constructor (initialize application)
  MyApp() { init(); }

  void init(){

  //Specify the 8 VERTICES of A Cube
   Vertex cube[] = {
                    { vec3( 1, -1,  1), vec3( 1,-1, 1), vec4(1,0,0,1) } ,               
                    { vec3( 1,  1,  1), vec3( 1, 1, 1), vec4(0,1,0,1) } , 
                    { vec3(-1,  1,  1), vec3(-1, 1, 1), vec4(0,0,1,1) } , 
                    { vec3(-1, -1,  1), vec3(-1,-1, 1), vec4(1,0,0,1) } , 

                    { vec3( 1, -1, -1), vec3( 1,-1,-1), vec4(0,1,0,1) } , 
                    { vec3( 1,  1, -1), vec3( 1, 1,-1), vec4(0,0,1,1) } , 
                    { vec3(-1,  1, -1), vec3(-1, 1,-1), vec4(1,0,0,1) } , 
                    { vec3(-1, -1, -1), vec3(-1,-1,-1), vec4(0,1,0,1) }  
                  };




       //6-------------/5
     //  .           // |
   //2--------------1   |
   //    .          |   |
   //    .          |   |
   //    .          |   |
   //    .          |   |
   //    7.......   |   /4
   //               | //
   //3--------------/0

   GLubyte indices[24] = { 
                     0,1,2,3, //front
                     7,6,5,4, //back
                     3,2,6,7, //left
                     4,5,1,0, //right
                     1,5,6,2, //top
                     4,0,3,7 }; //bottom

    /*-----------------------------------------------------------------------------
     *  CREATE THE SHADER
     *-----------------------------------------------------------------------------*/
    
    shader = new Shader( vert, frag );

    // With Shader bound, get attribute and uniform locations:
 
    // Get attribute locations
    positionID = glGetAttribLocation(shader -> id(), "position");
    colorID = glGetAttribLocation(shader -> id(), "color");
    normalID = glGetAttribLocation(shader->id(), "normal");

    // Get uniform locations
    modelID = glGetUniformLocation(shader -> id(), "model");
    viewID = glGetUniformLocation(shader -> id(), "view");
    projectionID = glGetUniformLocation(shader -> id(), "projection");

    //****************/
    normalMatrixID = glGetUniformLocation(shader->id(), "normalMatrix");
      
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
    glBindBuffer( GL_ARRAY_BUFFER, bufferID);
    glBufferData( GL_ARRAY_BUFFER, 8 * sizeof(Vertex), cube, GL_STATIC_DRAW );

     /*-----------------------------------------------------------------------------
     *  CREATE THE ELEMENT ARRAY BUFFER OBJECT
     *-----------------------------------------------------------------------------*/
    glGenBuffers(1, &elementID);
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, elementID);
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, 24 * sizeof(GLubyte), indices, GL_STATIC_DRAW );

    /*-----------------------------------------------------------------------------
     *  ENABLE VERTEX ATTRIBUTES
     *-----------------------------------------------------------------------------*/
    glEnableVertexAttribArray(positionID);
    glEnableVertexAttribArray(colorID);

    //****************/
    glEnableVertexAttribArray(normalID); //<-- Enable normalID attribute

    // Tell OpenGL how to handle the buffer of data that is already on the GPU
    glVertexAttribPointer(positionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0 );  
    glVertexAttribPointer(colorID,4,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)Vertex::offsetColor());

    //****************/         
    glVertexAttribPointer(normalID,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)Vertex::offsetNormal());

    // Unbind Everything (NOTE: unbind the vertex array object first)
    BINDVERTEXARRAY(0);
    glBindBuffer( GL_ARRAY_BUFFER, 0);
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0); 

  }


  void onDraw(){

    static float time = 0.0;
    time += .01;

    BINDVERTEXARRAY(arrayID);

    glm::mat4 view  = glm::lookAt( glm::vec3(0,0,5), glm::vec3(0,0,0), glm::vec3(0,1,0) );
    glm::mat4 proj  = glm::perspective( 3.14f / 3.0f, window().ratio(), 0.1f,-10.0f);
    glm::mat4 model = glm::rotate( glm::mat4(), time, glm::vec3(0,1,0) );

    glUniformMatrix4fv( viewID, 1, GL_FALSE, glm::value_ptr(view) );
    glUniformMatrix4fv( projectionID, 1, GL_FALSE, glm::value_ptr(proj) );
    glUniformMatrix4fv( modelID, 1, GL_FALSE, glm::value_ptr(model) );

    //****************/
    //  Here we calculate the normal matrix and send it to the shader
    glm::mat3 normalMatrix = glm::transpose( glm::inverse( glm::mat3(view*model) ) );
    glUniformMatrix3fv( normalMatrixID, 1, GL_FALSE, glm::value_ptr(normalMatrix) );

    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, 0);
  
    BINDVERTEXARRAY(0);
  }

};


int main(int argc, const char ** argv){
 
  MyApp app;
  app.start();
       
  return 0;
}



