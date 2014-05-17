#ifndef SHADER_FACTORY_H_
#define SHADER_FACTORY_H_
#define GLEW_STATIC
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <GL/glew.h>

namespace Fenrir
{
  namespace Graphics
  {
    class ShaderFactory
    {
    public:
      static inline ShaderFactory* GetInstance() { if (_instance == NULL) { _instance = new ShaderFactory(); } return _instance; };
      void LoadShader(std::string vertexSource, std::string fragmentSource);
      void LoadShaderFromFile(char* vertexLocation, char* fragmentLocation);
      inline GLuint GetShaderAtIndex(int index) { return shaderPrograms.at(index); };
    protected:
    private:
      static ShaderFactory* _instance;
      std::vector<GLuint> shaderPrograms;
      ShaderFactory();
    };
  }
}

#endif
