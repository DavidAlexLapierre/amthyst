#include "engine/core/game.h"
#include <iostream>


Game::Game() {
    windowManager = std::make_shared<Engine::Display::WindowManager>();
    windowManager->init();
    renderer = std::make_shared<Engine::Rendering::Renderer>();
    inputManager = std::make_shared<Engine::Inputs::InputManager>(windowManager->getWindow());
    sceneManager = std::make_shared<Engine::ECS::SceneManager>();
}

Game::~Game() {
    glfwTerminate();
}

void Game::registerScene(std::shared_ptr<Scene> scene) { sceneManager->registerScene(scene); }

void Game::run() {
    std::cout << "Hello world!" << std::endl;
    while (!glfwWindowShouldClose(windowManager->getWindow())) {
        auto color = sceneManager->getCurrentScene()->getBackgroundColor();
        glClearColor(color.r(), color.g(), color.b(), color.a());
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
