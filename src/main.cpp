#include <iostream>
#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <shaderLoader.h>

#include "Triangle.h"

using namespace std;

int main() {
    sf::ContextSettings settings;
    settings.depthBits = 24; // количество битов буффера глубины
    settings.stencilBits = 8; //количество битов буфера трафарета
    settings.majorVersion = 4;
    settings.minorVersion = 3;
    settings.attributeFlags = sf::ContextSettings::Core;

    sf::Window window(sf::VideoMode(800, 600, 32), "First Window",
                      sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    glewExperimental = GL_TRUE; // включить все современные функции ogl

    if (GLEW_OK != glewInit()) { // включить glew
        cout << "Error:: glew not init =(" << endl;
        return -1;
    }

    bool isGo = true;
    auto triangle = Triangle();

    while (isGo) {
        sf::Event windowEvent{};

        while (window.pollEvent(windowEvent)) { // обработка ивентов
            switch (windowEvent.type)
            {
                case sf::Event::Closed:
                    isGo = false;
                    break;
                default:
                    break;
            }
        }

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //отчистка экрана
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //отчистка экрана

        //...
        triangle.draw({4, 3, 3});

        window.display();
    }


    window.close();
    return 0;
}