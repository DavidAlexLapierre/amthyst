#include "engine/core/game.h"


Game::Game(const char* _name) {
    name = _name;
    sceneManager = std::make_unique<Amethyst::SceneManager>();
    initStatus = glfwInit();
    if (initStatus) {
        initWindow();
    }
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

    glfwSetKeyCallback(window, Amethyst::InputManager::keyboardCallback);
}

void Game::terminateWindow() {
    if (window) {
        glfwSetKeyCallback(window, nullptr);
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}

void Game::init() {
    if (initStatus) {
        if (window) {
            double previousDeltaT = glfwGetTime();
            while (!glfwWindowShouldClose(window)) {
                previousDeltaT = run(previousDeltaT);
                if (previousDeltaT < 0) break;
            }
        }

        sceneManager->dispose();
        terminateWindow();
    }
}

double Game::run(double previousDeltaT) {
    double currentTime = glfwGetTime();
    auto deltaT = (currentTime - previousDeltaT)*1000;
    auto scene = sceneManager->getCurrentScene();
    if (!scene) return -1; // ADD LOGGING FOR NO SCENE
    Amethyst::Color color = scene->getBackgroundColor();
    glClearColor(color.r(), color.g(), color.b(), color.a());
    glClear(GL_COLOR_BUFFER_BIT);
    glfwPollEvents();


    if (keyPressed(Keys::F1)) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }

    if (keyPressed(Keys::F2)) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    scene->update(deltaT);
    scene->draw();

    glfwSwapBuffers(window);

    return currentTime;
}
