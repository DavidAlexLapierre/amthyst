#include "engine/core/game.h"


Game::Game(const char* _name) {
    name = _name;
    sceneManager = std::make_unique<Engine::Managers::SceneManager>();
    if (glfwInit()) {
        initWindow();
    }
}

Game::~Game() {
    terminateWindow();
}

void Game::registerScene(std::shared_ptr<Scene> scene) { sceneManager->registerScene(scene); }

void Game::initWindow() {

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(800, 600, name, NULL, NULL);
    if (!window) { return; }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        return;
    }

    glfwSetKeyCallback(window, Engine::Managers::InputManager::keyboardCallback);
}

void Game::terminateWindow() {
    if (window) {
        glfwSetKeyCallback(window, nullptr);
        glfwDestroyWindow(window);
    }

    glfwTerminate();
}

void Game::init() {
    if (window) {
        double previousDeltaT = glfwGetTime();
        while (!glfwWindowShouldClose(window)) {
            previousDeltaT = run(previousDeltaT);
        }
    }

    terminateWindow();
}

double Game::run(double previousDeltaT) {
    double currentTime = glfwGetTime();
    double deltaT = currentTime - previousDeltaT;
    Data::Color color = sceneManager->getCurrentScene()->getBackgroundColor();
    glClearColor(color.r(), color.g(), color.b(), color.a());
    glClear(GL_COLOR_BUFFER_BIT);
    glfwPollEvents();

    // update
    sceneManager->getCurrentScene()->update(deltaT);

    // draw
    sceneManager->getCurrentScene()->draw();

    glfwSwapBuffers(window);

    return currentTime;
}
