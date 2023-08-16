#include "engine/inputs/keyboard_manager.h"

namespace Engine::Inputs {
    KeyboardManager::KeyboardManager() {
        keyStates = KeyStates();
        alreadyPressed = false;
    }

    bool KeyboardManager::checkKeyDown(int key) { return keyStates.getDownState(key); }

    bool KeyboardManager::checkKeyUp(int key) { return keyStates.getUpState(key); }

    bool KeyboardManager::checkKeyPressed(int key) {
        if (checkKeyDown(key) && !alreadyPressed) {
            alreadyPressed = true;
            return true;
        }

        return false;
    }

    void KeyboardManager::enableKeyDown(int key) { keyStates.setDownState(key, true); }

    void KeyboardManager::disableKeyDown(int key) { keyStates.setDownState(key, false); }

    void KeyboardManager::enableKeyUp(int key) { 
        keyStates.setUpState(key, true);
        alreadyPressed = false;
    }

    void KeyboardManager::disableKeyUp(int key) {
        keyStates.setUpState(key, false);
        alreadyPressed = false;
    }
}