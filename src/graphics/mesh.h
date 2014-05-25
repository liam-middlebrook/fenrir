#ifndef MESH_H_
#define MESH_H_

#include "shaderFactory.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
typedef unsigned int				uint;

namespace Fenrir
{
  namespace Graphics
  {
    class Mesh
    {
    public:
      Mesh(GLfloat* vertices, uint vertexCount, GLuint* indices, uint indexCount, GLuint shaderProgram);
      virtual ~Mesh();
      void DrawMesh(glm::mat4 viewMatrix, glm::mat4 projectionMatrix, bool drawOutline);
      glm::mat4 worldMatrix;
      glm::vec3 fillColor;
      glm::vec3 strokeColor;
    protected:
      bool useIndices;
    private:
      GLuint vertexBuffer;
      uint vertexCount;
      GLuint shaderProgram;
      GLuint posAttrib;
      GLuint vertexArray;
      GLuint elementBuffer;
      uint indexCount;
    };
  }
}

#endif
