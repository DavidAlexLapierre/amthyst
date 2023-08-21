#pragma once

#include <glad/glad.h>
#include "engine/managers/scene_manager.h"
#include "engine/core/keyboard.h"
#include <memory>


class Game {
    public:
        Game(const char* _name);
        void init();
        void registerScene(std::shared_ptr<Scene> scene);

    private:
        const char* name;
        GLFWwindow* initWindow();
        void terminateWindow(GLFWwindow* window);
        double run(GLFWwindow* window, double previousDeltaT);
        std::unique_ptr<Engine::Managers::SceneManager> sceneManager;
};
