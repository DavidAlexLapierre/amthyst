#pragma once

#include "engine/inputs/key_states.h"

namespace Engine::Inputs {
    class KeyboardManager {
        public:
            KeyboardManager();
            void enableKeyDown(int key);
            void enableKeyUp(int key);
            void disableKeyDown(int key);
            void disableKeyUp(int key);

        private:
            KeyStates keyStates;
            KeyStates previousKeyStates;
    };
}