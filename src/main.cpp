#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include "graphics/window.h"

using namespace Fenrir;
using namespace Fenrir::Graphics;
int main()
{
  if(!glfwInit())
    exit(EXIT_FAILURE);

  glewExperimental = GL_TRUE;
  glewInit();
  Window* window = new Window(640, 480, "Fenrir");

  while(window->IsRunning())
  {
    glfwPollEvents();
  }

  return 0;
}
