#include "mesh.h"

using namespace Fenrir;
using namespace Fenrir::Graphics;

Mesh::Mesh(GLfloat* vertices, uint vertexCount, GLuint shaderProgram)
{
  this->shaderProgram = shaderProgram;
  this->vertexCount = vertexCount;

  glGenBuffers(1, &this->vertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertexCount, vertices, GL_STATIC_DRAW);
}

void Mesh::DrawMesh()
{
  glUseProgram(shaderProgram);
  glDrawArrays(GL_TRIANGLES, 0, this->vertexCount);
}

Mesh::~Mesh()
{
  glDeleteBuffers(1, &this->vertexBuffer);
}
