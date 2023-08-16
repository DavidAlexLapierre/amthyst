#pragma once

#include "engine/display/window_manager.h"
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
    };
}