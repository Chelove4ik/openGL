#version 330 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 vertexColor;
uniform mat4 MVP;

out vec4 gl_Position;
out vec3 fragmentColor;


void main() {
    gl_Position =  MVP * vec4(pos, 1);
    fragmentColor = vertexColor;
}
