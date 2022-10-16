#ifndef MY_OPEN_GL_CUBE_H
#define MY_OPEN_GL_CUBE_H


#include "Vector3.h"
#include "GL/glew.h"

class Cube {
 public:
    GLuint vertexbuffer;
    GLuint colorbuffer;

    GLuint programID;

    mml::Vector3 position{0, 0, 0};

    Cube();

    ~Cube();

    void draw(mml::Vector3 cameraPosition);

 private:
};


#endif //MY_OPEN_GL_CUBE_H
