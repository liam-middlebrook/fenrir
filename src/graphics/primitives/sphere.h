#ifndef SPHERE_H_
#define SPHERE_H_

#include "primitiveMesh.h"

namespace Fenrir
{
  namespace Graphics
  {
    namespace Primitives
    {
      class Sphere : public Fenrir::Graphics::Primitives::PrimitiveMesh
      {
      public:
        Sphere(GLuint shaderProgram);
        GLuint SetVertices(GLuint shaderProgram);
      protected:
      private:
      };
    }
  }
}
#endif
