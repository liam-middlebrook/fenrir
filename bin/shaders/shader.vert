#version 140
in vec3 position;

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 worldMatrix;

out float instanceID;

void main()
{
float xPos = mod(gl_InstanceID,10);
float yPos = floor(gl_InstanceID / 10.);
  mat4 transMat = mat4(
1, 0, 0, 0,
0, 1, 0, 0,
0, 0, 1, 0,
xPos*2., yPos*2., 0, 1);
  gl_Position = projectionMatrix * viewMatrix * worldMatrix * transMat *  vec4(position, 1.0);
  
  instanceID = gl_InstanceID;
}
