#include <iostream>
#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <shaderLoader.h>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Triangle.h"
#include "Cube.h"
#include "imgui-SFML.h"
#include "imgui.h"

using namespace std;

int main() {
    sf::ContextSettings settings;
    settings.depthBits = 24; // количество битов буффера глубины
    settings.stencilBits = 8; //количество битов буфера трафарета
    settings.majorVersion = 4;
    settings.minorVersion = 3;
//    settings.attributeFlags = sf::ContextSettings::Core;

    sf::RenderWindow window(sf::VideoMode(800, 600, 32), (string)"First Window", sf::Style::Default, settings);
    window.setFramerateLimit(60);
    glewExperimental = GL_TRUE; // включить все современные функции ogl


    if (GLEW_OK != glewInit()) { // включить glew
        cout << "Error:: glew not init =(" << endl;
        return -1;
    }
//    ImGui::SFML::Init(window);

    bool isGo = true;
    auto triangle = Cube();

    sf::Clock deltaClock;
    while (isGo) {
        sf::Event windowEvent{};

        while (window.pollEvent(windowEvent)) { // обработка ивентов
//            ImGui::SFML::ProcessEvent(windowEvent);
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
        glEnable(GL_DEPTH_TEST);
//        glDepthFunc(GL_LESS);

//        ImGui::SFML::Update(window, deltaClock.restart());
//        ImGui::Begin("Sample window"); // создаём окно


        //...

//        static mml::Vector3 cameraPosition;
//        static float arr[3];
//        if (ImGui::DragFloat3("Camera Position", arr)) {
//             код вызывается при изменении значения, поэтому всё
//             обновляется автоматически
//            cameraPosition.x = static_cast<float>(arr[0]);
//            cameraPosition.y = static_cast<float>(arr[1]);
//            cameraPosition.z = static_cast<float>(arr[2]);
//        }



//        ImGui::End();
//        static int i = 0;
//        i++;
//        if (i < 1000)
//            ImGui::EndFrame();
//        else

//        ImGui::SFML::Render(window);
        triangle.draw({4, 3, 5});

        window.display();
    }


    window.close();
    ImGui::SFML::Shutdown();
    return 0;
}