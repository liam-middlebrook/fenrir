#ifndef WINDOW_H_
#define WINDOW_H_

#include <GLFW/glfw3.h>
#include <stdlib.h>

namespace Fenrir
{
  namespace Graphics
  {
    class Window
    {
    public:
      Window(uint width, uint height, char* title);
      ~Window();
    bool IsRunning();
    protected:
    private:
      GLFWwindow* window;
    };
  }
}

#endif
