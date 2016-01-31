
/*
 * =====================================================================================
 *
 *       Filename:  xTriangleOrtho.cpp
 *
 *    Description:  orthographic correction
 *
 *        Version:  1.0
 *        Created:  06/10/2014 20:12:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Pablo Colapinto (), gmail -> wolftype
 *   Organization:  
 *
 * =====================================================================================
 */

#include <vector>

#include "glfw_app.hpp"
#include "gl_macros.hpp"
#include "gl_shader.hpp"

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"                    //<-- a nifty math library
#include "glm/gtc/matrix_transform.hpp"  
#include "glm/gtc/type_ptr.hpp" 

using namespace lynda;


/*-----------------------------------------------------------------------------
 *  SHADER CODE
 *-----------------------------------------------------------------------------*/
const char * vert =  GLSL(120,
  
  attribute vec4 position;
  attribute vec4 color;

  varying vec4 dstColor;

  uniform mat4 ortho;                //<-- new uniform matrix

  void main(){
    dstColor = color;
    gl_Position = ortho * position;  //<-- matrix gets multiplied by the position
  }

);

const char * frag =  GLSL(120,
  
  varying vec4 dstColor;
   
  void main(){
    gl_FragColor = dstColor;
  }

);



/*-----------------------------------------------------------------------------
 *  CREATE A PLAIN-OLD-DATA ("POD") Container for 2D Coordinates
 *-----------------------------------------------------------------------------*/
struct vec2 {
  vec2(float _x=0, float _y=0) : x(_x), y(_y) {}
  float x,y;
};

/*-----------------------------------------------------------------------------
 *  CREATE A PLAIN-OLD-DATA ("POD") Container for RGBA values
 *-----------------------------------------------------------------------------*/
struct vec4 {
  vec4(float _r=1, float _g=1, float _b=1, float _a =1) : r(_r), g(_g), b(_b), a(_a) {}
  float r,g,b,a;
};

/*-----------------------------------------------------------------------------
 *  CREATE A VERTEX OBJECT
 *-----------------------------------------------------------------------------*/
struct Vertex{
  vec2 position;
  vec4 color;
};


/*-----------------------------------------------------------------------------
 *  OUR APP
 *-----------------------------------------------------------------------------*/
struct MyApp : public App{

  //A shader
  Shader * shader;

  //A Container for Vertices
  vector<Vertex> triangle; 

  //ID of Vertex Attribute
  GLuint positionID,colorID;
  //ID of Matrix unfiorm
  GLuint orthoID;                               //<-- orthoID

  //An array object and buffer ID
  GLuint arrayID, bufferID;

  //Constructor (initialize application)
  MyApp() { init(); }

  void init(){

    //Specify the 3 VERTICES of A Triangle
    Vertex v1 = { vec2(-1,-.5), vec4(1,0,0,1) };
    Vertex v2 = { vec2(0,1),    vec4(0,1,0,1) };
    Vertex v3 = { vec2(1,-.5),  vec4(0,0,1,1) };
    triangle.push_back(v1);               
    triangle.push_back(v2); 
    triangle.push_back(v3); 

    /*-----------------------------------------------------------------------------
     *  CREATE THE SHADER
     *-----------------------------------------------------------------------------*/

    //1. CREATE SHADER PROGRAM
    shader = new Shader(vert,frag);
    glUseProgram(shader->id());
      
    positionID = glGetAttribLocation(shader->id(), "position");
    colorID = glGetAttribLocation(shader->id(), "color");
    orthoID = glGetUniformLocation(shader->id(), "ortho");         //<-- get location in shader

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
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    // Send data over buffer to GPU
    glBufferData(GL_ARRAY_BUFFER, triangle.size() * sizeof(Vertex), triangle.data(), GL_STATIC_DRAW );


    /*-----------------------------------------------------------------------------
     *  ENABLE VERTEX ATTRIBUTES
     *-----------------------------------------------------------------------------*/
    // Enable Position Attribute
    glEnableVertexAttribArray(positionID);
    // Enable Color Attribute
    glEnableVertexAttribArray(colorID);

    // Tell OpenGL how to handle the buffer of data that is already on the GPU
    glVertexAttribPointer( positionID, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0 );  
    glVertexAttribPointer(colorID,4,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)sizeof(vec2));

    BINDVERTEXARRAY(0);


  }


  void onDraw(){
    glUseProgram(shader->id());

      //glm is picky about using floats: use .f!
      glm::mat4 ortho = glm::ortho(-window().ratio(), window().ratio(),-1.f, 1.f, -1.f,1.f);
      //set uniform in shader
      glUniformMatrix4fv( orthoID, 1, GL_FALSE, glm::value_ptr(ortho) );
           
      BINDVERTEXARRAY(arrayID);
        glDrawArrays(GL_TRIANGLES, 0, 3);
      BINDVERTEXARRAY(0);
    
    glUseProgram(0);
  }

};


int main(int argc, const char ** argv){
 
  MyApp app;
  app.start();
       
  return 0;
}


