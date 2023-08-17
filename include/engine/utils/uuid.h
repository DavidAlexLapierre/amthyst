#pragma once

#include <iostream>
#include <random>
#include <iomanip>
#include <sstream>

namespace Engine::Utils {
    class UUID {
        public:
            static const std::string EMPTY;
            UUID();
            std::string toString() const;

        private:
            uint32_t getRandomInt() const;
            void generate();
            uint32_t rnd1, rnd2, rnd3, rnd4;
    };
}
