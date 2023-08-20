#include "engine/core/game.h"


Game::Game(const char* _name) {
    name = _name;
    renderer = std::make_shared<Engine::Rendering::Renderer>();
    sceneManager = std::make_shared<Engine::Managers::SceneManager>();
}

void Game::registerScene(std::shared_ptr<Scene> scene) { sceneManager->registerScene(scene); }

GLFWwindow* Game::initWindow() {
    auto window = glfwCreateWindow(800, 600, name, NULL, NULL);
    if (!window) { return nullptr; }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        return nullptr;
    }

    glfwSetKeyCallback(window, Engine::Managers::InputManager::keyboardCallback);

    return window;
}

void Game::terminateWindow(GLFWwindow* window) {
    if (window) {
        glfwSetKeyCallback(window, nullptr);
        glfwDestroyWindow(window);
    }
    
    glfwTerminate();
}

void Game::init() {
    if (glfwInit()) {
        auto window = initWindow();
        if (window) {
            while (!glfwWindowShouldClose(window)) {
                run(window);
            }
        }

        terminateWindow(window);
    }
}

void Game::run(GLFWwindow* window) {
    Data::Color color = sceneManager->getCurrentScene()->getBackgroundColor();
    glClearColor(color.r(), color.g(), color.b(), color.a());
    glClear(GL_COLOR_BUFFER_BIT);
    glfwPollEvents();

    // update
    sceneManager->getCurrentScene()->update(0); // replace 0 with deltaT

    // draw

    //renderer->update(0);
    //renderer->draw();
    glfwSwapBuffers(window);
}
