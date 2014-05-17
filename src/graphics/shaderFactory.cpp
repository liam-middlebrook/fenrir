#include "shaderFactory.h"

using namespace Fenrir;
using namespace Fenrir::Graphics;

ShaderFactory* ShaderFactory::_instance = NULL;

ShaderFactory::ShaderFactory()
{
  shaderPrograms = std::vector<GLuint>();
}

std::string loadFileToString(char* fileLocation)
{
  std::string content;
  std::ifstream fileStream(fileLocation, std::ios::in);

  if(!fileStream.is_open())
  {
    std::cout << "Could not read file: " << fileLocation << " File does NOT Exist" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::string line = "";
  while(!fileStream.eof())
  {
    std::getline(fileStream, line);
    content.append(line + "\n");
  }

  fileStream.close();
  return content;
}

void ShaderFactory::LoadShaderFromFile(char* vertexLocation, char* fragmentLocation)
{
  this->LoadShader(loadFileToString(vertexLocation), loadFileToString(fragmentLocation));
}

void ShaderFactory::LoadShader(std::string vertexSource, std::string fragmentSource)
{
  const char* vertexChars = vertexSource.c_str();
  std::cout << vertexChars << std::endl;
  const char* fragmentChars = fragmentSource.c_str();
  std::cout << fragmentChars << std::endl;
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  std::cout << "Shader created" << std::endl;
  glShaderSource(vertexShader, 1, &vertexChars, NULL);
  glCompileShader(vertexShader);

  GLint status;
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
  std::cout << status << " Vertex Shader\n";

  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentChars, NULL);
  glCompileShader(fragmentShader);

  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
  std::cout << status << " Fragment Shader\n";

  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);

  glLinkProgram(shaderProgram);
  shaderPrograms.push_back(shaderProgram);
}
