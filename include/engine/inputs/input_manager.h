#pragma once

#include "engine/inputs/keyboard_manager.h"
#include <GLFW/glfw3.h>
#include <memory>

namespace Engine::Inputs {
    class InputManager {
        public:
            static void keyboardCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
            static KeyboardManager getKeyboard();
            static bool checkKeyPressed(int keyVal);
            static bool checkKeyDown(int keyVal);
            static bool checkKeyUp(int keyVal);

        private:
            static KeyboardManager keyboardManager;
    };
}