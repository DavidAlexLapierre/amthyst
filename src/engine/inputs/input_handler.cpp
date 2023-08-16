#include "engine/inputs/input_handler.h"
#include <iostream>

namespace Engine::Inputs {
    void keyboardCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
        if (action == GLFW_PRESS) {
            std::cout << key << std::endl;
        } else if (action == GLFW_RELEASE) {
            std::cout << key << std::endl;
        }
    }
}