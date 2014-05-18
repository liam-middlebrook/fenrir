
#include "cylinder.h"
#include <math.h>
using namespace Fenrir;
using namespace Fenrir::Graphics;
using namespace Fenrir::Graphics::Primitives;

Cylinder::Cylinder(GLuint shaderProgram) : PrimitiveMesh(SetVertices(shaderProgram))
{}

GLuint Cylinder::SetVertices(GLuint shaderProgram)
{
  vertexData = new std::vector<GLfloat>();
  float divisions = 150;
  float radius = 3;
  float height = 5;

  for(int i = 0; i < divisions*3; i+=6)
  {
    float angle = i * (2*3.141592653589f)/divisions;
    vertexData->push_back(radius*cos(angle));
    vertexData->push_back(radius*sin(angle));
    vertexData->push_back(0);

    vertexData->push_back(radius*cos(angle));
    vertexData->push_back(radius*sin(angle));
    vertexData->push_back(height);
  }

  for(int j = 0; j <= height; j+=height)
  {
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
      vertexData->push_back(j);
    }
  }
//*/
  // PrimitiveMesh::PrimitiveMesh(true);
  return shaderProgram;
}
