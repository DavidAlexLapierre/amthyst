#pragma once

#include "engine/managers/input_manager.h"
#include "engine/inputs/key_mapper.h"

enum class Keys {
    A, B, C, D, E, F, G, H, I, J, K, L, M,
    N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
    Num0, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9,
    Space, Apostrophe, Comma, Minus, Period, Slash,
    Semicolon, Equal, LeftBracket, Backslash, RightBracket, GraveAccent,
    World1, World2,
    Escape, Enter, Tab, Backspace, Insert, Delete,
    Right, Left, Down, Up,
    PageUp, PageDown, Home, End, CapsLock, ScrollLock, NumLock,
    PrintScreen, Pause,
    F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
    Keypad0, Keypad1, Keypad2, Keypad3, Keypad4,
    Keypad5, Keypad6, Keypad7, Keypad8, Keypad9,
    KeypadDecimal, KeypadDivide, KeypadMultiply, KeypadSubtract, KeypadAdd,
    KeypadEnter, KeypadEqual,
    LeftShift, LeftControl, LeftAlt, LeftSuper,
    RightShift, RightControl, RightAlt, RightSuper,
    Menu,
    Count, // Special value to represent the number of keys
};

bool keyPressed(Keys key);
bool keyDown(Keys key);
bool keyUp(Keys key);