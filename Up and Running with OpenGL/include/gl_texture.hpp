/*
 * =====================================================================================
 *
 *       Filename:  gl_texture.hpp
 *
 *    Description:  2D RGBA floats texture generation 
 *
 *    Note: include OpenGL first
 *
 *        Version:  1.0
 *        Created:  06/13/2014 16:23:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Pablo Colapinto (), gmail -> wolftype
 *   Organization:  
 *
 * =====================================================================================
 */


namespace lynda {

  struct Texture {

    GLuint tID;
    int width, height;

    GLuint id() const { return tID; }
    
    Texture(int w, int h) : width(w), height(h) {
      init();    
    };

    void init(){

      /*-----------------------------------------------------------------------------
       *  Generate Texture and Bind it
       *-----------------------------------------------------------------------------*/
      glGenTextures(1, &tID);
      glBindTexture(GL_TEXTURE_2D, tID); 

      /*-----------------------------------------------------------------------------
       *  Allocate Memory on the GPU
       *-----------------------------------------------------------------------------*/
       // target | lod | internal_format | width | height | border | format | type | data
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_FLOAT, NULL);
        
      /*-----------------------------------------------------------------------------
       *  Set Texture Parameters
       *-----------------------------------------------------------------------------*/
      // Set these parameters to avoid a black screen caused by improperly mipmapped textures
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);  //<-- or GL_LINEAR;
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);  //<-- or GL_LINEAR;

      //optional . . .
      //
      //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
      //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

      /*-----------------------------------------------------------------------------
       *  Unbind texture
       *-----------------------------------------------------------------------------*/
       glBindTexture(GL_TEXTURE_2D, 0);
        
    }

    void bind() { glBindTexture(GL_TEXTURE_2D, tID); }
    void unbind() { glBindTexture(GL_TEXTURE_2D, 0); }


    void update(void * data){
       
       bind(); 
      /*-----------------------------------------------------------------------------
       *  Load data onto GPU
       *-----------------------------------------------------------------------------*/
      // target | lod | xoffset | yoffset | width | height | format | type | data
	    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGBA, GL_FLOAT, data );
      glGenerateMipmap(GL_TEXTURE_2D);

      unbind();

    }
    

  };

}
