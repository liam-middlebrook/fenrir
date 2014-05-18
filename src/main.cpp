#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include "graphics/window.h"
#include "graphics/mesh.h"
#include "graphics/primitives/cube.h"
#include "graphics/primitives/cone.h"
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
  std::cout << err << std::endl;
  ShaderFactory::GetInstance()->LoadShaderFromFile("./shaders/shader.vert", "./shaders/shader.frag");

  GLfloat vertices[] = {
    -1.0f,-1.0f,-1.0f, // triangle 1 : begin
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f, // triangle 1 : end
    1.0f, 1.0f,-1.0f, // triangle 2 : begin
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f, // triangle 2 : end
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f
};

  //Mesh* myCube = new Mesh(vertices, 36, ShaderFactory::GetInstance()->GetShaderAtIndex(0));
  Cone* myCube = new Cone(ShaderFactory::GetInstance()->GetShaderAtIndex(0));
  myCube->fillColor = glm::vec3(1,0,0);
  glm::mat4 viewMatrix = glm::lookAt(
                                     glm::vec3(3, 3, 5),
                                     glm::vec3(0, 0, 0),
                                     glm::vec3(0, 1, 0));
  glm::mat4 projMatrix = glm::perspective(45.0f, 4.0f/3.0f, 0.01f, 100.0f);
  while(window->IsRunning())
  {
    window->Clear(100/255.0f, 149/255.0f, 237/255.0f);
    myCube->worldMatrix = glm::scale(glm::mat4(1), glm::vec3(0.5)) * glm::rotate(glm::mat4(1), (float)glfwGetTime(), glm::vec3(0,1,1));
    myCube->DrawMesh(viewMatrix, projMatrix, true);
    window->Render();
    glfwPollEvents();
  }

  return 0;
}
