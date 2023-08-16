#pragma once

#include <GLFW/glfw3.h>

namespace Engine::Display {
    class WindowManager {
        public:
            ~WindowManager();
            int init();
            GLFWwindow* getWindow() const;

        private:
            GLFWwindow *window;
    };
}