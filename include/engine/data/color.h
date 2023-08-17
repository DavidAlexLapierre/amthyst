#pragma once

#include <cstdint>

namespace Data {
    class Color {
        public:
            Color();
            Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
            float r();
            float g();
            float b();
            float a();
        private:
            uint8_t _r;
            uint8_t _g;
            uint8_t _b;
            uint8_t _a;
    };
}