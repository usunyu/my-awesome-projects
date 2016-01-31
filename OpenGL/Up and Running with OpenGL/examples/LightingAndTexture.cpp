/*
 * =====================================================================================
 *
 *       Filename:  LightingAndTexture.cpp
 *
 *    Description: add lighting and texture 
 *
 *        Version:  1.0
 *        Created:  06/13/2014 14:16:04
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
#include "gl_data.hpp"

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
  attribute vec2 textureCoordinate;
  
  uniform mat4 projection;
  uniform mat4 view;
  uniform mat4 model;
  uniform mat3 normalMatrix; //<-- This will be used to calculate our normals in eye space
  
  varying vec2 texCoord; 
  varying float diffuse;        

  //the simplest function to calculate lighting 
  float doColor(){
    vec3 norm  = normalize( normalMatrix * normalize(normal) );
    vec3 light = normalize( vec3(1.0, 1.0, 1.0) );
    diffuse = max(dot(norm,light),0.0 );

    return diffuse;
  }

  void main(void){
    diffuse = doColor();
    texCoord = textureCoordinate;
    gl_Position = projection * view * model * position;
  }

);



const char * frag = GLSL(120,

  uniform sampler2D sampler;
   
  varying vec2 texCoord;  
  varying float diffuse; 

  void main(void){
    gl_FragColor =  vec4(texture2D( sampler, texCoord ).rgb * diffuse, 1.0);
  }

);

using glm::vec2;
using glm::vec3;
using glm::vec4;


/*-----------------------------------------------------------------------------
 *  VERTEX DATA 
 *-----------------------------------------------------------------------------*/
struct Vertex{
  vec3 position;          //<-- Assign an xyz coordinate to the vertex
  vec3 normal;            //<-- Assign a normal to the vertex
  vec4 color;             //<-- Assign a color to the vertex
  vec2 textureCoordinate; //<-- Assign a texture coordinate to the vertex

  //Memory Offsets
  static size_t offsetNormal() { return sizeof(vec3); }
  static size_t offsetColor() { return sizeof(vec3) * 2; }
  static size_t offsetTextureCoordinate() { return sizeof(vec3)*2 + sizeof(vec4); }
};


/*-----------------------------------------------------------------------------
 *  OUR APP
 *-----------------------------------------------------------------------------*/
struct MyApp : public App{

  //ID of Vertex Attribute
  GLuint positionID, normalID, colorID, textureCoordinateID;          //<-- Attribute IDS
  //A buffer ID
  GLuint bufferID, elementID;
  //An array ID
  GLuint arrayID;
  //ID of Uniforms
  GLuint modelID, viewID, projectionID, normalMatrixID;              //<-- A normalMatrixID

  Shader * shader;

  //Texture ID
  GLuint tID;

  //Constructor (initialize application)
  MyApp() { init(); }



  void init(){


     Bitmap img("resources/flower.bmp");
	  
	 int tw = img.width; 
     int th = img.height;


    

  //Specify the 8 VERTICES of A Cube
  //                  position          normal          color          texturecoord
   Vertex cube[] = {
                    { vec3( 1, -1,  1), vec3( 1,-1, 1), vec4(.5,.5,.5,1), vec2(1,0) } ,               
                    { vec3( 1,  1,  1), vec3( 1, 1, 1), vec4(.5,.5,.5,1), vec2(1,1) } , 
                    { vec3(-1,  1,  1), vec3(-1, 1, 1), vec4(.5,.5,.5,1), vec2(0,1) } , 
                    { vec3(-1, -1,  1), vec3(-1,-1, 1), vec4(.5,.5,.5,1), vec2(0,0) } , 

                    { vec3( 1, -1, -1), vec3( 1,-1,-1), vec4(.5,.5,.5,1), vec2(0,0) } , 
                    { vec3( 1,  1, -1), vec3( 1, 1,-1), vec4(.5,.5,.5,1), vec2(0,1) } , 
                    { vec3(-1,  1, -1), vec3(-1, 1,-1), vec4(.5,.5,.5,1), vec2(1,1) } , 
                    { vec3(-1, -1, -1), vec3(-1,-1,-1), vec4(.5,.5,.5,1), vec2(1,0) }  
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
    positionID = glGetAttribLocation(shader->id(), "position");
    colorID = glGetAttribLocation(shader->id(), "color");
    normalID = glGetAttribLocation(shader->id(), "normal");
    textureCoordinateID = glGetAttribLocation(shader->id(), "textureCoordinate"); 

    // Get uniform locations
    modelID = glGetUniformLocation(shader->id(), "model");
    viewID = glGetUniformLocation(shader->id(), "view");
    projectionID = glGetUniformLocation(shader->id(), "projection");
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
    glBindBuffer( GL_ARRAY_BUFFER, bufferID );
    glBufferData( GL_ARRAY_BUFFER, 8 * sizeof(Vertex), cube, GL_STATIC_DRAW );

     /*-----------------------------------------------------------------------------
     *  CREATE THE ELEMENT ARRAY BUFFER OBJECT
     *-----------------------------------------------------------------------------*/
    glGenBuffers(1, &elementID);
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, elementID );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, 24 * sizeof(GLubyte), indices, GL_STATIC_DRAW );

    /*-----------------------------------------------------------------------------
     *  ENABLE VERTEX ATTRIBUTES
     *-----------------------------------------------------------------------------*/
    glEnableVertexAttribArray(positionID);
    glEnableVertexAttribArray(colorID);
    glEnableVertexAttribArray(normalID);   //<-- Enable normalID attribute
    glEnableVertexAttribArray(textureCoordinateID);

    // Tell OpenGL how to handle the buffer of data that is already on the GPU
    glVertexAttribPointer(positionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0 );
    glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (void*) Vertex::offsetColor() );
    glVertexAttribPointer(normalID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (void*) Vertex::offsetNormal() );
    glVertexAttribPointer(textureCoordinateID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (void*) Vertex::offsetTextureCoordinate() );

    // Unbind Everything (NOTE: unbind the vertex array object first)
    BINDVERTEXARRAY(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); 

     /*-----------------------------------------------------------------------------
     *  Generate Texture and Bind it
     *-----------------------------------------------------------------------------*/
    glGenTextures(1, &tID);
    glBindTexture(GL_TEXTURE_2D, tID); 

    /*-----------------------------------------------------------------------------
     *  Allocate Memory on the GPU
     *-----------------------------------------------------------------------------*/
     // target | lod | internal_format | width | height | border | format | type | data
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tw, th, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
       
    /*-----------------------------------------------------------------------------
     *  Load data onto GPU
     *-----------------------------------------------------------------------------*/
    // target | lod | xoffset | yoffset | width | height | format | type | data
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, tw, th, GL_BGR, GL_UNSIGNED_BYTE, img.pixels.data());
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    /*-----------------------------------------------------------------------------
     *  Unbind texture
     *-----------------------------------------------------------------------------*/
     glBindTexture(GL_TEXTURE_2D, 0);
  }


  void onDraw(){

    static float time = 0.0;
    time += .01;

    glBindTexture(GL_TEXTURE_2D, tID);
    BINDVERTEXARRAY(arrayID);

    glm::mat4 view  = glm::lookAt( glm::vec3(0,0,5), glm::vec3(0,0,0), glm::vec3(0,1,0) );
    glm::mat4 proj  = glm::perspective( 3.14f / 3.0f, window().ratio(), 0.1f,-10.0f);
    glm::mat4 model = glm::rotate( glm::mat4(), time, glm::vec3(0,1,0) );
    glm::mat3 normalMatrix = glm::transpose( glm::inverse( glm::mat3(view*model) ) );

    glUniformMatrix4fv( viewID, 1, GL_FALSE, glm::value_ptr(view) );
    glUniformMatrix4fv( projectionID, 1, GL_FALSE, glm::value_ptr(proj) );
    glUniformMatrix4fv( modelID, 1, GL_FALSE, glm::value_ptr(model) );
    glUniformMatrix3fv( normalMatrixID, 1, GL_FALSE, glm::value_ptr(normalMatrix) );

    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, (void*)0);
      
    BINDVERTEXARRAY(0);
  
  }

};


int main(int argc, const char ** argv){
 
  MyApp app;
  app.start();
       
  return 0;
}



