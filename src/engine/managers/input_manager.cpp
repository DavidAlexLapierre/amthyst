#include "engine/managers/input_manager.h"

namespace Amethyst {

    KeyboardManager InputManager::keyboardManager = KeyboardManager();
    
    KeyboardManager InputManager::getKeyboard() {
        return keyboardManager;
    }

    bool InputManager::checkKeyPressed(int keyVal) { return keyboardManager.checkKeyPressed(keyVal); }
    bool InputManager::checkKeyDown(int keyVal) { return keyboardManager.checkKeyDown(keyVal); }
    bool InputManager::checkKeyUp(int keyVal) { return keyboardManager.checkKeyUp(keyVal); }

    void InputManager::keyboardCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
        if (action == GLFW_PRESS) {
            keyboardManager.enableKeyDown(key);
            keyboardManager.disableKeyUp(key);
        } else if (action == GLFW_RELEASE) {
            keyboardManager.enableKeyUp(key);
            keyboardManager.disableKeyDown(key);
        }
    }
}