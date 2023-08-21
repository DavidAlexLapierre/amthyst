#pragma once

#include <glad/glad.h>
#include "engine/managers/scene_manager.h"
#include "engine/core/keyboard.h"
#include <memory>


class Game {
    public:
        Game(const char* _name);
        ~Game();
        void init();
        void registerScene(std::shared_ptr<Scene> scene);

    private:
        GLFWwindow* window;
        const char* name;
        void initWindow();
        void terminateWindow();
        double run(double previousDeltaT);
        std::unique_ptr<Engine::Managers::SceneManager> sceneManager;
};
