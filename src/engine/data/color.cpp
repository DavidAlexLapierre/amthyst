#include "engine/data/color.h"

namespace Data {

    Color::Color() {
        _r = 0;
        _g = 0;
        _b = 0;
        _a = 255;
    }

    Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        _r = r;
        _g = g;
        _b = b;
        _a = a;
    }

    float Color::r() { return _r / 255.0f; }
    float Color::g() { return _g / 255.0f; }
    float Color::b() { return _b / 255.0f; }
    float Color::a() { return _a / 255.0f; }
}