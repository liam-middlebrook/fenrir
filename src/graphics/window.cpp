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
  glfwMakeContextCurrent(this->window);
}

Window::~Window()
{
  glfwDestroyWindow(this->window);
}

bool Window::IsRunning()
{
  return !glfwWindowShouldClose(this->window);
}

void Window::Clear(float r, float g, float b)
{
  glClearColor(r, g, b, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::Render()
{
  glfwSwapBuffers(this->window);
}
