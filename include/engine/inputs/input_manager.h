#pragma once

#include "engine/inputs/keyboard_manager.h"
#include <GLFW/glfw3.h>
#include <memory>

namespace Engine::Inputs {
    class InputManager {
        public:
            InputManager(GLFWwindow* window);
            static void keyboardCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
            static KeyboardManager *getKeyboard();

        private:
            static std::shared_ptr<KeyboardManager> keyboardManager;
    };
}