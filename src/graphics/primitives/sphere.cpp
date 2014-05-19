#include "sphere.h"
#include <math.h>
using namespace Fenrir;
using namespace Fenrir::Graphics;
using namespace Fenrir::Graphics::Primitives;

//Create a new Cone Mesh using the vertices specified in SetVertices
Sphere::Sphere(GLuint shaderProgram) : PrimitiveMesh(SetVertices(shaderProgram))
{}

GLuint Sphere::SetVertices(GLuint shaderProgram)
{
  vertexData = new std::vector<GLfloat>();

  //The subdivisions to create the cone using
  float divisions = 150;

  //The radius of the cone
  float radius = 3;
/*
  //Draw the bottom face of the triangle
  for(int i = 0; i < divisions*3; i+=3)
  {
    for(int j = 0; j < divisions*3; j+=3)
    {
      float angle = i * (2*3.141592653589f)/divisions;
      float x = radius*cos(angle);
      float y = radius*sin(angle);
      float z;
      z = x*x + y*y - radius*radius;
      z = sqrt(z);
      vertexData->push_back(x);//z
      vertexData->push_back(y);//z
      vertexData->push_back(z);//z
    }
  }
//*/

  for(int i = 0; i < divisions*3; i++)
  {
    for(int j=0; j < divisions*3; j+=3)
    {
      float theta = i * (2*3.14159265358779f)/divisions;
      float phi = j * (2*3.14159265358979f)/divisions;

      vertexData->push_back(radius*cos(theta)*cos(phi));
      vertexData->push_back(radius*cos(theta)*sin(phi));
      vertexData->push_back(radius*sin(theta));
    }
  }
  // PrimitiveMesh::PrimitiveMesh(true);
  return shaderProgram;
}
