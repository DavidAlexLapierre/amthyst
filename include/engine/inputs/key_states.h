#pragma once

#include <GLFW/glfw3.h>

namespace Engine::Inputs {
    class KeyStates {
        public:
            static const int ENABLED = 1;
            static const int DISABLED = 0;
            KeyStates();
            void setDownState(int key, bool enabled);
            void setUpState(int key, bool enabled);
            int getDownState(int key);
            int getUpState(int key);

        private:
            int downStates[GLFW_KEY_LAST + 1];
            int upStates[GLFW_KEY_LAST + 1];
    };
}