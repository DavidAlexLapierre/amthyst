#pragma once

#include "engine/inputs/keyboard_manager.h"
#include <GLFW/glfw3.h>

namespace Engine::Inputs {
    class InputManager {
        public:
            InputManager(GLFWwindow* window);
            static void keyboardCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
    };
}