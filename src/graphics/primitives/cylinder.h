
#ifndef CYLINDER_H_
#define CYLINDER_H_

#include "primitiveMesh.h"

namespace Fenrir
{
  namespace Graphics
  {
    namespace Primitives
    {
      class Cylinder : public Fenrir::Graphics::Primitives::PrimitiveMesh
      {
      public:
        Cylinder(GLuint shaderProgram);
        GLuint SetVertices(GLuint shaderProgram);
      protected:
      private:
      };
    }
  }
}
#endif
