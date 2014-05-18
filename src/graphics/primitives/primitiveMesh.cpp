#include "primitiveMesh.h"
using namespace Fenrir;
using namespace Fenrir::Graphics;
using namespace Fenrir::Graphics::Primitives;


//Create a new primitive mesh that used the specified shaderProgram
PrimitiveMesh::PrimitiveMesh(GLuint shaderProgram)
  : Mesh(&(this->vertexData->at(0)),
         this->vertexData->size()/3,
         shaderProgram)
{ }

PrimitiveMesh::~PrimitiveMesh()
{
  delete this->vertexData;
}
