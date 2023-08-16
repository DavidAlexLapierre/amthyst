#include "engine/inputs/keyboard_manager.h"

namespace Engine::Inputs {

    KeyboardManager *KeyboardManager::instance = nullptr;

    KeyboardManager::KeyboardManager() {
        keyStates = KeyStates();
        previousKeyStates = KeyStates();
    }

    KeyboardManager::~KeyboardManager() {
        delete instance;
        instance = nullptr;
    }

    KeyboardManager* KeyboardManager::get() {
        if (instance == nullptr) {
            instance = new KeyboardManager();
        }
        return instance;
    }
}