#include "primitiveMesh.h"
using namespace Fenrir;
using namespace Fenrir::Graphics;
using namespace Fenrir::Graphics::Primitives;


//Create a new primitive mesh that used the specified shaderProgram
PrimitiveMesh::PrimitiveMesh(GLuint shaderProgram)
  : Mesh(&(this->vertexData->at(0)),
         this->vertexData->size()/3,
         &(this->indexData->at(0)),
         this->indexData->size(),
         shaderProgram)
{ }

PrimitiveMesh::~PrimitiveMesh()
{
  delete this->vertexData;
}

GLuint PrimitiveMesh::SetVertices(GLuint shaderProgram)
{
  if(this->indexData == NULL)
  {
    this->indexData = new std::vector<GLuint>();
    this->useIndices = false;
  }
  return shaderProgram;
}
