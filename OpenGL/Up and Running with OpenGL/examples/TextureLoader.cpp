/*
 * =====================================================================================
 *
 *       Filename:  TextureLoader.cpp
 *
 *    Description: load a texture from file. 
 *
 *        Version:  1.0
 *        Created:  06/16/2014 11:06:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Pablo Colapinto (), gmail -> wolftype
 *
 * =====================================================================================
 */

#include "glfw_app.hpp"
#include "gl_shader.hpp"
#include "gl_data.hpp"                                //<-- bitmap loader
#include "gl_macros.hpp"


using namespace lynda;
using namespace std;


const char * vert = GLSL(120,

  attribute vec4 position;          
  attribute vec2 textureCoordinate;                   //<-- Texture Coordinate Attribute

  varying vec2 texCoord;                              //<-- To be passed to fragment shader

  void main(void){
    texCoord = textureCoordinate;

    gl_Position = position;
  }

);

const char * frag = GLSL(120,

  uniform sampler2D texture;                        //<-- The texture itself

  varying vec2 texCoord;                            //<-- coordinate passed in from vertex shader

  void main(void){
    gl_FragColor =  texture2D( texture, texCoord ); //<-- look up the coordinate
  }

);


struct vec2 {
  vec2(float _x=0, float _y=0) : x(_x), y(_y) {}
  float x,y;
};


struct Vertex{
  vec2 position;
  vec2 textureCoordinate;
};


struct MyApp : App {

  Shader * shader;

  GLuint tID;
  GLuint arrayID;
  GLuint bufferID;
  GLuint positionID;
  GLuint textureCoordinateID;
  GLuint samplerID;
 

  MyApp() : App() { init(); }

  void init(){

     Bitmap img("resources/flower.bmp");
      
    /*-----------------------------------------------------------------------------
     *  A slab is just a rectangle with texture coordinates
     *-----------------------------------------------------------------------------*/
     //                  position      texture coord
      Vertex slab[] = { 
                        {vec2(-.8,-.8), vec2(0,0)}, //bottom-left
                        {vec2(-.8, .8), vec2(0,1)}, //top-left
                        {vec2( .8, .8), vec2(1,1)}, //top-right
                        {vec2( .8,-.8), vec2(1,0)}  //bottom-right
                      };

      
      /*-----------------------------------------------------------------------------
       *  Make some rgba data (can also load a file here)
       *-----------------------------------------------------------------------------*/
      int tw = img.width; 
      int th = img.height;

      /*-----------------------------------------------------------------------------
       *  Create Shader
       *-----------------------------------------------------------------------------*/
      shader = new Shader(vert,frag);

      /*-----------------------------------------------------------------------------
       *  Get Attribute Locations
       *-----------------------------------------------------------------------------*/
      positionID = glGetAttribLocation( shader->id(), "position" );
      textureCoordinateID = glGetAttribLocation( shader->id(), "textureCoordinate");
      

      /*-----------------------------------------------------------------------------
       *  Generate Vertex Array Object
       *-----------------------------------------------------------------------------*/
      GENVERTEXARRAYS(1,&arrayID);
      BINDVERTEXARRAY(arrayID);

      /*-----------------------------------------------------------------------------
       *  Generate Vertex Buffer Object
       *-----------------------------------------------------------------------------*/
      glGenBuffers(1, &bufferID);
      glBindBuffer( GL_ARRAY_BUFFER, bufferID);
      glBufferData( GL_ARRAY_BUFFER,  4 * sizeof(Vertex), slab, GL_STATIC_DRAW );

      /*-----------------------------------------------------------------------------
       *  Enable Vertex Attributes and Point to them
       *-----------------------------------------------------------------------------*/
      glEnableVertexAttribArray(positionID);
      glEnableVertexAttribArray(textureCoordinateID);
      glVertexAttribPointer( positionID, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0 );  
      glVertexAttribPointer( textureCoordinateID, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) sizeof(vec2) );        

      /*-----------------------------------------------------------------------------
       *  Unbind Vertex Array Object and the Vertex Array Buffer
       *-----------------------------------------------------------------------------*/
      BINDVERTEXARRAY(0);
      glBindBuffer( GL_ARRAY_BUFFER, 0 );

      /*-----------------------------------------------------------------------------
       *  Generate Texture and Bind it
       *-----------------------------------------------------------------------------*/
      glGenTextures(1, &tID);
      glBindTexture(GL_TEXTURE_2D, tID); 

      /*-----------------------------------------------------------------------------
       *  Allocate Memory on the GPU
       *-----------------------------------------------------------------------------*/
       // target | lod | internal_format | width | height | border | format | type | data
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tw, th, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
         
      /*-----------------------------------------------------------------------------
       *  Load data onto GPU (bitmaps flip RGB order)
       *-----------------------------------------------------------------------------*/
      // target | lod | xoffset | yoffset | width | height | format | type | data
      glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, tw, th, GL_BGR,GL_UNSIGNED_BYTE,img.pixels.data() );

      glGenerateMipmap(GL_TEXTURE_2D);

      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

      /*-----------------------------------------------------------------------------
       *  Unbind texture
       *-----------------------------------------------------------------------------*/
       glBindTexture(GL_TEXTURE_2D, 0);

  }

  void onDraw(){

      glUseProgram( shader->id() );          //<-- 1. Bind Shader
      glBindTexture( GL_TEXTURE_2D, tID );   //<-- 2. Bind Texture

      BINDVERTEXARRAY(arrayID);            //<-- 3. Bind VAO
      glDrawArrays( GL_QUADS, 0, 4);         //<-- 4. Draw the four slab vertices
      BINDVERTEXARRAY(0);                  //<-- 5. Unbind the VAO

      glBindTexture( GL_TEXTURE_2D, 0);      //<-- 6. Unbind the texture
      glUseProgram( 0 );                     //<-- 7. Unbind the shader

  }

};


int main(int argc, const char * argv[]){

  MyApp app;
  app.start();

  return 0;
}

