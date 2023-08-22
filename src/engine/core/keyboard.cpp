#include "engine/core/keyboard.h"

bool keyPressed(Keys key) {
    auto keyVal = Amethyst::KeyMapper::getKey(key);
    return Amethyst::InputManager::checkKeyPressed(keyVal);
}

bool keyDown(Keys key) {
    auto keyVal = Amethyst::KeyMapper::getKey(key);
    return Amethyst::InputManager::checkKeyDown(keyVal);
}

bool keyUp(Keys key) {
    auto keyVal = Amethyst::KeyMapper::getKey(key);
    return Amethyst::InputManager::checkKeyUp(keyVal);
}