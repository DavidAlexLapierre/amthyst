#pragma once

#include "engine/display/window_manager.h"
#include "engine/rendering/renderer.h"
#include "engine/inputs/input_handler.h"
#include <GLFW/glfw3.h>
#include <memory>

namespace Engine::Core {
    class Game {
        public:
            Game();
            ~Game();
            void run();
        private:
            std::shared_ptr<Display::WindowManager> windowManager;
            std::shared_ptr<Rendering::Renderer> renderer;
    };
}