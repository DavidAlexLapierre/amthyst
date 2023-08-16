#include "engine/inputs/input_manager.h"
#include <iostream>

namespace Engine::Inputs {

    InputManager::InputManager(GLFWwindow* window) {
        glfwSetWindowUserPointer(window, this);
        glfwSetKeyCallback(window, keyboardCallback);
    }

    void InputManager::keyboardCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
        if (action == GLFW_PRESS) {
        } else if (action == GLFW_RELEASE) {
            std::cout << key << std::endl;
        }
    }
}