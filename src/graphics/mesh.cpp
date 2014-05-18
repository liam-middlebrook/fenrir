#include "mesh.h"

using namespace Fenrir;
using namespace Fenrir::Graphics;

Mesh::Mesh(GLfloat* vertices, uint vertexCount, GLuint shaderProgram)
{
  this->shaderProgram = shaderProgram;
  this->vertexCount = vertexCount;

  glGenBuffers(1, &this->vertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertexCount* 3, vertices, GL_STATIC_DRAW);
  GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
  glEnableVertexAttribArray(posAttrib);
  glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  this->worldMatrix = glm::mat4(1);
  this->fillColor = glm::vec3(1,1,1);
  this->strokeColor = glm::vec3(0,0,0);
}

void Mesh::DrawMesh(glm::mat4 viewMatrix, glm::mat4 projectionMatrix, bool outline)
{
  GLint viewUni = glGetUniformLocation(this->shaderProgram, "viewMatrix");
  GLint projectionUni = glGetUniformLocation(this->shaderProgram, "projectionMatrix");
  GLint worldUni = glGetUniformLocation(this->shaderProgram, "worldMatrix");

  GLint colorUni = glGetUniformLocation(this->shaderProgram, "color");

  glUniformMatrix4fv(viewUni, 1, GL_FALSE, glm::value_ptr(viewMatrix));
  glUniformMatrix4fv(projectionUni, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
  glUniformMatrix4fv(worldUni, 1, GL_FALSE, glm::value_ptr(worldMatrix));

  glUseProgram(shaderProgram);
  glUniform3f(colorUni, this->fillColor.x, this->fillColor.y, this->fillColor.z);
  glDrawArrays(GL_TRIANGLES, 0, this->vertexCount*3);

  if(outline)
  {
    glUniform3f(colorUni, this->strokeColor.x, this->strokeColor.y, this->strokeColor.z);
    glDrawArrays(GL_LINE_STRIP, 0, this->vertexCount*3);
  }
}

Mesh::~Mesh()
{
  glDeleteBuffers(1, &this->vertexBuffer);
}
