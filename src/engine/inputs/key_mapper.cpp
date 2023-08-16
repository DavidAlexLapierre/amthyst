#include "engine/inputs/key_mapper.h"

namespace Engine::Inputs {
    const std::map<Keys, int> KeyMapper::keyMap = {
        {Keys::A, GLFW_KEY_A},
        {Keys::B, GLFW_KEY_B},
        {Keys::C, GLFW_KEY_C},
        {Keys::D, GLFW_KEY_D},
        {Keys::E, GLFW_KEY_E},
        {Keys::F, GLFW_KEY_F},
        {Keys::G, GLFW_KEY_G},
        {Keys::H, GLFW_KEY_H},
        {Keys::I, GLFW_KEY_I},
        {Keys::J, GLFW_KEY_J},
        {Keys::K, GLFW_KEY_K},
        {Keys::L, GLFW_KEY_L},
        {Keys::M, GLFW_KEY_M},
        {Keys::N, GLFW_KEY_N},
        {Keys::O, GLFW_KEY_O},
        {Keys::P, GLFW_KEY_P},
        {Keys::Q, GLFW_KEY_Q},
        {Keys::R, GLFW_KEY_R},
        {Keys::S, GLFW_KEY_S},
        {Keys::T, GLFW_KEY_T},
        {Keys::U, GLFW_KEY_U},
        {Keys::V, GLFW_KEY_V},
        {Keys::W, GLFW_KEY_W},
        {Keys::X, GLFW_KEY_X},
        {Keys::Y, GLFW_KEY_Y},
        {Keys::Z, GLFW_KEY_Z},
        {Keys::Num0, GLFW_KEY_0},
        {Keys::Num1, GLFW_KEY_1},
        {Keys::Num2, GLFW_KEY_2},
        {Keys::Num3, GLFW_KEY_3},
        {Keys::Num4, GLFW_KEY_4},
        {Keys::Num5, GLFW_KEY_5},
        {Keys::Num6, GLFW_KEY_6},
        {Keys::Num7, GLFW_KEY_7},
        {Keys::Num8, GLFW_KEY_8},
        {Keys::Num9, GLFW_KEY_9},
        {Keys::Space, GLFW_KEY_SPACE},
        {Keys::Apostrophe, GLFW_KEY_APOSTROPHE},
        {Keys::Comma, GLFW_KEY_COMMA},
        {Keys::Minus, GLFW_KEY_MINUS},
        {Keys::Period, GLFW_KEY_PERIOD},
        {Keys::Slash, GLFW_KEY_SLASH},
        {Keys::Semicolon, GLFW_KEY_SEMICOLON},
        {Keys::Equal, GLFW_KEY_EQUAL},
        {Keys::LeftBracket, GLFW_KEY_LEFT_BRACKET},
        {Keys::Backslash, GLFW_KEY_BACKSLASH},
        {Keys::RightBracket, GLFW_KEY_RIGHT_BRACKET},
        {Keys::GraveAccent, GLFW_KEY_GRAVE_ACCENT},
        {Keys::World1, GLFW_KEY_WORLD_1},
        {Keys::World2, GLFW_KEY_WORLD_2},
        {Keys::Escape, GLFW_KEY_ESCAPE},
        {Keys::Enter, GLFW_KEY_ENTER},
        {Keys::Tab, GLFW_KEY_TAB},
        {Keys::Backspace, GLFW_KEY_BACKSPACE},
        {Keys::Insert, GLFW_KEY_INSERT},
        {Keys::Delete, GLFW_KEY_DELETE},
        {Keys::Right, GLFW_KEY_RIGHT},
        {Keys::Left, GLFW_KEY_LEFT},
        {Keys::Down, GLFW_KEY_DOWN},
        {Keys::Up, GLFW_KEY_UP},
        {Keys::PageUp, GLFW_KEY_PAGE_UP},
        {Keys::PageDown, GLFW_KEY_PAGE_DOWN},
        {Keys::Home, GLFW_KEY_HOME},
        {Keys::End, GLFW_KEY_END},
        {Keys::CapsLock, GLFW_KEY_CAPS_LOCK},
        {Keys::ScrollLock, GLFW_KEY_SCROLL_LOCK},
        {Keys::NumLock, GLFW_KEY_NUM_LOCK},
        {Keys::PrintScreen, GLFW_KEY_PRINT_SCREEN},
        {Keys::Pause, GLFW_KEY_PAUSE},
        {Keys::F1, GLFW_KEY_F1},
        {Keys::F2, GLFW_KEY_F2},
        {Keys::F3, GLFW_KEY_F3},
        {Keys::F4, GLFW_KEY_F4},
        {Keys::F5, GLFW_KEY_F5},
        {Keys::F6, GLFW_KEY_F6},
        {Keys::F7, GLFW_KEY_F7},
        {Keys::F8, GLFW_KEY_F8},
        {Keys::F9, GLFW_KEY_F9},
        {Keys::F10, GLFW_KEY_F10},
        {Keys::F11, GLFW_KEY_F11},
        {Keys::F12, GLFW_KEY_F12},
        {Keys::Keypad0, GLFW_KEY_KP_0},
        {Keys::Keypad1, GLFW_KEY_KP_1},
        {Keys::Keypad2, GLFW_KEY_KP_2},
        {Keys::Keypad3, GLFW_KEY_KP_3},
        {Keys::Keypad4, GLFW_KEY_KP_4},
        {Keys::Keypad5, GLFW_KEY_KP_5},
        {Keys::Keypad6, GLFW_KEY_KP_6},
        {Keys::Keypad7, GLFW_KEY_KP_7},
        {Keys::Keypad8, GLFW_KEY_KP_8},
        {Keys::Keypad9, GLFW_KEY_KP_9},
        {Keys::KeypadDecimal, GLFW_KEY_KP_DECIMAL},
        {Keys::KeypadDivide, GLFW_KEY_KP_DIVIDE},
        {Keys::KeypadMultiply, GLFW_KEY_KP_MULTIPLY},
        {Keys::KeypadSubtract, GLFW_KEY_KP_SUBTRACT},
        {Keys::KeypadAdd, GLFW_KEY_KP_ADD},
        {Keys::KeypadEnter, GLFW_KEY_KP_ENTER},
        {Keys::KeypadEqual, GLFW_KEY_KP_EQUAL},
        {Keys::LeftShift, GLFW_KEY_LEFT_SHIFT},
        {Keys::LeftControl, GLFW_KEY_LEFT_CONTROL},
        {Keys::LeftAlt, GLFW_KEY_LEFT_ALT},
        {Keys::LeftSuper, GLFW_KEY_LEFT_SUPER},
        {Keys::RightShift, GLFW_KEY_RIGHT_SHIFT},
        {Keys::RightControl, GLFW_KEY_RIGHT_CONTROL},
        {Keys::RightAlt, GLFW_KEY_RIGHT_ALT},
        {Keys::RightSuper, GLFW_KEY_RIGHT_SUPER},
        {Keys::Menu, GLFW_KEY_MENU}
    };

    int KeyMapper::getKey(Keys key) {
        auto it = KeyMapper::keyMap.find(key);
        if (it != KeyMapper::keyMap.end()) {
            return it->second;
        }
        return -1;
    }
}