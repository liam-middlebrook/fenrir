#version 140
in vec3 position;

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 worldMatrix;

void main()
{
  mat4 transMat = mat4(
1, 0, 0, 0,
0, 1, 0, 0,
0, 0, 1, 0,
gl_InstanceID, 0, 0, 1);
  gl_Position = projectionMatrix * viewMatrix * worldMatrix * transMat *  vec4(position, 1.0);
  //gl_Position = vec4(position, 1.0) * worldMatrix * viewMatrix * projectionMatrix;
}
