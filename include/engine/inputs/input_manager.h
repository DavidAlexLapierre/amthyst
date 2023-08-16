#pragma once

#include <memory>

namespace Engine::Inputs {
    class InputManager {
        public:
            ~InputManager();
            static InputManager* get();

        private:
            static InputManager* instance;
    };
}