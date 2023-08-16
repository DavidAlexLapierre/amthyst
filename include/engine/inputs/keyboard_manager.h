#pragma once

#include "engine/inputs/key_states.h"
#include <memory>
#include <map>
#include <GLFW/glfw3.h>

namespace Engine::Inputs {
    class KeyboardManager {
        public:
            ~KeyboardManager();
            static KeyboardManager* get();

        private:
            KeyStates keyStates;
            KeyStates previousKeyStates;
            KeyboardManager();
            static KeyboardManager* instance;
    };
}