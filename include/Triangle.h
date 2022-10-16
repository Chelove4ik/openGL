#ifndef MY_OPEN_GL_TRIANGLE_H
#define MY_OPEN_GL_TRIANGLE_H

#include <GL/glew.h>
#include "Vector3.h"


class Triangle {
 public:
    GLuint vertexbuffer;

    GLuint programID;

    mml::Vector3 position{0, 0, 0};

    Triangle();

    ~Triangle();

    void draw(mml::Vector3 cameraPosition);

 private:
};


#endif //MY_OPEN_GL_TRIANGLE_H
