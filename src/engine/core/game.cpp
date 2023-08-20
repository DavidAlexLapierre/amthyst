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
            double previousDeltaT = glfwGetTime();
            while (!glfwWindowShouldClose(window)) {
                previousDeltaT = run(window, previousDeltaT);
            }
        }

        terminateWindow(window);
    }
}

double Game::run(GLFWwindow* window, double previousDeltaT) {
    double currentTime = glfwGetTime();
    double deltaT = currentTime - previousDeltaT;
    Data::Color color = sceneManager->getCurrentScene()->getBackgroundColor();
    glClearColor(color.r(), color.g(), color.b(), color.a());
    glClear(GL_COLOR_BUFFER_BIT);
    glfwPollEvents();

    // update
    sceneManager->getCurrentScene()->update(deltaT); // replace 0 with deltaT

    // draw
    renderer->update(deltaT);
    renderer->draw();

    glfwSwapBuffers(window);

    return currentTime;
}
