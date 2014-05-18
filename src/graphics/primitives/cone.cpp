
#include "cone.h"
#include <math.h>
using namespace Fenrir;
using namespace Fenrir::Graphics;
using namespace Fenrir::Graphics::Primitives;

Cone::Cone(GLuint shaderProgram) : PrimitiveMesh(SetVertices(shaderProgram))
{}

GLuint Cone::SetVertices(GLuint shaderProgram)
{
  vertexData = new std::vector<GLfloat>();
  float divisions = 150;
  float radius = 3;
  for(int i = 0; i < divisions*3; i+=3)
  {
    float angle = i * (2*3.141582653589f)/divisions;
    if( i % 9 == 0)
    {
      vertexData->push_back(0);
      vertexData->push_back(0);
      vertexData->push_back(5);
    }
    else
    {
      vertexData->push_back(radius*cos(angle));
      vertexData->push_back(radius*sin(angle));
      vertexData->push_back(0);
    }
  }
  for(int i = 0; i < divisions*3; i+=3)
  {
    float angle = i * (2*3.141592653589f)/divisions;
    if( i % 9 == 0)
    {
      vertexData->push_back(0);
      vertexData->push_back(0);
    }
    else
    {
      vertexData->push_back(radius*cos(angle));
      vertexData->push_back(radius*sin(angle));
    }
    vertexData->push_back(0);
  }
  // PrimitiveMesh::PrimitiveMesh(true);
  return shaderProgram;
}
