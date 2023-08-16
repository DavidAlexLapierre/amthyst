#include "engine/inputs/key_states.h"

namespace Engine::Inputs {
    KeyStates::KeyStates() {
        for (int i = 0; i <= GLFW_KEY_LAST; i++) {
            downStates[i] = KeyStates::DISABLED;
            upStates[i] = KeyStates::DISABLED;
        }
    }
}