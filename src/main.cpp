#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include "graphics/window.h"
#include "graphics/mesh.h"
#include "graphics/primitives/cube.h"
#include "graphics/primitives/cone.h"
#include "graphics/primitives/sphere.h"
#include "graphics/primitives/tube.h"
#include "graphics/primitives/cylinder.h"
using namespace Fenrir;
using namespace Fenrir::Graphics;
using namespace Fenrir::Graphics::Primitives;
int main()
{

  // std::cout << "Test";
  if(!glfwInit())
    exit(EXIT_FAILURE);

  Window* window = new Window(640, 480, "Fenrir");
  glewExperimental=GL_TRUE;
  GLenum err = glewInit();

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  std::cout << err << std::endl;
  ShaderFactory::GetInstance()->LoadShaderFromFile("./shaders/shader.vert", "./shaders/shader.frag");

  Cube* myCube = new Cube(ShaderFactory::GetInstance()->GetShaderAtIndex(0));
  Cone* myCone = new Cone(ShaderFactory::GetInstance()->GetShaderAtIndex(0));
  Tube* myCylinder = new Tube(ShaderFactory::GetInstance()->GetShaderAtIndex(0));

//  Sphere* mySphere = new Sphere(ShaderFactory::GetInstance()->GetShaderAtIndex(0));


  myCube->fillColor = glm::vec3(1,0,0);
  myCylinder->fillColor = glm::vec3(0,0,1);
  //mySphere->fillColor = glm::vec3(0,1,0);
  myCone->fillColor = glm::vec3(0,1,0);
  glm::mat4 viewMatrix = glm::lookAt(
                                     glm::vec3(3, 1, 8),
                                     glm::vec3(0, 0, 0),
                                     glm::vec3(0, 1, 0));
  glm::mat4 projMatrix = glm::perspective(45.0f, 4.0f/3.0f, 0.01f, 100.0f);
  while(window->IsRunning())
  {
    window->Clear(100/255.0f, 149/255.0f, 237/255.0f);
    //mySphere->worldMatrix = glm::scale(glm::mat4(1), glm::vec3(0.5))*glm::rotate(glm::mat4(1), (float)glfwGetTime(), glm::vec3(0, 0, 1));
    myCube->worldMatrix = glm::scale(glm::mat4(1), glm::vec3(0.25))*glm::translate(glm::mat4(1), glm::vec3(-5, 0, -4));
    myCone->worldMatrix = glm::scale(glm::mat4(1), glm::vec3(0.5)) * glm::rotate(glm::mat4(1), (float)glfwGetTime(), glm::vec3(1,1,1));
    myCylinder->worldMatrix = glm::scale(glm::mat4(1), glm::vec3(0.5)) * glm::rotate(glm::mat4(1), (float)glfwGetTime(), glm::vec3(0,1,0));
    //mySphere->DrawMesh(viewMatrix, projMatrix, true);
   // myCube->DrawMesh(viewMatrix, projMatrix, true);
    myCylinder->DrawMesh(viewMatrix, projMatrix, true);
   // myCone->DrawMesh(viewMatrix, projMatrix, true);
    window->Render();
    glfwPollEvents();
  }

  return 0;
}
