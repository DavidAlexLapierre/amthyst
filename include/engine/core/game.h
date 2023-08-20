#pragma once

#include <glad/glad.h>
#include "engine/rendering/renderer.h"
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
        std::shared_ptr<Engine::Rendering::Renderer> renderer;
        std::shared_ptr<Engine::Managers::SceneManager> sceneManager;
};
