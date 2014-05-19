#include "mesh.h"

#include <iostream>
using namespace Fenrir;
using namespace Fenrir::Graphics;

Mesh::Mesh(GLfloat* vertices, uint vertexCount, GLuint* indices, uint indexCount, GLuint shaderProgram)
{
  //Generate and bind the vertex array that will be used to draw this mesh
  glGenVertexArrays(1, &this->vertexArray);
  glBindVertexArray(this->vertexArray);

  //copy over the location of the shader program and the vertex count to member variables
  this->shaderProgram = shaderProgram;
  this->vertexCount = vertexCount;
  this->indexCount = indexCount;

  //Loop through all given vertices and write them to console
  for(int i = 0; i < vertexCount*3; i += 3)
  {
    std::cout << "X: " << vertices[i] << " Y: " << vertices[i+1] << " Z: " << vertices[i+2] << std::endl;
  }
  //Write the shader ID to console
  std::cout << "shader: " << shaderProgram << std::endl;

  //Generate and bind the buffer that will hold the vertices
  glGenBuffers(1, &this->vertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);

  //Send the vertex data to the buffer
  //2nd param: the total size of the data to copy to the buffer
  //3rd param: the data we are sending over
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertexCount* 3, vertices, GL_STATIC_DRAW);

  if(useIndices)
  {
    glGenBuffers(1, &this->elementBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indexCount, indices, GL_STATIC_DRAW);
  }

  //Get the location of the position attribute in our shader
  this->posAttrib = glGetAttribLocation(shaderProgram, "position");

  //Enable the position attribute and tell it how to parse our vertex buffer
  glEnableVertexAttribArray(this->posAttrib);
  glVertexAttribPointer(this->posAttrib, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

  //Assign some default values
  this->worldMatrix = glm::mat4(1);
  this->fillColor = glm::vec3(1,1,1);
  this->strokeColor = glm::vec3(0,0,0);
  //Disable the position attribute when we're not using it!
  glDisableVertexAttribArray(this->posAttrib);
}

void Mesh::DrawMesh(glm::mat4 viewMatrix, glm::mat4 projectionMatrix, bool outline)
{
  //Rebind our vertex array and vertex buffer
  glBindVertexArray(this->vertexArray);
  glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);

  if(useIndices)
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->elementBuffer);
  }

  //tell OpenGL to use the shader program associated with this mesh when drawing
  glUseProgram(shaderProgram);

  //enable our position attribute again
  glEnableVertexAttribArray(this->posAttrib);

  //Get the location of our uniform matrices in our shader program
  GLint viewUni = glGetUniformLocation(this->shaderProgram, "viewMatrix");
  GLint projectionUni = glGetUniformLocation(this->shaderProgram, "projectionMatrix");
  GLint worldUni = glGetUniformLocation(this->shaderProgram, "worldMatrix");

  //Get the location of our uniform color in our shader program
  GLint colorUni = glGetUniformLocation(this->shaderProgram, "color");

  //Set the value of all the matrices to be correct
  glUniformMatrix4fv(viewUni, 1, GL_FALSE, glm::value_ptr(viewMatrix));
  glUniformMatrix4fv(projectionUni, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
  glUniformMatrix4fv(worldUni, 1, GL_FALSE, glm::value_ptr(worldMatrix));

  //Set the color to draw with our shader program
  glUniform3f(colorUni, this->fillColor.x, this->fillColor.y, this->fillColor.z);

  //Draw the vertex data that's in our buffer! (as triangles)
  if(useIndices)
  {
    glDrawElements(GL_TRIANGLES, this->indexCount, GL_UNSIGNED_INT, 0);
  }
  else
  {
    glDrawArrays(GL_TRIANGLES, 0, this->vertexCount*3);
  }
  //if enabled draw each edge using strokeColor (as lines)
  if(outline)
  {
    glUniform3f(colorUni, this->strokeColor.x, this->strokeColor.y, this->strokeColor.z);
    if(useIndices)
    {
      glDrawElements(GL_LINE_STRIP, this->indexCount, GL_UNSIGNED_INT, 0);
    }
    else
    {
      glDrawArrays(GL_LINE_STRIP, 0, this->vertexCount*3);
    }
  }

  //disable the position attribute when we're not using itmm
  glDisableVertexAttribArray(this->posAttrib);
}

Mesh::~Mesh()
{
  glDeleteBuffers(1, &this->vertexBuffer);
}
