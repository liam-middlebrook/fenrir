#include "cube.h"
using namespace Fenrir;
using namespace Fenrir::Graphics;
using namespace Fenrir::Graphics::Primitives;

//Creates a new Cube using the vertices specified in SetVertices
Cube::Cube(GLuint shaderProgram) : PrimitiveMesh(SetVertices(shaderProgram))
{}

//Sets the vertices of a cube
GLuint Cube::SetVertices(GLuint shaderProgram)
{
  this->useIndices = true;
  vertexData = new std::vector<GLfloat>();
  indexData = new std::vector<GLuint>();

  vertexData->push_back(1);
  vertexData->push_back(-1);
  vertexData->push_back(-1);
  vertexData->push_back(1);
  vertexData->push_back(-1);
  vertexData->push_back(1);
  vertexData->push_back(-1);
  vertexData->push_back(-1);
  vertexData->push_back(1);
  vertexData->push_back(-1);
  vertexData->push_back(-1);
  vertexData->push_back(-1);
  vertexData->push_back(1);
  vertexData->push_back(1);
  vertexData->push_back(-1);
  vertexData->push_back(1);
  vertexData->push_back(1);
  vertexData->push_back(1);
  vertexData->push_back(-1);
  vertexData->push_back(1);
  vertexData->push_back(1);
  vertexData->push_back(-1);
  vertexData->push_back(1);
  vertexData->push_back(-1);

  indexData->push_back(4);
  indexData->push_back(0);
  indexData->push_back(3);
  indexData->push_back(4);
  indexData->push_back(3);
  indexData->push_back(7);
  indexData->push_back(2);
  indexData->push_back(6);
  indexData->push_back(7);
  indexData->push_back(2);
  indexData->push_back(7);
  indexData->push_back(3);
  indexData->push_back(1);
  indexData->push_back(5);
  indexData->push_back(2);
  indexData->push_back(5);
  indexData->push_back(6);
  indexData->push_back(2);
  indexData->push_back(0);
  indexData->push_back(4);
  indexData->push_back(1);
  indexData->push_back(4);
  indexData->push_back(5);
  indexData->push_back(1);
  indexData->push_back(4);
  indexData->push_back(7);
  indexData->push_back(5);
  indexData->push_back(7);
  indexData->push_back(6);
  indexData->push_back(5);
  indexData->push_back(0);
  indexData->push_back(1);
  indexData->push_back(2);
  indexData->push_back(0);
  indexData->push_back(2);
  indexData->push_back(3);
  return PrimitiveMesh::SetVertices(shaderProgram);
}
