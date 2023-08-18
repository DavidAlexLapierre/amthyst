#include "engine/core/keyboard.h"

bool keyPressed(Keys key) {
    auto keyVal = Engine::Inputs::KeyMapper::getKey(key);
    return Engine::Inputs::InputManager::checkKeyPressed(keyVal);
}

bool keyDown(Keys key) {
    auto keyVal = Engine::Inputs::KeyMapper::getKey(key);
    return Engine::Inputs::InputManager::checkKeyDown(keyVal);
}

bool keyUp(Keys key) {
    auto keyVal = Engine::Inputs::KeyMapper::getKey(key);
    return Engine::Inputs::InputManager::checkKeyUp(keyVal);
}