#version 330 core

layout(location = 0) in vec3 pos;
uniform mat4 MVP;

out vec4 gl_Position;

void main() {
    gl_Position =  MVP * vec4(pos, 1);
}
