#include "engine/inputs/input_manager.h"

namespace Engine::Inputs {

    InputManager *InputManager::instance = nullptr;

    InputManager::~InputManager() {
        delete instance;
        instance = nullptr;
    }

    InputManager* InputManager::get() {
        if (InputManager::instance == nullptr) {
            InputManager::instance = new InputManager();
        }
        return instance;
    }
}