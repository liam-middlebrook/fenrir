#include "window.h"
using namespace Fenrir;
using namespace Fenrir::Graphics;

Window::Window(uint width, uint height, char* title)
{
  //Create a new GLFW window
  this->window = glfwCreateWindow(width, height, title, NULL, NULL);
  if(!window)
  {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  //Tell opengl that it will use this window to draw
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
  //Clear the screen to the specified color value
  glClearColor(r, g, b, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::Render()
{
  //Blit everything!
  glfwSwapBuffers(this->window);
}
