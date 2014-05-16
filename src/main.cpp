#include <GLFW/glfw3.h>
#include <cstdlib>
#include "graphics/window.h"
using namespace Fenrir;
using namespace Fenrir::Graphics;
int main()
{
  if(!glfwInit())
    exit(EXIT_FAILURE);

  Window* window = new Window(640, 480, "Fenrir");

  while(window->IsRunning())
  {
    glfwPollEvents();
  }

  return 0;
}
