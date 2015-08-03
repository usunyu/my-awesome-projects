/*
 * =====================================================================================
 *
 *       Filename:  TriangleBuffer.cpp
 *
 *    Description:  Generate Vertex Array Objects and Vertex Buffer Objects
 *
 *        Version:  1.0
 *        Created:  06/10/2014 14:34:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Pablo Colapinto (), gmail -> wolftype
 *
 * =====================================================================================
 */

// INCLUDE the APP Class
#include "glfw_app.hpp"

#include <vector>

//macro to write shader programs inline
#ifndef GLSL 
#define GLSL(version,A) "#version " #version "\n" #A
#endif

//macro to pick the right glGenVertexArray function
#ifndef GENVERTEXARRAYS
#define GENVERTEXARRAYS(n,id) \
  if(GLEW_APPLE_vertex_array_object) glGenVertexArraysAPPLE(1,id);\
	else if (GLEW_ARB_vertex_array_object) glGenVertexArrays(n,id)
#endif

//macro to pick the right glBindVertexArray function
#ifndef BINDVERTEXARRAY
#define BINDVERTEXARRAY(id) \
  if(GLEW_APPLE_vertex_array_object) glBindVertexArrayAPPLE(id);\
	else if (GLEW_ARB_vertex_array_object) glBindVertexArray(id)
#endif

using namespace lynda;

/*-----------------------------------------------------------------------------
 *  SOME SHADER CODE
 *-----------------------------------------------------------------------------*/
const char * vert = GLSL(120,
  attribute vec4 position;
                //note: "attribute" should be changed to "in" on versions 130 and above

  void main(){
    gl_Position = position;
  }
);

const char * frag = GLSL(120, 
  void main(){
    gl_FragColor = vec4(1.0,0.0,0.0,1.0);
  }
);


/*-----------------------------------------------------------------------------
 *  FUNCION TO CHECK FOR SHADER COMPILER ERRORS
 *-----------------------------------------------------------------------------*/
void shaderCompilerCheck(GLuint ID){
  GLint comp;
  glGetShaderiv(ID, GL_COMPILE_STATUS, &comp);

  if(comp == GL_FALSE ){
      cout << "Shader Compilation FAILED" << endl;
      GLchar messages[256];
      glGetShaderInfoLog(ID, sizeof(messages),0,&messages[0]);
      cout << messages;
  }
}


/*-----------------------------------------------------------------------------
 *  FUNCION TO CHECK FOR SHADER LINK ERRORS
 *-----------------------------------------------------------------------------*/
void shaderLinkCheck(GLuint ID){
  GLint linkStatus, validateStatus;
  glGetProgramiv(ID, GL_LINK_STATUS, &linkStatus);
			

  if(linkStatus == GL_FALSE ){
      cout << "Shader Linking FAILED" << endl;
      GLchar messages[256];
      glGetProgramInfoLog(ID, sizeof(messages),0,&messages[0]);
      cout << messages;
  }

  glValidateProgram(ID);
	glGetProgramiv(ID, GL_VALIDATE_STATUS, &validateStatus);
  	
  if(linkStatus == GL_FALSE ){
      cout << "Shader Validation FAILED" << endl;
      GLchar messages[256];
      glGetProgramInfoLog(ID, sizeof(messages),0,&messages[0]);
      cout << messages;
  }
}


/*-----------------------------------------------------------------------------
 *  A PLAIN-OLD-DATA ("POD") Container for 2D Coordinates (eventually we'll use a
 *  library for this)
 *-----------------------------------------------------------------------------*/
struct vec2 {
  vec2(float _x=0, float _y=0) : x(_x), y(_y) {}
  float x,y;
};

struct vec3 {
    vec3(float _x=0, float _y=0, float _z=0) : x(_x), y(_y), z(_z) {}
    float x,y,z;
};



/*-----------------------------------------------------------------------------
 *  OUR APP
 *-----------------------------------------------------------------------------*/
struct MyApp : public App{

  //A Container for Vertices
  vector<vec2> triangle;
  vector<vec3> triangle2;

  //ID of shader
  GLuint sID;
  //ID of Vertex Attribute
  GLuint positionID;
  //A buffer ID
  GLuint bufferID;
  //A Vertex Array ID
  GLuint arrayID;

  //Constructor (initialize application)
  MyApp() { init(); }

  void init(){

    //Specify the 3 VERTICES of A Triangle
    triangle.push_back( vec2(-1,-.5) );               
    triangle.push_back( vec2(0,1) ); 
    triangle.push_back( vec2(1,-.5) );
      
    triangle2.push_back( vec3(-1,-.5,1) );
    triangle2.push_back( vec3(0,.5,.5) );
    triangle2.push_back( vec3(2,-.5,0) );

    /*-----------------------------------------------------------------------------
     *  CREATE THE SHADER
     *-----------------------------------------------------------------------------*/

    //1. CREATE SHADER PROGRAM
    sID = glCreateProgram();
    GLuint vID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fID = glCreateShader(GL_FRAGMENT_SHADER);

    //2. LOAD SHADER SOURCE CODE
    glShaderSource(vID, 1, &vert, NULL);
    glShaderSource(fID, 1, &frag, NULL);

    //3. COMPILE
    glCompileShader(vID);
    glCompileShader(fID);

    //4. CHECK FOR COMPILE ERRORS
    shaderCompilerCheck(vID);
    shaderCompilerCheck(fID);

    //5. ATTACH SHADERS TO PROGRAM
    glAttachShader(sID,vID);
    glAttachShader(sID,fID);

    //6. LINK PROGRAM
    glLinkProgram(sID);

    //7. CHECK FOR LINKING ERRORS
    shaderLinkCheck(sID);
        
    //8. USE PROGRAM
    glUseProgram(sID);
 
    //Get locations of variables in the program
    positionID = glGetAttribLocation(sID, "position");

      
    //9. Unbind Program
    glUseProgram(0);
    
    /*-----------------------------------------------------------------------------
     *  CREATE THE VERTEX ARRAY OBJECT
     *-----------------------------------------------------------------------------*/
    //  if(GLEW_APPLE_vertex_array_object) glGenVertexArraysAPPLE(1,id);
    //  else if (GLEW_ARB_vertex_array_object) glGenVertexArrays(n,id);
    GENVERTEXARRAYS(1, &arrayID);
    //  if(GLEW_APPLE_vertex_array_object) glBindVertexArrayAPPLE(id);
    //  else if (GLEW_ARB_vertex_array_object) glBindVertexArray(id);
    BINDVERTEXARRAY(arrayID);

    /*-----------------------------------------------------------------------------
     *  CREATE THE VERTEX BUFFER OBJECT
     *-----------------------------------------------------------------------------*/
    // Generate one buffer
    glGenBuffers(1, &bufferID);
    // Bind Array Buffer 
    glBindBuffer( GL_ARRAY_BUFFER, bufferID);
    // Send data over buffer to GPU
    // glBufferData( GL_ARRAY_BUFFER, triangle.size() * sizeof(vec2), triangle.data(), GL_STATIC_DRAW );
    
    glBufferData( GL_ARRAY_BUFFER, triangle2.size() * sizeof(vec3), &(triangle2[0]), GL_STATIC_DRAW );

    /*-----------------------------------------------------------------------------
     *  ENABLE VERTEX ATTRIBUTES
     *-----------------------------------------------------------------------------*/
    // Enable Position Attribute
    glEnableVertexAttribArray(positionID);
    // Tell OpenGL how to handle the buffer of data
    //                      attrib    num   type     normalize   stride   offset
    // glVertexAttribPointer( positionID, 2, GL_FLOAT, GL_FALSE, sizeof(vec2), 0 );
    glVertexAttribPointer( positionID, 3, GL_FLOAT, GL_FALSE, sizeof(vec3), 0 );

    /*-----------------------------------------------------------------------------
     *  UNBIND Vertex Array Object and Vertex Buffer Object
     *-----------------------------------------------------------------------------*/
    BINDVERTEXARRAY(0);
    glBindBuffer( GL_ARRAY_BUFFER, 0);
  }


  void onDraw(){
    //Bind Shader and Vertex Array Object
    glUseProgram(sID);
    BINDVERTEXARRAY(arrayID);
  
    //Draw Triangle
    glDrawArrays(GL_TRIANGLES, 0, 3);

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

