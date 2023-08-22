#pragma once

#include "engine/managers/keyboard_manager.h"
#include <GLFW/glfw3.h>
#include <memory>

namespace Amethyst {
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