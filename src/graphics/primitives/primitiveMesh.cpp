#include "primitiveMesh.h"
using namespace Fenrir;
using namespace Fenrir::Graphics;
using namespace Fenrir::Graphics::Primitives;

PrimitiveMesh::PrimitiveMesh(GLuint shaderProgram)
  : Mesh(&(this->vertexData->at(0)),
         this->vertexData->size()/3,
         shaderProgram)
{ }

PrimitiveMesh::~PrimitiveMesh()
{
  delete this->vertexData;
}
