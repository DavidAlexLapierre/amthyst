#pragma once

#include <GLFW/glfw3.h>

namespace Engine::Inputs {
    class KeyStates {
        public:
            static const int ENABLED = 1;
            static const int DISABLED = 0;
            KeyStates();

        private:
            int downStates[GLFW_KEY_LAST + 1];
            int upStates[GLFW_KEY_LAST + 1];
    };
}