#version 130
uniform vec3 color;

in float instanceID;
uniform float instanceCount;

void main()
{
  gl_FragColor = vec4(color * vec3(instanceID / instanceCount, 0., 0.), 1.0);
}
