#include "engine/core/game.h"
#include <iostream>


Game::Game() {
    windowManager = std::make_shared<Engine::Display::WindowManager>();
    windowManager->init();
    renderer = std::make_shared<Engine::Rendering::Renderer>();
    inputManager = std::make_shared<Engine::Inputs::InputManager>(windowManager->getWindow());
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

        if (keyPressed(Keys::A)) {
            std::cout << "A pressed" << std::endl;
        }

        // UPDATE
        // DRAW
    }
}
