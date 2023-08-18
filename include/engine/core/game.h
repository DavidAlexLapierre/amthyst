#pragma once

#include "engine/rendering/renderer.h"
#include "engine/inputs/input_manager.h"
#include "engine/core/keyboard.h"
#include "engine/ECS/scene_manager.h"
#include <GLFW/glfw3.h>
#include <memory>


class Game {
    public:
        Game();
        void init();
        void registerScene(std::shared_ptr<Scene> scene);

    private:
        GLFWwindow* initWindow();
        void terminateWindow(GLFWwindow* window);
        void run(GLFWwindow* window);
        std::shared_ptr<Engine::Rendering::Renderer> renderer;
        std::shared_ptr<Engine::ECS::SceneManager> sceneManager;
};
