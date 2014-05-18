#include "mesh.h"

#include <iostream>
using namespace Fenrir;
using namespace Fenrir::Graphics;

Mesh::Mesh(GLfloat* vertices, uint vertexCount, GLuint shaderProgram)
{
  glGenVertexArrays(1, &this->vertexArray);
  glBindVertexArray(this->vertexArray);
  this->shaderProgram = shaderProgram;
  this->vertexCount = vertexCount;
  for(int i = 0; i < vertexCount*3; i += 3)
  {
    std::cout << "X: " << vertices[i] << " Y: " << vertices[i+1] << " Z: " << vertices[i+2] << std::endl;
  }
  std::cout << "shader: " << shaderProgram << std::endl;
  glGenBuffers(1, &this->vertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertexCount* 3, vertices, GL_STATIC_DRAW);
  this->posAttrib = glGetAttribLocation(shaderProgram, "position");
  glEnableVertexAttribArray(this->posAttrib);
  glVertexAttribPointer(this->posAttrib, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  this->worldMatrix = glm::mat4(1);
  this->fillColor = glm::vec3(1,1,1);
  this->strokeColor = glm::vec3(0,0,0);
  glDisableVertexAttribArray(this->posAttrib);
}

void Mesh::DrawMesh(glm::mat4 viewMatrix, glm::mat4 projectionMatrix, bool outline)
{
  glBindVertexArray(this->vertexArray);
  glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
  glUseProgram(shaderProgram);
  glEnableVertexAttribArray(this->posAttrib);

  GLint viewUni = glGetUniformLocation(this->shaderProgram, "viewMatrix");
  GLint projectionUni = glGetUniformLocation(this->shaderProgram, "projectionMatrix");
  GLint worldUni = glGetUniformLocation(this->shaderProgram, "worldMatrix");

  GLint colorUni = glGetUniformLocation(this->shaderProgram, "color");

  glUniformMatrix4fv(viewUni, 1, GL_FALSE, glm::value_ptr(viewMatrix));
  glUniformMatrix4fv(projectionUni, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
  glUniformMatrix4fv(worldUni, 1, GL_FALSE, glm::value_ptr(worldMatrix));

  glUniform3f(colorUni, this->fillColor.x, this->fillColor.y, this->fillColor.z);


  glDrawArrays(GL_TRIANGLES, 0, this->vertexCount*3);

  if(outline)
  {
    glUniform3f(colorUni, this->strokeColor.x, this->strokeColor.y, this->strokeColor.z);
    glDrawArrays(GL_LINE_STRIP, 0, this->vertexCount*3);
  }
  glDisableVertexAttribArray(this->posAttrib);
}

Mesh::~Mesh()
{
  glDeleteBuffers(1, &this->vertexBuffer);
}
