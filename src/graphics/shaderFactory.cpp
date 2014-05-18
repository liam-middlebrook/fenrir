#include "shaderFactory.h"

using namespace Fenrir;
using namespace Fenrir::Graphics;

ShaderFactory* ShaderFactory::_instance = NULL;

ShaderFactory::ShaderFactory()
{
  //Create a vector to hold all of the loaded shaders
  shaderPrograms = std::vector<GLuint>();
}

std::string loadFileToString(char* fileLocation)
{
  //Load in the file
  std::string content;
  std::ifstream fileStream(fileLocation, std::ios::in);

  //Make sure the file loaded in
  if(!fileStream.is_open())
  {
    std::cout << "Could not read file: " << fileLocation << " File does NOT Exist" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::string line = "";

  //Get every line of the file
  while(!fileStream.eof())
  {
    std::getline(fileStream, line);
    content.append(line + "\n");
  }

  // return a string with the files contents
  fileStream.close();
  return content;
}

void ShaderFactory::LoadShaderFromFile(char* vertexLocation, char* fragmentLocation)
{
  this->LoadShader(loadFileToString(vertexLocation), loadFileToString(fragmentLocation));
}

void ShaderFactory::LoadShader(std::string vertexSource, std::string fragmentSource)
{
  //Convert the vertexShader string to a c-string and print it to console
  const char* vertexChars = vertexSource.c_str();
  std::cout << vertexChars << std::endl;

  //Convert the fragmentShader string to a c-string and print it to console
  const char* fragmentChars = fragmentSource.c_str();
  std::cout << fragmentChars << std::endl;

  //Create a vertex shader
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

  //Give the shader the proper source code and compile it
  glShaderSource(vertexShader, 1, &vertexChars, NULL);
  glCompileShader(vertexShader);

  //Print out whether or not the shader compiled successfuly!
  GLint status;
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
  std::cout << status << " Vertex Shader\n";

  //Create a fragment shader
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

  //Give the shader the proper source code and compile it
  glShaderSource(fragmentShader, 1, &fragmentChars, NULL);
  glCompileShader(fragmentShader);


  //Print out whether or not the shader compiled successfuly!
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
  std::cout << status << " Fragment Shader\n";

  //Create a full shader program and attach the vertex and fragment shaders to it
  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);

  //Link the shader program together and add it to the vector of loaded shaders
  glLinkProgram(shaderProgram);
  shaderPrograms.push_back(shaderProgram);
}
