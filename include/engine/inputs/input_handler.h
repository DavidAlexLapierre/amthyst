#pragma once

#include <GLFW/glfw3.h>

namespace Engine::Inputs {
    void keyboardCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
}