#version 430
in vec3 position;

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 worldMatrix[625];

out float instanceID;

void main()
{
  gl_Position = projectionMatrix * viewMatrix * worldMatrix[gl_InstanceID] *  vec4(position, 1.0);
  instanceID = gl_InstanceID;
}
