/*
 * =====================================================================================
 *
 *       Filename:  DynamicMesh.cpp
 *
 *    Description:  update vertex buffer
 *
 *        Version:  1.0
 *        Created:  06/16/2014 11:49:24
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

const char * frag = GLSL(120,
  
  varying vec4 dstColor;
   
  void main(){
    gl_FragColor = dstColor;
  }

);


/*-----------------------------------------------------------------------------
 *  CREATE A VERTEX STRUCT
 *-----------------------------------------------------------------------------*/
struct Vertex{
    glm::vec3 position;
    glm::vec4 color;
};


/*-----------------------------------------------------------------------------
 *  OUR APP
 *-----------------------------------------------------------------------------*/
struct MyApp : public App{

  Shader * shader;

  int w;
  int h;
  //A Container for Vertices
  vector<Vertex> vertices;
  //A Container for indices
  vector<unsigned short> indices;

  //ID of Vertex Attribute
  GLuint positionID, normalID, colorID;

  //A buffer ID
  GLuint bufferID, elementID;
  //An array ID
  GLuint arrayID;
  
  //ID of Uniforms
  GLuint modelID, viewID, projectionID;

  //Constructor (initialize application)
  MyApp() { init(); }

  void init(){

    w = 10; h = 10;
   
    /*-----------------------------------------------------------------------------
     *  Create vertices of a 2d grid mesh
     *-----------------------------------------------------------------------------*/
    for (int i=0;i<w;++i){
      float tu = -1.0 + 2*(float)i/w;
      for(int j=0;j<h;++j){
        float tv = -1.0 + 2*(float)j/h;
          Vertex v = {glm::vec3(tu,tv,0) * 5.0f, glm::vec4(fabs(tu),1,fabs(tv),1)};
          vertices.push_back( v );
      }
    }


    /*-----------------------------------------------------------------------------
     *  Create indices into the vertex array (triangle strip)
     *-----------------------------------------------------------------------------*/
    for (int i=0;i<w-1;++i){
      for (int j=0;j<h;++j){
        int idx = i * h + j;
        indices.push_back(idx);
        indices.push_back(idx+h);
        if(j==(h-1)) indices.push_back(idx+h); //<-- double up end of each column
      }
      indices.push_back((i+1)*h);           //<-- double up at beginning of each column
    }


    /*-----------------------------------------------------------------------------
     *  CREATE THE SHADER
     *-----------------------------------------------------------------------------*/
    
    shader = new Shader( vert, frag );

    // Get attribute locations
    positionID = glGetAttribLocation(shader -> id(), "position");
    colorID = glGetAttribLocation(shader -> id(), "color");

    // Get uniform locations
    modelID = glGetUniformLocation(shader -> id(), "model");
    viewID = glGetUniformLocation(shader -> id(), "view");
    projectionID = glGetUniformLocation(shader -> id(), "projection");


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

    // Send data over buffer to GPU and prepare for Dynamic Update
    glBufferData( GL_ARRAY_BUFFER,
                  vertices.size() * sizeof(Vertex),
                  vertices.data(),
                  GL_DYNAMIC_DRAW ); //<--DYNAMIC UPDATE


     /*-----------------------------------------------------------------------------
     *  CREATE THE ELEMENT ARRAY BUFFER OBJECT
     *-----------------------------------------------------------------------------*/
    glGenBuffers(1, &elementID);
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, elementID);
    glBufferData( GL_ELEMENT_ARRAY_BUFFER,
                  indices.size() * sizeof(GLushort),
                  indices.data(),
                  GL_STATIC_DRAW );


    /*-----------------------------------------------------------------------------
     *  ENABLE VERTEX ATTRIBUTES
     *-----------------------------------------------------------------------------*/
    glEnableVertexAttribArray(positionID);
    glEnableVertexAttribArray(colorID);

    // Tell OpenGL how to handle the buffer of data that is already on the GPU
    //                      attrib    num   type     normalize   stride     offset
    glVertexAttribPointer( positionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0 );  
      glVertexAttribPointer( colorID, 4,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)sizeof(glm::vec3));

    // Unbind Everything (NOTE: unbind the vertex array object first)
    BINDVERTEXARRAY(0);
    glBindBuffer( GL_ARRAY_BUFFER, 0);
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0); 


  }


  void onDraw(){

    static float time = 0.0;
    time += .05;

    BINDVERTEXARRAY(arrayID);

    glm::mat4 view = glm::lookAt( glm::vec3(0,0,10), glm::vec3(0,0,0), glm::vec3(0,1,0) );
    glm::mat4 proj = glm::perspective( 3.14f / 3.f, (float)window().width()/window().height(), 0.1f,-10.f);

    glUniformMatrix4fv( viewID, 1, GL_FALSE, glm::value_ptr(view) );
    glUniformMatrix4fv( projectionID, 1, GL_FALSE, glm::value_ptr(proj) );

    glm::mat4 model;        
    glUniformMatrix4fv( modelID, 1, GL_FALSE, glm::value_ptr(model) );


    for (int i=0;i<vertices.size();++i){
        vertices[i].color = glm::vec4(1,0,0,1.0);
    }
      
    //Bind Buffer itself before Substituting Data on it
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    glBufferSubData( GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(Vertex), vertices.data() );
	glDrawElements(GL_LINE_STRIP, indices.size(), GL_UNSIGNED_SHORT, 0);


    for (int i=0;i<w;++i){
      for (int j=0;j<h;++j){
        int idx = i*h+j;
        vertices[idx].position.z = sin( time + (float)idx/(w*h) * 3.14f );
        vertices[idx].color = glm::vec4( (float)i/w, float(j/h), .5, 0.5);
      }
    }

    glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(Vertex), vertices.data() );
    glDrawElements(GL_TRIANGLE_STRIP, indices.size(), GL_UNSIGNED_SHORT, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
      
    BINDVERTEXARRAY(0);
  }

};


int main(int argc, const char ** argv){
 
  MyApp app;
  app.start();
       
  return 0;
}



