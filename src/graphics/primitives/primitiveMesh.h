#ifndef PRIMITIVE_MESH_H_
#define PRIMITIVE_MESH_H_

#include "../mesh.h"
#include <vector>

namespace Fenrir
{
  namespace Graphics
  {
    namespace Primitives
    {
      class PrimitiveMesh : public Fenrir::Graphics::Mesh
      {
      public:
        PrimitiveMesh(GLuint shaderProgram);
	virtual GLuint SetVertices(GLuint shaderProgram) = 0;
        virtual ~PrimitiveMesh();
      protected:
        std::vector<GLfloat>* vertexData;
      private:
      };
    }
  }
}

#endif
