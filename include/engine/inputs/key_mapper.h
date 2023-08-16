#pragma once

#include "engine/core/keyboard.h"
#include <GLFW/glfw3.h>
#include <map>

enum class Keys;

namespace Engine::Inputs {
    
    class KeyMapper {
    public:
        static int getKey(Keys key);

    private:
        static const std::map<Keys, int> keyMap;
    };
}