#pragma once

#include "engine/inputs/key_states.h"

namespace Engine::Inputs {
    class KeyboardManager {
        public:
            KeyboardManager();
            void reset();
            void enableKeyDown(int key);
            void enableKeyUp(int key);
            void disableKeyDown(int key);
            void disableKeyUp(int key);
            bool checkKeyDown(int key);
            bool checkKeyUp(int key);
            bool checkKeyPressed(int key);

        private:
            bool alreadyPressed;
            KeyStates keyStates;
    };
}