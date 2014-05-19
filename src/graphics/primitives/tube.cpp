
#include "tube.h"
#include <math.h>
using namespace Fenrir;
using namespace Fenrir::Graphics;
using namespace Fenrir::Graphics::Primitives;

//Create a cylinder primitive using the data specified in SetVertices
Tube::Tube(GLuint shaderProgram) : PrimitiveMesh(SetVertices(shaderProgram))
{}

void drawSideFaces(float divisions, float radius, float height, std::vector<GLfloat>* vertexData)
{
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

}

void drawCocentricDonut(float divisions, float radius, float innerRadius, float height, std::vector<GLfloat>* vertexData)
{
    
  //Draw the side faces of the cylinder
  for(int i = 0; i < divisions*3; i+=6)
  {
    //Calculate the current angle based on how far
    //we are through the loop
    float angle = i * (2*3.141592653589f)/divisions;

    //Add the bottom vertex at this angle
    vertexData->push_back(innerRadius*cos(angle));//x
    vertexData->push_back(innerRadius*sin(angle));//y
    vertexData->push_back(height);//z

    //Add the top vertex at this angle
    vertexData->push_back(radius*cos(angle));//x
    vertexData->push_back(radius*sin(angle));//y
    vertexData->push_back(height);//z
  }
}

GLuint Tube::SetVertices(GLuint shaderProgram)
{
  vertexData = new std::vector<GLfloat>();
  //The number of subdivision (by angle) on the cylinder
  float divisions = 150;

  //The radius of the cylinder
  float radius = 3;
  float innerRadius = 1.5f;

  //The height of the cylinder
  float height = 5;

  drawSideFaces(divisions, radius, height, vertexData);
  drawSideFaces(divisions, innerRadius, height, vertexData);
  
  drawCocentricDonut(divisions, radius, innerRadius, 0, vertexData);
  drawCocentricDonut(divisions, radius, innerRadius, height, vertexData);
  
  
  return shaderProgram;
}
