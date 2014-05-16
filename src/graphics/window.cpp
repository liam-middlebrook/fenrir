#include "window.h"
using namespace Fenrir;
using namespace Fenrir::Graphics;

Window::Window(uint width, uint height, char* title)
{
  this->window = glfwCreateWindow(width, height, title, NULL, NULL);
  if(!window)
  {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
}

Window::~Window()
{
  glfwDestroyWindow(this->window);
}

bool Window::IsRunning()
{
  return !glfwWindowShouldClose(this->window);
}
