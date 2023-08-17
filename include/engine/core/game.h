#pragma once

#include "engine/display/window_manager.h"
#include "engine/rendering/renderer.h"
#include "engine/inputs/input_manager.h"
#include "engine/core/keyboard.h"
#include "engine/ECS/scene_manager.h"
#include <GLFW/glfw3.h>
#include <memory>


class Game {
    public:
        Game();
        ~Game();
        void run();
        void registerScene(std::shared_ptr<Scene> scene);

    private:
        std::shared_ptr<Engine::Display::WindowManager> windowManager;
        std::shared_ptr<Engine::Rendering::Renderer> renderer;
        std::shared_ptr<Engine::Inputs::InputManager> inputManager;
        std::shared_ptr<Engine::ECS::SceneManager> sceneManager;
};
