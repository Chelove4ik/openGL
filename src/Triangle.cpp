#include "Triangle.h"
#include "shaderLoader.h"
#include "Matrix4.h"

#define degreesToRadians(x) x*(3.141592f/180.0f)

Triangle::Triangle() {
    static const GLfloat g_vertex_buffer_data[] = {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
    };


    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    programID = LoadShaders("D:/Programs/CG_num_2/res/shaders/shader.vs",
                                   "D:/Programs/CG_num_2/res/shaders/shader.fs");

}

Triangle::~Triangle() {
    glDeleteBuffers(1, &vertexbuffer);
}

void Triangle::draw(mml::Vector3 cameraPosition) {
    glUseProgram(programID);

    mml::Matrix4 projection = mml::perspective(degreesToRadians(45.f), 800.f / 600.f, 0.1f, 100.f);
    mml::Matrix4 view = mml::view(cameraPosition, position, {0, 1, 0});
    mml::Matrix4 model = mml::Matrix4();
    model[0][0] = 1;
    model[1][1] = 1;
    model[2][2] = 1;
    model[3][3] = 1;

    mml::Matrix4 mvp = mml::model(projection, view, model);

    GLuint MatrixID = glGetUniformLocation(programID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);


    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void *) 0          // array buffer offset
    );
    // Draw the Triangle !
    glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 Triangle
    glDisableVertexAttribArray(0);
}