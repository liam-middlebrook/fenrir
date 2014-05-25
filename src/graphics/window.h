#ifndef WINDOW_H_
#define WINDOW_H_
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>

typedef unsigned int				uint;

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
      void Render();
      void Clear(float r, float g, float b);
    protected:
    private:
      GLFWwindow* window;
    };
  }
}

#endif
