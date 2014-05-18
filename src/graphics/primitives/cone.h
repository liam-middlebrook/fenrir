
#ifndef CONE_H_
#define CONE_H_

#include "primitiveMesh.h"

namespace Fenrir
{
  namespace Graphics
  {
    namespace Primitives
    {
      class Cone : public Fenrir::Graphics::Primitives::PrimitiveMesh
      {
      public:
        Cone(GLuint shaderProgram);
        GLuint SetVertices(GLuint shaderProgram);
      protected:
      private:
      };
    }
  }
}
#endif
