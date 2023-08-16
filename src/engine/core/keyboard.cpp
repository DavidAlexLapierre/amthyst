#include "engine/core/keyboard.h"

bool keyPressed(Keys key) {
    auto keyVal = Engine::Inputs::KeyMapper::getKey(key);
    return Engine::Inputs::InputManager::getKeyboard()->checkKeyPressed(keyVal);
}

bool keyDown(Keys key) {
    auto keyVal = Engine::Inputs::KeyMapper::getKey(key);
    return Engine::Inputs::InputManager::getKeyboard()->checkKeyDown(keyVal);
}

bool keyUp(Keys key) {
    auto keyVal = Engine::Inputs::KeyMapper::getKey(key);
    return Engine::Inputs::InputManager::getKeyboard()->checkKeyUp(keyVal);
}