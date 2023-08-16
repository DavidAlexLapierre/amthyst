#include "engine/core/game.h"
#include <iostream>

namespace Engine::Core {
    Game::Game() {
        windowManager = std::make_shared<Display::WindowManager>();
        windowManager->init();
    }

    Game::~Game() {
        glfwTerminate();
    }

    void Game::run() {
        std::cout << "Hello world!" << std::endl;
        while (!glfwWindowShouldClose(windowManager->getWindow())) {

            glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glfwPollEvents();
            glfwSwapBuffers(windowManager->getWindow());
        }
    }
}