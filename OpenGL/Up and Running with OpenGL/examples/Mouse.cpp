/*
 * =====================================================================================
 *
 *       Filename:  Mouse.cpp
 *
 *    Description:  Mouse interaction
 *
 *        Version:  1.0
 *        Created:  06/13/2014 17:03:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Pablo Colapinto (), gmail -> wolftype
 *
 * =====================================================================================
 */

#include "glfw_app.hpp"
#include "gl_shader.hpp"
#include "gl_texture.hpp"
#include "gl_macros.hpp"
#include "gl_mesh.hpp"
#include "gl_data.hpp"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

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
  uniform mat3 normalMatrix; //<-- This will be used to calculate our normals in world space
  
  varying vec4 destColor;   
  varying vec2 texCoord; 
  varying float diffuse;        

  //the simplest function to calculate lighting 
  vec4 doColor(){
    vec3 norm  = normalize( normalMatrix * normalize(normal) );
    vec3 light = normalize( vec3(1.0, 1.0, 1.0) );
    diffuse = max(dot(norm,light),0.0 );

    return vec4( (color * diffuse).xyz, 1.0);
  }

  void main(void){
    destColor = doColor();
    
    texCoord = textureCoordinate;
    gl_Position = projection * view * model * position;
  }

);


const char * frag = GLSL(120,

  uniform sampler2D sampler;

  varying vec4 destColor;        
  varying vec2 texCoord;  
  varying float diffuse; 

  void main(void){
    gl_FragColor = vec4(texture2D( sampler, texCoord ).rbg * diffuse, 1.0) ;
  }

);



/*-----------------------------------------------------------------------------
 *  A Mouse Struct
 *-----------------------------------------------------------------------------*/
struct Mouse{
  bool isDown;
  int lastX, lastY;
  int dx, dy;
  int x, y;
};


/*-----------------------------------------------------------------------------
 *  OUR APP
 *-----------------------------------------------------------------------------*/
struct MyApp : App {

  float timer;


  Shader * shader;
  Texture * texture;
  Mesh mesh;

  GLuint viewID, modelID, projectionID, normalMatrixID;

  Mouse mouse;
  glm::quat tmpRot;

  MyApp() : App(){ init(); }

  void init(){
   
    timer = 0.0; 
    srand( 0 );  

    shader = new Shader(vert,frag);

    modelID = glGetUniformLocation(shader->id(), "model");
    viewID = glGetUniformLocation(shader->id(), "view");
    projectionID = glGetUniformLocation(shader->id(), "projection");    
    normalMatrixID = glGetUniformLocation(shader->id(), "normalMatrix"); 

    texture = new Texture(32,32);
    glm::vec4 data[32*32];
    for (int i=0;i<32*32;++i){
      data[i] = glm::vec4(RAND,RAND,RAND,1.0);
    }
    texture -> update( data );


    /*-----------------------------------------------------------------------------
     *  A Cylindrical MESH
     *-----------------------------------------------------------------------------*/

    int slices = 50;
    int stacks = 5;
    for (int i=0; i<slices; ++i){
      float tu = (float)i/slices;
      float rad = 2 * PI * tu;
      for (int j=0;j<stacks;++j){
        float tv = (float)j/stacks;
        glm::vec3 pos( cos(rad), -1 + 2 * tv, sin(rad));
        glm::vec4 col( tu,.5,.5,1);
        glm::vec2 tex( tu, tv );
        Vertex v = { pos, pos, col, tex };
        mesh.vertices.push_back( v );       
      }
    }

    for (int i=0;i<slices;++i){
      int a, b;
      for(int j=0;j<stacks;++j){
        a = i * stacks + j;
        b = i < (slices-1) ? a + stacks : j;
        mesh.indices.push_back(a);
        mesh.indices.push_back(b);
      }
      mesh.indices.push_back(b);
      if (i<slices-1) mesh.indices.push_back((i+1)*stacks);
    }

    mesh.getAttributes( shader->id() );
    mesh.buffer();


  }

  void onDraw(){
    timer+=.01;
    
    //Randomize Texture
    glm::vec4 data[32*32];
    for (int i=0;i<32*32;++i){
      data[i] = glm::vec4(RAND,RAND,RAND,1.0); 
    }
     texture -> update( data );

    glUseProgram(shader->id());
    texture->bind();

    //Eye and Projection Matrices 
    glm::mat4 view  = glm::lookAt( glm::vec3(0,0,3), glm::vec3(0,0,0), glm::vec3(0,1,0) );
    glm::mat4 proj  = glm::perspective( 3.14f / 3.0f, (float)window().width()/window().height(), 0.1f,-10.0f); 
    glUniformMatrix4fv( viewID, 1, GL_FALSE, glm::value_ptr(view) );
    glUniformMatrix4fv( projectionID, 1, GL_FALSE, glm::value_ptr(proj) );
  
  
    /* Model and Normal Matrix for Mesh */    

    glm::mat4 model = mesh.model();
    glm::mat3 normalMatrix = glm::transpose( glm::inverse( glm::mat3(view*model) ) );
    glUniformMatrix4fv( modelID, 1, GL_FALSE, glm::value_ptr(model) );
    glUniformMatrix3fv( normalMatrixID, 1, GL_FALSE, glm::value_ptr(normalMatrix) ); 
    
    mesh.bind();
    mesh.drawElements(GL_TRIANGLE_STRIP);
    mesh.unbind();

    texture->unbind();
    glUseProgram(0);
   
  }

 
  /*-----------------------------------------------------------------------------
   *  Mouse Interactions
   *-----------------------------------------------------------------------------*/
  void onMouseMove(int x, int y){
    mouse.x = x;
    mouse.y = y;
    if (mouse.isDown) onMouseDrag(x,y);
  }

  void onMouseDown(int button, int action){
    if(action == GLFW_PRESS){
       mouse.isDown = true;
       double x,y;
       glfwGetCursorPos(window().window, &x, &y);
       mouse.lastX = x;
       mouse.lastY = y;
       tmpRot = mesh.mRot;
    } else {
      mouse.isDown = false;
    }
  }

  void onMouseDrag(int x, int y){
    mouse.dx = mouse.x - mouse.lastX;
    mouse.dy = mouse.y - mouse.lastY;

    float wx = (float)mouse.dx / window().width();
    float wy = (float)mouse.dy / window().height(); 

    glm::vec3 axis = glm::cross( glm::vec3(0,0,1), glm::vec3(wx,-wy,0) );
    glm::quat q = glm::angleAxis( glm::length(axis), glm::normalize(axis) );
    mesh.mRot = q * tmpRot;
  }

};



/*-----------------------------------------------------------------------------
 *  MAIN
 *-----------------------------------------------------------------------------*/
int main(int argc, const char ** argv){
 
  MyApp app;
  app.start();
       
  return 0;
}
