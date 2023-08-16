#pragma once

#include "engine/display/window_manager.h"
#include "engine/rendering/renderer.h"
#include "engine/inputs/input_manager.h"
#include "engine/core/keyboard.h"
#include <GLFW/glfw3.h>
#include <memory>

namespace Core {
    class Game {
        public:
            Game();
            ~Game();
            void run();
        private:
            std::shared_ptr<Engine::Display::WindowManager> windowManager;
            std::shared_ptr<Engine::Rendering::Renderer> renderer;
            std::shared_ptr<Engine::Inputs::InputManager> inputManager;
    };
}