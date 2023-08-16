#include "engine/inputs/input_manager.h"
#include <iostream>

namespace Engine::Inputs {

    std::shared_ptr<KeyboardManager> InputManager::keyboardManager = nullptr;

    InputManager::InputManager(GLFWwindow* window) {
        glfwSetWindowUserPointer(window, this);
        glfwSetKeyCallback(window, keyboardCallback);
        keyboardManager = std::make_shared<KeyboardManager>();
    }

    KeyboardManager* InputManager::getKeyboard() {
        return keyboardManager.get();
    }

    void InputManager::keyboardCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
        if (action == GLFW_PRESS) {
            keyboardManager->enableKeyDown(key);
            keyboardManager->disableKeyUp(key);
        } else if (action == GLFW_RELEASE) {
            keyboardManager->enableKeyUp(key);
            keyboardManager->disableKeyDown(key);
        }
    }
}