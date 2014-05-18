#ifndef CUBE_H_
#define CUBE_H_

#include "primitiveMesh.h"

namespace Fenrir
{
  namespace Graphics
  {
    namespace Primitives
    {
      class Cube : public Fenrir::Graphics::Primitives::PrimitiveMesh
      {
      public:
        Cube(GLuint shaderProgram);
        GLuint SetVertices(GLuint shaderProgram);
      protected:
      private:
      };
    }
  }
}
#endif
