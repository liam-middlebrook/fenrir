#ifndef MESH_H_
#define MESH_H_

#include "shaderFactory.h"

namespace Fenrir
{
  namespace Graphics
  {
    class Mesh
    {
    public:
      Mesh(GLfloat* vertices, uint vertexCount, GLuint shaderProgram);
      ~Mesh();
      void DrawMesh();
    protected:
    private:
      GLuint vertexBuffer;
      uint vertexCount;
      GLuint shaderProgram;
    };
  }
}

#endif
