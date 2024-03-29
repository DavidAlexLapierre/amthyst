#include "engine/inputs/key_states.h"

namespace Amethyst {
    KeyStates::KeyStates() {
        for (int i = 0; i <= GLFW_KEY_LAST; i++) {
            downStates[i] = KeyStates::DISABLED;
            upStates[i] = KeyStates::DISABLED;
        }
    }

    int KeyStates::getDownState(int key) { return downStates[key]; }
    int KeyStates::getUpState(int key) { return upStates[key]; }
    void KeyStates::setDownState(int key, bool enabled) { downStates[key] = enabled ? KeyStates::ENABLED : KeyStates::DISABLED; }
    void KeyStates::setUpState(int key, bool enabled) { upStates[key] = enabled ? KeyStates::ENABLED : KeyStates::DISABLED; }
}