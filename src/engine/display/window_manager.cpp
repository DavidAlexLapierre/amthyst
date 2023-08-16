#include "engine/display/window_manager.h"

namespace Engine::Display {
    int WindowManager::init() {
        if (!glfwInit()) {
            return -1;
        }

        window = glfwCreateWindow(800, 600, "Game", NULL, NULL);
        if (!window) {
            return -1;
        }

        glfwMakeContextCurrent(window);
        
        return 0;
    }

    WindowManager::~WindowManager() {
        glfwDestroyWindow(window);
    }

    GLFWwindow* WindowManager::getWindow() const {
        return window;
    }
}