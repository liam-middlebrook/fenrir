

#ifndef TUBE_H_
#define TUBE_H_

#include "primitiveMesh.h"

namespace Fenrir
{
  namespace Graphics
  {
    namespace Primitives
    {
      class Tube : public Fenrir::Graphics::Primitives::PrimitiveMesh
      {
      public:
        Tube(GLuint shaderProgram);
        GLuint SetVertices(GLuint shaderProgram);
      protected:
      private:
      };
    }
  }
}
#endif
