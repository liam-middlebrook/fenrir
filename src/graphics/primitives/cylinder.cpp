
#include "cylinder.h"
#include <math.h>
using namespace Fenrir;
using namespace Fenrir::Graphics;
using namespace Fenrir::Graphics::Primitives;

//Create a cylinder primitive using the data specified in SetVertices
Cylinder::Cylinder(GLuint shaderProgram) : PrimitiveMesh(SetVertices(shaderProgram))
{}

GLuint Cylinder::SetVertices(GLuint shaderProgram)
{
  this->useIndices = false;
  vertexData = new std::vector<GLfloat>();
  //The number of subdivision (by angle) on the cylinder
  float divisions = 150;

  //The radius of the cylinder
  float radius = 3;

  //The height of the cylinder
  float height = 5;

  //Draw the side faces of the cylinder
  for(int i = 0; i < divisions*3; i+=6)
  {
    //Calculate the current angle based on how far
    //we are through the loop
    float angle = i * (2*3.141592653589f)/divisions;

    //Add the bottom vertex at this angle
    vertexData->push_back(radius*cos(angle));//x
    vertexData->push_back(radius*sin(angle));//y
    vertexData->push_back(0);//z

    //Add the top vertex at this angle
    vertexData->push_back(radius*cos(angle));//x
    vertexData->push_back(radius*sin(angle));//y
    vertexData->push_back(height);//z
  }

  //Draw both end faces of the cylinder
  for(int j = 0; j <= height; j+=height)
  {
    //Draw Each triangle on the face
    for(int i = 0; i < divisions*3; i+=3)
    {
      //find the current angle based on for loop position
      float angle = i * (2*3.141592653589f)/divisions;

      //If it's the third vertex it's at (0,0,z);
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
      vertexData->push_back(j);//z
    }
  }
  return PrimitiveMesh::SetVertices(shaderProgram);
}
