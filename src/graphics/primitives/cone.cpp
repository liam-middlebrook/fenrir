
#include "cone.h"
#include <math.h>
using namespace Fenrir;
using namespace Fenrir::Graphics;
using namespace Fenrir::Graphics::Primitives;

//Create a new Cone Mesh using the vertices specified in SetVertices
Cone::Cone(GLuint shaderProgram) : PrimitiveMesh(SetVertices(shaderProgram))
{}

GLuint Cone::SetVertices(GLuint shaderProgram)
{
  vertexData = new std::vector<GLfloat>();

  //The subdivisions to create the cone using
  float divisions = 150;

  //The radius of the cone
  float radius = 3;

  //Draw the side triangles of the cone
  for(int i = 0; i < divisions*3; i+=3)
  {
    //Calculate the current angle on the cone based on how
    //far we are through the loop
    float angle = i * (2*3.141582653589f)/divisions;

    //Every third vertex is the tip of the cone
    if( i % 9 == 0)
    {
      vertexData->push_back(0);//x
      vertexData->push_back(0);//y
      vertexData->push_back(5);//z
    }
    else
    {
      vertexData->push_back(radius*cos(angle));//x
      vertexData->push_back(radius*sin(angle));//y
      vertexData->push_back(0);//z
    }
  }

  //Draw the bottom face of the triangle
  for(int i = 0; i < divisions*3; i+=3)
  {
    //Calculate the current angle on the cone based on how
    //far we are through the loop
    float angle = i * (2*3.141592653589f)/divisions;

    //Every third vertex should be at the center of the cone
    if( i % 9 == 0)
    {
      vertexData->push_back(0);//x
      vertexData->push_back(0);//y
    }
    else
    {
      vertexData->push_back(radius*cos(angle));//x
      vertexData->push_back(radius*sin(angle));//y
    }
    vertexData->push_back(0);//z
  }
  // PrimitiveMesh::PrimitiveMesh(true);
  return shaderProgram;
}
