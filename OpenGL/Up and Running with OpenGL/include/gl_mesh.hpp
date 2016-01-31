/*
 * =====================================================================================
 *
 *       Filename:  gl_mesh.hpp
 *
 *    Description:  encapsulation of vertex array object, vertex buffer objects, and vertex array pointers
 *
 *    NOTE: assumes shader defines attributes position, color, normal and textureCoordinate
 *
 *    assumes we will be updating vertex information frequently, but not index information
 *
 *        Version:  1.0
 *        Created:  06/13/2014 16:22:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Pablo Colapinto (), gmail -> wolftype 
 *
 * =====================================================================================
 */

#ifndef  gl_mesh_INC
#define  gl_mesh_INC

#include <vector>

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"


namespace lynda{
/*-----------------------------------------------------------------------------
 *  VERTEX DATA 
 *-----------------------------------------------------------------------------*/
struct Vertex{
  glm::vec3 position;                     //<-- An xyz coordinate of the vertex
  glm::vec3 normal;                       //<-- A normal at the vertex
  glm::vec4 color;                        //<-- A color at the vertex
  glm::vec2 textureCoordinate;            //<-- A texture coordinate of the vertex

  //Offsets into memory
  static size_t offsetNormal() { return sizeof(glm::vec3); }
  static size_t offsetColor() { return sizeof(glm::vec3) * 2; }
  static size_t offsetTextureCoordinate() { return sizeof(glm::vec3)*2 + sizeof(glm::vec4); }
};

struct Mesh{

  //position in world space
  glm::vec3 mPos;
  //orientation in world space
  glm::quat mRot;
  //scale
  float mScale;

  vector<Vertex> vertices;
  vector<GLushort> indices;

  //ID of Vertex Attribute
  GLuint positionID, normalID, colorID, textureCoordinateID;          //<-- Attribute IDS
  //A buffer ID and elementID
  GLuint bufferID, elementID;
  //An array object ID
  GLuint arrayID;


  Mesh() : mScale(1), mRot(1,0,0,0), mPos(0,0,0) {}
  
  void getAttributes( GLuint shaderID ){
    // Get attribute locations from SHADER (if these attributes do not exist in shader, ID=-1)
    positionID = glGetAttribLocation(shaderID, "position");
    colorID = glGetAttribLocation(shaderID, "color");
    normalID = glGetAttribLocation(shaderID, "normal");
    textureCoordinateID = glGetAttribLocation(shaderID, "textureCoordinate"); 
  }

  void buffer(){
    
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
    glBufferData( GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &(vertices[0]), GL_DYNAMIC_DRAW ); //<-- Prep for frequent updates

     /*-----------------------------------------------------------------------------
     *  CREATE THE ELEMENT ARRAY BUFFER OBJECT
     *-----------------------------------------------------------------------------*/
    glGenBuffers(1, &elementID);
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, elementID );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLushort), &(indices[0]), GL_STATIC_DRAW ); //<-- Update infrequently, if ever

    /*-----------------------------------------------------------------------------
     *  ENABLE VERTEX ATTRIBUTES
     *-----------------------------------------------------------------------------*/
    glEnableVertexAttribArray(positionID);
    glEnableVertexAttribArray(colorID);
    glEnableVertexAttribArray(normalID);   //<-- Enable normalID attribute
    glEnableVertexAttribArray(textureCoordinateID);

    // Tell OpenGL how to handle the buffer of data that is already on the GPU
    //                      attrib    num   type     normalize   stride     offset
    glVertexAttribPointer( positionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0 );  
    glVertexAttribPointer( colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) Vertex::offsetColor() );
    glVertexAttribPointer( normalID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) Vertex::offsetNormal() ); 
    glVertexAttribPointer( textureCoordinateID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) Vertex::offsetTextureCoordinate() ); 

    // Unbind Everything (NOTE: unbind the vertex array object first)
    BINDVERTEXARRAY(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); 
  }

  void subBuffer(){
    bind();
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    glBufferSubData( GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(Vertex), vertices.data() );
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    unbind();
  }

  void bind(){ BINDVERTEXARRAY(arrayID); }
  void unbind() { BINDVERTEXARRAY(0); }

  glm::mat4 model(){     
    glm::mat4 scale = glm::scale( glm::mat4(), glm::vec3(mScale) );
    glm::mat4 rotate = glm::toMat4( mRot );
    glm::mat4 translate = glm::translate( glm::mat4(), mPos );

    return translate * rotate * scale;
  }

  void drawArrays( GLuint mode ){ glDrawArrays( mode, 0, vertices.size() ); }
  void drawElements( GLuint mode){ glDrawElements( mode, indices.size(), GL_UNSIGNED_SHORT, 0 ); }
  
};

} //lynda::


#endif   /* ----- #ifndef gl_mesh_INC  ----- */
