#pragma once

#include "engine/core/keyboard.h"
#include <GLFW/glfw3.h>
#include <unordered_map>

enum class Keys;

namespace Amethyst {
    
    class KeyMapper {
    public:
        static int getKey(Keys key);

    private:
        static const std::unordered_map<Keys, int> keyMap;
    };
}