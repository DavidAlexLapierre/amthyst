#include "engine/core/keyboard.h"

namespace Keyboard {
    bool keyPressed(int key) { return Engine::Inputs::InputManager::getKeyboard()->checkKeyPressed(key); }

    bool keyDown(int key) { return Engine::Inputs::InputManager::getKeyboard()->checkKeyDown(key); }

    bool keyUp(int key) { return Engine::Inputs::InputManager::getKeyboard()->checkKeyUp(key); }
}