#version 330 core

// in vec4 color;
in vec3 fragmentColor;

out vec3 color;

void main() {
// 	color = vec3(0, 1, 0);
    color = fragmentColor;
}
