#include "engine/inputs/keyboard_manager.h"

namespace Engine::Inputs {
    KeyboardManager::KeyboardManager() {
        keyStates = KeyStates();
        previousKeyStates = KeyStates();
    }

    void KeyboardManager::enableKeyDown(int key) { keyStates.setDownState(key, true); }
    void KeyboardManager::enableKeyUp(int key) { keyStates.setUpState(key, true); }
    void KeyboardManager::disableKeyDown(int key) { keyStates.setDownState(key, false); }
    void KeyboardManager::disableKeyUp(int key) { keyStates.setUpState(key, false); }
}